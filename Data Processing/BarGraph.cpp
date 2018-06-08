#include<iostream>
#include<fstream>
using namespace std;
void output(ifstream&Input,ofstream&Output)
{
	int arr[600] {0};
	int inp;
	int index;
	while(!Input.eof())
	{
		Input>> inp;
		arr[inp/1000]+=1;
	}
	for(int i=0;i<600;i++)
	{
		Output << arr[i]<<endl;
	}
}
int main()
{
	ifstream infileWinProtoss;
	ifstream infileWinZerg;
	ifstream infileWinTerran;
	ifstream infileLoseProtoss;
	ifstream infileLoseZerg;
	ifstream infileLoseTerran;
	infileWinProtoss.open("Calc_WinTimeProtoss.log");
	infileWinTerran.open("Calc_WinTimeTerran.log");
	infileWinZerg.open("Calc_WinTimeZerg.log");
	infileLoseTerran.open("Calc_LoseTimeTerran.log");
	infileLoseProtoss.open("Calc_LoseTimeProtoss.log");
	infileLoseZerg.open("Calc_LoseTimeZerg.log");
	ofstream outfileWinProtoss;
	ofstream outfileWinZerg;
	ofstream outfileWinTerran;
	ofstream outfileLoseProtoss;
	ofstream outfileLoseZerg;
	ofstream outfileLoseTerran;

	outfileWinTerran.open("WinTimeTerran.result");
	outfileWinZerg.open("WinTimeZerg.result");
	outfileWinProtoss.open("WinTimeProtoss.result");
	outfileLoseTerran.open("LoseTimeTerran.result");
	outfileLoseZerg.open("LoseTimeZerg.result");
	outfileLoseProtoss.open("LoseTimeProtoss.result");

	output(infileWinZerg,outfileWinZerg);
	output(infileWinTerran,outfileWinTerran);
	output(infileWinProtoss,outfileWinProtoss);
	output(infileLoseZerg,outfileLoseZerg);
	output(infileLoseTerran,outfileLoseTerran);
	output(infileLoseProtoss,outfileLoseProtoss);

}