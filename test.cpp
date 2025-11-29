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










// podstawowy test sortowania int
TEST(MergeSortTests, BasicIntSort) {
    std::vector<int> v = { 5, 3, 1, 4, 2 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{1, 2, 3, 4, 5}));
}

// sortowanie double
TEST(MergeSortTests, BasicDoubleSort) {
    std::vector<double> v = { 2.5, 1.1, 3.3 };
    MergeSort<double>::sort(v);
    EXPECT_EQ(v, (std::vector<double>{1.1, 2.5, 3.3}));
}

// pusty
TEST(MergeSortTests, Empty) {
    std::vector<int> v;
    MergeSort<int>::sort(v);
    EXPECT_TRUE(v.empty());
}

// jeden element
TEST(MergeSortTests, Single) {
    std::vector<int> v = { 10 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v[0], 10);
}

// duplikaty
TEST(MergeSortTests, Duplicates) {
    std::vector<int> v = { 4,4,2,2,4 };
    MergeSort<int>::sort(v);
    EXPECT_EQ(v, (std::vector<int>{2, 2, 4, 4, 4}));
}
