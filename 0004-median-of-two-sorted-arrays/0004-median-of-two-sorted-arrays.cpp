class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // constraints 0(log(m+n)) means binary

        if (nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int n=nums1.size();

        int m=nums2.size();

        int left=0;

        int right=n;

        while(left<=right){
            int Px=left+(right-left)/2;    // mid ---- >> left half wala 

            int Py=(m+n+1)/2 - Px;         // right half wala 

            // left side

            int x1= (Px==0) ? INT_MIN : nums1[Px-1];

            int x2= (Py==0) ? INT_MIN : nums2[Py-1];

            // right side 

            int x3= (Px==n) ? INT_MAX : nums1[Px];

            int x4= (Py==m) ? INT_MAX : nums2[Py];

           if (x1<=x4 && x2<=x3){
               if ((m+n)%2==1){
                   return max(x1,x2);
               }
               else {
                    return (max(x1,x2)+min(x3,x4))/2.0;
               }
           }
           else {
                if (x1>x4){
                    right=Px-1;
                }
                else {
                    left=Px+1;
                }
           }
        }
        return -1;
    }
};


/*

x1 = biggest element on the left of nums1
x2 = biggest element on the left of nums2
x3 = smallest element on the right of nums1
x4 = smallest element on the right of nums2

*/