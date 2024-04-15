#include <bits/stdc++.h>
using namespace std;
# define LL long long
string str;
string num_to_bangla(long long int n)
{
    if(n >= 10000000){
        num_to_bangla(n / 10000000);
        str += " kuti";
        n %= 10000000;
    }
    if(n >= 100000){
        num_to_bangla(n / 100000);
        str += " lakh";
        n %= 100000;
    }
    if(n >= 1000){
        num_to_bangla (n / 1000);
        str += " hajar";
        n %= 1000;
    }
    if(n >= 100){
       num_to_bangla(n / 100);
        str += " shata";
        n %= 100;
    }
    if(n){
        str = str + " " + to_string(n);
    }
    return str;
}
int main()
{
    string s;
    int Case;
    Case = 1;
    while (getline(cin ,s)){
        int ans = 0;
        LL num = stoll(s);
        str = "";
        if(num == 0)
        {
            str = " 0";
        }
        string ans_string = num_to_bangla(num);
        cout << setw(4) << Case << "." << ans_string << endl;
        Case++;
    }
    return 0;
}