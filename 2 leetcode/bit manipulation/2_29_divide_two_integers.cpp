/*29. Divide Two Integers
Solved
Medium
Topics
premium lock icon
Companies
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == divisor) {
            return 1;
        }

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0)) {
            sign = false;
        }

        long n = std::abs((long)dividend);
        long d = std::abs((long)divisor);

        long ans = 0;
        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1L << count;
            n -= d << count;
        }

        return sign ? ans : -ans;
    }
};
















//niche sare answer run nhi ho rha hai bas aise he dekhne ke liye rakh liye hai hum 








































































class Solution {
public:
    int divide(int dividend, int divisor) {


        if(dividend == divisor){
            return 1;
        }

        bool sign =true;

        if(dividend>=0 && divisor<0){
            return false;
        }
        if (dividend <0 && divisor>0){
            return false;
        }
        long n = abs(dividend);
        long d = abs(divisor);

        int ans;
        while(n>=d){

            count =0;

            while(n>=(d<<count+1)){
                count++;
            }
            ans+=(1<<count);
        }
        if(ans == (1<<31) && sign){
            return INT_MAX;
        }
        if (ans== (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? ans : -ans;
    }
};























class Solution {
public:
    int divide(int dividend, int divisor) {
        int sum = 0;
        int count=0;

        while(sum+divisor<=dividend){
            count = count+1;
            sum+=divisor;
        }
        return count;
    }
};



class Solution {
public:
    int divide(int dividend, int divisor) {
       

        if(dividend == divisor){
            return 1;
        }

        bool sign =true;

        if(dividend>=0 && divisor<0)sign=false;
            
        
        else if(dividend <=0 && divisor>0)sign=false;
            
        
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        divisor=abs(divisor);

        long ans=0;
        while(n>=d){

           int count =0;

            while(n>=(d<<(count+1))){
                count+=1;
            }
            ans+= 1<<count;
            n-= (d<<count);
        }
        if(ans == (1<<31) && sign){
            return INT_MAX;
        }
        if (ans== (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? ans : -ans;
 
    }
};