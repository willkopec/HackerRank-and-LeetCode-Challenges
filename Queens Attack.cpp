#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int total = 0;
    int curX = c_q;
    int curY = r_q;
    int originalX = curX;
    int originalY = curY;
    bool checkedX = false;
    bool checkedY = false;
    bool checkedY1 = false;
    bool checkedY2 = false;
    bool checkedX1 = false;
    bool checkedX2 = false;
    
    bool checkedDiag = false;
    bool checkedDiag1 = false;
    bool checkedDiag2 = false;
    
    bool checkedD = false;
    bool checkedD1 = false;
    bool checkedD2 = false;
    
    map<pair<int, int>, int> flagMap;
    
    for(int i = 0; i < obstacles.size(); i++){
        int x = obstacles[i][1];
        int y = obstacles[i][0];
        
        flagMap[{y,x}] = 1;
    }
    
    while(!checkedX){
        
        if(!checkedX1){
            
            if(flagMap[{curY, curX}] == 1){
                    checkedX1 = true;
            }
          
            if(curX != originalX && !checkedX1){
                total++;
            }
            curX++;
            if(curX > n || checkedX1){
                checkedX1 = true;
                curX = originalX-1;
            }
           
        }
        if(checkedX1 && !checkedX2){
            for(int i = 0; i < obstacles.size(); i++){
                if(curX == obstacles[i][1] && curY == obstacles[i][0]){
                    checkedX2 = true;
                    checkedX = true;

                }
            }
            
          
            if(curX != originalX && curX >= 1 && !checkedX){
                total++;
            }      
            
            curX--;

          if(curX <= 0 || checkedX2){
                checkedX2 = true;
                curX = originalX;
                checkedX = true;
            } 
        }
        
    }
    
    while(!checkedY){
        
        if(!checkedY1){
          
            if(flagMap[{curY, curX}] == 1){
                    checkedY1 = true;
            }
          
            if(curY != originalY && curY <= n && !checkedY1){
                total++;
            }

            curY++;
            
            if(curY > n || checkedY1){
                checkedY1 = true;
                curY = originalY-1;
            }
            
        }
        if(checkedY1 && !checkedY2){
            for(int i = 0; i < obstacles.size(); i++){
                if(curX == obstacles[i][1] && curY == obstacles[i][0]){
                    checkedY2 = true;
                    checkedY = true;
                }
            }
          
            if(curY != originalY && curY >= 1 && !checkedY2){
                total++;
            }
            curY--;
          
            if(curY < 1 || checkedY2){
                checkedY2 = true;
                curY = originalY-1;
                curX = originalX+1;
                checkedY = true;
            }
            
        }
        
    }
    
    while(!checkedDiag){
      
        if(!checkedDiag1){

          if(flagMap[{curY, curX}] == 1){
                checkedDiag1 = true;        
            }
          
            if(curX != originalX && curY != originalY && curY >= 1 && curX <= n && !checkedDiag1){
                total++;
              }
            
            curX++;
            curY--;
          
            if(curX > n || curY < 1 || checkedDiag1){
                checkedDiag1 = true;
                curX = originalX-1;
                curY = originalY+1; 
            }
            
        }
        if(checkedDiag1 && !checkedDiag2){

            if(flagMap[{curY, curX}] == 1){
                    checkedDiag2 = true;
                    checkedDiag = true;         
            }
          
            if(curX != originalX && curY != originalY && curX >= 1 && curY <= n && !checkedDiag2){
                total++;
            }
            
            
            
            curX--;
            curY++;

            if(curX < 1 || curY > n || checkedDiag2){
                checkedDiag2 = true;
                checkedDiag = true;
                curX = originalX+1;
                curY = originalY+1;
            }
        }
        
    }
    
    while(!checkedD){
        
        if(!checkedD1){
            if(flagMap[{curY, curX}] == 1){
                    checkedD1 = true;
        }
            
            if(curX != originalX && curY != originalY && curX <= n && curY <= n && !checkedD1){
                total++;
            }
            if(curX >= n || curY >= n || checkedD1) {
                curX = originalX-1;
                curY = originalY-1; 
                checkedD1 = true;
            }
            
            
            curX++;
            curY++;
        }
        if(checkedD1 && !checkedD2){
            if(flagMap[{curY, curX}] == 1){
                    checkedD2 = true;
                    checkedD = true;
                }

          if(curX != originalX && curY != originalY && curX >= 1 && curY >= 1 && !checkedD2){
                total++;
            }
            
            if(curX <= 1 || curY <= 1 || checkedD2){
                checkedD2 = true;
                checkedD = true;
                curX = originalX;
                curY = originalY; 
            }
            
            curX--;
            curY--;
        }
        
    }
    
    
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
