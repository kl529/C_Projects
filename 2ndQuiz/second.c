#include <cs50.h>
#include <stdio.h>

void Goal(int goalmoney);

int main(void)
{
  int GoalMoney = get_int("목표금액? : ");
  Goal(GoalMoney);
}

void Goal(int goalmoney)
{
  printf("1년 만기시 받는 원금과 이자의 합계: %.2f\n", goalmoney*1.012);
}
