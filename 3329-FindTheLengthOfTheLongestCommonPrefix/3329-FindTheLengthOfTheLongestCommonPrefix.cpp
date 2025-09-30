// Last updated: 10/1/2025, 12:46:53 AM
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

    map<string, int> prefixMap;

    int maxPrefixLength = 0;

    for (int x : arr1) {

        string numStr = to_string(x);

        for (int i = 1; i <= numStr.length(); ++i) {

            prefixMap[numStr.substr(0, i)]++;

        }

    }

    for (int y : arr2) {

        string numStr = to_string(y);

        for (int i = 1; i <= numStr.length(); ++i) {

            if (prefixMap.find(numStr.substr(0, i)) != prefixMap.end()) {

                maxPrefixLength = max(maxPrefixLength, i);

            } else {

                break;

            }

        }

    }

    return maxPrefixLength;

}
};