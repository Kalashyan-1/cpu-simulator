#include "initialization.h"

#include <fstream>
#include <sstream>


std::map<int, instruction> code;
std::map<std::string, int> lb_map;

int strlen(std::string& s) {
	int count = 0;
	while (s[count] != '\0') {
		++count;
	}
	return count;
}


bool is_number(const std::string& s) {

    bool check = true;

    for (int i = 0; s[i] != '\0'; ++i) {

    if (s[i] >= 48 && s[i] <= 57) {

            continue;
    } else {

        check = false;
        break;
    }
    }
    return check;
}
	


void get_src(instruction& ins, std::string& s) {

	ins.is_imm = is_number(s);
	if (ins.is_imm) {
		ins.src_num = std::stoi(s);
	} else {
		ins.src_reg = reg_map[s];
	}
}


void target_lb(std::string& name) {
	std::fstream f;
	f.open(name, std::ios::in);
	std::string line;
	std::string lb_name = "";
	int target = 1;
	while (getline(f, line)) {
		if (line[strlen(line) -1] == 58) {
			for (int i = 0; line[i] != 58; ++i) {
				lb_name += line[i];
			}
			lb_map[lb_name] = target;
			lb_name = "";

		} else { 
			++target;
		}
	}
	
	f.close();
}




void mov(instruction* i, std::map<Register, int>& reg) {
        if (i->is_imm) {
                reg[i->dest_reg] = i->src_num;
        } else {
                reg[i->dest_reg] = reg[i->src_reg];
        }
}

void add(instruction* i, std::map<Register, int>& reg) {
        if (i->is_imm) {
                reg[i->dest_reg] += i->src_num;
        } else {
                reg[i->dest_reg] += reg[i->src_reg];
        }
}

void sub(instruction* i, std::map<Register, int>& reg) {
        if (i->is_imm) {
                reg[i->dest_reg] -= i->src_num;
        } else {
                reg[i->dest_reg] -= reg[i->src_reg];
        }
}

void cmp(instruction* i, std::map<Register, int>& reg) {
        if (i->is_imm) {
                if (reg[i->dest_reg] > i->src_num) {
                        reg[Register::FLAG] = 1;
                } else if (reg[i->dest_reg] < i->src_num) {
                        reg[Register::FLAG] = 2;
                } else {
                        reg[Register::FLAG] = 0;
                }
        } else {
                if (reg[i->dest_reg] > reg[i->src_reg]) {
                        reg[Register::FLAG] = 1;
                } else if (reg[i->dest_reg] < reg[i->src_reg]) {
                        reg[Register::FLAG] = 2;
                } else {
                        reg[Register::FLAG] = 0;
                }
        }
}



