#include "refalgo.hpp"

void refalgo::bubble_sort(int list[], int length) {
    int temp;

    for (auto it = 1; it < length; it++) {
        for (int idx = 0; idx < length - it; idx++) {
            if (list[idx] > list[idx + 1]) {
                temp = list[idx];
                list[idx] = list[idx + 1];
                list[idx + 1] = temp;
            }
        }
    }
}
