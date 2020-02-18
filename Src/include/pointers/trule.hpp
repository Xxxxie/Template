#ifndef TRULE_HPP
#define TRULE_HPP

template<typename T>
class Holder;

//传递holder类型的类
template<typename T>
class Trule
{
private:
    T* ptr;   //所引用的对象
public:
    //需要确保trule只能是返回类型、
    //从被调用对象传递给调用对象
    Trule(Holder<T> &h)
    {
        ptr = h.get();
        h.release();
    }

    Trule(Trule<T> const & rhs)
    {
        ptr = rhs.ptr;
        const_cast<Trule<T>&>(rhs).ptr = 0;
    }

    ~Trule()
    {
        delete ptr;
    }

private:
    //禁止Trule作为左值
    Trule(Trule<T>&);
    //禁止赋值
    Trule<T> & operator=( Trule<T>&);
    friend class Holder<T>;


};



#endif 