class Solution {
    public int hammingDistance(int x, int y) {
        int t = x^y,c = 0;
        while (t > 0){
            c += 1&t;
            t = t>>1;
        }
        return c;
    }
}