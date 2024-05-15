#include<iostream>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    for (int j = 0; j < N; j++)
    {
        for (int i = N; i > j; i--)
        {
            cout << "*";
        }
        cout << "\n";
    }
}