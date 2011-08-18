/*
ID: piotrek4
LANG: C++
PROG: msquare
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1 << 26;
const int SIZE = 8;

ifstream fin("msquare.in");
ofstream fout("msquare.out");
int final[SIZE];
string ret;


bool cmp(int* a, int* b) {
    for (int i = 0; i < 8; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void transformA(int* a, int* ret) {
    for (int i = 0; i < 4; ++i) {
        ret[i] = a[7-i];
        ret[7-i] = a[i];
    }
}

void transformB(int* a, int* ret) {
    for (int i = 0; i < 4; ++i) {
        ret[(i+1)%4] = a[i];
        if (i == 3)
            ret[7] = a[4];
        else
            ret[6-i] = a[7-i];
    }
}

void transformC(int* a, int* ret) {
    for (int i = 0; i < 8; ++i)
        ret[i] = a[i];
    ret[2] = a[1];
    ret[1] = a[6];
    ret[6] = a[5];
    ret[5] = a[2];
}

void dfs(int* cur, string s, int countA, int lastB, int lastC) {
    if (cmp(cur, final)) {
        if (s.size() < ret.size()) ret = s;
        else if (s < ret) ret = s;
        return;
    }
    if (s.size() < 15) {
        if (countA < 2) {
            int ra[SIZE];
            transformA(cur, ra);
            dfs(ra, s + "A", countA + 1, 0, 0);
        }
        if (lastB < 3) {
            int rb[SIZE];
            transformB(cur, rb);
            dfs(rb, s + "B", countA, lastB + 1, 0);
        }
        if (lastC < 3) {
            int rc[SIZE];
            transformC(cur, rc);
            dfs(rc, s + "C", countA, 0, lastC + 1);
        }
    }
}


int main() {
    int init[SIZE];

    for (int i = 0; i < 8; ++i) {
        fin >> final[i];
        init[i] = i+1;
    }

    ret = "ZZZZZZZZZZZZZZZZZZZZZZZZZ";
    dfs(init, "", 0, 0, 0);

    fout << ret.size() << endl << ret << endl;

    return 0;
}
