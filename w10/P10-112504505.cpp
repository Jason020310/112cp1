/*
Practice10
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //次數變數初始化
    int t;
    cin >> t;
    //用while loop 執行 t 次
    while(t--){
        //變數初始化及接受輸入
        int n,k;
        cin >> n >> k;
        string s;
        //有n - k 個零
        for(int i = 0;i < n - k; i++)
        {
            s.append("0");
        }
        //k 個 1
        for(int i = 0;i < k; i++)
        {
            s.append("1");
        }
        //利用next_permutation 做出所有s 的排列組合
        do 
        {
            cout << s << "\n";
        }
        while (next_permutation(s.begin(), s.end()));
        cout<<'\n';
    }
}