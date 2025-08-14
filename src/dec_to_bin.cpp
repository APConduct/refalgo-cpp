#include "refalgo.hpp"

int refalgo::dec_to_bin(int num, int base) {
    if (num == 0) {
        return 0;
    }
    int prev = dec_to_bin(num / base, base);
    return prev * 10 + (num % base);
}
