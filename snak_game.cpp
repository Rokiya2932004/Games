# include<iostream>
#include<ctime>
#include<conio.h> // library to deal with concol 
#include <windows.h>
using namespace std;
void Shift_Right(int arr[] , int size ){ // function to shift the place or square when the tail become tall
for (int i = size - 2 ; i >= 0; i--)
{
    arr[i + 1] = arr[i];
}
}
enum Direction { Top =1 , Down , Right , Left };
struct map {int width , height , fruitx , fruity;};
struct snake{int headx , heady , tailN, tailX[50], tailY[50]; Direction Dir; };
struct player {int score; bool lose;};
//.......properts of map......//
map map1 ; snake snake1; player player1;
void generateFruit(){
srand(time(NULL));
map1.fruitx = rand() % (map1.width -2 )+1 ;// from 1 to 38
map1.fruity = rand() % (map1.height -2 )+1 ;// from 1 to 18
}
void setup(){
    map1.width = 40;
    map1.height = 20;
    generateFruit();

 //......properts of snake.....//
 snake1.headx = map1.width /2 ;
 snake1.heady = map1.height /2 ;
 snake1.tailN = 0; // the tall of snake
 //......player....
 player1.score =0;
 player1.lose = false;
}
void draw(){
    system ("cls");
 for (int i = 0; i < map1.height ; i++) //for draw the hight 
 {
    for (int j = 0; j < map1.width ; j++) //for draw the width
    {
        if (i == 0 || i== map1.height - 1 )
        {
            cout<<"=";
        }
        else if (j == 0 || j== map1.width - 1)
        {
            cout<<"=";
        }
        else if ( i == snake1.heady && j == snake1.headx) //properts of snake
        {
            cout<<"O";
        }
        else if ( i == map1.fruity && j == map1.fruitx) //properts of fruit
        {
            cout<<"@";
        }
        
        else{
            bool printed = false; // if the condition at line 63 don’t achive will print space
            for (int z = 0; z < snake1.tailN; z++)
            {
              if (snake1.tailX[z] == j && snake1.tailY[z] == i)
              {
                cout<<"o"; //shape of tail
                printed = true;
                break;
              } 
            }
            if (!printed)
            {
                cout<<" ";
            }
        } 
    }
    cout << endl ;
 }
 cout<<" the score : "<< player1.score <<endl;
}
void input(){ //function to take the direction from user
if ( _kbhit()) //the function _kbhit(do return to D.T int) using to chek if i click on my keb or not
{
    char c = _getch(); 
    switch (c) //check the direction
    {
     case 'w': snake1.Dir = Top;  
        break;
     case 's': snake1.Dir = Down;  
        break;
     case 'd': snake1.Dir = Right;  
        break;
     case 'a': snake1.Dir = Left;  
        break;
     case 'x': exit(0); //to end the game
    }
}

}
void move(){ //to control moving of snake’s head
 Shift_Right(snake1.tailX , 50);
 Shift_Right(snake1.tailY , 50);
 snake1.tailX[0] = snake1.headx;
 snake1.tailY[0] = snake1.heady;
 switch (snake1.Dir)
 {
 case Top : snake1.heady--; //because when i go up the distance to the top become less than the first one
 break;
 case Down : snake1.heady++;//because when i go down the distance to the top become greater than the first one
 break;
 case Right :snake1.headx++;
 break;
 case Left :snake1.headx--;
 }
 if (snake1.heady>=map1.height || snake1.heady<= 0 || snake1.headx >= map1.width || snake1.headx <= 0) //condition to stop the game if the snake touch the matrix
 {
    player1.lose = true;
 }
 if (snake1.headx == map1.fruitx && snake1.heady == map1.fruity) //condition to move the fruit in a random way when it touch the snake and incress the score
 {
   generateFruit();
   player1.score +=1;
   snake1.tailN++;
 }
 
}
int main(){
    setup();
 while (!player1.lose)
 {
   draw();
   input();
   move();
   Sleep(50);// to make the loop slower
 }

}