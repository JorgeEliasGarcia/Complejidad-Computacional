/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief combinacion.h: Clase para la implementacion de la operación de combinación
  @bug No hay bug conocidos 

*/

#include "combinacion.h"

// Método para resolver la operación de combinación. Para ello, se resuelven las dos funciones primitivas recursivas con los mismos argumentos y se devuelven en un vector.
std::vector<FuncionPrimitivaRecursiva*> Combinacion::Resolver(FuncionPrimitivaRecursiva* funcion1, FuncionPrimitivaRecursiva* funcion2) {
  std::vector<FuncionPrimitivaRecursiva*> resultado;
  resultado.push_back(funcion1);
  resultado.push_back(funcion2);
  return resultado;
}