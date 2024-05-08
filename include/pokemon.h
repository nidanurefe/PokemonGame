//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Nida Nur Efe
//---Student Number: 150220025
//--------------------------//

#ifndef _H
#define _H

// If header files are not defined, define.

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


class pokemon{
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        //constructors
        pokemon();
        pokemon(string, int);
        pokemon(const pokemon&);

        //getters:
        int getHpValue() const;
        int getAtkValue() const;
        string getName() const;

        //setters
        void setHpValue(int);
        void setName(string);
        
       
};

class pokedex{
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        //constructor
        pokedex();

        //methods
        void updatePokedex(pokemon);
        void printPokedex() const;

        //getters
        pokemon* getPokedexArray();
        int getValue() const;
       
};

class player{
    private:
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;

        //constructors
        player();
        player(string, pokemon*);

        //getters
        int showPokemonNumber() const;
        int showPokeballNumber() const;
        int showBadgeNumber() const;
        pokemon getPokemon() const;

        //setters
        void setPokeballNumber(int);

        //methods
        void battleWon();
        void catchPokemon();

        
};

class enemy{
    private:
        string name;
        pokemon enemyPokemon;
    public:
    
        //constructors
        enemy(); 
        enemy(string, pokemon*);

        //getters 
        pokemon getPokemon() const;
        string getName() const;

        
};

#endif