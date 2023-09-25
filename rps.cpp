
#include <iostream>

int main() 
{
    // std::string player_one ("SCISSOR");
    // std::string player_two ("ROCK");

    std::string player_one;
    std::cout << "Play rock paper or scissors: ";
    std::cin >> player_one;
    std::string player_two;
    std::cout << "Play rock paper or scissors: ";
    std::cin >> player_two;

    if (player_one.empty() || player_two.empty()) {
        std::cout << "Please enter 'ROCK', 'PAPER' or 'SCISSOR'";
    } else if(player_one == "ROCK" && player_two == "SCISSOR"){
        std::cout << "PLAYER ONE WINS"; 
    } else if (player_one == "ROCK" && player_two == "PAPER"){
        std::cout << "PLAYER TWO WINS";
    } else if(player_one == "PAPER" && player_two == "SCISSOR"){
        std::cout << "PLAYER TWO WINS"; 
    } else if (player_one == "PAPER" && player_two == "ROCK"){
        std::cout << "PLAYER ONE WINS";
    } else if (player_one == "SCISSOR" && player_two == "ROCK"){
        std::cout << "PLAYER TWO WINS"; 
    } else if (player_one == "SCISSOR" && player_two == "PAPER"){
        std::cout << "PLAYER ONE WINS";
    } else { 
        std::cout << "TIE";
    }

    return 0;
}