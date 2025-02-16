#include <iostream>
#include "Vec.h"

int main() {
    std::cout << "Test Vec------------------------------" << std::endl;

    // constructor and access and << 
    Vec3<double> vec(100, 200, 300);
    Vec3<double> vec2(10);
    Vec3<double> vec3;
    Vec3<double> vec4(1);

    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
    std::cout << vec4 << std::endl;


    // Length LengthSquared
    std::cout << vec4.Length() << std::endl;
    std::cout << vec4.LengthSquared() << std::endl;

    std::cout << "Test Over-----------------------------" << std::endl;

    return 0;
}
