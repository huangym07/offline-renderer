#include <iostream>
#include "paths.h"

int main() {
#ifdef DEBUG
    std::cout << PROJECT_ROOT_DIR << std::endl;
#endif

    return 0;
}
