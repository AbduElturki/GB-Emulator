#include "lr35902.h"

void LR35902::RLC_B()
{
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
    if(n) AF.low = 0x80;
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
    if(n) AF.low = 0x80;
    mmu->WriteByte(HL.word, n);
    machine_cycle = 4;
}


void LR35902::RRC_A()
{
    RotateRightCarry(AF.high);
}


void LR35902::RL_B()
{
}


void LR35902::RL_C()
{
}


void LR35902::RL_D()
{
}


void LR35902::RL_E()
{
}


void LR35902::RL_H()
{
}


void LR35902::RL_L()
{
}


void LR35902::RL__HL_()
{
}


void LR35902::RL_A()
{
}


void LR35902::RR_B()
{
}


void LR35902::RR_C()
{
}


void LR35902::RR_D()
{
}


void LR35902::RR_E()
{
}


void LR35902::RR_H()
{
}


void LR35902::RR_L()
{
}


void LR35902::RR__HL_()
{
}


void LR35902::RR_A()
{
}


void LR35902::SLA_B()
{
}


void LR35902::SLA_C()
{
}


void LR35902::SLA_D()
{
}


void LR35902::SLA_E()
{
}


void LR35902::SLA_H()
{
}


void LR35902::SLA_L()
{
}


void LR35902::SLA__HL_()
{
}


void LR35902::SLA_A()
{
}


void LR35902::SRA_B()
{
}


void LR35902::SRA_C()
{
}


void LR35902::SRA_D()
{
}


void LR35902::SRA_E()
{
}


void LR35902::SRA_H()
{
}


void LR35902::SRA_L()
{
}


void LR35902::SRA__HL_()
{
}


void LR35902::SRA_A()
{
}


void LR35902::SWAP_B()
{
}


void LR35902::SWAP_C()
{
}


void LR35902::SWAP_D()
{
}


void LR35902::SWAP_E()
{
}


void LR35902::SWAP_H()
{
}


void LR35902::SWAP_L()
{
}


void LR35902::SWAP__HL_()
{
}


void LR35902::SWAP_A()
{
}


void LR35902::SRL_B()
{
}


void LR35902::SRL_C()
{
}


void LR35902::SRL_D()
{
}


void LR35902::SRL_E()
{
}


void LR35902::SRL_H()
{
}


void LR35902::SRL_L()
{
}


void LR35902::SRL__HL_()
{
}


void LR35902::SRL_A()
{
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


