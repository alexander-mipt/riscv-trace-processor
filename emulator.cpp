
#include "cmds.hpp"
#include "cstring"
#include <fstream>
#include <sstream>
#include <iostream>
#include "dot_gen.hpp"

#define FILENAME "../formatted_trace.txt"
constexpr uint lineLim = 100;

int main() {
    
    // parse to Instr
    std::ifstream file(FILENAME);
    if (file.is_open()) {
        std::string line{};
        std::string prev_line = "start";
        
        Context state;
        Graph g;
        uint line_count = 0;

        // init
        g.addNode(prev_line, state.counter);
        state.counter++;

        // read trace
        while (std::getline(file, line) && line_count++ < lineLim) {
            // parse instruction

            // std::cout << line << std::endl;
            std::istringstream ss(line);
            std::string pc{}, raw{}, opcode{}, src[opndCount];
            ss >> pc >> raw >> opcode >> src[0] >> src[1] >> src[2];

            Instr cur;
            printf("%s\n", line.c_str());

            // init instr
            if (OpcdHash.find(opcode) != OpcdHash.end()) {
                cur.opcd = OpcdHash[opcode];
                //printf("%s\n", line.c_str());
                
                for (int i = 0; i < opndCount - 1; ++i) {
                    cur.opnds[i].name = src[i];
                }

                // process instr
                Cmds[cur.opcd](state, cur);

            } else {
                printf("illegal instr:\n%s\n", line.c_str());
                exit(-1);
            }

            // push instr line on graph
            auto current_instr = opcode + " " + src[0] + " " + src[1] + " " + src[2];
            std::string target = current_instr;
            g.addNode(current_instr.c_str(), state.counter);
            g.addEdge(prev_line.c_str(), state.counter - 1, current_instr.c_str(), state.counter);
            prev_line = current_instr;
            
            // process def
            std::string def_target{};
            for (auto i = 0; i < regCount; ++i) {
                if (state.regs[i].def.first == state.counter) {
                    def_target = state.regs[i].name;
                    g.addNode(def_target, state.counter);
                    g.addEdge(def_target, state.counter, target, state.counter);
                    break;
                }
            }
            /*
            if (def_target.empty()) {
                def_target = current_instr;
            }*/

            Context::reg_t store_src{};
            for (auto i = 0; i < regCount; ++i) {
                if (state.regs[i].use.first == state.counter) {
                    auto& use_reg = state.regs[i];

                    if (use_reg.def.second == 0 || use_reg.def.first == 0) {
                        g.addNode(use_reg.name, 0);
                    }
                    if (use_reg.def.first == state.counter) {
                        if (def_target.empty()) {
                            g.addEdge(use_reg.name, use_reg.def.second, target, state.counter);
                        } else {
                            g.addEdge(use_reg.name, use_reg.def.second, def_target, state.counter);
                        }
                        
                    } else {
                        if (def_target.empty()) {
                            g.addEdge(use_reg.name, use_reg.def.first, target, state.counter);
                        } else {
                            g.addEdge(use_reg.name, use_reg.def.first, def_target, state.counter);
                        }
                    }

                    /*
                    if (use_reg.use.first == use_reg.def.first) {
                        if (use_reg.def.second == 0) {
                            g.addNode(use_reg.name, 0);
                        }
                        g.addEdge(use_reg.name, use_reg.def.second, def_target, state.counter);
                    } else {
                        g.addEdge(use_reg.name, use_reg.def.first, def_target, state.counter);
                    }
                    */
                   store_src = state.regs[i];
                }
            }

            // draw vars in cache (imm, addr)
            while(!state.cache.empty()) {
                auto operand = state.cache.front();

                // process addr
                if (state.addrs.find(operand) != state.addrs.end()) {
                    auto memory = state.addrs[operand];
                    g.addNode(operand, memory.def);
                    // if load
                    if (memory.def != state.counter) {
                        g.addEdge(operand, memory.def, def_target, state.counter);
                    // if store
                    } else {
                        def_target = operand;
                        g.addEdge(store_src.name, store_src.def.first, def_target, state.counter);
                        // g.addEdge(def_target, state.counter, current_instr.c_str(), state.counter);
                        g.addEdge(def_target, memory.def, target, state.counter);
                    }
                    
                    printf("used addr: %s %d\n", operand.c_str(), memory.def);

                // process imm
                } else {
                    g.addNode(operand, state.counter);
                    if (def_target.empty()) {
                        g.addEdge(operand, state.counter, target, state.counter);
                    } else {
                        g.addEdge(operand, state.counter, def_target, state.counter);
                    }
                    
                    printf("used imm: %s\n", operand.c_str());
                }
                state.cache.pop();
            }
            
            state.counter++;
        }


    }
    file.close();
}

// printf("Parsing:\npc: %s\nopcd: %s\nsrc: %s %s %s\n\n", pc.c_str(), opcode.c_str(), src1.c_str(), src2.c_str(), src3.c_str());