/*
Assignment10
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
bool check(string);
int main(void)
{
    //變數初始化
    int t, count;
    cin >> t;
    //用while loop 使執行t 次
    while(t--){
        //變數初始化 與接受輸入
        int n,k;
        count = 0;
        cin >> n >> k;
        string s;
        //有n - k 個 0
        for(int i = 0;i < n - k; i++)
        {
            s.append("0");
        }
        //有k 個1
        for(int i = 0;i < k; i++)
        {
            s.append("1");
        }
        //用next permutation 做出所有排列組合 並計數
        do 
        {
            if (check(s))
            {
                cout << s << "\n";
                count += 1;
            }
        }
        while (next_permutation(s.begin(), s.end()));
        //沒有排列則輸出none
        if (count == 0)
        {
            cout << "none" ;
        }
        cout <<'\n';
    }
}

bool check(string str)
{
    //如果有連續兩個1 相連則輸出false
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == '1')
        {
            if (str[i + 1] == '1')
            {
                return false;
            }
        }
    }
    //否則輸出true
    return true;
}
