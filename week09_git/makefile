PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
LIB_DIR=$(PROJ_DIR)/lib
OBJ_DIR=$(PROJ_DIR)/obj

CC=gcc
AR=ar
LN=ln -s

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: all clean basic

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c
	$(CC) $< -L$(LIB_DIR) -lmyops -o $@ -I$(INC_DIR) 


basic: $(LIB_DIR)/libmyops.so

$(LIB_DIR)/libmyops.so: $(LIB_DIR)/libmyops.so.1
	$(LN) $(notdir $<) $@

$(LIB_DIR)/libmyops.so.1: $(LIB_DIR)/libmyops.so.1.0
	$(LN) $(notdir $<) $@

$(LIB_DIR)/libmyops.so.1.0: $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mypow.o $(OBJ_DIR)/mysub.o
	$(CC) -shared -Wl,-soname=libmyops.so.1 $^ -o $(LIB_DIR)/libmyops.so.1.0 -lc -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -fPIC $< -o $@ -I$(INC_DIR)


clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/* $(LIB_DIR)/*
