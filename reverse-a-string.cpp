#include <string>
#include <iostream>

/* Finds the reverse of a string in O(n) time and O(1) space */

void reverseString(std::string &str)
{
	//directly modifies the string argument
	int i = 0; int j = str.size() - 1;
	while (i < j)
	{
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
}

int main()
{
	std::string input;
	std::cout << "\nType the string you want to reverse: ";
	cin >> input;
	std::cout << "\nReversed: " << reverseString(input) << "\n";
	return 0;
}
