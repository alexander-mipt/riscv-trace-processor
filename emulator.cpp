
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
        Context state;
        Graph g;
        auto limit = 0;
        while (std::getline(file, line) && limit++ < 30) {
            std::cout << line << std::endl;
            std::istringstream ss(line);
            std::string pc{}, raw{}, opcode{}, src[4];
            ss >> pc >> raw >> opcode >> src[0] >> src[1] >> src[2];

            Instr current;

            if (OpcdHash.find(opcode) != OpcdHash.end()) {
                current.opcd = OpcdHash[opcode];
                //printf("%s\n", line.c_str());
                
                for (int i = 0; i < opndCount - 1; ++i) {
                    current.opnds[i].name = src[i];
                }
                //std::cout << "opcode " << (int)current.opcd << std::endl;
                Cmds[current.opcd](state, current);

            } else {
                printf("illegal instr: %s\n", line.c_str());
                exit(-1);
            }

            g.addNode(line.c_str(), state.counter);
            
            if (state.counter >= 0) {

                std::string def_reg{};
                for (auto i = 0; i < regCount; ++i) {
                    if (state.regs[i].def == state.counter) {
                        std::cout << "def reg: " << state.regs[i].name << std::endl;
                        g.addNode(state.regs[i].name, state.counter);
                        def_reg = state.regs[i].name;
                        break;
                    }
                }
                for (auto i = 0; i < regCount; ++i) {
                    if (state.regs[i].use == state.counter) {
                        std::cout << "\tuse reg: " << state.regs[i].name << std::endl;
                        g.addEdge(state.regs[i].name, state.regs[i].def, def_reg, state.counter);
                    }
                }

                while(!state.cache.empty()) {
                    std::cout << "\tcache value: " << state.cache.front() << std::endl;
                    state.cache.pop();
                }
            }
            state.counter++;
        }


    }
    file.close();
}

// printf("Parsing:\npc: %s\nopcd: %s\nsrc: %s %s %s\n\n", pc.c_str(), opcode.c_str(), src1.c_str(), src2.c_str(), src3.c_str());