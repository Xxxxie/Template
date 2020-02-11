
#include "exprops1.hpp"
#include "exprarray.hpp"

template<typename T, typename R1, typename R2>
Array<T,A_Add< T,R1,R2> > operator+ (Array<T,R1> const& lhs, Array<T,R2> const& rhs)
{
    return Array<T,A_Add<T,R1,R2> >(A_Add<T,R1,R2>(lhs.rep(),rhs.rep() ));
}

template<typename T, typename R1, typename R2>
Array<T,A_Mult< T,R1,R2> > operator* (Array<T,R1> const& lhs, Array<T,R2> const& rhs)
{
    return Array<T,A_Mult<T,R1,R2> >(A_Mult<T,R1,R2>(lhs.rep(),rhs.rep() ));
}

template<typename T, typename R2>
Array<T,A_Mult<T,A_Scalar<T>,R2> > operator*(T const& s, Array<T,R2> const &b)
{
    return Array<T,A_Mult<T,A_Scalar<T>,R2> >(A_Mult<T,A_Scalar<T>,R2>(A_Scalar<T>(s), b.rep() ));
}
