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

int main() {
    Datakost data;
    string inputNama;
    string inputNim;
    int maksimalpercobaan = 3;
    int pilihan, index;

    // Login system
    for (int percobaan = 1; percobaan <= maksimalpercobaan; percobaan++) {
        cout << "=== LOGIN ===" << endl;
        cout << "Masukkan nama: ";
        cin >> inputNama;
        cout << "Masukkan NIM (3 digit angka): ";
        cin >> inputNim;

        if (inputNama == "rasyid" && inputNim == "042") {
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
                    case 1: // FITUR READ Melihat data penghuni kamar
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
                        break;

                    case 2: // FITUR CREATE Menambahkan data penghuni dan kamar
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
                        break;

                    case 3: // FITUR UPDATE Mengubah data penghuni
                        if (data.panjang == 0) {
                            cout << "Belum ada kamar untuk diubah." << endl;
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
                        break;

                    case 4: // FITUR DELETE Menghapus data penghuni
                        if (data.panjang == 0) {
                            cout << "Belum ada kamar untuk dihapus.\n" << endl;
                        } else {
                            cout << "No  Nama                umur                 Kamar" << endl;
                            cout << "----------------------------------------------------" << endl;
                            for (int i = 0; i < data.panjang; i++) {
                                cout << i + 1 << "   " << data.penghuni[i].nama;
                                for (int j = data.penghuni[i].nama.length(); j < 20; j++) cout << " ";
                                cout << data.penghuni[i].umur;
                                for (int j = data.penghuni[i].umur.length(); j < 20; j++) cout << " ";
                                cout << data.penghuni[i].kamar << endl;
                            }
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
                        break;

                    case 5: // Keluar dari program
                        cout << "Keluar dari program" << endl;
                        break;

                    default:
                        cout << "Pilihan tidak valid" << endl;
                        break;
                }
            } while (pilihan != 5);

            return 0;
        } else {
            cout << "\nNama atau NIM yang anda masukkan salah! Percobaan tersisa: " << maksimalpercobaan - percobaan << endl;
        }
    }
    cout << "\nAnda telah gagal login 3 kali. Program berhenti." << endl;
    return 0;
}