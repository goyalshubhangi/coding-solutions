// https://www.codechef.com/problems/RBTREE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t = 1;
    //cin>>t;
    while (t--)
    {
        long q, n, i, m = 0, x, y, k, f = 1, mod = 1000000, c;
        cin >> q;
        long a[n];
        while (q--)
        {
            string s;
            cin >> s;
            c = 0;
            map<long, long> mp;
            if (s == "Qi")
            {
                m = m ^ 1;
                continue;
            }
            if (s == "Qr")
            {
                if (m == 0)
                    f = 0;
                else
                    f = 1;
            }
            else
            {
                if (m == 0)
                    f = 1;
                else
                    f = 0;
            }
            cin >> x >> y;
            while (x)
            {
                k = log2(x);
                k++;
                if (k % 2 == f)
                {
                    c++;
                }
                mp[x] = 1;
                x = x / 2;
            }
            x = y;
            long h = 0;
            //cout<<f<<" ";
            while (x)
            {
                k = log2(x);
                k++;
                if (k % 2 == f)
                {
                    if (mp[x])
                    {
                        //cout<<x<<" "<<h<<" ";
                        if (h)
                            c--;
                        h = 1;
                    }
                    else
                        c++;
                }
                if (mp[x])
                    h = 1;
                //cout<<x<<" "<<mp[x]<<" ";
                x = x / 2;
            }
            cout << c << " ";
            //cout<<endl;
        }
        //cout<<"\n";
    }
    return 0;
}