#include <iostream>
#include "holder.hpp"

class Something
{

};

void ReadSomeThing(Something * x)
{}

Trule<Something> load_something()
{
    Holder<Something> result(new Something);
    ReadSomeThing(result.get());
    std::cout<<"success"<<std::endl;
    return result;
}

int main()
{
    Holder<Something> ptr(load_something());

    system("pause");7
}