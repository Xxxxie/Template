
#include "exprscalar.hpp"

//Traits负责将不同类型的转换为同一模板类型
//传引用，一般情况下，数组运算都为传引用
template<typename T>
class A_Traits
{
public:
    typedef T const& ExprRef;  //所引用的类型定义为一个常量引用
};

//对于特殊的类型进行特化
//针对A_Scalar 特化
template<typename T>
class A_Traits<A_Scalar<T> >
{
public:
    typedef A_Scalar<T> ExprRef; //传值
};
