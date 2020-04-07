#include "lr35902.h"

void LR35902::NOP()
{
    machine_cycle = 1;
}


void LR35902::LD_BC_d16()
{
    LoadFromMemory(BC.word);
    machine_cycle = 3;
}


void LR35902::LD__BC__A()
{
    LoadToMemory(AF.high,BC.word);
    machine_cycle = 2;
}


void LR35902::INC_BC()
{
    BC.word += 1;
    machine_cycle = 2;
}


void LR35902::INC_B()
{
    BC.high += 1;
    machine_cycle = 1;
}


void LR35902::DEC_B()
{
    BC.high -= 1;
    machine_cycle = 1;
}


void LR35902::LD_B_d8()
{
    LoadFromMemory(BC.high);
    machine_cycle = 2;
}


void LR35902::RLCA()
{
    if (AF.high == 0) AF.low = 0x80;
    else
    {
        this->AF.low = (this->AF.high&0x80)?0x10:0;
        this->AF.high = (this->AF.high<<1) | (this->AF.high>>7);
    }
    machine_cycle = 1;
}


void LR35902::LD__a16__SP()
{
    LoadToMemory(SP.word, mmu->ReadWord(PC.word));
    PC.word += 2;
    machine_cycle = 5;
}


void LR35902::ADD_HL_BC()
{
    AddToHL(BC.word);
    machine_cycle = 2;
}


void LR35902::LD_A__BC_()
{
    LoadFromMemory(AF.high,BC.word);
    machine_cycle = 2;
}


void LR35902::DEC_BC()
{
    BC.word -= 1;
    machine_cycle = 2;
}


void LR35902::INC_C()
{
    BC.low += 1;
    machine_cycle = 1;
}


void LR35902::DEC_C()
{
    BC.low -= 1;
    machine_cycle = 1;
}


void LR35902::LD_C_d8()
{
    LoadFromMemory(BC.low);
    machine_cycle = 2;
}


void LR35902::RRCA()
{
    if(AF.high == 0) AF.low = 0x80;
    else
    {
        AF.low = (AF.high&0x1)?0x10:0;
        AF.high = (AF.high>>1) | ((AF.high&0x1)<<7);
    }
    machine_cycle = 1;
}


void LR35902::STOP_0()
{
    machine_cycle = 1;
}


void LR35902::LD_DE_d16()
{
    LoadFromMemory(DE.word);
    machine_cycle = 3;
}


void LR35902::LD__DE__A()
{
    LoadFromMemory(AF.high,DE.word);
    machine_cycle = 2;
}


void LR35902::INC_DE()
{
    DE.word += 1;
    machine_cycle = 2;
}


void LR35902::INC_D()
{
    DE.high += 1;
    machine_cycle = 1;
}


void LR35902::DEC_D()
{
    DE.high += 1;
    machine_cycle = 1;
}


void LR35902::LD_D_d8()
{
    LoadFromMemory(DE.high);
    machine_cycle = 2;
}


void LR35902::RLA()
{
    AF.low = (AF.high&0x80)?0x10:0;
    AF.high = (AF.high << 1) | ((AF.low&0x10) >> 4);
    machine_cycle = 1;
}


void LR35902::JR_r8()
{
    PC.word += (mmu->ReadByte(PC.word) + 1);
    machine_cycle = 3;
}


void LR35902::ADD_HL_DE()
{
    AddToHL(DE.word);
    machine_cycle = 2;
}


void LR35902::LD_A__DE_()
{
    LoadFromMemory(AF.high,DE.word);
    machine_cycle = 2;
}


void LR35902::DEC_DE()
{
    DE.word -= 1;
    machine_cycle = 2;
}


void LR35902::INC_E()
{
    DE.low += 1;
    machine_cycle = 1;
}


void LR35902::DEC_E()
{
    DE.low -= 1;
    machine_cycle = 1;
}


void LR35902::LD_E_d8()
{
    LoadFromMemory(DE.low);
    machine_cycle = 2;
}


