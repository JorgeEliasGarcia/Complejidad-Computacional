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
  @brief  cinta.h Contiene la declaración de la clase cinta

  @bug No hay bug conocidos

 */

#ifndef CINTA_H
#define CINTA_H

#include "cadena.h"

class Cinta {
 public: 
  // Constructor
  Cinta(const Simbolo& blanco): blanco_(blanco) { cinta_.push_back(blanco); };
  
  // Método para copiar una cadena en la cinta
  void CopiarCadena(const Cadena& cadena);
  
  // Método para actualizar la cinta 
  void ActualizarCinta(const Simbolo& simbolo, const char direccion);

  // Mostrar la cinta
  void MostrarCinta() const; 

 private: 
  std::vector<Simbolo> cinta_; 
  unsigned cabeza_{0}; 
  Simbolo blanco_; //Guardamos que símbolo es el blanco, puesto que puede cambiar según el problema.
};

#endif //CINTA_H