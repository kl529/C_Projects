//2. 누가 빠졌나 찾아보자!
#include <stdio.h>
#define SIZE 500000

int nSum(int a);
int partArrSum(int arr[],int length);

int main(int arge, char*argv[]) {
    int k;
    int n;//1부터 n까지 숫자 모음
    scanf("%d", &n); //파일에서 n 인풋받기

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE]; 
    int lengthOfPartArr = n-1; //배열의 원소 개수

    for(int i=0; i < lengthOfPartArr; i++){ //배열 원소 개수 만큼
        scanf("%d", &partArr[i]);//인풋받음
    }
    k = nSum(n)-partArrSum(partArr,lengthOfPartArr);
    printf("k = %i\n",k);
    // TODO: n과 partArr를 이용하여, K를 구하라
    return 0;
}
//idea => 1부터 n까지의 합에서 원소의 합 빼기
int nSum(int a)
{
    int sum =0;
    for(int i=1 ; i < a+1 ; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int partArrSum(int arr[],int length)
{
    int sum =0;
    for(int i=0;i<length;i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
