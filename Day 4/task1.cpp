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

    if (right) {
        bool match = true;
        for (int x = x0; x < x0 + 4; x++) {
            if (input[y0][x] != word[x - x0]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (left) {
        bool match = true;
        for (int x = x0; x > x0 - 4; x--) {
            if (input[y0][x] != word[x0 - x]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (up) {
        bool match = true;
        for (int y = y0; y > y0 - 4; y--) {
            if (input[y][x0] != word[y0 - y]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (down) {
        bool match = true;
        for (int y = y0; y < y0 + 4; y++) {
            if (input[y][x0] != word[y - y0]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (right && up) {
        bool match = true;
        for (int i = 0; i < 4; i++) {
            int x = x0 + i;
            int y = y0 - i;
            if (y < 0 || x >= input[0].size() || input[y][x] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (right && down) {
        bool match = true;
        for (int i = 0; i < 4; i++) {
            int x = x0 + i;
            int y = y0 + i;
            if (y >= input.size() || x >= input[0].size() || input[y][x] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (left && up) {
        bool match = true;
        for (int i = 0; i < 4; i++) {
            int x = x0 - i;
            int y = y0 - i;
            if (y < 0 || x < 0 || input[y][x] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

    if (left && down) {
        bool match = true;
        for (int i = 0; i < 4; i++) {
            int x = x0 - i;
            int y = y0 + i;
            if (y >= input.size() || x < 0 || input[y][x] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) ans++;
    }

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