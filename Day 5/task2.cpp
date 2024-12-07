#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
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
    /*felepitjuk a hasht*/
    /*  */
    return 0;
}