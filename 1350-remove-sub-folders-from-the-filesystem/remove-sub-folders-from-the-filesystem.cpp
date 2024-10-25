class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        unordered_set<string> seenFolders;
        for (const auto& folder : folders) {
            seenFolders.insert(folder);
        }
        vector<string> res;
        string currFolder;
        for (const auto& folder : folders) {
            int fLen = folder.size();
            currFolder.clear();
            for (int indx = 0; indx < fLen; indx++) {
                char currChr = folder[indx];
                if (currChr == '/' && seenFolders.count(currFolder) && indx != fLen - 1) {
                    currFolder.clear();
                    break;
                }
                currFolder += currChr;
            }
            if (!currFolder.empty()) {
                res.push_back(currFolder);
            }
        }
        return res;
    }
};