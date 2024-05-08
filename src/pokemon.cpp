//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Nida Nur Efe
//---Student Number: 150220025
//--------------------------//

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/pokemon.h"

using namespace std;

//----------POKEMON CLASS----------------//

//Default constructor
pokemon::pokemon(){
    this->name = "";
    this->hpValue = 100;
    this->atkValue = 20;
}

pokemon::pokemon(string name, int attack_value){
    this->name = name;
    this->atkValue = attack_value;
    this->hpValue = 100;
}

//Copy constructor
pokemon::pokemon(const pokemon& originalPokemon) 
        : name{originalPokemon.name}, 
        hpValue{originalPokemon.hpValue},
        atkValue{originalPokemon.atkValue}
{}

//Getters
int pokemon::getAtkValue() const{
    return this->atkValue;
}

int pokemon::getHpValue() const{
    return this->hpValue;
}

string pokemon::getName() const{
    return this->name;
}

void pokemon::setHpValue(int newHp){
    this->hpValue = newHp;
}

void pokemon::setName(string name){
    this->name = name;
}


//----------POKEDEX CLASS----------------//

//Constructor
pokedex::pokedex(){
    this->value = 0;
}

void pokedex::printPokedex() const {
    for(pokemon p : pokedexArray){
        if(p.getName() != "")
            std::cout << p.getName() << '\n';
    }
}

void pokedex::updatePokedex(pokemon newP){
    int i = 0;
    bool found = false;
    int target = 0;
    for (pokemon p : pokedexArray) {
        i++;
        if (newP.getName() == this->pokedexArray[i].getName()) {
            found = true;
            cout << "Np Duplicates are allowed!" << endl;
            break;
        }
        else if (this->pokedexArray[i].getName() == "") {
            target = i;
            break;
        }
    }

    if (found == false) {
        pokemon newpoke(newP);
        this->pokedexArray[target] = newpoke;
        // cout << "New Pokemon added into the Pokedex!" << endl;
    }
}


//Getters
pokemon* pokedex::getPokedexArray(){
    return this->pokedexArray;
}

int pokedex::getValue() const{
    return this->value;
}



//----------PLAYER CLASS----------------//

player::player() {
    this->name = "Ash";
    this->pokemonNumber = 0;
    this->pokeballNumber = 0;
    this->badgeNumber = 0;
    this->playerPokemon = pokemon();
    this->playerPokedex = pokedex();

}

player::player(string name, pokemon* playerPokemon){
    this->name = name;
    this->playerPokemon = *(playerPokemon);
    this->pokemonNumber = 0;
    this->pokeballNumber = 0;
    this->badgeNumber = 0;
    this->playerPokedex = pokedex();
}

int player::showPokemonNumber() const{
    return this->pokemonNumber;
}

int player::showPokeballNumber() const{
    return this->pokeballNumber;
}

int player::showBadgeNumber() const{
    return this->badgeNumber;
}

pokemon player::getPokemon() const{
    return this->playerPokemon;
}

void player::setPokeballNumber(int pok){
    this->pokeballNumber = pok;
}


void player::battleWon(){
    this->badgeNumber = this->badgeNumber + 1;
    this->pokeballNumber = this->pokeballNumber + 3;
}

void player::catchPokemon(){
    this->pokemonNumber = this->pokemonNumber + 1;
    this->pokeballNumber = this->pokeballNumber - 1;
}



//----------ENEMY CLASS----------------//

//Default constructor
enemy::enemy() {
    this->name = "";
    this->enemyPokemon = pokemon();
}

enemy::enemy(string name, pokemon* enemyPokemon){
    this->name = name;
    this->enemyPokemon = *(enemyPokemon);
}

pokemon enemy::getPokemon() const{
    return this->enemyPokemon;
}

string enemy::getName() const{
    return this->name;
}

