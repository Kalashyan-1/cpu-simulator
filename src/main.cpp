#include "pars_execut.h"


int main() {
        std::string name;
        std::cout << "Please enter file name: ";
        std::cin >> name;
        init_opcode(op_map);
        maping_reg(reg_map);
        instruction ins;
        target_lb(name);
        parser(name, ins);
        init_fp_map();
        execute(code, reg);
}

