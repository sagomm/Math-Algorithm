#include "iostream"
#include "vector"
using namespace std;
#ifndef MAX_WEIGTH
#define MAX_WEIGTH 10000
#endif

class Object
{
public:
	Object(int w,int v)
	:weigth(w)
	,value(v)
	{}
	Object(){}
	friend istream& operator >>(istream& is,Object& obj){
		is >> obj.weigth >> obj.value;
		return is;
	}
	friend ostream& operator <<(ostream& os,Object& obj){
		os << "该物品的重量是: "<< obj.weigth <<"  "<< "该物品的价值是: "<< obj.value << endl;
		return os;
	}
	int weigth = 0;
	int value = 0;
	int statu = 0;
};
class Knapsack
{
public:
	vector<Object> objs;
	int total = 0; 
};
int planA(Knapsack pack,int limit){
	int value = 0;

	while(value < limit){
		int ;
		for(auto &x : pack.objs){
			if((x.statu == 0) && (x.value > best.value)){
				best = &x;
			}		
		}
		if(best.statu == 0){
			best.statu = 1;
		}

		if(best.value == 0){
			break;
		}else{
			value += best.value;			
		}
	}
	return value;
}

// int planB(pack Knapsack,int limit){
// 	int value = 0;
// 	while(value < limit){
// 		int best = 0;	
// 		for(auto &x : pack.objs){
// 			if((x.statu == 0 ) && (x.weigth < best)){
// 				cout << x << endl;
// 				best = x.value;
// 				x.statu = 1;
// 			}		
// 		}
// 		value += best;			
// 	}
// 	return value;
// }

// int planC(pack Knapsack,int limit){
// 	int value = 0;
// 	int _value = 0;
// 	while(_value > limit){
// 		value = _value;
// 		int best = MAX_WEIGTH;
// 		for(int i = pack.objs.begin();i != pack.objs.end();i++){
// 			if(((pack.objs[i].weigth/pack.objs[i].value) > best) && (pack.objs[i].statu == 0)){
// 				best = pack.objs[i].value;
// 				pack.objs[i].statu = 1;
// 			}
// 		}
// 		_value += best;	
// 	}
// 	return value;
// }
// int planD(pack Knapsack,int limit){
	
// }

int main()
{
	int total;
	int limit;
	Knapsack _knapsack;
	Knapsack knapsack;
	cout << " 请输入物品总数:\n";
	cin >> total;
	cout << "请输入物品重量 价值\n";
	for(int i = 0;i<total;i++){
		Object _tmp;
		if(cin >> _tmp){
			_knapsack.objs.push_back(_tmp);
		}
	}
	cout << "请输入背包重量限制:\n";
	cin >> limit;
	
	cout << planA(_knapsack,limit) << endl;
	// cout << planB() << endl;
	return 0;
}
