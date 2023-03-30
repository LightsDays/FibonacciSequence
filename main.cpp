#include <iostream>
#include <string>
using namespace std;

// Its addition strings ("55"+"55" = "110")
string operator*(string &b, string &a)
{
    int as = a.size(), bs = b.size();
    int help;
    int k;
    char c[2];
    string s;
    bool check;

    for (int i = 0; i < as; i++)
    {
        // sum last numbers
        check = false;
        k = 2;
        c[0] = a[as - i - 1];
        help = atoi(c);
        c[0] = b[bs - i - 1];
        help = help + atoi(c);

        if (help < 10)
        {
            s = to_string(help);
            b[bs - i - 1] = s[0];
        }

        // if sum last numbers > 10 then we add 1 next number
        while (help >= 10)
        {
            s = to_string(help % 10);
            b[bs - i - k + 1] = s[0];

            if (bs - i - k >= 0)
            {
                c[0] = b[bs - i - k];
                help = atoi(c);
                help++;
            }
            else
            {
                check = true;
                bs++;
                b.insert(0, 1, '1');
                break;
            }
            k++;
        }
        if ((check == false) && (bs - i - k + 1 >= 0))
        {
            s = to_string(help);
            b[bs - i - k + 1] = s[0];
        }

    }
    return b;
}

string sub(string &b, string &a)
{
    string temp;
    temp = a;
    a = b;
    b = b * temp;

    return b;
}


int main()
{
    int N;
    int count;
    string str;
    string a, b;

    cin >> N;
    getchar();

    for (int i = 0; i < N; i++)
    {
        getline(cin, str);

        // 0 Situation
        if (str == "0")
        {
            cout << "0 ";
            continue;
        }

        // 1 situation
        if (str == "1")
        {
            cout << "1 ";
            continue;
        }

        a = "0";
        b = "1";
        count = 0;
        while (str != sub(b, a))
        {
            count++;
        }

        cout << count + 2 << ' ';
    }
    return 0;
}
