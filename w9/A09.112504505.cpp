/*
Assignment9
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    // 變數初始化與變數儲存
    int times;
    cin >> times;
    // 有幾回合執行幾次
    for (int i = 0; i < times; i++)
    {
        // 輸出現在是第幾回合
        cout << "---第" << i + 1 << "回合---" << endl;
        int s;
        cin >> s;
        // 儲存上一個座標
        int x_before, y_before;
        cin >> x_before >> y_before;
        // 有幾根柱子執行幾次
        for (int j = 0; j < s; j++)
        {
            // 儲存現在的座標
            int x_current, y_current;
            cin >> x_current >> y_current;
            // 計算垂直位移
            y_before = y_before - (x_current - x_before - 1);
            // 判斷並輸出結果
            if (y_current > y_before)
            {
                cout << "上升：" << y_current - y_before << endl;
            }
            else if (y_current < y_before)
            {
                cout << "下降：" << y_before - y_current << endl;
            }
            else
            {
                cout << "維持" << endl;
            }
            // 更新座標
            x_before = x_current;
            y_before = y_current;
        }
    }
    return 0;
}
