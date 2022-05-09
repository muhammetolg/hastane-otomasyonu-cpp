#include<windows.h>
#include <iostream>
#include <fstream>      // dosya i�lemleri i�in
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


	void hastamen�() {
		cout << "HANG� H�ZMET�M�ZDEN YARARLANMAK �STERS�N�Z ?  " << endl;
		cout << "---------------------------------------------------------------------------------- " << endl;
		cout << " 1 -->  RANDEVU ALMA       <-- 1 " << endl;
		cout << " 2 -->  RANDEVU S�LME      <-- 2 " << endl;//
		cout << " 3 -->  RANDEVU SORGULAMA  <-- 3 " << endl;//Text dosyas� yazd�r�lacak
		cout << " 4 -->  B�LG� G�NCELLEME   <-- 4 " << endl;
		cout << " 5 -->  BOR� G�R�NT�LEME   <-- 5" << endl;
		cout << " 6 -->  �IKI� YAP          <-- 6 " << endl;
		cout << "---------------------------------------------------------------------------------- " << endl;
	}



};


class Calisan {


public:

	string ad, soyad, cinsiyet, unvan, tc;
	int yas, maas, cal�smaSaati, saatlikUcret;
	long telNo;


	Calisan() {}

	Calisan(string ad, string soyad, string cinsiyet, string unvan, int yas, int maas, int cal�smaSaati, int saatlikUcret, long telNo, string tc) {

		ad = ad;
		soyad = soyad;
		cinsiyet = cinsiyet;
		unvan = unvan;
		maas = maas;
		yas = yas;
		telNo = telNo;
		tc = tc;
		cal�smaSaati = cal�smaSaati;
		saatlikUcret = saatlikUcret;
	}

	void Cal�sanaMesaj() {
		cout << "* Ba�l�l���n�z ve s�k� �al��man�z i�in te�ekk�r ederiz...*" << endl;
	}
	virtual void  MaasHesapla(int cal�smaSaati) = 0;            // SAF SANAL FONKS�YON .



};

class Doktor : public Calisan {



public:

	string bran�;
	Hasta hasta;

	Doktor() {


	}
	Doktor(string ad, string soyad, string cinsiyet, string unvan, int yas, int maas, int cal�smaSaati, int saatlikUcret, long telNo, string tc, string bran�, Hasta hasta) :Calisan(ad, soyad, cinsiyet, unvan, yas, maas, cal�smaSaati, saatlikUcret, telNo, tc) {

		hasta = hasta;
		bran� = bran�;


	}

