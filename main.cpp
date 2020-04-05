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
            ofstream ff ("kursiokai.txt");
            spausdinti(studentas,vidurkis, ff);
        }
        else if(pasirinkimas=="y" || pasirinkimas=="Y"){
            int k;


            vector <studentai> kietekai;
            vector <studentai> vargsiukai;
            vector <studentai> studentas;
            cout << "Kuriami failai..\n ";
            ofstream fk ("kietekai.txt");
            ofstream fv ("vargsiukai.txt");
            string failuPavadinimai[5]={"Pirmas.txt","Antras.txt","Trecias.txt","Ketvirtas.txt","Penktas.txt"};
            for(k = 0; k<5;k++){

                Generuotifailus(failuPavadinimai[k], k);
                TestNuskaitymas(failuPavadinimai[k], k, studentas);
                cout << "Sarasas rikiuojamas su funkcija sort.. \n";
                 auto start = std::chrono::high_resolution_clock::now();
                sort(studentas.begin(), studentas.end(),testLyginimas);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start;
                cout << "=== Rikiavimas uztruko: " << diff.count() << "\n";
                cout << "Sarasas rusiuojamas i vargsiukus ir kietekus \n";
                TestRusiavimas(k,studentas, kietekai, vargsiukai);
                cout << "Spausdinami sarasai i atskirus failus.. \n";
                start = std::chrono::high_resolution_clock::now();
                spausdinti(kietekai,true,fk);
                end = std::chrono::high_resolution_clock::now();
                diff = end-start;
                cout << "=== Kieteku spausdinimas uztruko: " << diff.count() << "\n";
                start = std::chrono::high_resolution_clock::now();
                spausdinti(vargsiukai,true, fk);
                end = std::chrono::high_resolution_clock::now();
                diff = end-start;
                cout << "=== Vargsiuku spausdinimas uztruko: " << diff.count() << "\n";
                studentas.clear();
                vargsiukai.clear();
                kietekai.clear();
                cout << "----------------------------\n";
            }
        }
    }
    return 0;
}
