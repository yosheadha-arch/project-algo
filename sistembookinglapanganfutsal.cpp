#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

//=======struct=========

struct Booking {
    string namaTim;
    string tanggal;
    string jam;
    int durasi;
    int harga;
};

//====linked list=======
struct Node {
    Booking data;
    Node *next;
};

Node *head = NULL;

//=====validasi input======
int inputAngka(string pesan) {
    int angka;

    while (true) {
        cout << pesan;
        cin >> angka;
        
        if (cin.fail()) {
            
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "INput harus angka";

        }else {

            return angka;
        }
    }
}

//===hapus timeline====

void hapusNewline(char *str) {
    for(int i=0; str[i] != '\0'; i++){

        if(str[i] == '\n'){

            str[i] = '\0';
            break;
        }
    }
}

//===kosongkan list====

void kosongkanList(){
    Node *hapus;

    while(head != NULL) {

        hapus = head;
        head = head->next;

        delete hapus;
    }
}

//====simpan file====
void simpanFile(){
    FILE *file = fopen("booking.txt", "w");

    if(file == NULL){
        cout << "file tidak bisa dibuka\n"
        return;
    }

    Node *bantu = head;

    while(bantu != NULL) {

        fprintf(file,
            "%s\n%s\n%s\n%d %d\n"
            bantu->data.namaTim.c_str(),
                bantu->data.tanggal.c_str(),
                bantu->data.jam.c_str(),
                bantu->data.durasi,
                bantu->data.harga);

            bantu = bantu->next;
    }
    fclose(file);
}

//======baca file=====

void bacaFile(){
    kosongkanList();

    FILE *file = fopen("booking.txt", "r");

    if(file == NULL) {
        return;
    }
    char buffer[200];

    while(fgets(buffer, sizeof(buffer), file) != NULL){

        Node *baru = new Node;

        hapusNewline(buffer);
        baru->data.namaTim = buffer;

        fgets(buffer, sizeof(buffer), file);
        hapusNewline(buffer);
        baru->data.tanggal = buffer;

        fgets(buffer, sizeof(buffer), file);
        hapusNewline(buffer);
        baru->data.jam = buffer;

        fscanf(file,"%d %d\n",
               &baru->data.durasi,
               &baru->data.harga);

        baru->next = NULL;

        if(head == NULL){

            head = baru;

        } else {

            Node *bantu = head;

            while(bantu->next != NULL){
                bantu = bantu->next;
            }

            bantu->next = baru;
        }
    }
    fclose(file);
}

//=====cek bentrok=====
bool cekBentrok(string tanggal, string jam){
    Node *bantu = head;

    while(bantu !=NULL) {
        while(bantu != NULL){

        if(bantu->data.tanggal == tanggal &&
           bantu->data.jam == jam){

            return true;
        }

        bantu = bantu->next;
    }
    return false;
}

//====tambah booking
void tambahBooking(){
    bacaFile();

    cin.ignore(1000, '\n');

    Node *baru = new Node;

    cout << "\n========== TAMBAH BOOKING ==========\n";

    cout << "Nama Tim             : ";
    getline(cin, baru->data.namaTim);

    cout << "Tanggal (YYYY-MM-DD) : ";
    getline(cin, baru->data.tanggal);

    cout << "Jam (contoh 19:00)   : ";
    getline(cin, baru->data.jam);

    do {

        baru->data.durasi =
            inputAngka("Durasi (jam)        : ");

        if(baru->data.durasi <= 0){

            cout << "Durasi tidak valid!\n";
        }

    } while(baru->data.durasi <= 0);

    if(cekBentrok(baru->data.tanggal,
                  baru->data.jam)){

        cout << "Jadwal sudah dibooking!\n";

        delete baru;
        return;
    }

    baru->data.harga =
        baru->data.durasi * 100000;

    baru->next = NULL;

    if(head == NULL){

        head = baru;

    } else {

        Node *bantu = head;

        while(bantu->next != NULL){
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    simpanFile();

    cout << "Booking berhasil ditambahkan!\n";
}

//======HITUNG NODE=======
int jumlahData(){
    int jumlah = 0;
    Node *bantu = head;

    while(bantu != NULL){

        jumlah++;
        bantu = bantu->next;
    }
}