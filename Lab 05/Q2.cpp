/*
Task-02:
Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%*/
#include<iostream>
using namespace std;
float validaterate(float rate){
    if(rate>=0&&rate<=0.5){
        return rate;
    }
    else{
        cout << "Invalid interest rate. Please enter a value between 0 and 0.5%" << endl;
        return 0.0;
    }
}
class LoanHelper{
    const float interestrate;
    float loanamount;
    float amountbepaid;
    int month;
    public:
    LoanHelper(float interest, float loan, int months):interestrate(validaterate(interest)),loanamount(loan), month(months){
        amountbepaid = loanamount / month;
    }
    void calculatePayment(){
        float interest,amount;
        amount = loanamount / month;
        interest=amount+(amount*(interestrate/100));
        cout << "You have to pay $" << interest << " every month for " << month << " months to repay your loan." << endl;


    }

};

int main(){
    LoanHelper loanHelper(0.005, 10000, 12);
    loanHelper.calculatePayment();
}

