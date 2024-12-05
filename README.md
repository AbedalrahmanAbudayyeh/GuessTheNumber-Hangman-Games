 Guess The Number & Hangman Games

This project is a simple console-based application written in C, combining two classic games: **Guess the Number** and **Hangman**. The user can choose which game to play, or exit the program.

Features

1. User Interaction:
   - Prompts the user to enter their name.
   - Offers a menu to choose between "Guess The Number," "Hangman," or exit.

2. Guess The Number:
   - The computer attempts to guess a user-provided secret number using a binary search approach.
   - User provides feedback whether the guess is correct, too high, or too low.
   - Visual feedback through a simple image representation using a 2D array.

3. Hangman:
   - User selects a category (Food, Objects, Names, Colors).
   - A random word from the chosen category is selected.
   - The user has 5 attempts to guess the word.
   - Tracks and displays the progress of the user's guesses.

Usage Instructions

1. Compile the Code:
   ```bash
   gcc GuessTheNumber&Hangman.c -o game
   ```

2. Run the Program:
   ```bash
   ./game
   ```

3. Follow the Prompts:
   - Enter your name when prompted.
   - Choose a game by entering the corresponding number:
     - `1` for Guess The Number.
     - `2` for Hangman.
     - `3` to Exit.

4. Guess The Number Instructions:
   - Enter a secret number (between 1 and 10000).
   - The program will attempt to guess your number by asking for feedback.

5. Hangman Instructions:
   - Choose a category and start guessing letters.
   - You have 5 lives; each wrong guess deducts one life.
   - Guess all letters correctly to win!

 File Dependencies
- `foc_fa22.h`: Custom header file for utility functions (like displaying arrays).

 Notes
- Words for Hangman are read from files such as `food.txt`, `objects.txt`, `names.txt`, and `colors.txt`.
- Ensure these files exist in the same directory as the executable, containing relevant words.

Improvements and Contributions
for further inquiries or support, contact Abedalrhman Abudayyeh at abood.abudayyeh23@outlook.com
