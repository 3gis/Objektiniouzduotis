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
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::deque;
using std::list;

struct studentai {
    string vardas;
    string pavarde;
    double galutinisVid;
    double galutinisMed;
};

int naujasStudentas(int& studentusk, deque<studentai>& M, bool& vidurkis);
double mediana(deque<int>M, int masyvod);
bool lyginimas(const studentai& a, const studentai& b);
bool testLyginimas(const studentai& a, const studentai& b);
void spausdinti(deque<studentai>& studentas, bool vidurkis, string pavadinimas);
void spausdinti(list<studentai>& studentas, bool vidurkis, string pavadinimas);
void Generuotifailus(string a, int& b);
void TestNuskaitymas(string pasirinkimas, int& b, list <studentai>& M);
void TestRusiavimas(int& k,list <studentai>& studentas, list<studentai>& kietekai, list<studentai>& vargsiukai);

#endif // FUNCTIONS_H_INCLUDED
