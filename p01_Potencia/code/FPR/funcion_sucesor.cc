/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief funcion_sucesor.h: Clase para la implementación de la función de sucesor.
  @bug No hay bug conocidos 

*/

#include "funcion_sucesor.h"

// Método para resolver la función de sucesor. Esta deverá recibir un vector con un solo elemento, pues la definición de la función sucesor es s(x) = x + 1.
int FuncionSucesor::Resolver(std::vector<int> argumento) {
  if (argumento.size() != 1) { // Comprobamos que el número de argumentos sea 1.
    std::cerr << "Error: la función sucesor recibe un único argumento." << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva::IncrementarNumeroLlamadasFuncion(); // Incrementamos el número de llamadas a funciones
  return argumento[0] + 1; // Devolvemos el argumento incrementado en 1.
}