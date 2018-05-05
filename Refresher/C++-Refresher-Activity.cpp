#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;
ofstream myOfile;

class Fisherman {
public:
   Fisherman(string aName = "No name", int aPounds = 0, string aType = "None");
   string GetName() const;
   int GetPounds() const;
   string GetType() const;
   string ToString() const;
protected:
   string name;
   int pounds;
   string type;
};

Fisherman::Fisherman(string aName, int aPounds, string aType){
   name = aName;
   pounds = aPounds;
   type = aType;
}

string Fisherman::GetName() const {
   return name;
}

int Fisherman::GetPounds() const {
   return pounds;
}

string Fisherman::GetType() const {
   return type;
}

string Fisherman::ToString() const {
   ostringstream outSS;
   outSS << name << "\t\t" << pounds << "\t" << type;
   return outSS.str();
}

void AddFisherman(vector<Fisherman*>& allFishermen, string aName, string aType, int aPounds) {
   Fisherman* newFisherman = nullptr;
   newFisherman = new Fisherman(aName, aPounds, aType);
   allFishermen.push_back(newFisherman);
}

void SearchForFish(vector<Fisherman*>& allFishermen, string aSearchType) {
   int numTimes = 0;
   for (int i = 0; i < allFishermen.size(); ++i) {
      if (allFishermen.at(i)->GetType() == aSearchType) {
         myOfile << allFishermen.at(i)->GetName() << " caught " << allFishermen.at(i)->GetPounds() << " pounds of " << aSearchType << endl;
         numTimes = numTimes + 1;
      }
   }
   if(numTimes == 0) {
      myOfile << "No " << aSearchType << endl;
   }
}

int main(int argc, char *argv[]) {
   vector<Fisherman*> allFishermen;
   string aName;
   string aType;
   string aSearchType;
   string lineString;
   int aPounds = 0;
   istringstream inSS;
   ifstream inFS;
   
   myOfile.open(argv[2]);
   
   inFS.open(argv[1]);
   if (!inFS.is_open()) {
      myOfile << "Could not open file final.txt." << endl;
      return 1; // 1 indicates error
   }
   while(aName != "Search") {
      getline(inFS, lineString);
      inSS.clear();
      inSS.str(lineString);
      inSS >> aName;
      if(aName == "Search"){
         break;
      }
      inSS >> aPounds;
      inSS >> aType;
      AddFisherman(allFishermen, aName, aType, aPounds);
   } 
   inSS >> aSearchType;
   inFS.close();
   
   myOfile << endl << endl;
   
   for (int i = 0; i < allFishermen.size(); ++i) {
      myOfile << allFishermen.at(i)->ToString() << endl;
   }
         
   myOfile << endl << "Type wanted: " << aSearchType << endl;
   SearchForFish(allFishermen, aSearchType);
   
   myOfile.close();
   //cout << "Goodbye!" << endl;
   return 0;
}