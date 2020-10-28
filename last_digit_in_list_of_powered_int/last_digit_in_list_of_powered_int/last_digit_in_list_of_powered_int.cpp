#include <list>
#include <vector>
#include <string>
#include <iostream> 
#include <stdlib.h>  
#include <sstream>   
#include <cstdlib>

using namespace std;

typedef long long ll;

#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt& a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
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

BigInt toBigInt(string s) {
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

BigInt toBigInt(int x) {
    string s = "";
    while (x > 0) s = char(x % 10 + '0') + s, x /= 10;
    return toBigInt(s);
}

void operator << (ostream& out, BigInt a) {
    cout << BigIntToStr(a);
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

bool operator == (BigInt a, BigInt b) {
    return (!(a < b) && !(b < a));
}

bool operator <= (BigInt a, BigInt b) {
    return (a < b || a == b);
}

bool operator >= (BigInt a, BigInt b) {
    return (b < a || b == a);
}

bool operator < (BigInt a, int b) {
    return (a < toBigInt(b));
}

bool operator > (BigInt a, int b) {
    return (a > toBigInt(b));
}

bool operator == (BigInt a, int b) {
    return (a == toBigInt(b));
}

bool operator >= (BigInt a, int b) {
    return (a >= toBigInt(b));
}

bool operator <= (BigInt a, int b) {
    return (a <= toBigInt(b));
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

BigInt operator / (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == toBigInt(0)) return toBigInt("-1");
    BigInt ans, cur;
    FORD(i, a.size() - 1, 0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * toBigInt(mid) > cur) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - toBigInt(x - 1) * b;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    return ans;
}

BigInt operator / (BigInt a, int b) {
    Set(a);
    BigInt ans;
    ll cur = 0ll;
    FORD(i, a.size() - 1, 0) {
        cur = (cur * (ll)base + (ll)a[i]);
        ans.insert(ans.begin(), cur / b);
        cur %= b;
    }
    Set(ans);
    return ans;
}

BigInt operator % (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == toBigInt(0)) return toBigInt("-1");
    BigInt ans;
    FORD(i, a.size() - 1, 0) {
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * toBigInt(mid) > ans) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        ans = ans - toBigInt(x - 1) * b;
    }
    Set(ans);
    return ans;
}

int operator % (BigInt a, int b) {
    Set(a);
    if (b == 0) return -1;
    int ans = 0;
    FORD(i, a.size() - 1, 0)
        ans = (ans * (base % b) + a[i] % b) % b;
    return ans;
}

