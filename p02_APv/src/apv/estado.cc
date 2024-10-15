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
  @brief  estado.h Contiene la declaración de la clase estado.

  @bug No hay bug conocidos

*/

#include "estado.h"

// Comprobamos si existe alguna transición que se pueda aplicar
bool Estado::ExisteTransicion(const Simbolo& simbolo, const Simbolo& simbolo_cima_pila) const {
  for (const Transicion& transicion : transiciones_) {
    if (transicion.TransicionValida(simbolo, simbolo_cima_pila)) {
      return true; 
    }
  }
  return false; 
}

// Devolvemos todas las transiciones que se pueden aplicar
std::vector<Transicion> Estado::TransicionesValidas(const Simbolo& simbolo, const Simbolo& simbolo_cima_pila) const {
  std::vector<Transicion> transiciones_validas; 
  for (const Transicion& transicion : transiciones_) {
    if (transicion.TransicionValida(simbolo, simbolo_cima_pila)) {
      transiciones_validas.push_back(transicion);
    }
  }
  return transiciones_validas;
}