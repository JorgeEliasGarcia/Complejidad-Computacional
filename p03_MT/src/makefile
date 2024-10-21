CXX = g++						         
CXXFLAGS = -std=c++14 -g -Wall	 
LDFLAGS =	

all: mt

mt: main.o funciones_main.o MT/simbolo.o MT/alfabeto.o MT/cadena.o MT/transicion.o  MT/cinta.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o mt doc
	rm -f MT/*.o
	rm -rf *~ basura b i
	rm -rf mt
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;