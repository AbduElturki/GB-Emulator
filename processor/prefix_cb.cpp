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
    TestBit(BC.high, 0);
}


void LR35902::BIT_0_C()
{
    TestBit(BC.low, 0);
}


void LR35902::BIT_0_D()
{
    TestBit(DE.high, 0);
}


void LR35902::BIT_0_E()
{
    TestBit(DE.low, 0);
}


void LR35902::BIT_0_H()
{
    TestBit(HL.high, 0);
}


void LR35902::BIT_0_L()
{
    TestBit(HL.low, 0);
}


void LR35902::BIT_0__HL_()
{
    TestBit(HL.word, 0);
}


void LR35902::BIT_0_A()
{
    TestBit(AF.high, 0);
}


void LR35902::BIT_1_B()
{
    TestBit(BC.high, 1);
}


void LR35902::BIT_1_C()
{
    TestBit(BC.low, 1);
}


void LR35902::BIT_1_D()
{
    TestBit(DE.high, 1);
}


void LR35902::BIT_1_E()
{
    TestBit(DE.low, 1);
}


void LR35902::BIT_1_H()
{
    TestBit(HL.high, 1);
}


void LR35902::BIT_1_L()
{
    TestBit(HL.low, 1);
}


void LR35902::BIT_1__HL_()
{
    TestBit(HL.word, 1);
}


void LR35902::BIT_1_A()
{
    TestBit(AF.high, 1);
}


void LR35902::BIT_2_B()
{
    TestBit(BC.high, 2);
}


void LR35902::BIT_2_C()
{
    TestBit(BC.low, 2);
}


void LR35902::BIT_2_D()
{
    TestBit(DE.high, 2);
}


void LR35902::BIT_2_E()
{
    TestBit(DE.low, 2);
}


void LR35902::BIT_2_H()
{
    TestBit(HL.high, 2);
}


void LR35902::BIT_2_L()
{
    TestBit(HL.low, 2);
}


void LR35902::BIT_2__HL_()
{
    TestBit(HL.word, 2);
}


void LR35902::BIT_2_A()
{
    TestBit(AF.high, 2);
}


void LR35902::BIT_3_B()
{
    TestBit(BC.high, 3);
}


void LR35902::BIT_3_C()
{
    TestBit(BC.low, 3);
}


void LR35902::BIT_3_D()
{
    TestBit(DE.high, 3);
}


void LR35902::BIT_3_E()
{
    TestBit(DE.low, 3);
}


void LR35902::BIT_3_H()
{
    TestBit(HL.high, 3);
}


void LR35902::BIT_3_L()
{
    TestBit(HL.low, 3);
}


void LR35902::BIT_3__HL_()
{
    TestBit(HL.word, 3);
}


void LR35902::BIT_3_A()
{
    TestBit(AF.high, 3);
}


void LR35902::BIT_4_B()
{
    TestBit(BC.high, 4);
}


void LR35902::BIT_4_C()
{
    TestBit(BC.low, 4);
}


void LR35902::BIT_4_D()
{
    TestBit(DE.high, 4);
}


void LR35902::BIT_4_E()
{
    TestBit(DE.low, 4);
}


void LR35902::BIT_4_H()
{
    TestBit(HL.high, 4);
}


void LR35902::BIT_4_L()
{
    TestBit(HL.low, 4);
}


void LR35902::BIT_4__HL_()
{
    TestBit(HL.word, 4);
}


void LR35902::BIT_4_A()
{
    TestBit(AF.high, 4);
}


void LR35902::BIT_5_B()
{
    TestBit(BC.high, 5);
}


void LR35902::BIT_5_C()
{
    TestBit(BC.low, 5);
}


void LR35902::BIT_5_D()
{
    TestBit(DE.high, 5);
}


void LR35902::BIT_5_E()
{
    TestBit(DE.low, 5);
}


void LR35902::BIT_5_H()
{
    TestBit(HL.high, 5);
}


void LR35902::BIT_5_L()
{
    TestBit(HL.low, 5);
}


void LR35902::BIT_5__HL_()
{
    TestBit(HL.word, 5);
}


