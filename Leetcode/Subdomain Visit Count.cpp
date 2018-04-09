class Solution {
public:
    
    vector<string> separate(string domain){
        vector<string> res;
        while (domain.find('.') != string::npos){
            auto found = domain.find('.');
            res.push_back(domain.substr(0, found));
            domain = domain.substr(found+1, domain.size()-found);
        }
        if (domain.size() > 0){
            res.push_back(domain);
        }
        return res;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map< string, int > mp;
        for (auto w : cpdomains){
            auto found = w.find(" ");
            assert (found != string::npos);
            int counter = stoi(w.substr(0, found));
            string domain = w.substr(found+1, w.size()-found);
            vector< string > tmp = separate(domain);
            for (int i=0; i<tmp.size(); i++){
                stringstream tmp_stream;
                for (int k=i; k<tmp.size(); k++){
                    if (k != i){
                        tmp_stream<<".";
                    }
                    tmp_stream<<tmp[k];
                }
                mp[tmp_stream.str()] += counter;
            }
        }
        vector<string> res;
        for (auto p : mp){
            stringstream tmp;
            tmp<<p.second<<" "<<p.first;
            res.push_back(tmp.str());
        }
        
        return res;
    }
};