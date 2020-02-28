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
            }
        }
    vector<studentai> studentas;
    naujasStudentas(studentusk, studentas,vidurkis);
    sort(studentas.begin(), studentas.end(), lyginimas);
    spausdinti(studentas,vidurkis);
    return 0;
}