void LR35902::BIT_5_A()
{
    TestBit(AF.high, 5);
}


void LR35902::BIT_6_B()
{
    TestBit(BC.high, 6);
}


void LR35902::BIT_6_C()
{
    TestBit(BC.low, 6);
}


void LR35902::BIT_6_D()
{
    TestBit(DE.high, 6);
}


void LR35902::BIT_6_E()
{
    TestBit(DE.low, 6);
}


void LR35902::BIT_6_H()
{
    TestBit(HL.high, 6);
}


void LR35902::BIT_6_L()
{
    TestBit(HL.low, 6);
}


void LR35902::BIT_6__HL_()
{
    TestBit(HL.word, 6);
}


void LR35902::BIT_6_A()
{
    TestBit(AF.high, 6);
}


void LR35902::BIT_7_B()
{
    TestBit(BC.high, 7);
}


void LR35902::BIT_7_C()
{
    TestBit(BC.low, 7);
}


void LR35902::BIT_7_D()
{
    TestBit(DE.high, 7);
}


void LR35902::BIT_7_E()
{
    TestBit(DE.low, 7);
}


void LR35902::BIT_7_H()
{
    TestBit(HL.high, 7);
}


void LR35902::BIT_7_L()
{
    TestBit(HL.low, 7);
}


void LR35902::BIT_7__HL_()
{
    TestBit(HL.word, 7);
}


void LR35902::BIT_7_A()
{
    TestBit(AF.high, 7);
}


void LR35902::RES_0_B()
{
    ResetBit(BC.high, 0);
}


void LR35902::RES_0_C()
{
    ResetBit(BC.low, 0);
}


void LR35902::RES_0_D()
{
    ResetBit(DE.high, 0);
}


void LR35902::RES_0_E()
{
    ResetBit(DE.low, 0);
}


void LR35902::RES_0_H()
{
    ResetBit(HL.high, 0);
}


void LR35902::RES_0_L()
{
    ResetBit(HL.low, 0);
}


void LR35902::RES_0__HL_()
{
    ResetBit(HL.word, 0);
}


void LR35902::RES_0_A()
{
    ResetBit(AF.high, 0);
}


void LR35902::RES_1_B()
{
    ResetBit(BC.high, 1);
}


void LR35902::RES_1_C()
{
    ResetBit(BC.low, 1);
}


void LR35902::RES_1_D()
{
    ResetBit(DE.high, 1);
}


void LR35902::RES_1_E()
{
    ResetBit(DE.low, 1);
}


void LR35902::RES_1_H()
{
    ResetBit(HL.high, 1);
}


void LR35902::RES_1_L()
{
    ResetBit(HL.low, 1);
}


void LR35902::RES_1__HL_()
{
    ResetBit(HL.word, 1);
}


void LR35902::RES_1_A()
{
    ResetBit(AF.high, 1);
}


void LR35902::RES_2_B()
{
    ResetBit(BC.high, 2);
}


void LR35902::RES_2_C()
{
    ResetBit(BC.low, 2);
}


void LR35902::RES_2_D()
{
    ResetBit(DE.high, 2);
}


void LR35902::RES_2_E()
{
    ResetBit(DE.low, 2);
}


void LR35902::RES_2_H()
{
    ResetBit(HL.high, 2);
}


void LR35902::RES_2_L()
{
    ResetBit(HL.low, 2);
}


void LR35902::RES_2__HL_()
{
    ResetBit(HL.word, 2);
}


void LR35902::RES_2_A()
{
    ResetBit(AF.high, 2);
}


void LR35902::RES_3_B()
{
    ResetBit(BC.high, 3);
}


void LR35902::RES_3_C()
{
    ResetBit(BC.low, 3);
}


void LR35902::RES_3_D()
{
    ResetBit(DE.high, 3);
}


void LR35902::RES_3_E()
{
    ResetBit(DE.low, 3);
}


void LR35902::RES_3_H()
{
    ResetBit(HL.high, 3);
}


void LR35902::RES_3_L()
{
    ResetBit(HL.low, 3);
}


void LR35902::RES_3__HL_()
{
    ResetBit(HL.word, 3);
}


