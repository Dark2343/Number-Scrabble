// Date: 7/3/2022
// This is Number Scrabble.
// The premise of the game is: 2 players take turns each choosing a set of numbers that the sum of 3 of them should = 15.
// The players choose from a list of numbers from 1 to 9, any number chosen is removed from the main list.
// If all the numbers in the set have been chosen and none of the players meet the winning rule, the game ends in a draw.


#include <bits/stdc++.h>

using namespace std;

// This is a function for displaying the main list of numbers
void displaylist(list<int> g)
{
    list<int>::iterator it;
    cout << "|";
    for (it = g.begin(); it != g.end(); it++)
        cout << *it << '|';
    cout << "\n";
}

// This is a function for displaying and sorting the player's list of numbers
void sort(vector<int> v){
    sort(v.begin(),v.end());
    cout << "\nYour list of numbers: |";
    for(auto x : v) {
            cout << x << "|";
    }
}

// This is a function for checking to see if the sum if 3 numbers in a player's list is = 15
bool find3numbers(vector<int> u, int size , int sum){
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
               if(u[i] + u[j] + u[k] == sum){
                   cout << "You Win\n";
                   cout << "Winning combination is: {" << u[i] << "," << u[j] << "," << u[k] << "}\n";
                   return true;
               }
            }
            
        }
        
    }
    return false;
}

int main(){

    list<int> numbers;
    vector<int>player_1_list,player_2_list;
    int score_1 = 0, score_2 = 0, player_1, player_2;
    player_1_list = {};
    player_2_list = {};
    numbers ={1,2,3,4,5,6,7,8,9};
    
    while (numbers.size() != 0)
    {
        // Player 1
        if (numbers.size() != 0)
        {   
            //This is to check if the input is valid
            bool valid_input = false;
            while (!valid_input)
            {
                cout << "Available numbers are: ";
                displaylist(numbers);
                cout << "Player 1, choose a number from the list\n";
                cin >> player_1;
                bool found = (find(numbers.begin(), numbers.end(), player_1) != numbers.end());
                if (cin.fail() || !found)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid, Please enter a correct input\n"  << endl;
                }
                else{
                    numbers.remove(player_1);
                    valid_input = true;
                }
            }

            //This is where the input of the player is taken and added to his list
            player_1_list.push_back(player_1);
            sort(player_1_list);
            score_1 += player_1;
            cout << "\nYour score: "<< score_1 << endl;
            cout << "\n";
            int size_1 = player_1_list.size();

            // This is to check if a player has the correct sum and tell them if they won
            if (find3numbers(player_1_list,size_1,15)){
                cout << "Player 1 Wins\n";
                exit(0);
            }

        }
         // Player 2
         if (numbers.size() != 0)
        {   
            //This is to check if the input is valid
            bool valid_input = false;
            while (!valid_input)
            {
                cout << "Available numbers are: ";
                displaylist(numbers);
                cout << "Player 2, choose a number from the list\n";
                cin >> player_2;
                bool found = (find(numbers.begin(), numbers.end(), player_2) != numbers.end());
                if (cin.fail() || !found)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid, Please enter a correct input\n"  << endl;
                }
                else{
                    numbers.remove(player_2);
                    valid_input = true;
                }
            }

            //This is where the input of the player is taken and added to his list
            player_2_list.push_back(player_2);
            sort(player_2_list);
            score_2 += player_2;
            cout << "\nYour score: "<< score_2 << endl;
            cout << "\n";
            int size_2 = player_2_list.size();

            // This is to check if a player has the correct sum and tell them if they won
            if (find3numbers(player_2_list,size_2,15)){
                cout << "Player 2 Wins\n";
                exit(0);
            }

        }
         
    }    
    // This is displayed if nobody manages to win
    cout << "Draw\n";
}
