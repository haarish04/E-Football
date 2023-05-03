#include <stdio.h>
#include <stdlib.h>
#define max_size 4

char player1[max_size];
char computer[max_size];
static int top_p = -1;
static int top_c = -1;
char name1[20];
char name2[] = "COMPUTER";
char ball = 'p';
int choice;
int choice2;
char goal[] = {'G' , 'O' , 'A' , 'L' , '\0'};
void pass();
void goal_score();
void push_score(char p[] , int *t);
void display_score(char x[] , char n[]);
void pop_score(char p[]  , int *t2);
void game(int choice );
void empty_stack();

void goal_score()
{  

  printf("GOAL TIME! Enter a move: 4/5/6\n" );

  scanf("%d" , &choice2);
  if(choice2> 6 || choice2 <4)
  {
      printf("Oops Missed");
      exit(1);
  }
  int r=rand()%(3)+4;
  printf("COMPUTER'S move: %d \n" , r);

  if(choice2 != (r)){

      if(top_p == max_size -1){

          printf("That is a goal! YOU WIN!! CONGRATULATIONS! :) \n");

          exit(0);}

      else if(top_c == max_size -1){

          printf("OOPS! The computer scored the goal, Better luck next time! :( \n");

          exit(0);}

  }


  else if(choice2==r){
      int ex1;
      if(top_p == max_size -1){
          printf("OOPS your shot has been blocked, Try again\n");
          printf("Do you want to Try again or Exit the game? Enter 1: TRY AGAIN and 2: EXIT GAME \n");
          scanf("%d" , &ex1);
          if(ex1 == 1){
          empty_stack();
          printf("BACK TO PASS ROUND! \n");
          pass();}
          else if(ex1 == 2){
          exit(0);}
      }

      else if(top_c == max_size -1){
          printf("You have blocked the computer's shot!! Play on\n");
          printf("Do you want to Try to win the game or Exit the game? Enter T: TRY AGAIN and E: EXIT GAME \n");
          scanf("%d" , &ex1);
          if(ex1 == 1){
          empty_stack();
          printf("BACK TO PASS ROUND! \n");
          pass();}
          else if(ex1 == 2){
          exit(0);}
        }
  }  
    
}
void empty_stack()
{
    for(int y=0 ; y< max_size ; y++)
    {
        pop_score(player1 , &top_p);
        pop_score(computer , &top_c);
    }
}
    
void push_score(char p[] , int *t )

{
    ++*t;
    p[*t] = goal[*t];

    //printf("%d push  " , *t);
}
void pop_score(char p[] , int *t2)
{
p[*t2] = '\0';
(*t2)--;
//printf("%d pop  " , *t2);
}

void display_score(char x[] , char n[])

{
  printf("%s score: " , n);
  for(int i=0; i<max_size  ; i++)
    printf("%c  " , x[i] );
  printf("                    ");

}

void game_choice(int choice)
{
  int x = rand()%3 + 1;
  printf("COMPUTER'S MOVE: %d \n" , x );
  switch(ball)
  {
    case 'p':{

    if(choice == x)

    {

        if(top_p != -1){

        pop_score(player1 , &top_p);

        ball = 'c';

        display_score(player1 , name1);

        printf("\n");

        display_score(computer , name2);

        printf("\n");

        printf("BALL IS WITH THE COMPUTER \n" );

        

        }
        else
        {
            printf("Your first pass has been blocked, Try again");
        }

        

    }

    else if(choice !=x)

    {

        push_score(player1 , &top_p);

        display_score(player1 , name1);

        printf("\n");

        display_score(computer , name2);

        printf("\n");

        printf("BALL IS WITH %s \n" , name1);

    }

    break;

    

}

case 'c':{

    if(choice == x)

    {

        pop_score(computer , &top_c);

        ball = 'p';

        display_score(player1 , name1);

        printf("\n");

        display_score(computer , name2);

        printf("\n");

        printf("BALL IS WITH %s \n" , name1);

        

    }

    else{

    push_score(computer , &top_c);

    display_score(player1 , name1);

    printf("\n");

    display_score(computer , name2);

    printf("\n");

    printf("BALL IS WITH THE COMPUTER \n" );

    break;

}

}

}}

void main()

{

printf("WELCOME TO E-FOOTBALL\n\n");

printf("Player plays against the computer. The ball is initially with the player.\n In the pass round, the player has to make a move by choosing either 1, 2 or 3.\n If the computer and the player choose the same number,  the ball is passed to the opponent.\n If the computer and the player choose different numbers, the ball is not passed and the person who possessed the ball will get a point. Once the player or computer completes 4 successful passes, player or computer reaches the goal round.\n In the goal round, the player has to make a move by choosing either 4, 5 or 6.\n If the same number is chosen, the goal has been saved and the player can choose to continue or exit the game.\n If different numbers are chosen, the player/computer who won the goal round wins the football match.\n\n\n");

printf("ENTER YOUR NAME: ");

scanf("%s" , name1);

pass();
    
}

void pass()
{
    int ch;


while(top_p < (max_size - 1) && top_c < (max_size - 1))

{printf("\n");

printf("Make your move : (1/2/3)\n");

scanf("%d" , &ch);
if(ch> 3 || ch <1)
{
    printf("Invalid");
    
}
else    
    game_choice(ch);

}


game_choice(ch);

}

goal_score();

}
