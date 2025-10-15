#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())

struct line
{
    string left;
    string right;
    char op;
    string answer;
};

double applyOperator(double left, double right, char op)
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '/':
        return left / right;
    case '*':
        return left * right;
    default:
        assert(0);
        return -INFINITY;
    }
}

bool check_base(line expression, double base)
{
    map<char, double> charToNum = { };
    if (base == 1)
    {
        charToNum['1'] = 1;
    }
    else
    {
        for (int i = 0; i < base; i++)
        {
            if (i < 10)
            {
                charToNum[char(i + 48)] = i;
            }
            else
            {
                charToNum[char(i + 55)] = i;
            }

        }
    }


    double leftval = 0;
    double rightval = 0;
    double answer = 0;

    for (size_t i = 0; i < expression.left.size(); i++)
    {
        if (!charToNum.count(expression.left[i]))
        {
            return false;
        }
        leftval += pow(base, double(expression.left.size() - 1 - i)) * charToNum[expression.left[i]];
    }

    for (size_t i = 0; i < expression.right.size(); i++)
    {
        if (!charToNum.count(expression.right[i]))
        {
            return false;
        }
        rightval += pow(base, double(expression.right.size() - 1 - i)) * charToNum[expression.right[i]];
    }

    for (size_t i = 0; i < expression.answer.size(); i++)
    {
        if (!charToNum.count(expression.answer[i]))
        {
            return false;
        }
        answer += pow(base, double(expression.answer.size() - 1 - i)) * charToNum[expression.answer[i]];
    }

    if (applyOperator(leftval, rightval, expression.op) == answer)
    {
        return true;
    }

    return false;
}

int main()
{
    std::vector<string> operators = { "+","-","/","*" };

    vector<line> expressions;

    line l;
    cin >> l.left >> l.right >> l.answer;

    l.op = '+';

    expressions.push_back(l);

    map<int, char> numtochar = {};
    for (int i = 0; i < 26; i++)
    {
        numtochar[i + 10] = i + 97;
    }
    numtochar[36] = '0';
    for (size_t i = 1; i < 10; i++)
    {
        numtochar[i] = i + 48;
    }

    rep(i, expressions.size())
    {
        vector<int> bases;
        for (int base = 2; base <= 16; base++)
        {
            if (check_base(expressions[i], base))
            {
                bases.push_back(base);
            }
        }


        rep(i, bases.size())
        {
            cout << bases[i] << " ";
        }
    }

    return 0;
}
