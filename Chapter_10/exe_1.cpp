#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 9, 3, 3, 4};
    int val = 3;

    int cnt = count(ivec.begin(), ivec.end(), val);

    cout << "The value " << val
         << " occurs " << cnt << ((cnt > 1) ? " times." : " time.") << endl;

    return 0;
}
