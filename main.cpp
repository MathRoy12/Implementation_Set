#include <iostream>
#include "ensemble.h"

int main() {
    ensemble<int> e;
    e.insert(1);
    e.insert(5);
    e.insert(4);
    e.insert(6);
    e.insert(3);
    e.insert(3);
    e.insert(0);

    auto i =e.lower_bound(5);
    auto i2 =e.upper_bound(5);
    auto i3 =e.find(5);

    size_t lsfk = e.erase(29);
    size_t lsfk2 = e.erase(6);

    ensemble<int> e2 (e);

    afficher(std::cout, e);
    afficher(std::cout, e2);
    return 0;
}
