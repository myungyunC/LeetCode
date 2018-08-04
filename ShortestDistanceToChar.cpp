/*
    Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

    Example 1:

    Input: S = "loveleetcode", C = 'e'
    Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

    
    S string length is in [1, 10000].
    C is a single character, and guaranteed to be in string S.
    All letters in S and C are lowercase.


*/
#include <iostream>
#include <cstdlib>
#include  <vector>
#include <cctype>

using namespace std;

vector<int> shortestToChar(string &S, char C);
int startingChar(char C, char *right);
int endingChar(char C, char *left);
int middleChar(string &S, char C, char *left, char *right);


int main() {
    
    string S = "loveleetcode";
    char C = 'e';
    auto output = shortestToChar(S, C);
    for (auto &x : output) {
        cout << x << " ";
    }
     
        
    
    return 0;
}

vector<int> shortestToChar(string &S, char C) {
    vector<int> solution;
    solution.resize(S.length());
    char *left;
    char *right;
    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == C) {            //if already char C
            solution[i] = 0;
            continue;
        }
        if (i == 0) {
            right = &S[i + 1];
            solution[i] = startingChar(C, right); //for the beginning character, only needs to increment right pointer
        }
        else if (i == S.length() - 1) {
            left = &S[i - 1];
            solution[i] = endingChar(C, left); //for end character, only needs to increment left pointer
        }
        else { 
            left = &S[i - 1];
            right = &S[i + 1];
            solution[i] = middleChar(S, C, left, right); //checks left and right till found         
        }
    }
    return solution;
}


int startingChar(char C, char *right) {
    int distance = 1;
    while (true) {
        if (*right == C)
            return distance;
        right++;
        distance++;
    }
}

int endingChar(char C, char *left) {
    int distance = 1;
    while (true) {
        if (*left == C)
            return distance;
        left--;
        distance++;
    }
}
int middleChar(string &S, char C, char *left, char *right) {
    int distance = 1;
    while (true) {
        if (*right == C)
            return distance;
        if (*left == C)
            return distance;
        
        if (left != &S[0])
            left--;
        if (right != &S[S.length() - 1])
            right++;
        distance++;
    }
}


