// Pattern Searching using string

#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> hsh(256);

void initialize(string &t){
    for(int i = 0; i < t.size(); ++i){
        hsh[t[i]].insert(i);
    }
}

void pattern_search(string &t, string &p){
    initialize(t);
    queue<int> q_indices;
    for(auto ind: hsh[p[0]]){
        q_indices.push(ind);
    }

    for(int i = 1; i < p.size(); ++i){
        int ch = p[i];
        int queue_size = q_indices.size();
        while(queue_size--){
            int ind = q_indices.front();
            q_indices.pop();
            if(hsh[ch].find(ind + 1) != hsh[ch].end()){
                q_indices.push(ind + 1);
            }
        }
    }

    cout << "Pattern found at index ";
    while(!q_indices.empty()){
        int last_index = q_indices.front();
        q_indices.pop();
        cout << last_index - (p.size() - 1) << " ";
    }
}

int main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    pattern_search(txt, pat);
}