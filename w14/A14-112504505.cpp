/*
Assignment14
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
*/
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
bool is_first_S(int a, int b);
bool is_first_V(int a, int b);
char v_or_s;
const int special[6] = {211,221,231,113,123,133};
int main(void)
{
    cin >> v_or_s;
    int num;
    cin >> num;
    int audience[num];
    for (int i = 0; i < num; i++)
    {
        cin >> audience[i];
    }
    bubbleSort(audience, num);
    cout << "Line:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << audience[i] << " ";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int tmp  = *a;
    *a = *b;
    *b = tmp;
}
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            //開放V出口
            if (v_or_s == 'V')
            {
                if (is_first_V(arr[j], arr[j + 1]) == false)
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
            //開放 S 出口
            else
            {
                if (is_first_S(arr[j], arr[j + 1]) == false)
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}
// a 順序比 b 優先輸出true 
bool is_first_S(int a, int b)
{
    bool a_is_special = false;
    bool b_is_special = false;
    int a_hundred = a / 100;
    int b_hundred = b / 100;
    //找出ab 是否為 special                                     al
    for (int i = 0 ; i < 6;i++)
    {
       if (b == special[i])
       {
            b_is_special = true;
       }
       if (a == special[i])
       {
            a_is_special = true;
       }
    }
    // a 是special 但 b 非special  a 在前面
    if (a_is_special && !b_is_special)
    {
        return true;
    }
    else if (b_is_special && !a_is_special)
    {
        return false;
    }
    // ab 都是 special 或 ab 都不是 special (順序 是 132)
    if (a_hundred == 1 && b_hundred != 1)
    {
        return true; 
    }
    else if (a_hundred == 3 && b_hundred == 2)
    {
        return true; 
    }
    else if (a_hundred == b_hundred)
    {
        // B 的情況
        if (a_hundred == 2)
        {
            //先比個位數 個位數字大優先
            if (a % 10 > b % 10)
            {
                return true;
            }
            else if (a % 10 == b % 10)
            {
                //在比十位數 十位數字大優先
                if ((a / 10) % 10 > (b / 10) % 10)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        // A C 的
        else
        {
            //先比個位數字 數字小優先
            if (a % 10 < b % 10)
            {
                return true;
            }
            else if (a % 10 == b % 10)
            {
                //再比十位數字 數字大優先
                if ((a / 10) % 10 > (b / 10) % 10)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
//優先順序是百位數 231 a 順序比 b 優先輸出true 
bool is_first_V(int a, int b)
{
    bool a_is_special = false;
    bool b_is_special = false;
    int a_hundred = a / 100;
    int b_hundred = b / 100;
    //a b 是否為special 
    for (int i = 0 ; i < 6;i++)
    {
       if (b == special[i])
       {
            b_is_special = true;
       }
       if (a == special[i])
       {
            a_is_special = true;
       }
    }
    // a 是special b 不是special
    if (a_is_special && !b_is_special)
    {
        return true;
    }
    // b 是specail a 不是special
    else if (b_is_special && !a_is_special)
    {
        return false;
    }
    // a b  都是 special 或 都不是special
    // 判斷百位數優先順序
    if (a_hundred == 2 && b_hundred != 2)
    {
        return true; 
    }
    else if (a_hundred == 3 && b_hundred == 1)
    {
        return true; 
    }
    else if (a_hundred == b_hundred)
    {
        // 1 (A 區)的情況
        if (a_hundred == 1)
        {
            // 判斷個位數順序 數字小優先
            if (a % 10 < b % 10)
            {
                return true;
            }
            else if (a % 10 == b % 10)
            {
                //比十位數 數字小優先
                if ((a / 10) % 10 < (b / 10) % 10)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        // 23 ( vip 與 b 區)的
        else
        {
            // 判斷個位數順序
            if (a % 10 > b % 10)
            {
                return true;
            }
            else if (a % 10 == b % 10)
            {
                //判斷十位數順序
                if ((a / 10) % 10 < (b / 10) % 10)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}