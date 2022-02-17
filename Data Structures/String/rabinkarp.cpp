#include <iostream>
using namespace std;
#define d 256
const int q = 101;
void rabinKarp(string pattern, string text, int m, int n)
{

    // Compute (d^(M-1))%q
    int h = 1;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;

    // Compute p and to
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (int i = 0; i <= (n - m); i++)
    {
        // Check for hit
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }
        // Compute ti+1 using ti
        if (i < n - m)
        {
            t = ((d * (t - text[i] * h)) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
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
         << " ";
    rabinKarp(pattern, text, pattern.length(), text.length());

    return 0;
}