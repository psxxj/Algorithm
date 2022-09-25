#include <iostream>
#include <deque>

using namespace std;

/** think of the cursor position as BETWEEN two adjacent characters.
	let '|' show the cursor position.

	cursor == 0 - cursor is between the begining of the buffer, and the first char - "|abcdef"
	cursor == 1 - "cursor is between the first and second char - "a|bcdef"
	cursor == 5 - cursor is between the 5th and 6th char - "abcde|f"
*/

class Buffer
{
protected:
	deque<char> dq;
	deque<char>::iterator iter;
	char arr[100000];
	int cursor;

public:
	Buffer() {
		iter = dq.end();
		cursor = 0;
	}

	/** Get the current character count of the buffer  */
	virtual int size() = 0;

	virtual void loadBuffer() = 0;

	virtual char* toArray() = 0;

	/** get the cursor position, in characters from start */
	virtual int getCursor() = 0;

	/** set the cursor position, in characters from start */
	virtual void setCursor(int j) = 0;

	/** move cursor one to the right
	"abc|def" => "abcd|ef"
	*/
	virtual void moveRight() = 0;

	/** move cursor one to the left
	"abc|def" => "ab|cdef"
	*/
	virtual void moveLeft() = 0;

	/** insert a new char to the left of the cursor
	if the buffer is "abc|def", insertLeft('X')
	would change the buffer to 'abcX|def'
	*/
	virtual void insertLeft(char c) = 0;

	/** delete and return the character to the right of the cursor
	given "abc|def", deleteRight() => "abc|ef"
	*/
	virtual char deleteRight() = 0;

	/** delete and return the character to the left of the cursor
	given "abc|def", deleteLeft() => "ab|def"
	*/
	virtual char deleteLeft() = 0;

};

class FastBuffer : public Buffer
{
public:

	virtual int size() {
		return (int)dq.size();
	}

	virtual void loadBuffer() {
		cout << "  >> ";
		for (int i = 0; i < cursor; i++)
			cout << arr[i];

		if (size() != 0) {
			for (iter = dq.begin(); iter != dq.end(); iter++)
				cout << *iter;
		}
		cout << endl;
	}

	virtual char* toArray() {
		return &dq[0];
	}

	virtual int getCursor() {
		return cursor;
	}

	virtual void setCursor(int j) {
		if (j < cursor) {
			for (int i = cursor - 1; i >= j; i--) {
				dq.push_front(arr[i]);
				arr[i] = ' ';
			}
		}

		else{
			for (int i = 1; i <= j - cursor; i++) {
				arr[cursor] = *toArray();
				dq.pop_front();
			}
		}

		cursor = j;
	}

	virtual void moveRight() {
		if (size() == 0)
			cout << "  >> ERROR: Cursor is already on the far right." << endl;
		else {
			arr[cursor] = *toArray();
			cursor++;
			dq.pop_front();
			cout << "  >> Cursor is moved to Right." << endl;
		}
	}

	virtual void moveLeft() {
		if (cursor == 0)
			cout << "  >> ERROR: Cursor is already on the far left." << endl;
		else {
			dq.push_front(arr[cursor - 1]);
			arr[cursor - 1] = ' ';
			cursor--;
			cout << "  >> Cursor is moved to Left." << endl;
		}
	}

	virtual char deleteRight() {
		if (size() == 0) {
			cout << "  >> ERROR: There is no characters to the right of the cursor." << endl;
			return NULL;
		}
		else {
			char delete_ch;
			delete_ch = *toArray();
			dq.pop_front();
			cout << "  >> Right one Deleted : ";
			return delete_ch;
		}
	}

	virtual char deleteLeft() {
		if (cursor == 0) {
			cout << "  >> ERROR: There is no characters to the left of the cursor." << endl;
			return NULL;
		}
		else {
			char delete_ch;
			delete_ch = arr[cursor - 1];
			arr[cursor - 1] = ' ';
			cursor--;
			cout << "  >> Left one Deleted : ";
			return delete_ch;
		}
	}

	virtual void insertLeft(char c) {
		dq.push_front(c);
		arr[cursor] = *toArray();
		dq.pop_front();
		cursor++;
	}

};

