/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.cc: Programa cliente para el cálculo de la potencia, usando funciones primitivas recursivas.
  @bug No hay bug conocidos 

*/

#include "main.h"
#include "FPR/funcion_primitiva_recursiva.h"
#include "FPR/suma.h"
#include "FPR/funcion_nula.h"

// FUnción principal del programa
int main(int argc, char *argv[]) {
  ModoUso(argc, argv);
  int base = std::stoi(argv[1]);
  int exponente = std::stoi(argv[2]);
  FuncionPrimitivaRecursiva* fpr = new FuncionProyeccion(2, 3);
  std::vector<int> argumentos = {1, 2, 3, 4};
  int resultado = fpr->Resolver(argumentos);
  std::cout << "El resultado es: " << resultado << std::endl;
  fpr = new FuncionSucesor();
  resultado = fpr->Resolver(argumentos);
  std::cout << "El resultado es: " << resultado << std::endl;
  fpr = new FuncionNula();
  resultado = fpr->Resolver(argumentos);
  std::cout << "El resultado es: " << resultado << std::endl;
  return 0;
}