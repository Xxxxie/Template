

//表示常量
template<typename T>
class A_Scalar
{
private:
    T const& s;

public:

    A_Scalar(T const& v):s(v)
    {

    }

    //右值
    T operator[](size_t idx) const
    {
        return s;
    }

    //常量的大小为0
    size_t size() const
    {
        return 0;
    }
};