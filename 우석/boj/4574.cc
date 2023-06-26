#include <iostream>
#include <cstring>

using namespace std;

int gsudoku[10][10];
bool gdomino[10][10];
bool gcheckBox[10][10];
bool gcheckCol[10][10];
bool gcheckRow[10][10];

int dr[] = {0,1};
int dc[] = {1,0};

void maskFunction(int r, int c, int val, bool tf){
    gcheckRow[r][val] = tf;
    gcheckCol[c][val] = tf;
    gcheckBox[(r/3)*3+(c/3)][val] = tf;
}

bool checkAvailable(int r, int c, int val){
    return !(gcheckRow[r][val] || gcheckCol[c][val] || gcheckBox[(r/3)*3+(c/3)][val]);
}

bool sol(int k){ 
    if(k == 81){
        // print
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << gsudoku[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int r, c;
    r = k/9; c = k%9;
    // if already filled
    if(gsudoku[r][c] != 0){
        return sol(k+1);
    }
    else{
        // for domino
        for(int i = 0; i<2; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            // out of range
            if(!(0<=nr && nr <9 && 0<=nc && nc <9)) continue;
            // if already nr nc filled continue
            if(gsudoku[nr][nc]!=0) continue;
            // put two values together
            for(int p = 1; p<=9; p++){
                for(int q = 1; q<=9; q++){
                    if(p == q) continue;
                    // already there is domino set
                    if(gdomino[p][q]) continue; 
                    // check if p, q available in their position
                    if(checkAvailable(r, c, p) && checkAvailable(nr, nc, q)){
                        gsudoku[r][c] = p; gsudoku[nr][nc] = q;
                        gdomino[p][q] = gdomino[q][p] = true;
                        maskFunction(r, c, p, true);
                        maskFunction(nr, nc, q, true);
                        if(sol(k+1)) return true;
                        gsudoku[r][c] = 0; gsudoku[nr][nc] = 0;
                        gdomino[p][q] = gdomino[q][p] = false;
                        maskFunction(r, c, p, false);
                        maskFunction(nr, nc, q, false);
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int testNum = 0;
    while(1){
        // to print puzzle num
        testNum++;

        // initialize
        memset(gdomino, false, sizeof(gdomino));
        memset(gcheckBox, false, sizeof(gcheckBox));
        memset(gcheckCol, false, sizeof(gcheckCol));
        memset(gcheckRow, false, sizeof(gcheckRow));
        memset(gsudoku, 0, sizeof(gsudoku));

        int N; 
        cin >> N;
        if(N==0) break; // 마지막엔 0등장
        // U LU V LV
        string s1, s2;
        int n1, n2;
        for(int i = 0; i<N; i++){
            cin >> n1 >> s1 >> n2 >> s2;
            int r1, c1, r2, c2;
            r1 = s1[0]-'A';
            c1 = s1[1]-'1';
            r2 = s2[0]-'A';
            c2 = s2[1]-'1';

            gsudoku[r1][c1] = n1;
            gsudoku[r2][c2] = n2;
            gdomino[n1][n2] = gdomino[n2][n1] = true;

            // mask true
            maskFunction(r1, c1, n1, true);
            maskFunction(r2, c2, n2, true);
        }
        // fill number
        for(int i = 1; i<=9; i++){
            string s;
            cin >> s;
            int r,c;
            r = s[0]-'A';
            c = s[1]-'1';
            gsudoku[r][c] = i;
            maskFunction(r, c, i, true);
        }
        
        cout << "Puzzle " << testNum << endl;
        sol(0);
    }
    return 0;
}