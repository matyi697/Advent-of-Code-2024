#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const char word[5] = "XMAS";

unsigned checkXmas(const vector<vector<char>>& input, int x0, int y0) {
    unsigned ans = 0;
    bool right = x0 <= input[0].size() - 4;
    bool left = x0 >= 3;
    bool up = y0 >= 3;
    bool down = y0 <= input.size() - 4;

    /*
    minden x kozepe a betu
        -4 lehetoseg lehet hrdcodeolni    
    */

    return ans;
}

int main (int argc, char* argv[]) {
    ifstream file(argv[1]);
    vector<vector<char>> input;
    string line;
    unsigned ans = 0;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        input.push_back(row);        
    }

    file.close(); 

    for(int y = 0; y < input.size(); y++) 
        for(int x = 0; x < input[0].size(); x++)
            ans += checkXmas(input, x, y);
    cout << ans << "\n";
    return 0;
}