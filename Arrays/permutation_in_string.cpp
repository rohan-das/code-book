// https://leetcode.com/problems/permutation-in-string/

// Can further be optimized
// Current TC - O(m * 26), Possible TC - O(m)

class Solution {
public:

	bool checkAnagram(int freq1[], int freq2[]) {
		for (int i = 0; i < 26; i++) {
			if (freq1[i] != freq2[i])
				return false;
		}
		return true;
	}

	bool checkInclusion(string s1, string s2) {

		int n = s1.length(), m = s2.length();
		if (n > m) return false;

		int freq1[26], freq2[26];

		for (int i = 0; i < 26; i++)
			freq1[i] = freq2[i] = 0;

		for (int i = 0; i < n; i++)
			freq1[s1[i] - 'a']++;

		for (int i = 0; i < n; i++)
			freq2[s2[i] - 'a']++;

		for (int i = 0; i < m - n; i++) {
			if (checkAnagram(freq1, freq2))
				return true;

			freq2[s2[i] - 'a']--;
			freq2[s2[i + n] - 'a']++;
		}

		if (checkAnagram(freq1, freq2))
			return true;

		return false;
	}
};