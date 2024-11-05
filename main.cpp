#include <iostream>
#include "ensemble.h"

int main() {
    ensemble<int> e;
    e.insert(1);
    e.insert(5);
    e.insert(4);
    e.insert(6);
    e.insert(3);
    e.insert(0);

    auto i =e.lower_bound(5);
    auto i2 =e.upper_bound(5);
    auto i3 =e.find(5);

    afficher(std::cout, e);
    return 0;
}
