#include "refalgo.hpp"

void refalgo::insertion_sort(int* list, int list_length) {
    int first_out_of_order, location;
    int temp;
    for (first_out_of_order = 1; first_out_of_order < list_length; first_out_of_order++) {
        if (list[first_out_of_order] < list[first_out_of_order - 1]) {
            temp = list[first_out_of_order];
            location = first_out_of_order;

            do {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}
