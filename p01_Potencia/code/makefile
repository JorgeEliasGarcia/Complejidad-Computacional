CXX = g++						         
CXXFLAGS = -std=c++14 -g -Wall	 
LDFLAGS =	

all: potencia

potencia: main.o funciones_main.o FPR/funcion_primitiva_recursiva.o  FPR/funcion_nula.o FPR/funcion_sucesor.o FPR/funcion_proyeccion.o FPR/suma.o FPR/producto.o FPR/potencia.o Operaciones/composicion.o Operaciones/combinacion.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o potencia doc
	rm -f FPR/*.o
	rm -f Operaciones/*.o
	rm -rf *~ basura b i
	rm -rf potencia
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;