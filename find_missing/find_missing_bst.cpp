#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <random>
using namespace std;

//slowest method
//significantly slower than using unordered_map because
//map is implemented as a red-black tree, which has O(log(n))
//insertion and lookup time, opposed to O(n) for hash tables.
//~50s with n = 10 million
int findMissing(vector<int> &A, vector<int> &B)
{
    map<int, int> hash;
    for (int i = 0; i < B.size(); i++)
    {
        hash[B[i]] = i;
        
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (hash.find(A[i]) == hash.end())
        {
            return A[i];
        }
    }
    return -999;
}

int main()
{
    //vector<int> A{4, 12, 9, 5, 6, 6};
    //vector<int> B{4, 9, 12, 6, 6};
    srand(time(0)); //seed rng
    int vSize = 9999999;
    vector<int> A(vSize);
    vector<int> B(vSize);

    for (int i = 0; i < vSize; i++)
    {
        A[i] = i + 1;
        B[i] = i + 1;
    }

	//shuffle
    for (int i = vSize - 1; i > 0; i--)
    {
        int index = rand() % i;
        int temp = A[i];
        A[i] = A[index];
        A[index] = temp;

        index = rand() % i;
        temp = B[i];
        B[i] = B[index];
        B[index] = temp;
    }
	//-55 is guaranteed to be unique, since both arrays are all positive
    A.push_back(-55);

    clock_t start = clock();
    cout << findMissing(A, B) << "\n";
    clock_t finish = clock();
    cout << double(finish - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
