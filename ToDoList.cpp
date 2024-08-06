#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(string description) {
    Task newTask = { description, false };
    tasks.push_back(newTask);
}

void viewTasks() {
    if(tasks.size() == 0){
        cout<<"***Task is Empty***"<<endl;
    }else {
        cout<<"***********List************"<<endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) cout << " [Completed]";
            cout << endl;
        }
        cout<<"***************************"<<endl;
    }
}

void markTaskCompleted(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task description: ";
            string description;
            cin.ignore();
            getline(cin, description);
            addTask(description);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            cout << "Enter task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;
            markTaskCompleted(taskNumber);
        } else if (choice == 4) {
            cout << "Enter task number to remove: ";
            int taskNumber;
            cin >> taskNumber;
            removeTask(taskNumber);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
