#include "lr35902.h"

void LR35902::RLC_B()
{
    RotateLeftCarry(BC.high);
}


void LR35902::RLC_C()
{
    RotateLeftCarry(BC.low);
}


void LR35902::RLC_D()
{
    RotateLeftCarry(DE.high);
}


void LR35902::RLC_E()
{
    RotateLeftCarry(DE.low);
}


void LR35902::RLC_H()
{
    RotateLeftCarry(HL.high);
}


void LR35902::RLC_L()
{
    RotateLeftCarry(HL.low);
}


void LR35902::RLC__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    n = (n << 1) | (n >> 7);
    AF.low = (n&0x1)?0x10:0;
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word, n);
    machine_cycle = 4;
}


void LR35902::RLC_A()
{
    RotateLeftCarry(AF.high);
}


void LR35902::RRC_B()
{
    RotateRightCarry(BC.high);
}


void LR35902::RRC_C()
{
    RotateRightCarry(BC.low);
}


void LR35902::RRC_D()
{
    RotateRightCarry(DE.high);
}


void LR35902::RRC_E()
{
    RotateRightCarry(DE.low);
}


void LR35902::RRC_H()
{
    RotateRightCarry(HL.high);
}


void LR35902::RRC_L()
{
    RotateRightCarry(HL.low);
}


void LR35902::RRC__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    n = (n >> 1) | (n << 7);
    AF.low = (n&0x80)?0x10:0;
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word, n);
    machine_cycle = 4;
}


void LR35902::RRC_A()
{
    RotateRightCarry(AF.high);
}


void LR35902::RL_B()
{
    RotateLeft(BC.high);
}


void LR35902::RL_C()
{
    RotateLeft(BC.low);
}


void LR35902::RL_D()
{
    RotateLeft(DE.high);
}


void LR35902::RL_E()
{
    RotateLeft(DE.low);
}


void LR35902::RL_H()
{
    RotateLeft(HL.high);
}


void LR35902::RL_L()
{
    RotateLeft(HL.low);
}


void LR35902::RL__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = (n&0x80)?0x10:0;
    n = (n << 1) | ((AF.low&0x10) >> 4);
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word, n);
    machine_cycle = 4;
}


void LR35902::RL_A()
{
    RotateLeft(AF.high);
}


void LR35902::RR_B()
{
    RotateRight(BC.high);
}


void LR35902::RR_C()
{
    RotateRight(BC.low);
}


void LR35902::RR_D()
{
    RotateRight(DE.high);
}


void LR35902::RR_E()
{
    RotateRight(DE.low);
}


void LR35902::RR_H()
{
    RotateRight(HL.high);
}


void LR35902::RR_L()
{
    RotateRight(HL.low);
}


void LR35902::RR__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = (n&0x1)?0x10:0;
    n = (n >> 1) | ((AF.low&0x10) << 3);
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word, n);
    machine_cycle = 4;
}


void LR35902::RR_A()
{
    RotateRight(AF.high);
}


void LR35902::SLA_B()
{
    ShiftLeft(BC.high);
}


void LR35902::SLA_C()
{
    ShiftLeft(BC.low);
}


void LR35902::SLA_D()
{
    ShiftLeft(DE.high);
}


void LR35902::SLA_E()
{
    ShiftLeft(DE.low);
}


void LR35902::SLA_H()
{
    ShiftLeft(HL.high);
}


void LR35902::SLA_L()
{
    ShiftLeft(HL.low);
}


void LR35902::SLA__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = (n&0x80)?0x10:0;
    n = (n << 1);
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word,n);
    machine_cycle = 4;
}


void LR35902::SLA_A()
{
    ShiftLeft(AF.high);
}


void LR35902::SRA_B()
{
    ShiftRightNoChange(BC.high);
}


void LR35902::SRA_C()
{
    ShiftRightNoChange(BC.low);
}


void LR35902::SRA_D()
{
    ShiftRightNoChange(DE.high);
}


void LR35902::SRA_E()
{
    ShiftRightNoChange(DE.low);
}


void LR35902::SRA_H()
{
    ShiftRightNoChange(HL.high);
}


void LR35902::SRA_L()
{
    ShiftRightNoChange(HL.low);
}


void LR35902::SRA__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = (n&0x1)?0x10:0;
    n = (n&0x80) | (n >> 1);
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word,n);
    machine_cycle = 4;
}


void LR35902::SRA_A()
{
    ShiftRightNoChange(AF.high);
}


void LR35902::SWAP_B()
{
    Swap(BC.high);
}


void LR35902::SWAP_C()
{
    Swap(BC.low);
}


void LR35902::SWAP_D()
{
    Swap(DE.high);
}


void LR35902::SWAP_E()
{
    Swap(DE.low);
}


void LR35902::SWAP_H()
{
    Swap(HL.high);
}


void LR35902::SWAP_L()
{
    Swap(HL.low);
}


