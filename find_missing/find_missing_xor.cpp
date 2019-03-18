#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

//the fastest method
//~0.15s for n = 10 million
int findMissing(vector<int> &A, vector<int> &B)
{
    int sumXor = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sumXor ^= A[i];
    }
    for (int i = 0; i < B.size(); i++)
    {
        sumXor ^= B[i];
    }
    return sumXor;
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
        A[i] = (rand() % vSize) - (vSize / 2);
        B[i] = A[i];
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
    A.push_back(-55);

    clock_t start = clock();
    cout << findMissing(A, B) << "\n";
    clock_t finish = clock();
    cout << double(finish - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
