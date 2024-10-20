/**
  Universidad de La Laguna
  Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
  Grado en Ingenier ́ıa Inform ́atica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Práctica 6: Lenguajes regulares
  @autor: Jorge Elías García
  @correo: alu0101472294@ull.es
  @fecha: 1/11/2022
  @brief  automata.cc Contiene la declaración de la clase automata.

  @bug No hay bug conocidos

*/

#include "automata.h"

// Constructor de la clase. Leeremos desde el fichero de entrada los datos necesarios para crear el autómata
Automata::Automata(const std::string& nombre_fichero, bool modo_traza) {
  modo_traza_ = modo_traza;
  // Leemos el fichero y según la línea en la que estemos, guardamos los datos en las variables correspondientes. Las líneas que comienzan por #, serán omitidas.
  std::ifstream fichero(nombre_fichero);
  if (!fichero) {
    std::cerr << "Error: No se ha podido abrir el fichero de entrada" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string linea;
  unsigned linea_actual{0}; 
  unsigned transiciones_leidas{0};
  while (std::getline(fichero, linea)) {
    if (linea[0] == '#') {
      continue;
    }
    switch(linea_actual) {
      case 0: 
        CrearMapNombresEstados(linea);
        ReservarEspaciosEstados(linea);
        break;
      case 1: 
        alfabeto_.IncluirSimbolos(linea);
        break; 
      case 2: 
        alfabeto_pila_.IncluirSimbolos(linea);
        break;
      case 3: // Determinamos cual será el estado inicial, a partir del nombre y usando el HASH
        ComprobarEstadoValido(linea); // Comprobamos que s ∈ Q.
        estado_inicial_ = nombres_estados_[linea];
        break;
      case 4: 
        ComprobarSimboloArranquePila(Simbolo(linea[0]));
        pila_.AnadirSimbolo(Simbolo(linea[0]));
        break;
      case 5: // Leemos todas transiciones
        do {
          AnadirTransiciones(linea, transiciones_leidas);
          ++transiciones_leidas;
        } while (std::getline(fichero, linea)); 
        break; 

      default: 
        break;
    }
    linea_actual++;
  } 
}; 

// Método para comprobar si una cadena es aceptada por el autómata. 
bool Automata::CadenaPerteneceAlLenguaje(const Cadena& cadena) const {
  Pila pila_aux(pila_); // Creamos una copia de la pila, con el símbolo de arranque
  return ExaminarCadenaRecursivo(cadena, estado_inicial_, pila_aux, 0);
}

// Método privado y recursivo para examinar si la cadena pertenece al lenguaje. Usaremos la recursividad para examinar todos los caminos posibles.
bool Automata::ExaminarCadenaRecursivo(const Cadena& cadena, unsigned indice_estado, const Pila& pila, unsigned pos_cadena) const {
  const Simbolo kEpsilon('.'); // Definimos la constante epsilon
  // Determinamos el símbolo actual de la pila y de la cadena
  const Simbolo kSimboloActual = (cadena.EsCadenaVacia()) ? kEpsilon : cadena.ObtenerSimbolo(pos_cadena);
  const Simbolo kSimboloPilaActual = (pila.Vacia()) ? kEpsilon : pila.GetCima(); 
  // Determinamos todas las transiciones posibles desde el estado actual
  std::vector<Transicion> transiciones = estados_[indice_estado].TransicionesValidas(kSimboloActual, kSimboloPilaActual);
  // Estudiamos si estamos en modo traza
  if (modo_traza_) {
    MostrarTraza(cadena, pos_cadena, indice_estado, pila, transiciones);
  }
  if (pos_cadena == cadena.NumeroSimbolos() && pila.Vacia()) { // Caso Base. Hemos recorrido toda la cadena y la pila está vacía --> Cadena aceptada
    return true;  
  }
  // Recorremos todas las transiciones posibles y llamamos recursivamente a la función, para así examinar todos los caminos posibles.
  for (const auto& transicion : transiciones) {
    // Creamos una nueva pila, para poder recordar como estaba la pila antes de realizar la transición, por si tenemos que deshacer el camino. 
    Pila pila_nueva(pila);
    pila_nueva.ActualizarPila(transicion.GetNuevosSimbolosPila());
    // Avanzamos en la posición de la cadena, siempre y cuando el símbolo utilizado por la transición no haya sido epsilon
    unsigned nueva_pos_cadena = (transicion.GetSimboloNecesario() == kEpsilon) ? pos_cadena : pos_cadena + 1;
    // Llamamos recursivamente a la función
    if (ExaminarCadenaRecursivo(cadena, transicion.GetEstadoDestino(), pila_nueva, nueva_pos_cadena)) {
      return true; 
    }
  }

  return false; // No hemos encontrado ningún camino posible. 
}

// Método para mostrar la información de la traza
void Automata::MostrarTraza(const Cadena& cadena, unsigned indice_cadena, unsigned indice_estado, const Pila& pila, const std::vector<Transicion>& transiciones) const {
  std::cout <<  "Estado: " << estados_[indice_estado].GetNombre() << std::endl;
  std::cout << "Cadena: " << cadena.Subcadena(indice_cadena) << std::endl;
  std::cout << "Pila: " << pila << std::endl;
  std::cout << "Transiciones posibles: "; 
  for (const Transicion& transicion : transiciones) {
    std::cout << transicion.GetId() + 1 << " ";
  }

  std::cout << std::endl << "-----------------------------------------------------" << std::endl << std::endl;
}

// Método para añadir las transiciones a los estados, comprobando que los símbolos pertenecen a los alfabetos correspondientes y los estados son válidos.
void Automata::AnadirTransiciones(const std::string& linea_fichero, unsigned transiciones_leidas) {
  const char kEpsilon('.'); 
  std::istringstream datos(linea_fichero);
  std::string nombre_estado; // Identificamos en qué estado estamos
  datos >> nombre_estado;
  ComprobarEstadoValido(nombre_estado);
  unsigned indice_estado = nombres_estados_[nombre_estado];
  std::string simbolo_necesario; // Símbolo de entrada
  datos >> simbolo_necesario;
  if (!alfabeto_.Pertenece(simbolo_necesario[0]) && simbolo_necesario[0] != kEpsilon) {
    std::cerr << "Error: El símbolo " + simbolo_necesario +  " no pertenece al alfabeto" << std::endl;
    exit(EXIT_SUCCESS);
  }
  Simbolo simbolo_necesario_obj(simbolo_necesario[0]);
  std::string simbolo_pila;
  datos >> simbolo_pila;
  if (!alfabeto_pila_.Pertenece(simbolo_pila[0]) && simbolo_pila[0] != kEpsilon) {
    std::cerr << "Error: El símbolo " + simbolo_pila +  " no pertenece al alfabeto de la pila" << std::endl;
    exit(EXIT_SUCCESS);
  }
  Simbolo simbolo_pila_obj(simbolo_pila[0]);
  std::string nombre_estado_destino;
  datos >> nombre_estado_destino;
  ComprobarEstadoValido(nombre_estado_destino);
  unsigned indice_estado_destino = nombres_estados_[nombre_estado_destino];
  std::string simbolos_pila_nuevo;
  datos >> simbolos_pila_nuevo;
  std::vector<Simbolo> simbolos_pila_nuevo_obj;
  for (const char& char_simbolo : simbolos_pila_nuevo) {
    Simbolo simbolo(char_simbolo); 
    if (!alfabeto_pila_.Pertenece(simbolo) && simbolo.GetSimbolo() != kEpsilon) {
      std::string simbolo_incorrecto(1, simbolo.GetSimbolo()); 
      std::cerr << "Error: El símbolo " + simbolo_incorrecto +  " no pertenece al alfabeto de la pila" << std::endl;
      exit(EXIT_SUCCESS);
    }
    simbolos_pila_nuevo_obj.push_back(Simbolo(simbolo));
  }
  // Añadimos la transición al estado correspondiente
  estados_[indice_estado].AnadirTransicion(Transicion(simbolo_necesario_obj, simbolo_pila_obj, indice_estado_destino, simbolos_pila_nuevo_obj, transiciones_leidas));
  estados_[indice_estado].SetNombre(nombre_estado);
}

// Método para comprobar que el estado es válido
void Automata::ComprobarEstadoValido(const std::string& nombre) const {
  if (nombres_estados_.find(nombre) == nombres_estados_.end()) {
    std::cerr << "Error: El estado " + nombre +  " no pertenece al conjunto de estados" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

// Método para comprobar si el símbolo de arranque de la pila pertenece al alfabeto de la pila
void Automata::ComprobarSimboloArranquePila(const Simbolo& simbolo) const {
  if (!alfabeto_pila_.Pertenece(simbolo)) {
    std::cerr << "Error: El símbolo de arranque de la pila no pertenece al alfabeto de la pila" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

// Método para crear un map con los nombres de los estados. Así trabajaremos con los estados por índices, pero podremos mostrarlos por nombre. 
void Automata::CrearMapNombresEstados(const std::string& linea_fichero) {
  std::istringstream stream(linea_fichero);
  std::string nombre_estado;
  unsigned indice_estado{0};
  while (stream >> nombre_estado) {
    nombres_estados_[nombre_estado] = indice_estado;
    indice_estado++;
  }
}

// Método para reservar tantos espacios para estados como estados encontremos
void Automata::ReservarEspaciosEstados(const std::string& linea_fichero) {
  std::istringstream stream(linea_fichero);
  std::string nombre_estado;
  unsigned contador{0};
  while (stream >> nombre_estado) {
    ++contador;
  }
  estados_.resize(contador);
}