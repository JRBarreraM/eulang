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

* int: representa un número entero con signo de 32 bits.  
	```
	let int eligente;  
	let int eligente = 42;
	```

* bool: representan un valor booleano, es decir, true o false.  
	```
	let bool basor;  
	let bool basor = true;
	```

* float: representa un número decimal de 32 bits.  
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
	let int[] intArray4;
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

	let ura structura2 = {10, "diez"};
	```

* union: representa un tipo de dato especial que contiene una serie de datos que comparten un espacio de memoria, pero solo se puede almacenar uno de estos valores. 
	```
	union europea { 
		let int numero;
		let str texto;
	}

	let europea unioneuropea1;
	unioneuropea1.numero = 10;
	unioneuropea1.texto = "diez";
	let europea unioneuropea = { numero -> 10 };
	```

* type ~: representa una direccion de memoria del heap.
	```
	let int ~ var;
	let int ~ var = &variable;
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
* Definida:  
	```
	for (int i = 0; i < n; i++) {
		//do something n times
	}
	```
* Indefinida:  
	```
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
Las funciones solamente reciben tipos primitivos y apuntadores.
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


function fact(n) {
  return tail_fact(n,1) ;
}

function tail_fact(n,a) {
  if (n == 0)
    return a ;
  else
    return tail_fact(n-1,n*a) ;
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

* char:
	```
	str || char + str || char -> str
	ascii('a') -> 97
	ascii(97) -> 'a'
	char == char;
	char != char;
	char > char;
	char < char;
	char >= char;
	char <= char;
	```

* int: 
	```
	int + int -> int;
	int - int -> int;
	int * int -> int;
	int / int -> int;
	int ** int -> int;
	int % int -> int;
	int > int -> bool;
	int < int -> bool;
	int >= int -> bool;
	int <= int -> bool;
	int != int -> bool;
	int == int -> bool;
	int.toString() -> string;
	```

* bool: 
	```
	bool || bool = bool;
	bool && bool = bool;
	!bool = bool;
	bool.toString() -> string;
	```

* float: 
	```
	float || int +  float || int = float;
	float || int -  float || int = float;
	float || int *  float || int = float;
	float || int /  float || int = float;
	float || int ** float || int = float;
	float || int %  float || int = float;
	round(float)   -> int;
	ceil(float)    -> int;
	floor(float)   -> int;
	decimal(float) -> float;
	float > float  -> bool;
	float < float  -> bool;
	float >= float -> bool;
	float <= float -> bool;
	float != float -> bool;
	float == float -> bool;
	float.toString() -> string;
	```

* type[N]:
	```
	let type[] array = [];
	array[int] -> array_member_at_int;
	array[int] = type_member;
	array1[] + array2[] -> array3[];
	array[].len -> int;
	array[-1] == array[array.len];
	array[0...1] == array[0];
	array.toString() -> string;
	```

* str:  
	```
	str[int] -> char_at_int;
	str + str -> str;
	str.len -> int;
	str[-1] == str[str.len];
	str[0...1] == str[0];
	str.split(str) -> str[];
	str == str;
	str != str;
	```

* list:  
	```
	let list[type] lista = [];
	lista[int] -> lista_member_at_int;
	lista + lista -> lista;
	lista.len -> int;
	lista[-1] == lista[lista.len];
	lista[0...1] == lista[0];
	lista.pop();
	lista.pop(index);
	lista.push(type_member);
	lista.insert(index, type_member);
	lista.find(element);
	lista.reverse();
	lista.remove(type_member);
	lista.toString() -> string;
	```

* truthy y falsy:  
	```
	0 -> false
	int != 0 -> true
	[] -> false
	[algo] -> true
	```

## I/O:
* print();  
	```
	print(str); //like python
	print(type + type);
	```
* input();  
	```
	input('mensajito: '); //like python
	```