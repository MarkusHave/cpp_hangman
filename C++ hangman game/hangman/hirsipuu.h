#pragma once

#include <iostream>
#include <ctime> //aika kirjasto
#include <string> //stringit
#include <fstream> //tideostojen käsittely
#include <windows.h>  //sleep
#include <vector> //vectorit

using namespace std;

int Menu();
int Tarkastus(string, string, string&);
void Peli(int, int, string, string);
void Loppu(bool, string);
int Asetukset(int, vector<string>&, vector<string>&, vector<string>&);
void ArvMaara(int);
void Tulosta(vector<string>&);
bool Poista(string, vector<string>&);
void PoistaFunk(vector<string>&, vector<string>&, vector<string>&);
void TulostaFunk(vector<string>&, vector<string>&, vector<string>&);
void UusiSana(vector<string>&);
void Save(vector<string>&);



