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
#include "FPR/potencia.h"

// FUnción principal del programa
int main(int argc, char *argv[]) {
  ModoUso(argc, argv);
  int base = std::stoi(argv[1]);
  int exponente = std::stoi(argv[2]);
  if (base < 0 || exponente < 0) { // Hacemos la comprobación de que ambos son números naturales.
    std::cerr << "Error: Los números deben ser naturales" << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva* potencia = new Potencia();
  int resultado = potencia->Resolver({base, exponente});
  std::cout << "El resultado de elevar " << base << " a " << exponente << " es: " << resultado << std::endl;
  std::cout << "Número de llamadas a funciones realizadas: " << potencia->GetNumeroLlamadasFuncion() << std::endl;
}