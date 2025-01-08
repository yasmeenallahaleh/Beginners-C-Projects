FirstName:YASMEEN
LastName:ALLAHALEH
Section: CSC_Fall23 : ProjectTWO
ID: 2981504



TIC-TAC-TOE:
For this game, it has four modes. Player vs. Player, Player vs DUMB AI, Player vs. Smart AI, and DUMB AI vs DUMB AI. 
When you chose Tic-Tac-Toe,another menu pulls up to choose one of these modes. 
*NOTE: My computer does not have a C:\

Player VS Player:
This mode allows two people to play. A tic-tac toe board is displayed as a random number generator chooses which goes first. You are considered Player One for counting all your wins and calculating the win rate. Each player takes turns placing there symbol as a win checker is placed after each turn is played. Whoever gets three symbols in a row first wins the game and is counted as a win for that person. If no one wins the game, it's counted as a draw and the stats are saved to a file. After a game is done, the program then asks if the user would like to save their game to a file. If they say yes, they are asked to type in the file name. Its then displayed and then are asked if they would like to play again. If yes the process is repeated, if no then they are asked if they would go to the menu.

Player vs. Dumb AI:
This mode allows one layer and a computer based player, which is the DUMB AI. The program chooses a random player to first by a random number generator and then allows each player to takes turns. When the DUMB AI plays, it chooses a random number from a random number generator, that has not been occupied yet. Which ever player gets three in a row first, a win is counted for that player and saved to stats. After a game is done, the program then asks if the user would like to save their game to a file. If they say yes, they are asked to type in the file name. Its then displayed and then are asked if they would like to play again. If yes the process is repeated, if no then they are asked if they would go to the menu.

Player vs. Perfect AI:
This mode allows a real user and a computer programed to be "Perfect". The program chooses which player goes first and each player takes turns. The perfect AI plays and is coded according to the many strategies to win located in project 2 description. Depending on where each player is placed on the board, a bunch of condition are checked to make a "perfect" move. Whichever play has three in a row first wins, and is added and calculated to the stats board. After a game is done, the program then asks if the user would like to save their game to a file. If they say yes, they are asked to type in the file name. Its then displayed and then are asked if they would like to play again. If yes the process is repeated, if no then they are asked if they would go to the menu.

Dumb AI vs Dumb AI:
This mode allows two DUMB Ai to play against each other. Once this mode is chosen, a random DUMB Ai is chosen to go first. They taken turns automatically and chose a random number each turn that was not taken. This runs pretty quickly since the user themselves aren't playing. Once the winner is identified, it isn't saved to the stats board this time. After a game is done, the program then asks if the user would like to save their game to a file. If they say yes, they are asked to type in the file name. Its then displayed and then are asked if they would like to play again. If yes the process is repeated, if no then they are asked if they would go to the menu.

*To View the stats board without playing game, these should choose number two in the main menu.

*What doesn't work: One thing I noticed that was weird is that whenever it was saved to a file entered by the user, it would be perfectly output to the stream and would created the file. But whenever you go inside the file out of netbeans, the content of the game would disappear. 

HANGMAN:
For this game, I created two modes. The first mode allows player one to enter the word and a hint, while player two guesses the word.
The second mode allows both players to guess a letter each turn.  

One Guesser Mode:
This mode allows player One to enter the word and a hint for payer two to guess. The directions state that only one word can be entered. Each time the user enters a right guess, it's added to a right guess vector and the displays reveals the location of the letter that they guessed. If the player gets a guess wrong, it's added to the wrong guesses vector and then the parts of the hangman start to appear. Once the hangman is fully built, it kicks the user outstaying that they lost to player one and player one gains a win on the stats board. But if player two guesses the word correctly before the full hangman is built, they win against player one and there win is added to the stats board that is saved on a file name "hangmanStats.txt". 

Two Guesser Mode:
This mode allows player one and player two to both guess the word randomized. The random words come from a function created i I randomly created 10 words each assigned a number. A random number generator randomly picks a number and a word, along with a hint, is picked for both players to guess. Player Two goes first because thats is you, the user, and being player two sucks, so pitty points. Each player takes a turn to guess and whichever player gets the last correct letter, wins the gamed earns a win thats added to a stats board

HangMan Stats Board:
The stats is saved to a file. if the player would like to access the stats board, they could go to the main menu and choose option four.

*What doesn't work: One thing I noticed is that whenever a user might enter a capitalize version of a letter that is part of the word, it counts the guess as wrong. It also counts it wrong if you enter two letter or more at a time, even if they are both in the word.