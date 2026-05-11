#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>

void swap(char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}

std::string stringChange(std::string& str){
    std::string temp;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ' ') continue;
        if(str[i] >= 'A' && str[i]<='Z'){
            str[i] = str[i] - 'A' + 'a';
        }
        temp+=str[i];
    }
    return temp;
}

void insertionSort(std::string& str){
    for (int i = 1; i < str.size(); ++i) {
        char key = str[i];
        int j = i - 1;

        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }
}

void merge(std::string& str, int left, int middle, int right)
{

    int size_L = middle - left + 1;
    int size_R = right - middle;
    char L_Arr[size_L], R_Arr[size_R];

    for (int i = 0; i < size_L; ++i)
        L_Arr[i] = str[left + i];
    for (int j = 0; j < size_R; ++j)
        R_Arr[j] = str[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < size_L && j < size_R) {
        if (L_Arr[i] <= R_Arr[j]) {
            str[k] = L_Arr[i];
            ++i;
        }
        else {
            str[k] = R_Arr[j];
            ++j;
        }
        ++k;
    }

    while (i < size_L) {
        str[k] = L_Arr[i];
        ++i;
        ++k;
    }

    while (j < size_R) {
        str[k] = R_Arr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::string& str, int left, int right)
{
    if (left < right) {
        int middle = (left + right) / 2;

        mergeSort(str, left, middle);
        mergeSort(str, middle + 1, right);
        merge(str, left, middle, right);
    }
}

void shellSort(std::string& str, int size)
{
    for (int gap = size/2; gap > 0; gap /= 2)
    { 
        for (int i = gap; i < size; ++i)
        {
            char temp = str[i];
            int j;         
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap){
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

int partition(std::string& str, int low, int high){
    int pivot = str[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (str[j] < pivot) {
            ++i;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(std::string& str, int low, int high){
    if (low < high) {

        int pi = partition(str, low, high);

        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

void bubbleSort(std::string& str, int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void selectionSort(std::string& str, int size)
{
    int min_index;

    for (int i = 0; i < size-1; ++i)
    {
        min_index = i;
        for (int j = i+1; j < size; ++j){
          if (str[j] < str[min_index]){
            min_index = j;
          }
        }
           
        if(min_index != i){
            swap(str[min_index], str[i]);
        }
    }
}

bool cekValidNama(std::string& str){
    bool flag = true;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] < 'a' || str[i] > 'z'){
            flag = false;
            break;
        }
    }
    return flag;
}

bool cekValidNIM(std::string& str){
    bool flag = true;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] < '0' || str[i] > '9'){
            flag = false;
            break;
        } 
    }
    return flag;
}

int main(){
    char pil[1];
    int pilihan;
    std::string informasi;
    bool valid;
    do{
        std::cout<<"---------------------"<<std::endl;
        std::cout<<":      Sorting      :"<<std::endl;
        std::cout<<"---------------------"<<std::endl;
        std::cout<<"1. Insertion Sort"<<std::endl;
        std::cout<<"2. Merge sort"<<std::endl;
        std::cout<<"3. Shell Sort"<<std::endl;
        std::cout<<"4. Quick Sort"<<std::endl;
        std::cout<<"5. Bubble Sort"<<std::endl;
        std::cout<<"6. Selection Sort"<<std::endl;
        std::cout<<"7. Exit"<<std::endl;
        std::cout<<"Silahkan masukkan pilihan: ";
        std::cin >> pil;
        pilihan = atoi(pil);
        std::cin.ignore();

        valid = false;
        if(pilihan >= 1 && pilihan <= 3){
            while (!valid){
                std::cout << "Silahkan Masukkan Nama Anda: ";
                std::getline(std::cin, informasi); 
                informasi = stringChange(informasi);
                valid = cekValidNama(informasi);
                if(!valid){
                    std::cout<<"Nama Tidak Valid, Silahkan Coba Lagi"<<std::endl;
                }
            }
        } 
        
        else if (pilihan >= 4 && pilihan <= 6){
            while (!valid){
                std::cout<<"Silahkan Masukkan NIM Anda: ";
                std::getline(std::cin, informasi);
                valid = cekValidNIM(informasi);
                if(!valid){
                    std::cout<<"NIM Tidak Valid, Silahkan Coba Lagi"<<std::endl;
                }
            }
        }

        switch(pilihan){
            case 1:
                insertionSort(informasi);
                std::cout<<"Hasil sorting nama anda adalah: "<<informasi<<std::endl;
                break;
            case 2:
                mergeSort(informasi, 0, informasi.size()-1);
                std::cout<<"Hasil sorting nama anda adalah: "<<informasi<<std::endl;
                break;
            case 3:
                shellSort(informasi, informasi.size());
                std::cout<<"Hasil sorting nama anda adalah: "<<informasi<<std::endl;
                break;
            case 4:
                quickSort(informasi, 0, informasi.size()-1);
                std::cout<<"Hasil sorting NIM anda adalah: "<<informasi<<std::endl;
                break;
            case 5:
                bubbleSort(informasi, informasi.size());
                std::cout<<"Hasil sorting NIM anda adalah: "<<informasi<<std::endl;
                break;
            case 6:
                selectionSort(informasi, informasi.size());
                std::cout<<"Hasil sorting NIM anda adalah: "<<informasi<<std::endl;
                break;
            case 7:
                std::cout<<"Program was made by Zainil Musthofa Radam (2510817310013)."<<std::endl;
                break; 
            default:
                std::cout<<"Silahkan Coba Lagi"<<std::endl;
        }
        std::cout << "PRESS ANY KEY TO CONTINUE";
        getch();
        system("cls"); 
    } while (pilihan != 7);

    return 0;
}