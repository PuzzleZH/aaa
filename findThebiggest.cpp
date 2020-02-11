//findThebiggest.cpp
//分而治之，注意前后的位置的限定是有讲究的
//   lo---mi      mi+1---hi
#include<iostream>
using namespace std;

int findbig(int* a,int lo,int hi)
{
    int mi=(lo+hi)/2;
    if (lo==hi)
    {
        return a[mi];
    }
    else
    {
        int c=findbig(a,lo,mi),d=findbig(a,mi+1,hi);
        return c>=d?c:d;
    }
    
}
int main()
{
    int a[4]={1,2,5,4};
    cout<<findbig(a,0,3)<<endl;
    return 0;
}
