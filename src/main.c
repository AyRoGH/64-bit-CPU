#include <stdio.h>
#include <cpu.h>
#include <instruction_set.h>
#include <cu.h>

int load_program(cpu_t *cpu, size_t program_size, qword *program)
{
    if (program_size > MEMORY_SIZE)
        return -1;

    for (size_t i = 0; i < program_size; i++)
        cpu->memory[i] = program[i];

    return 0;
}

int run(cpu_t *cpu)
{
    int loop_condition = 1;

    while (loop_condition)
    {
        cpu->ir = cpu->memory[cpu->pc++];
        
        switch (cu(cpu))
        {
            case 0:
                break;
            case 1:
                loop_condition = 0;
                break;
            case -1:
                return -1;
        }
    }

    return 0;
}

int print_registers(cpu_t *cpu)
{
    for (int i = 0; i < NB_REGISTERS; i++)
        printf("[R%d: %lu] ", i, cpu->registers[i].q);
    printf("\n");

    return 0;
}

int print_memory(cpu_t *cpu, size_t size)
{
    if (size > MEMORY_SIZE)
        size = MEMORY_SIZE;
    
    for (size_t i = 0; i < size; i++)
        printf("[M%lu: %lu] ", i, (qword)(cpu->memory)[i]);
    printf("\n");

    return 0;
}

int main(void)
{
    cpu_t cpu = {0};

    qword program[] = 
    {
        MOV64_IR, R0, 1,
        NOP,
        MOV64_IR, R1, 2,
        ADD64, R0, R1,
        HLT
    };

    printf("Initial CPU state:\n");
    print_registers(&cpu);

    if (load_program(&cpu, sizeof(program) / sizeof(qword), program) != 0)
    {
        printf("Error loading program\n");
        return -1;
    }

    if (run(&cpu) != 0)
    {
        printf("Error running program\n");
        return -1;
    }

    printf("Final CPU state:\n");
    print_registers(&cpu);

    return 0;
}