// Q2. Write a C++ program using a doubly linked list to manage a web browser’s history. The
// program should insert new websites visited, move backward to go to the previous page and move
// forward to revisit a page. Add function to search for a website in history.
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node* pre;

    Node(string u) {
        url = u;
        next = nullptr;
        pre = nullptr;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* tail;
    Node* current;

    BrowserHistory() {
        head = tail = current = nullptr;
    }

    void visit(string site) {
        Node* temp = new Node(site);
        if (head == nullptr) {
            head = tail = current = temp;
        } else {
            tail->next = temp;
            temp->pre = tail;
            tail = temp;
            current = temp;
        }
        cout << "Visited: " << site << endl;
    }

    void goBack() {
        if (current != nullptr && current->pre != nullptr) {
            current = current->pre;
            cout << "Moved back to: " << current->url << endl;
        } else {
            cout << "No previous page!" << endl;
        }
    }

    void goForward() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            cout << "Moved forward to: " << current->url << endl;
        } else {
            cout << "No forward page!" << endl;
        }
    }

    void search(string site) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->url == site) {
                cout << "Website found: " << site << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Website not found: " << site << endl;
    }

    void showHistory() {
        if (head == nullptr) {
            cout << "History is empty." << endl;
            return;
        }
        cout << "Browser History: ";
        Node* temp = head;
        while (temp != nullptr) {
            if (temp == current)
                cout  << temp->url <<  "->";
            else
                cout << temp->url << " -> ";
            temp = temp->next;
        }

    }
};

int main() {
    BrowserHistory bh;
    int choice;
    string site;

    do {
        cout << "-1. Exit"<<endl;
        cout << "1. Visit a website"<<endl;
        cout << "2. Go back"<<endl;
        cout << "3. Go forward"<<endl;
        cout << "4. Search website"<<endl;
        cout << "5. Show history"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter website Ulr: ";
            cin >> site;
            bh.visit(site);
            break;
        case 2:
            bh.goBack();
            break;
        case 3:
            bh.goForward();
            break;
        case 4:
            cout << "Enter website URL to search: ";
            cin >> site;
            bh.search(site);
            break;
        case 5:
            bh.showHistory();
            break;
        case -1:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != -1);

    return 0;
}
