class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, total = need.size();
        int left = 0;
        int minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;


            if (need.count(c) && window[c] == need[c])
                have++;


            while (have == total) {

                if (right - left + 1 < minLen) {
                    minLen   = right - left + 1;
                    minStart = left;
                }

                char lc = s[left++];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc])
                    have--;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};