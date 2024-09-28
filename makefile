CXX = g++						         
CXXFLAGS = -std=c++14 -g -Wall	 
LDFLAGS =	

all: prueba

prueba: prueba.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o prueba doc
	rm -rf *~ basura b i
	rm -rf prueba
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;