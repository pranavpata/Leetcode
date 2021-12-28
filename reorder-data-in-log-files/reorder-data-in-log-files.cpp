class Solution {
public:
    static bool cmp(string s1, string s2){ // Custom Comparator Function        
      auto pos1 = s1.find(' '), pos2 = s2.find(' ');
      auto id1 = s1.substr(0, pos1), id2 = s2.substr(0, pos2);
      auto content1 = s1.substr(pos1 + 1), content2 = s2.substr(pos2 + 1);        
      return (content1 == content2) ? id1 < id2 : content1 < content2;
      
  }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;
        for (auto &log : logs) {
          if (isalpha(log[log.find(' ') + 1])) { // isapha is inbuild function in c++
            letterLogs.push_back(log);
          } else {
            digitLogs.push_back(log);
          }
        }

        // Use custom comparator function
        sort(letterLogs.begin(), letterLogs.end(), cmp); 

        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};