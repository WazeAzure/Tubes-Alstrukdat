#include <stdio.h>

#include "circle.h"

int main(){
    CIRCLE c;
    CreateCircle(&c, 5);
    ds_union(&c, 0, 1);
    showDsArray(c);
    ds_union(&c, 3, 1);
    showDsArray(c);
    ds_union(&c, 3, 4);
    showDsArray(c);

    showCircle(c, 0);
    printf("\n");
    showDsArray(c);
    
    return 0;
}