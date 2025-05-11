# 64-bit CPU Simulator

This project is a small 64-bit CPU simulator implemented in C. It provides a virtual CPU with 16 general-purpose registers (R0-R15), each 64 bits wide, capable of executing basic instructions.

## Features

- 16 general-purpose 64-bit registers
- 1KB of memory
- CPU flags (Carry, Zero, Sign, Overflow)
- Support for operations on multiple data sizes:
  - 8-bit operations
  - 16-bit operations
  - 32-bit operations
  - 64-bit operations

## Instruction Set

The CPU supports a comprehensive instruction set including:

### Basic Instructions
- `NOP`: No operation
- `HLT`: Halt execution

### Data Movement
- `MOV`: Copy data between registers or load immediate values

### Logical Operations
- `AND`, `OR`, `XOR`, `NOT`: Standard logical operations
- `NAND`, `NOR`, `XNOR`: Advanced logical operations
- `SHL`, `SHR`: Shift left and shift right

### Arithmetic Operations
- `ADD`, `SUB`: Addition and subtraction
- `MUL`, `DIV`, `MOD`: Multiplication, division, and modulo
- `INC`, `DEC`: Increment and decrement
- Signed variants: `SADD`, `SSUB`, `SMUL`, `SDIV`, `SMOD`

### Comparison and Flow Control
- `CMP`: Compare values
- Jump instructions:
  - `JMP`: Unconditional jump
  - `JE/JZ`: Jump if equal/zero
  - `JNE/JNZ`: Jump if not equal/not zero
  - `JL`: Jump if less than
  - `JLE`: Jump if less than or equal
  - `JG`: Jump if greater than
  - `JGE`: Jump if greater than or equal

## Building and Running

To build the project, run:
```
make
```

To execute the simulator, run:
```
make run
```

To debug the simulator with GDB, run:
```
make debug
```

## Example Program

The simulator comes with a simple example program that demonstrates how to use the instruction set. The program loads values into registers, performs arithmetic operations, and displays the final state of the registers.