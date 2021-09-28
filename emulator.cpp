
#include "cmds.hpp"
#include "cstring"
#include <fstream>
#include <sstream>
#include <iostream>

#define FILENAME "../formatted_trace.txt"

int main() {
    Context state;
    Instr current;
    // parse to Insgtr
    std::ifstream file(FILENAME);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // using printf() in all tests for consistency
            printf("%s\n", line.c_str());
            std::istringstream ss(line);
            std::string pc{}, raw{}, opcode{}, src[4];
            ss >> pc >> raw >> opcode >> src[0] >> src[1] >> src[2];
            // printf("Parsing:\npc: %s\nopcd: %s\nsrc: %s %s %s\n\n", pc.c_str(), opcode.c_str(), src1.c_str(), src2.c_str(), src3.c_str());

            current.opcd = OpcdHash[opcode];
            for (int i = 0; i < 4; ++i) {
                current.opnds[i].name = src[i];
            }
            std::cout << "opcode " << (int)current.opcd << std::endl;

            Cmds[current.opcd](state, current);
        }


    }
    file.close();
}