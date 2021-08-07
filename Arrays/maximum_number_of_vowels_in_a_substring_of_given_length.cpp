// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:

	bool isVowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
	}

	int maxVowels(string s, int k) {

		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (isVowel(s[i]))
				cnt++;
		}

		int maxCnt = cnt;
		for (int i = k; i < s.length(); i++) {
			if (isVowel(s[i - k]))
				cnt--;

			if (isVowel(s[i]))
				cnt++;

			maxCnt = max(maxCnt, cnt);
		}

		return maxCnt;
	}
};