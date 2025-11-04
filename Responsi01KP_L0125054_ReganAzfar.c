#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[10];
    char asal[15];
    char tujuan[15];
    int jumlah_kursi;
    int nomor_kursi[10];
    char kode[10];
} Pesanan;

Pesanan daftar_pesanan[100];
int jumlah_pesanan = 0;
int kursi_terisi[28] = {0};

void generateKode(char *kode) {
    static int counter = 1;
    sprintf(kode, "JI%03d", counter++);
}

void pesanTiket(char *nama_pemesan, int *jumlah_kursi_dipesan) {
    int sisa_kursi = 0;
    for (int i = 0; i < 28; i++) {
        if (kursi_terisi[i] == 0) {
            sisa_kursi++;
        }
    }
    if (sisa_kursi < *jumlah_kursi_dipesan) {
        puts("Maaf, kursi sudah penuh");
        return;
    }
    Pesanan *p = &daftar_pesanan[jumlah_pesanan];
    generateKode(p->kode);
    strcpy(p->nama, nama_pemesan);
    p->jumlah_kursi = *jumlah_kursi_dipesan;

    char jurusan[10][15] = {
        "Jakarta", "Bekasi", "Cikarang", "Karawang", "Cikampek",
        "Semarang", "Solo", "Ponorogo", "Tulungagung", "Malang",
    };
    char kota_asal[15];
    char kota_tujuan[15];

    int asal_valid, tujuan_valid;
    while (1) {
        asal_valid = 0;
        tujuan_valid = 0;

        printf("Kota asal: ");
        scanf("%s", kota_asal);

        printf("Kota tujuan: ");
        scanf("%s", kota_tujuan);

        for (int i = 0; i < 10; i++) {
            if (strcmp(kota_asal, jurusan[i]) == 0) asal_valid = 1;
            if (strcmp(kota_tujuan, jurusan[i]) == 0) tujuan_valid = 1;
        }

        if (asal_valid && tujuan_valid) {
            strcpy(p->asal, kota_asal);
            strcpy(p->tujuan, kota_tujuan);
            break;
        }

        puts("Jurusan tidak valid, coba lagi!\n");
    }
    printf("\n");
    for (int i = 0; i < 28; i++) {
        printf("%2d [%d]\t", i + 1, kursi_terisi[i]);
        if ((i + 1) % 2 == 0) printf("\n");
    }
    puts("Ket: 0 = kosong, 1 = terisi\n");

    printf("Masukkan nomor kursi yang ingin dipesan (%d kursi)\n", *jumlah_kursi_dipesan);
    for (int i = 0; i < *jumlah_kursi_dipesan; i++) {
        int nomor;
        printf("Pilih kursi ke-%d: ", i+1);
        scanf("%d", &nomor);

        if (nomor < 1 || nomor > 28 || kursi_terisi[nomor - 1] == 1) {
            puts("Nomor kursi tidak valid atau sudah dipesan!");
            i--;
            continue;
        }
        kursi_terisi[nomor - 1] = 1;
        p->nomor_kursi[i] = nomor;
        printf("Kursi nomor %d berhasil dipesan!\n", nomor);
    }
    printf("\n=== Pemesanan Berhasil ===\n");
    printf("Kode Pesanan: %s\n", p->kode);
    jumlah_pesanan++;
}

int cariPesanan(char *kode_dicari, int i) {
    if (i >= jumlah_pesanan)
        return -1;
    if (strcmp(daftar_pesanan[i].kode, kode_dicari) == 0)
        return i;
    return cariPesanan(kode_dicari, i + 1);
}

int main() {
    int pilihan;

    char *nama_pemesan = (char *)malloc(10 * sizeof(char));
    int *jumlah_kursi_dipesan = (int *)malloc(sizeof(int));

    while (1) {
        puts("\n=== Selamat Datang di PO Juragan Indah ===\n");

        puts("PO Juragan Indah merupakan sebuah perusahaan otobus antar kota antar provinsi (AKAP)");
        puts("jurusan Jakarta-Malang yang siap melayani dan mengantarkan anda ke berbagai tujuan.\n");

        puts("Jakarta-Malang: Bekasi, Cikarang, Karawang, Cikampek, Semarang, Solo,");
        puts("                Ponorogo, Tulungagung\n");

        puts("1. Pesan Tiket");
        puts("2. Cari Pesanan");
        puts("0. Exit");

        printf("Pilihanmu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            puts("Silahkan isi data dibawah");

            printf("Nama pemesan: ");
            scanf("%s", nama_pemesan);

            printf("Jumlah kursi yang ingin dipesan: ");
            scanf("%d", jumlah_kursi_dipesan);
            pesanTiket(nama_pemesan, jumlah_kursi_dipesan);
            break;
        case 2:
            char kode[10];
            printf("Masukkan kode pesananmu: ");
            scanf("%s", kode);

            int i = cariPesanan(kode, 0);
            if (i != -1) {
                Pesanan p = daftar_pesanan[i];
                printf("\n=== Detail Pesanan ===\n");
                printf("Nama Pemesan: %s\n", p.nama);
                printf("Kota Asal   : %s\n", p.asal);
                printf("Kota Tujuan : %s\n", p.tujuan);
                printf("Nomor Kursi : ");
                for (int i = 0; i < p.jumlah_kursi; i++) {
                    printf("%d ", p.nomor_kursi[i]);
                }
                printf("(%d kursi)", p.jumlah_kursi);
                printf("\n");
            }
            else {
                puts("\nPesanan tidak ditemukan!");
            }
            break;
        case 0:
            puts("Sampai jumpa di perjalanan berikutnya!");
            free(nama_pemesan);
            free(jumlah_kursi_dipesan);
            return 0;
        default:
            puts("Input tidak valid!");
            break;
        }
    }
}