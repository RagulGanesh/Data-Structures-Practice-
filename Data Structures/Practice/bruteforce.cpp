#include <iostream>
using namespace std;
void bruteForce(string t, string p)
{
    int m, n, i, j;
    m = t.length();
    n = p.length();
    for (i = 0; i <= m - n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (t[i + j] != p[j])
            {
                break;
            }
        }
        if (j == n)
        {
            cout << "Found at " << i << " index";
        }
    }
}
int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    bruteForce(text, pattern);
}