/*The OSE is a body of sotware that makes sure the system operates correctly and efficientlly*/
/*The OS use virtualization that means transform a resource into a more general, powerful, and easy to use virtual form of itself*/
/*The OS is known as a resource manager, because it manage resources (CPU, memory and disk) with many goals in mind*/

#include <stdio.h>//input output sistema operativo libreria estandar
#include <stdlib.h>//memoria sistema operativo malloc() y free() libreria estandar
#include <time.h>
/*
Aca se demuestra la virtualizacion, creamos 4 tareas que siempre estan activas, el OS intercala cada
tarea de una manera que todavia no sabemos, dando la impresion de que se ejecutan a la vez
*/
void spin(int seconds);

int main (int argc, char *argv[]){
    if (argc != 2) {
        /*acepta 2 argumentos, el nombre del programa y el argumento util*/
        fprintf(stderr, "usage: cpu <string>\n");//stdio.h
        exit(1);//stdlib.h
        /*devuelve 1 al sistema operativo, es decir sale del programa*/
    }
    char *str = argv[1];
    while (1) {
        spin(1);
        printf("%s\n", str);//stdio.h, %s para strings
    }
    return 0;
    //to stop the program press ctrl+c
}

void spin(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        // busy wait (no hace nada)
    }
}