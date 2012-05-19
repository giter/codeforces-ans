CC := ghc
SOURCES := $(wildcard src/*.hs)
TARGETS := $(patsubst %.hs,%.exe,$(SOURCES))


all	:  $(TARGETS)

%.exe : %.hs
	@echo Compiling $<...
	@$(CC) -O2 -prof -auto-all --make -outputdir bin $< -o $@
	@mv $@ bin

clean	: 
	@rm -rf bin/
