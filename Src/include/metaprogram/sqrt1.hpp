
#ifndef SQRT_HPP
#define SQRT_HPP

#include "ifthenelse.hpp"
template<int N , int LO = 0 , int HI =N>
class Sqrt
{
public:
    enum { mid = (LO + HI +1)/2};

    //typedef typename IfThenElse< (N < mid*mid) ,Sqrt<N,LO,mid-1>,Sqrt<N,mid,HI> >::ResultT SubT;

    //enum { result = SubT::result };
    enum { result = (N <mid * mid)? Sqrt<N,LO,mid-1>::result : Sqrt<N,mid,HI>::result};
};

template <int N ,int M>
class Sqrt<N,M,M>
{
public:
    enum {result = M};
};

#endif