
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
  @brief  alfabeto.cc: programa cliente.
  Contiene la definición de la clase alfabeto

  @bug No hay bug conocidos

 */

#include "alfabeto.h"

/** 
 * @brief.Recibiremos la línea del fichero e iremos añadiendo los símbolos al fichero
 * @return No retornamos ningún valor
*/ 
void Alfabeto::IncluirSimbolos(const std::string& linea_fichero) {
  const char kEspacio{' '}; 
  for(long unsigned int i{0}; i < linea_fichero.size(); ++i) {
    if (linea_fichero[i] != kEspacio) {
      const Simbolo kSimbolo(linea_fichero[i]); 
      alfabeto_.push_back(kSimbolo); 
    }
  }
}

/**
 * @brief: Comprobará que el símbolo pertenece al alfabeto
 * @return: Booleano que determina si pertence o no
 * @param: El símbolo a comprobar
*/
bool Alfabeto::Pertenece(const Simbolo& simbolo) const {
  for(int i{0}; i < Cardinal(); ++i) {
    if(Elemento(i) == simbolo) {
      return true; 
    }
  }
  return false; 
}

/**
 * @brief: Sobrecargamos el operador de flujo de salida. Para ello, mostraremos cada símbolo del alfabeto 
  separado por un espacio
*/
std::ostream& operator<<(std::ostream& salida, const Alfabeto& alfabeto) {
  for(int i{0}; i < alfabeto.Cardinal(); ++i) {
    salida << alfabeto.Elemento(i) << " "; 
  }
  
  return salida; 
} 
