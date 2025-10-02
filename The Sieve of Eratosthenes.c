#include <stdio.h>
#define size 1000

int main(){
    int prima[size];
    int i, j;

    //set index ke 0 dan 1 menjadi 0
    prima[0] = 0;
    prima[1] = 0;

    //set semua elemen array menjadi 1, dimulai dari index ke 2
    for (i = 2; i < size; i++){
        prima[i] = 1;
    }

    for (i = 2; i < size; i++){
        if (prima[i] == 1){
            //jika elemen array ke i bernilai 1, set setiap kelipatan dari i menjadi 0, yang artinya bukan prima
            for (j = i * 2; j < size; j += i){
                prima[j] = 0;
            }
        }
    }

    //cetak semua iterasi jika array bernilai 1, yang artinya bilangan prima
    printf("Bilangan prima:\n");
    for (i = 2; i < size; i++){
        if (prima[i] == 1){
            printf("%d\n", i);
        }
    }
}

