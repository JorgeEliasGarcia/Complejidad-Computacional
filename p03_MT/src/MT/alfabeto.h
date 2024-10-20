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
  @brief  alfabeto.h Contiene la declaración de la clase alfabeto

  @bug No hay bug conocidos

 */

#include <iostream>
#include <vector>

#include "simbolo.h"

#ifndef ALFABETO_H
#define ALFABETO_H

class Alfabeto {

 public: 
  //Constructor por defecto dejará el alfabeto vacío
  Alfabeto() { alfabeto_ = alfabeto_; }

  //Constructor
  Alfabeto(const Simbolo& simbolo) { alfabeto_.push_back(simbolo); }; 
  
  //Añadiremos los símbolos al alfabeto
  void IncluirSimbolos(const std::string& linea_fichero); 

  // Devolverá el cardinal del alfabeto
  int Cardinal() const { return alfabeto_.size(); };

  //Devolverá el elemento en la posición i
  Simbolo Elemento(int i) const { return alfabeto_[i]; };

  //Comprobará que el símbolo pertenece al alfabeto
  bool Pertenece(const Simbolo& simbolo) const; 

  private: 
  std::vector<Simbolo> alfabeto_; 

}; 

//Sobrecargamos el operador de flujo de salida
std::ostream& operator<<(std::ostream& salida, const Alfabeto& alfabeto); 


#endif