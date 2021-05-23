# CI4721_LenguajesII

# Protolenguaje

_Acá va un párrafo que describa lo que es el proyecto_

## Declaraciones
```
tipo_de_dato nombre_variable;  
o  
tipo_de_dato nombre_variable = valor;
```

## Tipos de datos

### Primitivos

* char: representa un caracter ASCII de 8 bits.  
	```
	char mander;  
	char mander = 'o';
	```
* int: representa un número entero con signo de 32 bits.  
	```
	int eligente;  
	int eligente = 42;
	```
* bool: representan un valor booleano, es decir, true o false.  
	```
	bool basor;  
	bool basor = true;
	```
* float: representa un número decimal de 32 bits.  
	```
	flot ante;  
    float ante = 3.1416;
	```

### Compuestos

* type[N]: representa un arreglo de tamaño N, con n siendo un entero positivo, del tipo Type.  
	```
	int[n] intArray1;  
	int[1] intArray;
	int[] intArray3 = [1,2,3];  
	int[] intArray4;
	```
* str: representa una cadena de caracteres.  
	```
	str string1 = "Hello";
	str string1;
	```
* struct: representa un conjunto de datos agrupados bajo un mismo nombre.   
	```
 	struct ura {
		int numero;
		str texto;
	}
	```
* union: representa un tipo de dato especial que contiene una serie de datos que comparten un espacio de memoria, pero solo se puede almacenar uno de estos valores. 
	```
	union europea { 
		int numero;
		str texto;
	}
	```
* type ~: representa una direccion de memoria del heap.
	```
	int ~ var;
	int ~ var = &variable;
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
list myLista;
list myLista = [a,b,c,d];
```

## Operaciones sobre tipos de datos:
