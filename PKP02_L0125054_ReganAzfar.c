/*
Nama: Muhammad Regan Azfar Azizan
NIM: L0125054
*/

#include <stdio.h>

int main(){
    puts("===Tebak angka 1-100, 3 diantaranya ada hadiah===");

    //inisialisasi variabel tebakan dari user dan sisa kesempatan
    int tebakan;
    int sisa_kesempatan = 3;

    //looping jika sisa kesempatan lebih dari nol
    while (sisa_kesempatan > 0){
        printf("\nTebakanmu: ");
        scanf("%d", &tebakan);  //menyimpan tebakan dari user

        switch (tebakan){
        case 20:    //jika user menebak 20
            puts("Kamu mendapat uang 20 juta!");
            puts("Game Selesai");
            return 0;
        case 59:    //jika user menebak 59
            puts("Kamu mendapat RTX 5090!");
            puts("Game Selesai");
            return 0;
        case 91:    //jika user menebak 91
            puts("Kamu mendapat Porsche 911!");
            puts("Game Selesai");
            return 0;
        default:    //akan terus berjalan dan sisa kesempatan berkurang 1 jika user salah menebak
            sisa_kesempatan--;
            puts("Zonk!");
            printf("Sisa kesempatan: %d", sisa_kesempatan);

            if (sisa_kesempatan == 0)   //jika kehabisan kesempatan
                puts("\nKesempatan habis! kamu kurang beruntung");
            break;
        }
    }
}