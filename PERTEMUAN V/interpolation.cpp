#include <iostream>
#include <algorithm>
#include <cmath>    
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data ascending
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi = -1;
    float posisi1;

    // Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        // Cegah pembagian dengan nol jika data[low] == data[high]
        if (data[low] == data[high]) {
            if (data[low] == cari) {
                posisi = low;
                flag = 1;
            }
            break;
        }

        // Rumus Interpolation Search yang benar
        posisi1 = low + ((float)(cari - data[low]) / (data[high] - data[low])) * (high - low);
        posisi = floor(posisi1);

        cout << "Posisi perkiraan: " << posisi1 << " -> dibulatkan ke " << posisi << endl;

        if (data[posisi] == cari) {
            flag = 1;
            break;
        }

        if (data[posisi] < cari) {
            low = posisi + 1;
        } else {        
            high = posisi - 1;
        }
    }
    
    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}