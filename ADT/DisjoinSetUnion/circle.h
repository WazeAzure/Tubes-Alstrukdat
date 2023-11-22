#ifndef _CIRCLE_h
#define _CIRCLE_h

#include "../boolean.h"
// #include "../User/user.h"
// #include "../../globalVar.h"

typedef struct {
    int root;
    int count;
} pair_ds;

typedef struct {
    boolean isVisited[20];
    int arr[20];
    int Neff;
} CIRCLE;

void CreateCircle(CIRCLE *c);

pair_ds ds_search(CIRCLE *c, int idUser);

void showAllCircle(CIRCLE *c);

void showCircle(CIRCLE c, int userId);

void ds_union(CIRCLE *c, int node1, int node2);

void showDsArray(CIRCLE c);

#endif