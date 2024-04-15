/*
Practice15
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
bool isPrime(int *num);
void backtrack(int now, int num,bool *visit, vector <int> *ans);
int n;
bool visited[20];
int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t;i++)
    {
        cin >> n;
        ans.clear();
        ans.push_back(1);
        memset(visited, 0, sizeof(visited));
        visited[1] = 1;
        cout << "Case " << i + 1 << ":" << endl;
        backtrack(2, n, visited, &ans);
    }
    return 0;
}
bool isPrime(int *num)
{
    //判斷是否為質數
    for(int i = 2; i < *num / 2 + 1;i++)
    {
        if(*num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void backtrack(int now, int num,bool *visit, vector <int> *ans)
{
    //回溯DF
    int a; 
    a = (*ans).back() + 1;
    if(now > num && isPrime(&a))
    {
        for(int i = 0; i < num - 1;i++)
        {
            cout << (*ans)[i] << " ";
        }
        cout << (*ans)[num - 1] << endl;
        return;
    }
    for(int i = 1; i <= num;i++)
    {
        a = (*ans).back() + i;
        if(!visited[i] && isPrime(&a))
        {
            //如果沒有 visit 過且與前項相加為質數，且放入
            (*ans).push_back(i);
            visited[i] = 1;
            backtrack(now + 1, num, visited, &(*ans));
            //取出，回溯過程
            visited[i] = 0;
            (*ans).pop_back();
        }
    }
}