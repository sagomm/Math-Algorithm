/*
  蒙提霍尔问题是个简单的电视游戏，
  在节目中三扇门后面只有一扇门有奖品
  观众会被要求在三扇门中间选择一个，如果门后面有奖品则算中奖。
  在观众选择完后，主持人会打开一扇没有奖品的门，这时候观众有一次更改当初选择的机会。
  问：更改选择与不更改选择哪个中奖的概率高？
*/    

#include <iostream> 
#include <stdlib.h> 
#include <time.h> 

using namespace std;

/*
* @param dSelect 选择的门号
* @param dChange 0表示不改变选择，1表示改变选择
* @return int  0表示中奖，1表示不中奖
*/
int MontyHall(int dSelect,int dChange){
    //初始化奖品的位置
	int dCar = rand()%3+1;
    //对于枚举每种情形是否中奖
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

	int changeRom = 0;//每次改变的中奖次数
	int unChangeRom = 0;//每次不改变的中奖次数

	int times = 10000;

	for(;times > 0;times--){
		changeRom += MontyHall(rand()%3+1,1);
		unChangeRom += MontyHall(rand()%3+1,0);
	}
	cout << "在10000次实验中,换了中奖的次数是: " << changeRom << "\n";
	cout << "在10000次实验中,没换中奖的次数是: " << unChangeRom << "\n"; 
	return 0;
}