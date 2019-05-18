class Solution {
    public int compress(char[] chars) {
        if (chars == null || chars.length == 0) return 0;
        
        char last;
        int res = 0, index = 0;
        while (index < chars.length) {
            int count = 1;
            last = chars[index];
            while (++index < chars.length && chars[index] == last) {
                count++;
            }
            String temp = "" + last + (count > 1 ? count : "");
            for (int i = 0; i < temp.length(); i++) {
                chars[i + res] = temp.charAt(i);
            }
            res += temp.length();
        }
        
        return res;
    }
}