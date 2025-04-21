// #include <iostream>
// using namespace std;

// int main(){
//     int stack = 64;
//     int stackSnow = 16;

//     // int isi = stack;
//     // cout << isi << endl;
//     // stack = 69;
//     int* isi = &stack;

//     *isi = *isi + 10;


//     cout << stack<<endl;
//     cout << *isi<<endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct Orang{
//     string nama;
//     int umur;
// };

// int main(){
//     Orang orang;
//     orang.nama = "Rasyid";
//     orang.umur = 20;

//     Orang* orang2 = &orang;
//     cout << orang.nama<<endl;
//     cout << orang2->nama<<endl;
// }

#include <iostream>
using namespace std;

struct Orang{
    string nama;
    int umur;
};

int main(){
    
    int primeNumber[] = {
        2,3,5,7,11,13
    };

    int (*ptrPrimeNumber)[6] = &primeNumber;
    for (int i = 0; i < 6; i++)
    {
        cout << (*ptrPrimeNumber)[i] << endl;
    }

    cout << "Pointer ayng menunjuk ";
    cout << "Kearah elemen array" << endl;
    
}