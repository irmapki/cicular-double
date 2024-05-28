#include <iostream>

using namespace std;

// struktur linked list
struct dataBarang {
  string namaBarang;
  int jumlahBarang, hargaBarang;

  dataBarang *sebelum;
  dataBarang *selanjutnya;
};

dataBarang *kepala, *ekor, *saatIni, *hapus, *nodeBaru, *setelahNode;

// fungsi membuat circular double Linked list
void createDataBarang(string namaBarang, int jmlBarang, int hargaBarang) {
  kepala = new dataBarang();
  kepala->namaBarang = namaBarang;
  kepala->jumlahBarang = jmlBarang;
  kepala->hargaBarang = hargaBarang;
  kepala->sebelum = kepala;
  kepala->selanjutnya = kepala;
  ekor = kepala;
}

// add First
void addFirst(string namaBarang, int jmlBarang, int hargaBarang) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    nodeBaru = new dataBarang();
    nodeBaru->namaBarang = namaBarang;
    nodeBaru->jumlahBarang = jmlBarang;
    nodeBaru->hargaBarang = hargaBarang;
    nodeBaru->sebelum = ekor;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelum = nodeBaru;
    ekor->selanjutnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// add Last
void addLast(string namaBarang, int jmlBarang, int hargaBarang) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    nodeBaru = new dataBarang();
    nodeBaru->namaBarang = namaBarang;
    nodeBaru->jumlahBarang = jmlBarang;
    nodeBaru->hargaBarang = hargaBarang;
    nodeBaru->sebelum = ekor;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelum = nodeBaru;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// add Middle
void addMiddle(string namaBarang, int jmlBarang, int hargaBarang, int posisi) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 bukan posisi tengah" << endl;
    } else if (posisi < 1) {
      cout << "Posisi diluar jangkauan" << endl;
    } else {
      nodeBaru = new dataBarang();
      nodeBaru->namaBarang = namaBarang;
      nodeBaru->jumlahBarang = jmlBarang;
      nodeBaru->hargaBarang = hargaBarang;

      // traversing
      saatIni = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        saatIni = saatIni->selanjutnya;
        nomor++;
      }
      setelahNode = saatIni->selanjutnya;
      saatIni->selanjutnya = nodeBaru;
      setelahNode->sebelum = nodeBaru;
      nodeBaru->sebelum = saatIni;
      nodeBaru->selanjutnya = setelahNode;
    }
  }
}

// remove First
void removeFirst() {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    hapus = kepala;
    kepala = kepala->selanjutnya;
    ekor->selanjutnya = kepala;
    kepala->sebelum = ekor;
    delete hapus;
  }
}

// remove Last
void removeLast() {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    hapus = ekor;
    ekor = ekor->sebelum;
    ekor->selanjutnya = kepala;
    kepala->sebelum = ekor;
    delete hapus;
  }
}

// remove Middle
void removeMiddle(int posisi) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 bukan posisi tengah" << endl;
    } else if (posisi < 1) {
      cout << "Posisi diluar jangkauan" << endl;
    } else {
      // traversing
      saatIni = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        saatIni = saatIni->selanjutnya;
        nomor++;
      }
      hapus = saatIni->selanjutnya;
      setelahNode = hapus->selanjutnya;
      saatIni->selanjutnya = setelahNode;
      setelahNode->sebelum = saatIni;
      delete hapus;
    }
  }
}

// fungsi print
void printDataBarang() {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    cout << "Data Barang : " << endl;
    saatIni = kepala;
    while (saatIni->selanjutnya != kepala) {
      // print
      cout << "Nama Barang : " << saatIni->namaBarang << endl;
      cout << "Jumlah Barang : " << saatIni->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << saatIni->hargaBarang << "\n" << endl;

      // step
      saatIni = saatIni->selanjutnya;
    }
    // print last node
    cout << "Nama Barang : " << saatIni->namaBarang << endl;
    cout << "Jumlah Barang : " << saatIni->jumlahBarang << " barang" << endl;
    cout << "Harga Barang : Rp." << saatIni->hargaBarang << "\n" << endl;
  }
}

int main() {
  createDataBarang("sabun", 15, 5000);
  printDataBarang();

  addFirst("parfum", 23, 7000);
  printDataBarang();

  addLast("odol", 11, 12000);
  printDataBarang();

  addMiddle("rexona", 11, 20000, 6);
  printDataBarang();

  removeMiddle(6);
  printDataBarang();
}