	void MaasHesapla(int cal�smaSaati) {
		saatlikUcret = 200;
		maas = cal�smaSaati * saatlikUcret * 30;
		system("CLS");
		cout << " BU AY ALACA�INIZ MAA�  :  " << maas << " TL " << endl;

	}
	void  receteYaz(Hasta& h) {
		cout << "hastan�n re�etesini girin." << endl;
		cin >> h.recete;


	}




};
void y�kleniyor() {

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
void hG�r�nt�le() {

	Hasta h1;
	string htc;
	ifstream achtc;
	string ghasta;

	cout << "--------HASTA G�R�NT�LEME EKRANI----------" << endl;
	cout << endl;
	cout << endl;
	cout << "G�r�nt�lemek �stedi�iniz Hastan�n Tc Kimlik Numaras�n� Giriniz : " << endl;
	cin >> htc;
	y�kleniyor();

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
		y�kleniyor();

		cout << "B�YLE B�R HASTA BULUNAMADI TEKRAR DENEY�N�Z" << endl;




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
	cout << "Recete Yazmak  �stedi�iniz Hastan�n Tc Kimlik Numaras�n� Giriniz : " << endl;
	cin >> htc;
	y�kleniyor();

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
		y�kleniyor();
		cout << "Receteye girmek istedi�iniz ilac� yaz�n�z" << endl;
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
		cout << "Receteye Yazd�r�ld� Men�ye Y�nlendiriliyorsunuz " << endl;
		cout << endl;
		cout << endl;
		geciciac.close();
		system("del gecici.txt");
	}

	else {
		y�kleniyor();

		cout << "B�YLE B�R HASTA BULUNAMADI TEKRAR DENEY�N�Z" << endl;




	}







}
int main() {
	system("COLOR 80");
	setlocale(LC_ALL, "Turkish");
	Doktor d1;
	Hasta h1;
	int kullan�c�;
	int sec;
	int al;
	int dkt;


	do {
		cout << ".......... HO�GELD�N�Z .........." << endl << endl << endl << "kullan�c� durumunuza kar��l�k gelen numaray� giriniz.." << endl;
		cout << " 1 --> HASTA " << endl << " 2 -->  DOKTOR" << endl;
		cout << " PROGRAMI KAPAMAK ���N 3'� TU�LAYINIZ.";
		cin >> kullan�c�;
		y�kleniyor();
		string tc;
		if (kullan�c� == 1) {
			cout << "--------------HASTA MEN�S�--------------" << endl;
			cout << endl;
			cout << endl;

			cout << "TC Kimlik Numaran�z� Giriniz" << endl;
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
				y�kleniyor();
				cout << "-------G�R�� YAPILDI---------  " << endl;
			}
			else {
				y�kleniyor();
				cout << "------- Sistemde Kayd�n�z Bulunamad� Kay�t Olunuz -------" << endl;
				cout << " " << endl;
				cout << "ADINIZ :(BOSLUK OLMADAN YAZINIZ) " << endl;
				cin >> h1.ad;//bo�luk girildi�inde hata vermemesi i�in
				cout << "SOYADINIZ : " << endl;
				cin >> h1.soyad;
				cout << "YA�INIZ : " << endl;
				cin >> h1.yas;
				cout << " C�NS�YET�N�Z :" << endl;
				cin >> h1.cinsiyet;
				cout << "S�GORTANIZ VAR  MI ?(Varsa - 1 | Yoksa - 0 ) " << endl;//evet hay�r d���nd�mm anlat�cam
				cin >> h1.sigortaDurumu;
				cout << " KAN GRUBUNUZ  : " << endl;
				cin >> h1.kanGrubu;
				cout << "K�LONUZ : " << endl;
				cin >> h1.kilo;
				cout << "BOYUNUZ : " << endl;
				cin >> h1.boy;
				ofstream kaydet;
				ofstream kaydettc;
				kaydet.open(tc + ".txt", ios::app);
				kaydet << "AD : " << h1.ad << endl << "Soyad: " << h1.soyad << endl << "YA�      : " << h1.yas << endl << "C�NS�YET : " << h1.cinsiyet << endl << "KAN GRUBU: " << h1.kanGrubu << endl << "K�LO     : " << h1.kilo << endl << "BOY      : " << h1.boy << endl << "RECETE   :  " << endl;
				if (h1.sigortaDurumu == 0) {


					kaydet << "S�GORTA BULUNMAMAKTADIR" << endl;


				}
				kaydettc.open("Hastalar.txt", ios::app);
				kaydettc << "--- TC K�ML�K NUMARALARI ----" << endl;
				kaydettc << tc << endl;
				kaydettc.close();
				kaydet.close();
				y�kleniyor();

			}


			do {
				cout << endl;
				h1.hastamen�();
				ofstream kaydet(tc + " rd.txt", ios::app);


				string tarih;
				string saat;
				string gecicitarih;
				cin >> sec;
				if (sec == 1) {
					y�kleniyor();
					cout << "RANDEVU ALMA ��LEM�N� SE�T�N�Z ." << endl;
					ifstream ranAl(tc + " rd.txt");
					string ranSatir;




					cout << "HANG� ANA B�L�M DALINDAN RANDEVU ALMAK �STERS�N�Z ?" << endl;
					cout << "---------------------------------------------------------------------------------- " << endl;
					string  polikinlikler[5];
					polikinlikler[0] = "1 - Kalp  Cerrahisi";
					polikinlikler[1] = "2 - Beyin  Cerrahisi";
					polikinlikler[2] = "3 - Genel Cerrahi";
					polikinlikler[3] = "4 - G�z Hastal�klar�";
					polikinlikler[4] = "5 - KBB Hastal�klar�";

					cout << "----------------------------------------------------------------------------------- " << endl;

					for (string p : polikinlikler)
					{
						cout << p << endl;
					}
					cin >> al;
					string c;
					switch (al)
					{
						//hangi durum se�ildiyse o hastan�n .txt  dosyas�na  o b�l�m�yazd�raca��z
					case 1:

						cout << "kalp ve damar cerrahisi b�l�m�n� se�tiniz " << endl;
						cout << " RANDEVU ALMAK �STED���N�Z TAR�H� G�R�N�Z : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK �STED���N�Z SAAT� G�R�N�Z :" << endl;
						cin >> saat;
						gecicitarih = "TAR�H-->" + tarih + "SAAT-->" + saat;

						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							y�kleniyor();
							cout << "AYNI TAR�H VE SAATTE RANDEVUNUZ BULUNDU�UNDAN RANDEVUNUZ ALINAMAMI�TIR \n " << endl;

							cout << "-------------MEN�YE Y�NLEND�R�L�YORSUNUZ-------------" << endl;
							break;


						}

						kaydet << "POL�K�NL�K : " << polikinlikler[0] << endl << "TAR�H-->" << tarih << "SAAT-->" << saat << endl;
						system("CLS");

						cout << "RANDEVUNUZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;

						break;

					case 2:
						cout << "Beyin ve Sinir Cerrahisi b�l�m�n� se�tiniz" << endl;
						cout << " RANDEVU ALMAK �STED���N�Z TAR�H� G�R�N�Z : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK �STED���N�Z SAAT� G�R�N�Z : " << endl;
						cin >> saat;
						gecicitarih = "TAR�H-->" + tarih + "SAAT-->" + saat;

						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							y�kleniyor();
							cout << "AYNI TAR�H VE SAATTE RANDEVUNUZ BULUNDU�UNDAN RANDEVUNUZ ALINAMAMI�TIR" << endl;

							cout << "-------------MEN�YE Y�NLEND�R�L�YORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POL�K�NL�K : " << polikinlikler[1] << endl << "TAR�H-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;
						break;
					case 3:
						cout << "Genel Cerrahi b�l�m�n� se�tiniz" << endl;
						cout << " RANDEVU ALMAK �STED���N�Z TAR�H� G�R�N�Z : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK �STED���N�Z SAAT� G�R�N�Z : " << endl;
						cin >> saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							y�kleniyor();
							cout << "AYNI TAR�H VE SAATTE RANDEVUNUZ BULUNDU�UNDAN RANDEVUNUZ ALINAMAMI�TIR" << endl;

							cout << "-------------MEN�YE Y�NLEND�R�L�YORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POL�K�NL�K : " << polikinlikler[2] << endl << "TAR�H-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;
						break;
					case 4:
						cout << " G�z Hastal�klar� b�l�m�n� se�tiniz" << endl;
						cout << " RANDEVU ALMAK �STED���N�Z TAR�H� G�R�N�Z : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK �STED���N�Z SAAT� G�R�N�Z : " << endl;
						cin >> saat;
						gecicitarih = "TAR�H-->" + tarih + "SAAT-->" + saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							y�kleniyor();
							cout << "AYNI TAR�H VE SAATTE RANDEVUNUZ BULUNDU�UNDAN RANDEVUNUZ ALINAMAMI�TIR" << endl;

							cout << "-------------MEN�YE Y�NLEND�R�L�YORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POL�K�NL�K : " << polikinlikler[3] << endl << "TAR�H-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;
						break;
					case 5:
						cout << "Kulak Burun Bo�az Hastal�klar� b�l�m�n� se�tiniz" << endl;
						cout << " RANDEVU ALMAK �STED���N�Z TAR�H� G�R�N�Z : " << endl;
						cin >> tarih;
						cout << " RANDEVU ALMAK �STED���N�Z SAAT� G�R�N�Z : " << endl;
						cin >> saat;
						gecicitarih = "TAR�H-->" + tarih + "SAAT-->" + saat;
						while (ranAl >> ranSatir) {


							if (gecicitarih == ranSatir) {

								c = ranSatir;
								break;
							}



						}

						if (c.size() != 0) {
							y�kleniyor();
							cout << "AYNI TAR�H VE SAATTE RANDEVUNUZ BULUNDU�UNDAN RANDEVUNUZ ALINAMAMI�TIR" << endl;

							cout << "-------------MEN�YE Y�NLEND�R�L�YORSUNUZ-------------" << endl;
							break;


						}
						kaydet << "POL�K�NL�K : " << polikinlikler[4] << "  " << "TAR�H-" << tarih << "SAAT-" << saat << endl;
						system("CLS");
						cout << "RANDEVUNUZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;
						break;
					default:
						system("CLS");
						cout << "B�L�M BULUNAMADI MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;

						break;
					}
					kaydet.close();
				}
				if (sec == 2) {
					string oku;
					int sil;
					int sil2 = 0;
					y�kleniyor();
					cout << "RANDEVU S�LME ��LEM�N� SE�T�N�Z ." << endl;
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

					cout << "------S�LMEK �STED���N�Z RANDEVUNUN BULUNDU�U SATIRI  G�R�N�Z------" << endl;
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

					y�kleniyor();
					cout << "-------------G�NCEL RANDEVULARINIZ-------------" << endl;
					while (getline(ranoku2, oku)) {
						cout << oku << endl;
					}
					ifstream gecoku2("gecici.txt");
					ofstream gecyaz("gecici.txt");
					gecoku2.close();
					gecyaz.close();
				}




				if (sec == 3) {
					y�kleniyor();
					cout << "RANDEVU SORGULAMA ��LEM�N� SE�T�N�Z ." << endl;
					cout << endl;
					ifstream ranSorgu(tc + " rd.txt");
					string sorgusatir;

					while (getline(ranSorgu, sorgusatir)) {

						cout << sorgusatir << endl;
					}
					ranSorgu.close();









				}
				if (sec == 4) {
					y�kleniyor();
					string dosya;
					ifstream bilgiYazdir(tc + ".txt");

					cout << "--------B�LG�LER�N�Z--------" << endl;
					cout << endl;
					while (!(bilgiYazdir.eof())) {
						getline(bilgiYazdir, dosya);
						cout << dosya << endl;
					}
					cout << endl;
					cout << "--------G�NCELLEY�N�Z--------" << endl;
					cout << endl;
					cout << "ADINIZ : " << endl;
					cin >> h1.ad;
					cout << "SOYADINIZ : " << endl;
					cin >> h1.soyad;
					cout << "YA�INIZ : " << endl;
					cin >> h1.yas;
					cout << " C�NS�YET�N�Z :" << endl;
					cin >> h1.cinsiyet;
					cout << "S�GORTANIZ VAR  MI ?(Varsa - 1 | Yoksa - 0 ) " << endl;
					cin >> h1.sigortaDurumu;
					cout << " KAN GRUBUNUZ  : " << endl;
					cin >> h1.kanGrubu;
					cout << "K�LONUZ : " << endl;
					cin >> h1.kilo;
					cout << "BOYUNUZ : " << endl;
					cin >> h1.boy;
					ofstream bilgiYaz(tc + ".txt");
					bilgiYaz << "AD : " << h1.ad << endl << "Soyad: " << h1.soyad << endl << "YA�      : " << h1.yas << endl << "C�NS�YET : " << h1.cinsiyet << endl << "KAN GRUBU: " << h1.kanGrubu << endl << "K�LO     : " << h1.kilo << endl << "BOY      : " << h1.boy << endl << "RECETE   :  " << endl;
					if (h1.sigortaDurumu == 0) {


						bilgiYaz << "S�GORTA BULUNMAMAKTADIR" << endl;


					}
					cout << endl;
					y�kleniyor();
					cout << "-----B�LG�LER�N�Z G�NCELLENM��T�R MEN�YE Y�NLEND�R�L�YORSUNUZ----" << endl;


				}


				if (sec == 5) {
					string a;
					string b;
					int i = 0;
					int j = 0;
					y�kleniyor();
					cout << "BOR� SORGULAMA ��LEM�N� SE�T�N�Z ." << endl;
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

						cout << "S�GORTANIZ OLMADI�INDAN TOPLAM BORCUNUZ :  " << i * 100 / 2 << " TL " << endl;//HER RANDEVU 2 SATIR KAPLADI�INDAN



					}
					else {

						cout << "BORCUNUZ SA�LIK S�GORTASI TARAFINDAN KAR�ILANMAKTADIR" << endl;

					}
					tcBorcSorgu.close();
				}



			} while (sec != 6);

			cout << "S�STEMDEN �IKI� YAPILMI�TIR ..." << endl;
		}

		if (kullan�c� == 2) {
			cout << "--------------DOKTOR MEN�S�--------------" << endl;
			cout << endl;
			cout << endl;
			cout << " 1 --> Kay�t Ol " << endl << " 2 -->  Giri� Yap" << endl;
			cin >> dkt;

			if (dkt == 1) {
				string sifre = "Tm.3010";
				string sifreal;
				cout << "Hastanameizin size kay�t olmak i�in vermi� oldu�u �ifreyi giriniz" << endl;
				cin >> sifreal;
				void y�kleniyor();
				if (sifreal == sifre) {



					cout << "---------��FRE DOGRU KAYIT OLUNUZ----------" << endl;

					cout << " " << endl;
					cout << " TC K�ML�K NUMARANIZ : " << endl;
					cin >> d1.tc;
					cout << "ADINIZ : " << endl;
					cin >> d1.ad;
					cout << "SOYADINIZ : " << endl;
					cin >> d1.soyad;

					cout << "YA�INIZ : " << endl;
					cin >> d1.yas;
					cout << " C�NS�YET�N�Z :" << endl;
					cin >> d1.cinsiyet;
					cout << "BRAN�INIZ " << endl;
					cin >> d1.bran�;
					cout << " TELEFON NUMARANIZ : " << endl;
					cin >> d1.telNo;
					ofstream dKaydet;
					ofstream dKaydettc;
					dKaydet.open(d1.tc + ".txt", ios::app);
					dKaydet << "AD : " << d1.ad << endl << "Soyad : " << d1.soyad << endl << "YA�      : " << d1.yas << endl << "C�NS�YET : " << d1.cinsiyet << endl << "BRAN� :  " << d1.bran� << endl << "TEL NO :   " << d1.telNo << endl;

					dKaydettc.open("DOKTORLAR.txt", ios::app);
					dKaydettc << "--- TC K�ML�K NUMARASI ----" << endl;
					dKaydettc << d1.tc << endl;
					dKaydettc.close();
					dKaydet.close();

					y�kleniyor();
					cout << "KAYDINIZ OLU�TURULMU�TUR MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl;
					cout << endl;

					sifreal = "";
				}


				else {

					y�kleniyor();

					cout << "S�FRE YANLI� G�R�� SAYFASINA Y�NLEND�R�L�YORSUNUZ " << endl;
					cout << endl;
					sifreal = "";

				}

			}
			if (dkt == 2) {
				y�kleniyor();
				cout << "------------G�R�� EKRANI----------------" << endl;
				cout << endl;
				cout << "L�TFEN TC K�ML�K NUMARANIZI G�R�N�Z" << endl;
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
					y�kleniyor();

					cout << "-------G�R�� YAPILDI---------  " << endl;

					do {

						cout << "YAPMAK �STED���N�Z ��LEM� SE��N�Z ? " << endl;
						cout << "---------------------------------------------------------------------------------- " << endl;
						cout << " 1 -->  MAA� SORGULAMA      <-- 1 " << endl;
						cout << " 2 -->  HASTA G�R�NT�LEME   <-- 2 " << endl;//
						cout << " 3 -->  RECETE YAZMA        <-- 3 " << endl;
						cout << " 4 -->  �IKI� YAP           <-- 4 " << endl;//
						cout << "---------------------------------------------------------------------------------- " << endl;
						cin >> sec;



						switch (sec) {


						case 1:

							y�kleniyor();
							cout << "--------MAA� SORGULAMA EKRANI----------" << endl;
							cout << endl;
							cout << "G�NL�K �ALI�MA SAAT�N�Z� G�R�N�Z : " << endl;
							cin >> d1.cal�smaSaati;

							d1.MaasHesapla(d1.cal�smaSaati);


							cout << endl;



							cout << endl;


							break;


						case 2:
							hG�r�nt�le();

							break;


						case 3:

							receteyaz();

							break;




						}





					} while (sec != 4);


				}
				else {
					y�kleniyor();
					cout << "G�R�LEN TC YANLI� MEN�YE Y�NLEND�R�L�YORSUNUZ" << endl << endl;
				}
			}

		}
	} while (kullan�c� != 3);
	cout << "program kapat�l�yor..." << endl;

}