# PRÁCTICA 1: Implementación de Funciones Primitivas Recursivas

En esta práctica  implementaremos un programa que calcule la función potencia(x , y) como una función primitiva recursiva. Consecuentemente, solo podremos hacer uso de funciones primitivas recursivas (FPR) y de las operaciones permitidas. 
Por otro lado, debemos calcular el número de llamadas recursivas. ´

## Funciones Primitivas Recursivas

Para poder implementar la potencia(x, y), he hecho uso de una jerarquía de clases, donde todas heredan de la **clase base abstracta FuncionPrimitvaRecursiva**. En esta encontramos un método virtual Resolver, el cual recibirá un array de enteros, para que de esta manera no tener que sobreescribir la función ninguna vez. No obstante, **cada función primitiva recursiva, corroborará que el número de elementos recibidos es el correcto.** Por ejemplo, por definición la función nula es: z(x) = 0, por lo que la clase FuncionNula en su método resolver corroborará que el array recibido contiene obligatoriamente un solo elemento. 
Las clases hijas codificadas, podemos entenderlas como "dos grupos". 

### Funciones Recursivas Básicas

Se han implementado las tres funciones recursivas básicas como clases hijas. Por lo tanto, encontramos las clases: **FuncionNula, FuncionSucesor y FuncionProyeccion.** Todas estas corroborarán que se han invocado con los argumentos correctos, como ha sido mencionado anteriormente. En el caso de la función proyección, el índice y el tamaño se guardan como atributos privados. 
A partir de estas tres clases, se ha ido construyendo el resto del programa, ya que a partir de este conjunto de funciones se construyen funciones computables más complejas. 

### Funciones Primitivas Recursivas para el cálculo.

En este segundo grupo, encontramos las clases que han sido empleadas para realizar el propio cálculo de la potencia. **Para ello, he codificado las clases Suma, Producto y Potencia.** De esta manera, la clase Producto se ayudará de la clase Suma y la clase Potencia de la clase Producto. 

1. En primer lugar, he codificado la clase Suma. A la hora de resolver identificamos el case base, cuando finalmente y == 0. En este caso, **hacemos uso de la función proyección y devolvemos la x**. Sin embargo, en otro caso, haremos uso de la que en clase conocemos con la función hSuma. En esta, iremos guardando en un vector los resultados de la recursividad, decrementando en uno el valor de y. Finalmente, **devolvemos la composición de la función sucesor con la función proyección, sobre el tercer elemento del array (x, y - 1, suma(x, y - 1))**.  

2. En segundo lugar, encontramos la clase producto. El caso base, cuando y == 0, **usaremos la función nula para devolver un cero**. En caso contrario, hacemos uso de lo que para nosotros sería hProducto. Esto quiere decir que en primer lugar vamos guardando los resultados de la recursividad. A continuación, guardamos en otro vector el resultado de la combinación de la función proyección sobre el primer y tercer elemento de hProducto. Es decir, almacenamos la funciones proyección sobre la x y la función proyección sobre el resultado de la recursividad. **Finalmente, devolvemos la composición de la función suma con el resultado de la operación de combinación del primer y tercer elemento del vector (x, y - 1, producto(x, y - 1)).** 

3. En último lugar, la potencia. El caso base, cuando y == 0, **devolveremos la composición de la función sucesor con la función nula, pasando x como argumento. De esta manera, obtendremos un uno.** Debemos pasar el x como argumento por definición de la función nula, pues aunque siempre devuelva 0, su definición es z(x) = 0. En caso contrario, **simplemente debemos repetir el proceso del producto, pero en vez de devolver la composición de la función suma, devolvemos la composición de la función producto con el resultado de la operación de combinación del primer y tercer elemento del vector (x, y - 1, potencia(x, y  - 1))** 

## Número Llamadas recursivas 

Para calcular el número de llamadas recursivas, utilizamos un atributo privado y estático de la clase base (FuncionPrimitivaRecursiva). De esta manera, **cada vez que nos adentramos en la función Resolver de alguna de las clases suma, producto o potencia, incrementamos en uno dicho contador.**

## Operaciones 

Para poder hacer uso de las operaciones de las funciones primitivas básicas, he codificado la clase Composición y la clase Combinación, puesto que ambas operaciones son necesarias para implementar el programa. 

### Combinación 

La clase Combinacion contiene un atributo privado con los argumentos, pues en la operación de combinación devolveremos un array de Funciones Primitivas Recursivas, donde ambas funciones tienen que ser llamadas con los mismos argumentos.  Consecuentemente, a la hora de resolver **recibiremos por parámetros dos Funciones Primitivas Recursivas y devolveremos un array con ambas, donde las dos serán llamadas con los mismos argumentos definidos en el constructor de la clase Combinacion.**

### Composición 

La clase Composición, al igual que la combinación, contiene un argumento privado con los argumentos. Consecuentemente, a la hora de resolver **recibiremos una Función Primitiva Recursiva y un array de Funciones Primitivas Recursivas. Iremos guardando en un vector los resultados de las funciones recibidas por parámetro en el array, llamando a todas ellas con los argumentos definidos en el constructor de la clase Combinacion. Finalmente, devolveremos el valor de llamar a la función recibida como primer parámetro con todos los resultados de las funciones recibidas en el array como segundo parámetro.** 

## Diagrama UML

Finalmente, debido a que no puedo estar presencialmente en la entrega de la práctica, adjunto también un diagrama UML con la jerarquía de clases, para de esta manera intentar clarificarle mi programa lo máximo posible. 