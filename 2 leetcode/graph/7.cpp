class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         queue<pair<string,int>> q;
         q.push(beginWord);
         unordered_set<string> st(wordList.begin(),wordList.begin);
    }
};