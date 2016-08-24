bool isIsomorphic(string s, string t) {
    int n = s.length();
    if(t.length() != n)   return false;
    unordered_map<char, char> hashst;
    unordered_map<char, char> hashts;
    for(int i=0; i<n; i++){
        if(hashst.count(s[i])==0) {
            hashst[s[i]] = t[i];
        }else{
            if(hashst[s[i]] != t[i])   return false; 
        }

       if(hashts.count(t[i])==0) {
            hashts[t[i]] = s[i];
        }else{
            if(hashts[t[i]] != s[i])   return false; 
        }
    }
    return true; 
}

