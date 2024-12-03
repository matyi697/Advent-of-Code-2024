#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int isSafe(vector<int> numbers) {
    bool asc = numbers[0] < numbers[1];
    for(int i = 0; i < numbers.size() - 1; i++) {
        int diff = abs(numbers[i] - numbers[i+1]);
        
        if(diff > 3 || diff < 1) 
            return 0;
        
        if ((asc && numbers[i] > numbers[i+1]) || (!asc && numbers[i] < numbers[i+1])) 
            return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    string line;
    int ans = 0;
    while (getline(file, line)) {
        vector<int> numbers;
        stringstream ss(line);
        int num;
        
        while (ss >> num) 
            numbers.push_back(num);
        
        ans += isSafe(numbers);
        }
    cout << ans << "\n";
    file.close();
    return 0;
}

/*
    The levels are either all increasing or all decreasing.
    Any two adjacent levels differ by at least one and at most three.
*/