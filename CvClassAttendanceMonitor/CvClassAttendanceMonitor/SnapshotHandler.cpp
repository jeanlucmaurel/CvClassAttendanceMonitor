#include "SnapshotHandler.h"

int main() {
	int choice;
	std::cout << "1. Recognise Face\n";
	std::cout << "2. Add Face\n";
	std::cout << "Choose One: ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:

		break;
	case 2:
		Capture();
		break;
	default:
		break;
	}
	//system("pause");
	return 0;
}