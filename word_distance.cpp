
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int  minD = INT_MAX;
        int p1 = -1, p2 = -1;
        for(int i=0; i<words.size(); i++) {
            string &word = words[i];
            if(word1.compare(word)==0) {
                p1 = i;
                if(p2 != 0){
                    minD = std:min(minD, p1 - p2);
                }
            }
            if(word2.compare(word)==0) {
                p2 = i;
                if(p1 != 0){
                    minD = std:min(minD, p2 - p1);
                }
            }
        }
        return minD;
    }

