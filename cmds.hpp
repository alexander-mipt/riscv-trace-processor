/*
 * This file is autogenerated by 'cmdgen.py' script from .yaml file
 * Do not try to change anything in this file
 * If you need to change code - change script/markdown file
 ***********************************************************
 * Written by Derzhavin Andrey (derzhavin3016) && Khaydari Farid (Tako-San) && Antipov Alexander
 */

#pragma once
#include <cstdio>
#include <unordered_map>

#include "parse_types.hpp"

#include "enums.hpp"

void do_BEQ(Context&, Instr&);
void do_BNE(Context&, Instr&);
void do_BLT(Context&, Instr&);
void do_BGE(Context&, Instr&);
void do_BLTU(Context&, Instr&);
void do_BGEU(Context&, Instr&);
void do_JALR(Context&, Instr&);
void do_JAL(Context&, Instr&);
void do_LUI(Context&, Instr&);
void do_AUIPC(Context&, Instr&);
void do_ADDI(Context&, Instr&);
void do_SLLI(Context&, Instr&);
void do_SLTI(Context&, Instr&);
void do_SLTIU(Context&, Instr&);
void do_XORI(Context&, Instr&);
void do_SRLI(Context&, Instr&);
void do_SRAI(Context&, Instr&);
void do_ORI(Context&, Instr&);
void do_ANDI(Context&, Instr&);
void do_ADD(Context&, Instr&);
void do_SUB(Context&, Instr&);
void do_SLL(Context&, Instr&);
void do_SLT(Context&, Instr&);
void do_SLTU(Context&, Instr&);
void do_XOR(Context&, Instr&);
void do_SRL(Context&, Instr&);
void do_SRA(Context&, Instr&);
void do_OR(Context&, Instr&);
void do_AND(Context&, Instr&);
void do_ADDIW(Context&, Instr&);
void do_SLLIW(Context&, Instr&);
void do_SRLIW(Context&, Instr&);
void do_SRAIW(Context&, Instr&);
void do_ADDW(Context&, Instr&);
void do_SUBW(Context&, Instr&);
void do_SLLW(Context&, Instr&);
void do_SRLW(Context&, Instr&);
void do_SRAW(Context&, Instr&);
void do_LB(Context&, Instr&);
void do_LH(Context&, Instr&);
void do_LW(Context&, Instr&);
void do_LD(Context&, Instr&);
void do_LBU(Context&, Instr&);
void do_LHU(Context&, Instr&);
void do_LWU(Context&, Instr&);
void do_SB(Context&, Instr&);
void do_SH(Context&, Instr&);
void do_SW(Context&, Instr&);
void do_SD(Context&, Instr&);
void do_FENCE(Context&, Instr&);
void do_FENCE_I(Context&, Instr&);
void do_MUL(Context&, Instr&);
void do_MULH(Context&, Instr&);
void do_MULHSU(Context&, Instr&);
void do_MULHU(Context&, Instr&);
void do_DIV(Context&, Instr&);
void do_DIVU(Context&, Instr&);
void do_REM(Context&, Instr&);
void do_REMU(Context&, Instr&);
void do_MULW(Context&, Instr&);
void do_DIVW(Context&, Instr&);
void do_DIVUW(Context&, Instr&);
void do_REMW(Context&, Instr&);
void do_REMUW(Context&, Instr&);
void do_AMOADD_W(Context&, Instr&);
void do_AMOXOR_W(Context&, Instr&);
void do_AMOOR_W(Context&, Instr&);
void do_AMOAND_W(Context&, Instr&);
void do_AMOMIN_W(Context&, Instr&);
void do_AMOMAX_W(Context&, Instr&);
void do_AMOMINU_W(Context&, Instr&);
void do_AMOMAXU_W(Context&, Instr&);
void do_AMOSWAP_W(Context&, Instr&);
void do_LR_W(Context&, Instr&);
void do_SC_W(Context&, Instr&);
void do_AMOADD_D(Context&, Instr&);
void do_AMOXOR_D(Context&, Instr&);
void do_AMOOR_D(Context&, Instr&);
void do_AMOAND_D(Context&, Instr&);
void do_AMOMIN_D(Context&, Instr&);
void do_AMOMAX_D(Context&, Instr&);
void do_AMOMINU_D(Context&, Instr&);
void do_AMOMAXU_D(Context&, Instr&);
void do_AMOSWAP_D(Context&, Instr&);
void do_LR_D(Context&, Instr&);
void do_SC_D(Context&, Instr&);
void do_ECALL(Context&, Instr&);
void do_EBREAK(Context&, Instr&);
void do_URET(Context&, Instr&);
void do_SRET(Context&, Instr&);
void do_MRET(Context&, Instr&);
void do_DRET(Context&, Instr&);
void do_SFENCE_VMA(Context&, Instr&);
void do_WFI(Context&, Instr&);
void do_CSRRW(Context&, Instr&);
void do_CSRRS(Context&, Instr&);
void do_CSRRC(Context&, Instr&);
void do_CSRRWI(Context&, Instr&);
void do_CSRRSI(Context&, Instr&);
void do_CSRRCI(Context&, Instr&);
void do_HFENCE_VVMA(Context&, Instr&);
void do_HFENCE_GVMA(Context&, Instr&);
void do_FADD_S(Context&, Instr&);
void do_FSUB_S(Context&, Instr&);
void do_FMUL_S(Context&, Instr&);
void do_FDIV_S(Context&, Instr&);
void do_FSGNJ_S(Context&, Instr&);
void do_FSGNJN_S(Context&, Instr&);
void do_FSGNJX_S(Context&, Instr&);
void do_FMIN_S(Context&, Instr&);
void do_FMAX_S(Context&, Instr&);
void do_FSQRT_S(Context&, Instr&);
void do_FADD_D(Context&, Instr&);
void do_FSUB_D(Context&, Instr&);
void do_FMUL_D(Context&, Instr&);
void do_FDIV_D(Context&, Instr&);
void do_FSGNJ_D(Context&, Instr&);
void do_FSGNJN_D(Context&, Instr&);
void do_FSGNJX_D(Context&, Instr&);
void do_FMIN_D(Context&, Instr&);
void do_FMAX_D(Context&, Instr&);
void do_FCVT_S_D(Context&, Instr&);
void do_FCVT_D_S(Context&, Instr&);
void do_FSQRT_D(Context&, Instr&);
void do_FADD_Q(Context&, Instr&);
void do_FSUB_Q(Context&, Instr&);
void do_FMUL_Q(Context&, Instr&);
void do_FDIV_Q(Context&, Instr&);
void do_FSGNJ_Q(Context&, Instr&);
void do_FSGNJN_Q(Context&, Instr&);
void do_FSGNJX_Q(Context&, Instr&);
void do_FMIN_Q(Context&, Instr&);
void do_FMAX_Q(Context&, Instr&);
void do_FCVT_S_Q(Context&, Instr&);
void do_FCVT_Q_S(Context&, Instr&);
void do_FCVT_D_Q(Context&, Instr&);
void do_FCVT_Q_D(Context&, Instr&);
void do_FSQRT_Q(Context&, Instr&);
void do_FLE_S(Context&, Instr&);
void do_FLT_S(Context&, Instr&);
void do_FEQ_S(Context&, Instr&);
void do_FLE_D(Context&, Instr&);
void do_FLT_D(Context&, Instr&);
void do_FEQ_D(Context&, Instr&);
void do_FLE_Q(Context&, Instr&);
void do_FLT_Q(Context&, Instr&);
void do_FEQ_Q(Context&, Instr&);
void do_FCVT_W_S(Context&, Instr&);
void do_FCVT_WU_S(Context&, Instr&);
void do_FCVT_L_S(Context&, Instr&);
void do_FCVT_LU_S(Context&, Instr&);
void do_FMV_X_W(Context&, Instr&);
void do_FCLASS_S(Context&, Instr&);
void do_FCVT_W_D(Context&, Instr&);
void do_FCVT_WU_D(Context&, Instr&);
void do_FCVT_L_D(Context&, Instr&);
void do_FCVT_LU_D(Context&, Instr&);
void do_FMV_X_D(Context&, Instr&);
void do_FCLASS_D(Context&, Instr&);
void do_FCVT_W_Q(Context&, Instr&);
void do_FCVT_WU_Q(Context&, Instr&);
void do_FCVT_L_Q(Context&, Instr&);
void do_FCVT_LU_Q(Context&, Instr&);
void do_FMV_X_Q(Context&, Instr&);
void do_FCLASS_Q(Context&, Instr&);
void do_FCVT_S_W(Context&, Instr&);
void do_FCVT_S_WU(Context&, Instr&);
void do_FCVT_S_L(Context&, Instr&);
void do_FCVT_S_LU(Context&, Instr&);
void do_FMV_W_X(Context&, Instr&);
void do_FCVT_D_W(Context&, Instr&);
void do_FCVT_D_WU(Context&, Instr&);
void do_FCVT_D_L(Context&, Instr&);
void do_FCVT_D_LU(Context&, Instr&);
void do_FMV_D_X(Context&, Instr&);
void do_FCVT_Q_W(Context&, Instr&);
void do_FCVT_Q_WU(Context&, Instr&);
void do_FCVT_Q_L(Context&, Instr&);
void do_FCVT_Q_LU(Context&, Instr&);
void do_FMV_Q_X(Context&, Instr&);
void do_FLW(Context&, Instr&);
void do_FLD(Context&, Instr&);
void do_FLQ(Context&, Instr&);
void do_FSW(Context&, Instr&);
void do_FSD(Context&, Instr&);
void do_FSQ(Context&, Instr&);
void do_FMADD_S(Context&, Instr&);
void do_FMSUB_S(Context&, Instr&);
void do_FNMSUB_S(Context&, Instr&);
void do_FNMADD_S(Context&, Instr&);
void do_FMADD_D(Context&, Instr&);
void do_FMSUB_D(Context&, Instr&);
void do_FNMSUB_D(Context&, Instr&);
void do_FNMADD_D(Context&, Instr&);
void do_FMADD_Q(Context&, Instr&);
void do_FMSUB_Q(Context&, Instr&);
void do_FNMSUB_Q(Context&, Instr&);
void do_FNMADD_Q(Context&, Instr&);


