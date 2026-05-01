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