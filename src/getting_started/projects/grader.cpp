#include <iostream>
#include <string>

const int kNumAssignments = 4;
const double kAssignmentWeight = 0.4;
const double kMidtermWeight = 0.15;
const double kFinalWeight = 0.35;
const double kParticipationWeight = 0.1;

const std::string kAssigmentMsg ("Enter the score for assignment ");
const std::string kMidtermMsg ("Enter the score for the midterm");
const std::string kFinalMsg ("Enter the score for the final");
const std::string kParticipationMsg ("Enter the score for the section grade");

int CollectInputFromUser(std::string message) {
    int input;
    std::cout << message + ": ";
    if(!(std::cin >> input)) {
        throw std::invalid_argument("Expected integer input.");    
    }

    return input;
}

double CalculateWeightedGrade(int grade, double weight) {
    return grade * weight;
} 

double CalculateAssignmentGrade(int numAssignments, double assignmentWeight) {
    int assignmentSum = 0;
    
    for(int i = 1; i <= numAssignments; i++) {
        assignmentSum += CollectInputFromUser(kAssigmentMsg + std::to_string(i));
    }

    return CalculateWeightedGrade((assignmentSum / numAssignments), assignmentWeight);
}

int main() {

    try {
        int assignmentGrade = CalculateAssignmentGrade(kNumAssignments, kAssignmentWeight);    
        int midtermGrade = CalculateWeightedGrade(CollectInputFromUser(kMidtermMsg), kMidtermWeight);
        int finalGrade = CalculateWeightedGrade(CollectInputFromUser(kFinalMsg), kFinalWeight);
        int participationGrade = CalculateWeightedGrade(CollectInputFromUser(kParticipationMsg), kParticipationWeight);

        int classGrade = assignmentGrade + midtermGrade + finalGrade + participationGrade;

        std::cout << "The final grade is: " << classGrade << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
