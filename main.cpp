#include <stdlib.h>
#include <iostream>
using namespace std;
class bank {
private:
    string isim;
    string soyad;
    int tc;
    int accountNo;
public:
        bank() {}
    bank(string isim, string soyad, int tc, int accountNo);
    void HesapNoYap();
    int GetHesapNo();

    void SetName(string isim);
    string GetIsim();

    void SetLastName(string soyad);
    string GetLastName();

    void SetTc(int tc);
    int GetTc();
    ~bank();

};

class account  {
protected:
    double bakiye;
public:
    bank b;
    void SetBakiye(double bakiye);
    double GetBakiye();

    virtual void kayit();
    virtual void ParaCekme();
    virtual void ParaYatirma();
    virtual void Print();
    void Menu();

};

class vadesiz :public account {
public:
    void kayit();
    void ParaCekme();
    void ParaYatirma();
    void Print();

};

class vadeli :public account {
private:
    double kisa_faiz = 0.08;
    double uzun_faiz = 0.14;
public:
    void kayit();
    void ParaCekme();
    void ParaYatirma();
    void Print();
    void uzunvadeli();
    void kisavadeli();
};

class cari :public account {
public:
    void kayit();
    void ParaCekme();
    void ParaYatirma();
    void Print();
};


//bank sınıfı fonk. tanımı
bank::bank(string isim, string soyad, int tc, int accountNo) {
        this->isim = isim;
        this->soyad = soyad;
        this->tc = tc;
        this->accountNo = accountNo;
}

void bank::HesapNoYap() {
    accountNo = rand() % 99999;
}

int bank::GetHesapNo() {
    return accountNo;
}

void bank::SetName(string isim) {
    this->isim = isim;
}

string bank::GetIsim() {
    return isim;
}

void bank::SetLastName(string soyad) {
    this->soyad = soyad;
}

string bank::GetLastName() {
    return soyad;
}

void bank::SetTc(int tc) {
    this->tc = tc;
}

int bank::GetTc() {
    return tc;
}
bank::~bank() {}

//account sınıfı fonk. tanımı
void account::kayit() {
    string isim;
    string soyad;
    int tc;
    cout << "Ad:";
    cin >> isim;
    b.SetName(isim);

    cout << endl << "Soyad:";
    cin >> soyad;
    b.SetLastName(soyad);

    cout << endl << "Tc:";
    cin >> tc;
    b.SetTc(tc);

    b.HesapNoYap();
    GetBakiye();
}

void account::SetBakiye(double bakiye) {
    this->bakiye = bakiye;
}
double account::GetBakiye() {
    return bakiye;
}
void account::ParaYatirma() {
    double value;
    cout << "Yatırmak istediğiniz meblayi girin:";
    cin >> value;
    if (value < 0) cout << "0'dan kucuk deger girdiniz.";
    else  bakiye += value;
}
void account::ParaCekme() {
    double value;
    cout << "Cekmek istediğiniz meblayi girin:";
    cin >> value;
    if (value < 0) cout << "0'dan kucuk deger girdiniz.";
    else  bakiye -= value;
}
void account::Print() {//yazdırma
    cout << "adiniz:" << b.GetIsim();
    cout << endl << "soyadiniz:" << b.GetLastName();
    cout << endl << "tc'niz:" << b.GetTc();
    cout << endl << "hesap numaraniz:" << b.GetHesapNo();
    cout << endl << "paraniz:" << GetBakiye();
}
void account::Menu() { //islem menusu

   account *a = new account();
   
    int secim1;
    do {
        cout << endl;
        cout << "\t \t--- MENU---" << endl;
        cout << "1) Hesap Olustur" << endl;
        cout << "2) Para yatir" << endl;
        cout << "3) Para Cek" << endl;
        cout << "4) Hesap Bilgileri Goster" << endl;
        cout << "5) Vadeli hesabın faizini gösterin:" << endl;
        cout << "6) Islemleri sonlandir ve Ana Menuya git" << endl;
        cout << "yapmak istediginiz islemi seciniz : ";
        cin >> secim1;

        switch (secim1) {
        case 1:a->kayit();
            break;
        case 2:a->ParaYatirma();
            break;
        case 3:a->ParaCekme();
            break;
        case 4:a->Print();
            break;
        case 5: break;
        }
    }


    while (secim1 != 6);
}



void vadesiz::kayit() {}
void vadesiz::ParaCekme() {}
void vadesiz::ParaYatirma() {}
void vadesiz::Print() {}

void vadeli::kayit() {}
void vadeli::ParaCekme() {}
void vadeli::ParaYatirma() {}
void vadeli::Print() {}
void vadeli::uzunvadeli() {
    bakiye += (bakiye * uzun_faiz);
    cout << "Faiz oranı:" << uzun_faiz;
    cout << "Gelen Faiz:" << (bakiye * uzun_faiz);
    cout << "Mevcut bakiyeniz:" << GetBakiye();
}
void vadeli::kisavadeli() {
    bakiye += (bakiye * kisa_faiz);
    cout << "Faiz oranı:" << kisa_faiz;
    cout << "Gelen Faiz:" << (bakiye * kisa_faiz);
    cout << "Mevcut bakiyeniz:" << GetBakiye();
}


void cari::kayit() {}
void cari::ParaCekme() {}
void cari::ParaYatirma() {}
void cari::Print() {}


int main() {


    vadesiz vds;
    vadeli vdl;
    cari cr;



    int secim2;
    do {
        cout << endl;
        cout << "\t \t \tMENU \n";
        cout << "Acmak Istediginiz Hesap Turunu Secin :";
        cout << "\n1) Vadesiz Hesap";
        cout << "\n2) Vadeli Hesap";
        cout << "\n3) Cari Hesap";
        cout << "\n4) Cikis\n";
        cout << "secin --> ";
        cin >> secim2;

        switch (secim2) {
        case 1:vds.Menu();
            break;
        case 2: 
        char sec;
        cout<<"a) Uzun Vadeli Hesap"<<endl;
      cout<<"b) Kisa Vadeli Hesap"<<endl;
      cin>>sec;

      if(sec=='a'){
        vdl.uzunvadeli();
        vdl.Menu();
        
        
      }
      else if (sec=='b'){ 
        vdl.kisavadeli();
        vdl.Menu();
       
        
      }
    break;
        case 3:cr.Menu();
            break;
        case 4:goto end;
        }

    } while (1);
end:
    return 0;

}