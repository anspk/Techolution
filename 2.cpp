#include<bits/stdc++.h>
using namespace std;

class Dungeon {
public:
    // We implement a function here, which will use a temporary
    // matrix of same size to store the minimum energy required
    // so far in bottom up manner, which will consider both possible
    // moves at every point and will take the one which will end up
    // with requiring minimum start energy.
    // As we have to start with positive energy and have to maintain
    // this at all cells we will need final energy +1 as our answer.

    int minHealth(vector<vector<int> >& dngn) {
    int iRow = dngn.size();
    int iCol = dngn[0].size();
    vector<vector<int> > temp(iRow, vector<int> (iCol, 0));

    if(dngn[iRow-1][iCol-1]<0)
        temp[iRow-1][iCol-1] = -1*dngn[iRow-1][iCol-1];
    for(int i=iRow-2 ; i>=0 ; --i)
        temp[i][iCol-1] = max(temp[i+1][iCol-1]-dngn[i][iCol-1], 0);
    for(int j=iCol-2 ; j>=0 ; --j)
        temp[iRow-1][j] = max(temp[iRow-1][j+1]-dngn[iRow-1][j], 0);
    for(int i=iRow-2 ; i>=0 ; --i) {
        for(int j=iCol-2 ; j>=0 ; --j) {
            temp[i][j] = min( max(temp[i+1][j]-dngn[i][j], 0),
                              max(temp[i][j+1]-dngn[i][j], 0));
        }
    }

    return temp[0][0]+1;
    }
};

int main() {
    int row_cnt, col_cnt;
    class Dungeon sol;
    // Input number of rows
    cin>>row_cnt;
    // Input number of cols
    cin>>col_cnt;

    vector<vector<int> > dngn(row_cnt,vector<int> (col_cnt));
    // Input dungeon matrix
    for(int i=0 ; i<row_cnt ; ++i) {
        for(int j=0 ; j<col_cnt ; ++j)
            cin >> dngn[i][j];
    }

    //Output min energy required
    cout << sol.minHealth(dngn) << endl;
}
