
#include "type1.hpp"

//针对函数类型的处理 依据数组的元素类型不能为void 引用或者函数
template<typename T>
class IsFunctionT{
private:
    typedef char One;
    typedef struct 
    {
        char a[2];
    } Two;

    template<typename u> static One test(...);
    template<typename u> static Two test(u (*)[1]);
 
 public:
    enum {Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1};
    enum {No = !Yes};
    
};
//对于引用进行特化
template<typename T>
class IsFunctionT<T&>
{
public:
    enum {Yes = 0};
    enum {No = !Yes};
};

//对于空类型特化
template<>
class IsFunctionT<void const>
{
public:
    enum {Yes = 0};
    enum {No = !Yes};
};


//辨别组合类型
template<typename T>
class CompoundT{
public:
    enum {IsPtrT = 0, IsRefT = 0 , IsArrayT = 0,
        IsFuncT = IsFunctionT<T>::Yes, IsPtrMemT = 0};
    
    typedef T BaseT;
    typedef T BottomT;
    typedef CompoundT<void> ClassT;
};

//针对不同组合类型进行特化
//对于引用的特化
template<typename T>
class CompoundT<T&>{
public:
    enum {IsPtrT = 0, IsRefT = 1 , IsArrayT = 0,
    IsFuncT = 0 , IsPtrMemT = 0};
    
    typedef T BaseT;
    typedef typename CompoundT<T>::BottomT BottomT;                 //模板递归获得BottomT
    typedef CompoundT<void> ClassT;
};

//对于指针的特化
template<typename T>
class CompoundT<T*>{
public:
    enum {IsPtrT = 1, IsRefT = 0 , IsArrayT = 0,
    IsFuncT = 0 , IsPtrMemT = 0};
    
    typedef T BaseT;
    typedef typename CompoundT<T>::BottomT BottomT;                 //模板递归获得BottomT
    typedef CompoundT<void> ClassT;
};

//对于数组的特化
template<typename T ,size_t N>
class CompoundT<T[N]>{
public:
    enum {IsPtrT = 0, IsRefT = 0 , IsArrayT = 1,
    IsFuncT = 0 , IsPtrMemT = 0};
    
    typedef T BaseT;
    typedef typename CompoundT<T>::BottomT BottomT;                 //模板递归获得BottomT
    typedef CompoundT<void> ClassT;
};

template<typename T>
class CompoundT<T[]>{
public:
    enum {IsPtrT = 0, IsRefT = 0 , IsArrayT = 1,
    IsFuncT = 0 , IsPtrMemT = 0};
    
    typedef T BaseT;
    typedef typename CompoundT<T>::BottomT BottomT;                 //模板递归获得BottomT
    typedef CompoundT<void> ClassT;
};

//对成员指针的特化
template<typename T , typename C>
class CompoundT<T C::*>{
public:
    enum {IsPtrT = 0, IsRefT = 0 , IsArrayT = 0,
    IsFuncT = 0 , IsPtrMemT = 1};
    
    typedef T BaseT;
    typedef typename CompoundT<T>::BottomT BottomT;                 //模板递归获得BottomT
    typedef C ClassT;
};

//利用重载解析辨别枚举类型

struct SizeOverOne { char c[2];};

//函数类型和数组类型不可能为枚举
template<typename T, bool convert_possible = !CompoundT<T>::IsFuncT && !CompoundT<T>::IsArrayT > 
class ConsumeUDC
{
public:
    operator T() const;
};

//函数类型的转型是不允许的
template <typename T>
class ConsumeUDC<T,false>
{};

//到void类型的转型也是不允许的
template<bool conver_possible>
class ConsumeUDC<void ,conver_possible>
{};

char enum_check(bool);
char enum_check(char);
char enum_check(unsigned char);
char enum_check(signed char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed int);
char enum_check(unsigned int);
char enum_check(signed long);
char enum_check(unsigned long);

#if LONGLONG_EXISTS
char enum_check(signed long long );
char enum_check(unsigned long long);
#endif

char enum_char(float);
char enum_char(double);
char enum_char(long double);

SizeOverOne enum_check(...);

template<typename T>
class IsEnumT
{
public:
    enum {Yes = IsFundaT<T>::No && 
                !CompoundT<T>::IsRefT && 
                !CompoundT<T>::IsPtrT &&
                !CompoundT<T>::IsPtrMemT &&
                sizeof(enum_check(ConsumeUDC<T>())) == 1};
    enum {No = !Yes};
};


//判断class类型，排除所有类型之后剩下的就是类 类型
template<typename T>
class IsClassT{
public:
    enum{ Yes = IsFundaT<T>::No &&
                IsEnumT<T>::No &&
                !CompoundT<T>::IsPtrT &&
                !CompoundT<T>::IsPtrMemT &&
                !CompoundT<T>::IsArrayT &&
                !CompoundT<T>::IsRefT &&
                !CompoundT<T>::IsFuncT};
    enum{ No = !Yes};
};

