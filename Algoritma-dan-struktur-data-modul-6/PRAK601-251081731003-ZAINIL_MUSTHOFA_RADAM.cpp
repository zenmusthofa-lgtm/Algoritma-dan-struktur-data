#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void Sequential()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for(int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\nDone. \n");

    for(int i = 0; i < 100; i++)
    {
        if(data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d! \n", counter);
        printf("pada indeks ke = %d", save);
    }
    else
    {
        printf("Data tidak ada! \n");
    }
}

void binary()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int *angka = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "=========================================================================\n";
    cout << "Data yang telah diurutkan adalah : \n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n=========================================================================\n";
    cout << "Masukkan angka yang dicari : ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
    {
        cout << "Angka ditemukan pada indeks : " << tengah << "!\n";
    }
    else
    {
        cout << "Angka tidak ditemukan!";
    }

    delete[] angka;
}

void tiga()
{
    cout << "PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING\n";

    cout << "\n[1] Sequential Searching (Linear)\n";
    cout << "------------------------------------------------------------------\n";
    cout << "Pengertian  : Metode pencarian dengan memindai setiap elemen array\n";
    cout << "              secara runtut dari awal hingga data target ditemukan.\n";
    cout << "Kelebihan : Sangat fleksibel memproses data acak\n";
    cout << "            Struktur logika sederhana dan mudah dikodekan.\n";
    cout << "Kelemahan : Kurang efisien untuk data bervolume besar karena proses\n";
    cout << "            pemeriksaan dilakukan pada seluruh elemen secara berkala.\n";

    cout << "\n[2] Binary Searching (Biner)\n";
    cout << "------------------------------------------------------------------\n";
    cout << "Pengertian  : Metode pencarian yang membagi dua bagian data terus-menerus,\n";
    cout << "              lalu memilih bagian yang mungkin berisi data target.\n";
    cout << "Syarat : Data wajib dalam kondisi terstruktur/terurut (sorted).\n";
    cout << "Kelebihan : Komputasi jauh lebih cepat dan responsif saat mengolah\n";
    cout << "            kumpulan data skala masif.\n";
    cout << "Kelemahan : Ketergantungan penuh pada urutan data; tidak dapat dioperasikan\n";
    cout << "            pada susunan data acak.\n";
}

int main()
{
    int n;
    cout << "Pilih menu\n";
    cout << "1. Sequential Searching\n";
    cout << "2. Binary Searching\n";
    cout << "3. Jelaskan Perbedaan Sequential Searching dan Bnary Searching?\n";
    cout << "4. Exit\n";
    cout << "Pilih :\n";
    cin >> n;
    switch(n)
    {
        case 1 :
            Sequential();
            break;
        case 2 :
            binary();
            break;
        case 3 :
            tiga();
        default :
            break;
    }
}