
#include "Parser.h"

// FIXME, implement this function.
//#define ADD 1
//#define SUB 2
//#define SLL 3
//#define SRL 4
//#define XOR 5
//#define OR 6
//#define AND 7



// Here shows an example on how to translate "add x10, x10, x25"
void loadInstructions(Instruction_Memory *i_mem, const char *trace)
{
    printf("Loading trace file: %s\n", trace);

    FILE *fd = fopen(trace, "r");
    if (fd == NULL)
    {
        perror("Cannot open trace file. \n");
        exit(EXIT_FAILURE);
    }

    // Iterate all the assembly instructions
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Addr PC = 0; // program counter points to the zeroth location initially.
    int IMEM_index = 0;
    while ((read = getline(&line, &len, fd)) != -1)
    {
        // Assign program counter
        i_mem->instructions[IMEM_index].addr = PC;

        // Extract operation
        char *raw_instr = strtok(line, " ");
        if (strcmp(raw_instr, "add") == 0 ||//Add sd
            strcmp(raw_instr, "sub") == 0 ||
            strcmp(raw_instr, "sll") == 0 ||
            strcmp(raw_instr, "srl") == 0 ||
            strcmp(raw_instr, "xor") == 0 ||
            strcmp(raw_instr, "or")  == 0 ||
            strcmp(raw_instr, "and") == 0)
        { //R type assembly commands
            parseRType(raw_instr, &(i_mem->instructions[IMEM_index]));
            i_mem->last = &(i_mem->instructions[IMEM_index]);
            printf("Address: %d\n", (i_mem->instructions[IMEM_index]).addr);
            printf("Decimal of ins: %d \n", (i_mem->instructions[IMEM_index]).instruction);
	    } else if 
        (strcmp(raw_instr, "ld") == 0 ||
         strcmp(raw_instr, "addi") == 0 ||
         strcmp(raw_instr, "slli") == 0 ||
         strcmp(raw_instr, "xori") == 0 ||
         strcmp(raw_instr, "srli") == 0 ||
         strcmp(raw_instr, "ori")  == 0 ||
         strcmp(raw_instr, "andi") == 0 ||
         strcmp(raw_instr, "jarl") == 0 )
        {//I type, may or may not have immediate
            int imm = 0;
            char* immTok = strtok(line, "(");
            printf("%s\n", immTok);
            //immTok = strtok(NULL, "(");
            //printf("%s\n", immTok);
            //parseIType(raw_instr, &(i_mem->instructions[IMEM_index]));
            i_mem->last = &(i_mem->instructions[IMEM_index]);
        } /* else if
         (strcmp(raw_instr, "beq") == 0 ||
         strcmp(raw_instr, "bne") == 0 ||
         strcmp(raw_instr, "blt") == 0 ||
         strcmp(raw_instr, "bge") == 0 ||)
        { //SB Type, opcode = 
            parseSBType(raw_instr, &(i_mem->instructions[IMEM_index]));
            i_mem->last = &(i_mem->instructions[IMEM_index]);
        } else if
        (strcmp(raw_instr, "jal") == 0)
        { //UJ Type
            parseUJType(raw_instr, &(i_mem->instructions[IMEM_index]));
            i_mem->last = &(i_mem->instructions[IMEM_index]);
        } */
        
        IMEM_index++;
        PC += 4;
    }

    fclose(fd);
}


