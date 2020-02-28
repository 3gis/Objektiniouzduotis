#include "functions.h"

int main(){
    int studentusk=-1;
    string pasirinkimas;
    bool vidurkis = false;
    while(true){
        cout << "Skaiciuoti vidurki? (jei ne, bus skaiciuojama mediana) (Y/N)";
        cin >> pasirinkimas;
        if(pasirinkimas=="y" || pasirinkimas=="Y"){
            vidurkis = true;
            cout << "Bus skaiciuojamas vidurkis..\n";
            break;
        }
        else if (pasirinkimas=="n" || pasirinkimas=="N"){
            cout << "Bus skaiciuojama mediana..\n";
            break;
=======
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct studentai {
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
    studentai* kitas = NULL;
};
int naujasStudentas(int& studentusk, studentai*& M);
int main(){
    int studentusk=0;
    studentai *studentas = new studentai();
    naujasStudentas(studentusk, studentas);
    cout << fixed << setprecision(2);          //lentele
    cout << "Pavarde";
    cout << setw(10)<< " Vardas ";
    cout << setw(5)<< "";
    cout << setw(10) << " Galutinis (Vid.) / Galutinis (Med.)" << endl;
    while(studentas->kitas){
    cout << studentas->pavarde;
    cout << setw(15) << studentas->vardas;
    cout << setw(15) << studentas->galutinisVid;
    cout << setw(20) << studentas->galutinisMed << endl;
    studentas = studentas->kitas;
    }
    return 0;
}
int naujasStudentas(int& studentusk, studentai*& M){
    char pasirinkimas;
    int suma=0;
    int masyvod=0;
    vector<int> namudarbai;
    studentai* temp = M;
    while(true){
    cout << "Ar norite prideti studenta? (Y/N)";
    cin >> pasirinkimas;
    if(pasirinkimas=='y' || pasirinkimas=='Y'){
            studentusk++;
            while(temp->kitas){
                temp = temp->kitas;
            }
            cout << "Iveskite studento varda: ";
            cin >> temp->vardas;
            cout << endl << "Iveskite studento pavarde: ";
            cin >> temp->pavarde;
            cout << endl << "Ar norite atsitiktinai sugeneruoti rezultatus? (Y/N): ";
            cin >> pasirinkimas;
            if(pasirinkimas == 'Y' || pasirinkimas == 'y'){
                int limitas = rand() % 100 + 1;
                for(int i = 0; i<limitas;i++){
                    masyvod++;
                         namudarbai.push_back(rand() % 10 + 1);
                    namudarbai.push_back(rand() % 10 + 1); // egzamino balas
                }
            }
            else{
            while(true){
                cout << endl << "Iveskite studento namu darbu pazymius (Iveskite ne skaiciu arba 0, kad baigtumete irasyma): " << endl;
                string p;
                cin >> p;
                double x = atof(p.c_str());
                cout << "Priimtas kaip: " << x << endl;
                if(x!=0){
                    if(x-floor(x)==0){
                        masyvod++;
                        namudarbai.push_back(x);
                    }
                    else cout << "Tik sveikieji skaiciai!" << endl;
                }
                else{
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << endl << "Namu darbu rezultatu irasymas baigtas.." << endl;
                    while(true){
                        cout << "Iveskite egzamino rezultata: ";
                        cin >> p;
                        x = atof(p.c_str());
                        cout << "Priimtas kaip: " << x << endl;
                        if(x!=0){
                            if(x-floor(x)==0){
                                masyvod++;
                                namudarbai.push_back(x);
                                break;
                            }
                            else cout << "Tik sveikieji skaiciai!" << endl;
                        }
                        else{
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                    }
                    break;
                }
            }
        }
    vector<studentai> studentas;
    naujasStudentas(studentusk, studentas,vidurkis);
    sort(studentas.begin(), studentas.end(), lyginimas);
    spausdinti(studentas,vidurkis);
    return 0;
}
