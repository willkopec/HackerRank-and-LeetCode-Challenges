#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    
    map<char, int> charCount;
    bool extraCharFound = false;
    
    for(int i = 0; i < s.size(); i++){
        charCount[s.at(i)] ++;
    }
    
    if(s.size() % 2 == 0){
        for(map<char, int>::iterator iter = charCount.begin(); iter != charCount.end(); ++iter) {
            if(iter->second % 2 != 0){
                return "NO";
            }
        }
    } else {
        for(map<char, int>::iterator iter = charCount.begin(); iter != charCount.end(); ++iter) {
            if(iter->second % 2 != 0 && !extraCharFound){
                extraCharFound = true;
            } else if(iter->second % 2 != 0 && extraCharFound){
                return "NO";
            }
        }
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
