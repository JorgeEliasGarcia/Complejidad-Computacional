/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief Composicion.cc: Clase para la implementacion de la operación de composición
  @bug No hay bug conocidos 

*/

#include "composicion.h"

// Método para resolver la operación de composición. Recibirá una función y un vector de funciones. Los argumentos para todos las funciones del array son los mismos por definición. 
// LLamaremos a la función 1 con todos los resultados de las funciones del vector pasado por parámetros. Para ello, primero almacenamos los resultados de las funciones en un vector auxiliar.
int Composicion::Resolver(FuncionPrimitivaRecursiva* funcion1, std::vector<FuncionPrimitivaRecursiva*> funciones) {
  std::vector<int> resultados_funciones; // Vector para almacenar los resultados de las funciones
  for (unsigned i {0}; i < funciones.size(); i++) {
    resultados_funciones.push_back(funciones[i]->Resolver(argumentos_));
  }
  return funcion1->Resolver(resultados_funciones);
}