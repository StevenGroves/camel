// Names: Sarah Villegas and Steven Groves

#include <iostream>
#include <cstdlib>
#include <cctype>
//#include <srand>
#include <ctime>
using namespace std;

void intro();

char menu();

void drink(int& dr, int& t);

void modSpeed(int& t, int& ct, int& np, int& mi, int o, int& dr);

void fullSpeed(int& t, int& ct, int& np, int& mi, int o, int& dr);

void stop(int& ct, int& np);

void status(int mi, int dr, int np);

void reset(int& dr, int& t, int& ct);

int main()
{
    srand(time(0));
    
    char choice;
    bool done = false;
    int milesTravelled = 0, thirst = 0, camelTired = 0;
    int nativePosition = -20; 
    int drinksLeft = rand() % 5 + 8;
    int oasis = rand() % 20 + 1;
    
    intro();
    do{
        if(thirst > 4)
        {
            cout << "You are thirsty!" << endl;
        }
        if(camelTired > 5)
        {
            cout << "Your camel is getting tired!" << endl;
        }
        if(nativePosition + 15 > milesTravelled)
        {
            cout << "The natives are getting close!\n"; 
        }
        choice = menu();
    
        switch(choice){
            case 'A':
                drink(drinksLeft, thirst);
                break;
            case 'B':
                modSpeed(thirst, camelTired, nativePosition, milesTravelled, oasis, drinksLeft);
                break;
            case 'C':
                fullSpeed(thirst, camelTired, nativePosition, milesTravelled, oasis, drinksLeft);
                break;
            case 'D':
                stop(camelTired, nativePosition);
                break;
            case 'E':
                status(milesTravelled, drinksLeft, nativePosition);
                break;
            case 'Q':
                done = true;
        }
        if(thirst > 6)
        {
            cout << "You died of thirst!" << endl;
            done = true;
        }
        if(camelTired > 8)
        {
            cout << "Your camel died!" << endl;
            done = true;
        }
        if(milesTravelled >= 200)
        {
            cout << "YOU WON!\n";
            done = true;
        }
        else if(nativePosition >= milesTravelled)
        {
            cout << "They caught you!" << endl;
            done = true;
        }
        
    }while(done == false);
    cout << "GAME OVER\n";
    return 0;
}//end main

void intro()
{
    cout << "Welcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your desert trek and out run the natives." << endl;
    
    return;
}//end intro
//*******************************************************
char menu()
{
    char result;
    
    do{
        cout << "A. Drink from your canteen." << endl;
        cout << "B. Ahead moderate speed." << endl;
        cout << "C. Ahead full speed." << endl;
        cout << "D. Stop for the night." << endl;
        cout << "E. Status check." << endl;
        cout << "Q. Quit." << endl;
        cout << "Your choice? ";
        cin >> result;
        result = toupper(result);
        if(result != 'A' && result != 'B' && result != 'C' && result != 'D' && result != 'E' && result != 'Q')
        {
            cout << "Error: invalid input" << endl;
        }
    }
    while(result != 'A' && result != 'B' && result != 'C' && result != 'D' && result != 'E' && result != 'Q');
    
    return result;
}//end menu
//**********************************************
void drink(int& dr, int& t)
{
    if(dr == 0)
    {
        cout << "No drinks left!" << endl;
    }
    else
    {
        dr--;
        t = 0;
    }
    
}//end drink
//***********************************************
void modSpeed(int& t, int& ct, int& np, int& mi, int o, int& dr)
{
    int travel = rand() % 8 + 5;
    mi = mi + travel;
    cout << "You travelled " << travel << " miles." << endl;
    t++;
    ct++;
    np = np + (rand() % 8 + 7);
    
    int find = rand() % 20 + 1;
    if(find == o)
    {
        cout << "You found an oasis!\n";
        reset(dr, t, ct);
    }
    
    return;
}//end modSpeed
//************************************************
void fullSpeed(int& t, int& ct, int& np, int& mi, int o, int& dr)
{
    int travel = rand() % 11 + 10;
    mi = mi + travel;
    cout << "You travelled " << travel << " miles." << endl;
    t++;
    ct = ct + (rand() % 3 + 1);
    np = np + (rand() % 8 + 7);
    
    int find = rand() % 20 + 1;
    if(find == o)
    {
        cout << "You found an oasis!\n";
        reset(dr, t, ct);
    }
    
    return;
}//end fullSpeed
//************************************************
void stop(int& ct, int& np)
{
    ct = 0;
    cout << "The camel is happy" << endl;
    np = np + (rand() % 8 + 7);
    return;
}//end stop
//****************************************************
void status(int mi, int dr, int np)
{
    cout << "Miles Travelled: " << mi << endl;
    cout << "Drinks in Canteen: " << dr << endl;
    cout << "The natives are " << abs(mi - np) << " miles behind you" << endl;
    
    return;
}//end status

void reset(int& dr, int& t, int& ct)
{
    dr = 12;
    t = 0;
    ct = 0;
    
    return;
}
