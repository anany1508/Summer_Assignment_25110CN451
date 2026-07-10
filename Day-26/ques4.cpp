#include <iostream>
#include <vector>
#include <string>
#include <cctype>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    char correctAnswer;
};

void runQuiz(const std::vector<Question>& quizBank) {
    int score = 0;
    int totalQuestions = quizBank.size();

    std::cout << "=================================\n";
    std::cout << "   WELCOME TO THE C++ QUIZ!      \n";
    std::cout << "=================================\n\n";

    for (size_t i = 0; i < quizBank.size(); ++i) {
        std::cout << "Question " << (i + 1) << ": " << quizBank[i].questionText << "\n";
        
        for (const auto& option : quizBank[i].options) {
            std::cout << option << "\n";
        }

        char userAnswer;
        std::cout << "Your answer (A, B, C, or D): ";
        std::cin >> userAnswer;
        userAnswer = std::toupper(userAnswer);

        // Input validation loop
        while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D') {
            std::cout << "Invalid choice. Please enter A, B, C, or D: ";
            std::cin >> userAnswer;
            userAnswer = std::toupper(userAnswer);
        }

        if (userAnswer == quizBank[i].correctAnswer) {
            std::cout << "Correct!\n\n";
            score++;
        } else {
            std::cout << "Wrong. The correct answer was " << quizBank[i].correctAnswer << ".\n\n";
        }
    }

    std::cout << "=================================\n";
    std::cout << "          QUIZ OVER              \n";
    std::cout << "=================================\n";
    std::cout << "Your Final Score: " << score << " / " << totalQuestions << "\n";
    
    double percentage = (static_cast<double>(score) / totalQuestions) * 100;
    std::cout << "Percentage: " << percentage << "%\n";
}

int main() {
    std::vector<Question> quizBank = {
        {
            "Which programming language is known as a 'superset' of C?",
            {"A. Python", "B. Java", "C. C++", "D. Ruby"},
            'C'
        },
        {
            "What is the correct way to output 'Hello World' in C++?",
            {"A. print(\"Hello World\");", "B. cout << \"Hello World\";", "C. System.out.println(\"Hello World\");", "D. echo \"Hello World\";"},
            'B'
        },
        {
            "Which of the following is used to create a comment in C++?",
            {"A. #", "B. //", "C. <!-- -->", "D. /*"},
            'B'
        }
    };

    runQuiz(quizBank);

    return 0;
}
