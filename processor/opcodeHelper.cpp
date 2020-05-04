#include"lr35902.h"

//LD
void LR35902::LoadFromMemory(uint8_t& reg)
{
    reg = mmu->ReadByte(PC.word);
    machine_cycle = 2;
    PC.word += 1;
}

void LR35902::LoadFromMemory(uint16_t& reg)
{
    reg = mmu->ReadWord(PC.word);
    machine_cycle = 3;
    PC.word += 2;
}

void LR35902::LoadFromMemory(uint8_t& reg, uint16_t address)
{
    reg = mmu->ReadByte(address);
    machine_cycle = 2;
}

void LR35902::LoadFromMemory(uint16_t& reg, uint16_t address)
{
    reg = mmu->ReadWord(address);
    machine_cycle = 3;
}

void LR35902::LoadToMemory(uint8_t reg)
{
    mmu->WriteByte(PC.word, reg);
    machine_cycle = 2;
    PC.word += 1;
}

void LR35902::LoadToMemory(uint16_t reg)
{
    mmu->WriteWord(PC.word, reg);
    machine_cycle = 3;
    PC.word += 2;
}

void LR35902::LoadToMemory(uint8_t reg, uint16_t address)
{
    mmu->WriteByte(address, reg);
    machine_cycle = 2;
}

void LR35902::LoadToMemory(uint16_t reg, uint16_t address)
{
    mmu->WriteWord(address, reg);
    machine_cycle = 3;
}

void LR35902::LoadFromRegister(uint8_t& reg_1, uint8_t& reg_2)
{
    reg_1 = reg_2;
    machine_cycle = 1;
}

void LR35902::PopRegister(uint16_t& reg)
{
    reg = mmu->ReadWord(SP.word);
    SP.word += 2;
    machine_cycle = 3;
}

void LR35902::PushRegister(uint16_t reg)
{
    SP.word -= 3;
    mmu->WriteWord(SP.word, reg);
    machine_cycle = 4;
}

void LR35902::Restart(uint16_t address)
{
    SP.word -= 2;
    mmu->WriteWord(SP.word,PC.word);
    PC.word = address;
    machine_cycle = 4;
}

//Branch
void LR35902::JumpRelative(bool condition)
{
    //TODO validate this...
    //There are some disagreement in some docs on how JR works...
    //Some believe that if the condition is met it should take 4 machine cycle
    //but I think they are confusing JP with JR.
    //Also I might need to convert the unsigned numbers to signed.
    if(condition)
    {
        PC.word += (mmu->ReadWord(PC.word) + 1);
        machine_cycle = 3;
    } 
    else 
    {
        PC.word += 2;
        machine_cycle = 2;
    }
}

void LR35902::Jump(bool condition)
{
    if(condition)
    {
        PC.word = mmu->ReadWord(PC.word);
        machine_cycle = 4;
    } 
    else 
    {
        PC.word += 2;
        machine_cycle = 3;
    }

}

void LR35902::Call(bool condition)
{
    if(condition)
    {
        uint16_t nn = mmu->ReadWord(PC.word);
        PC.word += 2;
        SP.word -= 2;
        mmu->WriteWord(SP.word,PC.word);
        PC.word = nn;
        machine_cycle = 6;
    }
    else
    {
        PC.word += 2;
        machine_cycle = 3;
    }
}

void LR35902::ReturnFunc(bool condition)
{
    if(condition)
    {
        PC.word = mmu->ReadWord(SP.word);
        SP.word += 2;
        machine_cycle = 5;
    }
    else
    {
        machine_cycle = 2;
    }
}

//ALU
void LR35902::IncrementRegister(uint8_t& reg)
{
    //Carry flag unaffected
    AF.low &= 0x10;
    AF.low |= (((reg&0xF) + 1) == 0x10)?0x20:0;
    AF.low |= reg?0:0x80;
    ++reg;
    machine_cycle = 1;
}

void LR35902::IncrementRegister(uint16_t& reg)
{
    ++reg;
    machine_cycle = 2;
}

