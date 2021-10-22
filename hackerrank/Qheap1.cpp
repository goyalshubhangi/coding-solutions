// https://www.hackerrank.com/challenges/qheap1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;
    vector<int> vlist;
    
    for(int i = 0; i < n; i ++)
    {
        int c, v;
        c = v = -1;
        cin >> c;
        if(c == 1 || c == 2)
            cin >> v;
        vlist.push_back(c);            
        vlist.push_back(v);            
    }    
    
    multiset<int> uset;
    for(int i = 0; i < n; i ++)
    {
        int c = vlist[i * 2];
        int v = vlist[i * 2 + 1];
        
        if(c == 1)
            uset.insert(v);
        else if(c == 2)
            uset.erase(uset.find(v));
        else
            cout << (*uset.begin()) << endl;
            
            
    }    
    return 0;
}
