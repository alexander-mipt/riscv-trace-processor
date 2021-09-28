#include "parse_types.hpp"
#include <cassert>

void def_routine(Context& ctx, Instr& instru) {
    assert(instru.opnds[0].type == Field::RD);
    auto reg_idx = ctx.RegNames[instru.opnds[0].name];
    ctx.regs[(int) reg_idx].gen = ctx.counter;

}