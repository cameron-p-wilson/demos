## find_missing
### Question:
You are given two arrays of integers, A and B. Array B contains all the elements in array A, except for exactly one element that is missing.
There are no duplicates in either array. Write a function that returns the missing integer.

### Answers:
Three of the solutions can handle duplicates in the array. These are: find_missing_with_repeats, find_missing_sum, and find_missing_xor.
The other two, find_missing_bst and find_missing, work only with arrays of unique numbers.
With the exception of find_missing_bst, whose time complexity is O(nlog(n)), these programs operate in O(n) time.
From slowest to fastest: find_missing_bst, find_missing, find_missing_sum, find_missing_xor

#### find_missing_bst
This approach uses a std::map to build a map of the elements in array B. Once the map is built, the program iterates through
the elements in A, checking to see if they exist in the map. If the element is a key in the map, then that element is the missing number.
This solution is by far the slowest, as its time complexity is O(nlog(n)), compared to O(n). 
This does not work if duplicates exist.

#### find_missing
This approach is nearly identical to find_missing_bst, except that, instead of a std::map, a std::unordered_map is used.
While std::map has O(log(n)) lookup and insertion times (since it is implemented as a binary tree), unordered_map is actually
a hash table with O(1) lookup and insertion times in most cases. Because of this, find_missing runs much faster, spending about 1/4 the time
according to my tests. 
This does not work with duplicates.

#### find_missing_sum
This approach simply finds the sum of the two arrays, then returns their difference.
This approach only works so long as a sum can be computed and thus would not work with strings.
Some measures are taken to attempt to avoid integer overflow.
Adding is significantly faster than hash table operations. This solution is about 10x faster than find_missing, according to my tests.

#### find_missing_xor
This approach is somewhat similar to find_missing_sum, but uses the XOR operation to compute the difference. 
Because of the properties of XOR, XOR'ing the same number by each element in both arrays will result in the element missing from B.
My tests indicated that this approach is about 10x faster than find_missing_sum.
Disclaimer: I did not come up with this solution.

#### find_missing_with_repeats
This solution can account for duplicates in the arrays and can work for any hashable type. It works similarly to find_missing, but the values in the 
hash table store the number of occurrences of their respective keys. If 25 appears in array B 7 times, then the value where key = 25 is 7.
As the second loop iterates through array A, the values in the hash table are decremented to reflect the finding of duplicates. 
If a key in the hash table has a value of 0 and the key is found again in array A, then that key is the missing number in B, and it had duplicates. 
If a number in array A is not a key in the hash table, then that number is the missing number, and it is unique in A.
