#include <bits/stdc++.h>
using namespace std;
vector <int> sequence;
int find_max(void);
bool check(int n);
int remain(int n,int quotient);
int main(void)
{
    int answer;
    while(1)
    {
        sequence.clear();
        int first,max;
        cin >> first;
        if (first == 0)
        {
            break;
        }
        else
        {
            sequence.push_back(first);
            max = first;
        }
        while (1)
        {
            int n;
            cin >> n;
            if (n == 0)
            {
                break;
            }
            else
            {
                if (n > max)
                {
                    max = n;
                }
                sequence.push_back(n);
            }
        }
        for (int i = 1 ; i < max; i++) 
        {
            if (check(i))
            {
                answer = i;
            }
        }
        cout << answer << endl;
    }
}

bool check(int n)
{
    int remainder;
    remainder = remain(sequence[0], n);
    cout << remainder << endl;
    int size = sequence.size();
    for (int i = 0; i < size ;i++ )
    {
        if (remain(sequence[i],n)  == remainder)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int remain(int n,int quotient)
{
    if (n > 0)
    {
        return n % quotient;
    }
    else
    {
        int r;
        r = (n % quotient) + quotient;
        return r;
    }
}