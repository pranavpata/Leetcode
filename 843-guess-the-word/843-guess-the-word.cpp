/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int checkString(string & word1, string & word2) {
      int counter = 0;

      for (int i = 0; i < 6; i++) {
        if (word1[i] == word2[i]) {
          counter++;
        }
      }
      return counter;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; i++) {
            string & guessWord = wordlist[rand() % wordlist.size()];
            int guessMatch = master.guess(guessWord);
            vector <string> newList;

              // Iterate though the list and call our checkString() function 
              // for word and the Guessed word

            for (string & word: wordlist) {
              if (guessMatch == checkString(word, guessWord)) {
                newList.push_back(word);
              }
            }
            wordlist = newList;
        }
    }
};