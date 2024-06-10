#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoListManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.emplace_back(task);
        std::cout << "Task '" << task << "' added." << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::string status = tasks[i].completed ? "Completed" : "Pending";
                std::cout << i + 1 << ". " << tasks[i].description << " [" << status << "]" << std::endl;
            }
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task " << taskNumber << " marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task " << taskNumber << " removed." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

int main() {
    ToDoListManager manager;
    int choice;
    std::string taskDescription;
    size_t taskNumber;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, taskDescription);
            manager.addTask(taskDescription);
            break;
        case 2:
            manager.viewTasks();
            break;
        case 3:
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> taskNumber;
            manager.markTaskCompleted(taskNumber);
            break;
        case 4:
            std::cout << "Enter task number to remove: ";
            std::cin >> taskNumber;
            manager.removeTask(taskNumber);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
