module;
#include <cstddef>
#include <string>
#include <vector>
export module refalgo.bubble_sort;

export namespace refalgo {
void bubble_sort(int list[], int length) {
    int temp;

    for (auto it = 1; it < length; it++) {
        for (auto idx = 0; idx < length - it; idx++) {
            if (list[idx] > list[idx + 1]) {
                temp = list[idx];
                list[idx] = list[idx + 1];
                list[idx + 1] = temp;
            }
        }
    }
}
void bubble_sort(std::vector<int>& list) {
    int temp;

    for (size_t it = 1; it < list.size(); it++) {
        for (size_t idx = 0; idx < list.size() - it; idx++) {
            if (list[idx] > list[idx + 1]) {
                temp = list[idx];
                list[idx] = list[idx + 1];
                list[idx + 1] = temp;
            }
        }
    }
}

// Sort vector of strings alphabetically
void bubble_sort(std::vector<std::string>& list) {
    std::string temp;

    for (size_t it = 1; it < list.size(); it++) {
        for (size_t idx = 0; idx < list.size() - it; idx++) {
            if (list[idx] > list[idx + 1]) {
                temp = list[idx];
                list[idx] = list[idx + 1];
                list[idx + 1] = temp;
            }
        }
    }
}

// Sort string alphabetically
void bubble_sort(std::string& str) {
    char temp;

    for (size_t it = 1; it < str.size(); it++) {
        for (size_t idx = 0; idx < str.size() - it; idx++) {
            if (str[idx] > str[idx + 1]) {
                temp = str[idx];
                str[idx] = str[idx + 1];
                str[idx + 1] = temp;
            }
        }
    }
}

// Sort array of integers
void bubble_sort(int* arr, size_t length) {
    int temp;

    for (size_t it = 1; it < length; it++) {
        for (size_t idx = 0; idx < length - it; idx++) {
            if (arr[idx] > arr[idx + 1]) {
                temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
        }
    }
}

// Sort array of doubles
void bubble_sort(double* arr, size_t length) {
    double temp;

    for (size_t it = 1; it < length; it++) {
        for (size_t idx = 0; idx < length - it; idx++) {
            if (arr[idx] > arr[idx + 1]) {
                temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
        }
    }
}
void bubble_sort(std::vector<double>& list) {
    double temp;

    for (size_t it = 1; it < list.size(); it++) {
        for (size_t idx = 0; idx < list.size() - it; idx++) {
            if (list[idx] > list[idx + 1]) {
                temp = list[idx];
                list[idx] = list[idx + 1];
                list[idx + 1] = temp;
            }
        }
    }
}
void bubble_sort(std::string str[]) {
    std::string temp;

    for (size_t it = 1; it < str->size(); it++) {
        for (size_t idx = 0; idx < str->size() - it; idx++) {
            if (str[idx] > str[idx + 1]) {
                temp = str[idx];
                str[idx] = str[idx + 1];
                str[idx + 1] = temp;
            }
        }
    }
}
} // namespace refalgo
