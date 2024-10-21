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
  Transicion(const Simbolo& simbolo, const Simbolo& simbolo_a_escribir, const char movimiento, const unsigned int estado_destino) : 
    simbolo_necesario_{simbolo}, movimiento_{movimiento}, simbolo_a_escribir_{simbolo_a_escribir}, estado_destino_{estado_destino} {};

  // Getter
  unsigned int GetEstadoDestino() const {return estado_destino_;};
  Simbolo GetSimboloNecesario() const {return simbolo_necesario_;};
  Simbolo GetSimboloAEscribir() const {return simbolo_a_escribir_;};
  
  // Función para determinar si se puede aplicar una transición
  bool TransicionValida(const Simbolo& simbolo) const;

 private: 
  Simbolo simbolo_necesario_; 
  char movimiento_;
  Simbolo simbolo_a_escribir_; 
  unsigned int estado_destino_;
}; 

#endif 