void LR35902::DecrementRegister(uint8_t& reg)
{
    //Carry flag unaffected
    AF.low &= 0x10;
    AF.low |= 0x40;
    --reg;
    AF.low |= ((reg &0xF) == 0xF)?0x20:0;
    AF.low |= reg?0:0x80;
    machine_cycle = 1;
}

void LR35902::DecrementRegister(uint16_t& reg)
{
    --reg;
    machine_cycle = 2;
}

void LR35902::AddToHL(uint16_t reg)
{
    //Zero flag unaffected
    AF.low &= 0x80; 
    //Half carry flag 
    AF.low |= (((HL.word&0xFFF) + (reg&0xFFF) & 0x1000) == 0x1000)?0x20:0;
    HL.word += reg;
    //carry flag 
    AF.low |= (HL.word < reg)?0x10:0;
    machine_cycle = 2;
}

void LR35902::AddToA(uint8_t reg)
{
    //Half carry flag
    AF.low = ((((AF.high&0xF) + (reg&0xF)) & 0x10) == 0x10)?0x20:0;
    AF.high += reg;
    //carry flag
    AF.low |= (AF.high < reg)?0x10:0;
    //Zero flag
    AF.low |= (AF.high)?0:0x80;
    machine_cycle = 1;
}

void LR35902::AddToA(uint16_t address)
{
    uint8_t nn = mmu->ReadByte(address);
    //Half carry flag
    AF.low = ((((AF.high&0xF) + (nn&0xF)) & 0x10) == 0x10)?0x20:0;
    AF.high += nn;
    //carry flag
    AF.low |= (AF.high < nn)?0x10:0;
    //Zero flag
    AF.low |= (AF.high)?0:0x80;
    machine_cycle = 2;
}

void LR35902::AddCarryToA(uint8_t reg)
{
    uint8_t carry = AF.low>>4;
    //Half carry flag
    AF.low = ((((AF.high&0xF) + (reg&0xF) + carry )&0x10) == 0x10)?0x20:0;
    AF.high += reg;
    //carry flag
    AF.low |= (AF.high < reg)?0x10:0;
    //Zero flag
    AF.low |= (AF.high)?0:0x80;
    machine_cycle = 1;
}

void LR35902::AddCarryToA(uint16_t address)
{
    uint8_t carry = AF.low>>4;
    uint8_t nn = mmu->ReadByte(address);
    //Half carry flag
    AF.low = ((((AF.high&0xF) + (nn&0xF) + carry)&0x10) == 0x10)?0x20:0;
    AF.high += (nn + carry);
    //carry flag
    AF.low |= (AF.high < nn)?0x10:0;
    //Zero flag
    AF.low |= (AF.high)?0:0x80;
    machine_cycle = 2;
}

void LR35902::SubFromA(uint8_t reg)
{
    AF.low = 0x40;
    //Half borrow flag
    AF.low |= ((AF.high&0xF) < (reg&0xF))?0x20:0;
    //Full borrow flag
    AF.low |= (AF.high < reg)?0x10:0;
    AF.high -= reg;
    AF.low |= AF.high?0:0x80;
    machine_cycle = 1;
}

void LR35902::SubFromA(uint16_t address)
{
    uint8_t nn = mmu->ReadByte(address);
    AF.low = 0x40;
    //Half borrow flag
    AF.low |= ((AF.high&0xF) < (nn&0xF))?0x20:0;
    //Full borrow flag
    AF.low |= (AF.high < nn)?0x10:0;
    AF.high -= nn;
    AF.low |= AF.high?0:0x80;
    machine_cycle = 2;
}

void LR35902::SubCarryFromA(uint8_t reg)
{
    uint8_t carry = AF.low>>4;
    AF.low = 0x40;
    //Half borrow flag
    AF.low |= ((AF.high&0xF) < ((reg+carry)&0xF))?0x20:0;
    //Full borrow flag
    AF.low |= (AF.high < ((uint16_t)reg+carry))?0x10:0;
    AF.high -= reg;
    AF.low |= AF.high?0:0x80;
    machine_cycle = 1;
}

