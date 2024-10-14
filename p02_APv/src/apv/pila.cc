/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Práctica 6: Lenguajes regulares
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @fecha: 1/11/2022
  @brief  pila.cc Contiene la declaración de la clase pila.

  @bug No hay bug conocidos

*/

#include "pila.h"

// Actualizar la pila del automata siginificará eliminar el último símbolo de la pila y añadir los nuevos símbolos.
void Pila::ActualizarPila(const std::vector<Simbolo>& simbolos) {
  pila_.pop_back(); // Eliminamos el último símbolo de la pila
  for (int i = simbolos.size() - 1; i >= 0; --i) {
    pila_.push_back(simbolos[i]);
  }
}