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

int FixBadSequence(const vector<pair<int, int>> &rule, const vector<int> &line) {
    if (checkValid(rule, line) == 1) {
        return 0;
    }
    vector<int> good = line;
    vector<int> bad;

    for (int i = 0; i < good.size() - 1; i++) {
        pair<int, int> target = {good[i], good[i + 1]};
        auto it = find(rule.begin(), rule.end(), target);
        if (it == rule.end()) {
            bad.push_back(good[i]);
            good.erase(good.begin() + i);
            i--; 
        }
    }

    for (int i = 0; i < bad.size(); i++) {
        bool inserted = false;
        for (int m = 0; m <= good.size(); m++) {
            good.insert(good.begin() + m, bad[i]);
            if (checkValid(rule, good)) {
                inserted = true;
                break;
            }
            good.erase(good.begin() + m);
        }
    }

    //cout << ((good.size() % 2 == 0) ?  good[(good.size() - 1) / 2 + 1] : good[(good.size() - 1) / 2])<< "\n";
    cout << good[(good.size() - 1) / 2] << "\n";
    if (good.size() % 2 == 0) {
        return good[((good.size() - 1) / 2 )+ 1];
    } else return good[(good.size() - 1) / 2];
}


int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
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
        ans += FixBadSequence(rule, printSequence[i]);
    
    cout << ans << "\n";
    return 0;
}
