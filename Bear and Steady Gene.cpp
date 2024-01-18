#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */
 bool isValid(string& str, string& pattern, int mid,
             int& start)
{
    int count[256] = { 0 };

    int distinct = 0;
 
    bool found = false;
 
    for (char c : pattern) {
        count[c]++;
        if (count[c] == 1)
            distinct++;
    }
 
    int curr_count = 0;
    for (int i = 0; i < str.size(); i++) {
        count[str[i]]--;
        if (count[str[i]] == 0) {
            curr_count++;
        }
        if (i >= mid) {
            count[str[i - mid]]++;
            if (count[str[i - mid]] == 1) {
                curr_count--;
            }
        }
        if (i >= mid - 1) {
 
            if (curr_count == distinct) {
 
                found = true;
 
                start = (i - mid) + 1;
                break;
            }
        }
    }
 
    return found;
}
 
// Function to find the smallest substring containing all
// characters of the pattern
string findSmallestSubstring(string& str, string& pattern)
{
    int len_str = str.length();
    int len_pattern = pattern.length();
    string smallestSubstring = "";
 
    int minLength = INT_MAX;
 
    int low_bound = 1, high_bound = len_str;
 
    int idx;
 
    while (low_bound <= high_bound) {
        int mid = (low_bound + high_bound) / 2;
        int start;

        if (isValid(str, pattern, mid, start)) {
            if (mid < minLength) {
                minLength = mid;
                idx = start;
            }
            high_bound = mid - 1;
        }
       
        else {
            low_bound = mid + 1;
        }
    }
 
    return smallestSubstring = str.substr(idx, minLength);
}

int steadyGene(string gene) {
    
    map<char, int> geneCount;
    
    for(int i = 0; i < gene.size(); i++){
        
        geneCount[gene[i]]++;
        
    }
    
    int curMinLength = 0;
    string curDeletingStr = "";
    for(map<char,int>::iterator iter = geneCount.begin(); iter != geneCount.end(); ++iter){
        
        if(iter->second - ( (int) gene.length()/4) >= 1){
            curDeletingStr += string(iter->second - ( (int) gene.length()/4), iter->first);
        }        
    }

    if(curDeletingStr.size() == 0){
        return 0;
    }
    
    int minSize = findSmallestSubstring(gene, curDeletingStr).length();
    
    
    return minSize;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
