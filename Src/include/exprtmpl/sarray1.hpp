#include <stddef.h>
#include <cassert>


//数组类模板
template<typename T>
class SArray
{
private:
    T * storage;            //元素的存储空间
    size_t storage_size;    //元素的个数
protected:

    void init()
    {
        for(size_t idx = 0; idx < storage_size ; idx++)
            storage[idx] = T();
    }

    void copy(SArray<T> const& rhs)
    {
        for(size_t idx = 0 ; idx < storage_size ; idx++)
            storage[idx] = rhs.storage[idx];   //此处应该存在问题，访问了类的私有成员
    }

public:

    //防止隐式类型转换
    explicit SArray(size_t s):storage(new T[s]),storage_size(s)
    {
        init();
    }

    //拷贝构造函数
    SArray(SArray<T> const & rhs): storage(new T[rhs.size()],storage_size(rhs.size()) )
    {
        copy(rhs);
    }

    ~SArray()
    {
        delete[] storage;
    }

    //赋值运算符 构造函数已经分配了内存空间，因此这边不需要分配
    SArray<T> operator=(SArray<T> const & rhs)
    {
        if(this != &rhs)
            copy(rhs);
        
        return *this;
    }

    size_t size() const
    {
        return storage_size;
    }

    //针对常数和变量的下标运算符
    T operator[] (size_t idx) const
    {
        return storage[idx];
    }

    //返回引用，当[]为左值时使用
    T& operator[] (size_t idx)
    {
        return storage[idx];
    }


};
