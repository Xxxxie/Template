
#include "trule.hpp"

template<typename T>
class Holder
{
private:
    T* ptr;        //引用所持有的对象

public:
    Holder():ptr(0){}

    //显示构造
    explicit Holder(T *p):ptr(p)
    {}

    ~Holder()
    {
        delete ptr;
    }

    Holder<T>& operator=(T* rhs)
    {
        delete ptr;
        ptr = rhs;
        return *this;
    }

    //const 函数为右值
    T& operator*() const
    {
        return *ptr;
    }
    //只能为右值
    T* operator->() const
    {
        return ptr;
    }

    //获取所引用的对象
    T* get() const
    {
        return ptr;
    }

    void release()
    {
        ptr = 0;
    }

    //与另外一个holder对象交换指针所有权
    void exchange_with (Holder<T> & rhs)
    {
        swap(ptr,rhs.ptr);
    }

    //与其他类型的指针交换指针所有权
    void exchange_with(T* &p)
    {
        swap(ptr ,p);
    }

    Holder(Trule<T> const & rhs)
    {
        ptr = rhs.ptr;
        const_cast<Trule<T> &>(rhs).ptr = 0;
    }

    Holder<T> & operator=(Trule<T> const & rhs)
    {
        delete ptr;
        ptr =rhs.ptr;
        const_cast<Trule<T> &>(rhs).ptr = 0;
        return *this;

    } 

private:

    //不向外提供拷贝和赋值运算符
    Holder (Holder const & rhs);
    Holder<T> & operator=(Holder<T> const & rhs);


};