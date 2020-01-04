#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long double a, b, c;
    cin >> a >> b >> c;
    long long sum = 2 * a + 3 * b + 4 * c;
    long long cnt = a + b + c;
    long long m, l = 0, r = cnt + 1;
    while (l < r)
    {
         m = (l + r) / 2;
        if ((sum + 5.0 * m) / (cnt + m) < 3.5)
            l = m + 1;
        else
            r = m;
    }
    cout << l;
}
