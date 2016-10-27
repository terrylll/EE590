CXX = g++ -std=c++11 -O3

 SOURCES = ComplexOP.cc
HEADERS = Complexnum.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_MATRIX=libComplexnum.a

all: $(LIB_MATRIX)
	make -C test

$(LIB_MATRIX): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_MATRIX) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_MATRIX)
	make -C test clean
