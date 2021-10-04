#include "parse_types.hpp"
#include <cassert>
#include <iostream>

void def_routine(Context& ctx, Instr& instru) {
    
    std::cout << "has rd" << std::endl;
    auto name = instru.opnds[0].name;
    std::cout << "changed reg: " << name << " gen: " << ctx.counter << std::endl;
    ctx.regs[(int)ctx.RegNames[name]].gen = ctx.counter;


    /*
    assert(instru.opnds[0].type == Field::RD);
    auto reg_idx = ctx.RegNames[instru.opnds[0].name];
    ctx.regs[(int) reg_idx].gen = ctx.counter;
    */

}

void err_routine(Context& ctx, Instr& instru) {

}