void LR35902::RRA()
{
    AF.low = (AF.high&0x80)?0x10:0;
    AF.high = (AF.high >> 1) | ((AF.low&0x10) << 3);
    machine_cycle = 1;
}


void LR35902::JR_NZ_r8()
{
    if((AF.low & 0x80) == 0)
    {
        PC.word += (mmu->ReadByte(PC.word) + 1);
        machine_cycle = 3;
    } 
    else 
    {
        PC.word += 2;
        machine_cycle = 2;
    }
}


void LR35902::LD_HL_d16()
{
    LoadFromMemory(HL.word);
    machine_cycle = 3;
}


void LR35902::LD__HL_PLUS___A()
{
    LoadFromMemory(AF.high,HL.word++);
    machine_cycle = 2;
}


void LR35902::INC_HL()
{
    HL.word += 1;
    machine_cycle = 2;
}


void LR35902::INC_H()
{
    HL.high += 1;
    machine_cycle = 1;
}


void LR35902::DEC_H()
{
    HL.high -= 1;
    machine_cycle = 1;
}


void LR35902::LD_H_d8()
{
    LoadFromMemory(HL.high);
    machine_cycle = 2;
}


void LR35902::DAA()
{
}


void LR35902::JR_Z_r8()
{
    if(AF.low & 0x80)
    {
        PC.word += (mmu->ReadByte(PC.word) + 1);
        machine_cycle = 3;
    } 
    else 
    {
        PC.word += 2;
        machine_cycle = 2;
    }
}


void LR35902::ADD_HL_HL()
{
    AddToHL(HL.word);
    machine_cycle = 2;
}


void LR35902::LD_A__HL_PLUS__()
{
    LoadFromMemory(AF.high,HL.word++);
    machine_cycle = 2;
}


void LR35902::DEC_HL()
{
    HL.word -= 1;
    machine_cycle = 2;
}


void LR35902::INC_L()
{
    HL.low += 1;
    machine_cycle = 1;
}


void LR35902::DEC_L()
{
    HL.low -= 1;
    machine_cycle = 1;
}


void LR35902::LD_L_d8()
{
    LoadToMemory(HL.low);
    machine_cycle = 2;
}


void LR35902::CPL()
{
}


void LR35902::JR_NC_r8()
{
    if((AF.low & 0x10) == 0)
    {
        PC.word += (mmu->ReadByte(PC.word) + 1);
        machine_cycle = 3;
    } 
    else 
    {
        PC.word += 2;
        machine_cycle = 2;
    }
}


void LR35902::LD_SP_d16()
{
    LoadFromMemory(SP.word);
    machine_cycle = 3;
}


void LR35902::LD__HL_MINUS___A()
{
    LoadToMemory(AF.high, HL.word--);
    machine_cycle = 2;
}


void LR35902::INC_SP()
{
    SP.word += 1;
    machine_cycle = 2;
}


void LR35902::INC__HL_()
{
}


void LR35902::DEC__HL_()
{
}


void LR35902::LD__HL__d8()
{
}


void LR35902::SCF()
{
}


void LR35902::JR_C_r8()
{
}


void LR35902::ADD_HL_SP()
{
}


void LR35902::LD_A__HL_MINUS__()
{
}


void LR35902::DEC_SP()
{
}


void LR35902::INC_A()
{
}


void LR35902::DEC_A()
{
}


void LR35902::LD_A_d8()
{
}


void LR35902::CCF()
{
}


void LR35902::LD_B_B()
{
}


void LR35902::LD_B_C()
{
}


void LR35902::LD_B_D()
{
}


void LR35902::LD_B_E()
{
}


void LR35902::LD_B_H()
{
}


void LR35902::LD_B_L()
{
}


void LR35902::LD_B__HL_()
{
}


void LR35902::LD_B_A()
{
}


void LR35902::LD_C_B()
{
}


void LR35902::LD_C_C()
{
}


