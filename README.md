# CI4721_LenguajesII

# Protolenguaje

_Acá va un párrafo que describa lo que es el proyecto_

## Primitivos

* Caracteres: char
* Enteros: int
* Booleanos: bool
* Flotantes: float

## Compuestos

* Arreglos: Type[]
* Cadenas de caracteres: str
* Registros: struct name { int numero; str texto; }
* Variantes uniones: union { int numero; | str texto; }
* Apuntadores: int ~

## Selección

	If( condicional ) {}
	elif( condicional ) {}
	else {}

## Repetición

* for (int i = 0; i < n; i++) {}  ó  for (int i = 1; 10) {} (nota se puede -10)
* while( condicional ) {}

## Comentarios
* Una linea:  //
* Multilinea: /* */

## Funciones y Procedimientos
* func name(type argument)::type return { … return Primitivo} (se puede retornar apuntadores?)
* proc name(type argument) {}