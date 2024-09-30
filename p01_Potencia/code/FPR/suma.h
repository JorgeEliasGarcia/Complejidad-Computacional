/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief suma.h: Clase para la implementación de la función suma.
  @bug No hay bug conocidos 

*/

#ifndef SUMA_H
#define SUMA_H

#include "funcion_primitiva_recursiva.h"
#include "funcion_proyeccion.h"
#include "funcion_sucesor.h"

// Declaramos la clase FuncionSuma que hereda de FuncionPrimitivaRecursiva
class FuncionSuma : public FuncionPrimitivaRecursiva {
 public:
  FuncionSuma() {}; // Constructor

  // Método para resolver la función suma.
  int Resolver(std::vector<int> args) override;

};

#endif