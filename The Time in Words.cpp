#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string prefix = "";
    string midfix = "";
    string postfix = "";
    
    bool afterHalf = false;
    bool onTheDot = false;
    
    if(m > 30){
        afterHalf = true;
    }
    if(!afterHalf){
        switch(m){
            case 0:
                postfix = " o' clock";
                onTheDot = true;
                break;
            case 1:
                prefix = "one minute";
                break;
            case 2:
                prefix = "two minutes";
                break;
            case 3:
                prefix = "thre minutes";
                break;
            case 4:
                prefix = "four minutes";
                break;
            case 5:
                prefix = "five minutes";
                break;
            case 6:
                prefix = "six minutes";
                break;
            case 7:
                prefix = "seven minutes";
                break;
            case 8:
                prefix = "eight minutes";
                break;
            case 9:
                prefix = "nine minutes";
                break;
            case 10:
                prefix = "ten minutes";
                break;
            case 11:
                prefix = "eleven minutes";
                break;
            case 12:
                prefix = "twelve minutes";
                break;
            case 13:
                prefix = "thirteen minutes";
                break;
            case 14:
                prefix = "fourteen minutes";
                break;
            case 15:
                prefix = "quarter";
                break;
            case 16:
                prefix = "sixteen minutes";
                break;
            case 17:
                prefix = "seventeen minutes";
                break;
            case 18:
                prefix = "eighteen minutes";
                break;
            case 19:
                prefix = "nineteen minutes";
                break;
            case 20:
                prefix = "twenty minutes";
                break;
            case 21:
                prefix = "twenty one minutes";
                break;
            case 22:
                prefix = "twenty two minutes";
                break;
            case 23:
                prefix = "twenty three minutes";
                break;
            case 24:
                prefix = "twenty four minutes";
                break;
            case 25:
                prefix = "twenty five minutes";
                break;
            case 26:
                prefix = "twenty six minutes";
                break;
            case 27:
                prefix = "twenty seven minutes";
                break;
            case 28:
                prefix = "twenty eight minutes";
                break;
            case 29:
                prefix = "twenty nine minutes";
                break;
            case 30:
                prefix = "half";
                break;
        }
        switch(h){
            case 1:
                if(onTheDot){
                    prefix = "one";
                } else {
                    postfix = " past one";
                }
                break;
            case 2:
                if(onTheDot){
                    prefix = "two";
                } else {
                    postfix = " past two";
                }
                
                break;
            case 3:
                if(onTheDot){
                    prefix = "three";
                } else {
                    postfix = " past three";
                }
                
                break;
            case 4:
                if(onTheDot){
                    prefix = "four";
                } else {
                    postfix = " past four";
                }
                
                break;
            case 5:
                if(onTheDot){
                    prefix = "five";
                } else {
                    postfix = " past five";
                }
                
                break;
            case 6:
                if(onTheDot){
                    prefix = "six";
                } else {
                    postfix = " past six";
                }
                
                break;
            case 7:
                if(onTheDot){
                    prefix = "seven";
                } else {
                    postfix = " past seven";
                }
                
                break;
            case 8:
                if(onTheDot){
                    prefix = "eight";
                } else {
                    postfix = " past eight";
                }
                
                break;
            case 9:
                if(onTheDot){
                    prefix = "nine";
                } else {
                    postfix = " past nine";
                }
                
                break;
            case 10:
                if(onTheDot){
                    prefix = "ten";
                } else {
                    postfix = " past ten";
                }
                
                break;
            case 11:
                if(onTheDot){
                    prefix = "eleven";
                } else {
                    postfix = " past eleven";
                }
                
                break;
            case 12:
                if(onTheDot){
                    prefix = "twelve";
                } else {
                    postfix = " past twelve";
                }
                
                break;
        }
        
    
    } else {
        switch(m){
            case 31:
                prefix = "twenty nine minutes";
            break;
            case 32:
                prefix = "twenty eight minutes";
            break;
            case 33:
                prefix = "twenty seven minutes";
            break;
            case 34:
                prefix = "twenty six minutes";
            break;
            case 35:
                prefix = "twenty five minutes";
            break;
            case 36:
                prefix = "twenty four minutes";
            break;
            case 37:
                prefix = "twenty three minutes";
            break;
            case 38:
                prefix = "twenty two minutes";
            break;
            case 39:
                prefix = "twenty one minutes";
            break;
            case 40:
                prefix = "twenty minutes";
            break;
            case 41:
                prefix = "nineteen minutes";
            break;
            case 42:
                prefix = "eighteen minutes";
            break;
            case 43:
                prefix = "seventeen minutes";
            break;
            case 44:
                prefix = "sixteen minutes";
            break;
            case 45:
                prefix = "quarter";
            break;
            case 46:
                prefix = "fourteen minutes";
            break;
            case 47:
                prefix = "thirteen minutes";
            break;
            case 48:
                prefix = "twelve minutes";
            break;
            case 49:
                prefix = "eleven minutes";
            break;
            case 50:
                prefix = "ten minutes";
            break;
            case 51:
                prefix = "nine minutes";
            break;
            case 52:
                prefix = "eight minutes";
            break;
            case 53:
                prefix = "seven minutes";
            break;
            case 54:
                prefix = "six minutes";
            break;
            case 55:
                prefix = "five minutes";
            break;
            case 56:
                prefix = "four minutes";
            break;
            case 57:
                prefix = "three minutes";
            break;
            case 58:
                prefix = "two minutes";
            break;
            case 59:
                prefix = "one minute";
            break;
        }
        switch(h){
            case 1:
                postfix = " to two";
            break;
            case 2:
                postfix = " to three";
            break;
            case 3:
                postfix = " to four";
            break;
            case 4:
                postfix = " to five";
            break;
            case 5:
                postfix = " to six";
            break;
            case 6:
                postfix = " to seven";
            break;
            case 7:
                postfix = " to eight";
            break;
            case 8:
                postfix = " to nine";
            break;
            case 9:
                postfix = " to ten";
            break;
            case 10:
                postfix = " to eleven";
            break;
            case 11:
                postfix = " to twelve";
            break;
            case 12:
                postfix = " to one";
            break;
        }
    }
    
    
    
    return prefix + postfix;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
