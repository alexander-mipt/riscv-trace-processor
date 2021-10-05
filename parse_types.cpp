#include "parse_types.hpp"
#include <cassert>
#include <iostream>

void def_routine(Context& ctx, Instr& instru) {
    
    auto name = instru.opnds[0].name;
    assert(RegNames.find(name) != RegNames.end());
    ctx.regs[(int)RegNames[name]].name = name;
    ctx.regs[(int)RegNames[name]].def = ctx.counter;

    for (auto i = 1; i < opndCount; ++i) {
        name = instru.opnds[i].name;
        if (RegNames.find(name) != RegNames.end()) {
            ctx.regs[(int)RegNames[name]].use = ctx.counter;
            ctx.regs[(int)RegNames[name]].name = name;
        } else if (!name.empty()) {
            ctx.cache.push(name);
        }
    }



    /*
    assert(instru.opnds[0].type == Field::RD);
    auto reg_idx = ctx.RegNames[instru.opnds[0].name];
    ctx.regs[(int) reg_idx].gen = ctx.counter;
    */

}

void err_routine(Context& ctx, Instr& instru) {

}