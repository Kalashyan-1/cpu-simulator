
enum class Opcode {
	MOV,
	ADD,
	SUB,
	CMP,
	JMP,
	JL,
	JE,
	PRINT
};

enum class Register {
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	FLAG
};




struct instruction {
	Opcode opcode;
	Register src_reg;
	Register dest_reg;
	int src_num;
	bool is_imm;
	int target;
};

