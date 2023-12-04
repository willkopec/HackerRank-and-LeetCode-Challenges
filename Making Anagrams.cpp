#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    map<char, int> charCount;
    int count = 0;
    
    string shorter = "";
    string longer = "";
    
    if(s1.length() > s2.length()){
        longer = s1;
        shorter = s2;
    } else {
        longer = s2;
        shorter = s1;
    }
    cout << longer << endl;
    
    for(int i = 0; i < longer.size(); i++){
        charCount[longer.at(i)]++;
    }
    
    for(int i = 0; i < shorter.size(); i++){
        if(charCount[shorter.at(i)] >= 1){
            charCount[shorter.at(i)]--;
        } else {
            count ++;
        }
        
    }
    
    for(map<char, int>::iterator iter = charCount.begin(); iter != charCount.end(); ++iter) {
        count += iter->second;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
