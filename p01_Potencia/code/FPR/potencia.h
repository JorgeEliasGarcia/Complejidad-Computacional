/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief potencia.h: Clase para la implementación de la función potencia. 
  @bug No hay bug conocidos 

*/

#ifndef POTENCIA_H
#define POTENCIA_H

#include "funcion_primitiva_recursiva.h"
#include "producto.h"

// Declaración de la clase Potencia que hereda de FuncionPrimitivaRecursiva
class Potencia : public FuncionPrimitivaRecursiva {
 public:
  Potencia() {}; // Constructor

  // Método para resolver la función potencia.
  int Resolver(std::vector<int> args) override;
};

#endif // POTENCIA_H