void LR35902::SubCarryFromA(uint16_t address)
{
    uint8_t carry = AF.low>>4;
    uint16_t nn = mmu->ReadByte(address);
    AF.low = 0x40;
    //Half borrow flag
    AF.low |= ((AF.high&0xF) < ((nn+carry)&0xF))?0x20:0;
    //Full borrow flag
    AF.low |= (AF.high < (nn+carry))?0x10:0;
    AF.high -= nn;
    AF.low |= AF.high?0:0x80;
    machine_cycle = 2;
}

void LR35902::AndWithA(uint8_t reg)
{
    AF.high &= reg;
    AF.low = AF.high?0x20:0xA0;
    machine_cycle = 1;
}

void LR35902::AndWithA(uint16_t address)
{
    AF.high &= mmu->ReadByte(address);
    AF.low = AF.high?0x20:0xA0;
    machine_cycle = 2;
}

void LR35902::XorWithA(uint8_t reg)
{
    AF.high ^= reg;
    AF.low = AF.high?0:0x80;
    machine_cycle = 1;
}

void LR35902::XorWithA(uint16_t address)
{
    AF.high ^= mmu->ReadByte(address);
    AF.low = AF.high?0:0x80;
    machine_cycle = 2;
}

void LR35902::OrWithA(uint8_t reg)
{
    AF.high |= reg;
    AF.low = AF.high?0:0x80;
    machine_cycle = 1;
}

void LR35902::OrWithA(uint16_t address)
{
    AF.high |= mmu->ReadByte(address);
    AF.low = AF.high?0:0x80;
    machine_cycle = 2;
}

void LR35902::CompareToA(uint8_t reg)
{
    AF.low = (AF.high == reg)?0xC0:0x40;
    AF.low |= ((AF.high&0xF) < (reg&0xF))?0x20:0;
    AF.low |= (AF.high < reg)?0x10:0;
    machine_cycle = 1;
}

void LR35902::CompareToA(uint16_t address)
{
    uint8_t nn = mmu->ReadByte(address);
    AF.low = (AF.high == nn)?0xC0:0x40;
    AF.low |= ((AF.high&0xF) < (nn&0xF))?0x20:0;
    AF.low |= (AF.high < nn)?0x10:0;
    machine_cycle = 2;
}

//Rotate
void LR35902::RotateLeftCarry(uint8_t& reg)
{
    reg = (reg << 1) | (reg >> 7);
    AF.low = (reg&0x1)?0x10:0;
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::RotateRightCarry(uint8_t& reg)
{
    reg = (reg >> 1) | (reg << 7);
    AF.low = (reg&0x80)?0x10:0;
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::RotateLeft(uint8_t& reg)
{
    AF.low = (reg&0x80)?0x10:0;
    reg = (reg << 1) | ((AF.low&0x10) >> 4);
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::RotateRight(uint8_t& reg)
{
    AF.low = (reg&0x1)?0x10:0;
    reg = (reg >> 1) | ((AF.low&0x10) << 3);
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::ShiftLeft(uint8_t& reg)
{
    AF.low = (reg&0x80)?0x10:0;
    reg = (reg << 1);
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::ShiftRightNoChange(uint8_t& reg)
{
    AF.low = (reg&0x1)?0x10:0;
    reg = (reg & 0x80) | (reg >> 1);
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::ShiftRight(uint8_t& reg)
{
    AF.low = (reg&0x1)?0x10:0;
    reg = (reg >> 1);
    AF.low |= reg?0:0x80;
    machine_cycle = 2;
}

void LR35902::Swap(uint8_t& reg)
{
    AF.low = reg?0:0x80;
    reg = ((reg&0xF0) >> 4) | ((reg&0xF) << 4);
    machine_cycle = 2;
}

//Bit operator
void LR35902::BitOperator(uint8_t& reg, int bit)
{
}
