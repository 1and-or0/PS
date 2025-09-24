#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string word1;
string word2;

int main()
{
    cin >> word1;
    cin >> word2;

    // Please write your code here.
    const int size = (int)('z' - 'a') + 1;
    int cnt1[size] = { 0 };
    int cnt2[size] = { 0 };
    bool isNo = false;
    int n = max(word1.length(), word2.length());
    if (word1.length() != word2.length())
    {
        isNo = true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cnt1[word1[i]] += 1;
            cnt2[word2[i]] += 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (cnt1[i] != cnt2[i])
            {
                isNo = true;
                break;
            }
        }
    }

    if (isNo)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    return 0;
}
