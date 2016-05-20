class Solution {
public:
    int divide(int dividend, int divisor) {
         long long num1 = abs((long long) dividend), num2 = abs((long long) divisor);
         long long l = 1, r = num1;
         
         if ((dividend == 0) || (divisor == 0) || num1 < num2) {
             return 0;
         }
         
         while (l <= r) {
             long long mid = (l + r) >> 1;
             
             long long tmp1 = mid, tmp2 = num2;
             long long tmpSum = 0;
             while (tmp2 > 0) {
                 if (tmp2 & 1) {
                     tmpSum += tmp1;
                 }
                 tmp1 += tmp1;
                 tmp2 >>= 1;
             }
             
             if (tmpSum == num1) {
                 break;
             }
             if (tmpSum > num1) {
                 r = mid - 1;
             } else {
                 l = mid + 1;
             }
         }
         
         long long res = (l + r) >> 1;
         if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
             res = 0 - res;
         }
         
         return res > INT32_MAX ? INT32_MAX : res;
    }
};