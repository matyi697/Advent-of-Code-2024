#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

unsigned countAntinode(vector<vector<char>> &input) {
    set<pair<int, int>> uniquePoints;

    for (int y = 0; y < input.size(); y++) {
        for (int x = 0; x < input[y].size(); x++) {
            if (input[y][x] != '.' && input[y][x] != '#') {
                char temp = input[y][x];
                for (int yy = 0; yy < input.size(); yy++) {
                    for (int xx = 0; xx < input[yy].size(); xx++) {
                        if (x == xx && y == yy) continue;
                        if (input[yy][xx] == temp) {
                            int dx = xx - x;
                            int dy = yy - y;
                            for(int i = 0; x-i*dx>=0 && x-i*dx<input[0].size() && y-i*dy>=0 && y-i*dy<input.size(); i++) {
                                /*if (input[y - i*dy][x - i*dx] == '.') {
                                    input[y - i*dy][x - i*dx] = '#';
                                }*/
                                uniquePoints.insert({y - i*dy, x - i*dx});
                            }                                
                        }
                    }
                }
            }
        }
    }
    return uniquePoints.size();
}


int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    unsigned ans = 0;
    vector<vector<char>> input;
    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        input.push_back(row);
    }
    file.close();
    ans = countAntinode(input);
    /*for (int y = 0; y < input.size(); y++) {
        for (int x = 0; x < input[y].size(); x++)
            cout << input[y][x];
        cout << "\n";
    }*/
    cout << "Ans: " << ans << "\n";
    return 0;
}
