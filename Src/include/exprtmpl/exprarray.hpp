
#include <stddef.h>
#include <cassert>
#include "sarray1.hpp"
template<typename T , typename Rep = SArray<T> >
class Array
{
private:
    Rep expr_rep; //数组的数据
public:
    //此处初始化应该为显示调用的初始化
    explicit Array(size_t s) : expr_rep(s)
    {

    }

    Array (Rep const & rhs): expr_rep(rhs)
    {

    }

    //相同类型的数组赋值
    Array& operator=(Array const& rhs)
    {
        assert(size() == rhs.size());
        for(size_t idx = 0 ; idx < rhs.size() ; idx++)
            expr_rep[idx] = rhs[idx];
        
        return *this;
    }

    template<typename T2, typename Rep2>
    Array& operator=(Array<T2,Rep2> const& rhs)
    {
        assert(size() == rhs.size());
        for(size_t idx = 0 ; idx < rhs.size(); idx++)
            expr_rep[idx] = rhs [idx];
        
        return *this;
    }

    size_t size() const
    {
        return expr_rep.size();
    }

    //const 为右值，不可改变
    T operator[](size_t idx) const
    {
        assert(idx < size());
        return expr_rep[idx];
    }
    //返回引用，当[]为左值时使用
    T& operator[](size_t idx)
    {
        assert(idx < size());
        return expr_rep[idx];
    }

    Rep const& rep() const
    {
        return expr_rep;
    }

    Rep & rep()
    {
        return expr_rep;
    }

};