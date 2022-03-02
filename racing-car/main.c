#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_car
{
	char	name[12];
	int	position;
}		t_car;

t_car	make_car(void)
{
	t_car	car;

	printf("enter your car name \n");
	gets(car.name);
	car.position = 0;
	return (car);
}

void	go(t_car	car, int number)
{
	printf("%s: ", car.name);
	if (number >= 4)
	{
		car.position ++;
		printf("%c", '-');
	}
}

void	main(void)
{
	int	random_number;
	t_car	car;

	car = make_car();
	srand(time(NULL));
	random_number = rand() % 10 + 1;
	go(car, random_number);
	printf("\n");
}
