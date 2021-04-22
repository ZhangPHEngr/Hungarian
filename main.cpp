#include<iostream>
#include<string.h >
/*
匈牙利算法：用以解决二分图最大匹配问题
算法思想：先到先占，能让就让
参考：https://blog.csdn.net/dark_scope/article/details/8880547
*/

const int m = 4;//左侧的m个点，属于X点集合
const int n = 4;//右侧的n个点，属于Y点集合
int map[m][n] = {{1,1,0,0},{0,1,1,0},{1,1,0,0},{0,0,1,0}};//记录m*n的关联矩阵，描述XY的连线关系
int used[n];//X点集合中，当前点腾挪占用记录
int Y2X[n];//记录Y中各个点分配的X点ID
int cnt = 0;//最大匹配计数

bool find(int x){
	
	for (int j=0;j<n;j++){    //扫描每个Y集合中的点
		if (map[x][j]==1 && !used[j])      
		//有关联且没有使用当前Y集合中的点
		{
			used[j]=1;
			if (Y2X[j]==-1 || find(Y2X[j])) { 
				Y2X[j]=x;
				return true;
			}
		}
	}
	return false;
}

int main(){
    memset(Y2X,-1,sizeof(Y2X));
    for (int i=0;i<m;i++)//遍历每个X集合中的点
    {
	    memset(used,0,sizeof(used));//每次遍历前都清空占用情况
	    if(find(i)){
            cnt+=1;
        }
            
    }
    std::cout<<"最大匹配为："<< cnt<<std::endl;
}