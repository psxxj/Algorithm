#include <iostream>
#include <windows.h>
#include "Buffer.h"

using namespace std;

void printMenu() {
	cout << "========== MENU ==========" << endl;
	cout << "   1 :: insertLeft" << endl;
	cout << "   2 :: moveLeft" << endl;
	cout << "   3 :: moveRight" << endl;
	cout << "   4 :: deleteLeft" << endl;
	cout << "   5 :: deleteRight" << endl;
	cout << "   6 :: getCursor" << endl;
	cout << "   7 :: setCursor" << endl;
	cout << "   8 :: Load Buffer" << endl;
	cout << "   9 :: EXIT" << endl;
	cout << "========== **** ==========" << endl << endl;
}

int main() {
	cout << "[ 20205075 ¹Ú¼ºÁØ HW2_ 'Buffer' ]" << endl << endl;

	FastBuffer ourBuff;
	printMenu();

	while (1) {
		cout << endl;
		cout << "========== * ==========" << endl << endl;
		cout << "Enter a MENU NUMBER: ";

		int num = 0;
		cin >> num;

		switch (num) {
		case 1:
			cout << "  >> Enter a Character : ";
			char ch;
			cin >> ch;
			ourBuff.insertLeft(ch);
			break;

		case 2:
			ourBuff.moveLeft();
			break;

		case 3:
			ourBuff.moveRight();
			break;
		case 4:
			cout << ourBuff.deleteLeft() << endl;
			break;
		case 5:
			cout << ourBuff.deleteRight() << endl;
			break;
		case 6:
			cout << "  > > Cursor is at position " << ourBuff.getCursor() << "." << endl;
			break;
		case 7:
			cout << "  >> Set a cursor position : ";
			int pos;
			cin >> pos;
			ourBuff.setCursor(pos);
			break;
		case 8:
			ourBuff.loadBuffer();
			break;
		case 9:
			exit(0);
			break;
		}
	}

}