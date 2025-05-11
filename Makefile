CC = gcc
CFLAGS_BASE = -Wall -Wextra -pedantic -std=c23
INCLUDES = -Iinclude
LD = ld

# Set debug flags conditionally
ifeq ($(MAKECMDGOALS),debug)
    CFLAGS = $(CFLAGS_BASE) -g
else
    CFLAGS = $(CFLAGS_BASE)
endif

# Output directory
OUTDIR = out

# Executable
TARGET = $(OUTDIR)/cpu_64b

# Object files
INSTR_OBJ = $(OUTDIR)/instructions.o
ALU_OBJ = $(OUTDIR)/alu.o
CU_OBJ = $(OUTDIR)/cu.o
MAIN_OBJ = $(OUTDIR)/main.o

# All object files
OBJS = $(INSTR_OBJ) $(ALU_OBJ) $(CU_OBJ) $(MAIN_OBJ)

# Default target
all: $(TARGET)

# Create output directory
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Compile instructions files into separate objects and then merge them
$(OUTDIR)/instructions_8b.o: src/instructions/instructions_8b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/instructions_16b.o: src/instructions/instructions_16b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/instructions_32b.o: src/instructions/instructions_32b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/instructions_64b.o: src/instructions/instructions_64b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(INSTR_OBJ): $(OUTDIR)/instructions_8b.o $(OUTDIR)/instructions_16b.o $(OUTDIR)/instructions_32b.o $(OUTDIR)/instructions_64b.o
	$(LD) -r $^ -o $@

# Compile alu files into separate objects and then merge them
$(OUTDIR)/alu_8b.o: src/alu/alu_8b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/alu_16b.o: src/alu/alu_16b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/alu_32b.o: src/alu/alu_32b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUTDIR)/alu_64b.o: src/alu/alu_64b.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ALU_OBJ): $(OUTDIR)/alu_8b.o $(OUTDIR)/alu_16b.o $(OUTDIR)/alu_32b.o $(OUTDIR)/alu_64b.o
	$(LD) -r $^ -o $@

# Compile other source files
$(CU_OBJ): src/cu.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MAIN_OBJ): src/main.c | $(OUTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link all object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -rf $(OUTDIR)

.PHONY: all clean debug run

# Run target
run: $(TARGET)
	./$(TARGET)

# Debug target
debug: clean $(TARGET)
	gdb --args ./$(TARGET)