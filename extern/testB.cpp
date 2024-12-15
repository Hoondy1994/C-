#include "testA.h"
#include "testB.h"
// 在别的文件中extern声明，就可以使用
extern int globalVariable;
extern void myFunction();

int main1()
{
    globalVariable = 100;
    myFunction();
    return 0;

}