void LR35902::RES_3_A()
{
    ResetBit(AF.high, 3);
}


void LR35902::RES_4_B()
{
    ResetBit(BC.high, 4);
}


void LR35902::RES_4_C()
{
    ResetBit(BC.low, 4);
}


void LR35902::RES_4_D()
{
    ResetBit(DE.high, 4);
}


void LR35902::RES_4_E()
{
    ResetBit(DE.low, 4);
}


void LR35902::RES_4_H()
{
    ResetBit(HL.high, 4);
}


void LR35902::RES_4_L()
{
    ResetBit(HL.low, 4);
}


void LR35902::RES_4__HL_()
{
    ResetBit(HL.word, 4);
}


void LR35902::RES_4_A()
{
    ResetBit(AF.high, 4);
}


void LR35902::RES_5_B()
{
    ResetBit(BC.high, 5);
}


void LR35902::RES_5_C()
{
    ResetBit(BC.low, 5);
}


void LR35902::RES_5_D()
{
    ResetBit(DE.high, 5);
}


void LR35902::RES_5_E()
{
    ResetBit(DE.low, 5);
}


void LR35902::RES_5_H()
{
    ResetBit(HL.high, 5);
}


void LR35902::RES_5_L()
{
    ResetBit(HL.low, 5);
}


void LR35902::RES_5__HL_()
{
    ResetBit(HL.word, 5);
}


void LR35902::RES_5_A()
{
    ResetBit(AF.high, 5);
}


void LR35902::RES_6_B()
{
    ResetBit(BC.high, 6);
}


void LR35902::RES_6_C()
{
    ResetBit(BC.low, 6);
}


void LR35902::RES_6_D()
{
    ResetBit(DE.high, 6);
}


void LR35902::RES_6_E()
{
    ResetBit(DE.low, 6);
}


void LR35902::RES_6_H()
{
    ResetBit(HL.high, 6);
}


void LR35902::RES_6_L()
{
    ResetBit(HL.low, 6);
}


void LR35902::RES_6__HL_()
{
    ResetBit(HL.word, 6);
}


void LR35902::RES_6_A()
{
    ResetBit(AF.high, 6);
}


void LR35902::RES_7_B()
{
    ResetBit(BC.high, 7);
}


void LR35902::RES_7_C()
{
    ResetBit(BC.low, 7);
}


void LR35902::RES_7_D()
{
    ResetBit(DE.high, 7);
}


void LR35902::RES_7_E()
{
    ResetBit(DE.low, 7);
}


void LR35902::RES_7_H()
{
    ResetBit(HL.high, 7);
}


void LR35902::RES_7_L()
{
    ResetBit(HL.low, 7);
}


void LR35902::RES_7__HL_()
{
    ResetBit(HL.word, 7);
}


void LR35902::RES_7_A()
{
    ResetBit(AF.high, 7);
}


void LR35902::SET_0_B()
{
    SetBit(BC.high, 0);
}


void LR35902::SET_0_C()
{
    SetBit(BC.low, 0);
}


void LR35902::SET_0_D()
{
    SetBit(DE.high, 0);
}


void LR35902::SET_0_E()
{
    SetBit(DE.low, 0);
}


void LR35902::SET_0_H()
{
    SetBit(HL.high, 0);
}


void LR35902::SET_0_L()
{
    SetBit(HL.low, 0);
}


void LR35902::SET_0__HL_()
{
    SetBit(HL.word, 0);
}


void LR35902::SET_0_A()
{
    SetBit(AF.high, 0);
}


void LR35902::SET_1_B()
{
    SetBit(BC.high, 1);
}


void LR35902::SET_1_C()
{
    SetBit(BC.low, 1);
}


void LR35902::SET_1_D()
{
    SetBit(DE.high, 1);
}


void LR35902::SET_1_E()
{
    SetBit(DE.low, 1);
}


void LR35902::SET_1_H()
{
    SetBit(HL.high, 1);
}


void LR35902::SET_1_L()
{
    SetBit(HL.low, 1);
}


void LR35902::SET_1__HL_()
{
    SetBit(HL.word, 1);
}


