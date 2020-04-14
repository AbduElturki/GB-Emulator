#include "lr35902.h"

void LR35902::NOP()
{
    machine_cycle = 1;
}


void LR35902::LD_BC_d16()
{
    LoadFromMemory(BC.word);
}


void LR35902::LD__BC__A()
{
    LoadToMemory(AF.high,BC.word);
}


void LR35902::INC_BC()
{
    IncrementRegister(BC.word); 
}


void LR35902::INC_B()
{
    IncrementRegister(BC.high);
}


void LR35902::DEC_B()
{
    DecrementRegister(BC.high);
}


void LR35902::LD_B_d8()
{
    LoadFromMemory(BC.high);
}


void LR35902::RLCA()
{
    AF.low = (AF.high&0x80)?0x10:0;
    AF.high = (AF.high<<1) | (AF.high>>7);
    if (AF.high == 0) AF.low = 0x80;
    machine_cycle = 1;
}


void LR35902::LD__a16__SP()
{
    mmu->WriteWord(mmu->ReadWord(PC.word), SP.word);
    PC.word += 2;
    machine_cycle = 5;
}


void LR35902::ADD_HL_BC()
{
    AddToHL(BC.word);
}


void LR35902::LD_A__BC_()
{
    LoadFromMemory(AF.high,BC.word);
}


void LR35902::DEC_BC()
{
    DecrementRegister(BC.word);
}


void LR35902::INC_C()
{
    IncrementRegister(BC.low);
}


void LR35902::DEC_C()
{
    DecrementRegister(BC.low);
}


void LR35902::LD_C_d8()
{
    LoadFromMemory(BC.low);
}


void LR35902::RRCA()
{
    AF.low = (AF.high&0x1)?0x10:0;
    AF.high = (AF.high>>1) | ((AF.high&0x1)<<7);
    if(AF.high == 0) AF.low = 0x80;
    machine_cycle = 1;
}


void LR35902::STOP_0()
{
    machine_cycle = 1;
}


void LR35902::LD_DE_d16()
{
    LoadFromMemory(DE.word);
}


void LR35902::LD__DE__A()
{
    LoadToMemory(AF.high,DE.word);
}


void LR35902::INC_DE()
{
    IncrementRegister(DE.word);
}


void LR35902::INC_D()
{
    IncrementRegister(DE.high);
}


void LR35902::DEC_D()
{
    DecrementRegister(DE.high);
}


void LR35902::LD_D_d8()
{
    LoadFromMemory(DE.high);
}


void LR35902::RLA()
{
    AF.low = (AF.high&0x80)?0x10:0;
    AF.high = (AF.high << 1) | ((AF.low&0x10) >> 4);
    machine_cycle = 1;
}


void LR35902::JR_r8()
{
    JumpRelative(true);
}


void LR35902::ADD_HL_DE()
{
    AddToHL(DE.word);
}


void LR35902::LD_A__DE_()
{
    LoadFromMemory(AF.high,DE.word);
}


void LR35902::DEC_DE()
{
    DecrementRegister(DE.word);
}


void LR35902::INC_E()
{
    IncrementRegister(DE.low);
}


void LR35902::DEC_E()
{
    DecrementRegister(DE.low);
}


void LR35902::LD_E_d8()
{
    LoadFromMemory(DE.low);
}


void LR35902::RRA()
{
    AF.low = (AF.high&0x80)?0x10:0;
    AF.high = (AF.high >> 1) | ((AF.low&0x10) << 3);
    machine_cycle = 1;
}


void LR35902::JR_NZ_r8()
{
    JumpRelative((AF.low & 0x80) == 0);
}


void LR35902::LD_HL_d16()
{
    LoadFromMemory(HL.word);
}


void LR35902::LD__HL_PLUS___A()
{
    LoadFromMemory(AF.high,HL.word++);
}


void LR35902::INC_HL()
{
    IncrementRegister(HL.word);
}


void LR35902::INC_H()
{
    IncrementRegister(HL.high);
}


void LR35902::DEC_H()
{
    DecrementRegister(HL.high);
}


