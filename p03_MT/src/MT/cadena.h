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
  @brief  cadena.h Contiene la declaración de la clase cadena

  @bug No hay bug conocidos

 */

#ifndef CADENA_H
#define CADENA_H

#include "simbolo.h"
#include <vector> 

class Cadena {
 public: 
  // Constructor, recibiremos la string
  Cadena(const std::string& cadena);
  Cadena(): cadena_() {};
  
  // Getter 
  std::vector<Simbolo> GetCadena() const { return cadena_; }

  // Método para identificar el número de símbolos de la cadena
  unsigned NumeroSimbolos() const { return cadena_.size(); }

  // Gettr de un símbolo de la cadena
  Simbolo GetSimbolo(unsigned indice) const { return cadena_[indice]; }
  
  // Método para combprobar si la cadena está vacía
  bool EsCadenaVacia() const;

 private: 
  std::vector<Simbolo> cadena_;
}; 

// Sobreescritura del operador de salida
std::ostream& operator<<(std::ostream& os, const Cadena& cadena);

#endif