
/*Power Set



Difficulty: MediumAccuracy: 43.3%Submissions: 120K+Points: 4
Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s constitutes of lower case english alphabets

Company Tags
Snapdeal
*/




class Solution {
  public:


    void backtrack(int i, int n, string& s, vector<string>&result,string current){
        if(i==n){
            if(current!= ""){
                result.push_back(current);
            }
            return;
        }

        backtrack(i+1,n,s,result,current+s[i]);

        backtrack(i+1,n,s,result,current);
    }


    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        vector<string>result;

        backtrack(0,n,s,result,"");
        
        sort(result.begin(),result.end());
        return result;
        
    }
};