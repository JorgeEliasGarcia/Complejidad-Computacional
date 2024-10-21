/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Pr ́actica 3: Máquina de Turing
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @fecha: 1/11/2022
  @brief  cinta.cc Contiene la definición de la clase cinta

  @bug No hay bug conocidos

 */

#include "cinta.h"

// Método para copiar una cadena en la cinta
void Cinta::CopiarCadena(const Cadena& cadena) {
  cinta_.resize(cadena.NumeroSimbolos()); 
  for (unsigned i = 0; i < cadena.NumeroSimbolos(); i++) {
    cinta_[i] = cadena.GetSimbolo(i);
  }
  cinta_.push_back(blanco_);
}

// Método para actualizar la cinta, atendiendo al símbolo a escibir y el movimiento a realizar
void Cinta::ActualizarCinta(const Simbolo& simbolo, const char direccion) {
  cinta_[cabeza_] = simbolo;
  if (direccion == 'R') {
    cabeza_++;
    if (cabeza_ == cinta_.size()) {
      cinta_.push_back(blanco_);
    }
  } else if (direccion == 'L') {
    if (cabeza_ == 0) {
      cinta_.insert(cinta_.begin(), blanco_); // Rodamos todos los elementos de la cinta una posición a la derecha, y añadimos un blanco al principio
    } else {
      cabeza_--;
    }
  }  // Si la dirección era 'S' no se hace nada, pues mantenemos la cabeza en la misma posición

}

// Mostrar la cinta
void Cinta::MostrarCinta() const {
  for (unsigned i = 0; i < cinta_.size(); i++) {
    std::cout << cinta_[i].GetSimbolo();
  }
  std::cout << std::endl;
}
