#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
//(-1+sqrt(1+(8*n)))/2; to know if n is sum from 1 to k or not

unordered_map<string,bool>m;  // to storage the dictionary
string input;
vector<vector<string>>ans;  // have all the possible sentences
vector<string>v;
void rec(int i,string take){
    if(i==input.size()){
        bool f=0;
        if(take.empty()){
            for(int k=0;k<v.size();k++){
                if(!m[v[k]]){ f=0; break; } // the word is not a real word in english
                else f=1;
            }
        }
        if(f) ans.push_back(v);
        return;
    }
    take+=input[i]; // add the char
    rec(i+1,take);  // go to the next without adding to the vector
    v.push_back(take);  // add to the vector
    take="";
    rec(i+1,take); // go to the next after adding to the vector
    v.pop_back(); // remove from the vector
}

int main(){
    ifstream dic("dictionary.txt",ios::in) ;
    string word;
    while (!dic.eof()){ // read from the file
        getline(dic,word);
        m[word]=1;
    }
    cin>>input;
    for(int i=0;i<input.size();i++){  //tolower letters
        if(input[i]<'a')
            input[i]+=32;
    }
    rec(0,"");
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}