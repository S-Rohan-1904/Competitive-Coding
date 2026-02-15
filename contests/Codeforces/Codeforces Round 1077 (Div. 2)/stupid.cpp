#include <iostream>
#include <vector>
using namespace std;

vector<string> binstr(int n) {
    vector<string> res;

    for (int i = 0; i < (1 << n); i++) {
        string s;

        // build string from bits of i
        for (int j = n - 1; j >= 0; --j)
            s += ((i >> j) & 1) ? '1' : '0';

        res.push_back(s);
    }
    
    return res;
}

int main() {
    int n = 5;
    vector<string> ans = binstr(n);

    cout<<ans.size()<<endl;
    for (auto &s : ans) {
        cout<<n<<endl;
        cout<<s<<endl;
    }
}