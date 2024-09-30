/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief prodcuto.h: Clase para la implementación de la función producto.
  @bug No hay bug conocidos 

*/

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "funcion_primitiva_recursiva.h"
#include "funcion_nula.h"
#include "suma.h"
#include "../Operaciones/combinacion.h"

// Declaramos la clase FuncionProducto que hereda de FuncionPrimitivaRecursiva
class Producto : public FuncionPrimitivaRecursiva {
 public:
  Producto() {}; // Constructor

  // Método para resolver la función producto.
  int Resolver(std::vector<int> args) override;
};

#endif // PRODUCTO_H0