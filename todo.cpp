#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string text;
    bool done;
};

int main() {
    vector<Task> tasks;
    int choice = 0;

    do {
        cout << "\n--- TO-DO LIST ---" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        } else {
            cin.ignore(1000, '\n');
        }

        if (choice == 1) {
            Task t;
            cout << "Enter task: ";
            getline(cin, t.text);
            t.done = false;
            tasks.push_back(t);
            cout << "Task added!" << endl;
        }
        else if (choice == 2) {
            if (tasks.empty())
                cout << "No tasks yet." << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i].text;
                if (tasks[i].done)
                    cout << " [completed]" << endl;
                else
                    cout << " [pending]" << endl;
            }
        }
        else if (choice == 3) {
            int n;
            cout << "Task number to mark completed: ";
            cin >> n;
            if (n >= 1 && n <= tasks.size()) {
                tasks[n - 1].done = true;
                cout << "Marked as completed!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        }
        else if (choice == 4) {
            int n;
            cout << "Task number to remove: ";
            cin >> n;
            if (n >= 1 && n <= tasks.size()) {
                tasks.erase(tasks.begin() + (n - 1));
                cout << "Task removed!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}
