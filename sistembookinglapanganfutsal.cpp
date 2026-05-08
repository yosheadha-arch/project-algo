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
}