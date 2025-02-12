#include "myteacher.hpp"

namespace myteacher {
    bool CheckRez(int a, int b, int rez) {
        if ((a + b) == rez) {
            return true;
        }
        return false;
    }
}
