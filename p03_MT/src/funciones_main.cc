/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Diseño y Análisis de Algoritmos
  Curso: 3º
  Pr ́actica 3: Complejidad Computacional
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.cc: Definción de las funciones utilazadas como ayuda para el main.cc
  @bug No hay bug conocidos 

*/

#include "main.h"

// Función para asegurarse de que el número de argumentos es correcto
void ModoUso(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: El programa necesita un solo argumento para funcionar correctamente." << std::endl;
    std::cerr << "Uso: " << argv[0] << " <nombre_fichero>" << std::endl;
    exit(EXIT_SUCCESS); 
  }
}
