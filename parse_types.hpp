#pragma once
#include <sys/types.h>
#include <unistd.h>
#include "enums.hpp"
#include <unordered_map>
#include <queue>
#include <map>

//typedef int Context;
//typedef int Instr;
typedef int opval;

constexpr int regCount{32};
constexpr int opndCount{4};
typedef uint64_t state;
typedef uint32_t raw;

enum class Register {
    ZERO,
    RA,
    SP,
    GP,
    TP,

    T0,
    T1,
    T2,
    T3,
    T4,
    T5,
    T6,
    
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8,
    S9,
    S10,
    S11,
    
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    UNDEFINED
};

static std::unordered_map<std::string, Register> RegNames = {
    {"zero", Register::ZERO},
    {"ra", Register::RA},
    {"sp", Register::SP},
    {"gp", Register::GP},
    {"tp", Register::TP},

    {"t0", Register::T0},
    {"t1", Register::T1},
    {"t2", Register::T2},
    {"t3", Register::T3},
    {"t4", Register::T4},
    {"t5", Register::T5},
    {"t6", Register::T6},

    {"s0", Register::S0},
    {"s1", Register::S1},
    {"s2", Register::S2},
    {"s3", Register::S3},
    {"s4", Register::S4},
    {"s5", Register::S5},
    {"s6", Register::S6},
    {"s7", Register::S7},
    {"s8", Register::S8},
    {"s9", Register::S9},
    {"s10", Register::S10},
    {"s11", Register::S11},
    
    {"a0", Register::A0},
    {"a1", Register::A1},
    {"a2", Register::A2},
    {"a3", Register::A3},
    {"a4", Register::A4},
    {"a5", Register::A5},
    {"a6", Register::A6},
    {"a7", Register::A7},
};

class Context {
public:
    struct reg_t {
        // Register type{Register::UNDEFINED};
        std::string name{};
        uint64_t value{0};
        std::pair<uint64_t, uint64_t> def{0, 0};
        std::pair<uint64_t, uint64_t> use{0, 0};
    };

    struct addr_t {
        std::string name{};
        Register base{Register::UNDEFINED};
        int offset{0};
        uint64_t def{0};
        uint64_t first_use{0};
    };

    reg_t regs[regCount]{};
    state counter{0};

    std::queue<std::string> cache;

    std::map<std::string, addr_t> addrs;
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


std::pair<std::string, std::string> parse_addr(std::string);
void def_routine(Context& ctx, Instr& instru);
void use_routine(Context& ctx, Instr& instru, uint8_t has_dst, uint8_t num_src);
void imm_routine(Context& ctx, Instr& instru, uint8_t idx);
void err_routine(Context& ctx, Instr& instru);
void load_routine(Context& ctx, Instr& instru);
void store_routine(Context& ctx, Instr& instru);