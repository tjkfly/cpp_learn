#include <iostream>
#include <string>
using namespace std;


namespace TJK
{
    template<typename T>
    T max(T a,T b)
    {
        return a > b ? a:b;
    }
    //重载函数模板
    template<typename T>
    T max(T a[],int n)
    {
        T temp;
        int i;
        temp = a[0];
        for (i = 1;i<n;i++)
        {
            temp = temp > a[i]?temp:a[i];
        }
        return temp;
    }
    const int size = 10;
    // 类模板
    template <typename Atype>
    class atype
    {
    public:
        atype()
        {

            int i;

            for(i = 0;i<size;i++)
            {
                array[i] = i;
            }
        }
        Atype &operator[](int n);
    private:

        Atype array[size];
    };
    template <typename Atype>
    Atype &atype<Atype>::operator[](int n)
    {
        if(n < 0 || n >= size)
        {
            cout<<"下标超出范围"<<endl;
            exit(1);
        }
        return array[n];
    }
};


int main()
{
//    int a,b;
//    cout<<"please input two integers to a,b"<<endl;
//    cin>>a>>b;
//    cout <<"max("<<a<<","<<b<<")="<<TJK::max(a,b)<<endl;
//
//    char c,d;
//    cout<<"please input two char to and d"<<endl;
//    cin >>c>>d;
//    cout<<"max("<<c<<","<<d<<") = "<<TJK::max(c,d)<<endl;
//
//    float x,y;
//    cout<<"please input two floats to x and y"<<endl;
//    cin >>x>>y;
//    cout<<"max("<<x<<","<<y<<")="<<TJK::max(x,y)<<endl;
//    int arr[5] = {1,34,5,6,7};
//    cout<<TJK::max(arr,5);

    TJK::atype<int> intob;
    TJK::atype<double> doubleob;
    for (int i = 0;i < 10;i++)
        intob[i] = i + 1;
    for(int i = 0;i<10;i++)
        doubleob[i] = i /2.f;
    for(int i = 0;i<10;i++)
    {
        cout<<intob[i]<<" , "<<doubleob[i]<<endl;
    }
    return 0;
}