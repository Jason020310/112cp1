/*
Practice14
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
void swap(int* a, int* b);
void bubbleSort(int* arr, int n);
bool is_first(int a, int b);
using namespace std;
int main(void)
{
    string row_or_col;
    cin >> row_or_col;
    string A[7][7] = {""};
    string B[5][5] = {""};
    int times;
    cin >> times;
    int all[times];
    //存error 位置座標
    const int error_A_x[2] = {4, 6};
    const int error_A_y[2] = {4, 1};
    const int error_B_x[2] = {1, 4};
    const int error_B_y[2] = {2, 3};
    for (int i = 0; i < times; i++)
    {
        cin >> all[i];
    }
    bubbleSort(all, times);
    int t = 0;
    // 根據排好的 array 填入 A 
    if (row_or_col == "row")
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                //填入 error 座標
                if (i == error_A_x[0] && j == error_A_y[0])
                {
                    A[i][j] = "err";
                }
                else if (i == error_A_x[1] && j == error_A_y[1])
                {
                    A[i][j] = "err";
                }
                else
                {
                    //超過 all 的長度就輸出 xxx
                    if (t >= times)
                    {
                        A[i][j] = "xxx";
                    }
                    else
                    {
                        A[i][j] = to_string(all[t]);
                        t++;
                    }
                }
            }
        }
        //填入B
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == error_B_x[0] && j == error_B_y[0])
                {
                    B[i][j] = "err";
                }
                else if (i == error_B_x[1] && j == error_B_y[1])
                {
                    B[i][j] = "err";
                }
                else
                {
                    if (t >= times)
                    {
                        B[i][j] = "xxx";
                    }
                    else
                    {
                        B[i][j] = to_string(all[t]);
                        t++;
                    }
                }
            }
        }
    }
    //by col ij 倒過來
    else
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (j == error_A_x[0] && i == error_A_y[0])
                {
                    A[j][i] = "err";
                }
                else if (j == error_A_x[1] && i == error_A_y[1])
                {
                    A[j][i] = "err";
                }
                else
                {
                    if (t >= times)
                    {
                        A[j][i] = "xxx";
                    }
                    else
                    {
                        A[j][i] = to_string(all[t]);
                        t++;
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == error_B_x[0] && i == error_B_y[0])
                {
                    B[j][i] = "err";
                }
                else if (j == error_B_x[1] && i == error_B_y[1])
                {
                    B[j][i] = "err";
                }
                else
                {
                    if (t >= times)
                    {
                        B[j][i] = "xxx";
                    }
                    else
                    {
                        B[j][i] = to_string(all[t]);
                        t++;
                    }
                }
            }
        }
    }
    //輸出答案
    cout << "Room A :" << endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl << endl;
    }

    cout << endl << "Room B :" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl << endl;
    }
}
//交換 a b
void swap(int* a, int* b)
{
    int* tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            // 如果優先順序錯了就交換
            if (is_first(arr[j], arr[j + 1]) == false)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// a 優先順序高則輸出 b
bool is_first(int a, int b)
{
    //比個位數
    if (a % 100 > b % 100)
    {
        return false;
    }
    else if (a % 100 < b % 100)
    {
        return true;
    }
    else
    {
        //比百位數
        if ((a / 100) > (b / 100))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
