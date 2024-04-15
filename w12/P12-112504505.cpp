/*
Practice12
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
string change(string num);
int calculate_ascii(string s1);
string find_s(string s);
//初始化 對應陣列
string arr[6] = {"tyuiafdhjka","zxssssqejjiucv","asdf","qwer","[][][][][]","{}[]{}[]{}[]{}[]"};
int main(void)
{
    //變數宣告
    string num,blibli_num;
    int ascii,count;
    //計數變數
    count = 1;
    while(getline(cin,num))
    {
        //得到對應不理不理王國的數字
        blibli_num = change(num);
        //計算ascii code 總和
        ascii = calculate_ascii(blibli_num);
        //印出結果
        cout << "Case " << count << ":" << blibli_num << endl;
        cout << "Ascii Sum = " << ascii << endl;
        count += 1;
    }
    
}
string change(string num)
{
    string s,s1;
    //遞迴中止條件
    if (num.length() == 1)
    {
        s =  " " + num;
        //如果開頭為零即什麼也不輸出
        if(num == "0")
        {
            return "";
        }
        //非零則回傳此數
        else
        {
             return s;
        }
    }
    else
    {
        string single_string(1,num[0]),s1;
        //如果開頭為零則s1 = 對應符號 無數字
        if (single_string == "0")
        {
            s1 = "";
            if (find_s(num) == arr[5])
            {
                s1 = " " +arr[5];
            }
        }
        //正常情況
        else
        {
            s1 = " " + single_string + " " + find_s(num);
        }
        s = s1 + change(num.substr(1, num.length() - 1));
        return s;
    }
}
int calculate_ascii(string s1)
{
    int ascii = 0;
    //每字ascii 累加
    for (int i = 0,j = s1.length(); i < j; i++)
    {
        ascii += int(s1[i]);
    }
    return ascii;
}
string find_s(string s)
{
    int s_len = s.length();
    //特例處理
    if (s_len % 6 == 0)
    {
        return arr[4];
    }
    else if (s_len % 6 == 1)
    {
        return arr[5];
    }
    // 回傳對應符號
    else
    {
         return arr[s_len % 6 - 2];
    }
}