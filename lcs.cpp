#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
std::string longest_common_subsequence(const std::string s1, const std::string s2) {
	const int lth1 = s1.size();
	const int lth2 = s2.size();
	enum class directions:char {
	    null=0,left=1,up,upleft
	};
	int depth[lth1][lth2];
	directions dir[lth1][lth2];
	memset(depth,0,sizeof(depth));
	memset(dir,0,sizeof(dir));
	for(int i = 0; i < lth1; ++i) {
		for(int j = 0; j < lth2; ++j) {
			if (s1[i] == s2[j]) {
				if( i==0 or j==0 ) depth[i][j] = 1;
				else depth[i][j] = depth[i-1][j-1]+1;
				dir[i][j] = directions::upleft;
			} else {
				if ( i == 0 and j == 0 ){
					dir[i][j] = directions::up;
				}else if( i == 0 ){
					dir[i][j] = ( 0 >= depth[i][j-1] ? directions::up : directions::left );
				}else if( j == 0 ){
					dir[i][j] = ( depth[i-1][j] >= 0 ? directions::up : directions::left );
				}else if (depth[i-1][j] >= depth[i][j-1]) {
					depth[i][j] = depth[i-1][j];
					dir[i][j] = directions::up;
				} else {
					depth[i][j] = depth[i][j-1];
					dir[i][j] = directions::left;
				}
			}
		}
	}
	//
	for(int i = -1; i < lth1; i++){
		if(i>=0) for( int j = -1; j< lth2; ++j){
			if(j>=0){
				if(dir[i][j]==directions::up) std::cout<<std::setw(6)<<"  ^";
				else if(dir[i][j]==directions::upleft) std::cout<<std::setw(6)<<"\\  ";
				else std::cout<<std::setw(6)<<"";
			}else std::cout<<std::setw(6)<<"";
		}
		std::cout<<std::endl;
		for( int j = -1; j < lth2; ++j){
			if(i<0) std::cout<< std::setw(6) << ( j>=0 ? s2[j] : ' ' );
			else if(j>=0){
				if(dir[i][j]==directions::left) std::cout<<" < "<<std::setw(3)<<depth[i][j];
				else std::cout<< std::setw(6) << depth[i][j];
			}else std::cout<< std::setw(6)<< ( i>=0 ? s1[i] : ' ' );
		}
		std::cout<<std::endl;
	}
	//
	std::string lcs = "";
	int i = lth1 - 1;
	int j = lth2 - 1;
	while ( i>=0 && j>=0 ) {
		switch(dir[i][j]) {
			case directions::upleft:
				lcs.insert(0,1,s1[i]);
				i --;
				j --;
				break;
			case directions::up:
				i --;
				break;
			case directions::left:
				j --;
				break;
			default:
				break;
		}
	}
	return lcs;
}
int main() {
	std::string s1("helloworld");
	std::string s2("hell");
	std::string s3 = longest_common_subsequence(s1, s2);
	std::cout<< s3 <<std::endl;
	system("pause");
	return 0;
}
