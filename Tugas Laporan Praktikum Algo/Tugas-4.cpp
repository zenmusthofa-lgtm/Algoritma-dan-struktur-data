#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int hitungJarakTerjauh(Node* root, int& max_dist) {
    if (root == nullptr) {
        return 0;
    }
    
    int kiri = hitungJarakTerjauh(root->left, max_dist);
    int kanan = hitungJarakTerjauh(root->right, max_dist);
    
    max_dist = max(max_dist, kiri + kanan);
    
    return 1 + max(kiri, kanan);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val); 
    }
    
    int jarak_maksimum = 0;
    hitungJarakTerjauh(root, jarak_maksimum);
    
    cout << jarak_maksimum << "\n";
    
    return 0;
}