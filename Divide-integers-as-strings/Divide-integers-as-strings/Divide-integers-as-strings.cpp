//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream> 
#include <stdlib.h>  
#include <sstream>   

using namespace std;

typedef int64_t ll;
typedef long long ll;

#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt& a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt Integer(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) { ans.push_back(0); return ans; }
    while (s.size() % 9 != 0) s = '0' + s;
    for (int i = 0; i < s.size(); i += 9) {
        int v = 0;
        for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
        ans.insert(ans.begin(), v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(int x) {
    string s = "";
    while (x > 0) s = char(x % 10 + '0') + s, x /= 10;
    return Integer(s);
}

bool operator < (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i, a.size() - 1, 0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}

bool operator > (BigInt a, BigInt b) {
    return (b < a);
}

BigInt operator + (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, max(a.size(), b.size()) - 1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.push_back(carry % base);
        carry /= base;
    }
    if (carry) ans.push_back(carry);
    Set(ans);
    return ans;
}

BigInt operator - (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, a.size() - 1) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0) ans.push_back(carry + base), carry = -1;
        else ans.push_back(carry), carry = 0;
    }
    Set(ans);
    return ans;
}
BigInt operator * (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    FOR(i, 0, a.size() - 1) {
        ll carry = 0ll;
        for (int j = 0; j < b.size() || carry > 0; j++) {
            ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
            ans[i + j] = s % base;
            carry = s / base;
        }
    }
    Set(ans);
    return ans;
}

BigInt operator % (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == Integer(0)) return Integer("-1");
    BigInt ans;
    FORD(i, a.size() - 1, 0) {
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * Integer(mid) > ans) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        ans = ans - Integer(x - 1) * b;
    }
    Set(ans);
    return ans;
}

string BigIntToStr(BigInt a) {
    string res, buff;
    Set(a);
    (a.size() == 0) ? res += '0' : res += to_string(a.back());
    FORD(i, a.size() - 2, 0)
    {
        buff = to_string(a[i]);
        while (buff.size() != 9) buff = '0' + buff;
        res += buff;
    }
    return res;
}

vector<string> divide_strings(string a, string b)
{
    BigInt aa = Integer(a);
    BigInt bb = Integer(b);
    pair<BigInt, BigInt> qu_re;
    Set(aa);
    Set(bb);
    BigInt ans, cur;
    FORD(i, aa.size() - 1, 0) {
        cur.insert(cur.begin(), aa[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (bb * Integer(mid) > cur) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - Integer(x - 1) * bb;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    Set(cur);

    vector<string> res;
    res.push_back(BigIntToStr(ans));
    res.push_back(BigIntToStr(cur));
    return res;
}

int main()
{
    vector<string> res;
    res = divide_strings("0", "5"); // {"0", "0"})); 
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("4", "5"); // {"0", "4"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("10", "2"); // {"5", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("20", "3"); // {"6", "2"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("60", "5"); // {"12", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("219", "11"); // {"19", "10"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("729", "9"); // {"81", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("1000", "10"); // {"100", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("600001", "100"); // {"6000", "1"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("285534065576886561", "1500400725");
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("12578367047084780373", "4158924807"); // {"6000", "1"}));
    cout << res[0] << " " << res[1] << "\n";


    return 0;
}