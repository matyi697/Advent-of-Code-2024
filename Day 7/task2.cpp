#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef unsigned long long u64;

u64 evaluateExpression(vector<int> numbers, vector<int> operators) {
    u64 ans = numbers[0];
    for (int i = 0; i < numbers.size() - 1; i++) {
        switch (operators[i]) {
            case 0:
                ans += numbers[i + 1];
                break;
            case 1:
                ans *= numbers[i + 1];
                break;
            case 2:
                ans = pow(10, floor(log10(numbers[i + 1])) + 1) * ans + numbers[i + 1];
                break;
        }
    }
    return ans;
}

void stepOperator(std::vector<int> &opr) {
    int n = opr.size();
    for (int i = n - 1; i >= 0; --i) {
        opr[i] = (opr[i] + 1) % 3;
        if (opr[i] != 0) break;
    }
}

bool isPossible(u64 sum, vector<int> numbers) {
    vector<int> operators(numbers.size() - 1, 0);
    int maxIter = pow(3, numbers.size() - 1);

    for (int i = 0; i < maxIter; ++i) {
        if (evaluateExpression(numbers, operators) == sum)
            return 1;
        stepOperator(operators);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    string line;
    unsigned long long ans = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        u64 sum;
        vector<int> numbers;

        getline(ss, temp, ':');
        sum = stoull(temp);

        while (ss >> temp) {
            numbers.push_back(stoi(temp));
        }
        if (isPossible(sum, numbers))
            ans += sum;
    }
    cout << ans << "\n";
    file.close();
    return 0;
}
