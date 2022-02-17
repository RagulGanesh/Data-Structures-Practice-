#include <iostream>
using namespace std;
int bruteForce(string t, string p)
{
    int n, m;
    n = t.length();
    m = p.length();
    int i, j,flag=0;
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (t[i + j] != p[j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout<<i<<" ";
            flag=1;
        }
    }
    return flag;
}
int main()
{
    string text, pattern;
    cout << "Enter the text string : ";
    cin >> text;
    cout << "Enter the pattern string : ";
    cin >> pattern;
    cout<<"Match found at index : ";
    int res = bruteForce(text, pattern);
    if (res == 0)
    {
        cout << "No match ";
    }
}