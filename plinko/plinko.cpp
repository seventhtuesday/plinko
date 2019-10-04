#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int userResponse;
	int numChip;
	double slotPlacement;
	double userPlacement;
	const int RANDOM_SEED = 42;
	double winnings = 0.00;
	srand(RANDOM_SEED);
	const double NOMONEY = 0.00;
	const double DEVIATION = 0.5;
	const double LITTLEMONEY = 100.00;
	const double SOMEMONEY = 500.00;
	const double BIGMONEY = 1000.00;
	const double BLOODMONEY = 10000.00;

	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl;

	do {
		cout << endl << "Enter your selection now:" << endl;
		cin >> userResponse;
		if (userResponse == 1) {
			cout << "*** Drop a single chip ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
			cin >> slotPlacement;
			if (slotPlacement < 0 || slotPlacement > 8) {
				cout << "Invalid slot." << endl;
			}
			else {
				cout << fixed << setprecision(0);
				cout << "*** Dropping chip into slot " << slotPlacement << " ***" << endl;
				cout << fixed << setprecision(1);
				cout << "Path: [" << slotPlacement << ", ";
				for (int n = 0; n < 12; n++) {
					if (slotPlacement == 0) {
						slotPlacement += DEVIATION;
					}
					else if (slotPlacement == 8) {
						slotPlacement -= DEVIATION;
					}
					else {
						int plusMinus = rand() % 2;
						if (plusMinus == 0) {
							slotPlacement -= DEVIATION;
						}
						else {
							slotPlacement += DEVIATION;
						}
					}
					if (n == 11) {
						cout << fixed << setprecision(1);
						cout << slotPlacement << "]" << endl;
					}
					else {
						cout << fixed << setprecision(1);
						cout << slotPlacement << ", ";
					}
				}
				if (slotPlacement == 0 || slotPlacement == 8) {
					cout << "Winnings: $100.00" << endl;
				}
				else if (slotPlacement == 1 || slotPlacement == 7) {
					cout << "Winnings: $500.00" << endl;
				}
				else if (slotPlacement == 2 || slotPlacement == 6) {
					cout << "Winnings: $1000.00" << endl;
				}
				else if (slotPlacement == 3 || slotPlacement == 5) {
					cout << "Winnings: $0.00" << endl;
				}
				else {
					cout << "Winnings: $10000.00" << endl;
				}
			}
		}
		else if (userResponse == 2) {
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl << "How many chips do you want to drop (>0)?" << endl;
			cin >> numChip;
			if (numChip < 0) {
				cout << "Invalid number of chips." << endl;
			}
			else {
				cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
				cin >> userPlacement;
				if (userPlacement < 0 || userPlacement > 8) {
					cout << "Invalid slot." << endl;
				}
				else {
					winnings = 0.00;
					for (int i = 0; i < numChip; i++) {
						slotPlacement = userPlacement;
						for (int n = 0; n < 12; n++) {
							if (slotPlacement == 0) {
								slotPlacement += DEVIATION;
							}
							else if (slotPlacement == 8) {
								slotPlacement -= DEVIATION;
							}
							else {
								int plusMinus = rand() % 2;
								if (plusMinus == 0) {
									slotPlacement -= DEVIATION;
								}
								else {
									slotPlacement += DEVIATION;
								}
							}
						}
						if (slotPlacement == 0 || slotPlacement == 8) {
							winnings += LITTLEMONEY;
						}
						else if (slotPlacement == 1 || slotPlacement == 7) {
							winnings += SOMEMONEY;
						}
						else if (slotPlacement == 2 || slotPlacement == 6) {
							winnings += BIGMONEY;
						}
						else if (slotPlacement == 3 || slotPlacement == 5) {
							winnings += NOMONEY;
						}
						else {
							winnings += BLOODMONEY;
						}
					}
					cout << fixed << setprecision(2);
					cout << "Total winnings on " << numChip << " chips: $" << winnings << endl;
					cout << "Average winnings per chip: $" << (winnings / numChip) << endl;
				}
			}
		}
		else if (userResponse == 3) {
			cout << "Menu: Please select one of the following options:" << endl << endl
				<< "1 - Drop a single chip into one slot" << endl
				<< "2 - Drop multiple chips into one slot" << endl
				<< "3 - Show the options menu" << endl
				<< "4 - Quit the program" << endl;
		}
		else if (userResponse == 4) {
			cout << "Goodbye!" << endl;
			break;
		}
		else {
			cout << "Invalid selection.  Enter 3 to see options." << endl;
		}
	} while (userResponse != 4);



	return 0;
}