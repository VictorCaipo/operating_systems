#include <stdio.h>

const int N = 3;
const int QUANTUM = 2;

typedef struct {
    int pid;
    int remaining_time;
    int completion_time;
    int first_run_time;
    int started;

} process;

int main(void){

    process p[N] = {
        {1, 6, 0, -1, 0},
        {2, 2, 0, -1, 0},
        {3, 4, 0, -1, 0}
    };
    int time = 0;
    int finished = 0;

    while(finished < N){
        for(int i = 0; i < N; i++){
            if(p[i].remaining_time > 0){
                if(!p[i].started){
                    p[i].first_run_time = time;
                    p[i].started = 1;
                }
                int exec = (p[i].remaining_time > QUANTUM) ? QUANTUM : p[i].remaining_time;
                time += exec;
                p[i].remaining_time -= exec;

                if(p[i].remaining_time == 0){
                    p[i].completion_time = time;
                    finished++;
                }
            }
        }
    }

    printf("\nPID\tTurnarount\tResponse\n");

    for(int i = 0; i<N ; i++){
        printf("%d\t%d\t\t%d\n",
            p[i].pid,
            p[i].completion_time,
            p[i].first_run_time
        );
    }
    return 0;
}

/*
Scheduling: Es decidir que proceso usa la CPU y cuando

Turnaround Time es el tiempo que total demoro en ejecutarse el proceso 
(Turnaround = Tcompletition - Tarrival)
Response Time es el tiempo hasta que el proceso empieza por primera
vez (Tresponse = Tfirst_run - Tarrival)

Preemption: Interrumpir procesos
Context switch: Cambiar proceso
Time slice/ quantum: tiempo asignado

Algoritmos de Scheduling:
    FIFO: Ejecuta en orden de llegada
    SJF: Ejecuta primero el mas corto
    STCF: Version preemptiva de SJF
    Round Robin: Cada proceso recibe un quantum (tiempo fijo)
*/