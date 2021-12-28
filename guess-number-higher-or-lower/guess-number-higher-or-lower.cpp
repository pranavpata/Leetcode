/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1; long high = n;
        long num = n/2;
        int g = guess(num);
        while (g != 0) {
            if (g == -1) {
                high = num-1;
            }
            else if (g == 1) {
                low = num+1;
            }
            num = (low + high)/2;
            g = guess(num);
        }
        return num;
    }
};