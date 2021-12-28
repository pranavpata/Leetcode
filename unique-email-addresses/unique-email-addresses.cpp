class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int toReturn = 0;
        map<string, bool> m;
        string local, domain, str;
        for (int i = 0; i < emails.size(); i++) {
            local = emails[i].substr(0, emails[i].find("@"));
            local = local.substr(0, local.find("+"));
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            domain = emails[i].substr(emails[i].find("@"));
            str = local + domain;
            if (!m[str]) {
                toReturn++;
                m[str] = true;
            }
        }
        
        return toReturn;
    }
};