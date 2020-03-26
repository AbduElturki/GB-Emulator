#include <vector>
#ifndef LR35902_H
#define LR35902_H


class LR35902
{
public:
    LR35902();

private:
    std::vector<void (LR35902::*)(void)> opcode_map; 
private:
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
};

#endif // LR35902_H
