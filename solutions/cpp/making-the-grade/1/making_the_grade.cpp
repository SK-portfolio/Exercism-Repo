#include <array>
#include <string>
#include <vector>
using namespace std;

// Round down all provided student scores.
vector<int> round_down_scores(vector<double> student_scores) {
    vector<int>rnd_scores;
    for(int i{0}; i < student_scores.size(); i++){
        rnd_scores.push_back(static_cast<int>(student_scores[i]));
    }
    return {rnd_scores};
}

// Count the number of failing students out of the group provided.
int count_failed_students(vector<int> student_scores) {
    int ctr{0};
    for(int i{0}; i < student_scores.size(); i++){
        if(student_scores[i]<=40){
            ctr++;
        }
    }
    return ctr;
}

// Create a list of grade thresholds based on the provided highest grade.
array<int, 4> letter_grades(int highest_score) {
    array<int, 4> grade_thresh{0,0,0,0};
    int score{41};
    int interval{(highest_score - 40)/4};
    for(int i{0}; i < grade_thresh.size(); i++){
        grade_thresh[i] = score;
        score += interval;
    }
    return {grade_thresh};
}

// Organize the student's rank, name, and grade information in ascending order.
vector<string> student_ranking(vector<int> student_scores, vector<string> student_names) {
    vector<string> ranks;
    for(int i{0}; i < student_names.size(); i++){
        ranks.push_back(to_string(i+1) + ". " + student_names[i] + ": " + to_string(student_scores[i]));
    }
    return {ranks};
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
string perfect_score(vector<int> student_scores, vector<string> student_names) {
    for(int i{0}; i < student_names.size(); i++){
        if(student_scores[i] == 100){
            return student_names[i];
        }
    }
    return "";
}
