#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahBelakangH();
void tampilkanH();
void hapusDepanH();
void hapusBelakangH();
void clearH();
void hapusTargetH();

void tambahDepanHT();
void tambahBelakangHT();
void tampilkanHT();
void hapusDepanHT();
void hapusBelakangHT();
void clearHT();
void hapusTargetHT();

void menuDLLNCHead();
void menuDLLNCHeadTail();

int main()
{
    menu :
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=======================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");
    
    if(menu == 1) {
        menuDLLNCHead();
        goto menu;
    } else if(menu == 2) {
        menuDLLNCHeadTail();
        goto menu;
    } else {
        cout << "\n TERIMA KASIH" << endl;
        cout << "Program was made by Zainil Musthofa Radam (2510817310013)" << endl;
    }
    return 0;
}

void menuDLLNCHead() {
    do {
        cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
        cout << "==============================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Reset" << endl;
        cout << "7. Hapus Berdasarkan Target" << endl; 
        cout << "8. Kembali ke Menu" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
            case 1: tambahDepanH(); break;
            case 2: tambahBelakangH(); break;
            case 3: tampilkanH(); break;
            case 4: hapusDepanH(); break;
            case 5: hapusBelakangH(); break;
            case 6: clearH(); break;
            case 7: hapusTargetH(); break;
            default: system("cls"); return;
        }
        cout << "\n press any key to continue" << endl;
        getch();
        system("cls");
    } while (pil < 8);
}

void menuDLLNCHeadTail() {
    do {
        cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
        cout << "=======================================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Reset" << endl;
        cout << "7. Hapus Berdasarkan Target" << endl; 
        cout << "8. Kembali ke Menu" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
            case 1: tambahDepanHT(); break;
            case 2: tambahBelakangHT(); break;
            case 3: tampilkanHT(); break;
            case 4: hapusDepanHT(); break;
            case 5: hapusBelakangHT(); break;
            case 6: clearHT(); break;
            case 7: hapusTargetHT(); break;
            default: system("cls"); return;
        }
        cout << "\n press any key to continue" << endl;
        getch();
        system("cls");
    } while (pil < 8);
}

void initH() { head = NULL; }
void initHT() { head = NULL; tail = NULL; }
int isEmptyH() { return (head == NULL) ? 1 : 0; }
int isEmptyHT() { return (tail == NULL) ? 1 : 0; }

