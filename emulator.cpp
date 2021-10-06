
#include "cmds.hpp"
#include "cstring"
#include <fstream>
#include <sstream>
#include <iostream>
#include "dot_gen.hpp"

#define FILENAME "../formatted_trace.txt"

int main() {
    
    // parse to Instr
    std::ifstream file(FILENAME);
    if (file.is_open()) {
        std::string line;
        std::string prev_line = "init";
        Context state;
        Graph g;
        auto limit = 0;

        g.addNode(prev_line, state.counter);
        state.counter++;

        // read trace
        while (std::getline(file, line) && limit++ < 30) {
            // std::cout << line << std::endl;
            std::istringstream ss(line);
            std::string pc{}, raw{}, opcode{}, src[4];
            ss >> pc >> raw >> opcode >> src[0] >> src[1] >> src[2];

            Instr current;

            // init instr
            if (OpcdHash.find(opcode) != OpcdHash.end()) {
                current.opcd = OpcdHash[opcode];
                //printf("%s\n", line.c_str());
                
                for (int i = 0; i < opndCount - 1; ++i) {
                    current.opnds[i].name = src[i];
                }

                // process instr
                Cmds[current.opcd](state, current);

            } else {
                printf("illegal instr: %s\n", line.c_str());
                exit(-1);
            }

            // push instr line on graph
            g.addNode(line.c_str(), state.counter);
            g.addEdge(prev_line.c_str(), state.counter - 1, line.c_str(), state.counter);
            prev_line = line;
            
            // process def and use
            
            /*
            for (auto i = 0; i < regCount; ++i) {
                if (state.regs[i].def.first != state.counter) {
                    g.addSpace(state.counter);
                }
            }
            */

            std::string def_reg{};
            for (auto i = 0; i < regCount; ++i) {
                if (state.regs[i].def.first == state.counter) {
                    def_reg = state.regs[i].name;
                    // std::cout << "def reg: " << def_reg << std::endl;
                    g.addNode(def_reg, state.counter);

                    while(!state.cache.empty()) {
                        // std::cout << "\tcache value: " << state.cache.front() << std::endl;
                        g.addNode(state.cache.front(), state.counter);
                        g.addEdge(state.cache.front(), state.counter, def_reg, state.counter);
                        state.cache.pop();
                    }

                    break;
                }
            }

            for (auto i = 0; i < regCount; ++i) {
                if (state.regs[i].use.first == state.counter) {
                    auto& use_reg = state.regs[i];
                    // std::cout << "\tuse reg: " << use_reg.name << std::endl;

                    if (use_reg.use.first == use_reg.def.first) {
                        if (use_reg.def.second == 0) {
                            g.addNode(use_reg.name, 0);
                        }
                        g.addEdge(use_reg.name, use_reg.def.second, def_reg, state.counter);
                    } else {
                        g.addEdge(use_reg.name, use_reg.def.first, def_reg, state.counter);
                    }
                }
            }
            
            state.counter++;
        }


    }
    file.close();
}

// printf("Parsing:\npc: %s\nopcd: %s\nsrc: %s %s %s\n\n", pc.c_str(), opcode.c_str(), src1.c_str(), src2.c_str(), src3.c_str());