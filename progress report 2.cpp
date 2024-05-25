#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string &taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    void completeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void completeTask(const string &taskDescription) {
        bool found = false;
        for (Task &task : tasks) {
            if (task.description == taskDescription) {
                task.completed = true;
                cout << "Task completed: " << task.description << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Task not found." << endl;
        }
    }

    void listTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) cout << " [Completed]";
            cout << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. Complete Task by Number\n3. Complete Task by Name\n4. List Tasks\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 5) break;

        if (choice == 1) {
            cin.ignore();
            string taskDescription;
            cout << "Enter task description: ";
            getline(cin, taskDescription);
            taskManager.addTask(taskDescription);
        } else if (choice == 2) {
            int taskIndex;
            cout << "Enter task number to complete: ";
            cin >> taskIndex;
            taskManager.completeTask(taskIndex - 1);
        } else if (choice == 3) {
            cin.ignore();
            string taskDescription;
            cout << "Enter task name to complete: ";
            getline(cin, taskDescription);
            taskManager.completeTask(taskDescription);
        } else if (choice == 4) {
            taskManager.listTasks();
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    cout << "Exiting. Goodbye!" << endl;
    return 0;
}
