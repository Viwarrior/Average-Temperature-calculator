#pragma once
#include <bits/stdc++.h>
using namespace std;

class fenwick{
vector<int> org; //  stores original array of values
vector<int> tree; // stores Binary index tree
int sot;// stores size

public:
    fenwick(vector<int> orgi){
    this->org = orgi;
    tree.insert(tree.begin(), 0);
    org.insert(org.begin(), 0); // to make 1-indexed
   this->sot= org.size();
    // building the tree
    for(int i=1; i<sot; i++){
    int s = 0;
            for(int j = i- (-i&i)+1; j<=i;j++){
                s+= org[j];
            }
            tree.push_back(s);
        }
    }

    void show(){
        cout<<"\n";
    for(int i=1; i<sot; i++) cout<<org[i]<<" ";
    }

    int halfRange(int);
    int sRange(int, int);
    void update(int, int);
};

int fenwick::halfRange(int index){
// returns sum from start index to a
    int  s= 0;
    while(index>=1){
        s+= tree[index];
        index -= -index&index;
    }
    return s;
}

int fenwick::sRange(int a, int b){
    //returns sum between a and b position in tree (inclusive)
return halfRange(b)-halfRange(a-1);
}

void fenwick::update(int pos, int value){

    int d = value-org[pos];
    org[pos] = value;
    while(pos<sot){
        tree[pos] += d;
        pos+= -pos&pos;
    }
}