void parseRType(char *opr, Instruction *instr)
{
    instr->instruction = 0;

    unsigned opcode = 0; //opcode = 51 for R type
    unsigned funct3 = 0;
    unsigned funct7 = 0;

    if (strcmp(opr, "add") == 0) {
        opcode = 51;
        funct3 = 0b000;
        funct7 = 0b0000000;
    } else if (strcmp(opr, "sub") == 0) {
        opcode = 51;
        funct3 = 0b000;
        funct7 = 0b0100000; //40
    } else if (strcmp(opr, "sll") == 0) {
        opcode = 51;
        funct3 = 0b001;
        funct7 = 0b0000000;
    } else if (strcmp(opr, "srl") == 0) {
        opcode = 51;
        funct3 = 0b101; //5
        funct7 = 0b0000000;
    } else if (strcmp(opr, "xor") == 0) {
        opcode = 51;
        funct3 = 0b100;
        funct7 = 0b0000000;
    } else if (strcmp(opr, "or") == 0) {
        opcode = 51;
        funct3 = 0b110; //6
        funct7 = 0b0000000;
    } else if (strcmp(opr, "and") == 0) {
        opcode = 51;
        funct3 = 0b111; //7
        funct7 = 0b0000000;
    }
    
    char *reg = strtok(NULL, ", ");
    unsigned rd = regIndex(reg);

    reg = strtok(NULL, ", ");
    unsigned rs_1 = regIndex(reg);

    reg = strtok(NULL, ", ");
    reg[strlen(reg)-1] = '\0';
    unsigned rs_2 = regIndex(reg);

    // Contruct instruction
    instr->instruction |= opcode;
    instr->instruction |= (rd << 7);
    instr->instruction |= (funct3 << (7 + 5));
    instr->instruction |= (rs_1 << (7 + 5 + 3));
    instr->instruction |= (rs_2 << (7 + 5 + 3 + 5));
    instr->instruction |= (funct7 << (7 + 5 + 3 + 5 + 5));
}

//Insert parseI type, parse SB type and parse UJ type
void parseIType(char *opr, Instruction *instr){
instr->instruction = 0;

    unsigned opcode = 0; //opcode differs on command
    unsigned funct3 = 0;
    unsigned funct7 = 0; // exists only on certain command
    unsigned imm = 0;

    if (strcmp(opr, "ld") == 0) {
        opcode = 3;
        funct3 = 0b011;
        
    } else if (strcmp(opr, "addi") == 0) {
        opcode = 51;
        funct3 = 0b000;
        funct7 = 0b0100000; //40
    } else if (strcmp(opr, "slli") == 0) {
        opcode = 51;
        funct3 = 0b001;
        funct7 = 0b0000000;
    } else if (strcmp(opr, "srli") == 0) {
        opcode = 51;
        funct3 = 0b101; //5
        funct7 = 0b0000000;
    } else if (strcmp(opr, "xori") == 0) {
        opcode = 51;
        funct3 = 0b100;
        funct7 = 0b0000000;
    } else if (strcmp(opr, "ori") == 0) {
        opcode = 51;
        funct3 = 0b110; //6
        funct7 = 0b0000000;
    } else if (strcmp(opr, "andi") == 0) {
        opcode = 51;
        funct3 = 0b111; //7
        funct7 = 0b0000000;
    } else if (strcmp(opr, "jarl") == 0) {
    
    }

    char *reg = strtok(NULL, ", ");
    unsigned rd = regIndex(reg);

    reg = strtok(NULL, ", ");
    unsigned rs_1 = regIndex(reg);

    reg = strtok(NULL, ", ");
    reg[strlen(reg)-1] = '\0';
    unsigned rs_2 = regIndex(reg);

    // Contruct instruction
    instr->instruction |= opcode;
    instr->instruction |= (rd << 7);
    instr->instruction |= (funct3 << (7 + 5));
    instr->instruction |= (rs_1 << (7 + 5 + 3));
    instr->instruction |= (rs_2 << (7 + 5 + 3 + 5));
    instr->instruction |= (funct7 << (7 + 5 + 3 + 5 + 5));

}

void parseSBType(char *opr, Instruction *instr){
}

void parseUJType(char *opr, Instruction *instr){
}


int regIndex(char *reg)
{
    unsigned i = 0;
    for (i; i < NUM_OF_REGS; i++)
    {
        if (strcmp(REGISTER_NAME[i], reg) == 0)
        {
            break;
        }
    }

    return i;
}
