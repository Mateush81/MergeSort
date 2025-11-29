#pragma once
#include <vector>


/**
 *@brief Klasa implementuj¹ca algorytm sortowania przez scalanie (Merge Sort).
 * 
 * Szablon klasy pozwala na sortowanie wektorów dowolnego typu T,
 * pod warunkiem, ¿e typ T obs³uguje operator porównania <=.
 * 
 * Przyk³ad u¿ycia:
 * 
 * std::vector<int> arr = {5, 2, 9, 1, 5, 6};
 * MergeSort<int>::sort(arr);
 * 
 * Po wywo³aniu metody sort(), wektor vec bêdzie posortowany rosn¹co.
 * 
 * @tparam T Typ elementów wektora do posortowania (int, double, itp.).
 */


template<typename T>
class MergeSort {
public:

    /**
     * @brief Sortuje wektor arr za pomoc¹ algorytmu sortowania przez scalanie.
     * 
     * @param arr Wektor do posortowania.
	 */


    static void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) return;
        mergeSort(arr, 0, arr.size() - 1);
    }

private:

    /**
     * @brief Rekurencyjna funkcja sortuj¹ca podwektory i scalaj¹ca je.
     * 
     * @param arr Wektor do posortowania.
     * @param left Lewy indeks podwektora.
	 * @param right Prawy indeks podwektora.
     */




    static void mergeSort(std::vector<T>& arr, int left, int right) {
		if (left >= right) return; // bez elementu lub pusty

        int mid = (left + right) / 2;

		// sortowanie lewej i prawej po³owy
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

		// scalanie posortowanych po³ówek
        merge(arr, left, mid, right);
    }


    /**
     * @brief Scala dwa posortowane podwektory w jeden posortowany.
     * 
     * @param arr Wektor zawieraj¹cy podwektory do scalenia.
     * @param left Lewy indeks pierwszego podwektora.
     * @param mid Œrodkowy indeks (koniec pierwszego podwektora).
     * @param right Prawy indeks drugiego podwektora.
     * 
	 */

    static void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

		// bufory tymczasowe dla podwektorów L i R
        std::vector<T> L(n1), R(n2);


		// kopiowanie danych do podwektorów L i R
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;


		// scalanie podwektorów z powrotem do arr
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }


		// kopiowanie pozosta³ych elementów z L, jeœli s¹
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

		// kopiowanie pozosta³ych elementów z R, jeœli s¹
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

