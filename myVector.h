//myVector.h
#ifndef __MYVECTOR__
#define __MYVECTOR__
typedef int Rank;
#define DEFAULT_CAPACITY 3
template <typename T>
class myVector
{
private:
    Rank _size, _capacity;
    T *_elem;
    /* data */
public:
    /*--构造析构函数--*/
    myVector(Rank const& c);
    myVector(myVector const &a);
    myVector(T const *A, Rank const &lo = 0, Rank const &hi=100);
    void operator=(myVector const &A) { copyFrom(A._elem, 0, A._size); };
    ~myVector() { delete[] _elem; }
    /*--只读接口--*/
    T &operator[](Rank const &i) { return _elem[i]; }
    void expand();
    /*--可写接口--*/
    void copyFrom(T* A, Rank const &lo, Rank const &hi);
    /*--遍历接口--*/
};
template <typename T>
inline
myVector<T>::myVector(Rank const& c)
{
    _capacity=c;
    _elem=new T[_capacity];
    _size=0;
}
template<typename T>
inline void
myVector<T>::expand()
{
    for (; _size>=_capacity; )
    {
        _capacity<<1;
    }
}
template<typename T>
inline void
myVector<T>::copyFrom(T* A, Rank const &lo, Rank const &hi)
{
    T* oldelem=_elem;
    _size=hi-lo;
    expand();
    _elem=new T[_capacity];
    for (int i = 0; i < hi; i++)
    {
        _elem[i]=A[i];
    }
}
template <typename T>
inline
myVector<T>::myVector(myVector const& a)
{
    _capacity=a._capacity;
    _size=a._size;
    T* oldelem=_elem;
    _elem=new T[_capacity];
    _elem=a._elem;
    delete[] oldelem;
}

#endif