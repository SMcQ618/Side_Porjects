//
// Created by steph on 12/26/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//this will display the tasks the user has to do
void displayTasks(const std::vector<std::string> &tasks) {
    std::cout << "To-Do:" << std::endl;
    for(int i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}
//this is the main thing of the function
int main() {
    std::vector<std::string> tasks;
    std::string task;
    char choice;

    //get the existing tasks from the file
    std::ifstream inputFile("tasks.txt");
    while(getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();

    do {
        std::cout << "A - Add a task" << std::endl;
        std::cout << "V - View tasks" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter your choice in capital: " << std::endl;
        std::cin >> choice;

        //switch depending on what user chooses
        switch(choice) {
            case 'A':
                std::cout << "Enter a task: ";
                std::cin.ignore(); //clear the input
                getline(std::cin, task);
                tasks.push_back(task);
                break;
            case 'V':
                displayTasks(tasks);
                break;
        }
    }
    while(choice != 'Q');

    //save the tasks in a file
    std::ofstream outputFile("tasks.txt");
    for(const auto &t : tasks) {
        outputFile << t << std::endl;
    }
    outputFile.close();

    return 0;
}
