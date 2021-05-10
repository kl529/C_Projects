#include <cs50.h>
#include <stdio.h>
#include <string.h>

void TodayMenu(void);

int main(void)
{
    TodayMenu();
}

void TodayMenu(void)
{
    string day = get_string("요일을 입력하세요 : "); 

    if(!strcmp(day,"월요일")){printf("월요일 : 청국장\n");} //strcmp 문자열 비교
    else if(!strcmp(day,"화요일")){printf("화요일 : 비빔밥\n");}
    else if(!strcmp(day,"수요일")){printf("수요일 : 된장찌개\n");}
    else if(!strcmp(day,"목요일")){printf("목요일 : 칼국수\n");}
    else if(!strcmp(day,"금요일")){printf("금요일 : 냉면\n");}
    else if(!strcmp(day,"토요일")){printf("토요일 : 소불고기\n");}
    else {printf("일요일 : 오삼불고기\n");}//일요일
}

