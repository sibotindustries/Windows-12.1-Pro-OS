# Compilador e flags
CC = gcc
CFLAGS = -Wall -g -I.

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Arquivos
KERNEL_SRC = $(SRC_DIR)/kernel.c
GUI_SRC = $(SRC_DIR)/GUI.c
DRIVER_SRC = $(SRC_DIR)/driver.c

KERNEL_OBJ = $(OBJ_DIR)/kernel.o
GUI_OBJ = $(OBJ_DIR)/GUI.o
DRIVER_OBJ = $(OBJ_DIR)/driver.o

TARGET = $(BIN_DIR)/os_system

# Alvos
all: setup $(TARGET)

# Cria os diretórios de saída, se não existirem
setup:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Compilação dos objetos
$(KERNEL_OBJ): $(KERNEL_SRC) $(INCLUDE_DIR)/kernel.h
	$(CC) $(CFLAGS) -c $< -o $@

$(GUI_OBJ): $(GUI_SRC) $(INCLUDE_DIR)/GUI.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DRIVER_OBJ): $(DRIVER_SRC) $(INCLUDE_DIR)/driver.h
	$(CC) $(CFLAGS) -c $< -o $@

# Linkagem dos objetos para formar o executável final
$(TARGET): $(KERNEL_OBJ) $(GUI_OBJ) $(DRIVER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Recompilar apenas as dependências necessárias
.PHONY: all clean setup
