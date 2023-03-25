#include<stdio.h>
#include<string.h>
#include<time.h>
struct position
{
    char c[7][6];
}p;
int lolexit=1;
void clrscr();
void delay(int);
char confirm();
void loading();
void mainscreen();
void menu();
void choice(char);
void start();
void game();
void matrix();
void value(int,int);
int win(int,int);
int vertical(int);
int horizontal(int);
int diagonal(int);
int fortytwo();
void rules();
void credits();
void endconfirm();
void endscreen();
void main()
{
    loading();
    menu();
}
void clrscr()
{
    system("@cls||clear");
}
void delay(int n)
{
    int m=1000*n;
    clock_t s= clock();
    while(clock()<s+m);
}
char confirm()
{
    clrscr();
    char ch;
    printf("\n\n\n\n\n\n\n\n\t\t\t\tAre you sure???");
    printf("\n\n\t\t\t      Enter Y to confirm:");
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
        return 'y';
    else
        return 'n';
}
void loading()
{
    clrscr();
    mainscreen();
    printf("\n\n\n\n\n\n\t\t\t       Loading.");
    delay(1);
    clrscr();
    mainscreen();
    printf("\n\n\n\n\n\n\t\t\t       Loading..");
    delay(1);
    clrscr();
    mainscreen();
    printf("\n\n\n\n\n\t\t\t       Loading...");
    delay(1);
    printf("\n\t\t\t       ");
    for(int i=0;i<10;i++)
    {
        printf("#");
        delay(1);
    }
}
void mainscreen()
{
    printf("\n\n\n\n");
    printf("\n\t\t\t#####  #### $$$$  $$$$$");
    printf("\n\t\t\t#       # # $  #### $");
    printf("\n\t\t\t#   $$$ # # $     # $");
    printf("\n\t\t\t#   $ $     $$$   # $");
    printf("\n\t\t\t#   $$$ # # $     # $");
    printf("\n\t\t\t#       # # $  #### $");
    printf("\n\t\t\t#####  #### $$$$    $");
    printf("\n\n\t\t\t        F 4 U R");
    printf("\n\n\t\t\t     by:SHUBH GARG");
}
void menu()
{
    clrscr();
    fflush(stdin);
    char ch;
    printf("\n\n\t\t\t\t  CONNECT4");
    printf("\n\n\n\t\t\t\t!!! MENU !!!");
    printf("\n\n\n\n\n\t\t\t       Start(press S)");
    printf("\n\n\t\t\t       Rules(press R)");
    printf("\n\n\t\t\t      Credits(press C)");
    printf("\n\n\t\t\t     Exit Game(press E)");
    printf("\n\n\n\n\n\t\t\t       Enter Choice: ");
    rich:
    fflush(stdin);
    scanf("%c",&ch);
    choice(ch);
    if(lolexit==1)
        goto rich;
}
void choice(char ch)
{
    if(ch=='s'||ch=='S')
    {
        start();
    }
    else if(ch=='r'||ch=='R')
    {
        rules();
    }
    else if(ch=='c'||ch=='C')
    {
        credits();
    }
    else if(ch=='e'||ch=='E')
    {
        endconfirm();
    }
    else
    {
        printf("\t\t\tEnter a valid choice: ");
    }
}
void start()
{
    clrscr();
    fflush(stdin);
    printf("\n\n\n\n\n\n\t\t\t\tStarting in");
    for(int i=3;i>0;i--)
    {
        delay(1);
        printf(" %d",i);
    }
    delay(1);
    printf("...");
    delay(1);
    game();
}
void game()
{
    clrscr();
    fflush(stdin);
    int flag=0,z;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<6;j++)
        {
            p.c[i][j]=' ';
        }
    }
    clrscr();
    matrix();
    int player=2;
    while(flag==0)
    {
        if(player==1)
            player=2;
        else if(player==2)
            player=1;
        printf("\n\n\n\n\n\n\t\t\tPlayer %d",player);
        printf("\n\t\t\tEnter choice(0 to quit): ");
        scanf("%d",&z);
        switch(z)
        {
        case 0:
            menu();
            break;
        case 1 ... 7:
            value(z-1,player);
            flag=win(z-1,player);
            if(flag==1)
                break;
            flag=fortytwo();
            if(flag==2)
                break;
            break;
        default:
            printf("Choose valid input");
            flag=0;
        }
    }
    if(flag==2)
    {
        clrscr();
        matrix();
        printf("\n\n\n\n\n\n\t\t\t\tDraw by stalemate!!!");
    }
    printf("\n\n\t\t\tReturn back to menu by pressing any key...");
    getch();
    menu();
}
void matrix()
{
    printf("\n\n\t\t1\t2\t3\t4\t5\t6\t7");
    printf("\n\n\tA   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][5],p.c[1][5],p.c[2][5],p.c[3][5],p.c[4][5],p.c[5][5],p.c[6][5]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");
    printf("\n\tB   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][4],p.c[1][4],p.c[2][4],p.c[3][4],p.c[4][4],p.c[5][4],p.c[6][4]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");
    printf("\n\tC   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][3],p.c[1][3],p.c[2][3],p.c[3][3],p.c[4][3],p.c[5][3],p.c[6][3]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");
    printf("\n\tD   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][2],p.c[1][2],p.c[2][2],p.c[3][2],p.c[4][2],p.c[5][2],p.c[6][2]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");
    printf("\n\tE   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][1],p.c[1][1],p.c[2][1],p.c[3][1],p.c[4][1],p.c[5][1],p.c[6][1]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");
    printf("\n\tF   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |\t%c   |",p.c[0][0],p.c[1][0],p.c[2][0],p.c[3][0],p.c[4][0],p.c[5][0],p.c[6][0]);
    printf("\n\t    |-------|-------|-------|-------|-------|-------|-------|");

}
void value(int n,int a)
{
    for(int i=0;i<6;i++)
    {
        if(p.c[n][i]==' ')
        {
            if(a==1)
            {
                p.c[n][i]='X';
            }
            else if(a==2)
            {
                p.c[n][i]='O';
            }
            break;
        }
    }
    clrscr();
    matrix();

}
int win(int n,int flag)
{
    int v,h,d;
    v=vertical(n);
    h=horizontal(n);
    d=diagonal(n);
    if(v==1 || h==1 || d==1)
    {
        clrscr();
        matrix();
        printf("\n\n\n\n\n\n\t\t\t\tPlayer %d wins!!!",flag);
        return 1;
    }
    return 0;
}
int vertical(int n)
{
    int i;
    for(i=0;p.c[n][i]!=' ';i++);
    i--;
    if(i>2)
    {
        if(p.c[n][i]==p.c[n][i-1] && p.c[n][i]==p.c[n][i-2] && p.c[n][i]==p.c[n][i-3])
        {
            return 1;
        }
    }
    return 0;
}
int horizontal(int n)
{
    int i;
    for(i=0;p.c[n][i]!=' ';i++);
    i--;
    if( (p.c[n][i]==p.c[n+1][i] && p.c[n][i]==p.c[n+2][i] && p.c[n][i]==p.c[n+3][i]) || (p.c[n][i]==p.c[n+1][i] && p.c[n][i]==p.c[n+2][i] && p.c[n][i]==p.c[n-1][i]) || (p.c[n][i]==p.c[n+1][i] && p.c[n][i]==p.c[n-1][i] && p.c[n][i]==p.c[n-2][i]) || (p.c[n][i]==p.c[n-1][i] && p.c[n][i]==p.c[n-2][i] && p.c[n][i]==p.c[n-3][i]) )
    {
        return 1;
    }
    return 0;
}
int diagonal(int n)
{
    int i;
    for(i=0;p.c[n][i]!=' ';i++);
    i--;
    //  '/'
    if( (p.c[n][i]==p.c[n+1][i+1] && p.c[n][i]==p.c[n+2][i+2] && p.c[n][i]==p.c[n+3][i+3]) || (p.c[n][i]==p.c[n+1][i+1] && p.c[n][i]==p.c[n+2][i+2] && p.c[n][i]==p.c[n-1][i-1]) || (p.c[n][i]==p.c[n+1][i+1] && p.c[n][i]==p.c[n-2][i-2] && p.c[n][i]==p.c[n-1][i-1]) || (p.c[n][i]==p.c[n-1][i-1] && p.c[n][i]==p.c[n-2][i-2] && p.c[n][i]==p.c[n-3][i-3]) )
    {
        return 1;
    }
    // '\'
    else if((p.c[n][i]==p.c[n-1][i+1] && p.c[n][i]==p.c[n-2][i+2] && p.c[n][i]==p.c[n-3][i+3]) || (p.c[n][i]==p.c[n-1][i+1] && p.c[n][i]==p.c[n-2][i+2] && p.c[n][i]==p.c[n+1][i-1]) || (p.c[n][i]==p.c[n-1][i+1] && p.c[n][i]==p.c[n+1][i+-1] && p.c[n][i]==p.c[n+2][i-2]) || (p.c[n][i]==p.c[n+1][i-1] && p.c[n][i]==p.c[n+2][i-2] && p.c[n][i]==p.c[n+3][i-3]) )
    {
        return 1;
    }
    return 0;
}
int fortytwo()
{

    for(int i=0;i<7;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(p.c[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 2;
}
void rules()
{
    clrscr();
    printf("\n\n\t\t\t\t   ***RULES***");
    printf("\n\n\n\t\tThe rules are simple. In fact, it is in the name.");
    printf("\n\t    To win Connect Four, connect four of your tokens in a row");
    printf("\n\t    (this can be done horizontally, vertically or diagonally)");
    printf("\n\n\t\t   A 42 slot(6x7) matrix will be on the screen");
    printf("\n\n\t      Each player will choose a column to drop the token in.");
    printf("\n\t       This will give you a chance to either build your row");
    printf("\n\t         or stop your opponent from getting four in a row");
    printf("\n\n\t       The game is over if any player reaches four in a row");
    printf("\n\t     or all forty two slots are filled, ending in a stalemate");
    printf("\n\n\n\t\t\t    Press any key to go back...");
    getch();
    menu();
}
void credits()
{
    clrscr();
    printf("\n\n\t\t\t\t***CREDITS***\n\n");
    printf("Game created by SHUBH GARG");
    printf("\nInstagram: @shubhgarg1404");
    printf("\nFacebook: shubhg019");
    printf("\nTwitter: @theshubhgarg");
    printf("\n\nReferred:");
    printf("\nGeeksforgeeks for Delaying");
    printf("\nGoogle for Clearing Screen Function");
    printf("\n\n\n\t\t\t    Press any key to go back...");
    getch();
    menu();
}
void endconfirm()
{
    clrscr();
    fflush(stdin);
    char ch;
    ch=confirm();
    clrscr();
    if(ch=='n')
        menu();
    else
    {
        endscreen();
    }
}
void endscreen()
{
    clrscr();
    fflush(stdin);
    delay(1);
    char ch[12];
    strcpy(ch,"CONNECT F4UR");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
    for(int i=0;i<12;i++)
    {
        printf("%c",ch[i]);
        delay(1);
    }
    delay(3);
    for(int i=0;i<12;i++)
    {
        printf("\b \b");
        delay(1);
    }
    for(int j=0;j<3;j++)
    {
        clrscr();
        delay(1);
        printf("\n\n\n\n\n\n\n\n\n\t\t\t    Thank you for playing!!!");
        delay(1);
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    lolexit=0;
    getch();
}
