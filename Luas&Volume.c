#include <stdio.h> //preprosesor

//program utama
int main(){

    //deklarasi data
    int pilih;
    float sisi, panjang, lebar, alas, tinggi, tinggi_prisma, radius, a, b;
    const float pi = 3.14;

    printf("===Kalkulator Bangun Datar dan Bangun Ruang===\n");
    
    //perulangan
    while (1){
        printf("\n1. Luas Bangun Datar\n2. Volume Bangun Ruang\n3. Hentikan program\n");
        printf("Pilih: ");
        scanf("%d",&pilih);

        //jika memilih bangun datar
        switch (pilih){
        case 1:
            printf("\n1. Persegi\n2. Persegi Panjang\n3. Segitiga\n4. Jajar Genjang\n5. Lingkaran\n6. Trapesium\n");
            printf("Pilih: ");
            scanf("%d",&pilih);

            //pilihan bangun datar
            switch (pilih){
            case 1:
                printf("Masukkan panjang sisi: ");
                scanf("%f",&sisi);
                printf("Luas: %.2f\n", sisi*sisi);
                break;
            case 2:
                printf("Masukkan panjang dan lebar: ");
                scanf("%f %f",&panjang,&lebar);
                printf("Luas: %.2f\n", panjang*lebar);
                break;
            case 3:
                printf("Masukkan panjang alas dan tinggi: ");
                scanf("%f %f",&alas,&tinggi);
                printf("Luas: %.2f\n", alas*tinggi/2);
                break;
            case 4:
                printf("Masukkan panjang alas dan tinggi: ");
                scanf("%f %f",&alas,&tinggi);
                printf("Luas: %.2f\n", alas*tinggi);
                break;
            case 5:
                printf("Masukkan jari-jari: ");
                scanf("%f",&radius);
                printf("Luas: %.2f\n", pi*radius*radius);
                break;
            case 6:
                printf("Masukkan panjang a, b, dan tinggi: ");
                scanf("%f %f %f",&a,&b,&tinggi);
                printf("Luas: %.2f\n", (a+b)*tinggi/2);
                break;
            default:
                printf("Input tidak valid!\n");
            }
            break;
        
        //jika memilih bangun ruang
        case 2:
            printf("\n1. Kubus\n2. Balok\n3. Prisma\n4. Tabung\n5. Kerucut\n6. Bola\n");
            printf("Pilih: ");
            scanf("%d",&pilih);

            //pilihan bangun ruang
            switch (pilih){
            case 1:
                printf("Masukkan panjang sisi: ");
                scanf("%f",&sisi);
                printf("Volume: %.2f\n", sisi*sisi*sisi);
                break;
            case 2:
                printf("Masukkan panjang, lebar, dan tinggi: ");
                scanf("%f %f %f",&panjang,&lebar,&tinggi);
                printf("Volume: %.2f\n", panjang*lebar*tinggi);
                break;
            case 3:
                printf("Masukkan panjang alas, tinggi segitiga, dan tinggi prisma: ");
                scanf("%f %f %f",&alas,&tinggi,&tinggi_prisma);
                printf("Volume: %.2f\n", (alas*tinggi/2)*tinggi_prisma);
                break;
            case 4:
                printf("Masukkan jari-jari dan tinggi: ");
                scanf("%f %f",&radius,&tinggi);
                printf("Volume: %.2f\n", pi*radius*radius*tinggi);
                break;
            case 5:
                printf("Masukkan jari-jari dan tinggi: ");
                scanf("%f %f",&radius,&tinggi);
                printf("Volume: %.2f\n", (pi*radius*radius*tinggi)/3);
                break;
            case 6:
                printf("Masukkan jari-jari: ");
                scanf("%f",&radius);
                printf("Volume: %.2f\n", (4.0/3.0)*pi*radius*radius*radius);
                break;
            default:
                printf("Input tidak valid!\n");
            }
            break;
        
        //jika memilih akhiri
        case 3:
            printf("Program berakhir\n");
            return 0;

        //jika memilih selain 1,2,3
        default:
            printf("Input tidak valid!\n");
        }
    }

    //program berakhir
    return 0;
}
