class Solution {
public:
    int numberOfSubstrings(string a) {
        int freq[3] = {0}; // Frequency array for 'a', 'b', and 'c'
        int r = 0, l = 0, n = a.length(), total = 0 ;

        while (r < n) {
            freq[a[r] - 'a']++; // Increment frequency of current character
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) { 
                total += (n - r); // Every valid substring contributes
                freq[a[l] - 'a']--; // Shrink the window from the left
                l++;
            }
            r++;
        }
        return total;
    }
};