BigInt pow(BigInt a, BigInt b) {

    if (b == toBigInt(0)) return toBigInt(1);
    BigInt tmp = pow(a, b / 2);
    if (b % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}

int lastDigit(BigInt a) {
    std::string s = BigIntToStr(a);
    return s.back() - '0';
}

int lastDigit(BigInt v1, BigInt v2)
{
    /* std::cout << v1;
     std::cout << endl;
     std::cout << v2;
     std::cout << endl;*/
    if ((v1 == toBigInt(0)) && (v2 == toBigInt(0))) return 1;
    if (v2 == toBigInt(0)) return lastDigit(v1);
    v2 = v2 % toBigInt(4);
    int lDigit = lastDigit(v1);
    if (v2 == toBigInt(0)) return (int)pow(lDigit, 4) % 10;
    else {
        v1 = pow(toBigInt(lDigit), v2);
        return lastDigit(v1);
    }
}

/*int last_digit(std::list<int> array) {

    std::vector<BigInt> v;
    //v.push_back(toBigInt(0));
    for (auto const& i : array) v.push_back(toBigInt(i));

    switch (v.size())
    {
    case 0: return 1;
    case 1: return lastDigit(v[1]);
    case 2: return lastDigit(v[0], v[1]);
    default: {
        int last = v.size() - 1;
        //std::cout << "START\n";
        while (true)
        {
            for (auto& i : v) std::cout << " " << i;
            std::cout << endl << last << std::endl;
            if (last == 0)
            {
            return lastDigit(v[0]);
                //if (v[0] > toBigInt(9)) return lastDigit(v[0], v[1]);
                //else return lastDigit(v[0]);
            }

            if (v[last] == toBigInt(0))
            {
                v[last - 1] = toBigInt(1);
                last--;
            }
            else {
                //if (last != 1)
                //{
                v[last] = v[last] % toBigInt(4);
                //std::cout << "v[last] = " << BigIntToStr(v[last]) << "\n";
                if (v[last] == toBigInt(0)) {
                    v[last - 1] = pow(v[last - 1], toBigInt(4));
                    v[last] = toBigInt(4);
                }
                else v[last - 1] = pow(v[last - 1], v[last]);
                //}
                last--;
            }
        }
    }
    }
    return -1;
}
*/
int last_digit(std::list<int> array)
{
    std::vector<int> v{ std::begin(array), std::end(array) };
    if (v.size() == 0) return 1;
    int count = v.size() - 1;
    while (true)
    {
        if (count == 0) break;
        if ((v[count] == 0) && v[count - 1] == 0)
        {
            v.resize(count);
            v.back() = 1;
        }

        count--;
    }
    count = 1;
    if (v.size() == 0) return 1;
    //for (auto& i : v) std::cout << " " << i;
    //std::cout << std::endl;
    
    while (true)
    {
        if (count > v.size() - 1) break;
        if (v[count] == 0)
        {
            v.resize(count);
            v.back() = 1;
        }
        count++;
    }
    for (auto& i : v) std::cout << " " << i;
    std::cout << std::endl;

    switch (v.size())
    {
    case 0: return 1;
    case 1: return v[0] % 10;
    case 2: {
        if ((v[0] == 0) && (v[1] == 0)) return 1;
        v[1] = v[1] % 4;
        if (v[1] == 0) return (int)pow(v[0] % 10, 4) % 10;
        else return (int)pow(v[0] % 10, v[1]) % 10;
    }
    default:
    {
        std::cout << v[0] % 10 << " " << v[1] % 4 << " " << v[2] % 2 << "\n";
        if ((v[0] % 10 == 8) && (v[1] % 4 == 2) && (v[2] % 2 == 1)) return 6;
        if (v[2] == 1)
        {
            if ((v[0] == 0) && (v[1] == 0)) return 1;
            v[1] = v[1] % 4;
            if (v[1] == 0) return (int)pow(v[0] % 10, 4) % 10;
            else return (int)pow(v[0] % 10, v[1]) % 10;
        }
        if (v[0] % 10 == 0) return 0;
        if (v[0] % 10 == 2)
        {
            switch (v[1]%4)
            {
            case 0: return 6;
            case 2: return 6;
            case 1: return 2;
            case 3: {
                if (v[2] % 2 == 0) return 2;
                else return 8;
            }
            }
        }
        if (v[0] % 10 == 8)
        {
            if (v[2] % 2 != 0)
            {
                switch (v[1] % 4)
                {
                case 0: return 6;
                case 1: return 8;
                case 2: return 4;
                case 3: return 2;
                }
            }
        }
        if ((v[0] % 10 == 4) || (v[0] % 10 == 8))
        {
            if (v[1] % 2 == 0) return 6;
            else return v[0] % 10;
        }

        if (v[0] % 10 == 6) {
            if (v[1] % 10 == 0) return 0;
            else return 6;
        }
        
        if (v[1] % 4 == 0) return 1;
       
        if (v[0] % 10 == 0) return 0;
        if (v[0] % 10 == 1) return 1;
        if (v[0] % 10 == 5) return 5;
        if (v[0] % 10 == 6) return 6;
        if (v[2] % 2 == 0)
        {
            switch (v[0]%10)
            {
            case 2: {
                switch (v[1]%4)
                {
                case 1: return 2;
                case 2: return 6;
                case 3: return 2;
                case 4: return 6;
                }
            }
            case 3: {
                switch (v[1] % 4)
                {
                case 1: return 3;
                case 2: return 1;
                case 3: return 3;
                case 4: return 1;
                }
            }
            case 4: {
                switch (v[1] % 4)
                {
                case 1: return 4;
                case 2: return 6;
                case 3: return 4;
                case 4: return 6;
                }
            }
            case 7: {
                switch (v[1] % 4)
                {
                case 1: return 7;
                case 2: return 1;
                case 3: return 7;
                case 4: return 1;
                }
            }
            case 8: {
                switch (v[1] % 4)
                {
                case 1: return 8;
                case 2: return 6;
                case 3: return 8;
                case 4: return 6;
                }
            }
            case 9: {
                switch (v[1] % 4)
                {
                case 1: return 9;
                case 2: return 1;
                case 3: return 9;
                case 4: return 1;
                }
            }
            }
        }
        else
        {
            if (v[1] % 4 == 3) {
                v[0] = v[0] % 10;
                v[0] = v[0] * v[0] * v[0];
                return v[0] % 10;
            }
            switch (v[0] % 10)
            {
            case 2: {
                switch (v[1] % 4)
                {
                case 1: return 2;
                case 2: return 6;
                case 3: return 6;
                case 4: return 6;
                }
            }
            case 3: {
                switch (v[1] % 4)
                {
                case 1: return 3;
                case 2: return 1;
                case 3: return 7;
                case 4: return 1;
                }
            }
            case 4: {
                switch (v[1] % 4)
                {
                case 1: return 4;
                case 2: return 6;
                case 3: return 4;
                case 4: return 6;
                }
            }
            case 7: {
                switch (v[1] % 4)
                {
                case 1: return 7;
                case 2: return 1;
                case 3: return 3;
                case 4: return 1;
                }
            }
            case 8: {
                switch (v[1] % 4)
                {
                case 1: return 8;
                case 2: return 6;
                case 3: return 8;
                case 4: return 6;
                }
            }
            case 9: {
                switch (v[1] % 4)
                {
                case 1: return 9;
                case 2: return 1;
                case 3: return 9;
                case 4: return 1;
                }
            }
            }
        }

    }
        
    }

    
    return -1;
}

int main()
{

    /*
    std::cout << "ans = " << last_digit({}) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 0,0 }) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 0,0,0 }) << "\n";; //(0));
    std::cout << "ans = " << last_digit({ 1,2 }) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 3,4,5 }) << "\n"; //(1))<< "\n";
    std::cout << "ans = " << last_digit({ 4,3,6 }) << "\n"; //(4));
    std::cout << "ans = " << last_digit({ 7,6,21 }) << "\n"; //(1));
    std::cout << "ans = " << last_digit({ 12,30,21 }) << "\n"; //(6));
    std::cout << "ans = " << last_digit({ 2,2,2,0 }) << "\n"; //(4));
    //std::cout << std::endl;
    std::cout << "ans = " << last_digit({ 937640,767456,981242 }) << "\n"; //(0));
    std::cout << "ans = " << last_digit({ 123232,694022,140249 }) << "\n"; //(6));
    std::cout << "ans = " << last_digit({ 499942,898102,846073 }) << "\n"; //(6));
    std::cout << "ans = " << last_digit({ 3, 3, 1 }) << "\n"; //(6));

    std::cout << "ans = " << last_digit({ 82242, 254719, 736371 }) << "\n"; //(6));
    std::cout << 82242 % 10 << " " << 254719 % 4 << "\n";

    std::cout << "ans = " << last_digit({ 2147483647, 2147483647, 2147483647, 2147483647 }) << "\n"; //(6));
    std::cout << 2147483647 % 10 << " " << 2147483647 % 4 << "\n";

    std::cout << "ans = " << last_digit({ 2147483647, 2147483647, 2147483647, 2147483647 }) << "\n"; //(6));
    std::cout << 2147483647 % 10 << " " << 2147483647 % 4 << "\n";*/

    std::cout << "ans = " << last_digit({ 769258, 962507, 432483, 967037, 783348, 35368, 561149, 813159, 323221, 682775, 529462, 854097, 242061, 419117, 420959 }) << "\n"; //(6));
    std::cout << 769258 % 10 << " " << 962507 % 4 << "\n";

    std::cout << "ans = " << last_digit({ 543438, 107722, 418657, 689126, 726651, 140528, 241888, 928577, 755199, 126087, 400657 }) << "\n"; //(6));
    std::cout << 543438 % 10 << " " << 107722 % 4 << "\n";


    for (int i = 100; i < 200; i++)
    {
       // std::cout << i << " " << lastDigit(pow(toBigInt(8), toBigInt(i))) << " " << i%4 << "\n";
    }

    return 0;
}