void LR35902::LD_C_D()
{
}


void LR35902::LD_C_E()
{
}


void LR35902::LD_C_H()
{
}


void LR35902::LD_C_L()
{
}


void LR35902::LD_C__HL_()
{
}


void LR35902::LD_C_A()
{
}


void LR35902::LD_D_B()
{
}


void LR35902::LD_D_C()
{
}


void LR35902::LD_D_D()
{
}


void LR35902::LD_D_E()
{
}


void LR35902::LD_D_H()
{
}


void LR35902::LD_D_L()
{
}


void LR35902::LD_D__HL_()
{
}


void LR35902::LD_D_A()
{
}


void LR35902::LD_E_B()
{
}


void LR35902::LD_E_C()
{
}


void LR35902::LD_E_D()
{
}


void LR35902::LD_E_E()
{
}


void LR35902::LD_E_H()
{
}


void LR35902::LD_E_L()
{
}


void LR35902::LD_E__HL_()
{
}


void LR35902::LD_E_A()
{
}


void LR35902::LD_H_B()
{
}


void LR35902::LD_H_C()
{
}


void LR35902::LD_H_D()
{
}


void LR35902::LD_H_E()
{
}


void LR35902::LD_H_H()
{
}


void LR35902::LD_H_L()
{
}


void LR35902::LD_H__HL_()
{
}


void LR35902::LD_H_A()
{
}


void LR35902::LD_L_B()
{
}


void LR35902::LD_L_C()
{
}


void LR35902::LD_L_D()
{
}


void LR35902::LD_L_E()
{
}


void LR35902::LD_L_H()
{
}


void LR35902::LD_L_L()
{
}


void LR35902::LD_L__HL_()
{
}


void LR35902::LD_L_A()
{
}


void LR35902::LD__HL__B()
{
}


void LR35902::LD__HL__C()
{
}


void LR35902::LD__HL__D()
{
}


void LR35902::LD__HL__E()
{
}


void LR35902::LD__HL__H()
{
}


void LR35902::LD__HL__L()
{
}


void LR35902::HALT()
{
}


void LR35902::LD__HL__A()
{
}


void LR35902::LD_A_B()
{
}


void LR35902::LD_A_C()
{
}


void LR35902::LD_A_D()
{
}


void LR35902::LD_A_E()
{
}


void LR35902::LD_A_H()
{
}


void LR35902::LD_A_L()
{
}


void LR35902::LD_A__HL_()
{
}


void LR35902::LD_A_A()
{
}


void LR35902::ADD_A_B()
{
}


void LR35902::ADD_A_C()
{
}


void LR35902::ADD_A_D()
{
}


void LR35902::ADD_A_E()
{
}


void LR35902::ADD_A_H()
{
}


void LR35902::ADD_A_L()
{
}


void LR35902::ADD_A__HL_()
{
}


void LR35902::ADD_A_A()
{
}


void LR35902::ADC_A_B()
{
}


void LR35902::ADC_A_C()
{
}


void LR35902::ADC_A_D()
{
}


void LR35902::ADC_A_E()
{
}


void LR35902::ADC_A_H()
{
}


void LR35902::ADC_A_L()
{
}


void LR35902::ADC_A__HL_()
{
}


void LR35902::ADC_A_A()
{
}


void LR35902::SUB_B()
{
}


void LR35902::SUB_C()
{
}


void LR35902::SUB_D()
{
}


void LR35902::SUB_E()
{
}


void LR35902::SUB_H()
{
}


void LR35902::SUB_L()
{
}


void LR35902::SUB__HL_()
{
}


void LR35902::SUB_A()
{
}


void LR35902::SBC_A_B()
{
}


void LR35902::SBC_A_C()
{
}


void LR35902::SBC_A_D()
{
}


void LR35902::SBC_A_E()
{
}


void LR35902::SBC_A_H()
{
}


void LR35902::SBC_A_L()
{
}


