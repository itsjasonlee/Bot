#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //abs()
using namespace std;
//This program calculates the APM Difference grouped into different points.

class apmdifference{
	public:
	int difference=0;
	bool higherapmwon=false;
	apmdifference *next= NULL;
	apmdifference();


};
apmdifference::apmdifference(){};


int main()
{

	ifstream ifile;
	ifile.open("fulllog.log");
	if(!ifile)
	{
		cerr<< "Error opening file. \n";
		return -1;
	}
	apmdifference* Head= new apmdifference;
	ofstream outAPMDifference;
	outAPMDifference.open("APM_Difference.log");//calculates absolute value of difference
	ofstream outAPMDifferencesBool;
	outAPMDifferencesBool.open("APM_DifferenceBool.log");


	string instring;
	getline(ifile,instring); //ignore file location

	getline(ifile,instring); //ignore ------ buffer

	getline(ifile,instring); //ignore structure

	size_t pos = 0;
	string filename;
	int build;
	string map_name;
	int game_duration_loops;
	int players;
	string p1outcome;
	string p1race;
	int p1apm;
	string p2race;
	int p2apm;

	while(!ifile.eof())
	{
		getline(ifile,instring);

		pos = instring.find(',',0);//filename
		filename = instring.substr(0, pos);
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//build
		build = atoi(instring.substr(0,pos).c_str());
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//map_name
		map_name = instring.substr(0, pos);
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//game_duration_loops
		game_duration_loops = atoi(instring.substr(0,pos).c_str());
		instring = instring.substr(pos + 1);		

		pos = instring.find(',',0);//players
		players = atoi(instring.substr(0,pos).c_str());
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//p1-outcome
		p1outcome = instring.substr(0, pos);
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//p1-race
		p1race = instring.substr(0, pos);
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//p1-apm
		p1apm = atoi(instring.substr(0,pos).c_str());
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//p2-race
		p2race = instring.substr(0, pos);
		instring = instring.substr(pos + 1);

		pos = instring.find(',',0);//p2-apm
		p2apm = atoi(instring.substr(0,pos).c_str());
		instring = instring.substr(pos + 1);
		
		apmdifference*node = new apmdifference;
		node->difference = abs(p1apm-p2apm);
		if(p1apm>=p2apm && p1outcome=="Victory")
			node->higherapmwon=true;
		else if(p2apm>=p1apm && p1outcome == "Defeat")
			node->higherapmwon=true;
		else
			node->higherapmwon=false;

		apmdifference* p = Head;
		for(;p->next!=NULL && p->next->difference<node->difference;p=p->next)
		{}//this should put this wear the node should be.
		node->next = p->next;
		p->next = node;
		cout<< abs(p1apm-p2apm)<<endl;

	}

apmdifference * q = Head;
while (q->next !=NULL )
{
	outAPMDifference << q->difference <<endl;
	outAPMDifferencesBool<< q->higherapmwon<<endl;
	q = q->next;
}
outAPMDifference.close();
outAPMDifferencesBool.close();

string loop;
	cin>> loop;
		return 1;

}