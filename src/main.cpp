//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Nida Nur Efe
//---Student Number: 150220025
//--------------------------//

#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it


string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
void mainMenu();player characterCreate(string, int);

void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);



int main(int argc, char* argv[]) {
    // system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);
    string* pokemonNames = readPokemonNames(argv[2]);


    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    int menuChoice;

    while (true) {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};

string* readEnemyNames(const char* argv){
    fstream f;
    f.open(argv, ios::in);
    string line;
    getline(f, line);
    int arrSize = stoi(line);
    string *enemyArray = new string[arrSize];
    int i = 0;
    while(i< arrSize && getline(f, enemyArray[i]))
        i++;
    f.close();
    NAME_COUNTER = i + 1;
    return enemyArray;
};


string* readPokemonNames(const char* argv){
    fstream f;
    f.open(argv, ios::in);
    string line;
    getline(f, line);
    int arrSize = stoi(line);
    string *pokemonArray = new string[arrSize];
    int i = 0;
    while(i< arrSize && getline(f, pokemonArray[i]))
        i++;
    f.close();
    POK_COUNTER = i + 1;
    return pokemonArray;
};

player characterCreate(string playerName, int pokemonChoice) {
    string pokemonName;
    if (pokemonChoice == 1) {
        pokemonName = "Bulbasaur";
    }
    else if (pokemonChoice == 2) {
        pokemonName = "Charmender";
    }
    else if (pokemonChoice == 3) {
        pokemonName = "Squirtle";
    }
    else {
        cout << "Invalid pokemon!" << endl;
    }

    pokemon* newPokemon = new pokemon(pokemonName, 20);
    player newPlayer(playerName, newPokemon);
    delete newPokemon;
    return newPlayer;
};



void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};


void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames) {
    int i = rand() % 5; //Creating a random number between 0 and 5 to select pokemon and enemy names randomly.

    pokemon playerPokemon(pokemonNames[i], 20);
    pokemon enemyPokemon(pokemonNames[i], 10);

    string enemyName = enemyNames[i];
    enemy newEnemy(enemyName, &enemyPokemon);

    newPlayer->playerPokedex.updatePokedex(enemyPokemon);
    int fightChoice;
    cout << "You encountered with " << newEnemy.getName() << 
            " and his/hers pokemon " << newEnemy.getPokemon().getName() << "\n";
    cout << newEnemy.getPokemon().getName() << " Health: " << 
    newEnemy.getPokemon().getHpValue() << " Attack: " << newEnemy.getPokemon().getAtkValue() << endl;


    while (playerPokemon.getHpValue() > 0 && enemyPokemon.getHpValue() > 0) {
        cout << "1- Fight" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: "; cin >> fightChoice;

        if(fightChoice == 1){
            enemyPokemon.setHpValue(enemyPokemon.getHpValue() - playerPokemon.getAtkValue());
            playerPokemon.setHpValue(playerPokemon.getHpValue() - enemyPokemon.getAtkValue());
            cout << "Your Pokemons Health: " << playerPokemon.getHpValue() << endl;
            cout << newEnemy.getPokemon().getName() << " Pokemons Health: " << enemyPokemon.getHpValue() << endl;

        }
        else if (fightChoice == 2) {
            cout << "You runaway from the battle!" << endl;
            return;
        }        
        else {
            cout << "Invalid choice." << endl;
        }

    }


    if (playerPokemon.getHpValue() <= 0) {
        cout << "You lost!";
        return;
    }
    else if (enemyPokemon.getHpValue() <= 0) {  
        cout << "You Won!";
        newPlayer->battleWon();
        return;
    }
    return;
}


void catchPokemon(player* newPlayer, string* pokemonNames){
    int i = rand() % 5;

    pokemon *newPokemon = new pokemon(pokemonNames[i], 10);
    newPlayer->playerPokedex.updatePokedex(*newPokemon);
    cout << "You encountered with " << newPokemon->getName() << 
    " Health: " << newPokemon->getHpValue() << " Attack: " << 
    newPokemon->getAtkValue() << endl;
    int choice; 
    cout << "1- Fight" << endl;
    cout << "2- Runaway" << endl;
    cout << "Choice: "; cin >> choice;
    if(choice == 1){
        cout << "You catch " << newPokemon->getName() << endl;
        newPlayer->catchPokemon();
        delete newPokemon; 
        return;
    }
    else if(choice == 2){
        cout << "You runaway!" << endl;
        delete newPokemon; 
        return;
    }
    return;
};

