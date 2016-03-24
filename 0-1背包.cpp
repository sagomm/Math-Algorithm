#include "iostream"
#include "vector"
using namespace std;

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
		os << "该物品的重量是: "<< obj.weigth <<"  "<< "该物品的价值是:"<< obj.value << endl;
		return os;
	}
	int weigth = 0;
	int value = 0;
	bool status = 0;
};
class Knapsack
{
public:
	vector<Object> objs;
	int total = 0; 
};
int main()
{
	int total;
	int limit;
	Knapsack knapsack;
	cout << " 请输入物品总数:\n";
	cin >> total;
	cout << "请输入物品重量 价值\n";
	for(int i = 0;i<total;i++){
		Object _tmp;
		if(cin >> _tmp){
			knapsack.objs.push_back(_tmp);
		}
	}
	
	cin >> _tmp;
	cout << "请输入背包重量限制:\n";
	cin >> limit;
	cout << _tmp;
	return 0;
}