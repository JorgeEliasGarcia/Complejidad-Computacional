/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Pr ́actica 6: Automatas finitos
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @fecha: 1/11/2022
  @brief  simbolo.h Contiene la declaración de la clase simbolo

  @bug No hay bug conocidos

 */

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo {
 public: 
  //Constructor
  Simbolo (const char simbolo) : simbolo_{simbolo} {};
  //Constructor a partir de otro simbolo
  Simbolo(const Simbolo& simbolo);

  //Getter
  const char GetSimbolo() const {return simbolo_; }; 

  //Sobrecarga del operador de flujo de salida para mostrar los símbolos
  friend std::ostream& operator<<(std::ostream& salida,const Simbolo& simbolo);

 private: 
  char simbolo_; 
}; 


//Sobrecargamos el operador == para comparar simbolos. 
bool operator==(const Simbolo& primer_simbolo, const Simbolo& segundo_simbolo); 

//Sobrecargamos el operador != para comparar simbolos. 
bool operator!=(const Simbolo& primer_simbolo, const Simbolo& segundo_simbolo); 

#endif