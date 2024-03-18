#include <iostream>
#include <string>
#include <cstdlib> //! library untuk exit(EXIT_FAILURE)
using namespace std;

const string merk_awal = "Oppo";
const int batasMerk = 100;
void pilih(string merk[], int &jumlahMerk);
void tambahkanMerk(string merk[], int &jumlahMerk);
void tampilkanMerk(string merk[], int &jumlahMerk);
void updateMerk(string merk[], int &jumlahMerk);
void hapusMerk(string merk[], int &jumlahMerk);

void clearTerminal() //! Prosedur
{
    system("cls");
}

bool cekMerk(string merk[], int jumlahMerk, const string &merkBaru); //! Fungsi
bool login();
int pilih();

int main()
{
    // login();
    string merk[batasMerk] = {merk_awal};
    int jumlahMerk = 1;
    pilih(merk, jumlahMerk);
}

void pilih(string merk[], int &jumlahMerk) //! Prosedur
{
    cout << "==========MENU==========\n";
    cout << "1. Tambahkan Merk Handphone\n";
    cout << "2. Tampilkan Semua Merk Handphone\n";
    cout << "3. Update Merk Handphone\n";
    cout << "4. Hapus Merk Handphone\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";

    int pilihan;
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        clearTerminal();
        tambahkanMerk(merk, jumlahMerk);
        break;
    case 2:
        clearTerminal();
        tampilkanMerk(merk, jumlahMerk);
        break;
    case 3:
        clearTerminal();
        updateMerk(merk, jumlahMerk);
        break;
    case 4:
        clearTerminal();
        hapusMerk(merk, jumlahMerk);
        break;
    case 5:
        clearTerminal();
        cout << "Program dihentikan\n";
        break;
    default:
        clearTerminal();
        cout << "Inputan salah, Program dihentikan\n";
        exit(EXIT_FAILURE);
    }
}

void tambahkanMerk(string merk[], int &jumlahMerk)
{
    string namaMerk;
    cout << "Masukkan nama merk handphone: ";
    cin >> namaMerk;

    if (jumlahMerk < batasMerk)
    {
        if (!cekMerk(merk, jumlahMerk, namaMerk))
        {
            merk[jumlahMerk++] = namaMerk;
            cout << "Merk handphone berhasil ditambahkan.\n";
        }
    }
    else
    {
        cout << "Tidak dapat menambah merk handphone lagi\n";
    }

    pilih(merk, jumlahMerk);
}

bool cekMerk(string merk[], int jumlahMerk, const string &merkBaru)
{
    for (int i = 0; i < jumlahMerk; ++i)
    {
        if (merk[i] == merkBaru)
        {
            cout << "Merk handphone sudah ada dalam daftar.\n";
            return true;
        }
    }
    return false;
}

void tampilkanMerk(string merk[], int &jumlahMerk)
{
    if (jumlahMerk == 0)
    {
        cout << "Tidak ada merk handphone yang ditambahkan.\n";
    }
    else
    {
        cout << "Daftar merk handphone:\n";
        for (int i = 0; i < jumlahMerk; ++i)
        {
            cout << merk[i] << endl;
        }
    }

    pilih(merk, jumlahMerk);
}

void updateMerk(string merk[], int &jumlahMerk)
{
    string merkLama, merkBaru;
    cout << "Masukkan nama merk handphone yang ingin diganti: ";
    cin >> merkLama;
    cout << "Masukkan nama merk handphone baru: ";
    cin >> merkBaru;
    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i)
    {
        if (merk[i] == merkLama)
        {
            indeks = i;
            break;
        }
    }
    if (indeks != -1)
    {
        merk[indeks] = merkBaru;
        cout << "Merk handphone berhasil diperbarui.\n";
    }
    else
    {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(merk, jumlahMerk);
}

void hapusMerk(string merk[], int &jumlahMerk)
{
    string hapusMerk;
    cout << "Masukkan nama merk handphone yang akan dihapus: ";
    cin >> hapusMerk;
    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i)
    {
        if (merk[i] == hapusMerk)
        {
            indeks = i;
            break;
        }
    }
    if (indeks != -1)
    {
        for (int i = indeks; i < jumlahMerk - 1; ++i)
        {
            merk[i] = merk[i + 1];
        }
        jumlahMerk--;
        cout << "Merk handphone berhasil dihapus.\n";
    }
    else
    {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(merk, jumlahMerk);
}

//! Line ke bawah fungsi login

bool login()
{
    int ulang = 0;
    string nama = "Dimas Raditya Permana";
    string nim = "2309106045";

    while (ulang < 3)
    {
        string input_nama;
        string input_nim;

        cout << "Masukkan Username: ";
        getline(cin, input_nama);

        cout << "Masukkan Password: ";
        getline(cin, input_nim);

        if (input_nama == nama && input_nim == nim)
        {
            clearTerminal();
            cout << "Login berhasil sebagai " << input_nama << endl;
            return true;
        }
        else
        {
            clearTerminal();
            cout << "Login gagal" << endl;
            ulang++;
        }
    }
    cout << "Batas percobaan login telah habis" << endl;
    exit(EXIT_FAILURE);
}
