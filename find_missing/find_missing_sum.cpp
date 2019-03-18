#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

//second fastest method
//~1.0s for n = 10 million
int findMissing(vector<int> &A, vector<int> &B)
{
    long int sumA = 0;
	long int sumB = 0;
	int aMods = 0;
	int bMods = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sumA += A[i];
		aMods += sumA / A.size();
        sumA %= A.size();
    }
    for (int i = 0; i < B.size(); i++)
    {
        sumB += B[i];
		bMods += sumB / A.size();
        sumB %= A.size();
    }
    return (int)(sumA-sumB + ( (aMods-bMods) * A.size() ));

}

int main()
{
    //vector<int> A{4, 12, 9, 5, -33, 6, 6, -18};
    //vector<int> B{4, 9, 12, -18, 6, 6, 5};
    srand(time(0)); //seed rng
    int vSize = 9999999;
    vector<int> A(vSize);
    vector<int> B(vSize);

    for (int i = 0; i < vSize; i++)
    {
        A[i] = (rand() % 9999999999999) - 4444444444444;
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
	//this could be any number, since duplicates and negatives are handled
    A.push_back(-55);

    clock_t start = clock();
    cout << findMissing(A, B) << "\n";
    clock_t finish = clock();
    cout << double(finish - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
