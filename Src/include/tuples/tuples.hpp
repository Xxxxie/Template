#ifndef TUPLES_HPP
#define TUPLES_HPP

#include "duo2.hpp"
#include "typeop.hpp"
class NullT{};

template<typename P1,
        typename P2 = NullT,
        typename P3 = NullT,
        typename P4 = NullT,
        typename P5 = NullT>
class Tuple : public Duo<P1,typename Tuple<P2,P3,P4,P5,NullT>::BaseT >
{
public:
    typedef Duo<P1,typename Tuple<P2,P3,P4,P5,NullT>::BaseT> BaseT;

    Tuple(){}

    Tuple(typename TypeOp<P1>::RefConstT a1,
        typename TypeOp<P2>::RefConstT a2 ,
        typename TypeOp<P3>::RefConstT a3 = NullT(),
        typename TypeOp<P4>::RefConstT a4 = NullT(),
        typename TypeOp<P5>::RefConstT a5 = NullT()):BaseT(a1,Tuple<P2,P3,P4,P5,NullT>(a2,a3,a4,a5))
    {

    }

    


};


template<typename P1,typename P2>
class Tuple<P1,P2,NullT,NullT,NullT> : public Duo<P1,P2>
{
public:
    typedef Duo<P1,P2> BaseT;


    Tuple(){}

    Tuple(typename TypeOp<P1>::RefConstT a1,
        typename TypeOp<P2>::RefConstT a2 ,
        typename TypeOp<NullT>::RefConstT = NullT(),
        typename TypeOp<NullT>::RefConstT = NullT(),
        typename TypeOp<NullT>::RefConstT = NullT()):BaseT(a1,a2)
    {

    }
};


template<typename P1>
class Tuple<P1,NullT,NullT,NullT,NullT> : public Duo<P1,void>
{
public:
    typedef Duo<P1,void> BaseT;


    Tuple(){}

    Tuple(typename TypeOp<P1>::RefConstT a1,
        typename TypeOp<NullT>::RefConstT =NullT(),
        typename TypeOp<NullT>::RefConstT = NullT(),
        typename TypeOp<NullT>::RefConstT = NullT(),
        typename TypeOp<NullT>::RefConstT  = NullT()):BaseT(a1)
    {

    }
};

template <typename T1>
inline
Tuple<T1> make_tuple(const T1 &a1)
{
    return Tuple<T1>(a1);
}

template <typename T1,typename T2>
inline
Tuple<T1,T2> make_tuple(const T1 &a1,const T2 &a2)
{
    return Tuple<T1,T2>(a1,a2);
}

template <typename T1,typename T2,typename T3>
inline
Tuple<T1,T2,T3> make_tuple(const T1 &a1,const T2 &a2,const T3 &a3)
{
    return Tuple<T1,T2,T3>(a1,a2,a3);
}

template <typename T1,typename T2,typename T3,typename T4>
inline
Tuple<T1,T2,T3,T4> make_tuple(const T1 &a1,const T2 &a2,const T3 &a3,const T4 &a4)
{
    return Tuple<T1,T2,T3,T4>(a1,a2,a3,a4);
}

template <typename T1,typename T2,typename T3,typename T4,typename T5>
inline
Tuple<T1,T2,T3,T4,T5> make_tuple(const T1 &a1,const T2 &a2,const T3 &a3,const T4 &a4,const T5 &a5)
{
    return Tuple<T1,T2,T3,T4,T5>(a1,a2,a3,a4,a5);
}

#endif
