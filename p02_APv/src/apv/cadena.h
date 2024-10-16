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

  // Método para eliminar el primer símbolo de la cadena. 
  void EliminarPrimerSimbolo();
  
  // Método para combprobar si la cadena está vacía
  bool EsCadenaVacia() const;
  
  // Método para obtener el primer símbolo de la cadena
  Simbolo ObtenerSimboloActual() const { return cadena_[0]; }

  void MostrarCadena() const {
    for (const Simbolo& simbolo : cadena_) {
      std::cout << simbolo.GetSimbolo();
    }
    std::cout << std::endl;
  }

 private: 
  std::vector<Simbolo> cadena_;
}; 


#endif