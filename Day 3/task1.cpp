#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

unsigned extract_numbers(const string& input) {
    regex pattern(R"(mul\((-?\d+),(-?\d+)\))");
    smatch matches;
    unsigned ans = 0;
    string::const_iterator searchStart(input.cbegin());

    while (regex_search(searchStart, input.cend(), matches, pattern)) {
        int num1 = stoi(matches[1].str());
        int num2 = stoi(matches[2].str());
        ans += num1 * num2;
        searchStart = matches.suffix().first;
    }
    return ans;
}

int main(int argc, char* argv[]) {
    ifstream file (argv[1]);
    ostringstream oss;
    oss << file.rdbuf();
    string input = oss.str();
    cout << extract_numbers(input) << "\n";
    return 0;
}