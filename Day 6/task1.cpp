#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool inBounds(unsigned x, unsigned y, unsigned dir, const vector<vector<char>> &input) {
    switch (dir) {
        case 1: return y > 0;
        case 2: return x + 1 < input[0].size();
        case 3: return y + 1 < input.size();
        case 4: return x > 0;
    }
    return false;
}

int guardPath(const vector<vector<char>> &input) {
    unsigned x = 0, y = 0;
    unsigned direction = 1; // 1=fel, 2=jobbra, 3=le, 4=balra
    vector<vector<char>> grid = input;

    for (unsigned i = 0; i < input.size(); i++)
        for (unsigned n = 0; n < input[i].size(); n++)
            if (input[i][n] == '^') {
                y = i;
                x = n;
                break;
            }

    while (inBounds(x, y, direction, grid)) {
        switch (direction) {
            case 1: // fel
                if (grid[y - 1][x] != '#') {
                    grid[y][x] = 'x';
                    y--;
                } else direction = (direction % 4) + 1;
                break;
            case 2: // jobbra
                if (grid[y][x + 1] != '#') {
                    grid[y][x] = 'x';
                    x++;
                } else direction = (direction % 4) + 1;
                break;
            case 3: // le
                if (grid[y + 1][x] != '#') {
                    grid[y][x] = 'x';
                    y++;
                } else direction = (direction % 4) + 1;
                break;
            case 4: // balra
                if (grid[y][x - 1] != '#') {
                    grid[y][x] = 'x';
                    x--;
                } else direction = (direction % 4) + 1;
                break;
        }
    }

    unsigned ans = 1; //kivetelesen azert 1 mert a kezdopozicio is kell
    for (unsigned y = 0; y < grid.size(); y++) 
        for (unsigned x = 0; x < grid[y].size(); x++) 
            ans += (grid[y][x] == 'x');

    return ans;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);

    vector<vector<char>> input;
    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        input.push_back(row);
    }
    file.close();

    cout << guardPath(input) << endl;

    return 0;
}
