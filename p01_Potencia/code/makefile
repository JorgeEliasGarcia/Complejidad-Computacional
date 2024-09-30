CXX = g++						         
CXXFLAGS = -std=c++14 -g -Wall	 
LDFLAGS =	

all: potencia

potencia: main.o funciones_main.o FPR/funcion_proyeccion.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o potencia doc
	rm -f FPR/*.o
	rm -rf *~ basura b i
	rm -rf potencia
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;