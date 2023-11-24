#include <stdio.h>
#include "charmachine.h"

int main() {
    char MARK = ';'; /

    // Tes fungsi START dan ADV 
    printf("Tes fungsi START dan ADV:\n");
    START(MARK);
    while (!EOP) {
        printf("currentChar: %c\n", currentChar);
        ADV(MARK);
    }
    printf("\n");

    return 0;
}
