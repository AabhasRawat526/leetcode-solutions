/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;    // to prevent the overflow we used this formula 
            int guess_no=guess(mid);

            if (guess_no==0){   // number mil gya 
                return mid;
            }
            else if (guess_no==-1){   // number bahut bada hai 
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return {};
    }
};