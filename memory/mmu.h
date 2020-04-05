#include<inttypes.h>
#ifndef MMU_H
#define MMU_H


class MMU
{
public:
    MMU();
private:
    uint8_t bios[0x100];
    bool read_bios;
    union Memory
    {
        uint8_t address[0x10000];
        struct
        {
            uint8_t rom[2][0x4000];
            uint8_t video_ram[0x2000];
            uint8_t external_ram[0x2000];
            uint8_t working_ram[0x2000];
            uint8_t echo_ram[0x1E00];
            uint8_t object_attribute_memory[0xA0];
            uint8_t unusable_memory[0x60];
            uint8_t io_registers[0x40];
            uint8_t ppu[0x40];
            uint8_t zero_page[0x80];
            uint8_t interrupt_flag;
        };
    };
    Memory memory;

public:

    uint8_t ReadByte(uint16_t address);
    uint8_t ReadWord(uint16_t address); 

    void WriteByte(uint16_t address, uint8_t value);
    void WriteWord(uint16_t address, uint16_t value);

};

#endif // MMU_H
