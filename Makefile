.PHONY: clean test release

SDCC_VER := 4.2.0
DOCKER_IMG = nataliapc/sdcc:$(SDCC_VER)
DOCKER_RUN = docker run -i --rm -u $(shell id -u):$(shell id -g) -v .:/src -w /src $(DOCKER_IMG)

AS = $(DOCKER_RUN) sdasz80
AR = $(DOCKER_RUN) sdar
CC = $(DOCKER_RUN) sdcc
HEX2BIN = hex2bin
EMUSCRIPTS = -script ./emulation/boot.tcl

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COL_RED = \e[1;31m
	COL_YELLOW = \e[1;33m
	COL_ORANGE = \e[1;38:5:208m
	COL_BLUE = \e[1;34m
	COL_GRAY = \e[1;30m
	COL_WHITE = \e[1;37m
	COL_RESET = \e[0m
endif

INCDIR = include/
SRCDIR = src/
TESTDIR = test/

OBJDIR=out/
ODIR_GUARD=@mkdir -p $(OBJDIR)

LIBDIR = lib/
LIBDIR_GUARD=@mkdir -p $(LIBDIR)

LDFLAGS = -rc
CRT = $(OBJDIR)crt0msx_msxdos_advanced.s.rel

#DEBUG = -DDEBUG
# -D_ROMBIOS_
DEFINES :=
FULLOPT :=  --max-allocs-per-node 2000000
CCFLAGS :=  --code-loc 0x0180 --data-loc 0 --no-std-crt0 --out-fmt-ihx --fomit-frame-pointer --opt-code-speed \
			--disable-warning 196 --disable-warning 85 -mz80 $(FULLOPT) $(DEBUG) $(DEFINES) $(EXTERNFLAGS)

LIBS = $(LIBDIR)conio.lib
TEST = test.com

all: $(LIBS)

$(OBJDIR)%.s.rel: */%.s
	@echo "$(COL_WHITE)======== ASM $@$(COL_RESET)"
	$(ODIR_GUARD)
	$(AS) -I$(INCDIR) -o $@ $^ ;

$(OBJDIR)%.c.rel: */%.c
	@echo "$(COL_WHITE)======== CC $@$(COL_RESET)"
	$(ODIR_GUARD)
	$(CC) -I$(INCDIR) $(CCFLAGS) -c -o $@ $^ ;

$(LIBDIR)conio.lib: $(patsubst $(SRCDIR)%, $(OBJDIR)%.rel, $(wildcard $(SRCDIR)conio_*))
	@echo "$(COL_ORANGE)################ Compiling $@$(COL_RESET)"
	$(LIBDIR_GUARD)
	$(AR) $(LDFLAGS) $@ $^ ;

$(TEST): $(LIBS) $(CRT) $(patsubst $(TESTDIR)%, $(OBJDIR), $(wildcard $(TESTDIR)*))
	@echo "$(COL_YELLOW)################ Compiling $@$(COL_RESET)"
	$(CC) $(CCFLAGS) -I$(INCDIR) -L$(INCDIR) -L$(LIBDIR) $(LIBS) $(CRT) $(TESTDIR)$(subst .com,.c,$@) -o $(OBJDIR)$(subst .com,.ihx,$@) ;
	$(HEX2BIN) -e com $(OBJDIR)$(subst .com,.ihx,$@) ;
	@mv $(OBJDIR)$(TEST) $(TESTDIR)$(TEST)

run: $(LIBS) $(TEST)
	openmsx -machine msx2_eu -ext debugdevice -diska $(TESTDIR) $(EMUSCRIPTS)

clean:
	@rm -f $(TESTDIR)$(TEST)
	@rm -rf $(LIBDIR) $(OBJDIR)
