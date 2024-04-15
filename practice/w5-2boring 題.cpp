//記得floating point exception 有可能是有除以零
#include <bits/stdc++.h>
using namespace std;
bool is_boring(int n, int m);
vector <int> a;
int main(void)
{
    int n, m;
    while(cin >> n >> m)
    {
        a.clear();
        if(is_boring(n, m))
        {
            cout << "Boring!" << endl;
        }
        else
        {
            for(int i = 0; i < a.size();i++)
            {
                cout << a[i];
                if(i != a.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
bool is_boring(int n, int m)
{
    if(m == 0 || n == 0 || m == 1 || m > n)
    {
        return 1;
    }
    while(n != 1)
    {
        if(n % m != 0 )
        {
            return 1;
        }
        else
        {
            a.push_back(n);
            n /= m;
        }
    }
    a.push_back(n);
    return 0;
}