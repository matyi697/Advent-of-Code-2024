#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int isSafeRow(vector<int> numbers) {
    bool asc = numbers[0] < numbers[1];
    for (int i = 0; i < numbers.size() - 1; i++) {
        int diff = abs(numbers[i] - numbers[i + 1]);

        if (diff > 3 || diff < 1)
            return 0;

        if ((asc && numbers[i] > numbers[i + 1]) || (!asc && numbers[i] < numbers[i + 1]))
            return 0;
    }
    return 1;
}

int isSafe(vector<int> numbers) {
    if (isSafeRow(numbers) == 1)
        return 1;

    for (int i = 0; i < numbers.size(); i++) {
        vector<int> input = numbers;
        input.erase(input.begin() + i);
        if (isSafeRow(input) == 1)
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    string line;
    int ans = 0;
    
    while (getline(file, line)) {
        vector<int> numbers;
        stringstream ss(line);
        int num;

        while (ss >> num)
            numbers.push_back(num);
        cout << (isSafe(numbers) == 1 ? "safe\n" : "unsafe\n");
        ans += isSafe(numbers);
    }
    
    file.close();
    cout << ans << "\n";
    
    return 0;
}