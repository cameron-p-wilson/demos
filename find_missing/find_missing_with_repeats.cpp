#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <random>
using namespace std;

//takes ~20s with n = 10 million
int findMissing(vector<int> &A, vector<int> &B)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < B.size(); i++)
    {
        //hash[B[i]] = i;
        if (hash.find(B[i]) == hash.end())
        {
            hash[B[i]] = 1;
        }
        else
        {
            hash[B[i]] = hash[B[i]] + 1;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (hash.find(A[i]) == hash.end())
        {
			//number does not exist in B
            return A[i];
        }
		else if (hash[A[i]] > 0)
		{
			//number exists in B, but is a duplicate
			hash[A[i]]--;
		}
		else
		{
			//number exists in B, but duplicates have been exhausted
			return A[i];
		}
    }
    return -999;
}

int main()
{
    //vector<int> A{4, 12, 9, 5, 5, 6, 6};
    //vector<int> B{4, 9, 5, 12, 6, 6};
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
	//this could be any number, since repeats and negatives are handled
    A.push_back(-55);

    clock_t start = clock();
    cout << findMissing(A, B) << "\n";
    clock_t finish = clock();
    cout << double(finish - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
