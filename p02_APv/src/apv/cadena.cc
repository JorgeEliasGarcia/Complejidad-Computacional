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
  @brief  cadena.cc Contiene la declaración de la clase cadena

  @bug No hay bug conocidos

 */

#include "cadena.h"

// Constructor, recibiremos la string y convertiremos cada uno de sus caracteres en un símbolo
Cadena::Cadena(const std::string& cadena) {
  for (const char& simbolo : cadena) {
    cadena_.push_back(Simbolo(simbolo));
  }
}

// Método para eliminar el primer símbolo de la cadena. Si la cadena está vacía, añadiremos un símbolo epsilon.
void Cadena::EliminarPrimerSimbolo() {
  cadena_.erase(cadena_.begin());
}

// Método para comprobar si la cadena está vacía
bool Cadena::EsCadenaVacia() const {
  return (cadena_.size() == 0);
}