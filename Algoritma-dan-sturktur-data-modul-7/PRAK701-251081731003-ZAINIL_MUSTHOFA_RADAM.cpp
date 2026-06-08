#include <conio.h> 
#include <stdlib.h> 
#include <iostream>

using namespace std;

struct Node
{
    int data; 
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru)
{
    if (*root == NULL)
    {
        Node *baru; 
        baru = new Node;
        baru->data = databaru; 
        baru->kiri = NULL; 
        baru->kanan = NULL; 
        (*root) = baru;
        cout << "\nData berhasil ditambahkan!";
    }
    else if (databaru < (*root)->data) 
    tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data) 
    tambah(&(*root)->kanan, databaru);
    else if (databaru == (*root)->data) 
    cout << "\nData sudah ada.";
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " "; 
        preOrder(root->kiri); 
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << " "; 
        inOrder(root->kanan);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri); 
        postOrder(root->kanan); 
        cout << root->data << " ";
    }
}

void hapus(Node *root)
{
    if (root != NULL)
    {
        hapus(root -> kiri); 
        hapus (root -> kanan); 
        delete root;
    }
}

int main()
{
    int pil, data; 
    Node *pohon; 
    pohon = NULL;

    do
    {
        system("cls");
        cout << "=== BINARY SEARCH TREE ===" << endl;
        cout << "1. Tambah Data" << endl; 
        cout << "2. PreOrder" << endl; 
        cout << "3. InOrder" << endl; 
        cout << "4. PostOrder" << endl; 
        cout << "5. Exit" << endl;
        cout << "=========================" << endl;
        cout << "Pilihan : "; 
        cin >> pil;

        switch (pil)
        {
        case 1:
        cout << "\n=== INPUT DATA ===" << endl;
        cout << "Data baru : ";
        cin >> data; 
        tambah(&pohon, data); 
        cout << endl;
        break;

    case 2:
        cout << "\n=== PREORDER TRAVERSAL ===" << endl;
        if (pohon != NULL)
        {
            cout << "Hasil : "; 
            preOrder(pohon); 
            cout << endl;
        }
        else
            cout << "Tree masih kosong!" << endl;
        break;

        case 3:
            cout << "\n=== INORDER TRAVERSAL ===" << endl;
            if (pohon != NULL)
            {
                cout << "Hasil : "; 
                inOrder(pohon); 
                cout << endl;
            }
            else
            cout << "Tree masih kosong!" << endl;
        break;

    case 4:
        cout << "\n=== POSTORDER TRAVERSAL ===" << endl;
        if (pohon != NULL)
        {
            cout << "Hasil : "; 
            postOrder(pohon); 
            cout << endl;
        }
        else
            cout << "Tree masih kosong!" << endl;
        break;

    case 5:
        hapus(pohon);
        cout << "\nTerima kasih! Program selesai." << endl;
        cout << "Program was made by Zainil Musthofa Radam"<< endl;
        cout << endl; 
        break;

    default:
        cout << "\nPilihan tidak valid!" << endl;
        break;
    }

        if (pil != 5)
    {
        cout << "\nTekan sembarang tombol untuk melanjutkan...";
        getch();
    }

} while (pil != 5);

return 0;
}