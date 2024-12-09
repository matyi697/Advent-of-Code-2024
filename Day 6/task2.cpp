#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool inBounds(int x, int y, int dir, const vector<vector<char>> &input) {
    switch (dir) {
        case 1: return y > 0;                       //fel
        case 2: return x + 1 < input[0].size();     //jobbra
        case 3: return y + 1 < input.size();        //le
        case 4: return x > 0;                       //balra
    }
    return false;
}

bool isLoop(const vector<vector<char>> &input) {
    int x = 0, y = 0, dir = 1;
    set<pair<int, int>> visited;

    for (int y_ = 0; y_ < input.size(); y_++) {
        for (int x_ = 0; x_ < input[0].size(); x_++) {
            if (input[y_][x_] == '^') {
                x = x_;
                y = y_;
                break;
            }
        }
    }

    while (inBounds(x, y, dir, input)) {
        pair<int, int> searchPair = {x + y * input[0].size(), dir};
        auto it = visited.find(searchPair);

        if (it != visited.end())
            return 1;

        if (dir == 1 && input[y - 1][x] != '#') {
            visited.insert(searchPair);
            y--;
        }
        else if (dir == 2 && input[y][x + 1] != '#') {
            visited.insert(searchPair);
            x++;
        }
        else if (dir == 3 && input[y + 1][x] != '#') {
            visited.insert(searchPair);
            y++;
        }
        else if (dir == 4 && input[y][x - 1] != '#') {
            visited.insert(searchPair);
            x--;
        }
        else
            dir = (dir % 4) + 1;
    }

    return 0;
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
        for (int x = 0; x < input[y].size(); x++) {
            vector<vector<char>> temp = input;
            temp[y][x] = '#';
            ans += isLoop(temp);
        }
    cout << ans << "\n";
    return 0;
}
