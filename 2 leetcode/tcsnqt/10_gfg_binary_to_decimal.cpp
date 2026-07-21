Binary to Decimal


Solved
Difficulty: BasicAccuracy: 51.5%Submissions: 107K+Points: 1
Given a string b representing a binary number, return its decimal equivalent as an integer.

Examples:

Input : b = 111
Output : 7
Explanation : The decimal equivalent of the binary number 111 is 22 + 21 + 20 = 7.
Input : b = 1010
Output : 10
Explanation : The decimal equivalent of the binary number 1010 is 23 + 21 = 10.
Input: b = 100001
Output: 33
Explanation : The decimal equivalent of the binary number 100001 is 25 + 20 = 33.
Constraints:
1 <= number of bits in binary number  <= 16



class Solution {
  public:
    int binaryToDecimal(string& b) {
       
        int n = b.length();
        int sum =0;
        int k = 0;
        for(int i = n-1; i>=0; i--){
            sum += ((b[i]-'0') * pow(2,k));
            k++;
        }
        return sum;
    }
};