#include"lr35902.h"

//LD
void LR35902::LoadFromMemory(uint8_t& reg)
{
    reg = mmu->ReadByte(PC.word);
    PC.word += 1;
}

void LR35902::LoadFromMemory(uint16_t& reg)
{
    reg = mmu->ReadWord(PC.word);
    PC.word += 2;
}

void LR35902::LoadFromMemory(uint8_t& reg, uint16_t address)
{
    reg = mmu->ReadByte(address);
}

void LR35902::LoadFromMemory(uint16_t& reg, uint16_t address)
{
    reg = mmu->ReadWord(address);
}

void LR35902::LoadToMemory(uint8_t reg)
{
    mmu->WriteByte(PC.word, reg);
    PC.word += 1;
}

void LR35902::LoadToMemory(uint16_t reg)
{
    mmu->WriteWord(PC.word, reg);
    PC.word += 2;
}

void LR35902::LoadToMemory(uint8_t reg, uint16_t address)
{
    mmu->WriteByte(address, reg);
}

void LR35902::LoadToMemory(uint16_t reg, uint16_t address)
{
    mmu->WriteWord(address, reg);
}

//ALU
void LR35902::AddToHL(uint16_t reg)
{
    AF.low &= 0x80; 
    //Half carry flag 
    if((HL.word&0xFFF) + (reg&0xFFF) == 0x1000) AF.low |= 0x20;
    HL.word += reg;
    //carry/overflow flag 
    if(HL.word < reg) AF.low |= 0x10;
}
