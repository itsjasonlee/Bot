#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//This program displays the wins/loss per ZvT, ZvP, PvT,
int main()
{

	ifstream ifile;
	ifile.open("MidGame.log");
	if(!ifile)
	{
		cerr<< "Error opening file. \n";
		return -1;
	}
	string instring;

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

    int sameracegame = 0;
    
    int ZwinvT =0;
    int ZwinvP =0;
    int TwinvZ = 0;
    int TwinvP = 0;
    int PwinvZ = 0;
    int PwinvT =0;
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

		if(p1race == "Zerg" && p2race == "Terran") //ZvT
		{
			if(p1outcome == "Victory")
                ZwinvT+=1;
            else if(p1outcome == "Defeat")
                TwinvZ+=1;
		}
        else if(p1race == "Zerg" && p2race == "Protoss") //ZvP
        {
            if(p1outcome == "Victory")
                ZwinvP+=1;
            else if(p1outcome == "Defeat")
                PwinvZ+=1;
        }		
        else if(p1race == "Terran" && p2race == "Zerg") //TvZ
        {
            if(p1outcome == "Victory")
                TwinvZ+=1;
            else if(p1outcome == "Defeat")
                ZwinvT+=1;
        }
        else if(p1race == "Terran" && p2race == "Protoss") //TvP
        {
            if(p1outcome == "Victory")
                TwinvP+=1;
            else if(p1outcome == "Defeat")
                PwinvT+=1;
        }
        else if(p1race == "Protoss" && p2race == "Zerg") //PvZ
        {
            if(p1outcome == "Victory")
                PwinvZ+=1;
            else if(p1outcome == "Defeat")
                ZwinvP+=1;
        }
        else if(p1race == "Protoss" && p2race == "Terran") //PvT
        {
            if(p1outcome == "Victory")
                PwinvT+=1;
            else if(p1outcome == "Defeat")
                TwinvP+=1;
        }
        else
            sameracegame+=1;
		i++;

	}

    cout<< "Zerg win over Protoss: " << ZwinvP<<endl;
    cout<< "Zerg win over Terran: " << ZwinvT<<endl;
    cout<< "Terran win over Zerg: " << TwinvZ<<endl;
    cout<< "Terran win over Protoss: " << TwinvP<<endl;
    cout<< "Protoss win over Terran: " << PwinvT<<endl;
    cout<< "Protoss win over Zerg: " << PwinvZ<<endl;
    cout<< "Number of same race game: "<<sameracegame<<endl;

string loop;
	cin>> loop;
		return 1;

}