void LR35902::SBC_A__HL_()
{
}


void LR35902::SBC_A_A()
{
}


void LR35902::AND_B()
{
}


void LR35902::AND_C()
{
}


void LR35902::AND_D()
{
}


void LR35902::AND_E()
{
}


void LR35902::AND_H()
{
}


void LR35902::AND_L()
{
}


void LR35902::AND__HL_()
{
}


void LR35902::AND_A()
{
}


void LR35902::XOR_B()
{
}


void LR35902::XOR_C()
{
}


void LR35902::XOR_D()
{
}


void LR35902::XOR_E()
{
}


void LR35902::XOR_H()
{
}


void LR35902::XOR_L()
{
}


void LR35902::XOR__HL_()
{
}


void LR35902::XOR_A()
{
}


void LR35902::OR_B()
{
}


void LR35902::OR_C()
{
}


void LR35902::OR_D()
{
}


void LR35902::OR_E()
{
}


void LR35902::OR_H()
{
}


void LR35902::OR_L()
{
}


void LR35902::OR__HL_()
{
}


void LR35902::OR_A()
{
}


void LR35902::CP_B()
{
}


void LR35902::CP_C()
{
}


void LR35902::CP_D()
{
}


void LR35902::CP_E()
{
}


void LR35902::CP_H()
{
}


void LR35902::CP_L()
{
}


void LR35902::CP__HL_()
{
}


void LR35902::CP_A()
{
}


void LR35902::RET_NZ()
{
}


void LR35902::POP_BC()
{
}


void LR35902::JP_NZ_a16()
{
}


void LR35902::JP_a16()
{
}


void LR35902::CALL_NZ_a16()
{
}


void LR35902::PUSH_BC()
{
}


void LR35902::ADD_A_d8()
{
}


void LR35902::RST_00H()
{
}


void LR35902::RET_Z()
{
}


void LR35902::RET()
{
}


void LR35902::JP_Z_a16()
{
}


void LR35902::PREFIX_CB()
{
}


void LR35902::CALL_Z_a16()
{
}


void LR35902::CALL_a16()
{
}


void LR35902::ADC_A_d8()
{
}


void LR35902::RST_08H()
{
}


void LR35902::RET_NC()
{
}


void LR35902::POP_DE()
{
}


void LR35902::JP_NC_a16()
{
}


void LR35902::CALL_NC_a16()
{
}


void LR35902::PUSH_DE()
{
}


void LR35902::SUB_d8()
{
}


void LR35902::RST_10H()
{
}


void LR35902::RET_C()
{
}


void LR35902::RETI()
{
}


void LR35902::JP_C_a16()
{
}


void LR35902::CALL_C_a16()
{
}


void LR35902::SBC_A_d8()
{
}


void LR35902::RST_1_8H()
{
}


void LR35902::LDH__a8__A()
{
}


void LR35902::POP_HL()
{
}


void LR35902::LD__C__A()
{
}


void LR35902::PUSH_HL()
{
}


void LR35902::AND_d8()
{
}


void LR35902::RST_20H()
{
}


void LR35902::ADD_SP_r8()
{
}


void LR35902::JP__HL_()
{
}


void LR35902::LD__a16__A()
{
}


void LR35902::XOR_d8()
{
}


void LR35902::RST_2_8H()
{
}


void LR35902::LDH_A__a8_()
{
}


void LR35902::POP_AF()
{
}


void LR35902::LD_A__C_()
{
}


void LR35902::DI()
{
}


void LR35902::PUSH_AF()
{
}


void LR35902::OR_d8()
{
}


void LR35902::RST_30H()
{
}


void LR35902::LD_HL_SP_PLUS_r8()
{
}


void LR35902::LD_SP_HL()
{
}


void LR35902::LD_A__a16_()
{
}


void LR35902::EI()
{
}


void LR35902::CP_d8()
{
}


void LR35902::RST_38H()
{
}

void LR35902::INVALID()
{
}
