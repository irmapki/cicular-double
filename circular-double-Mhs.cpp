#include <iostream>

using namespace std;

// struktur linked list untuk data mahasiswa
struct dataMahasiswa {
  string nama, jurusan;
  int NIM;

  // pointer
  dataMahasiswa *sebelum;
  dataMahasiswa *selanjutnya;
};

dataMahasiswa *kepala, *ekor, *saat_ini, *hapus, *nodeBaru, *setelahNode;

// fungsi membuat circular double linked list
void buatdataMhs(string nama, string jurusan, int NIM) {
  kepala = new dataMahasiswa();
  kepala->nama = nama;
  kepala->jurusan = jurusan;
  kepala->NIM = NIM;
  kepala->sebelum = kepala;
  kepala->selanjutnya = kepala;
  ekor = kepala;
}

// add First
void tambahawal(string nama, string jurusan, int NIM) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    nodeBaru = new dataMahasiswa();
    nodeBaru->nama = nama;
    nodeBaru->jurusan = jurusan;
    nodeBaru->NIM = NIM;
    nodeBaru->sebelum = ekor;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelum = nodeBaru;
    ekor->selanjutnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// add Last
void tambahakhir(string nama, string jurusan, int NIM) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    nodeBaru = new dataMahasiswa();
    nodeBaru->nama = nama;
    nodeBaru->jurusan = jurusan;
    nodeBaru->NIM = NIM;
    nodeBaru->sebelum = ekor;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelum = nodeBaru;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// add Middle
void tambahtengah(string nama, string jurusan, int NIM, int posisi) {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 bukan posisi tengah" << endl;
    } else if (posisi < 1) {
      cout << "Posisi diluar jangkauan" << endl;
    } else {
      nodeBaru = new dataMahasiswa();
      nodeBaru->nama = nama;
      nodeBaru->jurusan = jurusan;
      nodeBaru->NIM = NIM;

      // tranversing
      saat_ini = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }
      setelahNode = saat_ini->selanjutnya;
      saat_ini->selanjutnya = nodeBaru;
      setelahNode->sebelum = nodeBaru;
      nodeBaru->sebelum = saat_ini;
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
      // tranversing
      saat_ini = kepala;
      int nomor = 1;
      while (nomor < posisi - 1) {
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }
      hapus = saat_ini->selanjutnya;
      setelahNode = hapus->selanjutnya;
      saat_ini->selanjutnya = setelahNode;
      setelahNode->sebelum = saat_ini;
      delete hapus;
    }
  }
}

// fungsi print
void printDataMahasiswa() {
  if (kepala == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    cout << "Data Mahasiswa : " << endl;
    saat_ini = kepala;
    while (saat_ini->selanjutnya != kepala) {
      // print
      cout << "Nama: " << saat_ini->nama << endl;
      cout << "Jurusan: " << saat_ini->jurusan << endl;
      cout << "NIM: " << saat_ini->NIM << "\n" << endl;

      // step
      saat_ini = saat_ini->selanjutnya;
    }
    // print last node
    cout << "Nama: " << saat_ini->nama << endl;
    cout << "Jurusan: " << saat_ini->jurusan << endl;
    cout << "NIM: " << saat_ini->NIM << "\n" << endl;
  }
}

int main() {
  buatdataMhs("Iruma", "Informatika", 123456);
  printDataMahasiswa();

  tambahawal("Maherza", "Sistem Informasi", 234567);
  printDataMahasiswa();

  tambahakhir("Maher Ganteng", "Teknik Elektro", 345678);
  printDataMahasiswa();

  tambahtengah("Maher Lucu", "Manajemen", 456789, 2);
  printDataMahasiswa();

  removeMiddle(2);
  printDataMahasiswa();

  return 0;
}
