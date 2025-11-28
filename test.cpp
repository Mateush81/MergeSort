#include "pch.h"
#include "mergesort.h"   


// Testy jednostkowe dla MergeSort
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

















// Prosty test sortowania intów
TEST(MergeSortTests, SortIntBasic) {
    std::vector<int> v = { 5, 2, 9, 1, 0 };
    MergeSort<int>::sort(v);

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 5);
    EXPECT_EQ(v[4], 9);
}

// Test jednego elementu
TEST(MergeSortTests, SingleElement) {
    std::vector<int> v = { 42 };
    MergeSort<int>::sort(v);

    EXPECT_EQ(v[0], 42);
}

// Test pustego wektora
TEST(MergeSortTests, EmptyVector) {
    std::vector<int> v;
    MergeSort<int>::sort(v);

    EXPECT_TRUE(v.empty());
}

// Test duplikatów
TEST(MergeSortTests, Duplicates) {
    std::vector<int> v = { 4, 4, 2, 2, 4 };
    MergeSort<int>::sort(v);

    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 4);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 4);
}

// Test liczb typu double
TEST(MergeSortTests, SortDoubleBasic) {
    std::vector<double> v = { 3.1, 2.2, 5.5, 1.0 };
    MergeSort<double>::sort(v);

    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.2);
    EXPECT_DOUBLE_EQ(v[2], 3.1);
    EXPECT_DOUBLE_EQ(v[3], 5.5);
}

