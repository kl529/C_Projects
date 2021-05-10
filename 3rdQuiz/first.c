//1. 학점을 계산해보자!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include<stdlib.h>//형변환

void Score();
bool Availability(int num);
void ShowTable();

string ScoreTable[3][10] = {{"index:","0","1","2","3","4","5","6","7","8" },
                            {"학점:", "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"},
                            {"성적:","95", "90", "85", "80", "75", "70", "65", "60", "0"}};

int main()
{
    ShowTable(); //테이블 보여주기
    Score();

}
void ShowTable()
{
    printf("학점프로그램\n종료를 원하면 999를 입력\n[학점 테이블]\n");
    for(int i = 0; i<3 ; i++)
    {
        for(int j =0 ;j < 10;j++)
        {
            printf("%s\t",ScoreTable[i][j]);
        }
        printf("\n");
    }
}
void Score()
{  
    int input;
    do{
        input = get_int("성적을 입력하세요 (0 ~ 100): ");
        if(!Availability(input)) //유효성 검사
        {
            if(input==999) //999일 경우 탈출해서 종료
            {
                printf("학점프로그램을 종료합니다\n");
                break;
            }
            printf("%d는 올바른 값이 아닙니다 0부터 100까지의 값을 입력하세요 (999는 종료)\n",input);
        }
        else //유효성 통과시 점수 출력
        {
            for (int j = 1; j < 10; j++) 
            {
                if(input >= atoi(ScoreTable[2][j]))
                {   
                    printf("%s\n",ScoreTable[1][j]);
                    break;
                }
            }
        }
    }while(input!=999);
     
}
bool Availability(int num)
{
    if(num>=0&&num<=100) return true;
    else return false;
}
