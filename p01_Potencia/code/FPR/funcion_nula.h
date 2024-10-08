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

#ifndef FUNCION_NULA_H
#define FUNCION_NULA_H

#include "funcion_primitiva_recursiva.h"

// Declaramos la clase FuncionNula que hereda de FuncionPrimitivaRecursiva
class FuncionNula : public FuncionPrimitivaRecursiva {
 public:
  FuncionNula() {}; // Constructor

  // Método para resolver la función nula.
  int Resolver(std::vector<int> args) override; 

};

#endif  // FUNCION_NULA_H