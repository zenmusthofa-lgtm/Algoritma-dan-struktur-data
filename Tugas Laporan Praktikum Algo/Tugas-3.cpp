#include <iostream>
#include <algorithm> 

using namespace std;

int fungsi_lower_bound(int arr[], int low, int high, int target) {
    int hasil = high + 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            hasil = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return hasil;
}

int fungsi_upper_bound(int arr[], int low, int high, int target) {
    int hasil = high + 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            hasil = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return hasil;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    if (!(cin >> N >> X)) return 0;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int total_pasangan = 0;

    for (int i = 0; i < N - 1; i++) {
        int target_cari = X - arr[i];

        int batas_bawah = i + 1;
        int batas_atas = N - 1;

        int low_idx = fungsi_lower_bound(arr, batas_bawah, batas_atas, target_cari);
        int high_idx = fungsi_upper_bound(arr, batas_bawah, batas_atas, target_cari);

        total_pasangan += (high_idx - low_idx);
    }

    cout << total_pasangan << "\n";

    delete[] arr;

    return 0;
}