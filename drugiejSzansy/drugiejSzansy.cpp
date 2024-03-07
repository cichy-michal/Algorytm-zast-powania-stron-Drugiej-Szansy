#include <iostream>
#include <fstream>
using namespace std;

const int kolumny = 20;
int strony[kolumny];
int liczbaRamek;
int liczbaZastapien = 0;
bool czyJuzJest = false;

int main() {
    ifstream plik("dane2.txt"); // Otwiera plik do odczytu
    for (int i = 0; i < kolumny; i++) plik >> strony[i];
    plik >> liczbaRamek; // Wczytanie 2 linii z pliku do zmiennej
    plik.close();   // Zamyka plik

    int ramki[liczbaRamek][liczbaRamek];
    for (int i = 0; i < liczbaRamek; i++) ramki[1][i] = 0; // Dodanie wiersza z bitami odniesienia
    for (int i = 0; i < liczbaRamek; i++) ramki[0][i] = strony[i]; // Wypelnienie pustych ramek
    for (int i = 0; i < liczbaRamek; i++) cout << ramki[0][i] << " "; // Wyswietlanie aktualnych zawartosci ramek
    cout << "Ramki po 3 wejsciach "  << endl;
    for (int i = liczbaRamek; i < kolumny; i++) { // Glowna petla po stronach
        for (int j = 0; j < liczbaRamek; j++) {
            if(ramki[0][j] == strony[i]){ // Sprawdzenie czy dana strona juz jest w ktorejs z ramek
                czyJuzJest = true;
                ramki[1][j] = 1;
            } 
        }
        if(!czyJuzJest){ // Zmiana ramek
            for(int j = 0; j < liczbaRamek; j++){
                if(ramki[1][j] == 1){
                    ramki[1][j] = 0;
                    if(j == liczbaRamek-1) j = -1;
                    continue;
                }
                if(j == liczbaRamek-1) ramki[0][j] = strony[i];
                else ramki[0][j] = ramki[0][j+1];
            }
            liczbaZastapien++; // Zapis zastapienia strony
        }
        czyJuzJest = false;
        for (int k = 0; k < liczbaRamek; k++) cout << ramki[0][k] << " "; // Wyswietlanie aktualnych zawartosci ramek
        cout << "Ramki po "<< i+1 <<" wejsciach " << endl;
    }
    cout << "Liczba zastapionych stron "<< liczbaZastapien << endl; // // Wyswietlanie liczby zastapionych stron
    ofstream plikk; // Przesyla raport programu do pliku
    plikk.open("wynik2Szansy.txt");
    plikk << "Ilosc zastapionych stron dla metody drugiej szansy: " << liczbaZastapien<< endl;
    plikk.close();
    return 0;
}