#include <bits/stdc++.h>
using namespace std;
int f(int n);
int main(void)
{
    while(1)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        int result = f(n);
        cout << result << endl;
    }
}
int f(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    if (sum < 10)
    {
        return sum;
    }
    else
    {
        return f(sum);
    }
}
