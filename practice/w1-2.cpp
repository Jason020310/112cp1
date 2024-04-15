#include <bits/stdc++.h>
using namespace std;
int binary_converter(string s);
bool is_coprime(int s1, int s2);
int main (void)
{
    int times;
    cin >> times;
    for (int i = 0 ;i < times; i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int s1_dec, s2_dec;
        s1_dec = binary_converter(s1);
        s2_dec = binary_converter(s2);
        if (is_coprime(s1_dec, s2_dec ))
        {
            cout << "Pair #" << i + 1  <<": " << "All you need is love!" << endl;
        }
        else
        {
            cout << "Pair #" << i + 1 <<": " << "Love is not all you need!" << endl;
        }
    }
}
int binary_converter(string s)
{
    int base_convert = 0;
    for (int i = 0; i < s.length(); i++)
    {
        //乘以每個位數的權重 n[i] - '0' 是為了轉成int
        base_convert += (s[i] - '0') * pow(2, (s.length() - 1 - i));
    }
    return base_convert;
}
bool is_coprime(int s1, int s2)
{
    if (s1 < s2)
    {
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    while (s1 != 0 && s2 !=0)
    {
        s1 = s1 % s2;
        if (s1 == 0)
        {
            break;
        }
        s2 = s2 % s1;
    }
    if (s1 != 1 and s2 != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
    