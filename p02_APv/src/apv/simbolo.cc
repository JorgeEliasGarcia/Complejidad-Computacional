/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Pr ́actica 6: Automatas finitos
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @fecha: 5/10/2022
  @brief  simbolo.cc: definición de la clase simbolo
  Contiene la definición de la clase simbolo

  @bug No hay bug conocidos

 */

#include "simbolo.h"

// Constructor a partir de otro simbolo
Simbolo::Simbolo(const Simbolo& simbolo) {
  simbolo_ = simbolo.GetSimbolo(); 
}

// Sobrecarga del operador de flujo de salida para mostrar los símbolos
std::ostream& operator<<(std::ostream& salida,const Simbolo& simbolo) {
  salida << simbolo.GetSimbolo(); 
  return salida; 
}

// Sobrecargamos el operador == para comparar simbolos.
bool operator==(const Simbolo& primer_simbolo, const Simbolo& segundo_simbolo) {
  return primer_simbolo.GetSimbolo() == segundo_simbolo.GetSimbolo(); 
}

// Sobrecargamos el operador != para comparar simbolos.
bool operator!=(const Simbolo& primer_simbolo, const Simbolo& segundo_simbolo) {
  return !(primer_simbolo == segundo_simbolo); 
}