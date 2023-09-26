#include <iostream>
#include <conio.h>
#define ANY_ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define CMD 0
#define PS 1
using namespace std;
int main()
{
	int curTerm = CMD;
	string input;
	int rowPos = 0;
	cout << "type in \"termSwitch\" to switch between CMD and POWERSHELL. default terminal is CMD\n\n";
	cout << "command prompt >> ";
	for (int i = 0;;) {
		i = _getch();
		if (i == 8) {
			cout << "\b \b";
			input.pop_back();
			if (rowPos > 0) {
				rowPos = rowPos - 1;
			}
		}
		else if (i == 13) {
			cout << "\n";
			if (input == "termSwitch") {
				if (curTerm == CMD) {
					curTerm = PS;
					cout << "\nPOWERSHELL MODE ON \n(note: powershell might be more slower to get a response from) \n\n";
					cout << "powershell >> ";
				}
				else if (curTerm == PS) {
					curTerm = CMD;
					cout << "\nCOMMAND PROMPT MODE ON \n\n";
					cout << "command prompt >> ";
				}
			}
			else {
				switch (curTerm) {
				case CMD:
					system(input.c_str());
					cout << "\n";
					cout << "command prompt >> ";
					break;
				case PS:
					string systemCMD = "powershell -command \"" + input + "\"";
					system(systemCMD.c_str());
					cout << "\n";
					cout << "powershell >> ";
					break;
				}
			}
			input = "";
		}
		else {
			switch (i) {
			case ANY_ARROW:
				i = _getch();
				switch (i) {
				case LEFT_ARROW:
					cout << "\b";
					if (rowPos > 0) {
						rowPos = rowPos - 1;
					}
					break;
				case RIGHT_ARROW:
					if (rowPos < input.length()) {
						cout << "\033[C"; //idk how tf this works whoever's reading this pls explain!11
						rowPos = rowPos + 1;
					}
					break;
				case UP_ARROW:
					break;
				case DOWN_ARROW:
					break;
				}
				break;
			default:
				cout << (char)i;
				rowPos = rowPos + 1;
				input = input + (char)i;

			}
		}
	}
}
