#include "refalgo/refalgo.hpp"

int refalgo::binary_search(const int list[], int list_length, int search_item) {
    int first = 0;
    int last = list_length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found) {
        mid = (first + last) / 2;
        if (list[mid] == search_item) {
            found = true;
        }
        else if (list[mid] > search_item) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    if (found) {
        return mid;
    }
    return -1;
}
