CC = gcc
ASM = nasm

CFLAGS = -m32 -Wall -Wextra -I./src/c
ASMFLAGS = -f elf32

SRC_C = src/c
SRC_ASM = src/asm
BUILD = build


C_FILES = $(SRC_C)/interface.c $(SRC_C)/bridge.c
C_OBJS = $(BUILD)/interface.o $(BUILD)/bridge.o

ASM_FILE = $(SRC_ASM)/crud.asm
ASM_OBJ = $(BUILD)/crud.o

TARGET = $(BUILD)/programa



all: $(TARGET)


$(TARGET): $(C_OBJS) $(ASM_OBJ)
	$(CC) -m32 $^ -o $@


$(BUILD)/%.o: $(SRC_C)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@


$(ASM_OBJ): $(ASM_FILE)
	mkdir -p $(BUILD)
	$(ASM) $(ASMFLAGS) $< -o $@


clean:
	rm -rf $(BUILD)/*.o $(TARGET)


rebuild: clean all