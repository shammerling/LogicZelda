#include <iostream>
#include <vector>

using namespace std;

void printmap(vector< vector <string> > map);
void move(vector< vector <string> > &map, string s, int &posX, int &posY, int size);

int main (){
    int posX=0;
    int posY=0;
    int size = 5;
    string direction = " ";
    vector< vector<string> > map;
    
    map.resize( size, vector <string> (size, "0"));
    map [posX][posY] = "X";
    printmap(map);
    cout << "use WASD to move, you are X, Q to quit" << endl;
    while (direction != "Q"){
        cin >> direction;
        move(map, direction, posX, posY, size);
        
        printmap(map);
    }
    return 0;
    
}

void printmap(vector< vector <string> > map){
    
    int size = map.size();
    
    for (int i = 0; i < size; i++){
        for (int j=0; j < size; j++){
            cout << map [i][j] << '\t';
        }
        cout << endl;
    }
    
    
}

void move(vector< vector <string> > &map, string s, int &posX, int &posY, int size){
    map[posX][posY] = "0";
    if ( s == "W"){
        posX -= 1;
    }
    else if ( s == "S"){
        posX +=1;
    }
    else if ( s == "A"){
        posY -=1;
    }
    else if ( s == "D"){
        posY +=1; 
    }
    if (posX < 0){
        posX = size-1;
    }
    if (posX > size-1){
        posX = 0;
    }
    if (posY < 0){
        posY = size-1;
    }
    if (posY > size-1){
        posY = 0;
    }
    
    map[posX][posY] = "X";
}

