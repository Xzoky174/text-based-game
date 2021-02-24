#include <iostream> // For cout, cin and other basic stuff
#include <conio.h> // For exit()
#include <cstdlib>
#include <ctime>
// The two above are for generating random numbers
using namespace std; // Using standard namespace

int main()
{
	char direction = 'a'; // Direction the player wants to move to (n, e, s, w)
	int place_x = 10; // Current x coordinates
	int place_y = 10; // Current y coordinates
	int amount; // Amount of places or steps the player wants to move
	int random; // Generating a random number
	int bullets = 0; // Amount of bullets the player has found, by default, 0
	int snowballs = 0; // Amount of snowballs a player has, by defualt, 0
	bool gun = false; // If the player has found a gun or not, by default, the player doesn't
	bool snowball_thrower = false; // If the player has found a snowball thower or not, by default, the player doesn't
	int no_items = 1; // To make the game not so boring, it will hardcode so if the user played three times and got no items, they will automatically get one!
	srand((signed) time(0)); // Making sure that the [random] number will be different every time
	cout << "Text-based adventure game!\n"; // Starts the game
	cout << "*Press Enter on your keyboard to exit*\n";

	while ('j') // Infinite loop
	{
		cout << "Current x and y coordinates:\n" << "x: " << place_x << "\ny: " << place_y << '\n'; // Says the current x and y coordinates
		cout << "You can move north (n), east (e), south (s) and west (w)\nWhere would you like to move?\n"; // Prompt for direction
		direction = getch(); // Stores input into direction
		if (direction != '\r'){ // If statement so the program doesn't say: 'You chose '
			cout << "\nYou chose " << direction << '\n';
		}
		switch(direction)
		{
			case 'n': // Add 'place_y'
				cout << "\nHow many places do you want to move north?\n"; // Asks how many places the user wants to move north
				cin >> amount; // Stores input into amount
				place_y += amount; // Adds y to amount
				break;

			// Upper case is similar to all cases below

			case 'e': // Add 'place_x'
				cout << "\nHow many places do you want to move east?\n";
				cin >> amount;
				place_x += amount;
				break;

			case 's': // Substract 'place_y'
				cout << "\nHow many places do you want to move south?\n";
				cin >> amount;
				place_y -= amount;
				break;

			case 'w': // Substract 'place_x'
				cout << "\nHow many places do you want to move west?\n";
				cin >> amount;
				place_x -= amount;
				break;

			case '\r':
				cout << "Leaving.."; // Exits because the user pressed enter
				exit(0);

			default:
				cout << "Invalid value, value has to be either 'n', 's', 'w', or 'e'\n"; // Asks for input again
		}

	  if ((place_x == (rand() % 20 + 1) && place_y == (rand() % 20 + 1)) || no_items == 3){
			no_items = 0;
			random = (rand() % 5 + 1);
			if (random == 5){
				cout << "You found " << rand() % 5 + 1 << " bullet/s!\n";
				bullets += 1;
				if (gun == false){
					cout << "Find a gun to use the bullet/s\n";
				}
				else {
					cout << "You can use the bullet/s with your gun!\n";
				}
			}
			else if (random <= 2){
				cout << "You found 1 snowball!\n";
				snowballs += 1;
			}
			else if (random == 3){
				cout << "You found a gun!\n";
				if (gun == true){
					cout << "Sadly, you already have a gun..\n";
				}
				else {
					gun = true;
				}
			}
			else {
				cout << "You found a snowball thower!\n";
				snowball_thrower = true;
				if (snowballs >= 1){
					cout << "You can use your snowballs with the snowball thrower!\n";
				}
				else {
					cout << "You need to find some snowballs to use the snowball thrower\n";
				}
			}
		}
		else {
			no_items += 1;
		}
	}

	return 0;
}
