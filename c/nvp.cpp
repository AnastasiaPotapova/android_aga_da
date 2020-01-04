#include<bits/stdc++.h>

using namespace std;

vector<int> findLIS(vector<int> a):
   int n = a.size                     //размер исходной последовательности
   int d[0..n]
   int pos[0..n]
   int prev[0..n - 1]
   length = 0

   pos[0] = -1
   d[0] =
   for i = 1 to n
       d[i] =
   for i = 0 to n - 1
       j = binary_search(d, a[i])
       if (d[j - 1] < a[i] and a[i] < d[j])
           d[j] = a[i]
           pos[j] = i
           prev[i] = pos[j - 1]
           length = max(length, j)

   // восстановление ответа
   vector<int> answer
   p = pos[length]
   while p != -1
       answer.push_back(a[p])
       p = prev[p]
   reverse(answer)

   return answer;

int main()
{
    vector<int> d(100);
    int n = 10;
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    vector <int> ans = findLis(d);
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i];
}
