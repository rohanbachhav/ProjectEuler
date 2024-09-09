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

ll r = 4, c = 4;
vector<vector<ll>> a; 
ll ans = 0;

void dfs(int row, int col) {
   if (row > r || col > r) return;
   if (row == r && col == c) {
      ans++;
      // cout << ans << nl;
   }

   dfs(row, col + 1);
   dfs(row + 1, col);

}

void solve() {

   // https://projecteuler.net/problem=15
   // projecteuler problem 15 : Lattice Paths
   // tried brute force dfs at first !!!

   // the answer for a grid of size n * m,
   // would be a[n + 1][m + 1]

   // the 2d-grid is 1-indexed
   // a[0][0] represents point [0, 0] starting from top left

   ll t = 1;
   cin >> t;

   r = t, c = t;

   a.resize(r + 2);
   for (int i = 0; i < r + 2; i++) {
      a[i].resize(c + 2);
   }

   a[1][1] = 1;

   for (int i = 1; i < r + 2; i++) {
      for (int j = 1; j < c + 2; j++) {
         a[i][j] += a[i - 1][j] + a[i][j - 1];
      }
   }

   for (int i = 1; i < r + 2; i++) {
      for (int j = 1; j < c + 2; j++) {
         cout << a[i][j] << " ";
      }
     newline;
   }

   ans = a[r + 1][c + 1];
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
