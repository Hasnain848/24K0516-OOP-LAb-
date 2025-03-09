#include<iostream>
using namespace std;
class Message{
    private:
    string text;
    public:
    Message():text(""){}
    Message(string text):text(text){}
    string toString()const{ return text;}
    void setstring(string t1){text = t1;}
};
class SMS : public Message{
    private:
    string contactNo;
    public:
    SMS():Message(""),contactNo(""){}
    SMS(string no, string text) : Message(text), contactNo(no) {}
    string getcontactno(){return contactNo;}
    void setcontactno(string no){contactNo = no;}
    string toString()const{
        return Message::toString() + " (Contact no : " + contactNo + ")";
    }
};
class Email : public Message{
    private:
    string sender,receiver,subject;
    public:
    Email() :Message(""),sender(""), receiver(""), subject("") {}
    Email(string text, string sender, string receiver, string subject)
        : Message(text), sender(sender), receiver(receiver), subject(subject) {}
    void setSender(const string &s) { sender = s; }
    void setReceiver(const string &r) { receiver = r; }
    void setSubject(const string &sub) { subject = sub; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    string toString()const{
        return "From: " + sender + "\nTo: " + receiver + "\nSubject: " + subject +
               "\nMessage: " + Message::toString();
    }
};
bool ContainsKeyword(const Message &messageObject, const string &keyword) {
    string text = messageObject.toString();
    return text.find(keyword) != string::npos;
}
void encodemessage(Message &m1){
    string s1=m1.toString();
    int size = s1.length();
    for(int i=0;i<size;i++){
        if(s1[i]>='a'&&s1[i]<='z'||s1[i]>='A'&&s1[i]<='Z'){
            if(s1[i]=='z'){
                s1[i]='a';
            }
            else if(s1[i]=='Z'){
                s1[i]='A';
            }
            else s1[i]++;
        }
    }
    m1.setstring(s1);
}
int main(){
    SMS S1("03451234567", "Hello, this is a test message.");
    Email E1("This is an important email.", "alice@example.com", "bob@example.com", "Meeting Reminder");
    cout << "Original SMS:\n" << S1.toString() << "\n\n";
    cout << "Original Email:\n" << E1.toString() << "\n\n";
    string keyword = "test";
    cout<<"Does Sms contain '"<<keyword<<"'?"<<(ContainsKeyword(S1,keyword)?"Yes":"No")<<endl;
    keyword ="Meeting";
    cout<<"Does Email contain '"<<keyword<<"'?"<<(ContainsKeyword(E1,keyword)?"Yes":"No")<<endl;
    encodemessage(S1);
    encodemessage(E1);
    cout << "\nEncoded SMS:\n" << S1.toString() << "\n\n";
    cout << "Encoded Email:\n" << E1.toString() << "\n\n";

}