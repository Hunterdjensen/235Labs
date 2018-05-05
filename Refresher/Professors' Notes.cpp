#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> //necessary for sort 

using namespace std;

int main(int argc, char *argv[]) //The arguments for the command line
{
    vector<string> names; //creates a vector of names
    cout << "Hello World!" << endl;
    cout << "argc "<<argc<<" argv[0] "<<argv[0]<<" argv[1]= "<<argv[1]<<endl; //Prints out the count of #arguments, and the first and second
    if(argc != 2) {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl; //If too many arguments
    } else {
        ifstream fileHandle(argv[1]);
        if(!fileHandle.is_open()) {
            cout << "Could not open file"<<endl;
        } else {
            string name; //reads in a name
            int age; // and then an age
            while(fileHandle>>name>>age) { //while there are still names and ages to read
                cout << "Name "<<name<<"\t\t"<<" Age "<<age<<endl;
                names.push_back(name);
            }
        }
    }
    sort(names.begin(), names.end()); //sorts the vector in alphabetical order (<)
    ofstream outHandle("sorted.txt"); //creates an output file
    for(vector<string>::iterator it=names.begin(); //it is like a for loop instead of i, it iterates through
      it!=names.end(); it++) {
          cout << *it<<endl; //prints out the pointer, or the name
          outHandle << *it <<endl; //prints it out to the output file as well
    }
}