std::unordered_map<const std::string, Opcode> OpcdHash
{
    {"beq", BEQ},
    {"bne", BNE},
    {"blt", BLT},
    {"bge", BGE},
    {"bltu", BLTU},
    {"bgeu", BGEU},
    {"jalr", JALR},
    {"jal", JAL},
    {"lui", LUI},
    {"auipc", AUIPC},
    {"addi", ADDI},
    {"slli", SLLI},
    {"slti", SLTI},
    {"sltiu", SLTIU},
    {"xori", XORI},
    {"srli", SRLI},
    {"srai", SRAI},
    {"ori", ORI},
    {"andi", ANDI},
    {"add", ADD},
    {"sub", SUB},
    {"sll", SLL},
    {"slt", SLT},
    {"sltu", SLTU},
    {"xor", XOR},
    {"srl", SRL},
    {"sra", SRA},
    {"or", OR},
    {"and", AND},
    {"addiw", ADDIW},
    {"slliw", SLLIW},
    {"srliw", SRLIW},
    {"sraiw", SRAIW},
    {"addw", ADDW},
    {"subw", SUBW},
    {"sllw", SLLW},
    {"srlw", SRLW},
    {"sraw", SRAW},
    {"lb", LB},
    {"lh", LH},
    {"lw", LW},
    {"ld", LD},
    {"lbu", LBU},
    {"lhu", LHU},
    {"lwu", LWU},
    {"sb", SB},
    {"sh", SH},
    {"sw", SW},
    {"sd", SD},
    {"fence", FENCE},
    {"fence.i", FENCE_I},
    {"mul", MUL},
    {"mulh", MULH},
    {"mulhsu", MULHSU},
    {"mulhu", MULHU},
    {"div", DIV},
    {"divu", DIVU},
    {"rem", REM},
    {"remu", REMU},
    {"mulw", MULW},
    {"divw", DIVW},
    {"divuw", DIVUW},
    {"remw", REMW},
    {"remuw", REMUW},
    {"amoadd.w", AMOADD_W},
    {"amoxor.w", AMOXOR_W},
    {"amoor.w", AMOOR_W},
    {"amoand.w", AMOAND_W},
    {"amomin.w", AMOMIN_W},
    {"amomax.w", AMOMAX_W},
    {"amominu.w", AMOMINU_W},
    {"amomaxu.w", AMOMAXU_W},
    {"amoswap.w", AMOSWAP_W},
    {"lr.w", LR_W},
    {"sc.w", SC_W},
    {"amoadd.d", AMOADD_D},
    {"amoxor.d", AMOXOR_D},
    {"amoor.d", AMOOR_D},
    {"amoand.d", AMOAND_D},
    {"amomin.d", AMOMIN_D},
    {"amomax.d", AMOMAX_D},
    {"amominu.d", AMOMINU_D},
    {"amomaxu.d", AMOMAXU_D},
    {"amoswap.d", AMOSWAP_D},
    {"lr.d", LR_D},
    {"sc.d", SC_D},
    {"ecall", ECALL},
    {"ebreak", EBREAK},
    {"uret", URET},
    {"sret", SRET},
    {"mret", MRET},
    {"dret", DRET},
    {"sfence.vma", SFENCE_VMA},
    {"wfi", WFI},
    {"csrrw", CSRRW},
    {"csrrs", CSRRS},
    {"csrrc", CSRRC},
    {"csrrwi", CSRRWI},
    {"csrrsi", CSRRSI},
    {"csrrci", CSRRCI},
    {"hfence.vvma", HFENCE_VVMA},
    {"hfence.gvma", HFENCE_GVMA},
    {"fadd.s", FADD_S},
    {"fsub.s", FSUB_S},
    {"fmul.s", FMUL_S},
    {"fdiv.s", FDIV_S},
    {"fsgnj.s", FSGNJ_S},
    {"fsgnjn.s", FSGNJN_S},
    {"fsgnjx.s", FSGNJX_S},
    {"fmin.s", FMIN_S},
    {"fmax.s", FMAX_S},
    {"fsqrt.s", FSQRT_S},
    {"fadd.d", FADD_D},
    {"fsub.d", FSUB_D},
    {"fmul.d", FMUL_D},
    {"fdiv.d", FDIV_D},
    {"fsgnj.d", FSGNJ_D},
    {"fsgnjn.d", FSGNJN_D},
    {"fsgnjx.d", FSGNJX_D},
    {"fmin.d", FMIN_D},
    {"fmax.d", FMAX_D},
    {"fcvt.s.d", FCVT_S_D},
    {"fcvt.d.s", FCVT_D_S},
    {"fsqrt.d", FSQRT_D},
    {"fadd.q", FADD_Q},
    {"fsub.q", FSUB_Q},
    {"fmul.q", FMUL_Q},
    {"fdiv.q", FDIV_Q},
    {"fsgnj.q", FSGNJ_Q},
    {"fsgnjn.q", FSGNJN_Q},
    {"fsgnjx.q", FSGNJX_Q},
    {"fmin.q", FMIN_Q},
    {"fmax.q", FMAX_Q},
    {"fcvt.s.q", FCVT_S_Q},
    {"fcvt.q.s", FCVT_Q_S},
    {"fcvt.d.q", FCVT_D_Q},
    {"fcvt.q.d", FCVT_Q_D},
    {"fsqrt.q", FSQRT_Q},
    {"fle.s", FLE_S},
    {"flt.s", FLT_S},
    {"feq.s", FEQ_S},
    {"fle.d", FLE_D},
    {"flt.d", FLT_D},
    {"feq.d", FEQ_D},
    {"fle.q", FLE_Q},
    {"flt.q", FLT_Q},
    {"feq.q", FEQ_Q},
    {"fcvt.w.s", FCVT_W_S},
    {"fcvt.wu.s", FCVT_WU_S},
    {"fcvt.l.s", FCVT_L_S},
    {"fcvt.lu.s", FCVT_LU_S},
    {"fmv.x.w", FMV_X_W},
    {"fclass.s", FCLASS_S},
    {"fcvt.w.d", FCVT_W_D},
    {"fcvt.wu.d", FCVT_WU_D},
    {"fcvt.l.d", FCVT_L_D},
    {"fcvt.lu.d", FCVT_LU_D},
    {"fmv.x.d", FMV_X_D},
    {"fclass.d", FCLASS_D},
    {"fcvt.w.q", FCVT_W_Q},
    {"fcvt.wu.q", FCVT_WU_Q},
    {"fcvt.l.q", FCVT_L_Q},
    {"fcvt.lu.q", FCVT_LU_Q},
    {"fmv.x.q", FMV_X_Q},
    {"fclass.q", FCLASS_Q},
    {"fcvt.s.w", FCVT_S_W},
    {"fcvt.s.wu", FCVT_S_WU},
    {"fcvt.s.l", FCVT_S_L},
    {"fcvt.s.lu", FCVT_S_LU},
    {"fmv.w.x", FMV_W_X},
    {"fcvt.d.w", FCVT_D_W},
    {"fcvt.d.wu", FCVT_D_WU},
    {"fcvt.d.l", FCVT_D_L},
    {"fcvt.d.lu", FCVT_D_LU},
    {"fmv.d.x", FMV_D_X},
    {"fcvt.q.w", FCVT_Q_W},
    {"fcvt.q.wu", FCVT_Q_WU},
    {"fcvt.q.l", FCVT_Q_L},
    {"fcvt.q.lu", FCVT_Q_LU},
    {"fmv.q.x", FMV_Q_X},
    {"flw", FLW},
    {"fld", FLD},
    {"flq", FLQ},
    {"fsw", FSW},
    {"fsd", FSD},
    {"fsq", FSQ},
    {"fmadd.s", FMADD_S},
    {"fmsub.s", FMSUB_S},
    {"fnmsub.s", FNMSUB_S},
    {"fnmadd.s", FNMADD_S},
    {"fmadd.d", FMADD_D},
    {"fmsub.d", FMSUB_D},
    {"fnmsub.d", FNMSUB_D},
    {"fnmadd.d", FNMADD_D},
    {"fmadd.q", FMADD_Q},
    {"fmsub.q", FMSUB_Q},
    {"fnmsub.q", FNMSUB_Q},
    {"fnmadd.q", FNMADD_Q}
};

