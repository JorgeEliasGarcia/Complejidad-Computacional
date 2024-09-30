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

#ifndef FUNCION_SUCESOR_H
#define FUNCION_SUCESOR_H

#include "funcion_primitiva_recursiva.h"

// Declaramos la clase FuncionSucesor que hereda de FuncionPrimitivaRecursiva
class FuncionSucesor : public FuncionPrimitivaRecursiva {
 public:
  FuncionSucesor() {}; // Constructor

  // Método para resolver la función de sucesor.
  int Resolver(std::vector<int> argumento) override { return argumento[0] + 1; };
};

#endif // FUNCION_SUCESOR_H