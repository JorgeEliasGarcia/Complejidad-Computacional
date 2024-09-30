/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief Composicion.h: Clase para la implementacion de la operación de composición
  @bug No hay bug conocidos 

*/

#ifndef COMPOSICION_H
#define COMPOSICION_H

#include "../FPR/funcion_primitiva_recursiva.h"

// Declaramos la clase Composicion
class Composicion {  
 public:
  Composicion(std::vector<int> args) { argumentos_ = args; }; // Constructor

  // Método para resolver la operación de composición.
  int Resolver(FuncionPrimitivaRecursiva* funcion1, std::vector<FuncionPrimitivaRecursiva*> funciones);

  private: 
  std::vector<int> argumentos_; 
}; 

#endif  // Composicion_H