#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const char word[5] = "XMAS";

unsigned checkXmas(const vector<vector<char>>& input, int x0, int y0) {
    const int directions[8][2] = {
        {1, 0},  {-1, 0}, 
        {0, -1}, {0, 1}, 
        {1, -1}, {1, 1},  
        {-1, -1}, {-1, 1}
    };

    unsigned ans = 0;

    for (const auto& dir : directions) {
        int dx = dir[0], dy = dir[1];
        bool match = true;

        for (int i = 0; i < 4; ++i) {
            int x = x0 + i * dx;
            int y = y0 + i * dy;

            if (x < 0 || y < 0 || x >= input[0].size() || y >= input.size() || input[y][x] != word[i]) {
                match = false;
                break;
            }
        }

        if (match) 
            ++ans;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    vector<vector<char>> input;
    string line;
    unsigned ans = 0;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        input.push_back(row);
    }

    file.close();

    for (int y = 0; y < input.size(); y++)
        for (int x = 0; x < input[0].size(); x++)
            ans += checkXmas(input, x, y);

    cout << ans << "\n";
    return 0;
}