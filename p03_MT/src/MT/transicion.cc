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
  @brief  transicion.cc Contiene la declaración de la clase transicion

  @bug No hay bug conocidos

 */

#include "transicion.h"

// Función para determinar si se puede aplicar una transición
bool Transicion::TransicionValida(const Simbolo& simbolo) const {
  return (simbolo_necesario_ == simbolo); 
}