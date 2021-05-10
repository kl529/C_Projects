// 3. 큐를 만들어보자!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

#define QueMax 10

void Selection();
void insert();
void delete();
void display();

int front= 0;
int rear = -1;
int Que[QueMax]; 

int main(void)
{  
    Selection();   
}

void Selection(void)//스위치문사용
{
    int selectnum = get_int("1.삽입\n2.삭제\n3.조회\n4.종료\n입력 : ");
    switch(selectnum)
    {
        case 1: //add //case 4 제외하고 재귀함수?
            insert();
            Selection();
            break;

        case 2: //pop
            delete();
            Selection();
            break;
        
        case 3: //display
            display();
            Selection();
            break;
        
        case 4: //quit
            printf("끝\n");
            break;    
    }
}

void insert() //add
{
    if(rear + 1 < QueMax)//큐배열 크기가 10보다 작으면 -> 큐 인덱스(rear)
    {
        int new = get_int("삽입할 값 : ");//삽입할 값 받기
        rear = rear + 1;
        Que[rear] = new;//큐[rear +1]
    }
    else
    {
        printf("Queue가 꽉 찼습니다.\n");
    }
    printf("front : %d / rear : %d\n",front,rear);
}
void delete() //pop -> front를 제거해야함
{
    if(rear+1 > 0)//큐가 있을 때 = 배열 크기가 1이상일때 = 0보다 클때
    {
        printf("큐에서 삭제됨 : %d\n",Que[0]);
        for(int i=0 ; i < rear ;i++)
        {
            Que[i]=Que[i+1];
        }
        rear = rear - 1;
    }
    else //큐가 비었을 때 -> rear이 0 일때
    {
        printf("큐가 비었습니다 \n");
    }
    printf("front : %d / rear : %d\n",front,rear);

}
void display() //현재 큐 상황 보여줌
{
    for(int i = 0; i < rear + 1 ;i++)
    {
        printf("%d ", Que[i]);
    }
    printf("\n");
    printf("front : %d / rear : %d\n",front,rear);

}
