#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
    List* L = create_list();

    int* espacio;
    for(int i = 1; i <= 10; i++){
        
        espacio = (int*) malloc(sizeof(int));
        *espacio = i;
        pushBack(L, espacio);   
    }
    
    
    
    return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *Lista){
    int suma = 0;
    int* aux;
    aux = first(Lista);
    while(aux != NULL){
        suma += *aux;
        aux = next(Lista);
    }    
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *Lista, int elem){
    int* aux = first(Lista);
    while (aux != NULL) {
            if (*aux == elem) {
                popCurrent(Lista);
                aux = first(Lista);
            } else aux = next(Lista);
        }
    }


/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* Pila1, Stack* Pila2){
    Stack* Pilaaux = NULL;
    int* aux;
    aux = top(Pila1);
    int tamano = 0;
    while(aux != NULL){
        pop(Pila1);
        tamano++;
        Pilaaux = (Stack*) realloc(Pilaaux, tamano * sizeof(Stack*));
        push(Pilaaux, aux);
        aux = top(Pila1);
    }
    aux = top(Pilaaux);

    while(aux != NULL){
        pop(Pilaaux);
        push(Pila1, aux);
        push(Pila2, aux);
        aux = top(Pilaaux);        
    }
   free(Pilaaux);

}
/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
    char *stack=NULL;
       int count=-1;

       for (int i = 0; cadena[i] != '\0'; i++) {
          char c = cadena[i] ;

          if (c == '(' || c == '{' || c == '[') {
             count++;
             char *temp = (char*)realloc(stack,(count+1)*sizeof(char));
             if (!temp) {
                free(stack); return 0;
             }

             stack = temp;
             stack[count] = c;;
          } 
          else if (c == ')' || c == '}' || c == ']') {
             if (count == -1) {
                free(stack); return 0;
             }

             char top = stack[count];
             if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                free(stack); return 0;
             }
             count--; 
          }
       }

       int resultado;
       if (count == -1) resultado = 1;
       else resultado = 0;

       free(stack);
       return resultado;
    }