void LR35902::SWAP__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = n?0:0x80;
    n = ((n&0xF0) >> 4) | ((n&0xF) << 4);
    n |= n?0:0x80;
    mmu->WriteByte(HL.word,n);
    machine_cycle = 4;
}


void LR35902::SWAP_A()
{
    Swap(AF.high);
}


void LR35902::SRL_B()
{
    ShiftRight(BC.high);
}


void LR35902::SRL_C()
{
    ShiftRight(BC.low);
}


void LR35902::SRL_D()
{
    ShiftRight(DE.high);
}


void LR35902::SRL_E()
{
    ShiftRight(DE.low);
}


void LR35902::SRL_H()
{
    ShiftRight(HL.high);
}


void LR35902::SRL_L()
{
    ShiftRight(HL.low);
}


void LR35902::SRL__HL_()
{
    uint8_t n = mmu->ReadByte(HL.word);
    AF.low = (n&0x1)?0x10:0;
    n = n >> 1;
    AF.low |= n?0:0x80;
    mmu->WriteByte(HL.word,n);
    machine_cycle = 4;
}


void LR35902::SRL_A()
{
    ShiftRight(AF.high);
}


void LR35902::BIT_0_B()
{
}


void LR35902::BIT_0_C()
{
}


void LR35902::BIT_0_D()
{
}


void LR35902::BIT_0_E()
{
}


void LR35902::BIT_0_H()
{
}


void LR35902::BIT_0_L()
{
}


void LR35902::BIT_0__HL_()
{
}


void LR35902::BIT_0_A()
{
}


void LR35902::BIT_1_B()
{
}


void LR35902::BIT_1_C()
{
}


void LR35902::BIT_1_D()
{
}


void LR35902::BIT_1_E()
{
}


void LR35902::BIT_1_H()
{
}


void LR35902::BIT_1_L()
{
}


void LR35902::BIT_1__HL_()
{
}


void LR35902::BIT_1_A()
{
}


void LR35902::BIT_2_B()
{
}


void LR35902::BIT_2_C()
{
}


void LR35902::BIT_2_D()
{
}


void LR35902::BIT_2_E()
{
}


void LR35902::BIT_2_H()
{
}


void LR35902::BIT_2_L()
{
}


void LR35902::BIT_2__HL_()
{
}


void LR35902::BIT_2_A()
{
}


void LR35902::BIT_3_B()
{
}


void LR35902::BIT_3_C()
{
}


void LR35902::BIT_3_D()
{
}


void LR35902::BIT_3_E()
{
}


void LR35902::BIT_3_H()
{
}


void LR35902::BIT_3_L()
{
}


void LR35902::BIT_3__HL_()
{
}


void LR35902::BIT_3_A()
{
}


void LR35902::BIT_4_B()
{
}


void LR35902::BIT_4_C()
{
}


void LR35902::BIT_4_D()
{
}


void LR35902::BIT_4_E()
{
}


void LR35902::BIT_4_H()
{
}


void LR35902::BIT_4_L()
{
}


void LR35902::BIT_4__HL_()
{
}


void LR35902::BIT_4_A()
{
}


void LR35902::BIT_5_B()
{
}


void LR35902::BIT_5_C()
{
}


void LR35902::BIT_5_D()
{
}


void LR35902::BIT_5_E()
{
}


void LR35902::BIT_5_H()
{
}


void LR35902::BIT_5_L()
{
}


void LR35902::BIT_5__HL_()
{
}


void LR35902::BIT_5_A()
{
}


void LR35902::BIT_6_B()
{
}


void LR35902::BIT_6_C()
{
}


void LR35902::BIT_6_D()
{
}


void LR35902::BIT_6_E()
{
}


void LR35902::BIT_6_H()
{
}


void LR35902::BIT_6_L()
{
}


void LR35902::BIT_6__HL_()
{
}


void LR35902::BIT_6_A()
{
}


void LR35902::BIT_7_B()
{
}


void LR35902::BIT_7_C()
{
}


void LR35902::BIT_7_D()
{
}


void LR35902::BIT_7_E()
{
}


void LR35902::BIT_7_H()
{
}


void LR35902::BIT_7_L()
{
}


void LR35902::BIT_7__HL_()
{
}


void LR35902::BIT_7_A()
{
}


void LR35902::RES_0_B()
{
}


void LR35902::RES_0_C()
{
}


void LR35902::RES_0_D()
{
}


void LR35902::RES_0_E()
{
}


void LR35902::RES_0_H()
{
}


void LR35902::RES_0_L()
{
}


void LR35902::RES_0__HL_()
{
}


void LR35902::RES_0_A()
{
}


void LR35902::RES_1_B()
{
}


void LR35902::RES_1_C()
{
}


void LR35902::RES_1_D()
{
}


void LR35902::RES_1_E()
{
}


void LR35902::RES_1_H()
{
}


void LR35902::RES_1_L()
{
}


void LR35902::RES_1__HL_()
{
}


void LR35902::RES_1_A()
{
}


void LR35902::RES_2_B()
{
}


void LR35902::RES_2_C()
{
}


void LR35902::RES_2_D()
{
}


