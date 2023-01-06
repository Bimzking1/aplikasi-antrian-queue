/*
* Author     : Paulus Bimo Satrio Aji ~ ( 2110191019 )
* Created at : June 14, 2020
* Updated at : June 17, 2020
* A program to control patient queue in hospital using "Circular Queue with Arrays".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

 // STRUCT
typedef struct data pasien;
struct data{
    int nomor;
    char nama[30];
    char penyakit[30];
};

 // FUNGSI
void enqueue();
void dequeue();
void tampil();
int isEmpty();
int isFull();

 // ARRAY ANTRIAN with data type PASIEN
pasien antrian[MAX];

 // VARIABEL PEMBANTU
int front = 0;
int count = 0;
int rear = 0;
int pilih;
char lagi;

int main(){     // FUNGSI MAIN
    printf("    [\tFORM RUANG TUNGGU DOKTER THT\t]\n");
    printf("    [\t  RUMAH SAKIT SEHAT SELALOE\t]\n");
    do{
        printf("\n 1. Pasien Baru\n");
        printf(" 2. Panggil Pasien\n");
        printf(" 3. Daftar Pasien\n");
        printf(" Pilih = ");
        scanf("%d", &pilih);
        if (pilih == 1)
            enqueue();
        if (pilih == 2)
            dequeue();
        if (pilih == 3)
            tampil();
        printf("\n Akses lagi [y] - Tidak [t]\n Pilihan = ");
        fflush(stdin);
        scanf("%c", &lagi);
        fflush(stdin);
    }
    while (lagi == 'y' || lagi == 'Y');
    return 0;
}

void enqueue(){     // FUNGSI for MENAMBAH PASIEN
    if (isFull())
        printf("\n\t Sabar, ruang tunggu masih penuh !\n");
    else{
        printf("\n No. Antrian    = ");
        scanf("%d", &antrian[rear].nomor);
        printf(" Nama Pasien    = ");
        fflush(stdin);
        gets(antrian[rear].nama);
        fflush(stdin);
        printf(" Area penyakit  = ");
        fflush(stdin);
        gets(antrian[rear].penyakit);
        fflush(stdin);

        count++;
        rear++;
        if (rear >= MAX)
            rear = rear - MAX;
    }
}

 int isFull(){      // FUNGSI INDIKATOR FULL
    return count == MAX;
 }

void dequeue(){     // FUNGSI for MENGURANGI PASIEN
    int hapus_no;           // TEMP 1
    char hapus_nama[30];     // TEMP 2
    char hapus_penyakit[30]; // TEMP 3

    if (isEmpty())
        printf("\n\t Antrian kosong. Tidak ada pasien lagi.\n");
    else{
        printf("\n\t[*] Nomor %d. %s, silahkan masuk. [*]\n", antrian[front].nomor, antrian[front].nama);
        hapus_no = antrian[front].nomor;
        strcpy(hapus_nama, antrian[front].nama);
        strcpy(hapus_penyakit, antrian[front].penyakit);    // ASSIGNMENT VARIABLES to TEMPS

        antrian[front].nomor = 0;
        strcpy(antrian[front].nama, "");
        strcpy(antrian[front].penyakit, "");    // ASSIGNMENT TEMPS to VARIABLES

        front++;
        count--;
        if (front >= MAX)
            front = front - MAX;
    }
}

 int isEmpty(){     // FUNGSI INDIKATOR KOSONG
    return count == 0;
 }

void tampil(){      // FUNGSI UNTUK MENAMPILKAN OUTPUT
    int i, j = front; puts("");
    printf("  --------------------------------------------------------------");
    printf("\n |\t\t ANTRIAN RUMAH SAKIT SEHAT SELALOE \t\t|\n");
    printf("  --------------------------------------------------------------");
    printf("\n | No.\t|\tNama Pasien\t|\tGejala\t\t\t|\n");
    printf("  --------------------------------------------------------------\n");
        printf(" | %d\t|\t%s\t\t|\t%s\t\t|\n", antrian[j].nomor, antrian[j].nama, antrian[j].penyakit);
    for (i = 0; i < count; i++){
        j++;
        if (j > MAX)
            j = j - MAX;
    }
    printf("  --------------------------------------------------------------\n");
}
