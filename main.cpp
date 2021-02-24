#include <iostream> // For cout, cin and other basic stuff
#include <conio.h> // For exit()
using namespace std; // Using standard namespace

int main()
{
	char direction = 'a'; // Direction the player wants to move to (n, e, s, w)
	int place_x = 10; // Current x coordinates
	int place_y = 10; // Current y coordinates
	int amount; // Amount of places or steps the player wants to move
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
	}

	return 0;
}
