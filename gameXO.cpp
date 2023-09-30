#include <iostream>
using namespace std;
char m [3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // it’s the matrix of the game
char pl ='x'; //the player who will start the game
void printM ()// function to print the matrix
{ 
    system("cls"); // to clear the screan of concelapp and start again
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m [i][j] << "   ";
        }
        cout << endl;
    }
}
void play (){  // function to take the inpout from user
    char pos; // the position which i will replace it with x or o
    cout <<"choose your position player ( "<<pl<<" ):";
    cin >> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) //loop to replace evrey position with a player 
        {
           if (m [i][j]== pos)
           { m[i][j]= pl;

           }
           
        }
    }
    if (pl=='x') //codition to turn betwen players
        pl='o';
    else
    pl='x';
}
char winner(){
    int Xc=0 , Oc=0; // counter to count the number of x and o
    int c=0; // this counter to stop the game if noone winner 
    for (int i = 0; i < 3; i++)  //loop to check if the raw is full of x or o
       {
        for (int j = 0; j < 3; j++)
        { 
          if (m[i][j] != 'x' && m[i][j] != 'o')
            {
                c++;
            }
           if (m[i][j]== 'x')
           {
            Xc++;
           }
           else if (m[i][j] == 'o')
           {
            Oc++;
           }
           if (Xc == 3 || Oc == 3) // compaire if any matrix full with x or o
           {
            return Xc > Oc? 'x' : 'o'; // compair if xc > oc then will return xc else will return oc
           }

          /*if (m[i][j] != 'x' || m[i][j] != 'o')
            {
                c++;
            }*/ 
        }
          Xc = 0; //to make the counter = 0 if the raw have 2x and O 
           Oc = 0;        
    }
    for (int i = 0; i < 3; i++)  //loop to check if the colom is full of x or o
    {
        for (int j = 0; j < 3; j++)
        {
            
           if (m[j][i]== 'x')
           {
            Xc++;
           }
           else if (m[j][i] == 'o')
           {
            Oc++;
           }
           if (Xc == 3 || Oc == 3) 
           {
            return Xc > Oc? 'x' : 'o'; 
           }  
        }
      Xc = 0;  
      Oc = 0;
    }
 if (m[0][0] == 'x' && m[1][1] == 'x' && m[2][2] == 'x'){  //conditon to chek if the diameter =x or o
    return 'x';
 }
 else if (m[0][0] == 'o' && m[1][1] == 'o' && m[2][2] == 'o'){
    return 'o';
 }
 else if (m[0][2] == 'x' && m[1][1] == 'x' && m[2][0] == 'x'){
    return 'x';
 }
 else if (m[0][2] == 'o' && m[1][1] == 'o' && m[2][0] == 'o'){
    return 'o';
 }

 if (c == 0)
 {
    return 'z'; // this return mean that the game end but noone win
 }
 
 return '.'; // this point mean that the game still work and noone win
}
int main()
{
   while (winner() == '.') // if the game still work , still loop and play
   {
    printM();
    play ();
   }
   printM();
   if (winner() == 'z')
   {
    cout<<"\n no one winner !! \n\n"<<endl;
   }
   else 
   cout<<"\n the winner is player ("<<winner() <<") , congratulation!! \n\n";
   system ("pause");
   return 0;
}