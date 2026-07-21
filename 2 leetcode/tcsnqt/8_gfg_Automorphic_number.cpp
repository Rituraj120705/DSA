Automorphic Number



Solved
Difficulty: BasicAccuracy: 50.0%Submissions: 23K+Points: 1
Given a number n, check whether the number is an Automorphic number or not. A number is called an Automorphic number if and only if the square of the number ends with the number itself.

Example 1:

Input: n = 76
Output: Automorphic
Explanation: 762 = 5776
The square ends with 76, which is the original number. Hence, it is an Automorphic number.
Example 2:

Input: N = 14
Output: Not Automorphic
Explanation: 142 = 196
The square does not end with 14. Hence, it is not an Automorphic number.
Your Task:

You don't need to read or print anything. Your task is to complete the function isAutomorphic() which takes n as input parameter and returns "Automorphic" if it is Automorphic number otherwise returns "Not Automorphic"(Without quotes).
 


class Solution {
  public:
    string isAutomorphic(int n) {
        // code here
        int square = n * n;
        
        int temp = n;
        
        while(temp > 0){
            if(temp % 10 != square % 10){
                return "Not Automorphic";
            }
            temp/=10;
            square/=10;
        }
        return "Automorphic";
    }
};