#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <deque>
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
using std::deque;
using std::ifstream;
using std::ofstream;

class studentai {
private:
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
public:
    inline string getVardas() const  {return vardas;}
    inline string getPavarde() const {return pavarde;}
    inline double getGalutinisVid() const {return galutinisVid;}
    inline double getGalutinisMed() const {return galutinisMed;}
    inline void setVardas(string x) {this-> vardas = x;}
    inline void setPavarde(string x) {this-> pavarde = x;}
    inline void setGalutinisVid(double x){ this->galutinisVid = x;}
    inline void setGalutinisMed(double x){ this->galutinisMed = x;}

};

int naujasStudentas(int& studentusk, deque<studentai>& M, bool& vidurkis);
double mediana(deque<int>M, int masyvod);
bool lyginimas( studentai& a, studentai& b);
bool testLyginimas( studentai& a, studentai& b);
void spausdinti(deque<studentai>& studentas, bool vidurkis, ofstream& ff);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, deque <studentai>& M);
void TestRusiavimas(int& k, deque <studentai>& studentas, deque<studentai>& kietekai);

#endif // FUNCTIONS_H_INCLUDED
