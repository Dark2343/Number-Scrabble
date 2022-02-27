# Date: 24/2/2022
# This is Number Scrabble.
# The premise of the game is: 2 players take turns each choosing a set of numbers that the sum of 3 of them should = 15.
# The players choose from a list of numbers from 1 to 9, any number chosen is removed from the main list.
# If all the numbers in the set have been chosen and none of the players meet the winning rule, the game ends in a draw.

from itertools import combinations

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]

score_1 = 0
score_2 = 0
player_1_list = []
player_2_list = []

while len(numbers) != 0:

    # Player 1
    if len(numbers) != 0:

        # This is to check if the input is valid
        valid_input = False
        while not valid_input:

            try:
                print(f'Available numbers:{numbers}\n')
                player_1 = int(input("Player 1, choose a number from the list\n"))
                numbers.remove(player_1)
                valid_input = True
            except ValueError:
                print("Invalid, please choose another number\n")

        # This is where the input of the player is taken and added to his list
        player_1_list.append(player_1)
        print(f'Your list of numbers:{player_1_list}')
        score_1 += player_1
        print(f'Your current score: {score_1}\n')

        # This function is to check if all possible sums of 3 numbers in the player's list = 15
        def findTriplets(player_1_list, summation):
            def valid(val):
                return sum(val) == summation

            return list(filter(valid, list(combinations(player_1_list, 3))))


        # This is what happens if a player wins
        if bool(findTriplets(player_1_list, 15)):
            print("Player 1 wins")
            print(f'Your winning combination is: {findTriplets(player_1_list, 15)}')
            break

    # Player 2
    if len(numbers) != 0:

        # This is to check if the input is valid
        valid_input = False
        while not valid_input:

            try:
                print(f'Available numbers:{numbers}\n')
                player_2 = int(input("Player 2, choose a number from the list\n"))
                numbers.remove(player_2)
                valid_input = True
            except ValueError:
                print("Invalid, please choose another number\n")

        # This is where the input of the player is taken and added to his list
        player_2_list.append(player_2)
        print(f'Your list of numbers:{player_2_list}')
        score_2 += player_2
        print(f'Your current score: {score_2}\n')

        # This function is to check if all possible sums of 3 numbers in the player's list = 15
        def findTriplets(player_2_list, summation):
            def valid(val):
                return sum(val) == summation

            return list(filter(valid, list(combinations(player_2_list, 3))))


        # This is what happens if a player wins
        if bool(findTriplets(player_2_list, 15)):
            print("Player 2 wins")
            print(f'Your winning combination is: {findTriplets(player_2_list, 15)}')
            break
        
else:
    print("Draw")
