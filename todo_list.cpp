#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks in the list:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". ";
                cout << "[" << (tasks[i].completed ? "Completed" : "Pending") << "] ";
                cout << tasks[i].description << endl;
            }
        }
    }

    
    void markAsCompleted(int taskIndex) {
        if (isValidIndex(taskIndex)) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    
    void removeTask(int taskIndex) {
        if (isValidIndex(taskIndex)) {
            cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    
    bool isValidIndex(int taskIndex) {
        return taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size());
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
