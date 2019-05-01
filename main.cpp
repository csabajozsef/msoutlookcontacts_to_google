#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

/* The input file must be saved in .csv and in the right format, meaning that the exported file could differ in
the number off colums and other inline features I used to separate my text.I might write a part where the user could set these to match the need.
The file must be in the same folder as your program.*/

using namespace std;

struct Contact {
string name;
string address;
};

vector<Contact> filein (string in_name){

ifstream file_in;
vector<Contact>contacts;
stringstream ss;
string row;
string namepart1;
string namepart2;
string namepart3;
Contact tempcontact;

    file_in.open(in_name);

        if (file_in.fail()){
            cout<<" Can't open file. "<<endl;
        }

getline(file_in,row); //first row

        while(getline(file_in,row)) {
            ss<<row;
            getline(ss,namepart1,',');
            tempcontact.name=namepart1;
            tempcontact.name+=";";
            //tempcontact.name.erase(0,1);
            //getline(ss,namepart3,'"');//These were necessary modifications for the file I used as input.

            getline(ss,tempcontact.address);
            //tempcontact.address.erase(tempcontact.address.size()-3,3);
            //tempcontact.address.erase(0,1); //These were necessary modifications for the file I used as input.
            contacts.push_back(tempcontact);
            ss.clear();
            //cout<<tempcontact.name<<" --- "<<tempcontact.address<<endl; //Uncomment this line if you want to write out the content of the file in the terminal.
        }
return contacts;
}

void fileout(ofstream&file_out,vector<Contact>contacts){

file_out.open("Output.csv");

    if( file_out.fail()){
         cout<<" Can't open outputfile. "<<endl;
    }

    file_out<<"Name" <<";"<<"Email"<<"\n";

    for(int i=0;i<contacts.size();i++){
        file_out<<contacts[i].name <<contacts[i].address<<"\n";
    }
}

int main()
{
    string file_name;
    cout<<"Enter the filename:"<<endl;
    cin>>file_name;
    file_name+=".csv";
    vector<Contact>contacts=filein(file_name);
    ofstream file_out;
    fileout(file_out,contacts);

    cout << "Done." << endl;
    return 0;
}
