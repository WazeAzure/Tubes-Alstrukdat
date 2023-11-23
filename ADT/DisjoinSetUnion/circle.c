#include <stdio.h>

#include "circle.h"
#include "../../globalVar.h"
#include "../User/user.h"

void CreateCircle(CIRCLE* c){
    int i;
    for(i=0; i<20; i++){
        (*c).arr[i] = i;
        (*c).isVisited[i] = 0;
    }
    (*c).Neff = 0;
}

pair_ds ds_search(CIRCLE *c, int idUser){
    int count = 0;
    while((*c).arr[idUser] != idUser){
        idUser = (*c).arr[idUser];
        count++;
    }
    pair_ds d;
    d.count = count;
    d.root = idUser;
    return d;
}

void ds_union(CIRCLE *c, int node1, int node2){
    pair_ds root1 = ds_search(c, node1);
    pair_ds root2 = ds_search(c, node2);
    printf("nilai node - %d %d\n", node1, node2);
    // printf("nilai root - %d %d\n", root1, root2);
    if(root1.count > root2.count){
        // gabungin mereka
        (*c).arr[node2] = (*c).arr[node1];
    } else {
        (*c).arr[node1] = (*c).arr[node2];
    }
    (*c).Neff++;
}

int isAllVisited(CIRCLE *c){
    int i;
    for(i=0; i<(*c).Neff; i++){
        if((*c).arr[i] == 0){
            return i;
        }
    }
    return -1;
}

void showAllCircle(CIRCLE *c){
    while(isAllVisited(c) != -1){
        int j = isAllVisited(c);
        while((*c).arr[j] != j){
            if(!(*c).isVisited[j]){
                (*c).isVisited[j] = 1;
                printf("%d\n", j);
                // printf("%s\n", USER_NAMA(USER(user, j)).TabWord);
                j = (*c).arr[j];
            }
        }
        printf("%d\n", j);
        // printf("%s\n", USER_NAMA(USER(user, j)).TabWord);
    }
}

void showCircle(CIRCLE c, int userId){
    pair_ds root = ds_search(&c, userId);
    
    int i;
    int count = 0;
    for(i=0; i<c.Neff; i++){
        pair_ds temp = ds_search(&c, i);
        if(temp.root == root.root){
            printf("- %s\n", USER_NAMA(USER(user, i)).TabWord);
            count++;
        }
    }
    printf("banyak anggota circle %d\n", count);
}

void showDsArray(CIRCLE c){
    for(int i=0; i<20; i++){
        printf("%d ", c.arr[i]);
    }
    printf("\n");
    for(int i=0; i<20; i++){
        printf("%d ", i);
    }
    printf("\n");
}