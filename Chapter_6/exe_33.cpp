#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vec, unsigned index)
{
    unsigned sz = vec.size();
    if(!vec.empty() && index < sz)
    {
        cout << vec[index] << endl;
        print(vec, index+1);
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    print(vec, 0);

    return 0;
}
