#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int isSafe(vector<int> input) {
    bool asc = input[0] < input[1];

    for(int n = -1; n < input.size(); n++) {
        vector<int> numbers = input;
        if (n != -1) 
            numbers.erase(numbers.begin() + n);
        
        for(int i = 0; i < numbers.size() - 1; i++) {
            int diff = abs(numbers[i] - numbers[i+1]);

            if(diff > 3 || diff < 1) 
                return 0;
            
            if ((asc && numbers[i] > numbers[i+1]) || (!asc && numbers[i] < numbers[i+1])) 
                return 0;
        }
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
        //cout << (isSafe(numbers) == 1 ? "safe\n" : "unsafe\n");
        ans += isSafe(numbers);
        }
    cout << ans << "\n";
    file.close();
    return 0;
}