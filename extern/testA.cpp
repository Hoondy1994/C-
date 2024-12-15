#include "testA.h"
#include "testB.h"

#include<iostream>

using namespace std;

// 在Cpp中定义
int globalVariable = 42;
void myFunction() {
    std::cout << "globalVariable="<<globalVariable<< std::endl;
}