void LR35902::RES_2_E()
{
}


void LR35902::RES_2_H()
{
}


void LR35902::RES_2_L()
{
}


void LR35902::RES_2__HL_()
{
}


void LR35902::RES_2_A()
{
}


void LR35902::RES_3_B()
{
}


void LR35902::RES_3_C()
{
}


void LR35902::RES_3_D()
{
}


void LR35902::RES_3_E()
{
}


void LR35902::RES_3_H()
{
}


void LR35902::RES_3_L()
{
}


void LR35902::RES_3__HL_()
{
}


void LR35902::RES_3_A()
{
}


void LR35902::RES_4_B()
{
}


void LR35902::RES_4_C()
{
}


void LR35902::RES_4_D()
{
}


void LR35902::RES_4_E()
{
}


void LR35902::RES_4_H()
{
}


void LR35902::RES_4_L()
{
}


void LR35902::RES_4__HL_()
{
}


void LR35902::RES_4_A()
{
}


void LR35902::RES_5_B()
{
}


void LR35902::RES_5_C()
{
}


void LR35902::RES_5_D()
{
}


void LR35902::RES_5_E()
{
}


void LR35902::RES_5_H()
{
}


void LR35902::RES_5_L()
{
}


void LR35902::RES_5__HL_()
{
}


void LR35902::RES_5_A()
{
}


void LR35902::RES_6_B()
{
}


void LR35902::RES_6_C()
{
}


void LR35902::RES_6_D()
{
}


void LR35902::RES_6_E()
{
}


void LR35902::RES_6_H()
{
}


void LR35902::RES_6_L()
{
}


void LR35902::RES_6__HL_()
{
}


void LR35902::RES_6_A()
{
}


void LR35902::RES_7_B()
{
}


void LR35902::RES_7_C()
{
}


void LR35902::RES_7_D()
{
}


void LR35902::RES_7_E()
{
}


void LR35902::RES_7_H()
{
}


void LR35902::RES_7_L()
{
}


void LR35902::RES_7__HL_()
{
}


void LR35902::RES_7_A()
{
}


void LR35902::SET_0_B()
{
}


void LR35902::SET_0_C()
{
}


void LR35902::SET_0_D()
{
}


void LR35902::SET_0_E()
{
}


void LR35902::SET_0_H()
{
}


void LR35902::SET_0_L()
{
}


void LR35902::SET_0__HL_()
{
}


void LR35902::SET_0_A()
{
}


void LR35902::SET_1_B()
{
}


void LR35902::SET_1_C()
{
}


void LR35902::SET_1_D()
{
}


void LR35902::SET_1_E()
{
}


void LR35902::SET_1_H()
{
}


void LR35902::SET_1_L()
{
}


void LR35902::SET_1__HL_()
{
}


void LR35902::SET_1_A()
{
}


void LR35902::SET_2_B()
{
}


void LR35902::SET_2_C()
{
}


void LR35902::SET_2_D()
{
}


void LR35902::SET_2_E()
{
}


void LR35902::SET_2_H()
{
}


void LR35902::SET_2_L()
{
}


void LR35902::SET_2__HL_()
{
}


void LR35902::SET_2_A()
{
}


void LR35902::SET_3_B()
{
}


void LR35902::SET_3_C()
{
}


void LR35902::SET_3_D()
{
}


void LR35902::SET_3_E()
{
}


void LR35902::SET_3_H()
{
}


void LR35902::SET_3_L()
{
}


void LR35902::SET_3__HL_()
{
}


void LR35902::SET_3_A()
{
}


void LR35902::SET_4_B()
{
}


void LR35902::SET_4_C()
{
}


void LR35902::SET_4_D()
{
}


void LR35902::SET_4_E()
{
}


void LR35902::SET_4_H()
{
}


void LR35902::SET_4_L()
{
}


void LR35902::SET_4__HL_()
{
}


void LR35902::SET_4_A()
{
}


void LR35902::SET_5_B()
{
}


void LR35902::SET_5_C()
{
}


void LR35902::SET_5_D()
{
}


void LR35902::SET_5_E()
{
}


void LR35902::SET_5_H()
{
}


void LR35902::SET_5_L()
{
}


void LR35902::SET_5__HL_()
{
}


void LR35902::SET_5_A()
{
}


void LR35902::SET_6_B()
{
}


void LR35902::SET_6_C()
{
}


void LR35902::SET_6_D()
{
}


void LR35902::SET_6_E()
{
}


void LR35902::SET_6_H()
{
}


void LR35902::SET_6_L()
{
}


void LR35902::SET_6__HL_()
{
}


void LR35902::SET_6_A()
{
}


void LR35902::SET_7_B()
{
}


void LR35902::SET_7_C()
{
}


void LR35902::SET_7_D()
{
}


void LR35902::SET_7_E()
{
}


void LR35902::SET_7_H()
{
}


void LR35902::SET_7_L()
{
}


void LR35902::SET_7__HL_()
{
}


void LR35902::SET_7_A()
{
}


