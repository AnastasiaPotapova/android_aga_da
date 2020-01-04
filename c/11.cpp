#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> ans(n);
    multiset <int> num;

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        num.insert(k);
    }

    for (int i = 0; i < n; i++) {
        k = n - ans[i];
        auto it = num.lower_bound(k);
        if (it != num.end()) {
            ans[i] = (*it + ans[i]) % n;
            num.erase(it);
        } else {
            ans[i] = (*num.begin() + ans[i]) % n;
            num.erase(num.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
