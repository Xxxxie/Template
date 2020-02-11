
#include "exprscalar.hpp"

//传引用，一般情况下，数组运算都为传引用
template<typename T>
class A_Traits
{
public:
    typedef T const& ExprRef;  //所引用的类型定义为一个常量引用
};


//针对A_Scalar 特化
template<typename T>
class A_Traits<A_Scalar<T> >
{
public:
    typedef A_Scalar<T> ExprRef; //传值
};
