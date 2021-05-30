# CI4721_LenguajesII

# Eulang

_Eulang es como agarrar python pero con c++, 1% de probabilidades, 99% de fe_

## Declaraciones
```
let tipo_de_dato nombre_variable;  
o  
let tipo_de_dato nombre_variable = valor;
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
	let flot ante;  
    let float ante = 3.1416;
	```

### Compuestos

* type[N]: representa un arreglo de tamaño N, con n siendo un entero positivo, del tipo Type.  
	```
	let int[n] intArray1;  
	let int[1] intArray;
	let int[] intArray3 = [1,2,3];
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

	let ura structura2 = ura{10,"diez"};
	```

* union: representa un tipo de dato especial que contiene una serie de datos que comparten un espacio de memoria, pero solo se puede almacenar uno de estos valores. La estructura internamente guarda el ultimo valor asignado como "activo".
	```
	union europea { 
		let int numero;
		let str texto;
	}

	let europea unioneuropea1;
	unioneuropea1.texto = "diez";
	unioneuropea1.numero = 10;
	let ura structura2 = ura{10,"diez"};
	print(unioneuropea1.texto); //Error texto is not active
	let str hola = "hola" + unioneuropea1.numero; //Type error str + int
	let str hola = "hola" + unioneuropea1.numero.toString(); //fino
	```

* type ~: representa una direccion de memoria del heap. Solo se puede desreferenciar con el operador &.
	```
	let type ~ var = new type;
	let type variable = &var;
	vengeance var; //libera el espacio de memoria
	```

## Selección
```
if( condicional ) {
	//do
} elif( condicional ) {
	//something
} else {
	// or not
}
```

## Repetición
* Definida: disponible para array, str, list. Se crea una copia de la estructura a iterar, y se itera sobre la misma. Lo cual permite que se puedan hacer modificaciones sobre la estructura original.
	```
	let int[] a = [1,2,3];
	foreach elem in a {
		//do something a.len times
	}

	let list b = [1,2,3,4,5];
	foreach elem in b {
		if (elem % 2 != 0){
			b.append(elem)
		}
	}
	print(b)// [2,4]
	```
