# ===== paths =====
TOP     := $(abspath ..)
INCDIR  := $(TOP)/include
LIBDIR  := $(TOP)/lib
SRCDIR  := $(CURDIR)/src
OBJDIR  := $(CURDIR)/obj

# ===== tools/flags =====
CC      := gcc
AR      := ar
ARFLAGS := rcs
CFLAGS  := -Wall -Wextra -O2 -I$(INCDIR)

# ===== targets =====
SRCS  := $(wildcard $(SRCDIR)/*.c)
OBJS  := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
LIB   := $(LIBDIR)/libmyadvanced.a

.PHONY: all clean
all: $(LIB)

$(LIB): $(OBJS) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) $(LIBDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(LIB)
