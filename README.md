# CI4721_LenguajesII

# Eulang

_Eulang es como agarrar python pero con c++, 1% de probabilidades, 99% de fe_

## Declaraciones
```
let <tipo_de_dato> <nombre_variable>;  
o  
let <tipo_de_dato> <nombre_variable> = <valor>;
```

## Bloque
Permite secuenciar un conjunto de instrucciones y declarar variables locales. Puede usarse en cualquier
lugar donde se requiera una instruccion. Su sintaxis es:  
```
{
	instrucciones
}
```

## Tipos de datos

### Primitivos

* char: representa un caracter ASCII de 8 bits.  
	```
	let char mander;  
	let char mander = 'o';
	```

* int: representa un número entero con signo de 32 bits complemento a 2.  
	```
	let int eligente;  
	let int eligente = 42;
	```

* bool: representan un valor booleano, es decir, true o false.  
	```
	let bool basor;  
	let bool basor = true;
	```

* float: representa un número decimal de 32 bits, cumple con IEEE 754-2019.  
	```
	let float ante;  
    let float ante = 3.1416;
	```

### Compuestos

* tipo[N]: representa un arreglo de tamaño N, con n siendo un entero positivo, del tipo referenciado por el tipo declarado antes.  
	```
	let int[n] intArray1;  
	let int[1] intArray;
	let int[3] intArray3 = [1,2,3];
	```

* str: representa una cadena de caracteres.  
	```
	let str string1 = "Hello";
	let str string1;
	```

* struct: representa un conjunto de datos agrupados bajo un mismo nombre.   
	```
 	struct ura {
		let int numero;
		let str texto;
	}

	let ura structura1;
	structura1.numero = 10;
	structura1.texto = "diez";
	```

* union: representa un tipo de dato especial que contiene una serie de datos que comparten un espacio de memoria, pero solo se puede almacenar uno de estos valores. La estructura internamente guarda el ultimo valor asignado como "activo".
	```
	union europea {
		let int number;
		let str text;
	}

	let europea unioneuropea1;
	unioneuropea1.text = "diez";
	unioneuropea1.number = 10;
	print(unioneuropea1.text); //Error text no esta activo
	let str hola = "hola" + unioneuropea1.numero; // Error de tipo str + int
	let str hola = "hola" + itostr(unioneuropea1.numero); // Fino
	```

* tipo ~: representa una direccion de memoria del heap. Solo se puede desreferenciar con el operador &.
	```
	let <tipo> ~ <nombre_var> = new <tipo>;
	&var = 5;
	let type variable = &var;
	vengeance var; // Libera el espacio de memoria
	```

## Selección
```
if( condicional ) {
	// Hacer
} elif( condicional ) {
	// Algo
} else {
	// O no...
}
```

## Repetición
* Definida: disponible para array, str, list. Se crea una copia de la estructura a iterar, y se itera sobre la misma. Lo cual permite que se puedan hacer modificaciones sobre la estructura original.
	```
	let int[3] a = [1,2,3];
	for (elem in a) {
		// hacer algo tamano de a veces
	}

	for (elem in [1...3]) {
		// hacer algo tamano del rango veces
	}

	let list[int] b = [1,2,3,4,5];
	for (elem in b) {
		if (elem % 2 != 0){
			push(b, elem);
		}
	}
	print(ltostr(b)); // [2,4]
	```
* Indefinida:  
	```
	while( condicional ) {
		// hacer algo hasta que el condicional no se cumpla
	}
	```

## Comentarios
* Una linea:  
	```
	//esto es un comentario
	```
* Multilinea: 
	```
	/*  Este
		comentario
		tiene
		muchas
		lineas */
	```

## Funciones
Las funciones solamente retornan tipos primitivos.  
Las funciones reciben cualquier tipo como argumento, por valor o por referencia.
```
func <nombre_func>(<tipo> <nombre_argumento>, ...)::<tipo_retorno> { 
	// hacer algo
	return <tipo_retorno>
}

// Normal
func fact(int numero)::int {
	fact_aux(numero-1, 0);
}

func fact_aux(int numero, int count)::int {
	if(numero == 0){
		return count;
	}
	return fact_aux(numero-1, numero*count);
}

// De cola
func fact(int n)::int {
  return tail_fact(n,1);
}

func tail_fact(int n, int a)::int {
  if (n == 0)
    return a;
  else
    return tail_fact(n-1,n*a);
}
``` 
## Procedimientos
Los procedimientos reciben cualquier tipo como argumento, por valor o por referencia.
``` 
proc <nombre_proc>(<tipo> <nombre_argumento>, ...) {
	// Yo no retorno nada yeih
}
``` 

