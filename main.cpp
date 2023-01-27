#include<iostream>
#include<stdlib.h>

using namespace std;

struct Barang{
    int idBarang;
    string namaBarang;
    int stok;
    long harga;
    Barang *prev;
    Barang *next;
};

Barang *newData, *head = NULL, *tail = NULL, *current;

bool isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool isSingleNode(){
    if(head->next == NULL){
        return true;
    }
    else{
        return false;
    }
}

void cetak(){
    if(isEmpty()){
        cout<<"List masih kosong!"<<endl;
    }
    else{
        system("CLS");
        cout<<"Data :"<<endl;
        cout<<"---------------------"<<endl;
        current  = head;
        int i = 1;
        while(current!=NULL){
            cout<<current->idBarang<< ", ";
            current = current->next;
        }
        cout<<endl;
    }
}

void buatList(Barang *dataBarang){
    head = dataBarang;
    tail = dataBarang;
}

void tambahDepan(Barang *dataBarang){
    if(isEmpty()){
        buatList(dataBarang);
    }
    else{

        dataBarang->next = head;
        head->prev = dataBarang;
        head = dataBarang;
    }
}

void tambahBelakang(Barang *dataBarang){
    if(isEmpty()){
        buatList(dataBarang);
    }
    else{
        tail->next = dataBarang;
        dataBarang->prev = tail;
        tail = dataBarang;
    }
}

void tambahTengah(int pos, Barang *dataBarang){
    if(isEmpty()){
        buatList(dataBarang);
    }
    else{
        Barang *nextCurrent;
        current = head;
        int i = 1;
        while(i < pos - 1){
            current = current->next;
            i++;
        }

        nextCurrent = current->next;
        dataBarang->next = nextCurrent;
        current->next = dataBarang;
        dataBarang->prev = current;
        nextCurrent->prev = dataBarang;
    }
}

void hapusDepan(){
    if(isEmpty()){
        cout<<"Tidak dapat menghapus head karena list masih kosong"<<endl;
    }
    else{
        if(isSingleNode()){
           head = NULL;
        }
        else{
            Barang *hapus;
            hapus = head;
            head = hapus->next;
            head->prev = NULL;
            hapus->next = NULL;
            delete hapus;
        }
        cout<<"Berhasil menghapus data paling depan"<<endl;
    }
}

void hapusBelakang(){
    if(isEmpty()){
        cout<<"Tidak dapat menghapus tail karena list masih kosong"<<endl;
    }
    else{
        if(isSingleNode()){
            head = NULL;
        }
        else{
            Barang *hapus;
            hapus = tail;
            tail = hapus->prev;
            tail->next = NULL;
            delete hapus;
        }
        cout<<"Berhasil menghapus data paling belakang"<<endl;

    }
}

void hapusTengah(int pos){
    if(isSingleNode()){
        head = NULL;
        cout<<"Berhasil hapus node"<<endl;
    }
    else
    {
        Barang *hapus;
        current = head;
        int i = 1;
        while(i < pos){
            current = current->next;
            i++;
        }
        hapus = current->next;
        current->next = hapus->next;
        delete hapus;
        cout<<"Berhasil hapus node di posisi "<<pos<<endl;
    }
}

Barang *inputData()
{
    newData = new Barang();
    cout<<"Id Data: ";
    cin>>newData->idBarang;
    newData->next = NULL;
    return newData;
}

void aksi(int pilih){
    Barang *inputan;
    int posisi;
    switch(pilih){
        case 0 : cout<<"Terima kasih"<<endl;exit(0);
        case 1 : system("CLS");
                cout<<"Tambah data di depan"<<endl;
                inputan = inputData();
                tambahDepan(inputan);break;
        case 2 : system("CLS");
                cout<<"Tambah data di belakang"<<endl;
                inputan = inputData();
                tambahBelakang(inputan);break;
        case 3 : cetak();break;
        case 4 : hapusDepan();break;
        case 5 : hapusBelakang();break;
        case 6 : cout<<"Masukkan posisi: ";cin>>posisi;
                inputan = inputData();
                tambahTengah(posisi, inputan);break;
        case 7 : cout<<"Masukkan posisi yang mau dihapus: ";cin>>posisi;
                hapusTengah(posisi);break;
        default: cout<<"Pilihan "<<pilih<<" belum tersedia"<<endl;
                exit(0);break;
    }
}


int main(){
    int pilih;
    do {
        cout<<"---------------------"<<endl;
        cout<<"1. Tambah depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Cetak List"<<endl;
        cout<<"4. Hapus depan"<<endl;
        cout<<"5. Hapus belakang"<<endl;
        cout<<"6. Tambah di tengah"<<endl;
        cout<<"7. Hapus di tengah"<<endl;
        cout<<"0. Keluar Program"<<endl;
        cout<<"Masukkan pilihan : ";
        cin>>pilih;
        aksi(pilih);
    }
    while(pilih!=0);
    return 0;
}
