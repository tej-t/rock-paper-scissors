//
//  main.cpp
//  RPS
//
//  Created by Tej Thambi on 7/5/22.
//

#include <iostream>
#include "hand.h"
using namespace std;

hand* getWinner(string p1h, hand* p1, string p2h, hand* p2) {
    if(p1h == p2h) {
        return nullptr;
    }
    if (p1h == "rock") {
        if(p2h == "scissors") {
            return p1;
        } else if (p2h == "paper") {
            return p2;
        }
    }
    if (p1h == "paper") {
        if(p2h == "scissors") {
            return p1;
        } else if (p2h == "rock") {
            return p2;
        }
    }
    if (p1h == "scissors") {
        if(p2h == "paper") {
            return p1;
        } else if (p2h == "rock") {
            return p2;
        }
    }
    return nullptr;
}

int main() {
    //Creating instances of objects
    hand p1, p2, *winner = nullptr;
    string name, choice;
    //Rules
    cout << "Welcome to Rock Paper Scissors!" << endl;
    cout << "The rules of this game are slightly different: " << endl;
    cout << "Each player initially plays two hands, in which they select from rock, paper, or scissors" << endl;
    cout << "The two players then see eachother's hands, and decide which hand to keep" << endl;
    cout << "In the end, each player will have one hand. rock beats scissors, scissors beats paper, and paper beats rock" << endl;
    //Beginning the game
    cout << "Player 1, enter your name: ";
    getline(cin, name);
    cin.ignore(10000, '\n');
    p1.setName(name);
    
    cout << "Player 2, enter your name: ";
    getline(cin, name);
    cin.ignore(10000, '\n');
    p2.setName(name);
    
    cout << p1.getName() << "'s turn!" << endl;
    
    cout << p1.getName() <<  ", what will you play for your right hand?" << endl;
    cout << "Enter rock, paper, or scissors." << endl;
    cin >> choice;
    while(!(choice == "rock" || choice == "paper" || choice == "scissors")) {
        cout << "Please enter rock, paper, or scissors." << endl;
        cin >> choice;
    }
    p1.setRight(choice);
    
    cout << "What will you play for your left hand?" << endl;
    cout << "Enter rock, paper, or scissors." << endl;
    cin >> choice;
    while(!(choice == "rock" || choice == "paper" || choice == "scissors")) {
        cout << "Please enter rock, paper, or scissors." << endl;
        cin >> choice;
    }
    p1.setLeft(choice);
    
    cout << p2.getName() << "'s turn!" << endl;
    
    cout << p2.getName() <<  ", what will you play for your right hand?" << endl;
    cout << "Enter rock, paper, or scissors." << endl;
    cin >> choice;
    while(!(choice == "rock" || choice == "paper" || choice == "scissors")) {
        cout << "Please enter rock, paper, or scissors." << endl;
        cin >> choice;
    }
    p2.setRight(choice);
    
    cout << "What will you play for your left hand?" << endl;
    cout << "Enter rock, paper, or scissors." << endl;
    cin >> choice;
    while(!(choice == "rock" || choice == "paper" || choice == "scissors")) {
        cout << "Please enter rock, paper, or scissors." << endl;
        cin >> choice;
    }
    p2.setLeft(choice);
    
    cout << p1.getName() << " played " << p1.getLeft() << " and " << p1.getRight() << "!" << endl;
    cout << p2.getName() << " played " << p2.getLeft() << " and " << p2.getRight() << "!" << endl;
    
    cout << p1.getName() << "'s second turn!" << endl;
    cout << "Which hand do you want to keep, left (" << p1.getLeft() << ") or right (" << p1.getRight() << ") ?" << endl;
    cin >> choice;
    while(!(choice == "right" || choice == "left")) {
        cout << "Please enter right or left." << endl;
        cin >> choice;
    }
    if(choice == "right") {
        p1.setFinal(p1.getRight());
    } else if(choice == "left") {
        p1.setFinal(p1.getLeft());
    }
    
    cout << p2.getName() << "'s second turn!" << endl;
    cout << "Which hand do you want to keep, left (" << p2.getLeft() << ") or right (" << p2.getRight() << ") ?" << endl;
    cin >> choice;
    while(!(choice == "right" || choice == "left")) {
        cout << "Please enter right or left." << endl;
        cin >> choice;
    }
    if(choice == "right") {
        p2.setFinal(p2.getRight());
    } else if(choice == "left") {
        p2.setFinal(p2.getLeft());
    }
    
    cout << p1.getName() << " played " << p1.getFinal() << " and " << p2.getName() << " played " << p2.getFinal() << "!" << endl;
    //FIND WINNER AND SET WINNER POINTER
    winner = getWinner(p1.getFinal(), &p1, p2.getFinal(), &p2);
    if(winner == nullptr) {
        cout << "It is a tie!" << endl;
    } else {
        cout << "The winner is " << winner->getName() << "!" << endl;
    }
    cout << "Thank you for playing!" << endl;
    return 0;
}
