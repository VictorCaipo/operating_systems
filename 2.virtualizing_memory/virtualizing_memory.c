#include <unistd.h>//funciones sistema operativo tipo unix getpid()
#include <stdio.h>//input output sistema operativo printf()
#include <stdlib.h>//memoria sistema operativo malloc()
#include <assert.h>//condiciones, detecta errores rapidamente, assert()
#include <time.h>
/*
Un proceso es un programa ejecutandose, getpid(): obtiene el numero o
codigo del proceso actual
*/
void spin(int seconds);

int main(int argc, char *argv[]){
    /*
    malloc: el programa pide memoria al heap, malloc devuelve un
    puntero a esa direccion, si no hay espacio en la memoria
    devuelve NULL, la memoria reservada debe ser liberada despues
    con free()
    */    
    int *p = malloc(sizeof(int));
    assert(p != NULL);//El programa continua si p es diferente de NULL

    printf(" (%d) address of p: %p \n", getpid(), (void*)p );
    *p = 0;
    while(1) {
        spin(1);
        *p = *p + 1;
        printf(" (%d) p: %d \n", getpid(), *p);
    }
    /*
    %d formato decimal %08x formato hexadecimal, rellenar con ceros
    8 caracteres
    */
    return 0;
}

void spin(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        // busy wait (no hace nada)
    }
}
/*
La magia de este programa ocurre al correr el mismo programa varias veces,
porque nos damos cuenta de que una misma direccion se repite para
varios procesos, lo cual parece raro.

Esto ocurre porque cada proceso tiene su propio espacio de memoria virtual.
El sistema operativo asigna memoria fisica para cada proceso y mantiene
una tabla que traduce las direcciones virtuales a direcciones fisicas.

La MMU se encarga de realizar esta traduccion entre direcciones virtuales
y fisicas.

Por eso pueden existir variables con la misma direccion virtual en
distintos procesos, aunque en la memoria fisica real se encuentren
en lugares diferentes.
*/