void LR35902::LD_H_d8()
{
    LoadFromMemory(HL.high);
}


void LR35902::DAA()
{
    /*
     This instruction adjusts register A so that the  correct representation 
     of Binary Coded Decimal (BCD)  is obtained.
     */

    //Check if N flag equals to 0
    if (!(AF.low&0x40))
    {
        //Check carry flag
        if ((AF.low&0x10)||(AF.high>0x99))
        {
            AF.high+=0x60;
            AF.low |= 0x10; //Set carry flag if it is reset 
        }
        //Check half carry flag
        if ((AF.low&0x20)||((AF.high&0x0F)>0x09)) AF.high+=0x6;
    }
    else
    {
        if (AF.low&0x10) AF.high-=0x60;
        if (AF.low&0x20) AF.high-=0x6;
    }

    AF.low &= 0x5F; //Reset only half carry
    AF.low |= AF.high?0:0x80; //Set Z flag if it is reg A is 0
}


void LR35902::JR_Z_r8()
{
    JumpRelative(AF.low & 0x80);
}


void LR35902::ADD_HL_HL()
{
    AddToHL(HL.word);
}


void LR35902::LD_A__HL_PLUS__()
{
    LoadFromMemory(AF.high,HL.word++);
}


void LR35902::DEC_HL()
{
    DecrementRegister(HL.word);
}


void LR35902::INC_L()
{
    IncrementRegister(HL.low);
}


void LR35902::DEC_L()
{
    DecrementRegister(HL.low);
}


void LR35902::LD_L_d8()
{
    LoadToMemory(HL.low);
}


void LR35902::CPL()
{
//TODO
}


void LR35902::JR_NC_r8()
{
    JumpRelative((AF.low & 0x10) == 0);
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
    IncrementRegister(SP.word);
}


void LR35902::INC__HL_()
{
    AF.low &= 0x10;
    AF.low |= (((mmu->ReadByte(HL.word)&0xF) + 1) == 0x10)?0x20:0;
    AF.low |= mmu->ReadByte(HL.word)?0:0x80;
    mmu->WriteByte(HL.word, mmu->ReadByte(HL.word)+1);
    machine_cycle = 3;
}


void LR35902::DEC__HL_()
{
    AF.low &= 0x10;
    AF.low |= 0x40;
    mmu->WriteByte(HL.word, mmu->ReadByte(HL.word)-1);
    AF.low |= ((mmu->ReadByte(HL.word) &0xF) == 0xF)?0x20:0;
    AF.low |= mmu->ReadByte(HL.word)?0:0x80;
    machine_cycle = 3;
}


void LR35902::LD__HL__d8()
{
    LoadToMemory(mmu->ReadByte(PC.word), HL.word);
    PC.word++;
    machine_cycle = 3;
}


void LR35902::SCF()
{
    AF.low &= 0x80;
    AF.low |= 0x10;
    machine_cycle = 1;
}


void LR35902::JR_C_r8()
{
    JumpRelative(AF.low & 0x10);
}


void LR35902::ADD_HL_SP()
{
    AddToHL(SP.word);
}


void LR35902::LD_A__HL_MINUS__()
{
    LoadFromMemory(AF.high, HL.word--);
}


void LR35902::DEC_SP()
{
    DecrementRegister(SP.word);
}


void LR35902::INC_A()
{
    IncrementRegister(AF.high);
}


void LR35902::DEC_A()
{
    DecrementRegister(AF.high);
}


void LR35902::LD_A_d8()
{
    LoadFromMemory(AF.high);
}


void LR35902::CCF()
{
    //Complement carry flag
    AF.low = (AF.low & 0x80) | ((!AF.low)&0x10);
    machine_cycle = 1;
}


void LR35902::LD_B_B()
{
    machine_cycle = 1;
}


void LR35902::LD_B_C()
{
    LoadFromRegister(BC.high, BC.low);
}


void LR35902::LD_B_D()
{
    LoadFromRegister(BC.high, DE.high);
}


void LR35902::LD_B_E()
{
    LoadFromRegister(BC.high, DE.low);
}


