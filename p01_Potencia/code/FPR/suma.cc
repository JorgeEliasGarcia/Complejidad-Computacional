/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief suma.h: Clase para la implementación de la función suma.
  @bug No hay bug conocidos 

*/

#include "suma.h"

// Método para resolver la función suma, usando funciones recursivas primitivas.
int Suma::Resolver(std::vector<int> args) {
  if (args.size() != 2) { // Comprobamos que la función suma solo admite dos argumentos.
    std::cerr << "Error: la función suma solo admite dos argumentos." << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva::IncrementarNumeroLlamadasFuncion(); // Incrementamos el número de llamadas a funciones
  int primer_operando = args[0];
  int segundo_operando = args[1];
  // Identificamos el caso base
  if (segundo_operando == 0) {
    return FuncionProyeccion(0, 1).Resolver({primer_operando}); // Utilizamos la función proyección para devolver el primer operando.
  } else {  // En este caso, entramos en la recursividad
    const std::vector<int> kHSuma = {primer_operando, segundo_operando - 1, Resolver({primer_operando, segundo_operando - 1})}; 
    // Devolvemos la composición de la función sucesor con la función proyección indice 2 y tamaño. Los argumentos para ejecutar la proyección será kHSuma. 
    return Composicion(kHSuma).Resolver(new FuncionSucesor(), {new FuncionProyeccion(2, 3)}); // Llamada recursiva
  }
}