void LR35902::SET_1_A()
{
    SetBit(AF.high, 1);
}


void LR35902::SET_2_B()
{
    SetBit(BC.high, 2);
}


void LR35902::SET_2_C()
{
    SetBit(BC.low, 2);
}


void LR35902::SET_2_D()
{
    SetBit(DE.high, 2);
}


void LR35902::SET_2_E()
{
    SetBit(DE.low, 2);
}


void LR35902::SET_2_H()
{
    SetBit(HL.high, 2);
}


void LR35902::SET_2_L()
{
    SetBit(HL.low, 2);
}


void LR35902::SET_2__HL_()
{
    SetBit(HL.word, 2);
}


void LR35902::SET_2_A()
{
    SetBit(AF.high, 2);
}


void LR35902::SET_3_B()
{
    SetBit(BC.high, 3);
}


void LR35902::SET_3_C()
{
    SetBit(BC.low, 3);
}


void LR35902::SET_3_D()
{
    SetBit(DE.high, 3);
}


void LR35902::SET_3_E()
{
    SetBit(DE.low, 3);
}


void LR35902::SET_3_H()
{
    SetBit(HL.high, 3);
}


void LR35902::SET_3_L()
{
    SetBit(HL.low, 3);
}


void LR35902::SET_3__HL_()
{
    SetBit(HL.word, 3);
}


void LR35902::SET_3_A()
{
    SetBit(AF.high, 3);
}


void LR35902::SET_4_B()
{
    SetBit(BC.high, 4);
}


void LR35902::SET_4_C()
{
    SetBit(BC.low, 4);
}


void LR35902::SET_4_D()
{
    SetBit(DE.high, 4);
}


void LR35902::SET_4_E()
{
    SetBit(DE.low, 4);
}


void LR35902::SET_4_H()
{
    SetBit(HL.high, 4);
}


void LR35902::SET_4_L()
{
    SetBit(HL.low, 4);
}


void LR35902::SET_4__HL_()
{
    SetBit(HL.word, 4);
}


void LR35902::SET_4_A()
{
    SetBit(AF.high, 4);
}


void LR35902::SET_5_B()
{
    SetBit(BC.high, 5);
}


void LR35902::SET_5_C()
{
    SetBit(BC.low, 5);
}


void LR35902::SET_5_D()
{
    SetBit(DE.high, 5);
}


void LR35902::SET_5_E()
{
    SetBit(DE.low, 5);
}


void LR35902::SET_5_H()
{
    SetBit(HL.high, 5);
}


void LR35902::SET_5_L()
{
    SetBit(HL.low, 5);
}


void LR35902::SET_5__HL_()
{
    SetBit(HL.word, 5);
}


void LR35902::SET_5_A()
{
    SetBit(AF.high, 5);
}


void LR35902::SET_6_B()
{
    SetBit(BC.high, 6);
}


void LR35902::SET_6_C()
{
    SetBit(BC.low, 6);
}


void LR35902::SET_6_D()
{
    SetBit(DE.high, 6);
}


void LR35902::SET_6_E()
{
    SetBit(DE.low, 6);
}


void LR35902::SET_6_H()
{
    SetBit(HL.high, 6);
}


void LR35902::SET_6_L()
{
    SetBit(HL.low, 6);
}


void LR35902::SET_6__HL_()
{
    SetBit(HL.word, 6);
}


void LR35902::SET_6_A()
{
    SetBit(AF.high, 6);
}


void LR35902::SET_7_B()
{
    SetBit(BC.high, 7);
}


void LR35902::SET_7_C()
{
    SetBit(BC.low, 7);
}


void LR35902::SET_7_D()
{
    SetBit(DE.high, 7);
}


void LR35902::SET_7_E()
{
    SetBit(DE.low, 7);
}


void LR35902::SET_7_H()
{
    SetBit(HL.high, 7);
}


void LR35902::SET_7_L()
{
    SetBit(HL.low, 7);
}


void LR35902::SET_7__HL_()
{
    SetBit(HL.word, 7);
}


void LR35902::SET_7_A()
{
    SetBit(AF.high, 7);
}


