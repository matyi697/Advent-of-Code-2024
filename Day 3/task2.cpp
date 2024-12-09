#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

unsigned extract_numbers(const string &input) {
    regex pattern(R"(mul\((-?\d+),(-?\d+)\)|do\(\)|don't\(\))");
    auto searchStart = input.begin();
    smatch matches;
    bool enabled = true;
    unsigned ans = 0;

    while (regex_search(searchStart, input.end(), matches, pattern)) {
        if (matches[1].matched && matches[2].matched) {
            if (enabled) {
                int num1 = stoi(matches[1].str());
                int num2 = stoi(matches[2].str());
                ans += num1 * num2;
            }
        } else if (matches.str() == "do()")
            enabled = true;
        else if (matches.str() == "don't()")
            enabled = false;
        searchStart = matches.suffix().first;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    ostringstream oss;
    oss << file.rdbuf();
    string input = oss.str();
    cout << extract_numbers(input) << "\n";
    return 0;
}