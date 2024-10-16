CXX = g++						         
CXXFLAGS = -std=c++14 -g -Wall	 
LDFLAGS =	

all: automata

automata: main.o funciones_main.o apv/simbolo.o apv/cadena.o apv/alfabeto.o apv/pila.o apv/transicion.o apv/estado.o apv/automata.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o automata doc
	rm -f apv/*.o
	rm -rf *~ basura b i
	rm -rf automata
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;