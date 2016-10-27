CXX = g++ -std=c++11 -O3

// SOURCES = function.cc
HEADERS = fraction.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_MATRIX=libfraction.a

all: $(LIB_MATRIX)
	make -C test

$(LIB_MATRIX): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_MATRIX) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_MATRIX)
	make -C test clean
