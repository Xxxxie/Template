#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "exprops2.hpp"

int main()
{
    Array<double> x(1000),y(1000);

    //省略对x,y 初始化

    x= 1.2 * x + x * y;
    system("pause");
}