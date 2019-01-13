#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
void message() {
    cout<<"Use W A S D keys to move the object"<<endl;
}
int main()
{
    string line;
    fstream maze;
    char line1[100][100];
    maze.open("maze.txt");
    int i=0;
    if(maze.is_open())
    {
        while(getline(maze,line))
        {
            int j=0,len;
            while(line[j]!='\0')
            {
                j++;
                len++;
            }
            for(j=0;j<len;j++)
            {
                line1[i][j]=line[j];
            }
            i++;
        }
        maze.close();
    }
    else
        cout<<"Unable to open file";
    int k,loc1,loc2;
    // For clearing the terminal
    cout<<"\033[2J\033[1;1H";
    message();
    for(k=0;k<i;k++)
    {
        int l=0,len;
        while(line1[k][l]!='\0')
        {
                l++;
                len++;
        }
        for(l=0;l<len;l++)
        {
           if(line1[k][l]=='m')
            {
                loc1=k;
                loc2=l;
            }
        }

        cout<<line1[k]<<endl;
    }
    char turn;
    cin>>turn;
    //For clearing terminal
    cout<<"\033[2J\033[1;1H";
    message();
    while(loc1!=i-1)
    {
        if(turn=='w')
        {
            if(line1[loc1-1][loc2]==32)
            {
                line1[loc1][loc2]=32;
                line1[loc1-1][loc2]='m';
                loc1-=1;
            }
        }
        else if(turn=='s')
        {
            if(line1[loc1+1][loc2]==32)
            {
                line1[loc1][loc2]=32;
                line1[loc1+1][loc2]='m';
                loc1+=1;
            }
        }
        else if(turn=='a')
        {
            if(line1[loc1][loc2-1]==32)
            {
                line1[loc1][loc2]=32;
                line1[loc1][loc2-1]='m';
                loc2-=1;
            }
        }
        else if(turn=='d')
        {
            if(line1[loc1][loc2+1]==32)
            {
                line1[loc1][loc2]=32;
                line1[loc1][loc2+1]='m';
                loc2+=1;
            }
        }
        for(k=0;k<i;k++)
        {
            cout<<line1[k]<<endl;
        }
        cin>>turn;
        // For clearing terminal
        cout<<"\033[2J\033[1;1H";
        message();
    }
    cout<<"Game Completed";
    return 0;
}
