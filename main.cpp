#include "pch.h"
#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

int main() {

    vector<int> a = { 18, 27, 43, 10, 5, 99, 1 };
    MergeSort<int>::sort(a);

    cout << "Posortowane inty: ";
    for (const auto& x : a) cout << x << " ";
    cout << endl;

    vector<double> b = { 3.14, 2.71, 1.41, 1.73, 0.577 };
    MergeSort<double>::sort(b);

    cout << "Posortowane double: ";
    for (const auto& x : b) cout << x << " ";
    cout << endl;

    return 0;
}


