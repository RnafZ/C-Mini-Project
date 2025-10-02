#include <stdio.h>

int main(){
    int nomor_akun;
    float batas_kredit, saldo;

    for (int i = 1; i <= 3; i++){
        printf("\nMasukkan nomor akun, batas kredit, dan saldo: ");
        scanf("%d %f %f", &nomor_akun, &batas_kredit, &saldo);

        float batas_kredit_baru = batas_kredit * 0.5;
        printf("\nPelanggan ke-%d:", i);
        printf("\nNomor akun: %d", nomor_akun);
        printf("\nBatas kredit sebelum resesi: %.0f", batas_kredit);
        printf("\nBatas kredit baru: %.0f", batas_kredit * 0.5);
        printf("\nSaldo: %.0f", saldo);

        if (saldo > batas_kredit_baru)
            printf("\nSALDO MELEBIHI BATAS KREDIT\n");
        else
            printf("\nSALDO KURANG DARI ATAU SAMA DENGAN BATAS KREDIT\n");
    }
}