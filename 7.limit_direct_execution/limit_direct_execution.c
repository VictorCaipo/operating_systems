#include <stdio.h>

struct process{
    int pid;
    int remaining_time;
};

typedef struct process process;

void run_process(process *p);

int main(void){

    process p1 = {1,5};//nueva forma de inicializar
    process p2 = {2,3};
    process p3 = {3,4};

    while(p1.remaining_time > 0 || p2.remaining_time > 0 || p3.remaining_time > 0){
        //este while ejecuta siempre que haya un proceso vivo
        run_process(&p1);
        run_process(&p2);
        run_process(&p3);
        
        printf("-- Context Switch --\n");
    }

    printf("All processes finished\n");
    return 0;
}

void run_process(process *p){
    if(p->remaining_time > 0){
        printf("Runing process: %d\n", p->pid);
        p->remaining_time--;
    }
}

/*
Limited direct execution:
    El OS debe permitir que varios programas compartan la CPU, esto 
    se logra ejecutando un proceso un tiempo y cambiandolo a otro
    (time sharing).

    La idea basica es ejecutar el programa directamente en la CPU,
    esto es rapido pero introduce problemas de seguridad y control.

    Para solucionar esto se crearon 2 modos de ejecucion:
        user mode: lo usan programas normales, no puede ejecutar
            instrucciones privilegiadas
        kernel mode: modo del sistema operativo, tiene acceso comp
            leto al hardware

    Cuando un programa necesita una operacion privilegiada usa un
    system call. Esto permite control seguro del sistema

    El OS debe poder detener un proceso y ejecutar otro. Si un pro
    ceso esta ejecutandose el OS no tiene control de la CPU

    Enfoque cooperativo: (solucion 1)
    Los procesos deben cerder voluntariamente la CPU cuando existe
    una sistem call, si un proceso entre en bucle infinito, el OS
    no puede recuperar el control (solucion: reiniciar el sistema)

    Enfoque no copperativo (solucion 2) (interrupcion del temporizador)
    Esta es la solucion moderna, un temporizador genera interrupcion
    es periodicas, esto garantiza que ningun proceso monopolice la 
    CPU.

    Cuando el OS cambia de proceso realiza un context swuitch. Es
    decir sigue los siguientes pasos. Guardar los registros del 
    proceso actual, restaurar los registros del nuevo proceso, con
    tinuar con la ejecucion del nuevo proceso. Esto permita simular
    una ejecucion simultanea de procesos

    En resumen la virtualizacion del CPU se logra con varias herrami
    entas: user mode/ kernel mode, systems call, timer interrupts y
    context switching

*/