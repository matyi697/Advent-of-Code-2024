#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main (int argc, char* argv[]) {
    FILE* input = fopen(argv[1], "r");
    int tempA;
    int tempB;
    vector<int> left;
    vector<int> right;
    unsigned ans = 0;

    while(fscanf(input, "%d %d", &tempA, &tempB) == 2) {
        left.push_back(tempA);
        right.push_back(tempB);
    }

    for(int l = 0; l < left.size(); l++) 
        for(int r = 0; r < right.size(); r++) 
            if (left[l] == right[r]) 
                ans += right[r];
        
    cout << ans;
    fclose(input);
    return 0;
}