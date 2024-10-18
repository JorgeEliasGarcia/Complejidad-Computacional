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
  @brief  automata.h Contiene la declaración de la clase automata.

  @bug No hay bug conocidos

*/

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "alfabeto.h"
#include "cadena.h"
#include "estado.h"
#include "pila.h"
#include <fstream>
#include <sstream>
#include <map> 

class Automata {
 public: 
  // Constructor
  Automata(const std::string& nombre_fichero, bool modo_traza); 
  // Destructor
  ~Automata() {};
  
  // Método para comprobar si una cadena es aceptada por el autómata
  bool CadenaPerteneceAlLenguaje(const Cadena& cadena) const;

 private: 
  Alfabeto alfabeto_;
  std::vector<Estado> estados_;
  Alfabeto alfabeto_pila_;
  Pila pila_;
  unsigned estado_inicial_; // Solo guardamos el índice del estado inicial
  // Añadiremos un map, para poder trabajar con los estados por índices y no por nombre, pero poder mostrarlos en los resultados por nombre.  
  std::map<std::string, unsigned> nombres_estados_;
  void CrearMapNombresEstados(const std::string& linea_fichero);
  // Reservamos tantos espacios para estados como estados encontremos
  void ReservarEspaciosEstados(const std::string& linea_fichero);
  // Finalmente, un booleano para saber si trabajamos en modo traza o no
  bool modo_traza_;
  // Añaadimos un método para comprobar que el estado es válido
  void ComprobarEstadoValido(const std::string& nombre) const;
  // Método para comprobar si el símbolo de arranque de la pila pertenece al alfabeto de la pila
  void ComprobarSimboloArranquePila(const Simbolo& simbolo) const;
  // Método para añadir las transiciones a los estados, comprobando que los símbolos pertenecen a los alfabetos correspondientes y los estados son válidos.
  void AnadirTransiciones(const std::string& linea_fichero, unsigned transiciones_leidas);
  // Método para comprobar si una cadena es aceptada por el autómata utilizando la recursividad para examinar todos los caminos.  
  bool ExaminarCadenaRecursivo(const Cadena& cadena, unsigned inidice_estado, const Pila& pila, unsigned pos_cadena) const;
  // Método para mostrar la información de la traza
  void MostrarTraza(const Cadena& cadena, unsigned indice_cadena, unsigned indice_estado, const Pila& pila, const std::vector<Transicion>&) const;
}; 

#endif 