#include "functions.h"

int main(){
    int studentusk=-1;
    string pasirinkimas;
    bool vidurkis = false;
    while(true){
        cout << " Ar norite testuoti greicius? (Y/N) \n";
        cin >> pasirinkimas;
            if (pasirinkimas=="n" || pasirinkimas=="N"){
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
            deque<studentai> studentas;
            naujasStudentas(studentusk, studentas,vidurkis);
            sort(studentas.begin(), studentas.end(), lyginimas);
            spausdinti(studentas,vidurkis, "kursiokai.txt");
        }
        else if(pasirinkimas=="y" || pasirinkimas=="Y"){
            int k = 5;
            cout << "Kuriami atsitiktiniai failai... \n";
            Generuotifailus("Pirmas.txt", k);
            deque <studentai> kietekai;
            deque <studentai> vargsiukai;
            deque <studentai> studentas;
            TestNuskaitymas("Pirmas.txt", k, studentas);
            cout << "Sarasas rikiuojamas su funkcija sort.. \n";
            sort(studentas.begin(), studentas.end(),testLyginimas);
            cout << "Sarasas rusiuojamas i vargsiukus ir kietekus \n";
            TestRusiavimas(k,studentas, kietekai, vargsiukai);
            cout << "Spausdinami sarasai i atskirus failus.. \n";
            spausdinti(kietekai,true,"kietekai.txt");
            spausdinti(vargsiukai,true, "vargsiukai.txt");
            studentas.clear();
            kietekai.clear();
            vargsiukai.clear();
        }
    }
    return 0;
}
