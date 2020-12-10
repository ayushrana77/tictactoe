#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
//***************************************************Displsy*************************************


// display functon display the matrix 
void display(char a[3][3])
    {
        system("cls");
        int i,j;
        for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                cout<<endl;
            }
       
    }
//*************************************************palyer Turn******************************************


//palyer_turnis function which player turn in the game and fill the poistin in matrix 
void palyer_turn(char a[3][3],char *turn,string player1,string player2)
{
    //using goto if any place already fill it will restart the functon
    start:
    int i,j;
    display(a);
    //Display which player turn
    if(*turn=='X')
        {
            cout<<"\nPlayer of curret trun :"<<player1;
        }
    else if(*turn=='O')
        {
            cout<<"\nPlayer of curret trun :"<<player2;
        }
    //loop to enter row or colume
    do
    {
        //using  goto r to if colume is wrong
        r:
        cout<<"\nChoose the row number (0 to 2)"<<endl;
        cin>>i;
        if(i<0 || i>2)
        {
            cout<<i<<" is not a valid row";
        }
    }while (i<0 || i>2);
     do
    {
        cout<<"\nChoose the colume number (0 to 2)"<<endl;
        cin>>j;
        if(j<0 || j>2)
        {
            cout<<j<<" is not a valid colume";
            //when cloume wrong it go to enter the row
            goto r;
        }
    }while (j<0 || j>2);
    //Enter the row colurm in matrix and check the palce not fill
    if(*turn=='X'&& a[i][j]=='*')
        {
            a[i][j]='X';
            *turn='O';
        }
    else if(*turn=='O' && a[i][j]=='*')
        {
            a[i][j]='O';
            *turn='X';
        }
    else
        {
            //if palce fill show massage anr restart function
            cout<<"\nPlace are already choose\nPress ank key"<<endl;
            getch();
            //if place fill it go to start of the function
            goto start;
        }
    
}
//*************************************Game over***************************************


//gameover function is when some one win the game it return true else it return false
bool gameover(char a[3][3])
{
    int i;
    //loop for check row or colume are same is match it retun true mean some one win the game
    for(i=0;i<3;i++)
        {
            if((a[i][0]=='X' && a[i][1]=='X' && a[i][2]=='X') ||(a[i][0]=='O' && a[i][1]=='O' && a[i][2]=='O'))
                {
                    return true;
                }
            if((a[0][i]=='X' && a[1][i]=='X' && a[2][i]=='X') ||(a[0][i]=='O' && a[1][i]=='O' && a[2][i]=='O'))
                {
                    return true;
                }
        }
    //loop for check diagonal are same is match it retun true mean some one win the game
        if((a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X') ||(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O'))
                {
                    return true;
                }
         if((a[2][0]=='X' && a[1][1]=='X' && a[0][2]=='X') ||(a[2][0]=='O' && a[1][1]=='O' && a[0][2]=='O'))
                {
                    return true;
                }
    // if retun false mean no one win the match this time
    return false;
}
//**********************************************************main***********************************************


int main()
    {
        int i,j,k;
        char turn;//it varibal use to which palyer turn 
        char a[3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
        string first,player1,player2;
        cout<<"\nEnter a name for the X player"<<endl;
        getline(cin,player1);
        cout<<"\nEnter a name for the O player"<<endl;
        getline(cin,player2);
        // loop for which played first
        do
        {
            cout<<"\nwho plays first "<<player1<<"  or  "<<player2<<"?"<<endl;
            getline(cin,first);
            if((first==player1)||(first==player2))
                {
                    if(first==player1)
                        {
                            turn='X';
                        }
                    else
                        {
                            turn='O';
                        }
                    break;
                }
            cout<<first<<" is not a registered player"<<endl;
        } while (true);
    // loop for use every element
    for(k=1;k<=9;k++)
        {
            //palyer_turnis function which player turn in the game and fill the poistin in matrix  
            palyer_turn(a,&turn,player1,player2);
            //gameover function is when some one win the game it return true else it return false
            if(gameover(a)==true)
                {
                    break;
                }
        }
    display(a);
    //if k=10 mean that no one win the game so the game is draw
    if(k==10)
        {
            cout<<"\nMatch draw"<<endl;
        }
    else
        {
            // that last turn=o was palyer2(o) win the game and  turn changes to  x
            if(turn=='X')
                {
                    cout<<endl<<player2<<"  Win the game "<<endl;;
                }
             // that last turn=x was palyer1(x) win the game and  turn changes to  o
            else if(turn=='O')
                {
                    cout<<endl<<player1<<"  Win the game"<<endl;
                }

            
        }
    }
