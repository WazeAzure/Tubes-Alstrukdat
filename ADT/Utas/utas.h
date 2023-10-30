#include <stdio.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"
#include "../Linkedlist/listlinier.h"

#ifndef _UTAS_H
#define _UTAS_H

typedef struct {
    int index; // index dari 1,...
    Word utasan;
    DATETIME time;
} UTAS;

typedef struct {
    int IDKicauan;
    int IDUtas; 
    Node child; 
} MAINUTAS;

void CreateMainUtas(MAINUTAS *parent, int IDKicauan, int IDUtas, Node child);

void CetakMainUtas(MAINUTAS *parent);

void CreateUtas(UTAS *utas, int index, Word utasan, DATETIME time);

void ReadUtas(UTAS utas);

void CetakUtas(UTAS *utas);

void SambungUtas(int IDUtas,int index, UTAS *utas);

void HapusUtas(int IDUtas,int index, UTAS *utas); 




#endif