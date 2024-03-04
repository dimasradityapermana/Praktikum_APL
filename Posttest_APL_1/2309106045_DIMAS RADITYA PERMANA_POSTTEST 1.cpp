#include <iostream>
#include <string>
#include <cstdlib> //! library untuk exit(EXIT_FAILURE)
using namespace std;

bool login();
int pilih();
float dollar, rupiah, euro, yen;
float pilDollar(), pilRupiah(), pilEuro(), pilYen();



int main()
{
    login();
    pilih();
}



int pilih()
{
    int pilihan;
    cout << "Masukkan mata uang anda untuk dikonversi" << endl;
    cout << "1. Dollar" << endl;
    cout << "2. Rupiah" << endl;
    cout << "3. Euro" << endl;
    cout << "4. Yen" << endl;

    cin >> pilihan;

    if (pilihan == 1)
        pilDollar();
    else if (pilihan == 2)
        pilRupiah();
    else if (pilihan == 3)
        pilEuro();
    else if (pilihan == 4)
        pilYen();
    else
    {
        cout << "Pilihan tidak tersedia" << endl;
    }
    return pilihan;
}

//! Line ke bawah fungsi login

bool login()
{
    int ulang = 0;
    int max_ulang = 3;
    string nama = "Dimas Raditya Permana";
    string nim = "2309106045";

    while (ulang < max_ulang)
    {
        string input_nama;
        string input_nim;

        cout << "Masukkan Username: ";
        getline(cin, input_nama);

        cout << "Masukkan Password: ";
        getline(cin, input_nim);

        if (input_nama == nama && input_nim == nim)
        {
            cout << "Login berhasil sebagai " << input_nama << endl;
            return true;
        }
        else
        {
            cout << "Login gagal" << endl;
            ulang++;
        }
    }
    cout << "Batas percobaan login telah habis" << endl;
    exit(EXIT_FAILURE);
}

//! Line ke bawah fungsi konversi mata uang

float pilDollar()
{
    char y_n;
    cout << "Masukkan jumlah dollar: ";
    cin >> dollar;
    rupiah = dollar * 15701.95;
    euro = dollar * 0.92;
    yen = dollar * 150.10;
    cout << "Rupiah: " << rupiah << endl;
    cout << "Euro: " << euro << endl;
    cout << "Yen: " << yen << endl;

    cout << "Apakah anda ingin mengulang? (y/n): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        return pilih();
    }
    else if (y_n == 'n' || y_n == 'N')
    {
        cout << "Selamat tinggal" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Inputan salah" << endl;
        return 0;
    }
}

float pilRupiah()
{
    char y_n;
    cout << "Masukkan jumlah rupiah: ";
    cin >> rupiah;
    dollar = rupiah * 0.000064;
    euro = rupiah * 0.000059;
    yen = rupiah * 0.0096;
    cout << "Dollar: " << dollar << endl;
    cout << "Euro: " << euro << endl;
    cout << "Yen: " << yen << endl;

    cout << "Apakah anda ingin mengulang? (y/n): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        return pilih();
    }
    else if (y_n == 'n' || y_n == 'N')
    {
        cout << "Selamat tinggal" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Inputan salah" << endl;
        return 0;
    }
}

float pilEuro()
{
    char y_n;
    cout << "Masukkan jumlah euro: ";
    cin >> euro;
    rupiah = euro * 17043.68;
    dollar = euro * 1.09;
    yen = euro * 162.93;
    cout << "Rupiah: " << rupiah << endl;
    cout << "Dollar: " << dollar << endl;
    cout << "Yen: " << yen << endl;

    cout << "Apakah anda ingin mengulang? (y/n): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        return pilih();
    }
    else if (y_n == 'n' || y_n == 'N')
    {
        cout << "Selamat tinggal" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Inputan salah" << endl;
        return 0;
    }
}

float pilYen()
{
    char y_n;
    cout << "Masukkan jumlah yen: ";
    cin >> yen;
    rupiah = yen * 104.61;
    euro = yen * 0.0061;
    dollar = yen * 0.0067;
    cout << "Rupiah: " << rupiah << endl;
    cout << "Euro: " << euro << endl;
    cout << "Dollar: " << dollar << endl;

    cout << "Apakah anda ingin mengulang? (y/n): ";
    cin >> y_n;
    if (y_n == 'y' || y_n == 'Y')
    {
        return pilih();
    }
    else if (y_n == 'n' || y_n == 'N')
    {
        cout << "Selamat tinggal" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Inputan salah" << endl;
        return 0;
    }
}