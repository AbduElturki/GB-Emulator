#include<inttypes.h>
#include "../memory/mmu.h"
#ifndef LR35902_H
#define LR35902_H

/* Registers:
 * The register in gameboy are 16 bit but they are split into two 8 bit reigsters
 * except for the stack pointer and program_counter
 * high refers to bits 15 ... 8
 * low refers to bits 7 ... 0
 */

union Register {
    uint16_t word;
    struct {
        uint8_t low;
        uint8_t high;
    };
};

class LR35902
{
public:
    LR35902();

    MMU *mmu;

    Register AF;
    Register BC;
    Register DE;
    Register HL;
    Register SP;
    Register PC;

private:
    typedef void (LR35902::*mapping)();
    mapping instruct_map[256]; 
    mapping cb_map[256]; 

    void IncrementPC(uint8_t steps);
    void GetPC();

    //LD
    void Load(uint8_t& reg);
    void Load(uint8_t& reg1, const uint8_t& reg2);
    void Load(uint16_t& reg1, const uint16_t& reg2);

    void LoadFromAddr(uint8_t reg);

    //Instruction set
    void NOP();
    void LD_BC_d16();
    void LD__BC__A();
    void INC_BC();
    void INC_B();
    void DEC_B();
    void LD_B_d8();
    void RLCA();
    void LD__a16__SP();
    void ADD_HL_BC();
    void LD_A__BC_();
    void DEC_BC();
    void INC_C();
    void DEC_C();
    void LD_C_d8();
    void RRCA();
    void STOP_0();
    void LD_DE_d16();
    void LD__DE__A();
    void INC_DE();
    void INC_D();
    void DEC_D();
    void LD_D_d8();
    void RLA();
    void JR_r8();
    void ADD_HL_DE();
    void LD_A__DE_();
    void DEC_DE();
    void INC_E();
    void DEC_E();
    void LD_E_d8();
    void RRA();
    void JR_NZ_r8();
    void LD_HL_d16();
    void LD__HL_PLUS___A();
    void INC_HL();
    void INC_H();
    void DEC_H();
    void LD_H_d8();
    void DAA();
    void JR_Z_r8();
    void ADD_HL_HL();
    void LD_A__HL_PLUS__();
    void DEC_HL();
    void INC_L();
    void DEC_L();
    void LD_L_d8();
    void CPL();
    void JR_NC_r8();
    void LD_SP_d16();
    void LD__HL_MINUS___A();
    void INC_SP();
    void INC__HL_();
    void DEC__HL_();
    void LD__HL__d8();
    void SCF();
    void JR_C_r8();
    void ADD_HL_SP();
    void LD_A__HL_MINUS__();
    void DEC_SP();
    void INC_A();
    void DEC_A();
    void LD_A_d8();
    void CCF();
    void LD_B_B();
    void LD_B_C();
    void LD_B_D();
    void LD_B_E();
    void LD_B_H();
    void LD_B_L();
    void LD_B__HL_();
    void LD_B_A();
    void LD_C_B();
    void LD_C_C();
    void LD_C_D();
    void LD_C_E();
    void LD_C_H();
    void LD_C_L();
    void LD_C__HL_();
    void LD_C_A();
    void LD_D_B();
    void LD_D_C();
    void LD_D_D();
    void LD_D_E();
    void LD_D_H();
    void LD_D_L();
    void LD_D__HL_();
    void LD_D_A();
    void LD_E_B();
    void LD_E_C();
    void LD_E_D();
    void LD_E_E();
    void LD_E_H();
    void LD_E_L();
    void LD_E__HL_();
    void LD_E_A();
    void LD_H_B();
    void LD_H_C();
    void LD_H_D();
    void LD_H_E();
    void LD_H_H();
    void LD_H_L();
    void LD_H__HL_();
    void LD_H_A();
    void LD_L_B();
    void LD_L_C();
    void LD_L_D();
    void LD_L_E();
    void LD_L_H();
    void LD_L_L();
    void LD_L__HL_();
    void LD_L_A();
    void LD__HL__B();
    void LD__HL__C();
    void LD__HL__D();
    void LD__HL__E();
    void LD__HL__H();
    void LD__HL__L();
    void HALT();
    void LD__HL__A();
    void LD_A_B();
    void LD_A_C();
    void LD_A_D();
    void LD_A_E();
    void LD_A_H();
    void LD_A_L();
    void LD_A__HL_();
    void LD_A_A();
    void ADD_A_B();
    void ADD_A_C();
    void ADD_A_D();
    void ADD_A_E();
    void ADD_A_H();
    void ADD_A_L();
    void ADD_A__HL_();
    void ADD_A_A();
    void ADC_A_B();
    void ADC_A_C();
    void ADC_A_D();
    void ADC_A_E();
    void ADC_A_H();
    void ADC_A_L();
    void ADC_A__HL_();
    void ADC_A_A();
    void SUB_B();
    void SUB_C();
    void SUB_D();
    void SUB_E();
    void SUB_H();
    void SUB_L();
    void SUB__HL_();
    void SUB_A();
    void SBC_A_B();
    void SBC_A_C();
    void SBC_A_D();
    void SBC_A_E();
    void SBC_A_H();
    void SBC_A_L();
    void SBC_A__HL_();
    void SBC_A_A();
    void AND_B();
    void AND_C();
    void AND_D();
    void AND_E();
    void AND_H();
    void AND_L();
    void AND__HL_();
    void AND_A();
    void XOR_B();
    void XOR_C();
    void XOR_D();
    void XOR_E();
    void XOR_H();
    void XOR_L();
    void XOR__HL_();
    void XOR_A();
    void OR_B();
    void OR_C();
    void OR_D();
    void OR_E();
    void OR_H();
    void OR_L();
    void OR__HL_();
    void OR_A();
    void CP_B();
    void CP_C();
    void CP_D();
    void CP_E();
    void CP_H();
    void CP_L();
    void CP__HL_();
    void CP_A();
    void RET_NZ();
    void POP_BC();
    void JP_NZ_a16();
    void JP_a16();
    void CALL_NZ_a16();
    void PUSH_BC();
    void ADD_A_d8();
    void RST_00H();
    void RET_Z();
    void RET();
    void JP_Z_a16();
    void PREFIX_CB();
    void CALL_Z_a16();
    void CALL_a16();
    void ADC_A_d8();
    void RST_08H();
    void RET_NC();
    void POP_DE();
    void JP_NC_a16();
    void CALL_NC_a16();
    void PUSH_DE();
    void SUB_d8();
    void RST_10H();
    void RET_C();
    void RETI();
    void JP_C_a16();
    void CALL_C_a16();
    void SBC_A_d8();
    void RST_1_8H();
    void LDH__a8__A();
    void POP_HL();
    void LD__C__A();
    void PUSH_HL();
    void AND_d8();
    void RST_20H();
    void ADD_SP_r8();
    void JP__HL_();
    void LD__a16__A();
    void XOR_d8();
    void RST_2_8H();
    void LDH_A__a8_();
    void POP_AF();
    void LD_A__C_();
    void DI();
    void PUSH_AF();
    void OR_d8();
    void RST_30H();
    void LD_HL_SP_PLUS_r8();
    void LD_SP_HL();
    void LD_A__a16_();
    void EI();
    void CP_d8();
    void RST_38H();