void LR35902::LD_B_H()
{
    LoadFromRegister(BC.high, HL.high);
}


void LR35902::LD_B_L()
{
    LoadFromRegister(BC.high, HL.low);
}


void LR35902::LD_B__HL_()
{
    LoadFromMemory(BC.high, HL.word);
}


void LR35902::LD_B_A()
{
    LoadFromRegister(BC.high, AF.high);
}


void LR35902::LD_C_B()
{
    LoadFromRegister(BC.low, BC.high);
}


void LR35902::LD_C_C()
{
    machine_cycle = 1;
}


void LR35902::LD_C_D()
{
    LoadFromRegister(BC.low, DE.high);
}


void LR35902::LD_C_E()
{
    LoadFromRegister(BC.low, DE.low);
}


void LR35902::LD_C_H()
{
    LoadFromRegister(BC.low, HL.high);
}


void LR35902::LD_C_L()
{
    LoadFromRegister(BC.low, HL.low);
}


void LR35902::LD_C__HL_()
{
    LoadFromMemory(BC.low, HL.word);
}


void LR35902::LD_C_A()
{
    LoadFromRegister(BC.low, AF.high);
}


void LR35902::LD_D_B()
{
    LoadFromRegister(DE.high, BC.high);
}


void LR35902::LD_D_C()
{
    LoadFromRegister(DE.high, BC.low);
}


void LR35902::LD_D_D()
{
    machine_cycle = 1;
}


void LR35902::LD_D_E()
{
    LoadFromRegister(DE.high, DE.low);
}


void LR35902::LD_D_H()
{
    LoadFromRegister(DE.high, HL.high);
}


void LR35902::LD_D_L()
{
    LoadFromRegister(DE.high, HL.low);
}


void LR35902::LD_D__HL_()
{
    LoadFromMemory(DE.high, HL.word);
}


void LR35902::LD_D_A()
{
    LoadFromRegister(DE.high, AF.high);
}


void LR35902::LD_E_B()
{
    LoadFromRegister(DE.low, BC.high);
}


void LR35902::LD_E_C()
{
    LoadFromRegister(DE.low, BC.low);
}


void LR35902::LD_E_D()
{
    LoadFromRegister(DE.low, DE.high);
}


void LR35902::LD_E_E()
{
    machine_cycle = 1;
}


void LR35902::LD_E_H()
{
    LoadFromRegister(DE.low, HL.high);
}


void LR35902::LD_E_L()
{
    LoadFromRegister(DE.low, HL.low);
}


void LR35902::LD_E__HL_()
{
    LoadFromMemory(DE.low, HL.word);
}


void LR35902::LD_E_A()
{
    LoadFromRegister(DE.low, AF.high);
}


void LR35902::LD_H_B()
{
    LoadFromRegister(HL.high, BC.high);
}


void LR35902::LD_H_C()
{
    LoadFromRegister(HL.high, BC.low);
}


void LR35902::LD_H_D()
{
    LoadFromRegister(HL.high, DE.high);
}


void LR35902::LD_H_E()
{
    LoadFromRegister(HL.high, DE.low);
}


void LR35902::LD_H_H()
{
    machine_cycle = 1;
}


void LR35902::LD_H_L()
{
    LoadFromRegister(HL.high, HL.low);
}


void LR35902::LD_H__HL_()
{
    LoadFromMemory(HL.high, HL.word);
}


void LR35902::LD_H_A()
{
    LoadFromRegister(HL.high, AF.high);
}


void LR35902::LD_L_B()
{
    LoadFromRegister(HL.low, BC.high);
}


void LR35902::LD_L_C()
{
    LoadFromRegister(HL.low, BC.low);
}


void LR35902::LD_L_D()
{
    LoadFromRegister(HL.low, DE.high);
}


void LR35902::LD_L_E()
{
    LoadFromRegister(HL.low, DE.low);
}


void LR35902::LD_L_H()
{
    LoadFromRegister(HL.low, HL.high);
}


void LR35902::LD_L_L()
{
    machine_cycle = 1;
}


void LR35902::LD_L__HL_()
{
    LoadFromMemory(HL.low, HL.word);
}


