#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//This program calculates the average APM for winner and loser.
int main()
{

	ifstream ifile;
	ifile.open("midgame.log");
	if(!ifile)
	{
		cerr<< "Error opening file. \n";
		return -1;
	}

	int Z


	
	int LosersAPM[65000];

	string instring;
	getline(ifile,instring); //ignore file location

	getline(ifile,instring); //ignore ------ buffer

	getline(ifile,instring); //ignore structure

	size_t pos = 0;
	int i=0;
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

		if(p1outcome == "Victory")
		{
			WinnersAPM[i]= p1apm;
			LosersAPM[i] = p2apm;

		}
		else
		{
			WinnersAPM[i]= p2apm;
			LosersAPM[i]= p1apm;
		}
		i++;

	}

	double WinnersAPMAverage=0;
	double LosersAPMAverage=0;
	for(int j=0;j < i; j++)
	{
		WinnersAPMAverage+=WinnersAPM[j];
		LosersAPMAverage+=LosersAPM[j];
	}

	cout<< "Winners APM Average: " << WinnersAPMAverage/(i-1)<<endl;
	cout<< "Losers APM Average: " << LosersAPMAverage/(i-1)<<endl;
string loop;
	cin>> loop;
		return 1;

}