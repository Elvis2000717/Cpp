#include <iostream>

using namespace std;

bool fun(int i)
{
    for(int j = 2; j < i; j++)
    {
        if(i % j == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    int ret;
    int i;
    while(cin >> n)
    {
        ret = n / 2;
        for(i = ret; i >= 1; i--)
        {
            if(fun(i) && fun(n - i))
                break;
        }
        cout << i << endl;
        cout << n - i << endl;
    }
    
    return 0;
}