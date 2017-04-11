#include <iostream>

#include <cpr/cpr.h>

#include "bitsy/bitsy.hpp"

namespace bitsy {
    void f() {
        std::cout << cpr::Get(cpr::Url{"http://ipinfo.io/ip"}).text << std::endl;
    }
}
