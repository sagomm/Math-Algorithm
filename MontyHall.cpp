#include <iostream> 
#include <stdlib.h> 
#include <time.h> 

using namespace std;

int MontyHall(int dSelect,int dChange){
	int dCar = rand()%3+1;
	if((dCar == dSelect) && (dChange == 0)){
		return 1;
	}else if((dCar != dSelect) && (dChange == 0)){
		return 0;
	}else if((dCar == dSelect) && (dChange == 1)){
		return 0;
	}else if((dCar != dSelect) && (dChange == 1)){
		return 1;	
	}
}
int main(int argc, char const *argv[])
{
	srand((int)time(0));

	int changeRom = 0;
	int unChangeRom = 0;

	int times = 10000;

	for(;times > 0;times--){
		changeRom += MontyHall(rand()%3+1,1);
		unChangeRom += MontyHall(rand()%3+1,0);
	}
	cout << "在10000次实验中,换了中奖的次数是: " << changeRom << "\n";
	cout << "在10000次实验中,没换中奖的次数是: " << unChangeRom << "\n"; 
	return 0;
}