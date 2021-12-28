class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> curPath;
    vector<vector<string>> shortestPaths;
    
    vector<string> findNeighbors(string &word, unordered_set<string> &wordList) {
        vector<string> neighbors;
        for (int i = 0; i < word.size(); i++) {
            char old = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (c == old || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = old;
        }
        return neighbors;
    }
    
    void backtrack(string &source, string &dest) {
        if (source == dest) {
            shortestPaths.push_back(curPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            curPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], dest);
            curPath.pop_back();
        }
    }
    
    void bfs(string beginWord, string endWOrd, unordered_set<string> &wordList) {
        queue<string> q;
        q.push(beginWord);
        
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }
        
        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while (!q.empty()) {
            vector<string> visited;
            
            for (int i = q.size() - 1; i >= 0; i--) {
                string curWord = q.front();
                q.pop();
                vector<string> neighbors = findNeighbors(curWord, wordList);
                
                for (auto word : neighbors) {
                    visited.push_back(word);
                    adjList[curWord].push_back(word);
                    
                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        bfs(beginWord, endWord, copiedWordList);
        
        curPath = {beginWord};
        backtrack(beginWord, endWord);
        
        return shortestPaths;
    }
};