#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 

using namespace std;

unsigned countAntinode(const vector<vector<char>>& input, vector<char> antennas) {
    for(int y = 0; y < input.size(); y++) {
        for(int x = 0; x < input[y].size(); x++) {
            
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);

    vector<vector<char>> input;
    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        input.push_back(row);
    }
    file.close();
    unsigned ans = 0; 
    vector<char> antennas;
    
    for(int y = 0; y < input.size(); y++) {
        for(int x = 0; x < input[y].size(); x++) {
            if(input[y][x] == '.') continue;
                vector<char>::iterator it = find(antennas.begin(), antennas.end(), input[y][x]);
                if (it == antennas.end())
                    antennas.push_back(input[y][x]);
        }
    }

    ans = countAntinode(input, antennas);
    return 0;
}
