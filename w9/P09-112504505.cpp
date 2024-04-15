/*
Practice9
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    //有幾關
    int times;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        //變數初始化
        int s,climb_times = 0, descend_times = 0, maintain_times = 0, climb_distance = 0, descend_distance = 0, maintain_distance= 0;
        //有幾個水管
        cin >> s;
        //上一個座標變數
        int x_before, y_before;
        cin >> x_before >> y_before;
        //有幾關執行幾次
        for (int j = 0; j < s; j++)
        {
            //儲存現在位置的變數
            int x_current,y_current;
            cin >> x_current >> y_current;
            //如果是上升
            if (y_current > y_before)
            {
                climb_times += 1;
                //上升前進的距離
                climb_distance += (x_current - x_before);
            }
            //下降
            else if (y_current < y_before)
            {
                descend_times += 1;
                //下降前進的距離
                descend_distance += (x_current - x_before);
            }
            //維持
            else
            {
                maintain_times += 1;
                maintain_distance += (x_current - x_before);
            }
            //儲存至下次迴圈的上一個座標
            x_before = x_current;
            y_before = y_current;
        }
        //輸出結果
        cout << "---CASE" << i + 1 << "---" << endl;
        cout << "Climb times:" << climb_times << " Distance:" << climb_distance - climb_times << endl;
        cout << "Descent times:" << descend_times << " Distance:" << descend_distance - descend_times << endl;
        cout << "Maintain times:" << maintain_times << " Distance:" << maintain_distance - maintain_times << endl;
    } 
}