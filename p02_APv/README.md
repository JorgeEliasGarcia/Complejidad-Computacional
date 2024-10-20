# PRÁCTICA 2: Simulador de un autómata con pila

Para esta práctica, se implementará un simulador de un automáta con pila, concretamente **por vaciado de pila (APv)**. 

## Compilación y Ejecución del Programa

Para compilar el programa, simplemente nos adentramos en el directorio src y hacemos ***make***. 
Para ejecutar el programa, haremos: ./automata <fichero> <modo_traza>. Para ello, los ficheros se encuentran el directorio test. Por otro lado, respecto al modo traza, en caso de poner un 1, se ejecutará en dicho modo. En caso de poner cualquier otro caracter, no se entrará en el modo traza. 

## Automáta

Para poder implementar el automata por vaciado de pila, se ha codificado, entre otras muchas, la clase Automata. Esta clase nos permitirá definir un automata y, posteriormente, examinar cadenas y comprobar si pertenecen al lenguaje reconocido por el automata o no. 

### Atributos

Al igual que sucede en la teoría, nuestro automata tiene como atributos privados: Un alfabeto, un conjunto de estados, el alfabeto de la pila, una pila (con un símbolo inicial) y un estado inicial. 
Por otro lado, también hará uso de la clase Cadena, ya que recibirá objetos de esta clase, para examinar si las cadenas del usuario pertenecen al lenguaje reconocido por el automata o no. Asimismo, también utilizará la clase Transicion, para poder identificar que cambios realizar en cada iteración. 

### Comprobaciones

Por otro lado, previo a examinar las cadenas, se hacen todas **las comprobaciones pertinentes**. Consecuentemente, se comprueba que el estado inicial pertenece al conjunto de estados, que el símbolo inicial de la pila pertenece al alfabeto de la pila, y que todas las transiciones definidas son correctas. Esto quiere decir, que todos los símbolos pertencen al alfabeto (diferenciando cuando tenemos que comprobar el alfabeto de la entrada del de la pila, claro), todos los estados pertenecen al conjunto de estados definidos al inicio del fichero y, finalmente, que las transiciones tienen el formato definido. 

### Examinar Cadenas

Para poder examinar las cadenas, utilizaremos un **método recursivo (backtracking)**, ya que tendremos que comprobar todos los caminos y todas las transiciones posibles, hasta identificar si la cadena pertenece al lenguaje reconocido por el automata o no. Consecuentemente, al codificarlo de esta manera, en caso de habernos adentrado por un camino y después tener que rectificar, se podrá hacer sin problema. 

El procedimiento para examinar las cadenas ha sido el siguiente: 

En primer lugar, encontramos el caso base, el cual nos dice que si hemos recorrido toda la cadena y la pila está vacía, la cadena pertenece al lenguaje reconocido por el automata. Por lo tanto, retornamos true. 

En segundo lugar, encontramos el caso recursivo. Por lo tanto, identificamos todas las transiciones posibles, atendiendo al estado actual, al símbolo actual de la cadena y al símbolo en la cima de la pila. A continuación, recorremos todas las transiciones y llamamos recursivamente a la función, para así examinar todos los caminos posibles. Para cada transición, creamos una nueva pila (partiendo de la pila actual) y la actualizamos, eliminando el símbolo que se encuentre en la cima y añadiendo los símbolos que nos inidique la transición. Posteriormente, actualizamos el ínidice de la cadena (damos como leído dicho símbolo) y llamamos recursivamente a la función, pasando como argumentos: La cadena actualizada (cadena original y el ínidice donde nos encontramos), el estado destino y la nueva pila. Consecuentemente, al adentrarnos en esta llamda, habremos realizado correctamente la transición, ya que nos encontraremos en el estado destino, con el símbolo de la cadena y la pila actualizadas correctamente. 

### Modo traza

Asimismo, encontramos la opción de ejecutar el programa en modo traza. En este modo, para cada iteración mostramos el estado actual, la cadena (los símbolos que hayan sido leidos, no se mostrarán, por lo que vamos mostrando "subcadenas"), la pila y todas las transiciones posibles. Para mostrar las transiciones, **a cada una se le ha asignado un ID**, el cual corresponde al orden en el que fueron definidas. Es decir, la primera transición definida será el ID 1 y así sucesivamente. 

## Estructura de Clases

Una vez definido como funciona el programa, identificamos que clases han sido codificadas y que relaciones tienen entre sí. 

### Simbolo

Esta clase nos permitirá identificar un simbolo, ya sea para la pila o para la cadena. Un simbolo únicamente será un caracter, por lo que simplemente tendrá como atributo privado un char. Asimismo, en relación a sus métodos, encontramos el getter y la sobrecarga del operador de flujo de salida. 

### Cadena

Una cadena será un conjunto de símbolos, consecuentemente, **un vector de símbolos**. Asimismo, tendrá otros métodos como EsCadenaVacia(), para poder identificar si se trata de epsilon o no. Para ello, simplemente comprobamos si el vector está vacío o no. 

### Alfabeto  

Un alfabeto, será un conjunto de símbolos, por lo tanto será **un vector de símbolos**. Esta clase nos permitirá almacenar todos los simbolos, para **poder comprobar si los símbolos definidos en las transiciones pertencen a los alfabetos correspondientes** o no. 

### Transicion

Una transicion nos permitirá identificar, **dado el simbolo actual de la cadena, el simbolo de la cima de la pila y el estado actual, cual será nuestro estado destino y que conjunto de símbolos debemos añadir a la pila**. Consecuentemente, será necesaria para poder examinar correctamente las cadenas, ya que nos permite realizar los movimientos que han sido definidos por el automata. 

### Estado

Un estado, será **un conjunto de transiciones**. Consecuentemente, cada estado únicamente almacenará sus transiciones y podremos utilizar el método TransicionesValidas(), el cual recibiendo el símbolo actual de la cadena y el símbolo actual en la cima de la pila, nos devolverá **todas las transiciones aplicables**, dado el estado actual del automata. 

### Pila

Finalmente, una pila será **un conjunto de símbolos**. Esta clase, simplemente simulará el uso de una pila, pero añadimos el método ActualizarPila(), el cual recibirá un vector de símbolos. En este método, eliminamos el símbolo que se encuentre en la cima y vamos añadiendo cada uno de los símbolos recibidos en el orden correcto. En caso de que el símbolo a añadir sea epsilon, simplemente no añadimos nada.  