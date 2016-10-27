CXX = g++ -std=c++11
LIBS = -lm
INCLUDE_DIRS = -I..

SOURCES = 1.cc 2.cc 3.cc 4.cc 5.cc 6.cc 7.cc 8.cc 9.cc 10.cc 11.cc 12.cc 13.cc 14.cc 15.cc 16.cc 17.cc 18.cc 19.cc 20.cc 21.cc 22.cc 23.cc 24.cc 25.cc 26.cc 27.cc 28.cc 29.cc 30.cc 31.cc 32.cc 33.cc 34.cc 35.cc



TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh ../libComplexnum.a ../libfraction.a
	$(CXX) $(LIBS) $(INCLUDE_DIRS) $< -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
