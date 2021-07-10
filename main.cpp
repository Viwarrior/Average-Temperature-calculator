#include <bits/stdc++.h>
#include "fenwick.h"
using namespace std;


string enterFile(){
    // read the filename from the user
string s;

cout<<"\t\t\t\t<Average Temperature Calculator>\n\n";
cout<<"Enter file name to process: ";
cin>>s;
cout<<"\n\n";
return s;
}


vector<int> split(string s, string del=" "){
    // split function implementation for c++
vector<int> result; // stores the result
int start = 0;
int temp;
int last = s.find(del,start);
    while(last!= -1){
    temp = stoi(s.substr(start,last - start));
    result.push_back(temp);
        start = last+1;
        last = s.find(del,start);
    }
    result.push_back(stoi(s.substr(start, last-start)));
    return result;

}

fenwick* processFile(string fileName){
/*process file and return fenwick object*/

ifstream f(fileName);
if(f.is_open() == false){
        cout<<"\n File doesn't exists or ran into error!";
        exit(-1);
        }
string readChar;
vector<int> streamTemp;
vector<int> tempv;
// read numbers from the file
while(getline(f,readChar)){
    tempv  = split(readChar);
    streamTemp.insert(streamTemp.end(), tempv.begin(), tempv.end());
    }
f.close();

//create and initialize fenwick object

fenwick *obj = new fenwick(streamTemp);
return obj;


}




void mainMenu(fenwick *obj){
    // shows main menu
    cout<<"\n\n";
cout<<"Input temperatures are (1-indexed):\n";
obj->show();
cout<<"\n\n";
int l,r,pos,value;
int choice;
float avgtemp;

//perform queries until user exits
do{
cout<<"\n";
cout<<"----------------------------------------------------------------------\n";
cout<<"\n\n";
cout<<"1. Enter range\n";
cout<<"2. Update value\n";
cout<<"3. Exit\n";
cin>>choice;
    switch(choice){
case 1: cout<<"\nEnter range (inclusive): \n"; cin>>l; cin>>r; avgtemp = (float)obj->sRange(l,r)/(r-l+1); cout<<"\nAverage temperature is: "<<avgtemp; break;
case 2: cout<<"\nEnter position and value to update: \n"; cin>>pos; cin>>value; obj->update(pos,value); cout<<"Updated Successfully! Updated array - "; obj->show(); break;
    case 3: cout<<"\nThanks for using our software!\n";break;
    default: cout<<"\nchoose 1 or 2!\n";
    }
    cout<<"\n\n";
}while(choice!=3);
free(obj);
}




int main()
{
 fenwick *obj= processFile(enterFile());
 mainMenu(obj);

    return 0;
}
