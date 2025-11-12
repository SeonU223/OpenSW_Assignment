PROJ_DIR=$(shell pwd)
SRCDIR  := $(PROJ_DIR)/src
INCDIR  := $(PROJ_DIR)/include
OBJDIR  := $(PROJ_DIR)/obj
LIBDIR  := $(PROJ_DIR)/lib
BINDIR  := $(PROJ_DIR)/bin

CC      := gcc
AR      := ar
ARFLAGS := rv
CFLAGS  := -Wall -Wextra -O2 -I$(INCDIR)

LIBNAME := libmybasic.a
LIBPATH := $(LIBDIR)/$(LIBNAME)
APP     := $(BINDIR)/myapp

BASIC_SRCS := $(SRCDIR)/add.c $(SRCDIR)/sub.c $(SRCDIR)/mul.c $(SRCDIR)/div.c
BASIC_OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(BASIC_SRCS))
APP_OBJS   := $(OBJDIR)/myapp.o

.PHONY: all basic clean dirs run

all: dirs $(APP)

basic: dirs $(LIBPATH)

$(APP): $(APP_OBJS) $(LIBPATH) | $(BINDIR)
	$(CC) $(APP_OBJS) -L$(LIBDIR) -lmybasic -o $@

$(LIBPATH): $(BASIC_OBJS) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

dirs: | $(BINDIR) $(LIBDIR) $(OBJDIR)

$(BINDIR) $(LIBDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@echo "Cleaning up.."
	rm -rf $(OBJDIR)/*.o $(APP) $(LIBPATH)

run: $(APP)
	$(APP)
