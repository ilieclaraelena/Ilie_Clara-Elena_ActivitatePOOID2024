#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Autobuz {
private:
    const int idAutobuz;
    static int nrAutobuze;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;
public:
    Autobuz() :idAutobuz(++nrAutobuze) {
        this->capacitate = 10;
        this->nrPersoaneImbarcate = 8;
        this->producator = new char[strlen("BMW") + 1];
        strcpy(producator, "BMW");
    }
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) :idAutobuz(++nrAutobuze) {
        if (capacitate > 0)
            this->capacitate = capacitate;
        if (nrPersoaneImbarcate < capacitate)
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        if (producator != NULL) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
    }
    ~Autobuz() {
        if (producator != NULL)
            delete[]producator;
    }
    Autobuz(const Autobuz& a) :idAutobuz(++a.nrAutobuze) {
        this->capacitate = a.capacitate;
        this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        this->producator = new char[strlen(a.producator) + 1];
        strcpy(this->producator, a.producator);

    }
    int getnrPersoaneImbarcate() {
        return nrPersoaneImbarcate;
    }
    void setnrPersoaneImbarcate(int nrPersoaneImbarcate, int capacitate) {
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        this->capacitate = capacitate;
        if (nrPersoaneImbarcate < capacitate)
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;

    }
    char* getproducator() {
        return producator;
    }
    void setproducator(const char* newproducator) {
        if (this->producator != NULL)
            delete[]this->producator;
        this->producator = new char[strlen(newproducator) + 1];
        strcpy(producator, newproducator);
    }
    Autobuz& operator =(Autobuz& a) {
        if (&a != this) {
            if (producator != NULL)
                delete[]producator;
            this->capacitate = a.capacitate;
            this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
            this->producator = new char[strlen(a.producator) + 1];
            strcpy(this->producator, a.producator);
            return*this;
        }
        else {
            return *this;
        }
    }

    friend ostream& operator<<(ostream& out, Autobuz& a) {
        out << "Id ul autobuz:" << a.idAutobuz << "; Numarul autobuze:"
            << a.nrAutobuze<< "; Capacitate autobuz:" << a.capacitate 
            << "; Numar persoane imbarcate:"<< a.nrPersoaneImbarcate<<"; Producator:" << a.producator;
        return out;
    }

    int getNumarLocuriLibere() {
        int NumarLocuriLibere = capacitate - nrPersoaneImbarcate;
        return NumarLocuriLibere;
    }
    bool operator >(Autobuz& a) {
        if (this->capacitate > a.capacitate)
            return false;
        else
            return true;
    }
    explicit operator int() {
        return nrPersoaneImbarcate;
    }
};
int Autobuz::nrAutobuze = 0;

int main() {

    //constructor fara parametrii
    Autobuz autobuz1;
    cout << "Autobuzul 1 are urmatoarele date:" << endl;
    cout << autobuz1 << endl;

    cout << "----------------------" << endl;

    //constructor cu parametrii
    Autobuz autobuz2(20, 12, "Volvo");
    cout << "Autobuzul 2 are urmatoarele date:" << endl;
    cout << autobuz2 << endl;

    cout << "----------------------" << endl;

    // constructor de copiere 
    Autobuz autobuz3(autobuz2);
    cout << "Autobuzul 3 are urmatoarele date:" << endl;
    cout << autobuz3 << endl;

    cout << "----------------------" << endl;

    //Testare metode accesor
    autobuz2.setnrPersoaneImbarcate(9, 7);
    cout << "Numarul de persoane imbarcate in autobuzul 2 este: ";
    cout << autobuz2.getnrPersoaneImbarcate() << endl;

    autobuz1.setproducator("Toyota");
    cout << "Numele producatorului pentru autobuzul 1: ";
    cout << autobuz1.getproducator() << endl;


    cout << "Numarul de locuri libere din autobuzul 1 este: ";
    cout << autobuz1.getNumarLocuriLibere() << endl;

    cout << "----------------------" << endl;

    //Testare operator =
    Autobuz autobuz4;
    autobuz4 = autobuz1;
    cout << "Autobuzul 4 are urmatoarele date:" << endl;
    cout << autobuz4 << endl;

    //Testare operator >;
    if (autobuz1 > autobuz2)
        cout << "Autobuzul 1 are capacitate mai mare."<<endl;
    else
        cout << "Autobuzul 2 are capacitate mai mare."<<endl;

    //Testare operatr cast 
    cout << (int)autobuz4 << endl;
}