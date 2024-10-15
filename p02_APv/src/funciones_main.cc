/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Diseño y Análisis de Algoritmos
  Curso: 3º
  Pr ́actica 1: Complejidad Computacional
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.cc: Definción de las funciones utilazadas como ayuda para el main.cc
  @bug No hay bug conocidos 

*/

#include "main.h"

// Función para asegurarse de que el número de argumentos es correcto
void ModoUso(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Error: El programa necesita dos argumentos para funcionar correctamente." << std::endl;
    std::cerr << "Uso: " << argv[0] << " <nombre_fichero> <modo_traza>" << std::endl;
    std::cerr << "Para activar el modo traza, introduzca un 1. En caso contrario, introduzca cualquier otro caracter" << std::endl;
    exit(EXIT_SUCCESS); 
  }
}