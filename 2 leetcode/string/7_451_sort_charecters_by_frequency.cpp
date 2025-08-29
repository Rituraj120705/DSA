451. Sort Characters By Frequency
Solved
Medium
Topics
premium lock icon
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.


class Solution {
public:
    
   static bool compare(pair<char,int>p1,pair<char,int>p2){
        return p1.second > p2.second;
    }



    string frequencySort(string s) {
        

        unordered_map<char,int>freq;

        for(int i=0;i<s.size(); i++){
            if(freq.count(s[i])){
                freq[s[i]]++;
            }
            else{
                freq[s[i]] = 1;
            }
        }

        vector<pair<char,int>>m(freq.begin() , freq.end());

        sort(m.begin() , m.end() , compare);

        string result;
        for(auto & p : m){
            result.append(p.second,p.first);
        }

        return result;

    }
};