#include "pch.h"
#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;



// Zgodnie z poleceniem tworzone s¹ dwa wektory:
// - jeden z typem int,
// - drugi z typem double.

// Nastêpnie oba wektory s¹ sortowane za pomoc¹ klasy MergeSort,
// a wyniki s¹ wypisywane na ekran.



int main() {

    // wektor do intów
    vector<int> a = { 18, 27, 43, 10, 5, 99, 1 };

	// sortowanie wektora intów
    MergeSort<int>::sort(a);

	// wyœwietlanie posortowanego wektora intów
    cout << "Posortowane inty: ";
    for (const auto& x : a) cout << x << " ";
    cout << endl;

	// wektor do double'ów
    vector<double> b = { 3.14, 2.71, 1.41, 1.73, 0.577 };

	// sortowanie wektora double'ów
    MergeSort<double>::sort(b);

	// wyœwietlanie posortowanego wektora double'ów
    cout << "Posortowane double: ";
    for (const auto& x : b) cout << x << " ";
    cout << endl;

    return 0;
}


