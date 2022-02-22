#include <iostream>
using namespace std;
#define d 256
const int q = 101;
void rabinkarp(string text, string pattern, int m, int n)
{
    int h = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        h = (h * d) % q;
    }
    int p, t, i, j;
    p = t = 0;
    for (int i = 0; i < n; i++)
    {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }
    for (i = 0; i <= (m - n); i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < n; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }

                
            }
            if (flag == true)
                cout <<i<<" ";
        }

        if (i < m - n)
        {
            t = ((d * (t - text[i] * h)) + text[i + n]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}
int main()
{
    string text, pattern;
    cout << "Enter the text string : ";
    cin >> text;
    cout << "Enter the pattern string : ";
    cin >> pattern;
    cout << "Indices are :"
         << " \n";
    rabinkarp(text, pattern, text.length(), pattern.length());

    return 0;
}