#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define newline cout << "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;

str twoDigitNumber(str s) {
   str res = "";

   if (s.substr(0, 2) == "10") {
         res += "ten";
   } else if (s.substr(0, 2) == "11") {
      res += "eleven";
   } else if (s.substr(0, 2) == "12") {
      res += "twelve";
   } else if (s.substr(0, 2) == "13") {
      res += "thirteen";
   } else if (s.substr(0, 2) == "14") {
      res += "fourteen";
   } else if (s.substr(0, 2) == "15") {
      res += "fifteen";
   } else if (s.substr(0, 2) == "16") {
      res += "sixteen";
   } else if (s.substr(0, 2) == "17") {
      res += "seventeen";
   } else if (s.substr(0, 2) == "18") {
      res += "eighteen";
   } else if (s.substr(0, 2) == "19") {
      res += "nineteen";
   } else if (s[0] == '2') {
      res += "twenty";
   } else if (s[0] == '3') {
      res += "thirty";
   } else if (s[0] == '4') {
      res += "forty";
   } else if (s[0] == '5') {
      res += "fifty";
   } else if (s[0] == '6') {
      res += "sixty";
   } else if (s[0] == '7') {
      res += "seventy";
   } else if (s[0] == '8') {
      res += "eighty";
   } else if (s[0] == '9') {
      res += "ninety";
   }

   if (s.substr(0, 1) != "0") res += " ";

   return res;
}

str oneToNine(char c) {
   str res = "";

   switch(c) {
      case '1' : 
         res += "one";
         break;
      case '2' : 
         res += "two";
         break;
      case '3' : 
         res += "three";
         break; 
      case '4' : 
         res += "four";
         break;
      case '5' : 
         res += "five";
         break;
      case '6' : 
         res += "six";
         break;
      case '7' : 
         res += "seven";
         break;
      case '8' : 
         res += "eight";
         break;
      case '9' : 
         res += "nine";
         break;
   }

   if (c != '0') res += " ";
   
   return res;
}

str wordMap(str s) {
   str res = "";

   if (s.size() == 1) {
      res += oneToNine(s[0]);
   }

   else if (s.size() == 2) {
      res += twoDigitNumber(s.substr(0, 2));

      if (s[0] != '1') {
         res += wordMap(s.substr(1, 1));
      }
   }

   else if (s.size() == 3) {
      res += oneToNine(s[0]);

      if (s[0] != '0') {
         res += "hundred ";
      }

      if (s.substr(1, 2) != "00") {
         res += "and ";
      }

      res += wordMap(s.substr(1, 2));
   }

   else if (s.size() == 4) {
      res += oneToNine(s[0]);

      if (s[0] > '0') {
         res += "thousand ";
      }

      res += wordMap(s.substr(1, 3));
   }

   else if (s.size() == 5) {
      res += wordMap(s.substr(0, 2));

      if (s.substr(0, 2) != "00") {
         res += "thousand ";
      }

      res += wordMap(s.substr(2, 3));
   }

   return res;
   
}

str numberToWord(ll n) {
   str res;
   str s = to_string(n);

   res = wordMap(s);
   return res;
}

void solve() {

   ll ans = 0;

   for (int i = 10000; i <= 11111; i++) {
      // ans += numberToWord(i).size();
      cout << numberToWord(i) << nl;
   }
   // cout << ans << nl;

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