void LR35902::LD_L_A()
{
    LoadFromRegister(HL.low, AF.high);
}


void LR35902::LD__HL__B()
{
    LoadToMemory(BC.high,HL.word);
}


void LR35902::LD__HL__C()
{
    LoadToMemory(BC.low, HL.word);
}


void LR35902::LD__HL__D()
{
    LoadToMemory(DE.high, HL.word);
}


void LR35902::LD__HL__E()
{
    LoadToMemory(DE.low, HL.word);
}


void LR35902::LD__HL__H()
{
    LoadToMemory(HL.high, HL.word);
}


void LR35902::LD__HL__L()
{
    LoadToMemory(HL.low, HL.word);
}


void LR35902::HALT()
{
    //TODO
}


void LR35902::LD__HL__A()
{
    LoadToMemory(AF.high, HL.word);
}


void LR35902::LD_A_B()
{
    LoadFromRegister(AF.high, BC.high);
}


void LR35902::LD_A_C()
{
    LoadFromRegister(AF.high, BC.low);
}


void LR35902::LD_A_D()
{
    LoadFromRegister(AF.high, DE.high);
}


void LR35902::LD_A_E()
{
    LoadFromRegister(AF.high, DE.low);
}


void LR35902::LD_A_H()
{
    LoadFromRegister(AF.high, HL.high);
}


void LR35902::LD_A_L()
{
    LoadFromRegister(AF.high, HL.low);
}


void LR35902::LD_A__HL_()
{
    LoadToMemory(AF.high, HL.word);
}


void LR35902::LD_A_A()
{
    machine_cycle = 1;
}


void LR35902::ADD_A_B()
{
    AddToA(BC.high);
}


void LR35902::ADD_A_C()
{
    AddToA(BC.low);
}


void LR35902::ADD_A_D()
{
    AddToA(DE.high);
}


void LR35902::ADD_A_E()
{
    AddToA(DE.low);
}


void LR35902::ADD_A_H()
{
    AddToA(HL.high);
}


void LR35902::ADD_A_L()
{
    AddToA(HL.low);
}


void LR35902::ADD_A__HL_()
{
    AddToA(HL.word);
}


void LR35902::ADD_A_A()
{
    AddToA(AF.high);
}


void LR35902::ADC_A_B()
{
    AddCarryToA(BC.high);
}


void LR35902::ADC_A_C()
{
    AddCarryToA(BC.low);
}


void LR35902::ADC_A_D()
{
    AddCarryToA(DE.high);
}


void LR35902::ADC_A_E()
{
    AddCarryToA(DE.low);
}


void LR35902::ADC_A_H()
{
    AddCarryToA(HL.high);
}


void LR35902::ADC_A_L()
{
    AddCarryToA(HL.low);
}


void LR35902::ADC_A__HL_()
{
    AddCarryToA(HL.word);
}


void LR35902::ADC_A_A()
{
    AddCarryToA(AF.high);
}


void LR35902::SUB_B()
{
    SubFromA(BC.high);
}


void LR35902::SUB_C()
{
    SubFromA(BC.low);
}


void LR35902::SUB_D()
{
    SubFromA(DE.high);
}


void LR35902::SUB_E()
{
    SubFromA(DE.low);
}


void LR35902::SUB_H()
{
    SubFromA(HL.high);
}


void LR35902::SUB_L()
{
    SubFromA(HL.low);
}


void LR35902::SUB__HL_()
{
    SubFromA(HL.word);
}


void LR35902::SUB_A()
{
    SubFromA(AF.high);
}


void LR35902::SBC_A_B()
{
    SubCarryFromA(BC.high);
}


void LR35902::SBC_A_C()
{
    SubCarryFromA(BC.low);
}


void LR35902::SBC_A_D()
{
    SubCarryFromA(DE.high);
}


void LR35902::SBC_A_E()
{
    SubCarryFromA(DE.low);
}


void LR35902::SBC_A_H()
{
    SubCarryFromA(HL.high);
}


void LR35902::SBC_A_L()
{
    SubCarryFromA(HL.low);
}


