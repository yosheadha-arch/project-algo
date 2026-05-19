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

//======