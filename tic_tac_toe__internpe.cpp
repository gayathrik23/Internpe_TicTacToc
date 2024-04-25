#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char  Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int current_player;
int current_marker;

void drawBoard(){
	cout << " "<<Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << endl;
	cout << "-----------"<<endl;
	cout << " "<<Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << endl;
	cout << "-----------"<<endl;
	cout << " "<<Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << endl;
	
}

bool placeMarker(int slot){
	int row = slot/3;
	int col;
	if(slot % 3 == 0){
		row = row-1;
		col=2;
		}
	else{
	col=(slot%3)-1;
	}
	
	if(Board[row][col]!='x' && Board[row][col]!='o')
	{
		
	  Board[row][col]=current_marker;
	  return true;
	  
}
else return false;
	
}

char winner(){
	
	for(int i=0; i < 3; i++){
	
		if (Board[i][0]== Board[i][1] &&  Board[i][1]== Board[i][2]) return current_player;

		if (Board[0][i]== Board[1][i] && Board[1][i]==Board[2][i]) return current_player;
		}
	if (Board[0][0]==Board[1][1] && Board[1][1]== Board[2][2]) return current_player;
	if (Board[0][2]==Board[1][1] && Board[1][1]== Board[2][0]) return current_player;
	return 0;
}

void swap(){
	if(current_marker=='x') current_marker='o';
	else current_marker='x';
	
	if(current_player==1) current_player=2;
	else current_player=1;
}

void game(){
	cout<<"player 1, choose marker: ";
	char marker_p1;
	cin>>marker_p1;
	current_player=1;
	current_marker=marker_p1;
	drawBoard();
	
	int player_won;
	for(int i=0;i<9;i++){
		cout<<"its player "<<current_player<<"'s turn. enter your slot: ";
		int slot;
		cin>>slot;
		
		if(slot<1 || slot>9){
			
			cout<<"that slot is invalid, try another slot ";
			i--;
			continue;
		}
		
		if(!placeMarker(slot)){
			cout<<"that slot is occupied, try another slot ";
			i--;
			continue;
		}
		drawBoard();
		
		player_won=winner();
		if(player_won==1){
			cout<<"player 1 wins";
			break;
		}
		if(player_won==2){
			cout<<"player 2 wins";
			break;
		}
		swap();
	
	}
	if(player_won==0) cout<<"its a tie ";
}
int main(){
	game();
	return 0;
}