* Indefinida:  
	```
	for (int i = 0; i < n; i++) {
		//do something n times
	}

	while( condicional ) {
		//do something until not condicional
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
func name(type argument)::type_return { 
	// do something
	return Primitivo
}

func fact(int numero)::int {
	fact_aux(numero-1, 0);
}

func fact_aux(int numero, int count)::int {
	if(numero == 0){
		return count;
	}
	return fact_aux(numero-1, numero*count);
}


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
Los procedimientos solamente reciben tipos primitivos y apuntadores.
``` 
proc name(type argument) {
	//i do not return
}
``` 

## Paso por valor o por referencia:
Por valor por defecto.
Para pasar por referencia se usa int ^ hola. Ejemplo:  
```
int hola = 1;
int adios = 1;
function dummy(int ^ a, int b)::int{
	a++;
	b++;
	return a+b;
}
print(hola);  //1
print(adios); //1
print(dummy(hola,adios)); //4
print(hola); //2
print(adios); //1
```

## Arreglos dinamicos:
list: representa un arreglo de tamaño variable, de datos de un tipo primitivo homogeneo.
```
let list[type] myLista;
let list[type] myLista = [a,b,c,d];
```

## Operaciones sobre tipos de datos:

### Aritméticos
	int + int -> int;
	int - int -> int;
	int * int -> int;
	int / int -> int;
	int % int = float;
	int ** int -> int; //exponenciacion

	float || int +  float = float;
	float || int -  float = float;
	float || int *  float = float;
	float || int /  float = float;
	float || int %  float = float;
	float || int ** float = float; //exponenciacion

### Booleanos
* !: para bool, si el valor pasado es true retorna false, y viceversa.  
	```
	!true -> false;  
	!false -> true;
	``` 

* ||: para bool, or logico.  
	```
	true  || false -> true;  
	true  || true  -> true;  
	false || true  -> true;  
	false || false -> false;  
	``` 
* &&: para bool, and logico.  
	```
	true  && false -> false;  
	true  && true  -> true;  
	false && true  -> false;  
	false && false -> false;  
	``` 

### Relaciones
Operadores binarios que retornan un bool.


* ==: para int, float se verifica si tienen el mismo valor. En caso firmativo retorna true, en caso contrario false.
	``` 
	int == int -> bool;
	float == float -> bool;
	``` 

* !=: para int, float funciona como !( == ).
	``` 
	int != int -> bool;
	float != float -> bool;
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
	str || char + str || char -> str  //concatena creando un nuevo str.
	ascii('a') -> 97 //convierte un char en su int ASCII asociado.  
	ascii(97) -> 'a' //convierte un int en su char ASCII asociado.
	```

* int: 
	```
	int.toString() -> string; //convierte el int en str
	```

* float: 
	```
	floor(float)   -> int; //trunca el decimal, convirtiendolo en su parte entera. 

	ceil(float)    -> int; //aplica floor() al float y le suma 1, resultando en el int superior mas cercano.  

	decimal(float) -> float; //aplica float - floor(float).  

	round(float)   -> int; //aplica floor(), si el resultado de decimal() es menor 0.5, ceil() en caso contrario, resultando en un int.  

	float.toString() -> string; //convierte el flot en str
	```

* type[N]:
	```
	array[int] -> array_member_at_int;  //indexacion retorna el elemento del arreglo en la posicion indicada.  

	array1[] + array2[] -> array3[]; //se crea un nuevo arreglo colocando en las primeras n posiciones los n elementos del primer arreglo, y en las m posiciones siguientes los m elementos del segundo arreglo, resultando en un arreglo de n+m elementos.  

	array[].len -> int; // retorna el numero de elementos del arreglo.  

	array[-1] == array[array.len -1]; //azucar sintactica para indexar el arreglo como si fuese circular.  

	array[0...1] == array[0]; //retorna un el conjunto de elementos del elementos indexados en el rango especificado. El rango es inclusivo del lado izquierdo pero no del lado derecho.  

	let int[] array= [10,11];
	array.toString() -> [ '[' , '1' , '0' , ',' , '1' , '1' , ']' ]; //"["+ 10.tostring() + "," + 11.tostring() + "]"
	```

* str: arreglos de caracteres.
	```
	str[int] -> char_at_int;  //analogo al array. 

	str + str -> str;  //analogo al array.

	str.len -> int;  //analogo al array.

	str[-1] == str[str.len];  //analogo al array

	str[0...1] == str[0];  //analogo al array

	str1.split(str2) -> str3[]; //busca el str2 dentro del str1 y genera substrings con los elementos que quedan a cada lado del separador, para construir un arreglo de strings.

	str == str;  //comparacion caracter por caracter, solo se pueden comparar str del mismo lenght.

	str != str;  //! (str == str)

	str.toInt() -> int; // verifica que solo existan caracteres [0-9], y luego arma el entero.

	str.toFloat() -> float;  // verifica que solo existan caracteres [0-9] separados por un unico '.', y luego arma el float.
	```

* list: lista doblemente enlazada. Funciona como una arreglo dinamico.
	```
	lista[int] -> lista_member_at_int; //analogo al array.  

	lista + lista -> lista; //analogo al array.  

	lista.len -> int; //analogo al array.  

	lista[-1] == lista[lista.len]; //analogo al array. 

	lista[0...1] == lista[0]; //analogo al array.  

	lista.pop(); //elimina el ultimo elemento de la lista, y lo retorna.  

	lista.pop(int); //elimina el elemento en el indice indicado, y lo retorna.  

	lista.push(type_member); //agrega el elemento especificado al final de la lista.  

	lista.insert(index, type_member); //agrega el elemento especificado en el indice indicado,  

	lista.find(element);  //busca un elemento en la lista y si se encuentra retorna el indice. Si no error.
	lista.reverse();  //invierte la lista
	lista.remove(type_member); //elimina todas las ocurrencias de un elemento de la lista.  

	lista.toString() -> string; //analogo al array
	```

## I/O:

* print(): va donde iria un print.
	```
	print(str); //like python
	print(type + type);
	```

* input(): solamente puede ser usado para asignar variables de tipos primitivos y str.
	```
	let type var = input('mensajito: ')::type;
	```