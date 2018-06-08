#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//This program calculates the time in which races win

int main()
{

	ifstream ifile;
	ifile.open("fulllog.log");
	if(!ifile)
	{
		cerr<< "Error opening file. \n";
		return -1;
	}
	ofstream outWinTimeGameZerg;
	outWinTimeGameZerg.open("Calc_WinTimeZerg.log");
	ofstream outWinTimeGameProtoss;
	outWinTimeGameProtoss.open("Calc_WinTimeProtoss.log");
	ofstream outWinTimeGameTerran;
	outWinTimeGameTerran.open("Calc_WinTimeTerran.log");



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
		
		if(p1outcome=="Victory")
		{
			if(p1race == "Terran")
			{
				outWinTimeGameTerran << game_duration_loops<<endl;
			}
			else if(p1race == "Protoss")
			{
				outWinTimeGameProtoss << game_duration_loops<<endl;				
			}
			else if(p1race == "Zerg")
			{
				outWinTimeGameZerg<< game_duration_loops<<endl;				
			}
		}
		else if(p1outcome=="Defeat")
		{
			if(p2race == "Terran")
			{
				outWinTimeGameTerran << game_duration_loops<<endl;
			}
			else if(p2race == "Protoss")
			{
				outWinTimeGameProtoss << game_duration_loops<<endl;				
			}
			else if(p2race == "Zerg")
			{
				outWinTimeGameZerg<< game_duration_loops<<endl;				
			}
		}

	}
outWinTimeGameZerg.close();
outWinTimeGameProtoss.close();
outWinTimeGameTerran.close();

string loop;
	cin>> loop;
		return 1;

}