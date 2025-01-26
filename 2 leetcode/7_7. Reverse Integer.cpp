/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1*/

class Solution {
public:
    int reverse(int x) {
         int last_digit;
         int rev_num=0;
        
       while(x!=0){
        if((rev_num > INT_MAX / 10 )|| (rev_num< INT_MIN /10)) {
         return 0;
          }
        last_digit= x % 10;
       rev_num = (rev_num*10)+last_digit;
       x=x/10;
       }
       return rev_num;
    }
};