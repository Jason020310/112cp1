#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
bool is_first_K(int a, int b);
bool is_first_L(int a, int b);
char K_or_L;
int main(void)
{
    cin >> K_or_L;
    int num;
    cin >> num;
    int audience[num];
    for (int i = 0; i < num; i++)
    {
        cin >> audience[i];
    }
    bubbleSort(audience, num);
    cout << "Boarding Priority :" << endl;
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
            if (K_or_L == 'K')
            {
                if (is_first_K(arr[j], arr[j + 1]) == false)
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
            //開放 S 出口
            else
            {
                if (is_first_L(arr[j], arr[j + 1]) == false)
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}
// a 順序比 b 優先輸出true 
bool is_first_K(int a, int b)
{
    int a_thousand = a / 1000;
    int b_thousand = b / 1000;
    // 123
    if (a_thousand == 3 && b_thousand != 3)
    {
        return true; 
    }
    else if (a_thousand == 2 && b_thousand == 1)
    {
        return true; 
    }
    else if (a_thousand == b_thousand)
    {
        // 商務艙
        if (a_thousand == 1 )
        {
            // 百位數字
            if ((a / 100)  % 10 >  (b / 100)  % 10)
            {
                return true;
            }
            else if ((a / 100)  % 10 ==  (b / 100)  % 10)
            {
                if( a % 100 < b % 100)
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
        //  豪經根莖
        else
        {
            // 百位數字
            if ((a / 100)  % 10 >  (b / 100)  % 10)
            {
                return true;
            }
            else if ((a / 100)  % 10 ==  (b / 100)  % 10)
            {
                if( a % 100 > b % 100)
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
bool is_first_L(int a, int b)
{
    int a_thousand = a / 1000;
    int b_thousand = b / 1000;
    // 123
    if (a_thousand == 1 && b_thousand != 1)
    {
        return true; 
    }
    else if (a_thousand == 2 && b_thousand == 3)
    {
        return true; 
    }
    else if (a_thousand == b_thousand)
    {
        // 經濟艙
        if (a_thousand == 3 )
        {
            // 百位數字
            if ((a / 100)  % 10 >  (b / 100)  % 10)
            {
                return true;
            }
            else if ((a / 100)  % 10 ==  (b / 100)  % 10)
            {
                if( a % 100 > b % 100)
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
        //  豪經根莖
        else
        {
            // 百位數字
            if ((a / 100)  % 10 >  (b / 100)  % 10)
            {
                return true;
            }
            else if ((a / 100)  % 10 ==  (b / 100)  % 10)
            {
                if( a % 100 < b % 100)
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