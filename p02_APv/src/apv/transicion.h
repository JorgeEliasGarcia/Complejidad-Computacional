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
  @brief  transicion.h Contiene la declaración de la clase transicion

  @bug No hay bug conocidos

 */

#ifndef TRANSICION_H
#define TRANSICION_H

#include "simbolo.h"
#include <vector>

class Transicion {
 public: 
  //Constructor
  Transicion(const Simbolo& simbolo, const Simbolo& simbolo_cima_pila, const std::vector<Simbolo>& nuevos_simbolos_pila, const unsigned int estado_destino, unsigned id) :
   simbolo_{simbolo}, simbolo_cima_pila_{simbolo_cima_pila}, nuevos_simbolos_pila_{nuevos_simbolos_pila}, estado_destino_{estado_destino}, id_{id} {};

  // Getter
  unsigned int GetEstadoDestino() const {return estado_destino_;};
  std::vector<Simbolo> GetNuevosSimbolosPila() const {return nuevos_simbolos_pila_;};
  unsigned GetId() const {return id_;};
  
  // Función para determinar si se puede aplicar una transición
  bool TransicionValida(const Simbolo& simbolo, const Simbolo& simbolo_cima_pila) const;

 private: 
  Simbolo simbolo_; 
  Simbolo simbolo_cima_pila_; 
  std::vector<Simbolo> nuevos_simbolos_pila_; 
  unsigned int estado_destino_;
  // Añadimos un id para poder identificar las transiciones, y así saber que transiciones tenemos pendientes por poder aplicar en el automata
  unsigned id_; 
}; 

#endif 