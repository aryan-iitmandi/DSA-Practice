#include<bits/stdc++.h>
using namespace std;

// brute force
string reverseWords(string sentence){
    vector<string> words;
    string word;

    for(char ch : sentence){
        if(ch != ' ')  word += ch;

        else if(!word.empty()){
            words.push_back(word);
            word = "";
        }
    }
    if(!word.empty())   words.push_back(word);
    reverse(words.begin(), words.end());

    string result = "";
    for(int i=0; i<words.size(); i++){
        result += words[i];
        if(i < words.size() -1)   result += " ";
    }

    return result;
}

// optimal in-place
string reverseWordsOptimal(string sentance){
    reverse(sentance.begin(), sentance.end());

    int start = 0;
    for(int end=0; end<=sentance.size(); end++){
        if(end == sentance.size() || sentance[end] == ' '){
            reverse(sentance.begin()+start, sentance.begin()+end);
            start = end +1;
        }
    }
    return sentance;
}

int main(){
    string s;
    getline(cin, s);

    string result = reverseWordsOptimal(s);
    cout << result;

    return 0;
}