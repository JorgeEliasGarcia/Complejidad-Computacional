/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.cc: Programa cliente para implementar un automáta de pila
  @bug No hay bug conocidos 

*/

#include "apv/automata.h"
#include "apv/cadena.h"
#include "main.h"

int main(int argc, char* argv[]) { 
  ModoUso(argc, argv); 
  // Leemos el nombre del fichero y el modo traza 
  const std::string nombre_fichero = argv[1];
  int modo_traza = std::stoi(argv[2]);
  // Creamos el autómata
  Automata automata(nombre_fichero, (modo_traza == 1));
  // Leemos la cadena
  std::string cadena;
  std::cout << "Introduce la cadena: ";
  std::cin >> cadena;
  Cadena cadena_obj(cadena);
  // Comprobamos si la cadena pertenece al lenguaje
  if (automata.CadenaPerteneceAlLenguaje(cadena_obj)) {
    std::cout << "La cadena pertenece al lenguaje" << std::endl;
  } else {
    std::cout << "La cadena no pertenece al lenguaje" << std::endl;
  }

  return 0; 
}