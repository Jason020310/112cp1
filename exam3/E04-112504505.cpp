#include <bits/stdc++.h>
using namespace std;
int GetLucky(vector <int> &vec, int left, int right)
{
    if(left == right)
    {
        return vec[left];
    }
    int minn = 1001;
    int min_index = 0;
    for (int i = left ; i <= right;i++)
    {
        if( vec[i] < minn)
        {
            min_index = i;
            minn = vec[i];
        }
    }
    int left_num = 0,right_num = 0;
    for(int i = left; i < min_index;i++)
    {
        left_num += vec[i];
    }
    for(int i = min_index + 1; i < right;i++)
    {
        right_num += vec[i];
    }
    if(left_num > right_num)
    {
        return GetLucky(vec, left,min_index - 1);
    }
    else
    {
        return GetLucky(vec,min_index + 1,right);
    }
}
int main(void)
{
    vector <int> vec;
    int n, luck;
    while (cin >> n)
    {
        if(n == -1)
        {
            break;
        }
        vec.push_back(n);
    }
    luck = GetLucky(vec, 0,vec.size() - 1);
    cout << luck << endl;
}