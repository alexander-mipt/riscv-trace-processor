#include "parse_types.hpp"
#include <cassert>

void def_routine(Context& ctx, Instr& instru) {
    assert(instru.opnds[0].type == Field::RD);
}