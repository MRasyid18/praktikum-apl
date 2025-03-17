#include <iostream>
using namespace std;

#define MAX_KAMAR 100

int main() {
    string kamar[MAX_KAMAR];
    string nama[MAX_KAMAR];
    string nim[MAX_KAMAR];
    string inputNama, inputNim;
    int panjang = 0;
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
                cout << "4. Hapus Data Pelanggan/peghuni" << endl;
                cout << "5. Keluar Dari Program" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: // FITUR READ Melihat data penghuni kamar
                        if (panjang == 0) {
                            cout << "Belum ada pesanan\n" << endl;
                        } else {
                            cout << "No  Nama                No.Tlp                 Kamar" << endl;
                            cout << "----------------------------------------------------" << endl;
                            for (int i = 0; i < panjang; i++) {
                                cout << i + 1 << "   " << nama[i];
                                for (int j = nama[i].length(); j < 20; j++) cout << " ";
                                cout << nim[i];
                                for (int j = nim[i].length(); j < 20; j++) cout << " ";
                                cout << kamar[i] << endl;
                            }
                        }
                        break;

                    case 2: // FITUR CREATE Menambahkan data penghuni dan kamar
                        if (panjang < MAX_KAMAR) {
                            cout << "Masukkan nama: ";
                            cin.ignore();
                            getline(cin, nama[panjang]);
                            cout << "Masukkan nomor telepon: ";
                            getline(cin, nim[panjang]);
                            cout << "Masukkan nomor kamar: ";
                            getline(cin, kamar[panjang]);
                            panjang++;
                            cout << "Data pesanan berhasil ditambahkan\n" << endl;
                        } else {
                            cout << "Kapasitas penuh! Tidak bisa menambah penghuni lagi.\n" << endl;
                        }
                        break;

                    case 3: // FITUR UPDATE Mengubah data penghuni
                        if (panjang == 0) {
                            cout << "Belum ada kamar untuk diubah." << endl;
                        } else {
                            cout << "No  Nama                NIM                 Kamar" << endl;
                            cout << "----------------------------------------------------" << endl;
                            for (int i = 0; i < panjang; i++) {
                                cout << i + 1 << "   " << nama[i];
                                for (int j = nama[i].length(); j < 20; j++) cout << " ";
                                cout << nim[i];
                                for (int j = nim[i].length(); j < 20; j++) cout << " ";
                                cout << kamar[i] << endl;
                            }
                            cout << "Masukkan nomor kamar yang akan diubah: ";
                            cin >> index;
                            if (index > 0 && index <= panjang) {
                                cout << "Masukkan nama baru: ";
                                cin.ignore();
                                getline(cin, nama[index - 1]);
                                cout << "Masukkan NIM baru: ";
                                getline(cin, nim[index - 1]);
                                cout << "Masukkan nomor kamar baru: ";
                                getline(cin, kamar[index - 1]);
                                cout << "Kamar berhasil diubah" << endl;
                            } else {
                                cout << "Nomor kamar tidak valid" << endl;
                            }
                        }
                        break;

                    case 4: // FITUR DELETE Menghapus data penghuni
                        if (panjang == 0) {
                            cout << "Belum ada kamar untuk dihapus.\n" << endl;
                        } else {
                            cout << "No  Nama                NIM                 Kamar" << endl;
                            cout << "----------------------------------------------------" << endl;
                            for (int i = 0; i < panjang; i++) {
                                cout << i + 1 << "   " << nama[i];
                                for (int j = nama[i].length(); j < 20; j++) cout << " ";
                                cout << nim[i];
                                for (int j = nim[i].length(); j < 20; j++) cout << " ";
                                cout << kamar[i] << endl;
                            }
                            cout << "Masukkan nomor kamar yang akan dihapus: ";
                            cin >> index;
                            if (index > 0 && index <= panjang) {
                                for (int i = index - 1; i < panjang - 1; i++) {
                                    nama[i] = nama[i + 1];
                                    nim[i] = nim[i + 1];
                                    kamar[i] = kamar[i + 1];
                                }
                                panjang--;
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
