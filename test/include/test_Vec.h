#ifndef __TEST_VEC_H__
#define __TEST_VEC_H__

#include "Vec.h"

void TestVecConstructorAndCopy() {
    std::cout << "TestVecConstructorAndCopy-------------------- " << std::endl;
    Vec<3, double> vec1;
    Vec<4, int> vec2(2, 2, 2, 2);
    Vec<4, double> vec3(3.0, 3.0);
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
//     Vec<1, double> vec4(4.0, 4.0);

    Vec<3, double> vec5(5.0, 5.0, 5.0);
    Vec<3, double> vec6(vec5);
    Vec<3, double> vec7 = vec5;
    std::cout << vec5 << std::endl;
    std::cout << vec6 << std::endl;
    std::cout << vec7 << std::endl;

    Vec<3, double> vec8(8.0, 8.0, 8.0);
    vec8 = vec1 = vec5; 
    std::cout << vec1 << std::endl;
    std::cout << vec8 << std::endl;
}

void TestVecAccess() {
    std::cout << "TestVecAccess-------------------- " << std::endl;
    Vec<3, double> vec;
    for (int i = 0; i < 3; i++) {
        std::cout << vec[i] << " \n"[i == 2];
    }

    std::cout << vec.x() << ' ' << vec.y() << ' ' << vec.z() << std::endl;
    
//     std::cout << vec.w() << std::endl;
}

void TestVecLengthAndNegtive() {
    std::cout << "TestVecLengthAndNegtive-------------------- " << std::endl;
    Vec<3, double> vec(1.0, 1.0, 1.0);

    std::cout << -vec << std::endl;
    std::cout << vec.Length() << " " << vec.LengthSquared() << std::endl;
}

void TestVecFourBasicOperation() {
    std::cout << "TestVecFourBasicOperation--------------------" << std::endl;
    Vec<3, double> vec1(1.0, 1.0, 1.0);
    Vec<3, double> vec2(2.0, 2.0, 2.0);

    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;
    std::cout << vec1 * vec2 << std::endl;
    std::cout << vec1 * 10 << std::endl;
    std::cout << 10 * vec1 << std::endl;
    std::cout << vec1 / 10 << std::endl;
}

void TestVecDotCrossUnit() {
    std::cout << "TestVecDotCrossUnit-------------------- " << std::endl;
    Vec<3, double> unit_vec_x(1.0);
    Vec<3, double> unit_vec_y(0.0, 1.0);

    Vec<3, double> vec1(1.0, 1.0, 1.0);
    Vec<3, double> vec2(2.0, 2.0, 2.0);

    std::cout << Dot(vec1, vec2) << std::endl;
    std::cout << Cross(unit_vec_x, unit_vec_y) << std::endl;
    std::cout << UnitVector(vec2) << std::endl;
    std::cout << UnitVector(vec2).Length() << std::endl;
}

void TestVecAll() {
    std::cout << "TestVecAll-------------------------------------------------- " << std::endl;
    TestVecConstructorAndCopy();
    TestVecAccess();
    TestVecLengthAndNegtive();
    TestVecFourBasicOperation();
    TestVecDotCrossUnit();
}

#endif // __TEST_VEC_H__
