/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief potencia.h: Clase para la implementación de la función potencia. 
  @bug No hay bug conocidos 

*/

#include "potencia.h"

// Método para resolver la función potencia, usando funciones recursivas primitivas.
int Potencia::Resolver(std::vector<int> args) {
  if (args.size() != 2) { // Comprobamos que la función potencia solo admite dos argumentos.
    std::cerr << "Error: la función potencia solo admite dos argumentos." << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva::IncrementarLlamadasRecursivas(); // Incrementamos el número de llamadas recursivas
  int base = args[0];
  int exponente = args[1];
  // Identificamos el caso base
  if (exponente == 0) { // En este caso devolvemos una composición entre la función sucesor y la nula, para obtener un 1. 
    return Composicion({base}).Resolver(new FuncionSucesor(), {new FuncionNula()});
  } else {  // En este caso, entramos en la recursividad
    const std::vector<int> kHPotencia = {base, exponente - 1, Resolver({base, exponente - 1})}; 
    // Necesitamos almacenar el resultado de la combinación de las proyecciones. Los argumentos para ejecutar la proyección será kHPotencia. La coombinación nos devolverá las funciones primitivas recursivas metidas en el mismo array.
    std::vector<FuncionPrimitivaRecursiva*> resultado_combinacion = Combinacion(kHPotencia).Resolver(new FuncionProyeccion(0, 3), new FuncionProyeccion(2, 3));
    // Finalmente, devolvemos la composición de la función producto con el resultado de la combinación. Los argumentos para ejecutar la suma será kHPotencia.
    return Composicion(kHPotencia).Resolver(new Producto(), resultado_combinacion); // Llamada recursiva
  }
}