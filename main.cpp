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
            vector<studentai> studentas;
            naujasStudentas(studentusk, studentas,vidurkis);
            sort(studentas.begin(), studentas.end(), lyginimas);
            spausdinti(studentas,vidurkis, "kursiokai.txt");
        }
        else if(pasirinkimas=="y" || pasirinkimas=="Y"){
            int k = 5;
            cout << "Kuriami atsitiktiniai failai... \n";
            Generuotifailus("Pirmas.txt", k);
            vector <studentai> kietekai;
            vector <studentai> vargsiukai;
            vector <studentai> studentas;
            TestNuskaitymas("Pirmas.txt", k, studentas);
            cout << "Sarasas rikiuojamas su funkcija sort.. \n";
             auto start = std::chrono::high_resolution_clock::now();
            sort(studentas.begin(), studentas.end(),testLyginimas);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << "Rikiavimas uztruko: " << diff.count() << "\n";
            cout << "Sarasas rusiuojamas i vargsiukus ir kietekus \n";
            TestRusiavimas(k,studentas, kietekai, vargsiukai);
            cout << "Spausdinami sarasai i atskirus failus.. \n";
            start = std::chrono::high_resolution_clock::now();
            spausdinti(kietekai,true,"kietekai.txt");
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Rikiavimas uztruko: " << diff.count() << "\n";
            start = std::chrono::high_resolution_clock::now();
            spausdinti(vargsiukai,true, "vargsiukai.txt");
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Rikiavimas uztruko: " << diff.count() << "\n";
        }
    }
    return 0;
}
