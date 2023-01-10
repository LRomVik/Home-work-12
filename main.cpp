#include <iostream>
#include "multiply.h"

int main(){
    std::string txt = "abcdefgabcdefg";

    for (size_t k = 1; k <= 100; ++k) {
        if (IsKPeriodic(txt, k)) {
            std::cout << "The text is multiply - " << k << std::endl;
        }
    }
    return 0;
}