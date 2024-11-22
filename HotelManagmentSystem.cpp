#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Room {
public:
	int roomNo;
	int roomPrice;
	string Name;
	Room* next;
	Room(int no, int p, string n) {
		roomNo = no;
		roomPrice = p;
		Name = n;
		next = nullptr;
	}
};
class Hotel {
	Room* head;
public:
	Hotel() {
		head = nullptr;
	}

	void addRoom(int no, int p,string n) {
		Room* newRoom = new Room(no,p,n);
		if (head == nullptr) {
			newRoom->next = head;
			head = newRoom;
		}
		else {
			Room* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newRoom;
		}
		cout << "Room Is Added in the Hotel." << endl;
	}

	void addGuest(int no, string n) {
		Room* temp = head;
		while (temp != nullptr) {
			if (temp->roomNo == no) {
				temp->Name = n;
				cout << "Guest Is Added in the room." << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Room Number You Entered Is Not Found." << endl;
	}

	void deleteRoom(int no) {
		Room* curr = head;
		Room* prev = nullptr;
		if (curr == nullptr) {
			cout << "There are no rooms in the hotel." << endl;
			return;
		}
		while (curr != nullptr && curr->roomNo != no) {
			prev = curr;
			curr = curr->next;
		}
		if (prev == nullptr) {
			head = head->next;
		}
		else {
			prev->next = curr->next;
		}
		delete curr;
		cout << "The room number you entered is deleted from the hotel." << endl;
	}

	void deleteguest(int no, string n) {
		Room* temp1 = head;
		while (temp1 != nullptr) {
			if (temp1->roomNo == no) {
				if (temp1->Name == n) {
					temp1->Name = " ";
					cout << "the Guest name you entered is removed." << endl;
					return;
				}
				else {
					cout << "Guest Name Does Not Match." << endl;
					return;
				}
			}
			temp1 = temp1->next;
		}
		cout << "Room Number You Entered Is Not Found." << endl;
	}

	void count() {
		int count = 0;
		Room* temp2 = head;
		while (temp2 != nullptr) {
			count++;
			temp2 = temp2->next;
		}
		cout << "Total Number Of Rooms in the hotel are: " << count << endl;
	}

	void search(int no) {
		Room* temp3 = head;
		while (temp3 != nullptr) {
			if (temp3->roomNo == no) {
				cout << "Room Number You Entered Is Found." << endl;
				return;
			}
			temp3 = temp3->next;
		}
		cout << "Room Number You Entered Is Not Found." << endl;
	}

	void display() {
		Room* temp4 = head;
		if (temp4 == nullptr) {
			cout << "There are no rooms in the hotel." << endl;
		}
		while (temp4 != nullptr) {
			cout << "The Details of the rooms are: " << endl;
			cout << "Room Number is:" << endl;
			cout << temp4->roomNo << endl;
			cout << "Room Price is:" << endl;
			cout << temp4->roomPrice << endl;
			temp4 = temp4->next;
		}
	}

	void write() {
		ofstream file;
		file.open("project.txt");
		if (!file) {
			cout << "There is no file to write." << endl;
			return;
		}
		Room* temp5 = head;
		while (temp5 != nullptr) {
			file << "The Details Are: " << endl;
			file << "Room Number is:" << endl;
			file << temp5->roomNo << endl;
			file << "Room Price is:" << endl;
			file << temp5->roomPrice << endl;
			file << "Guest Name: " << endl;
			file << temp5->Name << endl;;
			temp5 = temp5->next;
		}
		file.close();
	}

	void read() {
		ifstream file;
		file.open("project.txt");
		if (!file) {
			cout << "No Details Are Here To Show." << endl;
			return;
		}
		int roomNo;
		int roomPrice;
		string Name;
		while (file >> roomNo >> roomPrice >> ws && getline(file,Name)){
			cout << "Room No:" << endl;
			cout << roomNo<<endl;
			cout << "Room Price: " << endl;
			cout << roomPrice<<endl;
			cout << "Guest Name: " << endl;
			cout << Name<<endl;
		}
		file.close();
	}
};
int main() {
	Hotel obj;
	obj.read();
	int roomNo;
	int roomPrice;
	string Name;
	int choice;
	do {
		cout << "Amna's Hotel System: " << endl;
		cout << "Enter Your choice from 1 to 9: " << endl;
		cout << "1. Add Room. " << endl;
		cout << "2. Add Guest. " << endl;
		cout << "3. Delete Room. " << endl;
		cout << "4. Delete Guest. " << endl;
		cout << "5. Count Rooms. " << endl;
		cout << "6. Search Room. " << endl;
		cout << "7. Display Rooms. " << endl;
		cout << "8. Write In File. " << endl;
		cout << "9. End The Program. " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter Room Number To Add: " << endl;
			cin >> roomNo;
			cout << "Enter Room Price To Add: " << endl;
			cin >> roomPrice;
			obj.addRoom(roomNo, roomPrice, Name);
			break;
		case 2:
			cout << "Enter Room Number: " << endl;
			cin >> roomNo;
			cout << "Enter Guest Name To Add: " << endl;
			cin >> Name;
			obj.addGuest(roomNo, Name);
			break;
		case 3:
			cout << "Enter Room Number To Delete: " << endl;
			cin >> roomNo;
			obj.deleteRoom(roomNo);
			break;
		case 4:
			cout << "Enter Room Number: " << endl;
			cin >> roomNo;
			cout << "Enter Guest Name To Delete: " << endl;
			cin >> Name;
			obj.deleteguest(roomNo, Name);
			break;
		case 5:
			obj.count();
			break;
		case 6:
			cout << "Enter Room Number To Search: " << endl;
			cin >> roomNo;
			obj.search(roomNo);
			break;
		case 7:
			obj.display();
			break;
		case 8:
			obj.write();
			cout << "The details are saved in the file." << endl;
			break;
		case 9:
			cout << "The Program is ended." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again" << endl;
		}
	} while (choice != 9);
	return 0;
}