#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <chrono>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::list;
using std::ifstream;
using std::ofstream;

class studentai {
private:
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
public:
    studentai& operator=(const studentai& gc1);
    inline string getVardas() const  {return vardas;}
    inline string getPavarde() const {return pavarde;}
    inline double getGalutinisVid() const {return galutinisVid;}
    inline double getGalutinisMed() const {return galutinisMed;}
    inline void setVardas(string x) {this-> vardas = x;}
    inline void setPavarde(string x) {this-> pavarde = x;}
    inline void setGalutinisVid(double x){ this->galutinisVid = x;}
    inline void setGalutinisMed(double x){ this->galutinisMed = x;}

};
ofstream& operator << (ofstream& os, const studentai& gc);
int naujasStudentas(int& studentusk, list<studentai>& M, bool& vidurkis);
double mediana(vector<int>M, int masyvod);
bool lyginimas( studentai& a, studentai& b);
bool testLyginimas(studentai& a, studentai& b);
void spausdinti(list<studentai>& studentas, bool vidurkis, ofstream& ff);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, list <studentai>& M);
void TestRusiavimas(int& k,list <studentai>& studentas, list<studentai>& kietekai);

#endif // FUNCTIONS_H_INCLUDED
