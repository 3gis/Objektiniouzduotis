#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class studentai {
private:
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
public:
    inline string getVardas() const { return vardas;}
    inline string getPavarde() const {return pavarde;}
    inline double getGalutinisVid() const {return galutinisVid;}
    inline double getGalutinisMed() const {return galutinisMed;}
    inline void setVardas(string x) {this-> vardas = x;}
    inline void setPavarde(string x) {this-> pavarde = x;}
    inline void setGalutinisVid(double x){ this->galutinisVid = x;}
    inline void setGalutinisMed(double x){ this->galutinisMed = x;}

};
int naujasStudentas(int& studentusk, vector<studentai>& M, bool& vidurkis);
double mediana(vector<int>M, int masyvod);
bool lyginimas( studentai& a, studentai& b);
bool testLyginimas( studentai& a,  studentai& b);
void spausdinti(vector<studentai>& studentas, bool vidurkis, ofstream& ff);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, vector <studentai>& M);
void TestRusiavimas(int& k, vector <studentai>& studentas, vector<studentai>& kietekai);

#endif // FUNCTIONS_H_INCLUDED
