#include <cs50.h>
#include <stdio.h>

void PrintResult(int Request, int Original);

int main(void)
{
    int original = get_int("기존 재고량? : ");
    int request = get_int("주문량이 몇건인가요? : ");
    PrintResult(original, request);
}

void PrintResult(int Request, int Original)
{    
    printf("주문건수 : %i\n", Request);
    printf("기존 재고량 : %i\n", Original);
    printf("남은 재고량 : %i\n", Request-Original);//현재 재고량
    printf("매출액(부가세포함) : %.2f\n", Request*10000*1.1);
}