std::unordered_map<Opcode, void(*)(Context&, Instr&)> Cmds
{
    {BEQ, do_BEQ},
    {BNE, do_BNE},
    {BLT, do_BLT},
    {BGE, do_BGE},
    {BLTU, do_BLTU},
    {BGEU, do_BGEU},
    {JALR, do_JALR},
    {JAL, do_JAL},
    {LUI, do_LUI},
    {AUIPC, do_AUIPC},
    {ADDI, do_ADDI},
    {SLLI, do_SLLI},
    {SLTI, do_SLTI},
    {SLTIU, do_SLTIU},
    {XORI, do_XORI},
    {SRLI, do_SRLI},
    {SRAI, do_SRAI},
    {ORI, do_ORI},
    {ANDI, do_ANDI},
    {ADD, do_ADD},
    {SUB, do_SUB},
    {SLL, do_SLL},
    {SLT, do_SLT},
    {SLTU, do_SLTU},
    {XOR, do_XOR},
    {SRL, do_SRL},
    {SRA, do_SRA},
    {OR, do_OR},
    {AND, do_AND},
    {ADDIW, do_ADDIW},
    {SLLIW, do_SLLIW},
    {SRLIW, do_SRLIW},
    {SRAIW, do_SRAIW},
    {ADDW, do_ADDW},
    {SUBW, do_SUBW},
    {SLLW, do_SLLW},
    {SRLW, do_SRLW},
    {SRAW, do_SRAW},
    {LB, do_LB},
    {LH, do_LH},
    {LW, do_LW},
    {LD, do_LD},
    {LBU, do_LBU},
    {LHU, do_LHU},
    {LWU, do_LWU},
    {SB, do_SB},
    {SH, do_SH},
    {SW, do_SW},
    {SD, do_SD},
    {FENCE, do_FENCE},
    {FENCE_I, do_FENCE_I},
    {MUL, do_MUL},
    {MULH, do_MULH},
    {MULHSU, do_MULHSU},
    {MULHU, do_MULHU},
    {DIV, do_DIV},
    {DIVU, do_DIVU},
    {REM, do_REM},
    {REMU, do_REMU},
    {MULW, do_MULW},
    {DIVW, do_DIVW},
    {DIVUW, do_DIVUW},
    {REMW, do_REMW},
    {REMUW, do_REMUW},
    {AMOADD_W, do_AMOADD_W},
    {AMOXOR_W, do_AMOXOR_W},
    {AMOOR_W, do_AMOOR_W},
    {AMOAND_W, do_AMOAND_W},
    {AMOMIN_W, do_AMOMIN_W},
    {AMOMAX_W, do_AMOMAX_W},
    {AMOMINU_W, do_AMOMINU_W},
    {AMOMAXU_W, do_AMOMAXU_W},
    {AMOSWAP_W, do_AMOSWAP_W},
    {LR_W, do_LR_W},
    {SC_W, do_SC_W},
    {AMOADD_D, do_AMOADD_D},
    {AMOXOR_D, do_AMOXOR_D},
    {AMOOR_D, do_AMOOR_D},
    {AMOAND_D, do_AMOAND_D},
    {AMOMIN_D, do_AMOMIN_D},
    {AMOMAX_D, do_AMOMAX_D},
    {AMOMINU_D, do_AMOMINU_D},
    {AMOMAXU_D, do_AMOMAXU_D},
    {AMOSWAP_D, do_AMOSWAP_D},
    {LR_D, do_LR_D},
    {SC_D, do_SC_D},
    {ECALL, do_ECALL},
    {EBREAK, do_EBREAK},
    {URET, do_URET},
    {SRET, do_SRET},
    {MRET, do_MRET},
    {DRET, do_DRET},
    {SFENCE_VMA, do_SFENCE_VMA},
    {WFI, do_WFI},
    {CSRRW, do_CSRRW},
    {CSRRS, do_CSRRS},
    {CSRRC, do_CSRRC},
    {CSRRWI, do_CSRRWI},
    {CSRRSI, do_CSRRSI},
    {CSRRCI, do_CSRRCI},
    {HFENCE_VVMA, do_HFENCE_VVMA},
    {HFENCE_GVMA, do_HFENCE_GVMA},
    {FADD_S, do_FADD_S},
    {FSUB_S, do_FSUB_S},
    {FMUL_S, do_FMUL_S},
    {FDIV_S, do_FDIV_S},
    {FSGNJ_S, do_FSGNJ_S},
    {FSGNJN_S, do_FSGNJN_S},
    {FSGNJX_S, do_FSGNJX_S},
    {FMIN_S, do_FMIN_S},
    {FMAX_S, do_FMAX_S},
    {FSQRT_S, do_FSQRT_S},
    {FADD_D, do_FADD_D},
    {FSUB_D, do_FSUB_D},
    {FMUL_D, do_FMUL_D},
    {FDIV_D, do_FDIV_D},
    {FSGNJ_D, do_FSGNJ_D},
    {FSGNJN_D, do_FSGNJN_D},
    {FSGNJX_D, do_FSGNJX_D},
    {FMIN_D, do_FMIN_D},
    {FMAX_D, do_FMAX_D},
    {FCVT_S_D, do_FCVT_S_D},
    {FCVT_D_S, do_FCVT_D_S},
    {FSQRT_D, do_FSQRT_D},
    {FADD_Q, do_FADD_Q},
    {FSUB_Q, do_FSUB_Q},
    {FMUL_Q, do_FMUL_Q},
    {FDIV_Q, do_FDIV_Q},
    {FSGNJ_Q, do_FSGNJ_Q},
    {FSGNJN_Q, do_FSGNJN_Q},
    {FSGNJX_Q, do_FSGNJX_Q},
    {FMIN_Q, do_FMIN_Q},
    {FMAX_Q, do_FMAX_Q},
    {FCVT_S_Q, do_FCVT_S_Q},
    {FCVT_Q_S, do_FCVT_Q_S},
    {FCVT_D_Q, do_FCVT_D_Q},
    {FCVT_Q_D, do_FCVT_Q_D},
    {FSQRT_Q, do_FSQRT_Q},
    {FLE_S, do_FLE_S},
    {FLT_S, do_FLT_S},
    {FEQ_S, do_FEQ_S},
    {FLE_D, do_FLE_D},
    {FLT_D, do_FLT_D},
    {FEQ_D, do_FEQ_D},
    {FLE_Q, do_FLE_Q},
    {FLT_Q, do_FLT_Q},
    {FEQ_Q, do_FEQ_Q},
    {FCVT_W_S, do_FCVT_W_S},
    {FCVT_WU_S, do_FCVT_WU_S},
    {FCVT_L_S, do_FCVT_L_S},
    {FCVT_LU_S, do_FCVT_LU_S},
    {FMV_X_W, do_FMV_X_W},
    {FCLASS_S, do_FCLASS_S},
    {FCVT_W_D, do_FCVT_W_D},
    {FCVT_WU_D, do_FCVT_WU_D},
    {FCVT_L_D, do_FCVT_L_D},
    {FCVT_LU_D, do_FCVT_LU_D},
    {FMV_X_D, do_FMV_X_D},
    {FCLASS_D, do_FCLASS_D},
    {FCVT_W_Q, do_FCVT_W_Q},
    {FCVT_WU_Q, do_FCVT_WU_Q},
    {FCVT_L_Q, do_FCVT_L_Q},
    {FCVT_LU_Q, do_FCVT_LU_Q},
    {FMV_X_Q, do_FMV_X_Q},
    {FCLASS_Q, do_FCLASS_Q},
    {FCVT_S_W, do_FCVT_S_W},
    {FCVT_S_WU, do_FCVT_S_WU},
    {FCVT_S_L, do_FCVT_S_L},
    {FCVT_S_LU, do_FCVT_S_LU},
    {FMV_W_X, do_FMV_W_X},
    {FCVT_D_W, do_FCVT_D_W},
    {FCVT_D_WU, do_FCVT_D_WU},
    {FCVT_D_L, do_FCVT_D_L},
    {FCVT_D_LU, do_FCVT_D_LU},
    {FMV_D_X, do_FMV_D_X},
    {FCVT_Q_W, do_FCVT_Q_W},
    {FCVT_Q_WU, do_FCVT_Q_WU},
    {FCVT_Q_L, do_FCVT_Q_L},
    {FCVT_Q_LU, do_FCVT_Q_LU},
    {FMV_Q_X, do_FMV_Q_X},
    {FLW, do_FLW},
    {FLD, do_FLD},
    {FLQ, do_FLQ},
    {FSW, do_FSW},
    {FSD, do_FSD},
    {FSQ, do_FSQ},
    {FMADD_S, do_FMADD_S},
    {FMSUB_S, do_FMSUB_S},
    {FNMSUB_S, do_FNMSUB_S},
    {FNMADD_S, do_FNMADD_S},
    {FMADD_D, do_FMADD_D},
    {FMSUB_D, do_FMSUB_D},
    {FNMSUB_D, do_FNMSUB_D},
    {FNMADD_D, do_FNMADD_D},
    {FMADD_Q, do_FMADD_Q},
    {FMSUB_Q, do_FMSUB_Q},
    {FNMSUB_Q, do_FNMSUB_Q},
    {FNMADD_Q, do_FNMADD_Q}
};