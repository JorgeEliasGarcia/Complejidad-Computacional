/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief funcion_proyección.h: Clase para la implementación de la función de proyección.
  @bug No hay bug conocidos 

*/

#include "funcion_proyeccion.h"

// Método para resolver la función de proyección.
int FuncionProyeccion::Resolver(std::vector<int> argumentos) {
  if (argumentos.size() != unsigned(tamanyo_)) { // Comprobamos que el número de argumentos sea el correcto.
    std::cerr << "Error: el número de argumentos no coincide con el tamaño del vector." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (indice_ < 0 || indice_ >= tamanyo_) {
    std::cerr << "Error: El índice está fuera de rango." << std::endl;
    exit(EXIT_SUCCESS);
  }
  return argumentos[indice_];
}