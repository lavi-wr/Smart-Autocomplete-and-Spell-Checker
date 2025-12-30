#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<map>
#include <algorithm>

using namespace std;

string green = "\033[32m";
string red = "\033[31m";
string yellow = "\033[33m";
string reset = "\033[0m";

class nd {
public:
    bool end;
    nd* nxt[26];

    nd() {
        end = false;
        for(int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

class tr {
public:
    nd* root;

    tr() {
        root = new nd();
    }

    void add(string &s) {
        nd* t = root;
        for(char c : s) {
            int k = c - 'a';
            if(t->nxt[k] == NULL) t->nxt[k] = new nd();
            t = t->nxt[k];
        }
        t->end = true;
    }

    void go(nd *p, string cur, vector<string> &out) {
        if(!p) return;
        if(p->end) out.push_back(cur);

        for(int i = 0; i < 26; i++) {
            if(p->nxt[i]) {
                cur.push_back('a' + i);
                go(p->nxt[i], cur, out);
                cur.pop_back();
            }
        }
    }

    vector<string> suggest(string s) {
        nd* t = root;
        for(char c : s) {
            int k = c - 'a';
            if(t->nxt[k] == NULL) return {};
            t = t->nxt[k];
        }
        vector<string> out;
        go(t, s, out);
        return out;
    }
};

int dist(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> d(n+1, vector<int>(m+1));

    for(int i = 0; i <= n; i++) d[i][0] = i;
    for(int j = 0; j <= m; j++) d[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) d[i][j] = d[i-1][j-1];
            else d[i][j] = 1 + min({ d[i-1][j], d[i][j-1], d[i-1][j-1] });
        }
    }
    return d[n][m];
}

vector<string> close3(string s, vector<string> &dict) {

    map<int, vector<string>> mp;  

    
    for (string x : dict) {
        int d = dist(s, x);
        mp[d].push_back(x);
    }

    vector<string> ans;
    int count = 0;

    
    for (auto &entry : mp) {
         sort(entry.second.begin(), entry.second.end());
        for (string w : entry.second) {
            if (count == 3) break;
            ans.push_back(w);
            count++;
        }
        if (count == 3) break;
    }

    return ans;
}



int main() {
    system("chcp 65001 > nul");

    tr t;
    vector<string> dict;

    ifstream fin("words.txt");
    string w;
    while(fin >> w) {
        dict.push_back(w);
        t.add(w);
    }

    cout << green << "✨ autocomplete + spell check ✨" << reset << "\n\n";

    while(true) {
        cout << "\nenter word or prefix (exit to quit): ";
        string s;
        cin >> s;

        if(s == "exit") break;

        vector<string> out = t.suggest(s);

        if(!out.empty()) {
            cout << green << "\nfound:\n" << reset;
            for(string x : out) cout << " ➤ " << x << "\n";
        }
        else {
            cout << red << "\nno match ⚠️\n" << reset;

            vector<string> near = close3(s, dict);

            cout << yellow << "did you mean:\n" << reset;
            for(string x : near) cout << " ⭐ " << x << "\n";

            char c;
            cout << "\nadd '" << s << "' ? (y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y') {
                dict.push_back(s);
                t.add(s);
                ofstream fout("words.txt", ios::app);
                fout << "\n" << s;
                cout << green << "added ✅\n" << reset;
            }
        }
    }
    return 0;
}
