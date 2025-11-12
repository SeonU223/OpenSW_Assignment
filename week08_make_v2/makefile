.PHONY: all basic_ops advanced_ops clean

# ===== paths =====
PROJ    := $(abspath .)
SRC_DIR := $(PROJ)/src
OBJ_DIR := $(PROJ)/obj
BIN_DIR := $(PROJ)/bin
INC_DIR := $(PROJ)/include
LIB_DIR := $(PROJ)/lib

# ===== tools/flags =====
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR) -lmybasic -lmyadvanced -lm

# ===== targets =====
APP      := $(BIN_DIR)/myapp
APP_OBJS := $(OBJ_DIR)/myapp.o
LIBS     := $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

all: basic_ops advanced_ops $(APP)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

$(APP): $(APP_OBJS) $(LIBS) | $(BIN_DIR)
	$(CC) $(APP_OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/myapp $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
