#include <iostream>

using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;

void tampilkanList() {
    if (head == NULL) {
        cout << "Isi Linked List: [ Kosong ]\n";
        return;
    }
    
    Node* current = head;
    cout << "Isi Linked List: ";
    while (current != NULL) {
        cout << current->nilai;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL\n";
}

void tambahDepan(int nilaiBaru) {
    Node* newNode = new Node();
    newNode->nilai = nilaiBaru;
    newNode->next = head;
    head = newNode;
    tampilkanList();
}

void tambahBelakang(int nilaiBaru) {
    Node* newNode = new Node();
    newNode->nilai = nilaiBaru;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    tampilkanList();
}

void tambahSetelah(int targetNilai, int nilaiBaru) {
    Node* current = head;
    
    while (current != NULL && current->nilai != targetNilai) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Masukkan nilai yang ingin dicari: " << targetNilai << "\n";
        cout << "[Gagal] Node dengan nilai " << targetNilai << " tidak ditemukan.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->nilai = nilaiBaru;
    newNode->next = current->next;
    current->next = newNode;

    tampilkanList();
}

void hapusNode(int nilaiHapus) {
    if (head == NULL) {
        cout << "[Gagal] Linked List kosong.\n";
        return;
    }

    if (head->nilai == nilaiHapus) {
        Node* temp = head;
        head = head->next;
        delete temp;
        tampilkanList();
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->nilai != nilaiHapus) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << "[Gagal] Node dengan nilai " << nilaiHapus << " tidak ditemukan.\n";
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    tampilkanList();
}

int main() {
    int pilihan, nilaiBaru, targetNilai, nilaiHapus;

    do {
        cout << "\n====== MENU SINGLE LINKED LIST ======\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilaiBaru;
                tambahDepan(nilaiBaru);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilaiBaru;
                tambahBelakang(nilaiBaru);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> targetNilai;
                tambahSetelah(targetNilai, nilaiBaru);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilaiHapus;
                hapusNode(nilaiHapus);
                break;
            case 5:
                tampilkanList();
                break;
            case 0:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}