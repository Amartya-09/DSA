class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        int pFreq[26] = {}, wFreq[26] = {};
        int pLen = p.size(), matches = 0;
        vector<int> result;


        for (int i = 0; i < pLen; i++) {
            pFreq[p[i] - 'a']++;
            wFreq[s[i] - 'a']++;
        }


        for (int i = 0; i < 26; i++)
            if (pFreq[i] == wFreq[i]) matches++;

        if (matches == 26) result.push_back(0);

 
        for (int r = pLen; r < s.size(); r++) {
            int l = r - pLen; 

            int in = s[r] - 'a';
            if (wFreq[in] == pFreq[in])     matches--; 
            wFreq[in]++;
            if (wFreq[in] == pFreq[in])     matches++;  

            int out = s[l] - 'a';
            if (wFreq[out] == pFreq[out])   matches--;
            wFreq[out]--;
            if (wFreq[out] == pFreq[out])   matches++;

            if (matches == 26) result.push_back(l + 1);
        }

        return result;
    }
};