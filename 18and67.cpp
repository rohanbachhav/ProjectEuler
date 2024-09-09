#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define newline cout << "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;

bool isPrime(int n) {
   if (n <= 1) {
      return false;
   }
   if (n <= 3) {
      return true;
   }
   if (n % 2 == 0 || n % 3 == 0) {
      return false;
   }
   for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) {
         return false;
      }
   }
   return true;
}

bool isPalindrome(int x) {
   str s = to_string(x);
   int n = s.size();

   for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) return 0;
   }
   return 1;
}

ll sumOfNNaturalNumbers(ll n) {
   return n * (n + 1) / 2;
}

ll square(ll n) {
   return n * n;
}

int r, c;
vector<vector<ll>> a;

void solve() {

   ll t = 1;
   cin >> t;

   r = c = t;

   a.resize(r + 2);
   for (int i = 0; i < r + 2; i++) {
      a[i].resize(c + 2);
   }

   for (ll row = 1; row < r + 1; row++) {
      for (int col = 1; col < row + 1; col++) {
         cin >> a[row][col];
      }
   }

   for (ll row = 1; row < r + 1; row++) {
      for (int col = 1; col < c + 2; col++) {
         a[row][col] += max(a[row - 1][col], a[row - 1][col - 1]);         
      }
   }

   // for (ll row = 0; row < r + 1; row++) {
   //    for (int col = 0; col < c + 1; col++) {
   //       cout << a[row][col] << " ";
   //    } 
   //    newline;
   // }

   ll ans = 0;

   for (int i = 1; i < c + 2; i++) {
      cout << a[r][i] << " ";
      ans =  max(ans, a[r][i]);
   }
   newline;
   cout << ans << nl;
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
