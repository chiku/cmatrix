# Written by     : Chirantan Mitra

INCLUDE_FILES += .
CPPFILES = $(shell ls size/*.cpp)

all: prepare vendor

vendor:
	@cd vendor && make

prepare:
	mkdir -p ../bin/obj

clean:
	rm -f *.o *.a
	@cd vendor && make clean

.PHONY: all prepare clean vendor
