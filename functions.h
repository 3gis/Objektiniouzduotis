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
    public:
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
};

int naujasStudentas(int& studentusk, list<studentai>& M, bool& vidurkis);
double mediana(vector<int>M, int masyvod);
bool lyginimas(const studentai& a, const studentai& b);
bool testLyginimas(const studentai& a, const studentai& b);
void spausdinti(list<studentai>& studentas, bool vidurkis, ofstream& ff);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, list <studentai>& M);
void TestRusiavimas(int& k,list <studentai>& studentas, list<studentai>& kietekai, list<studentai>& vargsiukai);

#endif // FUNCTIONS_H_INCLUDED
