#include <iostream>
using namespace std;

int main() {
    string nama, nim;
    int maksimalpercobaan = 3;

    for (int percobaan = 1; percobaan <= maksimalpercobaan; percobaan++) {
        cout << "=== LOGIN ===" << endl;
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM (3 digit angka): ";
        cin >> nim;

        if (nama == "rasyid" && nim == "042") {
            cout << "Login berhasil! Selamat datang, " << nama << endl;
            
            while (true) {
                int input;
                float celcius, fahrenheit, reamur, kelvin;
                cout << "\n== MENU KONVERSI ==\n1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin";
                cout << "\n2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin";
                cout << "\n3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin";
                cout << "\n4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur";
                cout << "\n5. Keluar dari program";
                cout << "\nPILIH MENU (1-5)";
                cout << "\nPilih menu :";
                cin >> input;
                
                if (input == 1) {
                    cout << "\nNilai suhu (Celcius) = \n";
                    cin >> celcius;
                    fahrenheit = (celcius*9/5)+32;
                    reamur = celcius*4/5;
                    kelvin = celcius+273.15;
                    cout << "Hasil konversi ke fahrenheit   :" << fahrenheit << endl;
                    cout << "Hasil konversi ke reamur       :" << reamur << endl;
                    cout << "Hasil konversi ke kelvin       :" << kelvin << endl;
                } else if (input == 2) {
                    cout << "\nNilai suhu (Fahrenheit)= \n";
                    cin >> fahrenheit;
                    celcius = (fahrenheit-32)*5/9;
                    reamur = (fahrenheit-32)*4/9;
                    kelvin = (fahrenheit-32)*5/9+273.15;
                    cout << "Hasil konversi ke celcius      :" << celcius << endl;
                    cout << "Hasil konversi ke reamur       :" << reamur << endl;
                    cout << "Hasil konversi ke kelvin       :" << kelvin << endl;
                } else if (input == 3) {
                    cout << "\nNilai suhu (Reamur) = \n";
                    cin >> reamur;
                    fahrenheit = (reamur*9/4)+32;
                    celcius = reamur*5/4;
                    kelvin = (reamur*5/4)+273.15;
                    cout << "Hasil konversi ke fahrenheit   :" << fahrenheit << endl;
                    cout << "Hasil konversi ke celcius      :" << celcius << endl;
                    cout << "Hasil konversi ke kelvin       :" << kelvin << endl;
                } else if (input == 4) {
                    cout << "\nNilai suhu (Kelvin) = \n";
                    cin >> kelvin;
                    fahrenheit = (kelvin-273.15)*9/5+32;
                    celcius = kelvin-273.15;
                    reamur = (kelvin-273.15)*4/5;
                    cout << "Hasil konversi ke fahrenheit   :" << fahrenheit << endl;
                    cout << "Hasil konversi ke celcius      :" << celcius << endl;
                    cout << "Hasil konversi ke reamur       :" << reamur << endl;
                } else if (input == 5) {
                    cout << "\nKeluar dari program";
                    return 0;
                } else {
                    cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                }
            }
        }else {
                cout << "\nNama atau NIM yang anda masukkan salah! Percobaan tersisa: " << maksimalpercobaan - percobaan << endl;
            }
    }
    cout << "\nAnda telah gagal login 3 kali. Program berhenti." << endl;
    return 0;
}
