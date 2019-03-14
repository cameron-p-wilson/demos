#include <string>
#include <iostream>

void reverseString(std::string &str)
{
	//directly modifies the string argument
	int i = 0; int j = str.size() - 1;
	while (i < j)
	{
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
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
