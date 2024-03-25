#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

const string merk_awal = "Oppo";
const int batasMerk = 10;

struct merk 
{
    string namaMerk;
    int stok;
};

void pilih(merk listMerk[], int &jumlahMerk);
void tambahMerk(merk listMerk[], int &jumlahMerk);
void tampilkanMerk(merk listMerk[], int &jumlahMerk);
void perbaruiMerk(merk listMerk[], int &jumlahMerk);
void hapusMerk(merk listMerk[], int &jumlahMerk);
void tambahStok(merk listMerk[], int &jumlahMerk);
void kurangiStok(merk listMerk[], int &jumlahMerk);

void clearTerminal()
{
    system("cls");
}

bool cekMerk(merk listMerk[], int jumlahMerk, const string &merkBaru);
bool login();

int main() 
{
    //login();
    merk listMerk[batasMerk] = {{merk_awal, 1}};
    int jumlahMerk = 1;
    pilih(listMerk, jumlahMerk);
}

void pilih(merk listMerk[], int &jumlahMerk) 
{
    cout << "==========MENU==========\n";
    cout << "1. Tambahkan Merk Handphone\n";
    cout << "2. Tampilkan Semua Merk Handphone\n";
    cout << "3. Perbarui Merk Handphone\n";
    cout << "4. Hapus Merk Handphone\n";
    cout << "5. Tambah Stok Merk Handphone\n";
    cout << "6. Kurangi Stok Merk Handphone\n";
    cout << "7. Keluar\n";
    cout << "Pilih opsi: ";

    int pilihan;
    cin >> pilihan;

    switch (pilihan) 
    {
        case 1:
            clearTerminal();
            tambahMerk(listMerk, jumlahMerk);
            break;
        case 2:
            clearTerminal();
            tampilkanMerk(listMerk, jumlahMerk);
            break;
        case 3:
            clearTerminal();
            perbaruiMerk(listMerk, jumlahMerk);
            break;
        case 4:
            clearTerminal();
            hapusMerk(listMerk, jumlahMerk);
            break;
        case 5:
            clearTerminal();
            tambahStok(listMerk, jumlahMerk);
            break;
        case 6:
            clearTerminal();
            kurangiStok(listMerk, jumlahMerk);
            break;
        case 7:
            clearTerminal();
            cout << "Program dihentikan\n";
            break;
        default:
            clearTerminal();
            cout << "Inputan salah, Masukkan perintah yang benar\n";
            exit(EXIT_FAILURE);
    }
}

// 1
void tambahMerk(merk listMerk[], int &jumlahMerk) 
{
    string namaMerk;
    cout << "Masukkan nama merk handphone: ";
    cin >> namaMerk;

    if (jumlahMerk < batasMerk) {
        if (!cekMerk(listMerk, jumlahMerk, namaMerk)) {
            listMerk[jumlahMerk].namaMerk = namaMerk;
            listMerk[jumlahMerk].stok = 1;
            jumlahMerk++;
            cout << "Merk handphone berhasil ditambahkan.\n";
        }
    }
    else {
        cout << "Tidak dapat menambah merk handphone lagi\n";
    }

    pilih(listMerk, jumlahMerk);
}

bool cekMerk(merk listMerk[], int jumlahMerk, const string &merkBaru) 
{
    for (int i = 0; i < jumlahMerk; ++i) {
        if (listMerk[i].namaMerk == merkBaru) {
            cout << "Merk handphone sudah ada dalam daftar.\n";
            return true;
        }
    }
    return false;
}

// 2
void tampilkanMerk(merk listMerk[], int &jumlahMerk) 
{
    if (jumlahMerk == 0) {
        cout << "Tidak ada merk handphone yang ditambahkan.\n";
    }
    else {
        cout << "Daftar merk handphone:\n";
        for (int i = 0; i < jumlahMerk; ++i) {
            cout << listMerk[i].namaMerk << " (Stok: " << listMerk[i].stok << ")" << endl;
        }
    }

    pilih(listMerk, jumlahMerk);
}

// 3
void perbaruiMerk(merk listMerk[], int &jumlahMerk) 
{
    string merkLama, merkBaru;
    cout << "Masukkan nama merk handphone yang ingin diganti: ";
    cin >> merkLama;
    cout << "Masukkan nama merk handphone baru: ";
    cin >> merkBaru;
    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i) {
        if (listMerk[i].namaMerk == merkLama) {
            indeks = i;
            break;
        }
    }
    if (indeks != -1) {
        listMerk[indeks].namaMerk = merkBaru;
        cout << "Merk handphone berhasil diperbarui.\n";
    }
    else {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(listMerk, jumlahMerk);
}

// 4
void hapusMerk(merk listMerk[], int &jumlahMerk) 
{
    string hapusMerk;
    cout << "Masukkan nama merk handphone yang akan dihapus: ";
    cin >> hapusMerk;
    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i) {
        if (listMerk[i].namaMerk == hapusMerk) {
            indeks = i;
            break;
        }
    }
    if (indeks != -1) {
        for (int i = indeks; i < jumlahMerk - 1; ++i) {
            listMerk[i] = listMerk[i + 1];
        }
        jumlahMerk--;
        cout << "Merk handphone berhasil dihapus.\n";
    }
    else {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(listMerk, jumlahMerk);
}

// 5
void tambahStok(merk listMerk[], int &jumlahMerk)  
{
    string namaMerk;
    int tambahanStok;
    cout << "Masukkan nama merk handphone: ";
    cin >> namaMerk;

    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i) {
        if (listMerk[i].namaMerk == namaMerk) {
            indeks = i;
            break;
        }
    }

    if (indeks != -1) {
        cout << "Masukkan jumlah stok tambahan: ";
        cin >> tambahanStok;
        if (tambahanStok > 0) {
            listMerk[indeks].stok += tambahanStok;
            cout << "Stok berhasil ditambahkan untuk merk " << namaMerk << ". Stok sekarang: " << listMerk[indeks].stok << endl;
        } else {
            cout << "Jumlah stok tambahan harus lebih dari 0.\n";
        }
    } else {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(listMerk, jumlahMerk);
}

// 6
void kurangiStok(merk listMerk[], int &jumlahMerk) 
{
    string namaMerk;
    int kurangiStok;
    cout << "Masukkan nama merk handphone: ";
    cin >> namaMerk;

    int indeks = -1;
    for (int i = 0; i < jumlahMerk; ++i) {
        if (listMerk[i].namaMerk == namaMerk) {
            indeks = i;
            break;
        }
    }

    if (indeks != -1) {
        cout << "Masukkan jumlah stok yang akan dikurangi: ";
        cin >> kurangiStok;
        if (kurangiStok > 0 && kurangiStok <= listMerk[indeks].stok) {
            listMerk[indeks].stok -= kurangiStok;
            cout << "Stok berhasil dikurangi untuk merk " << namaMerk << ". Stok sekarang: " << listMerk[indeks].stok << endl;
        } else if (kurangiStok > listMerk[indeks].stok) {
            cout << "Jumlah stok yang akan dikurangi melebihi stok yang tersedia.\n";
        } else {
            cout << "Jumlah stok yang akan dikurangi harus lebih dari 0.\n";
        }
    } else {
        cout << "Merk handphone tidak ditemukan.\n";
    }

    pilih(listMerk, jumlahMerk);
}

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
