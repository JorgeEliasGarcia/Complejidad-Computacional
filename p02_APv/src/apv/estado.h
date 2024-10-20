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

#ifndef ESTADO_H
#define ESTADO_H

#include "transicion.h"

class Estado {
 public: 
  // Constructor por defecto
  Estado() : nombre_("") {}; 
  
  // Getter y setter del nombre del estado
  std::string GetNombre() const {return nombre_;};
  void SetNombre(const std::string& nombre) {nombre_ = nombre;};

  // Añadimos una transición al estado
  void AnadirTransicion(const Transicion& transicion) {transiciones_.push_back(transicion);};

  // Devolvemos todas las transiciones que se pueden aplicar 
  std::vector<Transicion> TransicionesValidas(const Simbolo& simbolo, const Simbolo& simbolo_cima_pila) const;

  // Getter de las transiciones
  std::vector<Transicion> GetTransiciones () const {return transiciones_;};
  Transicion GetTransicion(const unsigned int indice) const {return transiciones_[indice];};

 private: 
  std::vector<Transicion> transiciones_;
  std::string nombre_; 
}; 

#endif 