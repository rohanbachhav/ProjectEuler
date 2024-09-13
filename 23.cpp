#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define newline cout << "\n"

using str = string;
using ll = long long;
using ld = long double;

void solve() {

   vector<ll> abundantNumbers;

   for (int i = 2; i < 28124; i++) {
      int sum = 1;
      // the commented part is wrong because it leads to some extra abundant numbers
      // if (sqrt(i) * sqrt(i) == i) {
      //    sum += sqrt(i);
      // }
      for (int j = 2; j <= i / 2; j++) {
         if (i % j == 0) {
            sum += j;
            // sum += i / j;
         }
      }
      if (sum > i) abundantNumbers.pb(i);
   }

   
   int a[28124] = {0};
   int n = abundantNumbers.size();

   cout << "n : " << n << nl;

   for (int i = 0; i < n; i++) {
      cout << abundantNumbers[i] << ' ';
   }
   newline;

   fstream myFile("example.txt", ios::out);

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int temp = abundantNumbers[i] + abundantNumbers[j];
         if (temp < 28124) {
            a[temp] = 1;
            // myFile << abundantNumbers[i] << ' ' << abundantNumbers[j] << ' ';
            // myFile << temp << nl;
         } else {
            break;
         }
      }
   }
   myFile.close();

   ll ans = 0;

   for (int i = 1; i < 28124; i++) {
      if (!a[i]) {
         ans += i;
         // cout << i << ' ';
      }
   }

   for (int i = 0; i < 28124; i++) {
      // if (!a[i]) {
         // cout << i << ' ' << a[i] << nl;
      // }
   }


   cout << ans;

   newline;

}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int TESTCASES = 1;
   // cin >> TESTCASES;

   while (TESTCASES--) {
      solve();
   }
   return 0;
}
