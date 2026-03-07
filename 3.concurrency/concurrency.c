/* Definition:
Concurrency: We use this conceptual term to refer to problems that
arise because of concurrency.
Thread: Unidad mas pequena de procesamiento que un OS ejecuta (un thread/hilo es parte de el process)
*/

/* Working:
We are executing two threads at the same time, each of them work over the
the 'worker' function (a routine). Each thread increment the loop variable
depending on the argv argument, so if the input is 100 the ouput shall be
200. However, when the argv argument is over 10000, our program get broken.
The output now is 15480. Why? It is because of the instruction's behavior
when being executed.
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0;
int loops;

void *worker(void *arg){
    for(int i = 0; i<loops; i++){
        counter++;
    }
    return NULL;
}

int main (int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "usage: threads <value>\n");
        //imprime texto formateado en un stream specifico stderr es el stream de errores, el segundo argumento es el mensaje
        exit(1);
        //termina el programa inmediatamente, segun el argumento puede ser exito o error
    }
    loops = atoi(argv[1]);
    //pertenece a stdlib, convierte string a numero entero

    pthread_t p1, p2;

    printf("Initial value: %d \n", counter);

    Pthread_create(&p1, NULL, worker, NULL);
    //crea un nuevo thread (identificador,atributos,funcion a ejecturar,argumentos de la funcion)
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    //espera a que un thread termine (thread a esperar, valor retornado por el thread)
    Pthread_join(p2, NULL);
    
    printf("Final value: %d\n", counter);
    return 0;

}
/*
English:
    concurrently: at the same time /kənˈkʌr.ənt.li/ <The two events happened concurrently>
Estructura de compilacion:
    gcc concurrency.c -o concurrency -pthread
*/