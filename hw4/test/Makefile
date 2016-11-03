CXX = g++ -std=c++11 -O3 -fpermissive
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = ErrorTest.cc ErrorTest2.cc 2.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
