#include <iostream>
using namespace std;

void numeric()
{
    char a[50];

    cout << "Enter an input: ";
    cin >> a;

    for(int i = 0; a[i] != '\0'; i++)
    {
        if(a[i] < 48 || a[i] > 57)
        {
            cout << "Not Numeric";
            return;
        }
    }

    cout << "Numeric";
}

void isOperator(){

    char a[50];

    cout << "Enter an input: ";
    cin >> a;

    char sym[]={'+','-','*','/','%','='};
     int count = 1;
    for(int i=0;a[i]!=0;i++){
        for(int j = 0; j<6 ;j++){
            if(a[i] == sym[j] ){
                cout<< "Operator"<<count<<": "<<a[i]<<endl;
                count++;
            }
        }
    }
}

void iscomment() {

    char a[50];

    cout << "Enter an input: ";
    cin >> a;

     if (a[0] == '/' && a[1] == '/') {
        cout << "This is a Single-line Comment";
    }
    else if (a[0] == '/' && a[1] == '*') {

        int i = 2; 

        while (a[i] != '\0') {

            if (a[i] == '*' && a[i + 1] == '/') {
                cout << "This is a Multi-line Comment";
            }
            i++;
        }
    }
    else {
        cout << "Not a Comment";
    }
}

void isIdentifier(){

    char a[50];

    cout << "Enter an input: ";
    cin >> a;

   
        if(!((a[0] >= 'a' && a[0] <= 'z') || (a[0] >= 'A' && a[0] <= 'Z')|| a[0] == '_')){
            cout << "Not an Identifier";
            return;
        }
        
        for(int i = 0; a[i] != '\0'; i++){
        if(!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9') || a[i] == '_')){
            cout << "Not an Identifier";
            return;
        }
    }
    cout << "This is an Identifier" ;

}

float findAverage() {

    int arr[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }


    cout<<"Average: "<< (float)sum / n;
}

int minMax(){
    
int arr[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Maximum = " << max << endl;


    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Minimum = " << min << endl;
}

void addName(){
    string firstName, lastName, fullName;

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    fullName = firstName + " " + lastName;
    cout << "Full Name: " << fullName << endl;

}

int main()
{
    int choice;
    
    cout << "1. Numeric Constant Check" << endl;
    cout << "2. Operator Check" << endl;
    cout << "3. Comment Check" << endl;
    cout << "4. Identifier Check" << endl;
    cout << "5. Find Average" << endl;
    cout << "6. Min and Max" << endl;
    cout << "7. Add Name" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            numeric();
            break;

        case 2:
            isOperator();
            break;

        case 3:
            iscomment();
            break;

        case 4:
            isIdentifier();
            break;

        case 5:
            findAverage();
            break;

        case 6:
            minMax();
            break;

        case 7:
            addName();
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}