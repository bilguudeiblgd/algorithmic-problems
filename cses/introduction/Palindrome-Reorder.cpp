#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    size_t len = str.size();

    int table[26];
    for (int i = 0; i < 26; i++)
        table[i] = 0;

    for (size_t i = 0; i < len; i++)
        table[str[i] - 65]++;

    int left = 0;
    int right = len - 1;
    int unique = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (table[i] % 2 == 1 && len % 2 == 0)
        {
            cout << "NO SOLUTION\n";
            return 0;
        }
        if(table[i] % 2 == 1) {
            unique++;
        }
    }
    if(unique > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    char middle = '\0';
    for (size_t i = 0; i < 26; i++)
    {
        if (table[i] > 0)
        {
            if (table[i] % 2 == 1)
            {
                middle = i + 65;
                table[i]--;
            }
            while (table[i] % 2 == 0 && table[i] > 0)
            {
                str[left] = i + 65;
                table[i]--;
                left++;
                str[right] = i + 65;
                table[i]--;
                right--;
            }
        }
    }
    if (middle)
        str[left] = middle;
    cout << str << endl;
}