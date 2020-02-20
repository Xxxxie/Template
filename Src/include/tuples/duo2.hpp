#ifndef DOU2_HPP
#define DOU2_HPP

#include "duo1.hpp"
#include "typeop.hpp"

//对关于嵌套dou的特化

template<typename A,typename B,typename C>
class Duo<A,Duo<B,C> >
{
public:
    typedef A T1;
    typedef Duo<B,C> T2;
    enum {N = Duo<B,C>::N +1};

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


//只包含一个域的duo，为上面的特化提供出口
template<typename A>
class Duo<A,void>
{
public:
    typedef A T1;
    typedef void T2;
    enum {N = 1};

private:
    T1 value1;           //第1个域的值

public:

    //构造函数
    Duo():value1(){}

    Duo(T1 const &a):value1(a){}

    //在构造期间，进行隐式的类型转换
    template<typename U1,typename U2>
    Duo(Duo<U1,U2> const &d):value1(d.v1() ,d.v2()){}

    //在赋值期间，进行隐式类型转换

    template<typename U1,typename U2>
    Duo<T1,T2> & operator=(Duo<U1,U2> const & rhs)
    {
        value1 = rhs.v1();
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

    T2 v2()
    {
        
    }

    T2 v2() const
    {
        
    }
};


//用于获取duo的第N个域的类型的基本模板
template<int N ,typename T>
class DuoT
{
public:
    typedef void ResultT;  //一般情况下，结构类型为void
};

template<typename A,typename B>
class DuoT<1,Duo<A,B> >
{
public:
    typedef A ResultT;
};

template<typename A, typename B>
class DuoT<2,Duo<A,B> >
{
public:
    typedef B ResultT;
};


template<int N,typename A,typename B,typename C>
class DuoT<N,Duo<A,Duo<B,C> > >
{
public:
    typedef typename DuoT<N-1,Duo<B,C> >::ResultT ResultT;  //由于ResultT为类型名，因此需要加typename
};

template<typename A,typename B,typename C>
class DuoT<1,Duo<A,Duo<B,C> > >
{
public:
    typedef A ResultT; 
};

template<typename A,typename B,typename C>
class DuoT<2,Duo<A,Duo<B,C> > >
{
public:
    typedef B ResultT; 
};




//获取Duo 中第N个域的值
template<int N, typename T>
class DuoValue
{
public:
    static void get(T&)
    {

    }

    static void get(const T&){}
};

template <typename A ,typename B>
class DuoValue<1,Duo<A,B> >
{
public:

    //可以作为左值
    static A& get(Duo<A,B> &d)
    {
        return d.v1();
    }

    //作为右值
    static  A const& get(const Duo<A,B> &d)
    {
        return d.v1();
    }

};

template <typename A ,typename B>
class DuoValue<2,Duo<A,B> >
{
public:

    //可以作为左值
    static B& get(Duo<A,B> &d)
    {
        return d.v2();
    }

    //作为右值
    static const B& get(const Duo<A,B> &d)
    {
        return d.v2();
    }

};

template <int N,typename A, typename B,typename C>
class DuoValue<N,Duo<A,Duo<B,C> > >
{
public:
    static 
    typename TypeOp<typename DuoT<N-1 ,Duo<B,C> >::ResultT >::RefT 
    get(Duo<A,Duo<B,C> > & d)
    {
        return DuoValue<N-1,Duo<B,C> >::get(d.v2());
    }

    static 
    typename TypeOp<typename DuoT<N-1 ,Duo<B,C> >::ResultT >::RefConstT 
    get(const Duo<A,Duo<B,C> > & d)
    {
        return DuoValue<N-1,Duo<B,C> >::get(d.v2());
    }


};

template <typename A, typename B,typename C>
class DuoValue<1,Duo<A,Duo<B,C> > >
{
public:
    static A& get(Duo<A,Duo<B,C> > & d)
    {
        return d.v1();
    }

    static const A& get(const Duo<A,Duo<B,C> > & d)
    {
        return d.v1();
    }
};

template <typename A, typename B,typename C>
class DuoValue<2,Duo<A,Duo<B,C> > >
{
public:
    static B& get(Duo<A,Duo<B,C> > & d)
    {
        return d.v2().v1();
    }

    static const B& get(const Duo<A,Duo<B,C> > & d)
    {
        return d.v2().v1();
    }
};

template<int N,typename A,typename B>
inline
typename TypeOp<typename DuoT<N,Duo<A,B> >::ResultT >::RefT
val(Duo<A,B> &d)
{
    return DuoValue<N,Duo<A,B> >::get(d); 
}

template<int N,typename A,typename B>
inline
typename TypeOp<typename DuoT<N,Duo<A,B> >::ResultT >::RefConstT
val(const Duo<A,B> &d)
{
    return DuoValue<N,Duo<A,B> >::get(d); 
}

#endif