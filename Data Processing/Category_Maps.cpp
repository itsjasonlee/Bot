#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//This program calculates the average APM for winner and loser.
int main()
{

	ifstream ifile;
	ifile.open("fulllog.log");
	if(!ifile)
	{
		cerr<< "Error opening file. \n";
		return -1;
	}
	ofstream outfile_abyssal;
	outfile_abyssal.open("Map_Abyssal_Reef_LE.log");
	ofstream outfile_Catallena;
	outfile_Catallena.open("Map_Catallena_LE_(Void).log");
	ofstream outfile_Interloper;
	outfile_Interloper.open("Map_Interloper_LE.log");
	ofstream outfile_Acolyte;
	outfile_Acolyte.open("Map_Acolyte_LE.log");
	ofstream outfile_Mech_Depot_LE;
	outfile_Mech_Depot_LE.open("Map_Mech_Depot_LE.log");
	ofstream outfile_Odyssey_LE;
	outfile_Odyssey_LE.open("Map_Odyssey_LE.log");
	ofstream outfile_Ascension_to_Aiur_LE;
	outfile_Ascension_to_Aiur_LE.open("Map_Ascension_to_Aiur_LE.log");




	string instring;

	getline(ifile,instring); //ignore file location
	getline(ifile,instring); //ignore ------ buffer
	getline(ifile,instring); //ignore structure

	size_t pos = 0;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m=0;
	int n=0;
	int o=0;
	int others=0;
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

	string copystring;
	while(!ifile.eof())
	{
		getline(ifile,instring);
		copystring = instring;
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

		if(map_name == "Abyssal Reef LE")
		{
			outfile_abyssal << copystring<<endl;
			i++;
		}
		else if(map_name == "Catallena LE (Void)")
		{
			outfile_Catallena << copystring<<endl;
			j++;
		}
		else if(map_name == "Interloper LE")
		{
			outfile_Interloper << copystring<<endl;
			k++;
		}
		else if(map_name == "Acolyte LE")
		{
			outfile_Acolyte << copystring<<endl;
			l++;
		}
		else if(map_name == "Mech Depot LE")
		{
			outfile_Mech_Depot_LE << copystring<<endl;
			m++;
		}
		else if(map_name == "Odyssey LE")
		{
			outfile_Odyssey_LE << copystring<<endl;
			n++;
		}
		else if(map_name == "Ascension to Aiur LE")
		{
			outfile_Ascension_to_Aiur_LE << copystring<<endl;
			o++;
		}
		else
		{	others++;
			cout<< map_name <<endl;}
	}
	outfile_abyssal.close();
	outfile_Catallena.close();
	cout << "Success in gathering Abyssal Reef map games. Count: "<< i<<endl;
	cout << "Success in gathering Catallena map games. Count: "<< j <<endl;
	cout << "Success in gathering Interloper map games. Count: "<< k <<endl;
	cout << "Success in gathering Acolyte map games. Count: "<< l <<endl;
	cout << "Success in gathering Mech Depot map games. Count: "<< m <<endl;
	cout << "Success in gathering Odyssey map games. Count: "<< n <<endl;
	cout << "Success in gathering Ascension map games. Count: "<< o <<endl;
	cout << "Others missed: "<< others;

string loop;
	cin>> loop;
		return 1;

}