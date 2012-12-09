CC := g++
OPTIONS := -Wall -g
SOURCES := $(wildcard src/*/*.cpp)
TARGETS := $(patsubst %.cpp,%.exe,$(SOURCES))

GHC := ghc
HOPTIONS := -O2 -prof -auto-all --make
HSOURCES := $(wildcard src/*/*.hs)
HTARGETS := $(patsubst %.hs,%.hs.exe,$(HSOURCES))

all	: cxx haskell

cxx : $(TARGETS)

haskell : $(HTARGETS)

%.hs.exe : %.hs
	@echo Compiling $< ...
	@$(GHC) $(HOPTIONS) $< -o $@
	#@$(GHC) -O2 -prof -auto-all --make -outputdir bin $< -o $@

%.exe : %.cpp
	@echo Compiling $< ...
	@$(CC) $(OPTIONS) $< -o $@

clean	: 
	@rm -rf src/*/*.exe