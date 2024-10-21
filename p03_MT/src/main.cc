/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 3: Implementación de Máquina de Turing
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.cc: Programa cliente para implementar una máquina de Turing	
  @bug No hay bug conocidos 

*/

#include "main.h"
#include "MT/cinta.h"

int main(int argc, char* argv[]) { 
  ModoUso(argc, argv); 
  // Leemos el nombre del fichero y el modo traza 
  const std::string nombre_fichero = argv[1];
  // Creamos la máquina de Turing
  Cinta cinta('B');
  cinta.CopiarCadena(Cadena("0101"));
  cinta.MostrarCinta();
  // Actualizamos para probar el movimiento a la derecha
  cinta.ActualizarCinta(Simbolo('P'), 'R');
  cinta.ActualizarCinta(Simbolo('E'), 'R');
  cinta.MostrarCinta();

  return 0; 
}