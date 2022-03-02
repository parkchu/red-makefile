#include <stdio.h>
#include <string.h>

struct Car
{
	char name[12];
};

void	main()
{
	printf("자동차 이름을 입력해주세요 \n");
	struct Car car;
	gets(car.name);
	printf(car.name);
}
