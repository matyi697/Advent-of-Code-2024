#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    vector<int> colA;
    vector<int> colB;
    string line;
    unsigned ans = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        int tempA, tempB;
        if (iss >> tempA >> tempB) {
            colA.push_back(tempA);
            colB.push_back(tempB);
        }
    }

    file.close();

    sort(colA.begin(), colA.end());
    sort(colB.begin(), colB.end());

    for (int a = 0; a < colA.size(); a++)
        ans += abs(colA[a] - colB[a]);

    cout << ans << "\n";
    return 0;
}
