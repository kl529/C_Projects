#include <stdio.h>
#include <cs50.h>
#include <string.h>

const int numberlength = 4;
int number[numberlength] = {1, 2, 5, 10};
bool numberbool[numberlength] = {true, true, true, true};
int ProcessArrlength = 5;
char *ProcessArr[10];

int light = true; //손전등 있으면 true 없으면 false

void Bubble();
void Go();
void Back();
void Bridge();
void Show();
void BridgeProcess(char *set);

int main(void) {  
  
    Bubble();//정렬을 하고..?
    Show();
    Bridge();
    //printf(ProcessArr);
    for(int i =0;i<ProcessArrlength;i++)
    {
        printf("%s",ProcessArr[i]);
    }
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
    for(int i=0;i<numberlength;i++) //모든 numberbool이 false라면 return
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
        Go();
    }
    else if(light == false)
    {
        Back();
    }
    Show();
    Bridge();
}

void Go() //가는거
{
   printf("Go() : ");
   int count =0;
   if(numberbool[0]&&numberbool[1]) //둘다 true면 -> 다리를 안건너 갔다면
   {
        //printf("%d %d",number[0],number[1]);//2개먼저감
        char go[20];
        go[0] = (char)number[0];
        BridgeProcess(go);
       
        go[0] = (char)number[1];
        BridgeProcess(go);
        
        
        numberbool[0] = false;
        numberbool[1] = false;//다리건너 지나 갔으니까 false처리
   }
   else if(numberbool[0]||numberbool[1])//둘중 하나만 true이면
   {
       for(int i=2;i<numberlength;i++)//그 다음으로 작은거 보내기
       {
           if(numberbool[i]==true && count < 2)//2개만 보내야함
           {
                //printf("%d ", number[i]);
                count++;
                numberbool[i] = false;
           }
       }
       if(numberbool[0] && count == 1)//근데 홀수라서 남은게 하나라면
       {
            //printf("%d ", number[0]);
            numberbool[0] = false;

            for(int i=2;i<numberlength-2;i++)//그 다음으로 작은거 보내기
            {
              if(numberbool[i]==true)// true인거 하나 찾아서 건너 보냄
              {
                //printf("%d ", number[i]);
                numberbool[i] = false;
              }
           }
       }
   }
   //printf("\n");
   light = false;
}
void Back()
{
    //printf("Back() : ");
    int count = 0;
    for(int i=0 ;i<2;i++)
    {
        if(!numberbool[i] && count < 1)//건너간것 -> false
        {
            //printf("%d\n",number[i]);
            numberbool[i]=true;
            count++;
        }
    }
    light = true;    
}
void Show()
{
    //printf("Show()\n");
    for(int i =0 ;i < numberlength;i++)
        {
            //printf("%d\t",number[i]);
        }
    //printf("\n");
    for(int i =0 ;i < numberlength;i++)
        {
            //printf("%d\t",(int)numberbool[i]);
        }
    //printf("\n");
}
void BridgeProcess(char *set)
{   
    ProcessArrlength++;
    //ProcessArr[ProcessArrlength-1] = *set; //추가
    strcpy(ProcessArr[ProcessArrlength-1],set);
    //for(int i=0 ;i<ProcessArrlegth;i++)
    //{
        
    //    if(i == ProcessArrlegth-1)
    //    {
    //        ProcessArr[i] == set;
    //    }
    //}
}   
