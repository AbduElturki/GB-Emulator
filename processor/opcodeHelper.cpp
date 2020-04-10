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

//Branch
void LR35902::JumpRelative(bool condition)
{
    if(condition)
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
    AF.low |= ((HL.word&0xFFF) + (reg&0xFFF) == 0x1000)?0x20:0;
    HL.word += reg;
    //carry flag 
    AF.low |= (HL.word < reg)?0x10:0;
    machine_cycle = 2;
}
