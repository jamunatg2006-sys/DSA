// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // for(long long i=1;i<=n;i++){
        //     if(isBadVersion(i)){
        //     //chceking one by one is tht a  bade version 
        //     //if it is bad version return tht number
        //         return i;
        //     }
        // }
        // return -1;
        int low=1;
        int high=n;
        while(low<high){
            int mid=low+(high -low )/2;

            if(isBadVersion(mid)){
                high =mid;

            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};