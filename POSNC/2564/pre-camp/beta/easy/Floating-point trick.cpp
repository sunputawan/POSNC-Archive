#include <iostream>
#include <iomanip>
using namespace std;
int q, num;
long double k;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        k = 1.0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            k = k * 2.0;
        }
        cout << fixed;
        cout << setprecision(0) << k << endl;
    }
    return 0;
}
