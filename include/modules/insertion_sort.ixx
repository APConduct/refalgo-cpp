module;
#include <cstddef>
#include <vector>
export module refalgo.insertion_sort;

export namespace refalgo {
void insertion_sort(int* list, int list_length) {
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

void insertion_sort(std::vector<int>& list) {
    size_t first_out_of_order, location;
    int temp;
    for (first_out_of_order = 1; first_out_of_order < list.size(); first_out_of_order++) {
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

void insertion_sort(std::vector<std::string>& list) {
    std::string temp;
    for (size_t first_out_of_order = 1; first_out_of_order < list.size(); first_out_of_order++) {
        if (list[first_out_of_order] < list[first_out_of_order - 1]) {
            temp = list[first_out_of_order];
            size_t location = first_out_of_order;

            do {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}

void insertion_sort(std::vector<double>& list) {
    double temp;
    for (size_t first_out_of_order = 1; first_out_of_order < list.size(); first_out_of_order++) {
        if (list[first_out_of_order] < list[first_out_of_order - 1]) {
            temp = list[first_out_of_order];
            size_t location = first_out_of_order;

            do {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}

void insertion_sort(std::vector<char>& list) {
    char temp;
    for (size_t first_out_of_order = 1; first_out_of_order < list.size(); first_out_of_order++) {
        if (list[first_out_of_order] < list[first_out_of_order - 1]) {
            temp = list[first_out_of_order];
            size_t location = first_out_of_order;

            do {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}
} // namespace refalgo
