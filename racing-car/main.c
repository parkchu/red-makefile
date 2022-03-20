#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Car {
	int number;
	int moveTime;
} Car;

void makeCars(int carsNumber, Car *cars)
{
	int number;
	number = 1;
	while (number <= carsNumber)
	{
		Car car;
		car.number = number;
		car.moveTime = 0;
		cars[number - 1] = car;
		number++;
	}
}

void go(Car *car, int randomValue)
{
	if (randomValue >= 4)
	{
		car->moveTime++;
	}
}

void main()
{
	int carsNumber;
	int i;
	int randomValue;
	Car *cars;

	printf("몇개의 자동차로 경주를 할건가요? : ");
	scanf("%d", &carsNumber);
	cars = malloc(sizeof(Car) * carsNumber);
	makeCars(carsNumber, cars);
	srand(time(NULL));
	i = 0;
	while (i < carsNumber)
	{
		Car car = cars[i];
		randomValue = rand() % 10 + 1;
		go(&car, randomValue);
		printf("%d : %d \n", car.number, car.moveTime);
		i++;
	}
	printf("------------------------------------ \n");
	free(cars);
}
