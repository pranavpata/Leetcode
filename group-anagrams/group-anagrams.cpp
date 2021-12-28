/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

- I: vector<string> (infinitely large), possible to get empty inputs
- O: vector<vector<string>>

Approach 1: sort each string based on the characters
    words that are anagrams should have the same sorted order
    group words with the same sorted order and return the groups
    - m is the maximum length of each string, n is the number of strings
    I would use a hash table to store the groups, the key is the sorted word, the value is a list of the original words
    
    unordered_map<string, vector<string>>
    ["bat", "cat", "tab"]
    ["abt", "act", "abt"]
    
    table["abt"] = ["bat", "tab"]
    table["act"] = ["cat"]
    
    Time: O(n*mlogm) + O(n) = O(n*mlogm)
    Space: O(n*m)
    
Approach 2: each anagram will have the same character counts
    keep track of character counts in a vector of size 26 (one for each letter of the alphabet), words with the same character counts are anagrams
    loop through each string and find the character counts, and store this information
    use character count information as my key in my hash table that stores the result
    ["bat", "cat", "tab"]
    ["1a1b1t", "1a1c1t", "1a1b1t"]
    
    table["1a1b1t"] = ["bat", "tab"]
    table["1a1c1t"] = ["cat"]
    
    - m is the maximum length of each string, n is the number of strings
    
    Time: O(n*m)
    Space: O(n*m)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            vector<int> chars(26, 0); //character counts;
            for (int i = 0; i < str.size(); i++) {
                char c = str[i];
                chars[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                if (chars[i] > 0) {
                    key += to_string(chars[i]) + to_string(i + 'a');
                }
            }
            anagrams[key].push_back(str);
        }
        for (auto element : anagrams) {
            result.push_back(element.second);
        }
        return result;
    }
};













