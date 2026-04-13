/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : I : OVERVIEW OF C LANGUAGE 
 *   Hari dan Tanggal    : Senin, 13 April 2026
 *   Nama (NIM)          : Imam Azkaziyan Ahmad (13224058)
 *   Nama File           : soal1.c
 *   Deskripsi           : Gerbang Koloni Bertingkat
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// fungsi untuk mengetahui angka atau tidak
int isDigit(int t) {
    return (t >= '0' && t <= '9');
}

// fungsi untuk kalkulasi hasil output
void calc (char *output, int izin, int suhu, int radiasi, int jam) {
    if (radiasi >= 6) {
        strcpy(output, "TOLAK");
    }
    else if (suhu >= 390) {
        strcpy(output, "KARANTINA");
    }
    else if (izin == 1 && (jam < 6 || jam > 20)) {
        strcpy(output, "TOLAK");
    }
    else if (izin == 1) {
        strcpy(output, "MASUK");
    }
    else if (izin == 2 && radiasi <= 2 && jam >= 8 && jam <= 18) {
        strcpy(output, "MASUK");
    }
    else if (izin == 2) {
        strcpy(output, "PEMERIKSAAN");
    }
    else if (izin == 3 && radiasi == 0 && suhu < 380) {
        strcpy(output, "MASUK");
    }
    else {
        strcpy(output, "TOLAK");
    }
}

// fungsi untuk separate input
void separate(char *input, int *izin, int *suhu, int *radiasi, int *jam) {
    // panjang karakter di input
    int len = strlen(input);

    int temp = 0;
    int s = 0;

    // menyalin dan memisahkan input berupa char ke variabel
    for(int i = 0; i < len; i++) {

        // jika digit maka akan ditambah
        if (isDigit(input[i])) {
            temp = temp * 10 + (input[i] - '0');
        }

        // jika bukan digit (spasi) masukn
        if (!isDigit(input[i]) || i == len - 1) {
            if (s == 0) *izin = temp;
            if (s == 1) *suhu = temp;
            if (s == 2) *radiasi = temp;
            if (s == 3) *jam = temp;

            s++;
            temp = 0;
        }
    }
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);

    // izin suhu radiasi jam
    int izin, radiasi, jam, suhu;

    separate(input, &izin, &suhu, &radiasi, &jam);

    // printf("%d\n", izin);
    // printf("%lf\n", suhu);
    // printf("%d\n", radiasi);
    // printf("%d\n", jam);

    // else if bertingkat dari soal
    char output[20];
    calc(output, izin, suhu, radiasi, jam);

    printf("%s", output);

    return 0;
}