/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Diseño y Análisis de Algoritmos
  Curso: 3º
  Pr ́actica 1: Complejidad Computacional
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief main.h: Declaración de las funciones utilazadas como ayuda para el main.cc
  @bug No hay bug conocidos 

*/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "apv/automata.h"
#include "apv/cadena.h"

// Función para asegurarse de que el número de argumentos es correcto
void ModoUso(int argc, char *argv[]);

// Función para ir examinando cadenas
void ExaminarCadenas(const Automata& automata);

#endif 
