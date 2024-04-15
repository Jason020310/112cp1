#include <bits/stdc++.h>
void swap(int* a, int* b);
bool is_first(int a, int b);
using namespace std;
int m;
int main(void)
{
    while(1)
    {
        int n;
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        cout << n << " " <<  m << endl;
        int arr[n];
        for (int i = 0 ; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n,is_first);
        for (int i = 0; i < n;i++)
        {
            cout << arr[i] << endl;
        }    
    }
    cout << "0 0" << endl;
}
bool is_first(int a, int b)
{
    int a_mod = a % m;
    int b_mod = b % m;
    if (a_mod < b_mod)
    {
        return true;
    }
    else if (a_mod > b_mod)
    {
        return false;
    }
    //mod 相同時
    else
    {
        int  a_odd = a % 2;
        int  b_odd = b % 2; 
        if (a < 0)
        {
            a_odd  = (-a) % 2;
        }
        if (b < 0)
        {
            b_odd = (-b) % 2;
        }
        //both are even
        if( a_odd == 0 && b_odd == 0)
        {
            if (a < b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // both are odd
        else if (a_odd == 1 && b_odd == 1)
        {
            if(a > b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // one is odd one is even
        else if (a_odd == 0 && b_odd == 1) 
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}