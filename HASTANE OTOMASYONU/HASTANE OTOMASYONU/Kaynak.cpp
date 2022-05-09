#include<windows.h>
#include <iostream>
#include <fstream>      // dosya iþlemleri için
#include <string>
#include <clocale>
using namespace std;
class Hasta {
	friend class Doktor;
public:
	string ad, soyad, dogumYeri, cinsiyet, recete, tc;
	bool sigortaDurumu;
	string kanGrubu;
	int yas;
	double boy, kilo;
	long telNo;

	Hasta() {

	}

	Hasta(string ad, string  soyad, string dogumYeri, string sigortaDurumu, string cinsiyet, string recete, string kanGrubu, int yas, double boy, double kilo, long telNo, string tc) {

		ad = ad;
		soyad = soyad;
		dogumYeri = dogumYeri;
		cinsiyet = cinsiyet;
		recete = recete;
		sigortaDurumu = sigortaDurumu;
		kanGrubu = kanGrubu;
		yas = yas;
		boy = boy;
		kilo = kilo;
		telNo = telNo;
		tc = tc;

	}


	void hastamenü() {
		cout << "HANGÝ HÝZMETÝMÝZDEN YARARLANMAK ÝSTERSÝNÝZ ?  " << endl;
		cout << "---------------------------------------------------------------------------------- " << endl;
		cout << " 1 -->  RANDEVU ALMA       <-- 1 " << endl;
		cout << " 2 -->  RANDEVU SÝLME      <-- 2 " << endl;//
		cout << " 3 -->  RANDEVU SORGULAMA  <-- 3 " << endl;//Text dosyasý yazdýrýlacak
		cout << " 4 -->  BÝLGÝ GÜNCELLEME   <-- 4 " << endl;
		cout << " 5 -->  BORÇ GÖRÜNTÜLEME   <-- 5" << endl;
		cout << " 6 -->  ÇIKIÞ YAP          <-- 6 " << endl;
		cout << "---------------------------------------------------------------------------------- " << endl;
	}



};


class Calisan {


public:

	string ad, soyad, cinsiyet, unvan, tc;
	int yas, maas, calýsmaSaati, saatlikUcret;
	long telNo;


	Calisan() {}

	Calisan(string ad, string soyad, string cinsiyet, string unvan, int yas, int maas, int calýsmaSaati, int saatlikUcret, long telNo, string tc) {

		ad = ad;
		soyad = soyad;
		cinsiyet = cinsiyet;
		unvan = unvan;
		maas = maas;
		yas = yas;
		telNo = telNo;
		tc = tc;
		calýsmaSaati = calýsmaSaati;
		saatlikUcret = saatlikUcret;
	}

	void CalýsanaMesaj() {
		cout << "* Baðlýlýðýnýz ve sýký çalýþmanýz için teþekkür ederiz...*" << endl;
	}
	virtual void  MaasHesapla(int calýsmaSaati) = 0;            // SAF SANAL FONKSÝYON .



};

class Doktor : public Calisan {



public:

	string branþ;
	Hasta hasta;

	Doktor() {


	}
	Doktor(string ad, string soyad, string cinsiyet, string unvan, int yas, int maas, int calýsmaSaati, int saatlikUcret, long telNo, string tc, string branþ, Hasta hasta) :Calisan(ad, soyad, cinsiyet, unvan, yas, maas, calýsmaSaati, saatlikUcret, telNo, tc) {

		hasta = hasta;
		branþ = branþ;


	}

