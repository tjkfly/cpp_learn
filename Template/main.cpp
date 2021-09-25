#include <iostream>

using namespace std;
// 函数模板
template <typename T>
T my_max(T a, T b)
{
    return a > b?a:b;
}

template <typename T>
T my_max(T a[], int n)
{
    T temp;
    if(n <= 0)
    {
        return 0;
    }
    for (int i = 1;i < n;i++)
    {
        temp = temp > a[i]?temp:a[i];
    }
}

// 类模板
template<typename AType> class atype
{

};

int main() {
    int a = 0,b = 0;
    cin>>a>>b;
    cout<<my_max(a,b)<<endl;
    int arr[5] = { 1,3, 4,7,8};
    cout<<my_max(arr,5)<<endl;
    return 0;
}
