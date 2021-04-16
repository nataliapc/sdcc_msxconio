.PHONY: clean test release

AS = sdasz80
AR = sdar
CC = sdcc
HEX2BIN = hex2bin

INCDIR = include/
SRCDIR = src/
TESTDIR = test/

OBJDIR=out/
ODIR_GUARD=@mkdir -p $(OBJDIR)

LIBDIR = lib/
LIBDIR_GUARD=@mkdir -p $(LIBDIR)

LDFLAGS = -rc
LIBS = $(LIBDIR)conio.lib
CRT = $(OBJDIR)crt0msx_msxdos_advanced.s.rel

#REL_LIBS := $(addprefix $(INCDIR), crt0msx_msxdos_advanced.rel heap.rel) $(addprefix $(LIBDIR), dos.lib ini.lib)

#DEBUG = -DDEBUG
CCFLAGS := --code-loc 0x0178 --data-loc 0 --disable-warning 196 --disable-warning 85 -mz80 --no-std-crt0 --out-fmt-ihx --opt-code-size $(DEBUG)

#CCFLAGS := --code-loc 0x0178 --data-loc 0 --disable-warning 196 --disable-warning 85 -mz80 --no-std-crt0 --out-fmt-ihx --opt-code-size $(DEBUG)
TEST = test.com

all: $(LIBS)

$(OBJDIR)%.s.rel: */%.s
	@echo "======== ASM $@"
	$(ODIR_GUARD)
	$(AS) -I$(INCDIR) -o $@ $^

$(OBJDIR)%.c.rel: */%.c
	@echo "======== CC $@"
	$(ODIR_GUARD)
	$(CC) -I$(INCDIR) $(CCFLAGS) -c -o $@ $^

$(LIBDIR)conio.lib: $(patsubst $(SRCDIR)%, $(OBJDIR)%.rel, $(wildcard $(SRCDIR)conio_*))
	@echo "################ Compiling $@"
	$(LIBDIR_GUARD)
	$(AR) $(LDFLAGS) $@ $^

$(TEST): $(LIBS) $(CRT) $(patsubst $(TESTDIR)%, $(OBJDIR), $(wildcard $(TESTDIR)*))
	@echo "################ Compiling $@"
	$(CC) $(CCFLAGS) -I$(INCDIR) -L$(INCDIR) -L$(LIBDIR) $(LIBS) $(CRT) $(TESTDIR)$(subst .com,.c,$@) -o $(OBJDIR)$(subst .com,.ihx,$@)
	$(HEX2BIN) -e com $(OBJDIR)$(subst .com,.ihx,$@)
	@mv $(OBJDIR)$(TEST) $(TESTDIR)$(TEST)

run: $(LIBS) $(TEST)
	openmsx -machine msx2_eu -diska $(TESTDIR)

clean:
	@rm -f $(OBJDIR)* $(TESTDIR)$(TEST)
	@rm -f $(LIBS)
	@rmdir $(LIBDIR) $(OBJDIR)
