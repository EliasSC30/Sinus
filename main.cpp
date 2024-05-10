#include <iostream>
#include "Sinus.h"
#include <fstream>

int main() {
    std::fstream file;
    file.open("/Users/I573040/CLionProjects/Sinus/pts.txt", std::ios::out);

    for(int i = 0; i <= 100; ++i)
    {
        double t{(static_cast<double>(i)/100.0)};
        double x{(1.0 - t) * 2.0 * M_PI };
        file << x << '\n' << Sinus()(x) << '\n';

    }
    return 0;
}
