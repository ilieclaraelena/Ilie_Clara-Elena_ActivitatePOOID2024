#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
enum Tip { familie, singur };
class Hotel {
	const int nrCamera;
	int etaj;
	char* denumire;
	Tip tip;
	string* facilitati;
	int nrFacilitati;
public:
	Hotel() :nrCamera(1) {
		this->etaj = 2;
		this->denumire = new char[strlen("Aurora") + 1];
		strcpy(this->denumire, "Aurora");
		this->tip = familie;
		this->nrFacilitati = 2;
		this->facilitati = new string[nrFacilitati];
		for (int i = 0; i < this->nrFacilitati; i++) {
			this->facilitati[0] = 2;
			this->facilitati[1] = 3;
		}
	}
	Hotel(const int nrCamera, int etaj, const char* denumire, Tip tip, string* facilitati, int nrFacilitati) :nrCamera(nrCamera) {
		this->etaj = etaj;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->tip = tip;
		this->nrFacilitati = nrFacilitati;
		this->facilitati = new string[nrFacilitati];
		for (int i = 0; i < this->nrFacilitati; i++) {
			this->facilitati[i] = facilitati[i];
		}
	}
	~Hotel() {
		if (denumire != NULL) {
			delete[] denumire;
		}
		if (facilitati != NULL) {
			delete[]facilitati;
		}
	}
	Hotel(const Hotel& h) : nrCamera(h.nrCamera) {
		this->etaj = h.etaj;
		this->denumire = new char[strlen(h.denumire) + 1];
		strcpy(this->denumire, h.denumire);
		this->tip = h.tip;
		this->nrFacilitati = h.nrFacilitati;
		this->facilitati = new string[h.nrFacilitati];
		for (int i = 0; i < h.nrFacilitati; i++) {
			this->facilitati[i] = h.facilitati[i];
		}
	}

	void setnewdenumire(const char* newDenumire) {
		if (newDenumire != NULL) {
			if (denumire != NULL) {
				delete[]denumire;
				this->denumire = new char[strlen(newDenumire) + 1];
				strcpy(this->denumire, newDenumire);
			}
		}
		else { // nu punem char* pe NUULL
			delete[]denumire;
			this->denumire = new char[strlen("Aurora") + 1];
			strcpy(this->denumire, "Aurora");
		}
	}

	char* getdenumire() {
		return denumire;
	}
	void setFacilitati(string* facilitati, int nrFacilitati) {
		if (facilitati != NULL) {
			this->nrFacilitati = nrFacilitati;
			if (this->facilitati != NULL)
				delete[] this->facilitati;
			this->facilitati = new string[nrFacilitati];
			for (int i = 0; i < this->nrFacilitati; i++) {
				this->facilitati[i] = facilitati[i];
			}
		}
		else {
			
			if (this->facilitati != NULL) {
				delete[]this->facilitati;
			}
			this->nrFacilitati = 2;
			this->facilitati = new string[this->nrFacilitati];
			for (int i = 0; i < this->nrFacilitati; i++) {
				this->facilitati[0] = "masaj";
				this->facilitati[1] = "sauna";
			}
		}

	}
	string getFacilitate(int pozitie) {
		if (pozitie < nrFacilitati && pozitie > 0)
			return facilitati[pozitie];
		else
			return "pozitie invalida"; 
	}
	string* getFacilitati() {
		return facilitati;
	}
	int operator++(int) {
		Hotel copie = *this;
		etaj++;
		return copie.etaj;
	}
	
	int operator++() {
		
		return ++etaj;
	}


	friend ostream& operator<<(ostream& out, Hotel& h) {
		out << h.nrCamera << endl;
		out << h.etaj << endl;
		out << h.denumire << endl;
		out << h.nrFacilitati << endl;
		for (int i = 0; i < h.nrFacilitati; i++) {
			out << h.facilitati[i] << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Hotel& h) {
		in >> h.etaj;
		char buffer[100];
		in >> buffer;
		delete[]h.denumire;
		h.denumire = new char[strlen(buffer) + 1];
		strcpy(h.denumire, buffer);
		in >> h.nrFacilitati;
		delete[]h.facilitati;
		h.facilitati = new string[h.nrFacilitati];
		for (int i = 0; i < h.nrFacilitati; i++) {
			in >> h.facilitati[i];
		}
		return in;
	}
};
int main() {

	Hotel h1;
	cout << h1 << endl;

	Hotel h2(4, 5, "Sinaia", singur, new string[3]{ "sauna", "piscina", "masaj" }, 3);
	cout << h2 << endl;

	Hotel h3(h2);
	cout << h3 << endl;

	h2.setnewdenumire(NULL);
	cout << h2.getdenumire() << endl;

	h2.setFacilitati(NULL, 0);
	cout << h2 << endl;
	cout << h2.getFacilitate(1) << endl;
	cout << h2.getFacilitate(7) << endl;
	cout << ++h1 << endl;
	cout << h2++ << endl;

	cin >> h1;
	cout << h1 << endl;

}