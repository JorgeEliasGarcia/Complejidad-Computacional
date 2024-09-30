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

  // Función para resolver la función primitiva recursiva. Recibe un vector de enteros, ya que cada fpr puede tener un número variable de argumentos.
  virtual int Resolver(std::vector<int>) = 0; 

 protected: 
  void IncrementarLlamadasRecursivas() {numero_llamadas_recursivas_++;}; // Método para incrementar el número de llamadas recursivas.

 private: 
  static int numero_llamadas_recursivas_; // Número de llamadas recursivas realizadas.
}; 

#endif  // FUNCION_PRIMITIVA_RECURSIVA_H