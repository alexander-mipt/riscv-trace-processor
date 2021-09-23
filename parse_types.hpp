#pragma once
#include <sys/types.h>
#include <unistd.h>
#include "enums.hpp"

//typedef int Context;
//typedef int Instr;
typedef int opval;

constexpr int regCount{32};
constexpr int opndCount{4};
typedef uint64_t state;
typedef uint32_t raw;

class Context {
public:
    struct reg_t {
        std::string name{};
        uint64_t value{0};
        uint64_t gen{0};
    };

    reg_t regs[regCount]{0};
    state counter{0};
};

class Instr {
public:
    struct opnd_t {
        std::string name;
        Field type{Field::UNDEFINED};
        opval value{0};
    };
    Opcode opcd{Opcode::UNDEFINED};
    
    opnd_t opnds[opndCount]{};
    raw bits{0};
};


void def_routine(Context& ctx, Instr& instru);