#include <stdio.h>
#include <math.h>

void jumlah_kurang_kali_bagi(){     //fungsi jumlah kurang kali bagi
    int pilihan, N;
    float hasil;

    printf("Pilih salah satu\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\nInput dengan angka: ");
    scanf("%d", &pilihan);  //user memilih 1 sampai 4

    printf("Mau berapa angka?: ");
    scanf("%d", &N);

    float arr[N];   //inisialisasi array sebesar N
    printf("Masukkan angka dibawah sebanyak %d kali:\n", N);
    for (int i = 0; i < N; i++){
        scanf("%f", &arr[i]);   //simpan elemen ke array dengan looping sebanyak N kali
    }

    switch (pilihan){
    case 1: //penjumlahan
        for (int i = 0; i < N; i++){
            hasil += arr[i];    //looping untuk menjumlahkan elemen ke i dan disimpan ke hasil
        }
        break;
    case 2: //pengurangan
        hasil = arr[0]; //set hasil menjadi array elemen ke nol karena kalau hasil 0, indeks pertama jadi mines
        for (int i = 1; i < N; i++){    //looping dimulai dari iterasi 1 karena hasil sudah di set ke array[0]
            hasil -= arr[i]; 
        }
        break;
    case 3: //perkalian
        hasil = 1;  //set hasil ke 1 karena kalau hasil 0, hasil semua perkaliannya jadi 0
        for (int i = 0; i < N; i++){
            hasil *= arr[i]; 
        }
        break;
    case 4: //pembagian
        hasil = arr[0]; //set hasil ke array[0] karena kalau hasil 0, hasil semua pembagian jadi 0
        for (int i = 1; i < N; i++){
            if (arr[i] != 0){
                hasil /= arr[i];
            } else {    //jaga-jaga kalau ada elemen yang bernilai 0
                printf("Tidak bisa dibagi dengan nol!\n");
                return; //keluar dari fungsi
            }
        }
        break;
    default:
        printf("Angka tidak valid!\n"); //jika input pilihan diluar 1-4
        return; //keluar dari fungsi
    }
    printf("Hasil: %.4f\n", hasil); //cetak hasil
}

float perpangkatan(float x, int n){ //fungsi perpangkatan dengan 2 parameter, x sebagai bilangan, dan n sebagai pangkat
    if (n == 0){    //jika pangkatnya 0, kembalikan 1
        return 1;
    } else if (n > 0){  //jika pangkat positif, kembalikan x * panggil fungsi kembali dengan n dikurangi 1
        return x * perpangkatan(x, n-1);
    } else {    //jika pangkat negatif, kembalikan 1 / panggil fungsi kembali dengan n dikali mines (dijadikan positif) sehingga kembali ke jika pangkat positif
        return 1/perpangkatan(x, -n);
    }
}

int faktorial(int x){   //fungsi faktorial dengan parameter x sebagai bilangan yang akan difaktorialkan
    if (x == 0){    //jika x = 0, kembalikan 1
        return 1;
    }
    return x * faktorial(x-1);  //kembalikan x * panggil fungsi kembali dengan x dikurangi 1
}

int main(){ //fungsi utama
    int pilihan;

    while (1){  //looping
        puts("===== Kalkulator Sederhana =====");
        puts("1. Penjumlahan, Pengurangan, Perkalian, Pembagian");
        puts("2. Perpangkatan");
        puts("3. Faktorial");
        puts("4. Akar Kuadrat");
        puts("5. Trigonometri (menghasil sin cos tan dari input derajat)");
        puts("6. Pembulatan Nilai (ceil dan floor)");
        puts("7. Exit");
        printf("Input dengan angka: ");
        scanf("%d", &pilihan);  //user memilih 1-7

        switch (pilihan){
            case 1:{    //panggil fungsi ini jika user memilih diantara penjumlahan, pengurangan, perkalian, pembagian
                jumlah_kurang_kali_bagi();
                break;
            }
            case 2:{    //perpangkatan
                float bilangan;
                int pangkat;

                printf("Masukkan bilangan dan pangkat: ");
                scanf("%f %d", &bilangan, &pangkat);    //user memasukkan bilangan dan pangkatnya, dipisah dengan spasi

                printf("Hasil: %.4f\n", perpangkatan(bilangan, pangkat));   //panggil fungsi perpangkatan
                break;
            }
            case 3:{    //faktorial
                int bilangan;

                printf("Masukkan bilangan: ");
                scanf("%d", &bilangan); //user memasukkan bilangan yang ingin difaktorialkan

                printf("Hasil: %d\n", faktorial(bilangan)); //panggil fungsi faktorial
                break;
            }
            case 4:{    //akar kuadrat
                double bilangan;

                printf("Masukkan bilangan: ");
                scanf("%lf", &bilangan);    //user memasukkan bilangan yang ingin diakar

                printf("Hasil: %.4lf\n", sqrt(bilangan));   //cetak memakai fungsi bawaan math.h
                break;
            }
            case 5:{    //trigonometri
                double derajat, radian;

                printf("Masukkan derajat: ");
                scanf("%lf", &derajat); //user memasukkan derajat
                radian = derajat * 3.14159265358979323846 / 180;    //mengubah derajat menjadi radian karena fungsi sin cos tan menghitung radian
                printf("Sin: %.2lf\nCos: %.2lf\nTan: %.2lf\n", sin(radian), cos(radian), tan(radian)); //cetak memakai fungsi bawaan math.h
                break;
            }
            case 6:{    //ceiling atau floor
                double bilangan;

                printf("Masukkan bilangan: ");
                scanf("%lf", &bilangan); //user memasukkan bilangan yang ingin dibulatkan

                printf("Keatas: %.0lf\nKebawah: %.0lf\n", ceil(bilangan), floor(bilangan)); //cetak memakai fungsi bawaan math.h
                break;
            }
            case 7:{    //user memilih exit
                puts("Program Berakhir");
                return 0;   //akhiri program
            }
            default:{
                printf("Angka tidak valid!\n"); //jika input diluar 1-7
                break;
            }
        }
    }
}
