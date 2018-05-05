/*#include <iostream>
using namespace std;
int main(){
    int mysize = 10;
    int *badptr = new int[mysize];
    
    cout << "address of pointer " << &badptr << endl;
    cout << "1=" << badptr[0] << endl;
    badptr[1] = 5;
    
    cout << "everything worked" << endl;
    delete [] badptr; //[] deletes every element in the array
};*/

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

int main()
{
	stringstream ss("Speedy R P");
	string name, type;
	int speed;
	ss.exceptions(ios_base::failbit);

	try {
	    ss >> name >> type >> speed;
	} 
	catch(ios_base::failure& ex) {
	    cout << "Error "<<ex.what()<<endl;
	}
}