/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief funcion_nula.h: Clase para la implementación de la función nula.
  @bug No hay bug conocidos 

*/

#include "funcion_nula.h"

// Método para resolver la función nula. Esta deverá recibir un vector con un solo elemento, pues la definición de la función nula es z(x) = 0.
int FuncionNula::Resolver(std::vector<int> args) {
  if (args.size() != 1) { // Comprobamos que el número de argumentos sea 0.
    std::cerr << "Error: la función nula no recibe argumentos." << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva::IncrementarNumeroLlamadasFuncion(); // Incrementamos el número de llamadas a funciones
  return 0; // Devolvemos 0, ya que la función nula siempre devuelve 0.
}