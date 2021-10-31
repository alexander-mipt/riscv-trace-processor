#include "parse_types.hpp"
#include <cassert>
#include <iostream>

void def_routine(Context& ctx, Instr& instru) {
    
    auto name = instru.opnds[0].name;

    assert(RegNames.find(name) != RegNames.end());
    auto& reg = ctx.regs[(int)RegNames[name]];
    reg.name = name;
    
    if (reg.def.first != 0) {
        reg.def.second = reg.def.first;
    }
    reg.def.first = ctx.counter;

    for (auto i = 1; i < opndCount; ++i) {
        name = instru.opnds[i].name;
        if (RegNames.find(name) != RegNames.end()) {
            auto& reg = ctx.regs[(int)RegNames[name]];
            reg.name = name;

            if (reg.use.first != 0) {
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

std::pair<std::string, std::string> parse_addr(std::string pattern) {
    pattern.erase(pattern.find(')'), 1);
    const auto idx = pattern.find('(') + 1;
    assert(idx > 0);
    auto reg = pattern.substr(idx, pattern.size() - idx);
    auto offset = pattern.substr(0, idx - 1);
    std::cout << reg << " " << offset << std::endl;
    return std::make_pair(reg, offset);
}

void load_routine(Context& ctx, Instr& instru) {
    auto pattern = instru.opnds[1].name;
    std::pair<std::string, std::string> base_offset = parse_addr(pattern);

    auto reg_def = ctx.regs[(int)RegNames[base_offset.first]].def.first;
    if (ctx.addrs.find(pattern) != ctx.addrs.end()) {
        if (ctx.addrs[pattern].def < reg_def) {
            ctx.addrs[pattern].def = reg_def;
        }
    } else {
        Context::addr_t addr;
        addr.name = pattern;
        addr.base = RegNames[base_offset.first];
        addr.offset = std::stoi(base_offset.second);
        addr.def = reg_def;
        addr.first_use = ctx.counter;
        ctx.addrs.insert(std::make_pair(pattern, addr));
    }

}

void store_routine(Context& ctx, Instr& instru) {
    auto pattern = instru.opnds[1].name;
    std::pair<std::string, std::string> base_offset = parse_addr(pattern);

    if (ctx.addrs.find(pattern) != ctx.addrs.end()) {
        ctx.addrs[pattern].def = ctx.counter;
    } else {
        Context::addr_t addr;
        addr.name = pattern;
        addr.base = RegNames[base_offset.first];
        addr.offset = std::stoi(base_offset.second);
        addr.def = ctx.counter;
        ctx.addrs.insert(std::make_pair(pattern, addr));
    }
    //ctx.cache.push(pattern);
    //ctx.regs[(int)RegNames[instru.opnds[0].name]].use.first = ctx.counter;
}