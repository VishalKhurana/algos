#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1st approach
// the idea is to keep one part of the string fixed and swap the other parts
void permutation(string s, int left, int right)
{
    // Base case
    if (left == right)
        cout << s << endl;
    else
    {
        // swapping to create the permuation
        for (int i = left; i <= right; i++)
        {
            swap(s[left], s[i]);
            permutation(s, left + 1, right);
            swap(s[left], s[i]);
        }
    }
}
// 2nd approach
void permutationWithSTL(string s)
{
    // We first sort the string, so that it is converted to lexicographically smallest permutation
    // ascennding order
    sort(s.begin(), s.end());
    // Keep printing next permutation while there next permutation exists
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main()
{
    string str = "ABC";
    int n = str.size();
    permutation(str, 0, n - 1);
    permutationWithSTL(str);
    return 0;
}
