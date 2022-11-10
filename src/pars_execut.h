#include "helpers.h"

#include <iostream>


void parser(std::string& name, instruction ins) {

	std::fstream f;
	std::string line;
	std::string tmp = "";
	int times = 1;
	int k = 0;
	f.open(name, std::ios::in);
	while (f >> line) {
		
		if (line[strlen(line) -1] == 58) {
			continue;
		}
		if (times == 1) {
			ins.opcode = op_map[line];
			++times;
			continue;
		}
		if (times == 2) {
			switch (ins.opcode) {
				case Opcode::JMP:
				case Opcode::JL:
				case Opcode::JE:
					ins.target = lb_map[line];
					code[++k] = ins;
					times = 1;
					break;
				case Opcode::PRINT:
					ins.dest_reg = reg_map[line];
					code[++k] = ins;
					times = 1;
					break;
				default:
					ins.dest_reg = reg_map[line];
					++times;
			}
			continue;
		}
		if (times == 3) {
			get_src(ins, line);	
			code[++k] = ins;
			times = 1;		
		}
		}
	f.close();
}


std::map<Opcode, void(*)(instruction* ins, std::map<Register, int>& reg)> fp_map;

void init_fp_map() {
        fp_map[Opcode::MOV] = &mov;
        fp_map[Opcode::ADD] = &add;
        fp_map[Opcode::SUB] = &sub;
        fp_map[Opcode::CMP] = &cmp;
}

void execute(std::map<int, instruction>& code, std::map<Register, int>& reg) {

        int ip = 1;
        while (ip <= code.size()) {
        auto curr_ins = code[ip];
                switch (curr_ins.opcode) {
                        case Opcode::JE:
                                if (reg[Register::FLAG] == 0) {
                                          ip = curr_ins.target;
                                } else {
                                         ++ip;
                                 }
                                break;
                        case Opcode::JL:
                                if (reg[Register::FLAG] == 2) {
                                        ip = curr_ins.target;
                                 } else {
                                         ++ip;
                                 }
                                break;
                        case Opcode::JMP:
                                ip = curr_ins.target;
                                break;
			case Opcode::PRINT:
				std::cout << reg[curr_ins.dest_reg];
				++ip;
				break;
                        default:

                                fp_map[curr_ins.opcode](&curr_ins, reg);
                                ++ip;
				break;
                }


        }
}




