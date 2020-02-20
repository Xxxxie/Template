#include <iostream>
#include "duo2.hpp"
#include "tuples.hpp"

int main()
{
    Duo<bool,int> d;
    std::cout << d.v1() << std::endl;
    std::cout << val<1>(d) << std::endl;

    Duo<bool,Duo<int,float> > t;
    val<1>(t) = true;
    val<2>(t) = 42;
    val<3>(t) = 0.2;

    std::cout << val<1>(t) << std::endl;
    std::cout << val<2>(t) << std::endl;
    std::cout << val<3>(t) << std::endl;


    Tuple<int> t1;
    val<1>(t1) +=42;
    std::cout<< t1.v1() <<std::endl;

    Tuple<bool,int> t2;
    std::cout << val<1>(t2) << ", ";
    std::cout << t2.v1() << std::endl;

    Tuple<bool,int,double> t3;

    val<1>(t3) = true;
    val<2>(t3) = 42;
    val<3>(t3) = 0.2;
    std::cout << val<1>(t3) << std::endl;    
    std::cout << val<2>(t3) << std::endl;
    std::cout << val<3>(t3) << std::endl;

    //此处为什么不需要重载=进行赋值
    t3 = make_tuple(false,23,13.13);
    std::cout << val<1>(t5) << std::endl;    
    std::cout << val<2>(t5) << std::endl;
    std::cout << val<3>(t5) << std::endl;
    
    Tuple<bool,int,float,double> t4(true,42,13,1.95);
    std::cout<<val<4>(t4)<<std::endl;
    std::cout<<t4.v2().v2().v2()<<std::endl;


    system("pause");

}