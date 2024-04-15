#include <bits/stdc++.h>
using namespace std;
string decimal_to_binary(int n);
int calculate(string bin);
int main(void)
{
    while(1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        string bin = decimal_to_binary(n);
        int p = calculate(bin);
        cout << "The parity of " << bin << " is " << p << " (mod 2)." << endl;
    }
    return 0;
}
string decimal_to_binary(int n)
{
    string bin = "";
    while (n > 0)
    {
        bin += to_string((n % 2));
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
int calculate(string bin)
{
    int n = 0;
    for (int i = 0;i < bin.length();i++)
    {
        if (bin[i] == '1')
        {
            n += 1;
        }
    }
    return n;
}