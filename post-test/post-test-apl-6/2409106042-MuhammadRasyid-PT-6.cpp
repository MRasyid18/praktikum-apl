#include <iostream>
using namespace std;

#define MAX_KAMAR 100

struct Penghuni {
    string nama;
    string umur;
    string kamar;
};

struct Datakost {
    Penghuni penghuni[MAX_KAMAR];
    int panjang = 0;
};

// Fungsi login
bool login(string *nama, string *nim) {
    return *nama == "rasyid" && *nim == "042";
}

// Fungsi menampilkan data
void tampilkanData(Datakost *data) {
    if (data->panjang == 0) {
        cout << "Belum ada pesanan\n" << endl;
    } else {
        cout << "No  Nama                Umur                 Kamar" << endl;
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < data->panjang; i++) {
            cout << i + 1 << "   " << data->penghuni[i].nama;
            for (int j = data->penghuni[i].nama.length(); j < 20; j++) cout << " ";
            cout << data->penghuni[i].umur;
            for (int j = data->penghuni[i].umur.length(); j < 20; j++) cout << " ";
            cout << data->penghuni[i].kamar << endl;
        }
    }
}

// Fungsi menambah data
void tambahData(Datakost *data) {
    if (data->panjang < MAX_KAMAR) {
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, data->penghuni[data->panjang].nama);
        cout << "Masukkan umur: ";
        getline(cin, data->penghuni[data->panjang].umur);
        cout << "Masukkan nomor kamar: ";
        getline(cin, data->penghuni[data->panjang].kamar);
        data->panjang++;
        cout << "Data pesanan berhasil ditambahkan\n" << endl;
    } else {
        cout << "Kapasitas penuh! Tidak bisa menambah penghuni lagi.\n" << endl;
    }
}

// Fungsi mengubah data
void ubahData(Datakost *data) {
    if (data->panjang == 0) {
        cout << "Belum ada kamar untuk diubah." << endl;
    } else {
        tampilkanData(data);
        int index;
        cout << "Masukkan nomor data yang akan diubah: ";
        cin >> index;
        if (index > 0 && index <= data->panjang) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, data->penghuni[index - 1].nama);
            cout << "Masukkan umur baru: ";
            getline(cin, data->penghuni[index - 1].umur);
            cout << "Masukkan nomor kamar baru: ";
            getline(cin, data->penghuni[index - 1].kamar);
            cout << "Data berhasil diubah" << endl;
        } else {
            cout << "Nomor tidak valid" << endl;
        }
    }
}

// Fungsi menghapus data
void hapusData(Datakost *data) {
    if (data->panjang == 0) {
        cout << "Belum ada kamar untuk dihapus.\n" << endl;
    } else {
        tampilkanData(data);
        int index;
        cout << "Masukkan nomor data yang akan dihapus: ";
        cin >> index;
        if (index > 0 && index <= data->panjang) {
            for (int i = index - 1; i < data->panjang - 1; i++) {
                data->penghuni[i] = data->penghuni[i + 1];
            }
            data->panjang--;
            cout << "Data berhasil dihapus\n" << endl;
        } else {
            cout << "Nomor tidak valid\n" << endl;
        }
    }
}

// Fungsi reset panjang
void resetPanjang(Datakost &data) {
    data.panjang = 0;
    cout << "Semua data penghuni telah direset!" << endl;
}

// Sorting Nama menggunakan SELECTION SORT (Descending)
void sortNamaDescending(Datakost *data) {
    for (int i = 0; i < data->panjang - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < data->panjang; j++) {
            if (data->penghuni[j].nama > data->penghuni[maxIdx].nama) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(data->penghuni[i], data->penghuni[maxIdx]);
        }
    }
    cout << "Data telah diurutkan berdasarkan Nama (Z-A) menggunakan Selection Sort." << endl;
}

// Sorting Umur menggunakan INSERTION SORT (Ascending)
void sortUmurAscending(Datakost *data) {
    for (int i = 1; i < data->panjang; i++) {
        Penghuni key = data->penghuni[i];
        int j = i - 1;
        while (j >= 0 && stoi(data->penghuni[j].umur) > stoi(key.umur)) {
            data->penghuni[j + 1] = data->penghuni[j];
            j--;
        }
        data->penghuni[j + 1] = key;
    }
    cout << "Data telah diurutkan berdasarkan Umur (Ascending) menggunakan Insertion Sort." << endl;
}

// Sorting Kamar menggunakan BUBBLE SORT (Ascending)
void sortKamarAscending(Datakost *data) {
    for (int i = 0; i < data->panjang - 1; i++) {
        for (int j = 0; j < data->panjang - i - 1; j++) {
            if (data->penghuni[j].kamar > data->penghuni[j + 1].kamar) {
                swap(data->penghuni[j], data->penghuni[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan berdasarkan Nomor Kamar (Ascending) menggunakan Bubble Sort." << endl;
}

// Main Program
int main() {
    Datakost data;
    string inputNama, inputNim;
    int maksimalpercobaan = 3;
    int pilihan;

    for (int percobaan = 1; percobaan <= maksimalpercobaan; percobaan++) {
        cout << "=== LOGIN ===" << endl;
        cout << "Masukkan nama: ";
        cin >> inputNama;
        cout << "Masukkan NIM (3 digit angka): ";
        cin >> inputNim;

        if (login(&inputNama, &inputNim)) {
            cout << "Login berhasil! Selamat datang, " << inputNama << endl;
            do {
                cout << "\nMANAJEMEN PEMESANAN KAMAR KOST PUTRA\n" << endl;
                cout << "1. Tampilkan Data Kost" << endl;
                cout << "2. Tambah Data Penghuni" << endl;
                cout << "3. Ubah Data Penghuni" << endl;
                cout << "4. Hapus Data Penghuni" << endl;
                cout << "5. Reset Semua Data" << endl;
                cout << "6. Sorting Nama (Descending)" << endl;
                cout << "7. Sorting Umur (Ascending)" << endl;
                cout << "8. Sorting Kamar (Ascending)" << endl;
                cout << "9. Keluar Dari Program" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: tampilkanData(&data); break;
                    case 2: tambahData(&data); break;
                    case 3: ubahData(&data); break;
                    case 4: hapusData(&data); break;
                    case 5: resetPanjang(data); break;
                    case 6: 
                        sortNamaDescending(&data); 
                        tampilkanData(&data);
                        break;
                    case 7: 
                        sortUmurAscending(&data);
                        tampilkanData(&data);
                        break;
                    case 8: 
                        sortKamarAscending(&data);
                        tampilkanData(&data);
                        break;
                    case 9: cout << "Keluar dari program" << endl; break;
                    default: cout << "Pilihan tidak valid" << endl; break;
                }
            } while (pilihan != 9);

            return 0;
        } else {
            cout << "\nNama atau NIM yang anda masukkan salah! Percobaan tersisa: "
                << maksimalpercobaan - percobaan << endl;
        }
    }
    cout << "\nAnda telah gagal login 3 kali. Program berhenti." << endl;
    return 0;
}