	void MaasHesapla(int calýsmaSaati) {
		saatlikUcret = 200;
		maas = calýsmaSaati * saatlikUcret * 30;
		system("CLS");
		cout << " BU AY ALACAÐINIZ MAAÞ  :  " << maas << " TL " << endl;

	}
	void  receteYaz(Hasta& h) {
		cout << "hastanýn reçetesini girin." << endl;
		cin >> h.recete;


	}




};
void yükleniyor() {

	system("CLS");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "-->";
		Sleep(100);
		system("CLS");

	}
}
void hGörüntüle() {

	Hasta h1;
	string htc;
	ifstream achtc;
	string ghasta;

	cout << "--------HASTA GÖRÜNTÜLEME EKRANI----------" << endl;
	cout << endl;
	cout << endl;
	cout << "Görüntülemek Ýstediðiniz Hastanýn Tc Kimlik Numarasýný Giriniz : " << endl;
	cin >> htc;
	yükleniyor();

	achtc.open("Hastalar.txt");


	string dosyadakTc;
	while (achtc >> dosyadakTc)
	{
		if (htc == dosyadakTc) {
			h1.tc = dosyadakTc;

			break;
		}

	}

	if (h1.tc.size() != 0) {

		ifstream gHasta;
		gHasta.open(h1.tc + ".txt");

		while (getline(gHasta, ghasta)) {

			cout << ghasta << endl;


		}
		gHasta.close();
		cout << endl;
		cout << endl;
	}

	else {
		yükleniyor();

		cout << "BÖYLE BÝR HASTA BULUNAMADI TEKRAR DENEYÝNÝZ" << endl;




	}

}
void receteyaz() {
	Hasta h1;
	string htc;
	ifstream achtc;
	string ghasta;

	cout << "--------RECETE YAZMA EKRANI----------" << endl;
	cout << endl;
	cout << endl;
	cout << "Recete Yazmak  Ýstediðiniz Hastanýn Tc Kimlik Numarasýný Giriniz : " << endl;
	cin >> htc;
	yükleniyor();

	achtc.open("Hastalar.txt");


	string dosyadakTc;
	while (achtc >> dosyadakTc)
	{
		if (htc == dosyadakTc) {
			h1.tc = dosyadakTc;

			break;
		}

	}

	if (h1.tc.size() != 0) {
		yükleniyor();
		cout << "Receteye girmek istediðiniz ilacý yazýnýz" << endl;
		cin >> h1.recete;
		ifstream gHasta;
		ofstream gecici("gecici.txt");
		gHasta.open(h1.tc + ".txt");

		while (getline(gHasta, ghasta)) {

			gecici << ghasta << endl;


		}
		ghasta = "";
		gecici.close();
		ifstream geciciac("gecici.txt");
		ofstream rHasta(h1.tc + ".txt");


		for (int i = 0; i < 7; i++) {
			getline(geciciac, ghasta);
			rHasta << ghasta << endl;
		}

		rHasta << "Recete : " << h1.recete;
		gHasta.close();
		rHasta.close();
		cout << "Receteye Yazdýrýldý Menüye Yönlendiriliyorsunuz " << endl;
		cout << endl;
		cout << endl;
		geciciac.close();
		system("del gecici.txt");
	}

	else {
		yükleniyor();

		cout << "BÖYLE BÝR HASTA BULUNAMADI TEKRAR DENEYÝNÝZ" << endl;




	}







}
int main() {
	system("COLOR 80");
	setlocale(LC_ALL, "Turkish");
	Doktor d1;
	Hasta h1;
	int kullanýcý;
	int sec;
	int al;
	int dkt;


	do {
		cout << ".......... HOÞGELDÝNÝZ .........." << endl << endl << endl << "kullanýcý durumunuza karþýlýk gelen numarayý giriniz.." << endl;
		cout << " 1 --> HASTA " << endl << " 2 -->  DOKTOR" << endl;
		cout << " PROGRAMI KAPAMAK ÝÇÝN 3'Ü TUÞLAYINIZ.";
		cin >> kullanýcý;
		yükleniyor();
		string tc;
		if (kullanýcý == 1) {
			cout << "--------------HASTA MENÜSÜ--------------" << endl;
			cout << endl;
			cout << endl;

			cout << "TC Kimlik Numaranýzý Giriniz" << endl;
			cin >> tc;
			ifstream actc;

			actc.open("Hastalar.txt");

			//actc >> h1.tc;

			string dosyadakiTc;
			while (actc >> dosyadakiTc)
			{
				if (tc == dosyadakiTc) {
					h1.tc = dosyadakiTc;
					break;
				}
			}

			if (h1.tc.size() != 0) {
				yükleniyor();
				cout << "-------GÝRÝÞ YAPILDI---------  " << endl;
			}
			else {
				yükleniyor();
				cout << "------- Sistemde Kaydýnýz Bulunamadý Kayýt Olunuz -------" << endl;
				cout << " " << endl;
				cout << "ADINIZ :(BOSLUK OLMADAN YAZINIZ) " << endl;
				cin >> h1.ad;//boþluk girildiðinde hata vermemesi için
				cout << "SOYADINIZ : " << endl;
				cin >> h1.soyad;
				cout << "YAÞINIZ : " << endl;
				cin >> h1.yas;
				cout << " CÝNSÝYETÝNÝZ :" << endl;
				cin >> h1.cinsiyet;
				cout << "SÝGORTANIZ VAR  MI ?(Varsa - 1 | Yoksa - 0 ) " << endl;//evet hayýr düþündümm anlatýcam
				cin >> h1.sigortaDurumu;
				cout << " KAN GRUBUNUZ  : " << endl;
				cin >> h1.kanGrubu;
				cout << "KÝLONUZ : " << endl;
				cin >> h1.kilo;
				cout << "BOYUNUZ : " << endl;
				cin >> h1.boy;
				ofstream kaydet;
				ofstream kaydettc;
				kaydet.open(tc + ".txt", ios::app);
				kaydet << "AD : " << h1.ad << endl << "Soyad: " << h1.soyad << endl << "YAÞ      : " << h1.yas << endl << "CÝNSÝYET : " << h1.cinsiyet << endl << "KAN GRUBU: " << h1.kanGrubu << endl << "KÝLO     : " << h1.kilo << endl << "BOY      : " << h1.boy << endl << "RECETE   :  " << endl;
				if (h1.sigortaDurumu == 0) {


					kaydet << "SÝGORTA BULUNMAMAKTADIR" << endl;


				}
				kaydettc.open("Hastalar.txt", ios::app);
				kaydettc << "--- TC KÝMLÝK NUMARALARI ----" << endl;
				kaydettc << tc << endl;
				kaydettc.close();
				kaydet.close();
				yükleniyor();

			}


			do {
				cout << endl;
				h1.hastamenü();
				ofstream kaydet(tc + " rd.txt", ios::app);


				string tarih;
				string saat;
				string gecicitarih;
				cin >> sec;
				if (sec == 1) {
					yükleniyor();
					cout << "RANDEVU ALMA ÝÞLEMÝNÝ SEÇTÝNÝZ ." << endl;
					ifstream ranAl(tc + " rd.txt");
					string ranSatir;




					cout << "HANGÝ ANA BÝLÝM DALINDAN RANDEVU ALMAK ÝSTERSÝNÝZ ?" << endl;
					cout << "---------------------------------------------------------------------------------- " << endl;
					string  polikinlikler[5];
					polikinlikler[0] = "1 - Kalp  Cerrahisi";
					polikinlikler[1] = "2 - Beyin  Cerrahisi";
					polikinlikler[2] = "3 - Genel Cerrahi";
					polikinlikler[3] = "4 - Göz Hastalýklarý";
					polikinlikler[4] = "5 - KBB Hastalýklarý";

					cout << "----------------------------------------------------------------------------------- " << endl;

					for (string p : polikinlikler)
					{
						cout << p << endl;
					}
					cin >> al;
					string c;
					switch (al)
					{
						//hangi durum seçildiyse o hastanýn .txt  dosyasýna  o bölümüyazdýracaðýz
					case 1:

						cout << "kalp ve damar cerrahisi bölümünü seçtiniz " << endl;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ TARÝHÝ GÝRÝNÝZ : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ SAATÝ GÝRÝNÝZ :" << endl;
						cin >> saat;
						gecicitarih = "TARÝH-->" + tarih + "SAAT-->" + saat;

						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							yükleniyor();
							cout << "AYNI TARÝH VE SAATTE RANDEVUNUZ BULUNDUÐUNDAN RANDEVUNUZ ALINAMAMIÞTIR \n " << endl;

							cout << "-------------MENÜYE YÖNLENDÝRÝLÝYORSUNUZ-------------" << endl;
							break;


						}

						kaydet << "POLÝKÝNLÝK : " << polikinlikler[0] << endl << "TARÝH-->" << tarih << "SAAT-->" << saat << endl;
						system("CLS");

						cout << "RANDEVUNUZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;

						break;

					case 2:
						cout << "Beyin ve Sinir Cerrahisi bölümünü seçtiniz" << endl;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ TARÝHÝ GÝRÝNÝZ : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ SAATÝ GÝRÝNÝZ : " << endl;
						cin >> saat;
						gecicitarih = "TARÝH-->" + tarih + "SAAT-->" + saat;

						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							yükleniyor();
							cout << "AYNI TARÝH VE SAATTE RANDEVUNUZ BULUNDUÐUNDAN RANDEVUNUZ ALINAMAMIÞTIR" << endl;

							cout << "-------------MENÜYE YÖNLENDÝRÝLÝYORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POLÝKÝNLÝK : " << polikinlikler[1] << endl << "TARÝH-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;
						break;
					case 3:
						cout << "Genel Cerrahi bölümünü seçtiniz" << endl;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ TARÝHÝ GÝRÝNÝZ : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ SAATÝ GÝRÝNÝZ : " << endl;
						cin >> saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							yükleniyor();
							cout << "AYNI TARÝH VE SAATTE RANDEVUNUZ BULUNDUÐUNDAN RANDEVUNUZ ALINAMAMIÞTIR" << endl;

							cout << "-------------MENÜYE YÖNLENDÝRÝLÝYORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POLÝKÝNLÝK : " << polikinlikler[2] << endl << "TARÝH-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;
						break;
					case 4:
						cout << " Göz Hastalýklarý bölümünü seçtiniz" << endl;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ TARÝHÝ GÝRÝNÝZ : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ SAATÝ GÝRÝNÝZ : " << endl;
						cin >> saat;
						gecicitarih = "TARÝH-->" + tarih + "SAAT-->" + saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							yükleniyor();
							cout << "AYNI TARÝH VE SAATTE RANDEVUNUZ BULUNDUÐUNDAN RANDEVUNUZ ALINAMAMIÞTIR" << endl;

							cout << "-------------MENÜYE YÖNLENDÝRÝLÝYORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POLÝKÝNLÝK : " << polikinlikler[3] << endl << "TARÝH-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;
						break;
					case 5:
						cout << "Kulak Burun Boðaz Hastalýklarý bölümünü seçtiniz" << endl;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ TARÝHÝ GÝRÝNÝZ : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK ÝSTEDÝÐÝNÝZ SAATÝ GÝRÝNÝZ : " << endl;
						cin >> saat;
						gecicitarih = "TARÝH-->" + tarih + "SAAT-->" + saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							yükleniyor();
							cout << "AYNI TARÝH VE SAATTE RANDEVUNUZ BULUNDUÐUNDAN RANDEVUNUZ ALINAMAMIÞTIR" << endl;

							cout << "-------------MENÜYE YÖNLENDÝRÝLÝYORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POLÝKÝNLÝK : " << polikinlikler[4] << "  " << "TARÝH-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;
						break;
					default:
						system("CLS");
						cout << "BÖLÜM BULUNAMADI MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;

						break;
					}
					kaydet.close();
				}
				if (sec == 2) {
					string oku;
					int sil;
					int sil2 = 0;
					yükleniyor();
					cout << "RANDEVU SÝLME ÝÞLEMÝNÝ SEÇTÝNÝZ ." << endl;
					cout << endl;
					cout << endl;
					ifstream ranoku(tc + " rd.txt");
					ofstream gecici("gecici.txt", ios::app);
					while (!(ranoku.eof())) {

						for (int g = 0; g < 2; g++) {
							getline(ranoku, oku);
							cout << oku + " ";
						}
						cout << endl;
					}
					cout << endl;
					ranoku.close();

					cout << "------SÝLMEK ÝSTEDÝÐÝNÝZ RANDEVUNUN BULUNDUÐU SATIRI  GÝRÝNÝZ------" << endl;
					cin >> sil;
					ranoku.open(tc + " rd.txt");
					if (sil == 1) {
						getline(ranoku, oku);
						getline(ranoku, oku);

						while (getline(ranoku, oku)) {

							gecici << oku << endl;
						}

					}
					if (sil == 2) {

						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);

						while (getline(ranoku, oku)) {

							gecici << oku << endl;
						}

						ranoku.close();
						ifstream ranoku2;
						ranoku2.open(tc + " rd.txt");
						getline(ranoku2, oku);
						gecici << oku << endl;
						getline(ranoku2, oku);
						gecici << oku << endl;
					}
					if (sil == 3) {
						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);
						getline(ranoku, oku);

						while (getline(ranoku, oku)) {

							gecici << oku << endl;
						}

						ranoku.close();
						ifstream ranoku2;
						ranoku2.open(tc + " rd.txt");
						getline(ranoku2, oku);
						gecici << oku << endl;
						getline(ranoku2, oku);
						gecici << oku << endl;
						getline(ranoku2, oku);
						gecici << oku << endl;
						getline(ranoku2, oku);
						gecici << oku << endl;
					}
					oku = "";
					gecici.close();
					ifstream gecicioku;
					gecicioku.open("gecici.txt", ios::app);
					ranoku.close();
					ifstream ranoku2(tc + " rd.txt");
					ofstream ranyaz(tc + " rd.txt");
					while (getline(gecicioku, oku)) {
						ranyaz << oku << endl;
					}
					oku = "";

					yükleniyor();
					cout << "-------------GÜNCEL RANDEVULARINIZ-------------" << endl;
					while (getline(ranoku2, oku)) {
						cout << oku << endl;
					}
					ifstream gecoku2("gecici.txt");
					ofstream gecyaz("gecici.txt");
					gecoku2.close();
					gecyaz.close();
				}




				if (sec == 3) {
					yükleniyor();
					cout << "RANDEVU SORGULAMA ÝÞLEMÝNÝ SEÇTÝNÝZ ." << endl;
					cout << endl;
					ifstream ranSorgu(tc + " rd.txt");
					string sorgusatir;

					while (getline(ranSorgu, sorgusatir)) {

						cout << sorgusatir << endl;
					}
					ranSorgu.close();









				}
				if (sec == 4) {
					yükleniyor();
					string dosya;
					ifstream bilgiYazdir(tc + ".txt");

					cout << "--------BÝLGÝLERÝNÝZ--------" << endl;
					cout << endl;
					while (!(bilgiYazdir.eof())) {
						getline(bilgiYazdir, dosya);
						cout << dosya << endl;
					}
					cout << endl;
					cout << "--------GÜNCELLEYÝNÝZ--------" << endl;
					cout << endl;
					cout << "ADINIZ : " << endl;
					cin >> h1.ad;
					cout << "SOYADINIZ : " << endl;
					cin >> h1.soyad;
					cout << "YAÞINIZ : " << endl;
					cin >> h1.yas;
					cout << " CÝNSÝYETÝNÝZ :" << endl;
					cin >> h1.cinsiyet;
					cout << "SÝGORTANIZ VAR  MI ?(Varsa - 1 | Yoksa - 0 ) " << endl;
					cin >> h1.sigortaDurumu;
					cout << " KAN GRUBUNUZ  : " << endl;
					cin >> h1.kanGrubu;
					cout << "KÝLONUZ : " << endl;
					cin >> h1.kilo;
					cout << "BOYUNUZ : " << endl;
					cin >> h1.boy;
					ofstream bilgiYaz(tc + ".txt");
					bilgiYaz << "AD : " << h1.ad << endl << "Soyad: " << h1.soyad << endl << "YAÞ      : " << h1.yas << endl << "CÝNSÝYET : " << h1.cinsiyet << endl << "KAN GRUBU: " << h1.kanGrubu << endl << "KÝLO     : " << h1.kilo << endl << "BOY      : " << h1.boy << endl << "RECETE   :  " << endl;
					if (h1.sigortaDurumu == 0) {


						bilgiYaz << "SÝGORTA BULUNMAMAKTADIR" << endl;


					}
					cout << endl;
					yükleniyor();
					cout << "-----BÝLGÝLERÝNÝZ GÜNCELLENMÝÞTÝR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ----" << endl;


				}


				if (sec == 5) {
					string a;
					string b;
					int i = 0;
					int j = 0;
					yükleniyor();
					cout << "BORÇ SORGULAMA ÝÞLEMÝNÝ SEÇTÝNÝZ ." << endl;
					ifstream borcSorgu(tc + " rd.txt");
					ifstream tcBorcSorgu(tc + ".txt");
					while (getline(tcBorcSorgu, b)) {


						j++;


					}
					if (j == 9) {
						while (getline(borcSorgu, a)) {

							i++;


						}
						borcSorgu.close();

						cout << "SÝGORTANIZ OLMADIÐINDAN TOPLAM BORCUNUZ :  " << i * 100 / 2 << " TL " << endl;//HER RANDEVU 2 SATIR KAPLADIÐINDAN



					}
					else {

						cout << "BORCUNUZ SAÐLIK SÝGORTASI TARAFINDAN KARÞILANMAKTADIR" << endl;

					}
					tcBorcSorgu.close();
				}



			} while (sec != 6);

			cout << "SÝSTEMDEN ÇIKIÞ YAPILMIÞTIR ..." << endl;
		}

		if (kullanýcý == 2) {
			cout << "--------------DOKTOR MENÜSÜ--------------" << endl;
			cout << endl;
			cout << endl;
			cout << " 1 --> Kayýt Ol " << endl << " 2 -->  Giriþ Yap" << endl;
			cin >> dkt;

			if (dkt == 1) {
				string sifre = "Tm.3010";
				string sifreal;
				cout << "Hastanameizin size kayýt olmak için vermiþ olduðu þifreyi giriniz" << endl;
				cin >> sifreal;
				void yükleniyor();
				if (sifreal == sifre) {



					cout << "---------ÞÝFRE DOGRU KAYIT OLUNUZ----------" << endl;

					cout << " " << endl;
					cout << " TC KÝMLÝK NUMARANIZ : " << endl;
					cin >> d1.tc;
					cout << "ADINIZ : " << endl;
					cin >> d1.ad;
					cout << "SOYADINIZ : " << endl;
					cin >> d1.soyad;

					cout << "YAÞINIZ : " << endl;
					cin >> d1.yas;
					cout << " CÝNSÝYETÝNÝZ :" << endl;
					cin >> d1.cinsiyet;
					cout << "BRANÞINIZ " << endl;
					cin >> d1.branþ;
					cout << " TELEFON NUMARANIZ : " << endl;
					cin >> d1.telNo;
					ofstream dKaydet;
					ofstream dKaydettc;
					dKaydet.open(d1.tc + ".txt", ios::app);
					dKaydet << "AD : " << d1.ad << endl << "Soyad : " << d1.soyad << endl << "YAÞ      : " << d1.yas << endl << "CÝNSÝYET : " << d1.cinsiyet << endl << "BRANÞ :  " << d1.branþ << endl << "TEL NO :   " << d1.telNo << endl;

					dKaydettc.open("DOKTORLAR.txt", ios::app);
					dKaydettc << "--- TC KÝMLÝK NUMARASI ----" << endl;
					dKaydettc << d1.tc << endl;
					dKaydettc.close();
					dKaydet.close();

					yükleniyor();
					cout << "KAYDINIZ OLUÞTURULMUÞTUR MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl;
					cout << endl;

					sifreal = "";
				}


				else {

					yükleniyor();

					cout << "SÝFRE YANLIÞ GÝRÝÞ SAYFASINA YÖNLENDÝRÝLÝYORSUNUZ " << endl;
					cout << endl;
					sifreal = "";

				}

			}
			if (dkt == 2) {
				yükleniyor();
				cout << "------------GÝRÝÞ EKRANI----------------" << endl;
				cout << endl;
				cout << "LÜTFEN TC KÝMLÝK NUMARANIZI GÝRÝNÝZ" << endl;
				cin >> tc;
				ifstream acdoktor;
				acdoktor.open("DOKTORLAR.txt");
				string dosyaTc;
				while (acdoktor >> dosyaTc) {

					if (tc == dosyaTc) {

						d1.tc = dosyaTc;

						break;
					}



				}
				if (d1.tc.size() != 0) {
					d1.tc = "";
					yükleniyor();

					cout << "-------GÝRÝÞ YAPILDI---------  " << endl;

					do {

						cout << "YAPMAK ÝSTEDÝÐÝNÝZ ÝÞLEMÝ SEÇÝNÝZ ? " << endl;
						cout << "---------------------------------------------------------------------------------- " << endl;
						cout << " 1 -->  MAAÞ SORGULAMA      <-- 1 " << endl;
						cout << " 2 -->  HASTA GÖRÜNTÜLEME   <-- 2 " << endl;//
						cout << " 3 -->  RECETE YAZMA        <-- 3 " << endl;
						cout << " 4 -->  ÇIKIÞ YAP           <-- 4 " << endl;//
						cout << "---------------------------------------------------------------------------------- " << endl;
						cin >> sec;



						switch (sec) {


						case 1:

							yükleniyor();
							cout << "--------MAAÞ SORGULAMA EKRANI----------" << endl;
							cout << endl;
							cout << "GÜNLÜK ÇALIÞMA SAATÝNÝZÝ GÝRÝNÝZ : " << endl;
							cin >> d1.calýsmaSaati;

							d1.MaasHesapla(d1.calýsmaSaati);


							cout << endl;



							cout << endl;


							break;


						case 2:
							hGörüntüle();

							break;


						case 3:

							receteyaz();

							break;




						}





					} while (sec != 4);


				}
				else {
					yükleniyor();
					cout << "GÝRÝLEN TC YANLIÞ MENÜYE YÖNLENDÝRÝLÝYORSUNUZ" << endl << endl;
				}
			}

		}
	} while (kullanýcý != 3);
	cout << "program kapatýlýyor..." << endl;

}