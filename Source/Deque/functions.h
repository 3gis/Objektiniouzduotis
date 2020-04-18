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
    public:
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
};

int naujasStudentas(int& studentusk, deque<studentai>& M, bool& vidurkis);
double mediana(deque<int>M, int masyvod);
bool lyginimas(const studentai& a, const studentai& b);
bool testLyginimas(const studentai& a, const studentai& b);
void spausdinti(deque<studentai>& studentas, bool vidurkis, ofstream& ff);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, deque <studentai>& M);
void TestRusiavimas(int& k, deque <studentai>& studentas, deque<studentai>& kietekai);

#endif // FUNCTIONS_H_INCLUDED
