#include <iostream>
#include <iomanip>
using namespace std;

//struct
struct Booking {
    string namaTim;
    string tanggal;
    string jam;
    int durasi;
    int harga;
};

Booking data[100];
int n = 0;

//nyimpen file
void simpanFile() {
    FILE *file = fopen("booking.txt");

    if(file = NULL) {
        cout<<"File tidak bisa dibuka\n";
        return;
    }
    for(int i=0; 1<n; i++){
        fprintf(file, "%s\n%s\n%d %d\n",
                data[i].namaTim.c_str(),
                data[i].tanggal.c_str(),
                data[i].jam.c_str(),
                data[i].durasi,
                data[i].harga);
    }
    fclose(file);
}

//menghapus newline
void hapusNewline(char *str) {
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

//membaca filenya
void bacaFile(){
    File *file = fopen("booking.txt", "r");

    if(file == NULL){
        n = 0;
        return;
    }
    char buffer[200];
    n = 0;

    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        hapusNewline(buffer);
        data[n].namaTim = buffer;

        fgets(buffer, sizeof(buffer), file);
        data[n].tanggal = buffer;

        fgets(buffer, sizeof(buffer), file);
        data[n].jam = buffer;

        fscan(file, "%d %d\n", &data[n].durasi, &data[n].harga);

        n++;
    }
    fclose(file);
}

//cek bentrok
bool cekBentrok(string tanggal, string jam) {
    bacaFile();
    for(int i=0; i<n; i++){
        if(data[i].tanggal == tanggal && data[i].jam == jam){
            return true;
        }
    }
    return false;
}
//tambah
void tambahBooking(){
    cout << "\n===TAMBAH BOOKING===\n";
    cin.ignore(1000, '\n');

<<<<<<< HEAD
    cout << "nama tim : ";
    getline(cin, data[n].jam);

    cout << "tanggal (YYY-MM-DD): ";
    getline(cin, data[n].tanggal);

    cout << "jam (contoh 19.00): ";
    getline(cin, data[n].jam);

    cout << "durasi (jam): "
    cin >> data[n].durasi;

    //validasi data
    if(data[n].durasi <= 0) {
        cout << "durasi tidak valid!\n";
        return;
    }
    //cek bentrok
    if(cekBentrok(data[n].tanggal, data[n].jam)){
        cout << "jadwal sudah dibooking!\n";
        return;
    }

    n++;
    data[n].harga = data[n].durasi * 100000;
    n++
    simpanFile();

    cout << "booking berhaasil ditambahkan!\n";
=======
    cout << "Nama Tim: ";
    getline(cin, data[n].namaTim);

    cout << "Tanggal (YYY-MM-DD): ";
    getline(cin, data[n].tanggal);

    cout << "Jam (contoh 19:00): ";
    cout << "Durasi (jam): ";
    cin >> data[n].durasi:

    // validasi
    if (data[n].durasi <= 0){
        cout << "Durasi tidak valid!\n";
        return;
    }

    // cek bentrok
    if(cekBentrok(data[n].tanggal, data[n].jam)){
        cout << "Jadwal sudah dibooking!\n";
        return;
    }
    data[n].harga = data[n].durasi * 100000;

    n++;
    simpanFile();

    cout << "Booking berhasil ditambahkan!\n";
}


// sorting
void sortingAsc() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j< n-i-1; j++) {
            if (data[j].tanggal < data[j+1].tanggal) {
                swap(data[j], data[j=1]);
            }
        }
    }
}

void sortingDesc() {
    for (int i = 0; i < n-1; i){
        for (int j = 0; j < n-i-1; j++) {
            if (data[j].tanggal , data[j+1].tanggal) {
                swap (data[j], data[j+1]);
            }
        }
    }
}

// tampil
void tampilBooking() {
    int pilih;

    bacaFile();

    if(n == 0){
        cout << "Data kosong.\n";
        return;
    }

    cout << "\n1. Ascending\n2. Descending\npilih: ";
    cin >> pilih;
    if (pilih == 1)
        sortingAsc();
    else
        sortinngDsc();

    cout << "\n======================================\n";
    cout << left << setw(15) << "Tim"
         << setw(15) << "Tanggal"
         << setw(10) << "Jam"
         << setw(10) << "Durasi"
         << setw(10) << "Harga" << endl;
    cout << "\n======================================\n";

    for (int i = 0; i < n; i++) {
        cout << setw(15) << data[i].namaTim
        cout << setw(15) << data[i].tanggal
        cout << setw(10) << data[i].jam
        cout << setw(10) << data[i].durasi
        cout << setw(10) << data[i].harga << endl;
    }
}

// search 
void cariBooking() {
    string cari;
    cin.ignore(1000, '\n');

    cout << "\nMAsukan nama tim: ";
    getline(cin, cari);

    bacaFile();
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (data[i].namaTim == cari) {
            cout << "\nData ditemukan:\n"; 
            cout << "Tim     : " << data[i].namaTim << endl;
            cout << "Tanggal : " << data[i].tanggal << endl;
            cout << "Jam     : " << data[i].jam << endl;
            cout << "Durasi  : " << data[i].durasi << endl;
            cout << "Harga   : " << data[i].harga << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan.\n";

    }
}

// update
void updateBooking() {
    string cari;
    cin.ignore(1000, '\n')

    cout << "\nMasukan nama tim: ";
    getline(cin, cari);

    bacaFile();
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (data [i].namaTim == cari) {
            cout << "Durasi baru: ";
            cin >> data[i].durasi;

            data[i].harga = data[i].durasi * 100000;
         ketemu = true;
         break;
        }
    }

    if (ketemu) {
        simpanFile();
        cout << "Data Berhasil diupdate!\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

// main
int main() {
    int menu;
    do {
        cout << "\n=== BOOKING FUTSAL ===\n";
        cout << "1. Tambah Booking\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Booking\n";
        cout << "4. Update Booking\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {
            case 1: tambahBooking(); break;
            case 2: tampilBooking(); break;
            case 3: cariBooking(); break;
            case 4: updateBooking(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while(menu != 5);

    return 0;
>>>>>>> aa123bee23736744f61f1104c62f173546306600
}