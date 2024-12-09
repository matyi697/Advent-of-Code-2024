#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int checkValid(const vector<pair<int, int>> &rule, const vector<int> &line) {
    for (int i = 0; i < line.size() - 1; i++) {
        pair<int, int> target = {line[i], line[i + 1]};
        auto it = find(rule.begin(), rule.end(), target);
        if (it == rule.end()) 
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    ifsstream file(argv[1]);
    unsigned ans = 0;
    vector<pair<int, int>> rule;
    vector<vector<int>> printSequence;
    string line;
    bool newPart = false;

    while (getline(file, line)) {
        if (line.empty()) {
            newPart = true;
            continue;
        }

        if (!newPart) {
            stringstream ss(line);
            int a, b;
            char delimiter;
            ss >> a >> delimiter >> b;
            if (delimiter == '|')
                rule.emplace_back(a, b);
        } else {
            stringstream ss(line);
            vector<int> row;
            string number;
            while (getline(ss, number, ','))
                row.push_back(stoi(number));

            printSequence.push_back(row);
        }
    }
    file.close();

    for (int i = 0; i < printSequence.size(); i++)
        ans += checkValid(rule, printSequence[i]);

    cout << ans << "\n";
    return 0;
}
