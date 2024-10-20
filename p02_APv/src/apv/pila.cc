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

// Actualizar la pila del automata siginificará eliminar el último símbolo de la pila y añadir los nuevos símbolos. Si es epsilon, no añadimos nada.
void Pila::ActualizarPila(const std::vector<Simbolo>& simbolos) {
  const Simbolo kEpsilon('.');
  if (pila_.size() > 0) {
    pila_.pop_back(); // Eliminamos el último símbolo de la pila
  }
  for (int i = simbolos.size() - 1; i >= 0; --i) {
    if (simbolos[i] != kEpsilon) {
      pila_.push_back(simbolos[i]); // Añadimos los nuevos símbolos a la pila
    }
  }
}

// Comprobamos si la pila está vacía
bool Pila::Vacia() const {
  return (pila_.size() == 0);
}

// Sobreescritura del operador de salida
std::ostream& operator<<(std::ostream& os, const Pila& pila) {
  for (const Simbolo& simbolo : pila.GetPila()) {
    os << simbolo.GetSimbolo();
  }
  if (pila.Vacia()) {
    os << '.';
  }
  return os;
}