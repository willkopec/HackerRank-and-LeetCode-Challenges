#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr) {
    
    int numsOutOfOrder = 0;
    int ordersMessedUp = 0;
    int firstNumOutOfOrder = 0;
    
    int reverseBeginI = 0;
    int reverseEndI = 0;
    
    int swapBeginI = -1;
    int swapEndI = 0;
    
    bool reversed = false;
    bool swapped = false;
    
    bool reverseNeeded = false;
    bool swapNeeded = false;
    
    if(arr.size() <= 2){
        if(arr[0] > arr[1]){
            cout << "yes" << endl;
            cout << "swap 1 2" << endl;
        }
    } else {
        for(int i = 0; i < arr.size() - 1; i++){
        
            if(arr[i] > arr[i + 1]) {

                if(ordersMessedUp == 0){
                    swapBeginI = i + 1;
                    reverseBeginI = i + 1;
                } else if(ordersMessedUp == 1){
                    if(reversed){
                        reversed = false;
                        swapped = false;
                        break;
                    }
                    if(numsOutOfOrder > 0){
                        reverseNeeded = true;
                    }
                    if(swapNeeded){
                        swapEndI = i + 2;
                    }
                    
                    if(swapped){
                        swapped = false;
                        break;
                    }
                    
                } else {
                    swapped = false;
                    reversed = false;
                    reverseNeeded = false;
                    swapNeeded = false;
                    break;
                }
                
                if(numsOutOfOrder == 0){
                    ordersMessedUp++;
                }
                
                numsOutOfOrder++;
                firstNumOutOfOrder = arr[i];
            } 
            
            else if(arr[i] < arr[i + 1]){
                if(ordersMessedUp >= 1 && numsOutOfOrder == 1){
                    if(swapNeeded){
                        swapEndI = i + 1;
                        swapped = true;
                    }
                    
                    swapNeeded = true;
                }
                
                if(ordersMessedUp >= 1 && numsOutOfOrder > 1){
                    reverseEndI = i + 1;
                    reversed = true;
                }
                
                numsOutOfOrder = 0;
            }
        
        }
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        if(swapBeginI != -1 && !swapped){
            std::swap(arr[swapBeginI - 1], arr[swapBeginI]);
            
            if(arr == sortedArr){
                cout << "yes" << endl;
                cout << "swap " << swapBeginI << " " << swapBeginI + 1 << endl;
                return;
            }
        }
        
        if(reverseNeeded && reverseEndI == 0){
            cout << "yes" << endl;
            cout << "reverse " << reverseBeginI << " " << arr.size() << endl;
        } else if(reversed){
            cout << "yes" << endl;
            cout << "reverse " << reverseBeginI << " " << reverseEndI << endl;
        } else if(swapped){
            cout << "yes" << endl;
            cout << "swap " << swapBeginI << " " << swapEndI << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    
    
    

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
