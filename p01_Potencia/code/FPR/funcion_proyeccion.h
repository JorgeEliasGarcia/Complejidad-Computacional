/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief funcion_proyección.h: Clase para la implementación de la función de proyección.
  @bug No hay bug conocidos 

*/

#ifndef FUNCION_PROYECCION_H
#define FUNCION_PROYECCION_H

#include "funcion_primitiva_recursiva.h"

// Declaramos la clase FuncionProyeccion que hereda de FuncionPrimitivaRecursiva
class FuncionProyeccion : public FuncionPrimitivaRecursiva {
 public:
  FuncionProyeccion() {}; // Constructor

  // Método para resolver la función de proyección.
  int Resolver(std::vector<int> argumentos, int indice, int tamanyo) const override;

  // Sobrecargamos los métodos Resolver de la clase base, pero no los usaremos.
  int Resolver() const override { return 0; };
  int Resolver(int argumento) const override { return 0; };
};

#endif  // FUNCION_PROYECCION_H