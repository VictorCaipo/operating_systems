#include <stdio.h>
#include <unistd.h>//interactua con el OS (basados en unix) <fork,getpid>
#include <sys/types.h>//tipos de datos usados por el sistema operativo <pid_t>

/*
PID significa Process ID, cada proceso tienen un identificador
El OS mantiene la relacion entre procesos
Padre e hijo proceso corren al mismo tiempo
*/

int main(void){
    pid_t pid;
    /*
    pid es un numero asi que podriamos guardarlo en un int (en linux), pero para que el codigo sea
    portable (en windows talvez usan numeros long) y para seguridad del sistema se usa pid_t
    (libreria sys/types.h)
    */
    pid = fork();
    /*
    crea un nuevo proceso duplicando el proceso actual, si nos encontramos en el proceso hijo devuelve 0
    si es proceso padre devuelve pid del hijo, si es error -1
    */
    if(pid == 0){
        //proceso hijo
        printf("Soy el proceso hijo. PID = %d\n", getpid());//obtiene PID del proceso
        printf("Mi padre es %d\n", getppid());//obtiene PID del padre
    } else{
        //proceso padre
        printf("Soy el proceso padre. PID = %d\n", getpid());
        printf("He creado un hijo con PID = %d\n", pid);
    }
    return 0;
}

/*
Process es un programa en ejecucion, un programa es codigo y datos, cuando el sistema operativo
lo carga y ejecuta se convierte en un proceso.

El sistema operativo crea una ilusion de que hay muchos CPUs usando una tecnica llamada Time Sharing
(ejecuta un proceso, lo pausa, ejecuta otro, repite).

El OS usa dos herramientas Mechanisms y Policis. Mechanisims son herramientas para hacer
algo (cambiar de un proceso a otro), Policies son las decisiones del sistema (que proceso ejecutar ahora).

Un proceso puede acceder a varias partes de la maquina (memoria, registros del cpu, informacion I/O).

La API de procesos son un conjunto de funciones basicas para manejar procesos (crear, destruir, esperar, etc).

Cuando un programa se ejecuta el OS hace varias cosas:
    Carga el programa desde el disco a la memoria
    Crea el stack (variables locales y parametros)
    Crea el hep
    Configura entrada y salida
    Inicia la ejecucion en la funcion main()

Un Proceso puede estar en tres estados (running, ready, blocked) (ejecutandose, listo para ejecutar, esperando)
si el evento termina el proceso vuelve a ready

El sistema operativo mantiene informacion sobre cada proceso en una estructura llamada PCB
Process Control Block

*/