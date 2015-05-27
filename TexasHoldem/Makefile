CC=gcc
OBJDIR=objs
SRCDIR=src
INCDIR=$(SRDIR)/inc
CFLAGS+=-I$(INCDIR)

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS=-Wall -std=c99 -O2
CFLAGS_DEBUG+=-O0 -g3 -Werror -DDEBUG -pedantic


all: run

debug: CC+=$(CFLAGS_DEBUG)
debug: run .FORCE

.FORCE:

run: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS): | $(OBJDIR)
$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(wildcard $(INCDIR)/*.h) Makefile
	$(CC) $(CFLAGS) $< -c -o $@
