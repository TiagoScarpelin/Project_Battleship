#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;
 
 void boat (char board [10][10]){

    int i, amount = 10;
    int positionedQuantity = 0;

    while(positionedQuantity < amount){

        if (board[rand() % 10][rand() % 10] == 'W'){

            board[rand() % 10][rand() % 10] = 'B'; 

            positionedQuantity++;
        }
    }

 }

void startBoard(char board [10][10], char mask [10][10]){

    int column ,line;

    for(line = 0;line < 10; line++){
       for(column = 0;column < 10; column++){
            board[line][column] = 'W';
            mask[line][column] = '*';
        } 
    }

    boat(board);

}

void displayMap(){
int i;

    cout << "    ";

    for(i = 0;i < 10;i++){
        
        cout << i << " ";
    }

    cout << "\n";
    cout << "    ";

    for(i = 0;i < 10;i++){
        
        cout << "| ";
    }

    cout << "\n\n";

}


void displayBoard(char board [10][10], string message){

    int column ,line;
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };

    cout << "\n" << message << "\n\n";

    displayMap();
    for(line = 0;line < 10; line++){
        cout << line << "- ";
       for(column = 0;column < 10; column++){

            switch (board[line][column]){
                case 'W':
                    cout << " " <<  blue << board[line][column] << normal;
                    break;
                case 'B':
                    cout << " " << red << board[line][column] << normal;
                    break;
                default:
                    cout << " " << normal << board[line][column];   
                    break;
            }

        } 
        cout << "\n";
        
    }

}

void checks (char board [10][10],int chosenLine, int chosenColumn, int *score, string *message){

    switch(board[chosenLine][chosenColumn]){

        case 'B':
            *score = *score + 10;
            *message = "Let`s goo!!!, very good (+10 points)\n";
            break;
        case 'W':
            *message = "OH, you hit de sea (;-;)\n\n";
            break;
    }
}

void About(){

    system ("clear");
    cout <<            "Game Information\n\n";
    cout << "---------------------------------------" << endl
         << "|                                     |" << endl
         << "|               ABOUT                 |" << endl
         << "|                                     |" << endl
         << "|          Game produced by:          |" << endl
         << "|                                     |" << endl
         << "|   Tiago Gimenes Scarpelin           |" << endl
         << "|                                     |" << endl
         << "|       Produced on the date of:      |" << endl
         << "|                                     |" << endl
         << "|   13/09/2022                        |" << endl
         << "|                                     |" << endl
         << "|         With the help of:           |" << endl
         << "|                                     |" << endl
         << "|    Teacher John's Course at Udemy:  |" << endl
         << "|                                     |" << endl
         << "|  Link:https://www.udemy.com/course/ |" << endl
         << "|  curso-completo-de-linguagem-c-     |" << endl
         << "|  iniciante-ao-avancado/             |" << endl
         << "|                                     |" << endl
         << "---------------------------------------" << endl;


    system("read -p 'Press enter to return to home menu...' var");
}


void game (string name)
{
    int riskyLine [10];
    bool test = false;
    int riskyColumn [10];
    int i,j=0;
    int chosenLine, chosenColumn;
    char board [10][10];
    char mask [10][10];
    int aux = 1, score = 0;
    int attempts = 0, maxattempts = 10;
    string message = "Welcome to the game!";
 
    startBoard(board,mask);

    while(attempts < maxattempts){
        system("clear");
        cout << "\n";
        displayBoard(mask, message);
        cout << "\nScore: " << score;
        cout << "\nRemaining Attempts: " << maxattempts - attempts;

        cout << "\nType a line " << name << "\n";
        cin >> chosenLine;
        cout << "Type a colunm " << name << "\n";
        cin >> chosenColumn;

        for(i=0;i<=11;i++){

            if(riskyColumn[i] == chosenColumn && riskyLine[i] == chosenLine){
                test = true;
            }
        }

        
        if((chosenLine > -1 && chosenLine < 11) && (chosenColumn > -1 && chosenColumn < 11) && (test == false)){
            
            checks(board,chosenLine,chosenColumn ,&score,&message);
            mask [chosenLine][chosenColumn] = board [chosenLine][chosenColumn];
            
            riskyLine[attempts] = chosenLine;
            riskyColumn[attempts] = chosenColumn;
            
            attempts++;
        }else{

            cout << "\nInvalid position, or repeated position. Try again!";
            test = false;
        }
    }   
}

void homeMenu(){

    int option = 1;
    string name;

    while(option > 0 && option < 3){

        system("clear");
        cout << "1-Play\n";
        cout << "2-About\n";
        cout << "3-Exit\n";
        cout << "Choose a option and press Enter!\n";
        cin >> option;

        
        switch(option){
            case 1:
                cout << "What your name?\n";
                cin >> name;
                game(name);
                break;
            case 2:
                About();
                break;
        }

    }
}

int main()
{
    srand( (unsigned)time (NULL));
    homeMenu();

    return 0;
}
