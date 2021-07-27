// https://leetcode.com/problems/max-chunks-to-make-sorted/

// Idea is to compare index with Prefix Max value. If match then increment chunks.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int PMAX[n];
        PMAX[0] = arr[0];

        for (int i = 1; i < n; i++)
            PMAX[i] = max(PMAX[i - 1], arr[i]);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == PMAX[i])
                res++;
        }

        return res;
    }
};


/* BRUTE-FORCE

class Solution {
public:

    bool canBeChunked(int i, int j, vector<int>& arr) {
        for (int k = i; k <= j; k++) {
            if (arr[k] < i || arr[k] > j)
                return false;
        }
        return true;
    }

    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0, res = 0;

        while (i < n) {
            for (j = i; j < n; j++) {
                if (canBeChunked(i, j, arr))
                    break;
            }
            res++;
            i = j + 1;
        }

        return res;
    }
};
*/