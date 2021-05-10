#include <stdio.h>
#include <cs50.h>

const int numberlength = 4;
int number[numberlength] = {10, 5, 2, 1};
bool numberbool[numberlength] = {true, true, true, true};
int light = true; //손전등 있으면 true 없으면 false
int timetotal = 0; //최소 시간 합

void Bubble(); //정렬하기
int Go();
int Back();
void Bridge();
void Show();

int main(void) {  
  
    Bubble();//정렬을 하고..?
    Show();
    Bridge();
    printf("%d\n",timetotal);
    return 0;
}

void Bubble()
{
  int temp;
  for (int i=0; i < numberlength; i++)
  {
    for (int j=0; j < numberlength - i - 1; j++ )
    {
      if (number[j] > number[j+1])
      {
        temp = number[j];
        number[j] = number[j+1];
        number[j+1] = temp;
      }
    }
  }

}

void Bridge()
{
    int count =0;
    for(int i=0;i<numberlength;i++) //모든 numberbool이 false라면 return 멈춤
    {
        if(!numberbool[i])
        {   
            count++;
        }
    }
    if(count==numberlength)
    {
        return;
    }


    if(light==true)
    {
        timetotal = timetotal + Go();
    }
    else if(light == false)
    {
        timetotal = timetotal + Back();
    }
    Show();
    Bridge();
}

int Go() //가는거
{
   printf("Go() : ");
   int count =0;
   int max = 0;

   if(numberbool[0]&&numberbool[1]) //둘다 true면 -> 다리를 안건너 갔다면
   {
        printf("%d %d",number[0],number[1]);//2개먼저감
        max = number[1];
        numberbool[0] = false;
        numberbool[1] = false;//다리건너 지나 갔으니까 false처리
   }
   else if(numberbool[0]||numberbool[1])//둘중 하나만 true이면
   {
       for(int i=2;i<numberlength;i++)//그 다음으로 작은거 보내기
       {
           if(numberbool[i]==true && count < 2)//2개만 보내야함
           {
                printf("%d ", number[i]);
                max = number[i];
                count++;
                numberbool[i] = false;
           }
       }
       if(numberbool[0] && count == 1)//근데 홀수라서 남은게 하나라면
       {
            printf("%d ", number[0]); //제일 작은 수 보내면됨
            numberbool[0] = false;
       }
   }
   printf("\n");
   light = false;

   return max;
}
int Back()
{
    int max = 0;
    printf("Back() : ");
    int count = 0;
    for(int i=0 ;i<2;i++)
    {
        if(!numberbool[i] && count < 1)//건너간것 -> false
        {
            printf("%d\n",number[i]);
            max = number[i];
            numberbool[i]=true;
            count++;
        }
    }
    light = true;
    return max;    
}
void Show()
{
    //printf("Show()\n");
    for(int i =0 ;i < numberlength;i++)
        {
            printf("%d\t",number[i]);
        }
    printf("\n");
    for(int i =0 ;i < numberlength;i++)
        {
            printf("%d\t",(int)numberbool[i]);
        }
    printf("\n");
}
