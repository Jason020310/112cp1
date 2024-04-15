/*
Practice11
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
//函數宣告
void compute_place(int m_second,int& x, int& y);
int main(void)
{
    while(1)
    {
        int x = 0;
        int y = 0;
        int m_second;
        cin >> m_second;
        //結束指令
        if (m_second == 0)
        {
            break;
        }
        else
        {
            //計算並印出結果
            compute_place(m_second,x,y);
            cout << x << "," << y << endl;
        }

    }
}
void compute_place(int m_second,int& x, int& y)
{
    int count = 1;
    //計算m 在哪個數的平方之間
    while (1)
    {
        if (m_second > pow(count,2))
        {
            count += 1;
            continue;
        }
        else
        {
            break;
        }
    }
    count -= 1;
    m_second -= pow(count, 2);
    //如果count 為偶數
    if (count % 2 == 0)
    {
        //如果還有時間先往右走
        x = count - 1;
        if (m_second > 0)
        {
            x += 1;
            m_second -= 1;
        }
        //還有時間再往上走且不能超過邊界
        while (m_second > 0 && y < count)
        {
            y += 1;
            m_second -= 1;
        }
        //再有時間則往左走
        while (m_second > 0)
        {
            x -= 1;
            m_second -= 1;
        }
    }
    else
    {
        //若count 為奇數
        y = count - 1;
        //如果還有時間則先往上走一格
        if (m_second > 0)
        {
            y += 1;
            m_second -= 1;
        }
        //再有時間則往右走
        while (m_second > 0 && x < count)
        {
            x += 1;
            m_second -= 1;
        }
        //還是有時間再往下走
        while (m_second > 0)
        {
            y -= 1;
            m_second -= 1;
        }
    }
    return;
}