void LR35902::SBC_A__HL_()
{
    SubCarryFromA(HL.word);
}


void LR35902::SBC_A_A()
{
    SubCarryFromA(AF.high);
}


void LR35902::AND_B()
{
    AndWithA(BC.high);
}


void LR35902::AND_C()
{
    AndWithA(BC.low);
}


void LR35902::AND_D()
{
    AndWithA(DE.high);
}


void LR35902::AND_E()
{
    AndWithA(DE.low);
}


void LR35902::AND_H()
{
    AndWithA(HL.high);
}


void LR35902::AND_L()
{
    AndWithA(HL.low);
}


void LR35902::AND__HL_()
{
    AndWithA(HL.word);
}


void LR35902::AND_A()
{
    AndWithA(AF.high);
}


void LR35902::XOR_B()
{
    XorWithA(BC.high);
}


void LR35902::XOR_C()
{
    XorWithA(BC.low);
}


void LR35902::XOR_D()
{
    XorWithA(DE.high);
}


void LR35902::XOR_E()
{
    XorWithA(DE.low);
}


void LR35902::XOR_H()
{
    XorWithA(HL.high);
}


void LR35902::XOR_L()
{
    XorWithA(HL.low);
}


void LR35902::XOR__HL_()
{
    XorWithA(HL.word);
}


void LR35902::XOR_A()
{
    XorWithA(AF.high);
}


void LR35902::OR_B()
{
    OrWithA(BC.high);
}


void LR35902::OR_C()
{
    OrWithA(BC.low);
}


void LR35902::OR_D()
{
    OrWithA(DE.high);
}


void LR35902::OR_E()
{
    OrWithA(DE.low);
}


void LR35902::OR_H()
{
    OrWithA(HL.high);
}


void LR35902::OR_L()
{
    OrWithA(HL.low);
}


void LR35902::OR__HL_()
{
    OrWithA(HL.word);
}


void LR35902::OR_A()
{
    OrWithA(AF.high);
}


void LR35902::CP_B()
{
    CompareToA(BC.high);
}


void LR35902::CP_C()
{
    CompareToA(BC.low);
}


void LR35902::CP_D()
{
    CompareToA(DE.high);
}


void LR35902::CP_E()
{
    CompareToA(DE.low);
}


void LR35902::CP_H()
{
    CompareToA(HL.high);
}


void LR35902::CP_L()
{
    CompareToA(HL.low);
}


void LR35902::CP__HL_()
{
    CompareToA(HL.word);
}


void LR35902::CP_A()
{
    AF.low = 0xC0;
    machine_cycle = 1;
}


void LR35902::RET_NZ()
{
    ReturnFunc((AF.low & 0x80) == 0);
}


void LR35902::POP_BC()
{
    PopRegister(BC.word);
}


void LR35902::JP_NZ_a16()
{
    Jump((AF.low & 0x80) == 0);
}


void LR35902::JP_a16()
{
    Jump(true);
}


void LR35902::CALL_NZ_a16()
{
    Call((AF.low & 0x80) == 0);
}


void LR35902::PUSH_BC()
{
    PushRegister(BC.word);
}


void LR35902::ADD_A_d8()
{
    AddToA(PC.word++);
}


void LR35902::RST_00H()
{
    Restart(0x00);
}


void LR35902::RET_Z()
{
    ReturnFunc(AF.low & 0x80);
}


void LR35902::RET()
{
    ReturnFunc(true);
}


void LR35902::JP_Z_a16()
{
    Jump(AF.low & 0x80);
}


void LR35902::PREFIX_CB()
{
    //TODO
}


void LR35902::CALL_Z_a16()
{
    Call(AF.low & 0x80);
}


void LR35902::CALL_a16()
{
    Call(true);
}


void LR35902::ADC_A_d8()
{
    AddCarryToA(PC.word++);
}


void LR35902::RST_08H()
{
    Restart(0x08);
}


void LR35902::RET_NC()
{
    ReturnFunc((AF.low & 0x10) == 0);
}


void LR35902::POP_DE()
{
    PopRegister(DE.word);
}


