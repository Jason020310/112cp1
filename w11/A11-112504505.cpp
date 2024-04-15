/*
Assignment11
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
*/

#include <bits/stdc++.h>
using namespace std;
//函數宣告
string palindrome(int n);
int basedivision(string n);
int main(void)
{
    //向量初始化
    vector <string> all_palindrome;
    vector <int> all_basedivision;
    //不斷執行
    while (1)
    {
        //接受指令
        int command;
        cin >> command;
        if (command == 1)
        {
            //印出此遊戲開頭與變數宣告
            cout << "Game:Palindrome" << endl;
            string result;
            int n;
            cin >> n;
            //將此遊戲結果存入result
            result = palindrome(n);
            //存入all_palindrome
            all_palindrome.push_back(result);
            //印出結果
            cout << "Result:" <<  result << endl;
        }
        else if (command == 2)
        {
            cout << "Game:BaseDivision" << endl;
            string N;
            int result;
            cin >> N;
            //將結果存入result
            result = basedivision(N);
            //存入all_basedivision
            all_basedivision.push_back(result);
            cout << "Result:" << result << endl;
        }
        else if (command == 3)
        {
            cout << "Result of the game:" << endl;
            int n;
            cin >> n;
            //如果是palindrome
            if (n == 1)
            {
                //排序
                sort(all_palindrome.begin(),all_palindrome.end());
                cout << "Palindrome:";
                if (all_palindrome.size() == 0)
                {
                    cout << "No result" << endl;
                }
                //印出所有palindrome的結果
                else
                {
                    for (int i = 0; i < all_palindrome.size(); i++)
                    {
                        cout << all_palindrome[i] << " ";
                    }
                cout << endl;
                }
            }
            else if (n == 2)
            {
                //排序
                sort(all_basedivision.begin(),all_basedivision.end());
                cout << "BaseDivision:";
                if (all_basedivision.size() == 0)
                {
                    cout << "No result" << endl;
                }
                else
                {
                    //印出所有basedivision 結果
                    for (int i = 0; i < all_basedivision.size(); i++)
                    {
                        cout << all_basedivision[i] << " ";
                    }
                    cout << endl;
                }
            }

        }
        //結束指令
        else if (command == 4)
        {
            cout << "End program" << endl;
            return 0;
        }
        //錯誤指令
        else
        {
            cout << "Error" << endl;
        }
    }
}
string palindrome(int n)
{
    string sn;
    string n_string;
    //將n轉乘string
    n_string = to_string(n);
    //遞迴base condition
    if (n == 1)
    {
        sn = "1";
    }
    //遞迴關係式
    else
    {
        sn = palindrome(n - 1) + n_string + palindrome(n - 1);
    }
    return sn;
}
int basedivision(string n)
{
    int R = 2;
    //R從2 開始找直到找到符合的
    while(1)
    {
        //將n轉乘R進位
        }
        //如果R - 1可以整除 n　則跳出迴圈
        if (base_convert > 0)
        {
            if (base_convert % (R - 1) == 0)
            {
                return R;
            }
        }
        R += 1;
    }
}