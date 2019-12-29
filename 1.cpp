#include<bits/stdc++.h>
using namespace std;

class Reach {
public:
    // We implement a function here, which will do BFS on all
    // the possible paths that can be taken from starting point
    // and are valid to check that means it falls in the
    // rectangle formed by source and destination.
    // source - start point
    // dest - final point to check

    bool reachable(pair<int, int>& source, pair<int,int>& dest) {
        queue<pair<int,int> > qu;
        qu.push(source);
        while(!qu.empty()) {
            pair<int,int> pr = qu.front();
            qu.pop();
            if(pr.first == dest.first && pr.second == dest.second)
                return true;
            if(pr.first+pr.second <= dest.first)
                qu.push(make_pair(pr.first+pr.second,pr.second));
            if(pr.first+pr.second <= dest.second)
                qu.push(make_pair(pr.first,pr.first+pr.second));
        }
        return false;
    }
};

int main() {
    int sx,sy,tx,ty;
    class Reach check;
    pair<int,int> src, dst;

    // Input source point
    cin>>sx>>sy;

    // Input destination point to check
    src = make_pair(sx, sy);
    cin>>tx>>ty;

    dst = make_pair(tx, ty);
    if (check.reachable(src, dst))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}
