/*
Nama: Muhammad Regan Azfar Azizan
NIM: L0125054
*/

#include <stdio.h>

int main(){
    //deklarasi data
    char nama_barang[20]; //menyiapkan ruang untuk 19 karakter dan 1 \0 (terminator)
    int jumlah_barang, harga_barang, total_harga;
    float harga_setelah_diskon;

    //input dari pengguna
    printf("Nama barang: ");
    scanf("%s",nama_barang);
    
    printf("Jumlah barang: ");
    scanf("%d",&jumlah_barang);

    printf("Harga per unit: ");
    scanf("%d",&harga_barang);

    total_harga = jumlah_barang * harga_barang; //menghitung total harga

    //output
    printf("\n====== Rincian Pembelian ======\n");
    printf("Nama barang: %s\n",nama_barang);
    printf("Jumlah barang: %d\n",jumlah_barang);
    printf("Harga per unit: Rp %d\n",harga_barang);
    printf("Total harga: Rp %d\n",total_harga);

    //kalau harga diatas 100000 maka ada diskon 10%
    if (total_harga > 100000){
        harga_setelah_diskon = 0.9*total_harga; //pake 0.9 karna kalau 90/100 hasilnya bakal dibuletin jadi 0
        printf("Harga setelah diskon: %.0f",harga_setelah_diskon); //pake .0f supaya hasilnya jadi bilangan bulat
    }
    return 0;
}