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
            int guess_no=guess(mid);   // internal it will compare the our mid value to the number which it picks gives 0 when we got gives -1 when it is bigger and gives 1 when it is smaller..

            if (guess_no==0){   // number mil gya 
                return mid;
            }
            else if (guess_no==-1){   // number bahut bada hai  given 
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return {};
    }
};