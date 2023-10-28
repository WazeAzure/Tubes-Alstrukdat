#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

#define endl printf("\n")

int main() {
    char MARK = ';'; // Assuming each sentence ends with a newline character
    Word sentence1, sentence2, sentence3;

    printf("Enter the first sentence: ");
    readWord(&sentence1, MARK);
    printf("First sentence: %s\n", sentence1.TabWord);

    printf("Enter the second sentence: ");
    readWord(&sentence2, MARK);
    printf("Second sentence: %s\n", sentence2.TabWord);

    printf("Enter the third sentence: ");
    readWord(&sentence3, MARK);
    printf("Third sentence: %s\n", sentence3.TabWord);

    printf("Third sentence: %s", sentence3.TabWord);
    return 0;
}