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
  @brief  pila.h Contiene la declaración de la clase pila.

  @bug No hay bug conocidos

*/

#ifndef PILA_H
#define PILA_H

#include "simbolo.h"
#include <vector>

class Pila {
 public: 
  // Constructor simplemente inicializará la pila vacía
  Pila() {};
  
  // Devolverá la cima de la pila
  Simbolo GetCima() const { return pila_[pila_.size() - 1]; };

  // Añadir solo un símbolo a la pila
  void AnadirSimbolo(const Simbolo& simbolo) { pila_.push_back(simbolo); };

  // Actualizamos la pila. 
  void ActualizarPila(const std::vector<Simbolo>& simbolos);

 private: 
  std::vector<Simbolo> pila_;
}; 

#endif 