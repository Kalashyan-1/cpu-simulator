#include "declaration.h"

#include <map>
#include <string>

std::map<std::string, Opcode> op_map;


void init_opcode(std::map<std::string, Opcode>& op_map) {

op_map["mov"] = Opcode::MOV;
op_map["add"] = Opcode::ADD;
op_map["sub"] = Opcode::SUB;
op_map["cmp"] = Opcode::CMP;
op_map["jmp"] = Opcode::JMP;
op_map["jl"] = Opcode::JL;
op_map["je"] = Opcode::JE;
op_map["print"] = Opcode::PRINT;
}


std::map<Register, int> reg;


void reg_init(std::map<Register, int>& reg) {
	reg[Register::R1] = 0;
	reg[Register::R2] = 0;
	reg[Register::R3] = 0;
	reg[Register::R4] = 0;
	reg[Register::R5] = 0;
	reg[Register::R6] = 0;
	reg[Register::R7] = 0;
	reg[Register::R8] = 0;
	reg[Register::R9] = 0;
	reg[Register::R10] = 0;
	reg[Register::FLAG] = 0;
}

std::map<std::string, Register> reg_map;

void maping_reg(std::map<std::string, Register>& reg_map) {

reg_map["r1"] = Register::R2;
reg_map["r2"] = Register::R3;
reg_map["r3"] = Register::R4;
reg_map["r5"] = Register::R5;
reg_map["r6"] = Register::R6;
reg_map["r7"] = Register::R7;
reg_map["r8"] = Register::R8;
reg_map["r9"] = Register::R9;
reg_map["r10"] = Register::R10;
reg_map["FLAG"] = Register::FLAG;

}


