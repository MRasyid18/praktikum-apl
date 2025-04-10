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

bool login(string nama, string nim) {
    return nama == "rasyid" && nim == "042";
}

void tampilkanData(Datakost &data) {
    if (data.panjang == 0) {
        cout << "Belum ada pesanan\n" << endl;
    } else {
        cout << "No  Nama                Umur                 Kamar" << endl;
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < data.panjang; i++) {
            cout << i + 1 << "   " << data.penghuni[i].nama;
            for (int j = data.penghuni[i].nama.length(); j < 20; j++) cout << " ";
            cout << data.penghuni[i].umur;
            for (int j = data.penghuni[i].umur.length(); j < 20; j++) cout << " ";
            cout << data.penghuni[i].kamar << endl;
        }
    }
}

void tambahData(Datakost &data) {
    if (data.panjang < MAX_KAMAR) {
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, data.penghuni[data.panjang].nama);
        cout << "Masukkan umur: ";
        getline(cin, data.penghuni[data.panjang].umur);
        cout << "Masukkan nomor kamar: ";
        getline(cin, data.penghuni[data.panjang].kamar);
        data.panjang++;
        cout << "Data pesanan berhasil ditambahkan\n" << endl;
    } else {
        cout << "Kapasitas penuh! Tidak bisa menambah penghuni lagi.\n" << endl;
    }
}

void ubahData(Datakost &data) {
    if (data.panjang == 0) {
        cout << "Belum ada kamar untuk diubah." << endl;
    } else {
        tampilkanData(data);
        int index;
        cout << "Masukkan nomor kamar yang akan diubah: ";
        cin >> index;
        if (index > 0 && index <= data.panjang) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, data.penghuni[index - 1].nama);
            cout << "Masukkan umur baru: ";
            getline(cin, data.penghuni[index - 1].umur);
            cout << "Masukkan nomor kamar baru: ";
            getline(cin, data.penghuni[index - 1].kamar);
            cout << "Kamar berhasil diubah" << endl;
        } else {
            cout << "Nomor kamar tidak valid" << endl;
        }
    }
}

void hapusData(Datakost &data) {
    if (data.panjang == 0) {
        cout << "Belum ada kamar untuk dihapus.\n" << endl;
    } else {
        tampilkanData(data);
        int index;
        cout << "Masukkan nomor kamar yang akan dihapus: ";
        cin >> index;
        if (index > 0 && index <= data.panjang) {
            for (int i = index - 1; i < data.panjang - 1; i++) {
                data.penghuni[i] = data.penghuni[i + 1];
            }
            data.panjang--;
            cout << "Kamar berhasil dihapus\n" << endl;
        } else {
            cout << "Nomor kamar tidak valid\n" << endl;
        }
    }
}

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

        if (login(inputNama, inputNim)) {
            cout << "Login berhasil! Selamat datang, " << inputNama << endl;
            do {
                cout << "\nMANAJEMEN PEMESANAN KAMAR KOST PUTRA\n" << endl;
                cout << "1. Tampilkan Data Kost" << endl;
                cout << "2. Tambah Data Pelanggan/penghuni" << endl;
                cout << "3. Ubah Data Pelanggan/penghuni" << endl;
                cout << "4. Hapus Data Pelanggan/penghuni" << endl;
                cout << "5. Keluar Dari Program" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: tampilkanData(data); break;
                    case 2: tambahData(data); break;
                    case 3: ubahData(data); break;
                    case 4: hapusData(data); break;
                    case 5: cout << "Keluar dari program" << endl; break;
                    default: cout << "Pilihan tidak valid" << endl; break;
                }
            } while (pilihan != 5);

            return 0;
        } else {
            cout << "\nNama atau NIM yang anda masukkan salah! Percobaan tersisa: "
                << maksimalpercobaan - percobaan << endl;
        }
    }
    cout << "\nAnda telah gagal login 3 kali. Program berhenti." << endl;
    return 0;
}