## Paso por valor o por referencia:
Por valor por defecto.
Para pasar por referencia se usa ```<tipo> ^ <nombre>```. Ejemplo:  
```
let int hola = 1;
let int adios = 1;

func dummy(int ^ a, int b)::int {
	a++;
	b++;
	return a+b;
}

print(itostr(hola));  //1
print(itostr(adios)); //1
print(itostr(dummy(hola,adios))); //4
print(itostr(hola)); //2
print(itostr(adios)); //1
```

## Arreglos dinamicos:
list: representa un arreglo de tamaño variable, de datos de un tipo primitivo homogeneo.
```
list[<tipo>] <nombre_variable>

let list[int] myList;
let list[int] myList = [1,2,3,4];
```

## Operaciones sobre tipos de datos:

### Aritméticos
	int + int -> int;
	int - int -> int;
	int * int -> int;
	int / int -> int;
	int % int = float; // modulo
	int ** int -> int; // exponenciacion

	float || int +  float = float;
	float || int -  float = float;
	float || int *  float = float;
	float || int /  float = float;
	float || int %  float = float; // modulo
	float || int ** float = float; // exponenciacion

### Booleanos
* !: para bool, si el valor pasado es true retorna false, y viceversa.  
	```
	!true => false;  
	!false => true;
	``` 

* ||: para bool, or logico.  
	```
	true  || false => true;  
	true  || true  => true;  
	false || true  => true;  
	false || false => false;  
	``` 
* &&: para bool, and logico.  
	```
	true  && false => false;  
	true  && true  => true;  
	false && true  => false;  
	false && false => false;  
	``` 

### Relaciones
Operadores binarios que retornan un bool.


* ==: para los tipos primitivos se verifica si tienen el mismo valor. En caso afirmativo retorna true, en caso contrario false.
	``` 
	int == int -> bool;
	float == float -> bool;
	bool == bool -> bool;
	char == char -> char;
	``` 

* !=: para los tipos primitivos funciona como no igual.
	``` 
	int != int -> bool;
	float != float -> bool;
	bool != bool -> bool;
	char != char -> bool;
	``` 

* \>: para int, float, funcionamiento: si el de la derecha tiene un valor mayor que el de la izquierda, retorna true. En caso contrario retorna false.
	``` 
	int > int -> bool;
	float > float  -> bool;
	``` 

* \<: para int, float, funcionamiento: si el de la izquierda tiene un valor mayor que el de la derecha, retorna true. En caso contrario retorna false.
	``` 
	int > int -> bool;
	float > float  -> bool;
	``` 

* \>=: para int, float, funcionamiento: si el de la derecha tiene un valor mayor que el de la izquierda o son iguales, retorna true. En caso contrario retorna false. Azucar sintactico de: var == var || var > var
	``` 
	int >= int -> bool;
	float >= float  -> bool;
	``` 

* \<=: para int, float, funcionamiento: si el de la izquierda tiene un valor mayor que el de la derecha o son iguales, retorna true. En caso contrario retorna false. Azucar sintactico de: var == var || var < var
	``` 
	int <= int -> bool;
	float <= float  -> bool;
	```

* char:
	```
	str o char + str o char -> str  // concatena creando un nuevo str.
	ctoint('a') => 97 // convierte un char en su int ASCII asociado.  
	itochar(97) => 'a' // convierte un int en su char ASCII asociado.
	```

* int: 
	```
	itostr(int) -> string; // convierte el int en str
	```

* float: 
	```
	floor(float)   -> int; // trunca el decimal, convirtiendolo en su parte entera. 

	ceil(float)    -> int; // aplica floor() al float y le suma 1, resultando en el int superior mas cercano.  

	decimal(float) -> float; // aplica float - floor(float).  

	round(float)   -> int; // aplica floor(), si el resultado de decimal() es menor 0.5, ceil() en caso contrario, resultando en un int.  

	ftostr(float) -> string; //convierte el float en str
	```

