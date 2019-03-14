#include <string>

/* Returns the length of the longest substring within s, where all of the 
 * characters in the substring are unique.
 *
 * Runs in O(n) time and uses O(m) space, where m is the number of characters
 * in the character set (128 for ASCII, several hundred thousand for a Chinese set).
*/

int lengthOfLongestSusbtring(std::string &s)
{
	//an array to store information about each of the 128 ASCII characters
	//this array stores the last index of s where the character was found
	//initialized to -1 for each character
	//indexed by ASCII value
	int lastFound[128];

	for (int i = 0; i < 128; i++)
	{
		lastFound[i] = -1;
	}

	int maxLength = 0;
	int currentLength = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int index = s[i];

		if (i - lastFound[index] <= currentLength)
		{
			//if this character had been seen more recently than
			//the start of the current unique substring, then
			//reset the length of the substring accordingly
			currentLength = i - lastFound[index];
		}
		else
		{
			//if the character has not been seen recently, increment counter
			currentLength++;
		}

		if (currentLength > maxLength)
		{
			maxLength = currentLength;
		}

		//update to reflect that the character has been seen at this index
		lastFound[index] = i;
	}

	return maxLength;
}
