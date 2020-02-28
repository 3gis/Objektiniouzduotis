#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

using std::cout; // pakeista
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

struct studentai {
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
};

int naujasStudentas(int& studentusk, vector<studentai>& M, bool& vidurkis);
double mediana(vector<int>M, int masyvod);
bool lyginimas(const studentai& a, const studentai& b);
void spausdinti(vector<studentai> studentas, bool vidurkis);

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
            }
        }
    vector<studentai> studentas;
    naujasStudentas(studentusk, studentas,vidurkis);
    sort(studentas.begin(), studentas.end(), lyginimas);
    spausdinti(studentas,vidurkis);
    return 0;
}

int naujasStudentas(int& studentusk, vector<studentai>& M, bool& vidurkis){
    string pasirinkimas;
    string p;
    float suma=0;
    int masyvod=0;
    vector<int> namudarbai;
    while(true){
        cout << "Ar norite skaityti is failo? (Y/N)";
        cin >> pasirinkimas;
        if(pasirinkimas=="y" || pasirinkimas=="Y"){
            ifstream fd;
            cout << "**Ikelkite txt faila i programos aplankala!** \n Iveskite txt failo pavadinima: <pavadinimas>.txt \n";
            cin >> pasirinkimas;
            cout << "\n";
           if(pasirinkimas[pasirinkimas.length()-4]=='.')
                fd.open(pasirinkimas);
            else
                fd.open(pasirinkimas + ".txt");
            //    string n;
            //    fd >> n;
            //cout << n << endl;
            if(fd.is_open()){
                std::stringstream ss;
                ss << fd.rdbuf();
                fd.close();
                int stulpeliai = 0;
                while(ss >> pasirinkimas){
                    if(pasirinkimas=="Egz." || pasirinkimas=="Egzaminas"){
                        stulpeliai++;
                        break;
                    }
                    else
                        stulpeliai++;
                }
                while(!ss.eof()){
                    studentusk++; // ?
                    M.push_back(studentai());
                    ss >> M[studentusk].vardas >> M[studentusk].pavarde;
                    for(int i = 0; i<stulpeliai-3;i++){
                        ss >> pasirinkimas;
                        suma+=atof(pasirinkimas.c_str());
                        namudarbai.push_back(atof(pasirinkimas.c_str()));
                        //cout << pasirinkimas << " ";
                    }
                    ss >> p;
                    namudarbai.push_back(atof(p.c_str()));
                    if(vidurkis==true)
                        M[studentusk].galutinisVid=((double)(suma/(stulpeliai-3)) * 0.40 + 0.60 * atof(p.c_str()));
                    else{
                        sort(namudarbai.begin(),namudarbai.end());
                        M[studentusk].galutinisMed=mediana(namudarbai, stulpeliai-2);
                    }
                    suma = 0;
                    namudarbai.clear();
                    //cout << studentusk << endl;*/
                }
                cout << "Nuskaityta: " << studentusk+1 << " rezultatu \n";
                naujasStudentas(studentusk,M,vidurkis);
                return 0;
            }
            else{
                cout << "Failas nerastas!!! \n";
            }
        }
        else{
            cout << "Rankinis studentu irasymas... \n";
            break;
        }
    }
    while(true){
    cout << "Ar norite prideti studenta? (Y/N)";
    cin >> pasirinkimas;
    if(pasirinkimas=="y" || pasirinkimas=="Y"){
            studentusk++;
            M.push_back(studentai());
            cout << "Iveskite studento varda: ";
            cin >> M[studentusk].vardas;
            cout << endl << "Iveskite studento pavarde: ";
            cin >> M[studentusk].pavarde;
            cout << endl << "Ar norite atsitiktinai sugeneruoti rezultatus? (Y/N): ";
            cin >> pasirinkimas;
            if(pasirinkimas == "Y" || pasirinkimas == "y"){
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
                cin >> p;
                if(p[1]==',')
                    p[1]='.';
                else if (p[2]==',')
                    p[2]='.';
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
                        if(p[1]==',')
                            p[1]='.';
                        else if (p[2]==',')
                            p[2]='.';
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
    }
    else{
        cout << "Rezultatu irasymas baigtas.." << endl;
        return 0;
    }
    break;
    }
        for (int i = 0; i<masyvod-1; i++)
            suma+=namudarbai[i];
        M[studentusk].galutinisVid = (double)suma/(masyvod-1) * 0.4 + 0.6 * namudarbai.back();
        sort(namudarbai.begin(), namudarbai.end());
        M[studentusk].galutinisMed = mediana(namudarbai,masyvod);
        cout << "-----------------------------------------" << endl;
        namudarbai.clear();
        naujasStudentas(studentusk,M,vidurkis);
}
double mediana(vector<int>M, int masyvod){
    return masyvod%2==0 ? (double)(((M[(masyvod/2)-2]) + (M[(masyvod/2)]))/2.0) : M[(masyvod/2)];
}
bool lyginimas(const studentai& a, const studentai& b){
    return a.pavarde < b.pavarde;
}
void spausdinti(vector<studentai> studentas, bool vidurkis){
    char buffer[80];
    ofstream ff ("kursiokai.txt");
    if(vidurkis==true)
        sprintf(buffer, "%-20s %-20s %-20s \n", "Pavarde", "Vardas", "Galutinis (Vid.)");
    else
        sprintf(buffer, "%-20s %-20s %-20s \n", "Pavarde", "Vardas", "Galutinis (Med.)");
    ff << buffer;
    for(int i = 0; i<80;i++,ff << "-");
    ff << "\n";
    if(vidurkis==true){
        for(auto i : studentas){
                sprintf(buffer,"%-20s %-20s %-20.2lf \n", i.pavarde.c_str(), i.vardas.c_str(), i.galutinisVid);
            ff << buffer;
        }
    }
    else{
        for(auto i : studentas){
                sprintf(buffer,"%-20s %-20s %-20.2lf \n", i.pavarde.c_str(), i.vardas.c_str(), i.galutinisMed);
            ff << buffer;
        }
    }
    cout << "Rezultatai irasyti i kursiokai.txt faila \n";


}
