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

#ifndef COMBINACION_H
#define COMBINACION_H

#include "../FPR/funcion_primitiva_recursiva.h"

// Declaramos la clase Combinación. Esta recibe dos funciones y devuelve en un array el resultado de ambas. Los argumentos para ambas funciones son los mismos por definición. 
class Combinacion { 
 public: 
  Combinacion(std::vector<int> args) { argumentos_ = args; }; // Constructor

  // Método para resolver la operación de combinación.
  std::vector<FuncionPrimitivaRecursiva*> Resolver(FuncionPrimitivaRecursiva* funcion1, FuncionPrimitivaRecursiva* funcion2);
 private: 
  std::vector<int> argumentos_;
}; 

#endif // COMBINACION_H