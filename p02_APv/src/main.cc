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

#include "main.h"

int main(int argc, char* argv[]) { 
  ModoUso(argc, argv); 
  // Leemos el nombre del fichero y el modo traza 
  const std::string nombre_fichero = argv[1];
  int modo_traza = std::stoi(argv[2]);
  // Creamos el autómata
  Automata automata(nombre_fichero, (modo_traza == 1));
  // Examinamos las cadenas que vaya introduciendo 
  ExaminarCadenas(automata);

  return 0; 
}