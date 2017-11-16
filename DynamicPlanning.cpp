#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct item {// 结构体定义重量和价值 
	int weight;
	int value;
};

int DynamicPrograming(int ItemMax,item ItemInfo[],int Capacity) {
	int list[ItemMax][Capacity+1];
	bool ItemIsLoaded[200];
	int i,j;
	memset(list,0,sizeof(list));
	memset(ItemIsLoaded,0,sizeof(ItemIsLoaded));
	for(i=0; i<ItemMax; i++){
		for(j=0; j<=Capacity; j++){
			if(j<ItemInfo[i].weight){
				list[i][j] = i>0 ? list[i-1][j] : 0;
			} else {
				if( i>0 and j>0 ) {
					list[i][j] = max(list[i-1][j],list[i-1][j-ItemInfo[i].weight]+ItemInfo[i].value);
				} else list[i][j] = ItemInfo[i].value;
			}
		}
	}
	j = Capacity;
	for(i=ItemMax-1; i>=0; i--) {
		if(i==0 or list[i][j]>list[i-1][j]) {
			ItemIsLoaded[i] = 1;
			j -= ItemInfo[i].weight;
		} else ItemIsLoaded[i] = 0;
	}

	for(i=0; i<ItemMax; i++)
		printf("物品%d%s装进背包\n",i,(ItemIsLoaded[i]?"已":"未"));

	return list[ItemMax-1][Capacity];
}
int main() {
	item ItemInfo[5] = {{2,6},{2,3},{6,5},{5,4},{4,6}};
	int ItemMax = 5;//物品总量
	int SackCapacity = 10;//容纳重量
	int OptimalValue = 0;//最大价值

	OptimalValue = DynamicPrograming (ItemMax,ItemInfo,SackCapacity);

	printf("背包中的总价值:\n");
	printf("%d\n",OptimalValue);

}


