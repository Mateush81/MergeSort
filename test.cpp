#include "pch.h"
#include "mergesort.h"   


// Testy jednostkowe dla MergeSort
// Jeden test to jeden przypadek użycia funkcji sortującej
// Różne typy danych i różne scenariusze

/*

• 1. zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco,
• 2. potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności,
• 3. poprawnie sortuje losową tablicę liczb,                                            =========> działa poprawnie ✅ <=========
• 4. poprawnie sortuje tablice tylko z liczbami ujemnymi,
• 5. poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi,
• 6. obsługuje pustą tablicę bez rzucania wyjątkiem,                                    =========> działa poprawnie ✅ <=========
• 7. nie zmienia tablicy, która zawiera tylko jeden element,                            =========> działa poprawnie ✅ <=========
• 8. poprawnie sortuje tablicę z duplikatami liczb,                                     =========> działa poprawnie ✅ <=========
• 9. poprawnie sortuje tablice ujemną z duplikatami,
• 10. poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami,
• 11. poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej,
• 12. poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów,
• 13. poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami

*/



// 1. tablica już posortowana rosnąco ( powinno pozostać be zmian )
TEST(MergeSortTests, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{1, 2, 3, 4, 5}));
}



// 2. tablica posortowana odwrotnie
TEST(MergeSortTests, ReverseSorted) {
    std::vector<int> v = { 5, 4, 3, 2, 1 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{1, 2, 3, 4, 5}));
}

// 3. losowa tablica
TEST(MergeSortTests, RandomNumbers) {
    std::vector<int> v = { 7, 1, 4, 9, 2 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{1, 2, 4, 7, 9}));
}

// 4. tylko liczby ujemne
TEST(MergeSortTests, NegativeOnly) {
    std::vector<int> v = { -5, -1, -10, -3 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{-10, -5, -3, -1}));
}

// 5. mieszane ujemne i dodatnie
TEST(MergeSortTests, MixedNegativePositive) {
    std::vector<int> v = { -3, 7, -1, 4 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{-3, -1, 4, 7}));
}

// 6. pusta tablica
TEST(MergeSortTests, EmptyVector) {
    std::vector<int> v;
    MergeSort<int>::sort(v);
    EXPECT_TRUE(v.empty());
}

// 7. jeden element
TEST(MergeSortTests, SingleElement) {
    std::vector<int> v = { 42 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v[0], 42);
}

// 8. duplikaty
TEST(MergeSortTests, Duplicates) {
    std::vector<int> v = { 4, 4, 2, 2, 4 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{2, 2, 4, 4, 4}));
}

// 9. ujemne z duplikatami
TEST(MergeSortTests, NegativeDuplicates) {
    std::vector<int> v = { -2, -5, -2, -1, -5 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{-5, -5, -2, -2, -1}));
}

// 10. ujemne, dodatnie i duplikaty
TEST(MergeSortTests, MixedAll) {
    std::vector<int> v = { -2, 4, -2, 7, 0, 4 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{-2, -2, 0, 4, 4, 7}));
}

// 11. dwa elementy posortowane
TEST(MergeSortTests, TwoElements) {
    std::vector<int> v = { 1, 2 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{1, 2}));
}

// 12. duża tablica (100 elementów)
TEST(MergeSortTests, LargeVector) {
    std::vector<int> v;
    for (int i = 100; i >= 1; i--)
        v.push_back(i);

    MergeSort<int>::sort(v);

    for (int i = 0; i < 100; i++)
        EXPECT_EQ(v[i], i + 1);
}

// 13. duża tablica mix (ujemne, dodatnie, duplikaty)
TEST(MergeSortTests, LargeMixedVector) {
    std::vector<int> v;
    for (int i = -50; i <= 50; i++)
        v.push_back(i);
    for (int i = -10; i <= 10; i++)
        v.push_back(i); // duplikaty

    MergeSort<int>::sort(v);

    // sprawdzamy pierwsze i ostatnie elementy,
    // żeby nie pisać 120 expectów
    EXPECT_EQ(v.front(), -50);   // front() to pierwszy element -> powinien być najmniejszy możliwy = -50
    EXPECT_EQ(v.back(), 50);    // back() to ostatni element -> powinien być największy możliwy = 50
}