    //Invalid for errors
    void INVALID();

    //Prefix CB
    //
    
    void RLC_B();
    void RLC_C();
    void RLC_D();
    void RLC_E();
    void RLC_H();
    void RLC_L();
    void RLC__HL_();
    void RLC_A();
    void RRC_B();
    void RRC_C();
    void RRC_D();
    void RRC_E();
    void RRC_H();
    void RRC_L();
    void RRC__HL_();
    void RRC_A();
    void RL_B();
    void RL_C();
    void RL_D();
    void RL_E();
    void RL_H();
    void RL_L();
    void RL__HL_();
    void RL_A();
    void RR_B();
    void RR_C();
    void RR_D();
    void RR_E();
    void RR_H();
    void RR_L();
    void RR__HL_();
    void RR_A();
    void SLA_B();
    void SLA_C();
    void SLA_D();
    void SLA_E();
    void SLA_H();
    void SLA_L();
    void SLA__HL_();
    void SLA_A();
    void SRA_B();
    void SRA_C();
    void SRA_D();
    void SRA_E();
    void SRA_H();
    void SRA_L();
    void SRA__HL_();
    void SRA_A();
    void SWAP_B();
    void SWAP_C();
    void SWAP_D();
    void SWAP_E();
    void SWAP_H();
    void SWAP_L();
    void SWAP__HL_();
    void SWAP_A();
    void SRL_B();
    void SRL_C();
    void SRL_D();
    void SRL_E();
    void SRL_H();
    void SRL_L();
    void SRL__HL_();
    void SRL_A();
    void BIT_0_B();
    void BIT_0_C();
    void BIT_0_D();
    void BIT_0_E();
    void BIT_0_H();
    void BIT_0_L();
    void BIT_0__HL_();
    void BIT_0_A();
    void BIT_1_B();
    void BIT_1_C();
    void BIT_1_D();
    void BIT_1_E();
    void BIT_1_H();
    void BIT_1_L();
    void BIT_1__HL_();
    void BIT_1_A();
    void BIT_2_B();
    void BIT_2_C();
    void BIT_2_D();
    void BIT_2_E();
    void BIT_2_H();
    void BIT_2_L();
    void BIT_2__HL_();
    void BIT_2_A();
    void BIT_3_B();
    void BIT_3_C();
    void BIT_3_D();
    void BIT_3_E();
    void BIT_3_H();
    void BIT_3_L();
    void BIT_3__HL_();
    void BIT_3_A();
    void BIT_4_B();
    void BIT_4_C();
    void BIT_4_D();
    void BIT_4_E();
    void BIT_4_H();
    void BIT_4_L();
    void BIT_4__HL_();
    void BIT_4_A();
    void BIT_5_B();
    void BIT_5_C();
    void BIT_5_D();
    void BIT_5_E();
    void BIT_5_H();
    void BIT_5_L();
    void BIT_5__HL_();
    void BIT_5_A();
    void BIT_6_B();
    void BIT_6_C();
    void BIT_6_D();
    void BIT_6_E();
    void BIT_6_H();
    void BIT_6_L();
    void BIT_6__HL_();
    void BIT_6_A();
    void BIT_7_B();
    void BIT_7_C();
    void BIT_7_D();
    void BIT_7_E();
    void BIT_7_H();
    void BIT_7_L();
    void BIT_7__HL_();
    void BIT_7_A();
    void RES_0_B();
    void RES_0_C();
    void RES_0_D();
    void RES_0_E();
    void RES_0_H();
    void RES_0_L();
    void RES_0__HL_();
    void RES_0_A();
    void RES_1_B();
    void RES_1_C();
    void RES_1_D();
    void RES_1_E();
    void RES_1_H();
    void RES_1_L();
    void RES_1__HL_();
    void RES_1_A();
    void RES_2_B();
    void RES_2_C();
    void RES_2_D();
    void RES_2_E();
    void RES_2_H();
    void RES_2_L();
    void RES_2__HL_();
    void RES_2_A();
    void RES_3_B();
    void RES_3_C();
    void RES_3_D();
    void RES_3_E();
    void RES_3_H();
    void RES_3_L();
    void RES_3__HL_();
    void RES_3_A();
    void RES_4_B();
    void RES_4_C();
    void RES_4_D();
    void RES_4_E();
    void RES_4_H();
    void RES_4_L();
    void RES_4__HL_();
    void RES_4_A();
    void RES_5_B();
    void RES_5_C();
    void RES_5_D();
    void RES_5_E();
    void RES_5_H();
    void RES_5_L();
    void RES_5__HL_();
    void RES_5_A();
    void RES_6_B();
    void RES_6_C();
    void RES_6_D();
    void RES_6_E();
    void RES_6_H();
    void RES_6_L();
    void RES_6__HL_();
    void RES_6_A();
    void RES_7_B();
    void RES_7_C();
    void RES_7_D();
    void RES_7_E();
    void RES_7_H();
    void RES_7_L();
    void RES_7__HL_();
    void RES_7_A();
    void SET_0_B();
    void SET_0_C();
    void SET_0_D();
    void SET_0_E();
    void SET_0_H();
    void SET_0_L();
    void SET_0__HL_();
    void SET_0_A();
    void SET_1_B();
    void SET_1_C();
    void SET_1_D();
    void SET_1_E();
    void SET_1_H();
    void SET_1_L();
    void SET_1__HL_();
    void SET_1_A();
    void SET_2_B();
    void SET_2_C();
    void SET_2_D();
    void SET_2_E();
    void SET_2_H();
    void SET_2_L();
    void SET_2__HL_();
    void SET_2_A();
    void SET_3_B();
    void SET_3_C();
    void SET_3_D();
    void SET_3_E();
    void SET_3_H();
    void SET_3_L();
    void SET_3__HL_();
    void SET_3_A();
    void SET_4_B();
    void SET_4_C();
    void SET_4_D();
    void SET_4_E();
    void SET_4_H();
    void SET_4_L();
    void SET_4__HL_();
    void SET_4_A();
    void SET_5_B();
    void SET_5_C();
    void SET_5_D();
    void SET_5_E();
    void SET_5_H();
    void SET_5_L();
    void SET_5__HL_();
    void SET_5_A();
    void SET_6_B();
    void SET_6_C();
    void SET_6_D();
    void SET_6_E();
    void SET_6_H();
    void SET_6_L();
    void SET_6__HL_();
    void SET_6_A();
    void SET_7_B();
    void SET_7_C();
    void SET_7_D();
    void SET_7_E();
    void SET_7_H();
    void SET_7_L();
    void SET_7__HL_();
    void SET_7_A();
};

#endif // LR35902_H
