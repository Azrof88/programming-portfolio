#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {

        int n;
        cin>>n;
        string s;
        cin >> s;
        double m=sqrt(n);
        if(ceil(m)!=floor(m))
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            int r = m;
            if(i < r || (n - i) < r || i % r == 0 || i % r == r - 1){
                if(s[i] != '1') ok = false;
            }
            else{
                if(s[i] != '0') ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}