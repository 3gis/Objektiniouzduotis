#include <iostream>
#include <iomanip>
using namespace std;

struct studentai {
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
    studentai* kitas = NULL;
};
int naujasStudentas(int& studentusk, studentai*& M);
int* masyvoDidinimas(int dydis, int* M,int pasirinkimas);
void Rikiuoti(int* M, int n);
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
int* masyvoDidinimas(int dydis, int* M,int pasirinkimas){
    int* P = new int[dydis];
    for(int* i = P;i<P+dydis;i++){
        for(int* j = M; j<M+dydis-1;j++){
            *i = *j;
            i++;
        }
        *i = pasirinkimas;
        break;
    }
    //delete [] M;
    M = P;
    //delete P;
    return M;
}
int naujasStudentas(int& studentusk, studentai*& M){
    char pasirinkimas;
    int suma=0;
    int masyvod=0;
    int* namudarbai = new int();
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
                    if(masyvod == 1)
                        *namudarbai = rand() % 10;
                    else
                        namudarbai = masyvoDidinimas(masyvod, namudarbai, rand() % 10);
                    namudarbai = masyvoDidinimas(masyvod, namudarbai, rand() % 10); // egzamino balas
                }
            }
            else{
            while(true){
                cout << endl << "Iveskite studento namu darbu pazymius (Iveskite ne skaiciu, kad baigtumete irasyma): " << endl;
                int p;
                cin >> p;
                if(!cin.fail()){
                    masyvod++;
                    if(masyvod == 1)
                        *namudarbai = p;
                    else
                        namudarbai = masyvoDidinimas(masyvod, namudarbai, p);
                    }
                else{
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << endl << "Namu darbu rezultatu irasymas baigtas.." << endl;
                    while(true){
                        cout << "Iveskite egzamino rezultata: ";
                        cin >> p;
                        if(!cin.fail()){
                            masyvod++;
                            namudarbai = masyvoDidinimas(masyvod, namudarbai, p);
                            break;
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
    else if (pasirinkimas == 'N' || pasirinkimas == 'n')
            return 0;
    else{}
    break;
    }
        for(int i = 0; i<masyvod-1;i++)
            suma+=namudarbai[i];
        temp->galutinisVid = (double)suma/(masyvod-1) * 0.4 + 0.6 * *(namudarbai+masyvod-1);
        temp->kitas = new studentai();
        Rikiuoti(namudarbai,masyvod);
        if(masyvod%2==0)
            temp->galutinisMed = (*(namudarbai+1+(masyvod/2)-2) + *(namudarbai+(masyvod/2)))/2.0;
        else
            temp->galutinisMed = *(namudarbai + (masyvod/2));
        cout << "-----------------------------------------" << endl;
        naujasStudentas(studentusk,M);
}

void Rikiuoti(int* M, int n){
    for(int i = 0; i<n;i++)
        for(int j = 0; j<n;j++)
            if(*(M+i)<*(M+j))
                swap(*(M+i),*(M+j));
}