void LR35902::JP_NC_a16()
{
    Jump((AF.low & 0x10) == 0);
}


void LR35902::CALL_NC_a16()
{
    Call((AF.low & 0x10) == 0);
}


void LR35902::PUSH_DE()
{
    PushRegister(DE.word);
}


void LR35902::SUB_d8()
{
    SubFromA(PC.word++);
}


void LR35902::RST_10H()
{
    Restart(0x10);
}


void LR35902::RET_C()
{
    ReturnFunc(AF.low & 0x10);
}


void LR35902::RETI()
{
    //TODO
}


void LR35902::JP_C_a16()
{
    Jump(AF.low & 0x10);
}


void LR35902::CALL_C_a16()
{
    Call(AF.low & 0x10);
}


void LR35902::SBC_A_d8()
{
    SubCarryFromA(PC.word++);
}


void LR35902::RST_1_8H()
{
    Call(0x18);
}


void LR35902::LDH__a8__A()
{
    uint8_t n = mmu->ReadByte(PC.word++);
    mmu->WriteByte((0xFF00|n),AF.high);
    machine_cycle = 3;
}


void LR35902::POP_HL()
{
    PopRegister(HL.word);
}


void LR35902::LD__C__A()
{
    LoadToMemory(AF.high,(0xFF00|BC.low));
}


void LR35902::PUSH_HL()
{
    PushRegister(HL.word);
}


void LR35902::AND_d8()
{
    AndWithA(PC.word++);
}


void LR35902::RST_20H()
{
    Restart(0x20);
}


void LR35902::ADD_SP_r8()
{
    uint8_t n = mmu->ReadByte(PC.word++);
    //Half carry
    AF.low = (((SP.word&0xFFF) + (n&0xFFF) & 0x1000) == 0x1000)?0x20:0;
    SP.word += n;
    //Carry
    AF.low |= (SP.word < n)?0x10:0;
    machine_cycle = 4;
}


void LR35902::JP__HL_()
{
    PC.word = mmu->ReadWord(HL.word);
    machine_cycle = 1;
}


void LR35902::LD__a16__A()
{
    mmu->WriteByte(mmu->ReadByte(PC.word), AF.high);
    PC.word += 2;
    machine_cycle = 4;
}


void LR35902::XOR_d8()
{
    XorWithA(PC.word++);
}


void LR35902::RST_2_8H()
{
    Restart(0x28);
}


void LR35902::LDH_A__a8_()
{
    uint8_t n = mmu->ReadByte(PC.word++);
    AF.high = mmu->ReadByte(0xFF00|n);
    machine_cycle = 3;
}


void LR35902::POP_AF()
{
    PopRegister(AF.word);
}


void LR35902::LD_A__C_()
{
    LoadFromMemory(AF.high,(0xFF00|BC.low));
}


void LR35902::DI()
{
    //TODO
}


void LR35902::PUSH_AF()
{
    PushRegister(AF.word);
}


void LR35902::OR_d8()
{
    OrWithA(PC.word++);
}


void LR35902::RST_30H()
{
    Restart(0x30);
}


void LR35902::LD_HL_SP_PLUS_r8()
{
    uint8_t n = mmu->ReadByte(PC.word++);
    //Half carry
    AF.low = (((SP.word&0xFFF) + (n&0xFFF) & 0x1000) == 0x1000)?0x20:0;
    HL.word = SP.word + n;
    //Carry
    AF.low |= (HL.word < SP.word)?0x10:0;
    machine_cycle = 3;
}


void LR35902::LD_SP_HL()
{
    SP.word = HL.word;
    machine_cycle = 2;
}


void LR35902::LD_A__a16_()
{
    uint8_t nn = mmu->ReadWord(PC.word);
    PC.word += 2;
    LoadFromMemory(AF.high,nn);
}


void LR35902::EI()
{
    //TODO
}


void LR35902::CP_d8()
{
    CompareToA(PC.word++);
}


void LR35902::RST_38H()
{
    Restart(0x38);
}

void LR35902::INVALID()
{
    //TODO
}
