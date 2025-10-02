#include <stdio.h>
#define size 1000

int main(){
    int prima[size];
    int i, j;

    prima[0] = 0;
    prima[1] = 0;
    
    for (i = 2; i < size; i++){
        prima[i] = 1;
    }

    for (i = 2; i < size; i++){
        if (prima[i] == 1){
            for (j = i * 2; j < size; j += i){
                prima[j] = 0;
            }
        }
    }
    
    printf("Bilangan prima:\n");
    for (i = 2; i < size; i++){
        if (prima[i] == 1){
            printf("%d\n", i);
        }
    }
}
