#include <stdio.h>
#include "prioqueue.h"

int main(){
    PrioQueue Q;
    infotype x1,x2,x3,x4,x5,x6,x7;
    Word nama;
    nama.TabWord[0] =  'a';
    nama.TabWord[1] =  'b';
    nama.TabWord[2] =  'c';
    nama.TabWord[3] =  'd';
    Info(x1) = nama;
    Prio(x1) = 1;
    Info(x2) = nama;
    Prio(x2) = 2;
    Info(x3) = nama;
    Prio(x3) = 3;
    Info(x4) = nama;
    Prio(x4) = 4;
    Info(x5) = nama;
    Prio(x5) = 5;
    Info(x6) = nama;
    Prio(x6) = 5;
    Info(x7) = nama;
    Prio(x7) = 100;
    infotype val;
    MakeEmpty(&Q,5);
    // PrintPrioQueue(Q);
    // DeAlokasi(&Q);
    // PrintPrioQueueChar(Q);
    // PrintPrioQueueChar(Q);
    // DeAlokasi(&Q);
    Enqueue(&Q,x1);
    Enqueue(&Q,x4);
    PrintPrioQueue(Q);
    // PrintPrioQueue(Q);
    // Enqueue(&Q,x3);
    // PrintPrioQueue(Q);
    // Enqueue(&Q,x2);
    // PrintPrioQueue(Q);
    // Enqueue(&Q,x1);
    // PrintPrioQueue(Q);
    // Enqueue(&Q,x6);
    // PrintPrioQueue(Q);
    // PrintPrioQueue(Q);
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);
    // printf("hello\n");
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));

    // Enqueue(&Q,x7);
    // PrintPrioQueue(Q);

    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);

    // Enqueue(&Q,x4);
    // PrintPrioQueue(Q);

    // Dequeue(&Q,&val);
    // PrintPrioQueue(Q);

    // printf("%d\n",NBElmt(Q));
    // printf("%d\n",IsEmpty(Q));
    // printf("%d\n",IsFull(Q));
    
    // Enqueue(&Q,x3);
    // Dequeue(&Q,&val);
    // Enqueue(&Q,x4);
    // Dequeue(&Q,&val);
    // Dequeue(&Q,&val);
    // Enqueue(&Q,x5);
}