#include <iostream>
using namespace std;

void hwGradeCalc();
void labGradeCalc();
void examGradeCalc();
void finalGradeCalc();

//WEIGHTS
const int HW_WEIGHT = 30;
const int LAB_WEIGHT = 30;
const int EXAM_WEIGHT = 40;

//TOTAL AMOUNT OF ASSIGNMENTS
const int HW_AMOUNT = 9;

//TOTAL POINTS ABLE TO ACHIEVE
const int HW_TOTAL = 270; 
const int LAB_TOTAL = 30;
const int EXAM_TOTAL = 160;
const int OVERALL_TOTAL = HW_TOTAL+LAB_TOTAL+EXAM_TOTAL;

//GRADE IN THAT SECTION
int hwGrade = 0;
int labGrade = 0;
int examGrade = 0;
int finalWeight = 0;

//EXTRA CREDIT
double hwExtraCredit = 0;
double labExtraCredit = 0;


vector<int> hws;
vector<double> userTotals;

int main(){
    int userInput;

    bool grading = true;

    do{
    cout << "Please select one from the menu: " << endl;
    cout << "HW(1) | LABS(2) | EXAMS (3) | CALCULATE GRADE (4) | EXIT (5)" << endl << ">> ";
    cin >> userInput;


    switch(userInput){
        case 1: hwGradeCalc();
        break;
        case 2: labGradeCalc();
        break;
        case 3: examGradeCalc();
        break; 
        case 4: finalGradeCalc();
        break;
        default: cout << "Not in menu. Try again. OR Goodbye if you're exiting.";
    }
}
    while(userInput!=5);

return 0;

}

// ****** FUNCTIONS *******

void hwGradeCalc(){
    const int TOTAL = 15;
    string userInput;
    double scores = 0; //double so it can calculate the amount (C++ is weird)

    if(hwGrade==0){
    cout << "***HOMEWORK***" << endl;
    cout << "Did you score 15/15 on all the HWs (1-9)\nY or N >> ";
    cin >> userInput;

    if(userInput == "Y"){
        for(int i=0; i<HW_AMOUNT; i++){
            scores += HW_WEIGHT*(15/TOTAL); //this is equal to 270
        }
    }
    else{
        for(int i=0; i<HW_AMOUNT; i++){
            double scores = 0;
            cout << "What did you get on HW " << (i+1) << " out of " << TOTAL << " points?" << endl;
            cout << ">> ";
            cin >> scores;
            hws.push_back(HW_WEIGHT*(scores/TOTAL));
        }

        for(int n : hws){
            scores+=n;
        }
    }

    cout << "How much extra credit have you done? Please input the sum of extra credit homework you've done: ";
    cin >> hwExtraCredit;
    scores += hwExtraCredit;
    userTotals.push_back(scores);
    hwGrade = (scores/HW_TOTAL)*100;
    }
    else {
        cout << "You scored " << hwGrade << "% in the HW section. ";
    }
   
}
void labGradeCalc(){
    double scores=0;
    const int TOTAL_ONE=10;
    const int TOTAL_TWO=100;

    if(labGrade==0){
    cout << endl;
    cout << "***LABS***" << endl;
    cout << "What do you believe is your grade for Lab 1 out of 10 points?" << endl;
    cout << endl;
    cout << "*keep in mind that even if you did stemplosion and had 100%,\nhe never graded our reports. this is purely a guess on your end.*" << endl;
    cout << endl;
    cout << ">> ";
    cin >> scores;
    scores = (scores/TOTAL_ONE)*LAB_WEIGHT;

    cout << "What do you believe is your grade for Lab 2 out of 100 points?" << endl;
    cout << "*for this calculator, this will be added as extra credit. putting zero will not hurt you.*" << endl;
    cout << ">> ";
    cin >> labExtraCredit;
    scores += LAB_WEIGHT*(labExtraCredit/TOTAL_TWO);
    userTotals.push_back(scores);
    labGrade = (scores/LAB_TOTAL)*100;
    }
    else{
        cout << "You scored " << labGrade << "% in the HW section. ";
    }
}
void examGradeCalc(){

    double scores;

    double score_one;
    double score_two;
    double score_three;
    double score_four;

    const int TOTAL_TWO = 100;
    const int TOTAL_ONE = 6;
    const int TOTAL_THREE = 5;
    const int TOTAL_FOUR = 4;

    if(examGrade == 0){
    cout << "What did you get on Exam 2 out of 100? (The one on WileyPlus) >> ";
    cin >> score_two;
    scores = (score_two/TOTAL_TWO)*EXAM_WEIGHT;

    cout << "What did you think you got on Exam 1 out of 6 points? (Please include the one extra credit question if it applies)\n>> ";
    cin >> score_one;
    scores += (score_one/TOTAL_ONE)*EXAM_WEIGHT;

    cout << "What did you think you got on Exam 3 out of 5 points? (Please include the one extra credit question if it applies)\n>> ";
    cin >> score_three;
    scores += (score_three/TOTAL_THREE)*EXAM_WEIGHT;

    cout << "What did you think you got on Exam 4 (the final) out of 4 points? (Please include the one extra credit question if it applies)\n>> ";
    cin >> score_four;
    scores += (score_four/TOTAL_FOUR)*EXAM_WEIGHT;

    userTotals.push_back(scores);
    examGrade = (scores/EXAM_TOTAL)*100;
    }
    else {
         cout << "You scored " << examGrade << "% in the exam section. ";
    }
}
void finalGradeCalc(){

double userTotal=0;

for(double n: userTotals){
    userTotal+=n;
}

int finalGrade = (userTotal/OVERALL_TOTAL)*100;

cout << "You final grade was calculated as " << finalGrade << "%" << endl;
cout << "These were your point totals for each section: " << endl;
cout << "HOMEWORK: " << userTotals[0] << "/" << HW_TOTAL <<endl;
cout << "LABS: " << userTotals[1] << "/" << LAB_TOTAL <<endl;
cout << "EXAM: " << userTotals[2] << "/" << EXAM_TOTAL <<endl;
}