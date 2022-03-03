#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct s_car
{
	char	name[12];
	int	position;
}		t_car;

t_car	make_car(void)
{
	char	names[50];
	t_car	car;
	t_car	cars[5];

	printf("enter your car name (separated by ,)\n");
	gets(names);
	names = strtok(names, ",");
	while (names != NULL)
	{
		printf("%s", names);
		strtok(NULL, ",");
	}
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
