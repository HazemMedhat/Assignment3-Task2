#include <bits/stdc++.h>
using namespace std;

void print(string str)
{
    map<string, int> m;
    string word = "";
    for(int i =0 ; i < str.size();i++)
    {
        str[i] = tolower(str[i]);
    }
    auto it = remove_if(str.begin(), str.end(), ::ispunct);
    str.erase(it, str.end());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ')
        {
            if (m.find(word) == m.end())
            {
                m.insert(make_pair(word, 1));
                word = "";
            }
            else
            {
                m[word]++;
                word = "";
            }
        }
        else
        {
            word += str[i];
        }
    }
    if (m.find(word) == m.end()){
        m.insert(make_pair(word, 1));
    }
    else{
        m[word]++;
    }
    for (auto& it : m) {
        cout << it.first << " --> "<< it.second << endl;
    }
}

int main()
{
    fstream file;
    string line;
    cout<<"Enter the file name: ";
    string n;
    cin>>n;
    file.open(n+".txt",ios::app);
    cout<<"start writing your text and if you finished press 0: "<<endl;
    string str;
    while(file)
    {
        getline(cin,line);

        if(line == "0")
            break;

        file << line << endl;
        str = line;
    }
    file.close();

    print(str);
    return 0;
}
