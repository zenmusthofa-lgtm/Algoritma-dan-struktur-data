#include <iostream>
#define max 10
using namespace std;

struct Stack {
    int atas;
    int data[max];
} Tumpuk;

int kosong() {
    if (Tumpuk.atas == -1) return 1;
    else return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1) return 1;
    else return 0;
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack " << endl;
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack " << endl;
    }
    else {
        cout << "Tumpukan Penuh" << endl;
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil" << endl;
        Tumpuk.atas--;
    }
    else {
        cout << " Data Kosong" << endl;
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    }
    else {
        cout << "Tumpukan Kosong" << endl;
    }
}

int main() {

    Tumpuk.atas = -1; 

    input(10);
    input(20);
    input(30);
    cout << endl;

    tampil();
    cout << endl;

    hapus();
    cout << endl;

    tampil();
    cout << endl;

    bersih();

    return 0;
}