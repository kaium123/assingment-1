
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string P1 = "ab";
    string P2 = "aaa";
    string T1 = "ababababab";
    string T2 = "abaabbaaabbbaaaabbbb";

    int i, k = 0;
    int mx = T1.size() - P1.size() + 1;
    int cnt = 0;

    for (k = 0; k <= mx; )
    {
        for (i = 0; i < P1.size(); i++)
        {
            if (P1[i] != T1[k+i-1]) break;
        }
        if (i == P1.size()) cnt++;

        k++;
    }
    cout<<"P1 appears "<<cnt<<" time(s) in T1."<<endl;

    k = 0;
    mx = T2.size() - P2.size() + 1;
    cnt = 0;

    for (k = 0; k <= mx; )
    {
        for (i = 0; i < P2.size(); i++)
        {
            if (P2[i] != T2[k+i-1]) break;
        }
        if (i == P2.size()) cnt++;

        k++;
    }
    cout<<"P2 appears "<<cnt<<" time(s) in T2."<<endl;


    return 0;
}
