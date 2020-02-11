
#include <stddef.h>
#include <cassert>
#include "exprops1a.hpp"


//两个对象相加
template<typename T,typename OP1, typename OP2>
class A_Add
{
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;

public:
    A_Add(OP1 const& lhs , OP2 const& rhs):op1(lhs), op2(rhs)
    {
        
    }

    T operator[] (size_t idx) const
    {
        return op1[idx] + op2[idx];
    }

    size_t size() const
    {
        assert(op1.size() == 0 || op2.size() == 0 || op1.size() == op2.size());
        return op1.size()>0? op1.size(): op2.size();
    }
};

//两个对象相乘
template<typename T,typename OP1, typename OP2>
class A_Mult
{
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;
public:
    A_Mult(OP1 const& lhs , OP2 const& rhs):op1(lhs), op2(rhs)
    {
        
    }

    T operator[] (size_t idx) const
    {
        return op1[idx] * op2[idx];
    }

    size_t size() const
    {
        assert(op1.size() == 0 || op2.size() == 0 || op1.size() == op2.size());
        return op1.size()>0? op1.size(): op2.size();
    }
};