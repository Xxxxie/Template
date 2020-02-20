#ifndef DUO_HPP
#define DUO_HPP

template <typename T1, typename T2>
class Duo
{
public:
    typedef T1 type1;
    typedef T2 type2;
    enum {N =2};

private:
    T1 value1;           //第1个域的值
    T2 value2;           //第2个域的值

public:

    //构造函数
    Duo():value1(),value2(){}

    Duo(T1 const &a , T2 const &b):value1(a),value2(b){}

    //在构造期间，进行隐式的类型转换
    template<typename U1,typename U2>
    Duo(Duo<U1,U2> const &d):value1(d.v1() ,d.v2()){}

    //在赋值期间，进行隐式类型转换

    template<typename U1,typename U2>
    Duo<T1,T2> & operator=(Duo<U1,U2> const & rhs)
    {
        value1 = rhs.v1();
        value2 = rhs.v2();
        return *this;
    }

    T1& v1()
    {
        return value1;
    }

    T1 const& v1() const
    {
        return value1;
    }

    T2& v2()
    {
        return value2;
    }

    T2 const& v2() const
    {
        return value2;
    }
};

//比较运算符
template<typename T1 ,typename T2, typename U1,typename U2>
bool operator == (const Duo<T1,T2> &lhs,const Duo<U1,U2> & rhs)
{
    return lhs.v1() == rhs.v1() && lhs.v2() == rhs.v2();
}

template<typename T1 ,typename T2, typename U1,typename U2>
bool operator != (const Duo<T1,T2> &lhs,const Duo<U1,U2> & rhs)
{
    return !(lhs==rhs);
}

//针对创建和初始化的辅助函数
template<typename T1, typename T2>
Duo<T1,T2> make_duo(const T1 & v1,const T2 &v2)
{
    return Duo<T1,T2>(v1,v2);
}


#endif