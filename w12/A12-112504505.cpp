/*
Assignment12
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
*/
#include <bits/stdc++.h>
using  namespace std;
//global variable declaration
vector <int> A, B ,C;
int m_step;
void hanoi(int n,vector <int> &A, vector <int> &B, vector <int> &C);
void display(void);
int main(void)
{
    //variable declaration
    int n_num,game_num ;
    game_num = 1;
    while (1)
    {
        //stop command
        cin >> n_num >> m_step;
        if (n_num == 0 && m_step == 0)
        {
            break;
        }
        else
        {
            cout << "Problem #" << game_num << endl;
            //fill in A with n_num plate
            for (int i = n_num; i > 0; i--)
            {
                A.push_back(i);
            }
            display();
            hanoi(n_num,A,B,C);
            game_num ++;
        }
        //clear the plate for the next game
        A.clear();
        B.clear();
        C.clear();
    }
}
//a is start， b is temp，c goal
void hanoi(int n,vector <int> &a, vector <int> &b, vector <int> &c)
{
    //stop the program when there's no step
    if (m_step == 0)
    {
        return;
    }
    //base condition (move 1 plate from a to c)(move actually occurs)
    if (n == 1)
    {
        int tmp = a[a.size()-1];
        a.pop_back();
        c.push_back(tmp);
        display();
        m_step -= 1;
        return;
    } 
    //move n - 1 plates from a to c
    hanoi(n - 1, a, c, b);
    //move nth plate from a to c
    hanoi(1,a,b,c);
    //move n plates from b to c
    hanoi(n - 1, b, a , c);
}
void display(void)
{
    //print current plate conditon
    cout << "A=>  ";
    for (int i = 0 ; i < A.size();i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "B=>  ";
    for (int i = 0 ; i < B.size();i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "C=>  ";
    for (int i = 0 ; i < C.size();i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}