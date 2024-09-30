/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Complejidad Computacional
  Curso: 4º
  Práctica 1: Implementación de Funciones Primitivas Recursivas
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @brief prodcuto.cc: Clase para la implementación de la función producto.
  @bug No hay bug conocidos 

*/

#include "producto.h"

// Método para resolver la función producto, usando funciones recursivas primitivas.
int Producto::Resolver(std::vector<int> args) {
  if (args.size() != 2) { // Comprobamos que la función producto solo admite dos argumentos.
    std::cerr << "Error: la función suma solo admite dos argumentos." << std::endl;
    exit(EXIT_SUCCESS);
  }
  FuncionPrimitivaRecursiva::IncrementarLlamadasRecursivas(); // Incrementamos el número de llamadas recursivas
  int primer_operando = args[0];
  int segundo_operando = args[1];
  // Identificamos el caso base
  if (segundo_operando == 0) {
    return FuncionNula().Resolver({primer_operando});  // Utilizamos la función nula para devolver el cero. 
  } else {  // En este caso, entramos en la recursividad
    const std::vector<int> kHProducto = {primer_operando, segundo_operando - 1, Resolver({primer_operando, segundo_operando - 1})}; 
    // Necesitamos almacenar el resultado de la combinación de las proyecciones. Los argumentos para ejecutar la proyección será kHProducto. La coombinación nos devolverá las funciones primitivas recursivas metidas en el mismo array.
    std::vector<FuncionPrimitivaRecursiva*> resultado_combinacion = Combinacion(kHProducto).Resolver(new FuncionProyeccion(0, 3), new FuncionProyeccion(2, 3));
    // Finalmente, devolvemos la composición de la función suma con el resultado de la combinación. Los argumentos para ejecutar la suma será kHProducto.
    return Composicion(kHProducto).Resolver(new Suma(), resultado_combinacion); // Llamada recursiva
  }
}