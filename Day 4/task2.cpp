#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool checkXmas(const vector<vector<char>> &input, int x0, int y0) {
    bool right = x0 <= input[0].size() - 4;
    bool left = x0 >= 3;
    bool up = y0 >= 3;
    bool down = y0 <= input.size() - 4;

    if (input[x0][y0] != 'A')
        return 0;

    bool leftDiag = false;
    bool rightDiag = false;
    char topLeft = (x0 - 1 >= 0 && y0 - 1 >= 0) ? input[x0 - 1][y0 - 1] : 0;
    char bottomLeft = (x0 - 1 >= 0 && y0 + 1 < input.size()) ? input[x0 - 1][y0 + 1] : 0;
    char topRight = (x0 + 1 < input[0].size() && y0 - 1 >= 0) ? input[x0 + 1][y0 - 1] : 0;
    char bottomRight = (x0 + 1 < input[0].size() && y0 + 1 < input.size()) ? input[x0 + 1][y0 + 1] : 0;


    if ((topLeft == 'M' && bottomRight == 'S') || (topLeft == 'S' && bottomRight == 'M'))
        leftDiag = true;

    if ((topRight == 'M' && bottomLeft == 'S') || (topRight == 'S' && bottomLeft == 'M'))
        rightDiag = true;

    return leftDiag && rightDiag;
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