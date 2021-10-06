#include "parse_types.hpp"
#include <cassert>
#include <iostream>

void def_routine(Context& ctx, Instr& instru) {
    
    auto name = instru.opnds[0].name;

    assert(RegNames.find(name) != RegNames.end());
    auto& reg = ctx.regs[(int)RegNames[name]];
    reg.name = name;
    
    if (reg.def.first != -1) {
        reg.def.second = reg.def.first;
    }
    reg.def.first = ctx.counter;

    for (auto i = 1; i < opndCount; ++i) {
        name = instru.opnds[i].name;
        if (RegNames.find(name) != RegNames.end()) {
            auto& reg = ctx.regs[(int)RegNames[name]];
            reg.name = name;

            if (reg.use.first != -1) {
                reg.use.second = reg.use.first;
            }
            reg.use.first = ctx.counter;

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