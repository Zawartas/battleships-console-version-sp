#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

char opcje[] = { '*', 'X', ' ' , 'z'};
static int hits = 0;

struct pole {
char znak = opcje [2];
bool zajete = false;
bool zakryte = true;        //wszystko w standardzie zakrywamy
};

void print (pole t[][10]) {

    for (int j = 0; j < 11; j++){
            cout << setw(3) << j;}
    cout << endl;

    for (int i = 0; i < 10; i++){
        cout << setw(3) << i+1;
        for (int j = 0; j < 10; j++){
            if (t[i][j].zakryte == true)
                cout << setw(3) << opcje[2];
            else
                cout << setw(3) << t[i][j].znak;}
        cout << endl;
        }

}

void zajete_kom (pole t[][10]){ //funkcja ktora dostaje tablice ze statkiem i dookoła kazdego X robi zajete pola
    int k, m;
    for (k = 0; k < 10; k++){
        for (m = 0; m < 10; m++){
            if (t[k][m].znak == opcje[1]){
                int a = k - 1;
                int b = m - 1;
                for (int i = 0 ; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        if (a + i >= 0 && b + j >= 0 && a + i <= 9 && b + j <= 9){
                        t[a + i][b + j].zajete = true;
                        }
                    }
                }
            }

        }
    }
}

void strzal (pole t[][10]){ //poki co dziala o tyle ze w dany punkt wpisuje '*'
int x, y;
print(t);
cin >> x >> y;
if (t[x - 1][y - 1].znak == opcje[1]){
    cout << "HIT !" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    hits++;
    t[x - 1][y - 1].zakryte = false;
    t[x - 1][y - 1].znak = opcje[1];
}
else{
    cout << "MISSED !" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    t[x - 1][y - 1].zakryte = false;
    t[x - 1][y - 1].znak = opcje[0];
}
system("cls");
}

void losowy_statek_1 (pole t[][10]){
    int x, y;
    do {
        x = rand() % 10;
        y = rand() % 10;
    }
    while (t[x][y].zajete == true);

        t[x][y].znak = opcje[1];
        //t[x][y].zakryte = false;

zajete_kom(t);
}

void losowy_statek_2 (pole t[][10]){
    int x = 0, y = 0, k = 0;

    do {
        x = rand() % 10;
        y = rand() % 10;
    }
    while (((t[x][y].zajete || t[x+1][y].zajete) || ( x > 8))
           || ((t[x][y].zajete || t[x][y+1].zajete) || ( y > 8)));

        if (!t[x][y].zajete && !t[x+1][y].zajete)
            k++;
        if (!t[x][y].zajete && !t[x][y+1].zajete)
            k++;

        int l = 1 + rand() % k;

        switch(l){

        case 1:
            t[x][y].znak = t[x+1][y].znak = opcje[1];
            //t[x][y].zakryte = t[x+1][y].zakryte = false;
            break;
        case 2:
            t[x][y].znak = t[x][y+1].znak = opcje[1];
            //t[x][y].zakryte = t[x][y+1].zakryte = false;
            break;
        }
    zajete_kom(t);

}

void losowy_statek_3 (pole t[][10]){
    int x = 0, y = 0, k = 0;

    do {
        x = rand() % 10;
        y = rand() % 10;
    }
    while (((t[x][y].zajete || t[x+1][y].zajete || t[x+2][y].zajete) || ( x > 7))
           || ((t[x][y].zajete || t[x][y+1].zajete || t[x][y+2].zajete) || ( y > 7)));

        if (!t[x][y].zajete && !t[x+1][y].zajete && !t[x+2][y].zajete)
            k++;
        if (!t[x][y].zajete && !t[x][y+1].zajete && !t[x][y+2].zajete)
            k++;

        int l = 1 + rand()%k;

        switch(l){

        case 1:
            t[x][y].znak = t[x+1][y].znak = t[x+2][y].znak = opcje[1];
            //t[x][y].zakryte = t[x+1][y].zakryte = t[x+2][y].zakryte = false;
            break;
        case 2:
            t[x][y].znak = t[x][y+1].znak = t[x][y+2].znak = opcje[1];
            //t[x][y].zakryte = t[x][y+1].zakryte = t[x][y+2].zakryte = false;
            break;
        }
    zajete_kom(t);

}

void losowy_statek_4 (pole t[][10]){
    //powinien być losowany jako pierwszy
    int x = 0, y = 0, k = 0;

    do {
        x = rand() % 10;
        y = rand() % 10;
    }
    while (((t[x][y].zajete || t[x+1][y].zajete || t[x+2][y].zajete || t[x+3][y].zajete) || ( x > 6))
           || ((t[x][y].zajete || t[x][y+1].zajete || t[x][y+2].zajete || t[x][y+3].zajete) || ( y > 6)));

        if (!t[x][y].zajete && !t[x+1][y].zajete && !t[x+2][y].zajete && !t[x+3][y].zajete)
            k++;
        if (!t[x][y].zajete && !t[x][y+1].zajete && !t[x][y+2].zajete && !t[x][y+3].zajete)
            k++;

        int l = 1 + rand()%k;

        switch(l){

        case 1:
            t[x][y].znak = t[x+1][y].znak = t[x+2][y].znak = t[x+3][y].znak = opcje[1];
            //t[x][y].zakryte = t[x+1][y].zakryte = t[x+2][y].zakryte = t[x+3][y].zakryte = false;
            break;
        case 2:
            t[x][y].znak = t[x][y+1].znak = t[x][y+2].znak = t[x][y+3].znak = opcje[1];
            //t[x][y].zakryte = t[x][y+1].zakryte = t[x][y+2].zakryte = t[x][y+3].zakryte = false;
            break;
        }
    zajete_kom(t);
}



int main (){
    srand(time(nullptr));

    pole tablicaG[10][10];

    losowy_statek_4(tablicaG);

    for (int i = 0; i < 2; i++)
        losowy_statek_3(tablicaG);

    for (int i = 0; i < 3; i++)
        losowy_statek_2(tablicaG);

    for (int i = 0; i < 4; i++)
        losowy_statek_1(tablicaG);

int vol = 0;
do {
strzal(tablicaG);
vol++;   //działa
}while (hits < 20);

print(tablicaG);
    cout << "Victory in " <<vol<< " moves!"<< endl << endl;

    this_thread::sleep_for(chrono::seconds(3));
return 0;
}
