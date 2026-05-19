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

