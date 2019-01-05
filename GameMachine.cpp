//
// Created by Britta on 03.12.2018.
//

#include <iostream>
#include "GameMachine.h"

Player *GameMachine::playAGame(Player *playerA, Player *playerB)
{
    this->currentPlayer = playerA;
    this->waitingPlayer = playerB;
    this->playingField = new PlayingField();
    while (true)
    {
        this->currentPlayer->play(this->playingField);
        if (this->playingField->proofWinner())
        {
            if (this->print)
            {
                this->playingField->print();
                std::cout << "Player " << this->currentPlayer->name << " wins!" << std::endl;
            }
            return this->currentPlayer;
        }
        if (this->playingField->isFull())
        {
            if (this->print)
            {
                std::cout << "Remis!" << std::endl;
            }
            return 0;
        }
        this->switchPlayer();
    }
}

void GameMachine::switchPlayer()
{
    Player *lastPlayer = this->currentPlayer;
    this->currentPlayer = this->waitingPlayer;
    this->waitingPlayer = lastPlayer;
}
