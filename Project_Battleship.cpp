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

        if (board[rand() % 10][rand() % 10] == 'A'){

            board[rand() % 10][rand() % 10] = 'P'; 

            positionedQuantity++;
        }
    }

 }

void startBoard(char board [10][10], char mask [10][10]){

    int column ,line;

    for(line = 0;line < 10; line++){
       for(column = 0;column < 10; column++){
            board[line][column] = 'A';
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

    cout << "\n" << message << "\n\n";

    displayMap();
    for(line = 0;line < 10; line++){
        cout << line << "- ";
       for(column = 0;column < 10; column++){
            cout << " " << board[line][column];
        } 
        cout << "\n";
        
    }

}

void checks (char board [10][10],int chosenLine, int chosenColumn, int *score, string *message){

    switch(board[chosenLine][chosenColumn]){

        case 'P':
            *score = *score + 10;
            *message = "Let`s goo!!!, very good (+10 points)\n\n";
            break;
        case 'A':
            *message = "OH, you hit de sea (;-;)\n\n";
            break;
    }
}

void game (string name)
{
    
    int chosenLine, chosenColumn;
    char board [10][10];
    char mask [10][10];
    int aux = 1, score = 0;
    int attempts = 0, maxattempts = 10;
    string message = "Welcome to the game!";
 
    startBoard(board,mask);

    while(attempts < maxattempts){
        
        //displayBoard(board);
        cout << "\n";
        displayBoard(mask, message);
        cout << "\nScore: " << score;
        cout << "\nRemaining Attempts: " << maxattempts - attempts;

        cout << "\nType a line " << name << "\n";
        cin >> chosenLine;
        cout << "Type a colunm " << name << "\n";
        cin >> chosenColumn;

        checks(board,chosenLine,chosenColumn ,&score,&message);

        mask [chosenLine][chosenColumn] = board [chosenLine][chosenColumn];

        attempts++;
        system("clear");
    }   
}

void homeMenu(){

    int option = 1;
    string name;

    while(option > 0 && option < 3){

        system("clear");
        cout << "1-Jogar\n";
        cout << "2-Sobre\n";
        cout << "3-Sair\n";
        cout << "Choose a option and press Enter!\n";
        cin >> option;

        
        switch(option){
            case 1:
                cout << "What your name?\n";
                cin >> name;
                game(name);
                break;
            case 2:
                

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