* arreglos:
	```
	<nombre_arreglo>[<entero>] => indexacion retorna el elemento del arreglo en la posicion indicada.  

	array1 + array2 => array3; //se crea un nuevo arreglo colocando en las primeras n posiciones los n elementos del primer arreglo, y en las m posiciones siguientes los m elementos del segundo arreglo, resultando en un arreglo de n+m elementos.  

	lena(array) -> int; // retorna el numero de elementos del arreglo.  

	<nombre_arreglo>[-1] <==> <nombre_arreglo>[lena(<nombre_arreglo>) - 1]; //azucar sintactica para indexar el arreglo como si fuese circular.  

	<nombre_arreglo>[0...1] <==> <nombre_arreglo>[0]; //retorna el conjunto de elementos indexados en el rango especificado. El rango es inclusivo del lado izquierdo pero no del lado derecho.  

	let int[2] array= [10,11];
	atostr(array) <==> "[" + itostr(10) + "," + itostr(11) + "]" // Visto por debajo [ '[' , '1' , '0' , ',' , '1' , '1' , ']' ]
	```

* str: arreglos de caracteres.
	```
	<nombre_str>[<entero>] => caracter en la posicion del entero;  //analogo al array. 

	str + str -> str;  //analogo al array.

	lens(str) -> int;  //analogo al array.

	<nombre_str>[-1] <==> <nombre_str>[lens(<nombre_str>) - 1];  //analogo al array

	<nombre_str>[0...1] <==> <nombre_str>[0];  //analogo al array

	split(<nombre_str>, <str_separador>) -> str[]; //Divide el string por el separador dado y el resultado lo almacena en un arreglo de strings.

	str == str -> bool  //comparacion caracter por caracter, solo se pueden comparar str del mismo tamano.

	str != str -> bool  // ! (str == str)

	stoint(<nombre_str>) -> int // verifica que solo existan caracteres [0-9], y luego arma el entero.

	stofloat(<nombre_str>) -> float  // verifica que solo existan caracteres [0-9] separados por un unico '.', y luego arma el float.
	```

* list: lista doblemente enlazada. Funciona como una arreglo dinamico.
	```
	<nombre_lista>[<entero>] -> elemento de la lista en la posicion dada //analogo al array.  

	list + list -> list //analogo al array.  

	lenl(<nombre_lista>) -> int; //analogo al array.  

	<nombre_lista>[-1] == <nombre_lista>[lenl(<nombre_lista>) - 1]; //analogo al array. 

	<nombre_lista>[0...1] <==> <nombre_lista>[0]; //analogo al array.

	pop(<nombre_lista>, <entero>) //elimina el elemento en el indice indicado, y lo retorna.  

	push(<nombre_lista>, <elemento>) //agrega el elemento especificado al final de la lista.  

	insert(<nombre_lista>, <entero>, <elemento>) //agrega el elemento especificado en el indice indicado.  

	find(<nombre_lista>, <elemento>) -> int  //busca un elemento en la lista y si se encuentra retorna el indice del primer elemento que encuentre. Si no error.

	reversed(<nombre_lista>)  //devuelve la lista invertida

	remove(<nombre_lista>, <elemento>) //elimina todas las ocurrencias de un elemento de la lista.  

	ltostr(<nombre_lista>) -> string //analogo al array
	```

## I/O:

* print(): instruccion que imprime en pantalla el string que se pase como argumento.
	```
	print(string); //like python
	print(<tipo> + <tipo>);
	```

* input(): instruccion que recibe valores del usuario. Solamente puede ser usado para asignar variables de tipos primitivos y str.
	```
	let <tipo> <nombre_var> = input(<string>)::<tipo>;
	```

## Como correr el lexer

```
flex nombreArchivoLexer.l
g++ nombreArchivoLexer.yy.c
./nombreEjecutable nombreArchivoCodigo.eula      *NOTA: Es importante la extension*
```

## To Do:
* valores default para argumentos en las subrutinas
	func(a, b=1){}