void tambahDepanH() {
    cout << "Masukkan data : ";
    string inputLine;
    cin.ignore();
    getline(cin, inputLine);
    
    string temp[100];
    int count = 0;
    string kata = "";
    
    for(size_t i = 0; i <= inputLine.length(); i++) {
        if(i == inputLine.length() || inputLine[i] == ' ') {
            if(kata != "") {
                temp[count] = kata;
                count++;
                kata = "";
            }
        } else {
            kata += inputLine[i];
        }
    }
    
    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = temp[i];
        baru->next = NULL; baru->prev = NULL;
        if(isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH() {
    cout << "Masukkan data : ";
    string inputLine;
    cin.ignore();
    getline(cin, inputLine);
    
    string kata = "";
    for(size_t i = 0; i <= inputLine.length(); i++) {
        if(i == inputLine.length() || inputLine[i] == ' ') {
            if(kata != "") {
                TNode *baru = new TNode;
                baru->data = kata;
                baru->next = NULL; baru->prev = NULL;
                
                if(isEmptyH() == 1) {
                    head = baru;
                } else {
                    TNode *bantu = head;
                    while(bantu->next != NULL) { bantu = bantu->next; }
                    bantu->next = baru;
                    baru->prev = bantu;
                }
                kata = "";
            }
        } else {
            kata += inputLine[i];
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian belakang.";
}

void tampilkanH() {
    TNode *bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanH() {
    if(isEmptyH() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusBelakangH() {
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    int nTarget;
    cout << "Hapus node ke-berapa dari belakang? : ";
    cin >> nTarget;
    
    int totalNode = 0;
    TNode *bantu = head;
    while(bantu != NULL) { totalNode++; bantu = bantu->next; }
    
    TNode *hapus = head;
    if(nTarget >= totalNode) {
        hapus = head; 
    } else {
        bantu = head;
        while(bantu->next != NULL) { bantu = bantu->next; }
        for(int i = 1; i < nTarget; i++) {
            if(bantu->prev != NULL) bantu = bantu->prev;
        }
        hapus = bantu;
    }
    
    string data = hapus->data;
    if(hapus == head) {
        if(head->next != NULL) { head = head->next; head->prev = NULL; }
        else { initH(); }
    } else if(hapus->next == NULL) {
        hapus->prev->next = NULL;
    } else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }
    delete hapus;
    cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus.";
}

void clearH() {
    if(isEmptyH() == 1) {
        cout << "Seluruh data pada LInked List telah dibersihkan";
        return;
    }
    int noUrutan = 1;
    bool dariDepan = true;
    while(head != NULL) {
        TNode *hapus = NULL;
        if(dariDepan) {
            hapus = head;
            if(head->next != NULL) { head = head->next; head->prev = NULL; }
            else { head = NULL; }
        } else {
            TNode *ekor = head;
            while(ekor->next != NULL) { ekor = ekor->next; }
            hapus = ekor;
            if(ekor->prev != NULL) { ekor->prev->next = NULL; }
            else { head = NULL; }
        }
        cout << "Hapus urutan ke-" << noUrutan << " [Sisi " << (dariDepan ? "Depan" : "Belakang") << "]: " << hapus->data << endl;
        delete hapus;
        noUrutan++;
        dariDepan = !dariDepan;
    }
    initH();
    cout << "Seluruh data pada LInked List telah dibersihkan";
}

void hapusTargetH() {
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;
    
    TNode *bantu = head;
    bool ditemukan = false;
    while(bantu != NULL) {
        TNode *nextNode = bantu->next;
        if(bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;
            if(hapus == head) {
                if(head->next != NULL) { head = head->next; head->prev = NULL; }
                else { initH(); }
            } else if(hapus->next == NULL) {
                hapus->prev->next = NULL;
            } else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }
            delete hapus;
        }
        bantu = nextNode;
    }
    if(ditemukan) cout << "Semua data \"" << target << "\" telah berhasil dihapus.";
    else cout << "Data target \"" << target << "\" tidak ditemukan.";
}

void tambahDepanHT() {
    cout << "Masukkan data : ";
    string inputLine;
    cin.ignore();
    getline(cin, inputLine);
    
    string temp[100];
    int count = 0;
    string kata = "";
    for(size_t i = 0; i <= inputLine.length(); i++) {
        if(i == inputLine.length() || inputLine[i] == ' ') {
            if(kata != "") { temp[count] = kata; count++; kata = ""; }
        } else { kata += inputLine[i]; }
    }
    
    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = temp[i];
        baru->next = NULL; baru->prev = NULL;
        if(isEmptyHT() == 1) {
            head = baru; tail = baru;
        } else {
            baru->next = head; head->prev = baru; head = baru;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian depan.";
}

void tambahBelakangHT() {
    cout << "Masukkan data : ";
    string inputLine;
    cin.ignore();
    getline(cin, inputLine);
    
    string kata = "";
    for(size_t i = 0; i <= inputLine.length(); i++) {
        if(i == inputLine.length() || inputLine[i] == ' ') {
            if(kata != "") {
                TNode *baru = new TNode;
                baru->data = kata;
                baru->next = NULL; baru->prev = NULL;
                if(isEmptyHT() == 1) {
                    head = baru; tail = baru;
                } else {
                    tail->next = baru; baru->prev = tail; tail = baru;
                }
                kata = "";
            }
        } else { kata += inputLine[i]; }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan dibagian belakang.";
}

void tampilkanHT() {
    TNode *bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next; head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    int nTarget;
    cout << "Hapus node ke-berapa dari belakang? : ";
    cin >> nTarget;
    
    int totalNode = 0;
    TNode *bantu = head;
    while(bantu != NULL) { totalNode++; bantu = bantu->next; }
    
    TNode *hapus = tail;
    if(nTarget >= totalNode) {
        hapus = head;
    } else {
        hapus = tail;
        for(int i = 1; i < nTarget; i++) {
            if(hapus->prev != NULL) hapus = hapus->prev;
        }
    }
    
    string data = hapus->data;
    if(hapus == head) {
        if(head->next != NULL) { head = head->next; head->prev = NULL; }
        else { initHT(); }
    } else if(hapus == tail) {
        tail = tail->prev; tail->next = NULL;
    } else {
        hapus->prev->next = hapus->next; hapus->next->prev = hapus->prev;
    }
    delete hapus;
    cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus.";
}

void clearHT() {
    if(isEmptyHT() == 1) {
        cout << "Seluruh data pada Linked List telah dibersihkan";
        return;
    }
    int noUrutan = 1;
    bool dariDepan = true;
    while(head != NULL) {
        TNode *hapus = NULL;
        if(dariDepan) {
            hapus = head;
            if(head->next != NULL) { head = head->next; head->prev = NULL; }
            else { head = NULL; tail = NULL; }
        } else {
            hapus = tail;
            if(tail->prev != NULL) { tail = tail->prev; tail->next = NULL; }
            else { head = NULL; tail = NULL; }
        }
        cout << "Hapus urutan ke-" << noUrutan << " [Sisi " << (dariDepan ? "Depan" : "Belakang") << "]: " << hapus->data << endl;
        delete hapus;
        noUrutan++;
        dariDepan = !dariDepan;
    }
    initHT();
    cout << "Seluruh data pada Linked List telah dibersihkan";
}  

void hapusTargetHT() {
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;
    
    TNode *bantu = head;
    bool ditemukan = false;
    while(bantu != NULL) {
        TNode *nextNode = bantu->next;
        if(bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;
            if(hapus == head) {
                if(head->next != NULL) { head = head->next; head->prev = NULL; }
                else { initHT(); }
            } else if(hapus == tail) {
                tail = tail->prev; tail->next = NULL;
            } else {
                hapus->prev->next = hapus->next; hapus->next->prev = hapus->prev;
            }
            delete hapus;
        }
        bantu = nextNode;
    }
    if(ditemukan) cout << "Semua data \"" << target << "\" telah berhasil dihapus.";
    else cout << "Data target \"" << target << "\" tidak ditemukan.";
}