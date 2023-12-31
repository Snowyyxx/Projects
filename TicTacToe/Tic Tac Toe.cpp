#include<iostream>
#include<vector>

class TicTacToe{
 
    std::vector<std::vector<char>>GameGrid;
    bool GameOver;
    

    void CheckWin(){
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(GameGrid[i][j]!=' '){
                 
                    if(j+2<3&&GameGrid[i][j]==GameGrid[i][j+1] && GameGrid[i][j]==GameGrid[i][j+2]){
                        GameOver=true;
                        DisplayBoard();
                        std::cout<<"We have a winner!"<<std::endl;
                        if(GameGrid[i][j]=='O'){
                            std::cout<<"Circle Wins! Game Over :)"<<std::endl;
                        }else{
                            std::cout<<"Cross Wins! Game Over :)";
                        }

                    }

                    else if(i+2<3&&GameGrid[i][j]==GameGrid[i+1][j] && GameGrid[i][j]==GameGrid[i+2][j]){
                        GameOver=true;
                        DisplayBoard();
                        std::cout<<"We have a winner!"<<std::endl;
                        if(GameGrid[i][j]=='O'){
                            std::cout<<"Circle Wins! Game Over :)"<<std::endl;
                        }else{
                            std::cout<<"Cross Wins! Game Over :)";
                        }

                    }
                    else if(j+2<3&&i+2<3&&GameGrid[i][j]==GameGrid[i+1][j+1] && GameGrid[i][j]==GameGrid[i+2][j+2]){
                        GameOver=true;
                        DisplayBoard();
                        std::cout<<"We have a winner!"<<std::endl;
                        if(GameGrid[i][j]=='O'){
                            std::cout<<"Circle Wins! Game Over :)"<<std::endl;
                        }else{
                            std::cout<<"Cross Wins! Game Over :)";
                        }


                    }
                    
                }
            }
        }


    }

    bool CheckDraw(){
        int count=0;
        for(auto i =0;i<3;i++){
            for(auto j =0;j<3;j++){
                if(GameGrid[i][j]!=' '){
                    count++;
                }
            }
        }
        if(count==9){
            std::cout<<"ITS A DRAW!"<<std::endl;
            return true;
        } else{
            return false;
        }


    }

    public:

    TicTacToe(){
        GameGrid = std::vector<std::vector<char>>(3,std::vector<char>(3,' '));
        GameOver = false;
    
    
        DisplayBoard();
    }

    void DisplayBoard() {
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << GameGrid[0][0] << "  |  " << GameGrid[0][1] << "  |  " << GameGrid[0][2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << GameGrid[1][0] << "  |  " << GameGrid[1][1] << "  |  " << GameGrid[1][2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << GameGrid[2][0] << "  |  " << GameGrid[2][1] << "  |  " << GameGrid[2][2] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
}


    void GamePlay(){
        int count = 0;
        int row,column;
        while(GameOver==false){
        if(count%2==0){ // circle!
            std::cout<<"Where would you like to place the circle: "<<std::endl;
            std::cout<<"    Which Row?: ";
            std::cin>>row;
            std::cout<<"    Which Column?: ";
            std::cin>>column;

            if (row >= 1 && row <= 3 && column >= 1 && column <= 3) {
                row -= 1;
                column -= 1;
                if(GameGrid[row][column]==' '){                                                         
                    GameGrid[row][column]='O';
                    CheckWin();
                    if(GameOver==false){
                        DisplayBoard();
                    }

                    if(CheckDraw()==true){
                        break;
                    }

                    count++;
                } else{
                    std::cout<<"Invalid Entry!"<<std::endl;
                }
            }
        }
        
        else { // cross
            std::cout<<"Where would you like to place the cross: "<<std::endl;
            std::cout<<"    Which Row?: ";
            std::cin>>row;
            std::cout<<"    Which Column?: ";
            std::cin>>column;

            if (row >= 1 && row <= 3 && column >= 1 && column <= 3) {
                row -= 1;
                column -= 1;
                if(GameGrid[row][column]==' '){
                    GameGrid[row][column]='X';
                    CheckWin();
                    if(GameOver==false){
                        DisplayBoard();
                    }

                    if(CheckDraw()==true){
                        std::cout<<"well played:)";
                        break;
                    }

                count++;
                }else{
                    std::cout<<"Invalid Entry!"<<std::endl;
                }
            }
        
        }
        }
    }

};


int main(){
    TicTacToe game;
    game.GamePlay();
}