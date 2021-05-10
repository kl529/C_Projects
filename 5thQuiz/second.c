#include <stdio.h>
void sort(int num,int array[]);

int main() 
{ 
    int n = 7; 
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 }; 
    sort(n, arr); 
    return 0; 
}

void sort(int num,int array[]) //버블정렬 포인터 사용
{
  int temp;
  for (int i=0; i < num; i++)
  {
    for (int j=0; j < num - i - 1; j++ )
    {
      if (*(array+j) > *(array+j+1))
      {
        temp = *(array+j);
        *(array+j) = *(array+j+1);
        *(array+j+1) = temp;
      }
    }
  }
  for(int i=0; i<num; i++) {
        printf("%d\t", *(array+i));		//배열의 포인터 접근을 위한 방법, \t 의 경우 tab 과 같은 역할을 함
    }
}

