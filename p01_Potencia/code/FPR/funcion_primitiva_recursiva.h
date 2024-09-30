/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief funcion_primitiva_recursiva.h: Clase base abstracta para la implementación de funciones primitivas recursivas.
  @bug No hay bug conocidos 

*/

#ifndef FUNCION_PRIMITIVA_RECURSIVA_H
#define FUNCION_PRIMITIVA_RECURSIVA_H

#include <vector>
#include <iostream>

class FuncionPrimitivaRecursiva {
 public: 
  FuncionPrimitivaRecursiva() {}; // Constructor por defecto

  // Función para resolver la función primitiva recursiva. Debemos sobrecargarla varias veces, pues cada función primitiva recursiva tiene un número distinto de argumentos.
  virtual int Resolver() const = 0; // Será sobrescrita por la clase FuncionNula. 
  virtual int Resolver(int argumento) const = 0; // Será sobrescrita por la clase FuncionSucesor.
  virtual int Resolver(std::vector<int> argumentos, int indice, int tamanyo) const = 0; // Será sobrescrita por la clase FuncionProyeccion.

 protected: 
  static int numero_llamadas_recursivas_; // Número de llamadas recursivas realizadas.
}; 

#endif  // FUNCION_PRIMITIVA_RECURSIVA_H