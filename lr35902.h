#ifndef LR35902_H
#define LR35902_H


class LR35902
{
public:
    LR35902();

private:
    // 00
    void NOP();void LD_BC();void INC_BC();void INC_B();void DEC_B();void LD_B();void RL_CA();void LD_a16_SP();void ADD_HL_BC();void LD_A_BC();void DEC_BC();void INC_C();void DEC_V();void LD_C_d8();
};
    // 01

#endif // LR35902_H
