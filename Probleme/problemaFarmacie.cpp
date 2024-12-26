#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Farmacie{
private:
    const int CODUnic;
    static int nrFarmacii;
    char* adresa;
    int nrMedicamente;
    float* preturiMedicamente;

public:
Farmacie(): CODUnic(++nrFarmacii){
    this->adresa= new char[strlen("Victoriei")+1];
    strcpy(this-> adresa, "victoriei");
    this-> nrMedicamente = 2;
    this-> preturiMedicamente = new float[nrMedicamente];
    preturiMedicamente[0] = 5;
    preturiMedicamente[1] = 8;
}
Farmacie(int CODUnic, const char* adresa, int nrMedicamente, float* preturiMedicamente):CODUnic(++nrFarmacii){
    
    this->adresa= new char[strlen(adresa)+1];
    strcpy(this-> adresa, adresa);
    this-> nrMedicamente = nrMedicamente;
    this-> preturiMedicamente = new float[this->nrMedicamente];
    for(int i =0; i< this-> nrMedicamente; i++){
        this-> preturiMedicamente[i] = preturiMedicamente[i];
    }
}
~Farmacie(){
    if(adresa != NULL){
        delete[] adresa;
    }
    if(preturiMedicamente != NULL){
        delete[]preturiMedicamente;
    }
    }
Farmacie(const Farmacie& f):CODUnic(++nrMedicamente){
    this->adresa= new char[strlen(f.adresa)+1];
    strcpy(this-> adresa, f.adresa);
    this-> nrMedicamente = f.nrMedicamente;
    this-> preturiMedicamente = new float[f.nrMedicamente];
    for(int i =0; i < f.nrMedicamente; i++){
        this-> preturiMedicamente[i] = f.preturiMedicamente[i];
    }
}
char* getAdresa() {
    return this->adresa;
}
void setadresa(char* adresaNoua){
    if (this->adresa != NULL) {
        delete[] this->adresa;
    }
    this->adresa = new char[strlen(adresaNoua) + 1];
    strcpy(this->adresa, adresaNoua);
}
int getnrMedicamente(){
    return nrMedicamente;

}
const int getCOUDUnic(){
    return CODUnic;
}
Farmacie& operator=(const Farmacie& f){
    if(adresa != NULL){
        delete[] adresa;
    }
    if(preturiMedicamente != NULL){
        delete[] preturiMedicamente;
    }
    this->adresa = new char[strlen(f.adresa)+1];
    strcpy(adresa, f.adresa);
    this-> nrMedicamente =f.nrMedicamente;
    this-> preturiMedicamente = new float[f.nrMedicamente];
    for(int i= 0; i < f.nrMedicamente; i++){
        this->preturiMedicamente[i] =f.preturiMedicamente[i];
    }
    return* this;
}
friend ostream &operator<<(ostream& out, Farmacie& f){
    cout<<"Cod unic farmacie: ";
    out<<f.CODUnic <<endl;
    cout<<"Adresa farmaciei este: ";
    out<<f.adresa << endl;
    cout<<"Numar medicamente: ";
    out<<f.nrMedicamente << endl;
    cout<<"Preturile medicamentelor:"<< endl;
    for(int i = 0; i < f.nrMedicamente; i++){
        out <<f.preturiMedicamente[i]<< endl;
    }
    return out;

}
friend istream &operator>>(istream& in, Farmacie& f){
    cout<<"Introduceti adresa farmaciei: "<< endl;
    char buffer[100];
    in>> buffer;
    delete[]f.adresa;
    f.adresa = new char[strlen(buffer)+1];
    strcpy(f.adresa, buffer);
    cout<<"Introduceti numar medicamente: "<< endl;
    in>> f.nrMedicamente;
    cout<<"Preturile medicamentelor:"<< endl;
    delete[]f.preturiMedicamente;
    f.preturiMedicamente = new float[f.nrMedicamente];
    for(int i = 0; i < f.nrMedicamente; i++){
        in >> f.preturiMedicamente[i];
    }   
    return in; 
}

float getNrMedicamenteIeftine(){
    int contor = 0;
    int valoareReala =8;
    for(int i =0; i < nrMedicamente; i++){
        if(preturiMedicamente[i]< valoareReala){
            contor++;
        }
    }
    return contor;
}
bool operator>(Farmacie& f){
    if(this->nrMedicamente > f.nrMedicamente)
        return true;
    else
        return false;
}

};
int Farmacie :: nrFarmacii = 0;
int main(){

    Farmacie farmacie1;
    cout << farmacie1 << endl;

    float preturiMedicamente[] ={3, 5, 6, 8, 9};
    Farmacie farmacie2(2, "Romana" , 4, preturiMedicamente);
    cout << farmacie2 <<endl;

    //Constructorul de copiere
    Farmacie farmacie3(farmacie1);
    cout<<"Farmacia 3 are urmatoarele date:"<< endl;
    cout << farmacie3 << endl;

    //Testare operator =
    Farmacie farmacie4;
    farmacie4 =farmacie2; // la farmacie 3 imi da codul unic de la farmacie 1 nu 2
    cout<<"Farmacia 4 are urmatoarele date:"<< endl;
    cout<<farmacie4<<endl;

    //Testare operator>> 
    Farmacie farmacia5;
    cout<<"Introduceti date pentru farmacia 5:"<< endl;
    cin>> farmacia5;
    cout<<"Farmacia 5 are urmatoarele date:" <<endl;
    cout<< farmacia5<<endl;
    

    cout << "Numărul de medicamente ieftine în farmacia2: "
         << farmacie2.getNrMedicamenteIeftine() << endl;


    //operator >
    if(farmacie1 >farmacie2)
        cout<<"Farmacie1 are mai multe medicamente";
    else    
        cout<<"Farmacie2 are mai multe medicamente";

    return 0;
}
