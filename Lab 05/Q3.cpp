
#include<iostream>
using namespace std;
class ValidateString{
    private:
    string str;
    public:
    ValidateString(string str):str(str){}
    //Making validatestring function constant as it doesn't change the state of the object.
    // const means this function will not modify any member variables of the class
    // Function to validate if the string contains only alphabetic characters
     void validatestring(string str1)const{
        for(int i=0;i<str1.length();i++){
            if(str1[i]>='a'&&str1[i]<='z'||str1[i]>='A'&&str1[i]<='Z'){
                continue;
            }
            else{
                cout << "Invalid string" << endl;
                return;
            }
        }
        cout << "Valid string" << endl;

     }

};
int main(){
    ValidateString vs1("Hello123!");
    vs1.validatestring("Hello123!");
    ValidateString vs2("Hello123@");
    vs2.validatestring("Hello123@");
    return 0;
}
