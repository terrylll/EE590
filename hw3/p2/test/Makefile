CXX = g++ -std=c++11 -O3
LIBS = -lm -lComplexnum
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc 3.cc 4.cc 5.cc 6.cc 7.cc 8.cc 9.cc 10.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libComplexnum.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
