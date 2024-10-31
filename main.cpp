#include <iostream>
#include "ensemble.h"

int main() {
    ensemble<int> e;
    e.insert(1);
    auto it = e.lower_bound(5);
    e.insert(5);
    afficher(std::cout,e);
    return 0;
}
