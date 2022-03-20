#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Car {
	int number;
	int moveTime;
} Car;

void getInputValue(int *carsNumber, int *times)
{
	printf("몇개의 자동차로 경주를 할건가요? : ");
        scanf("%d", carsNumber);
        printf("시도횟수는 몇회 인가요? : ");
        scanf("%d", times);
        printf("------------------------------------ \n");
}

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
	int times;
	int index;
	int randomValue;
	Car *cars;

	getInputValue(&carsNumber, &times);

	cars = malloc(sizeof(Car) * carsNumber);
	makeCars(carsNumber, cars);

	srand(time(NULL));
	char *test = malloc(sizeof(char) * times);
	index = 0;
	while (times > 0)
	{
		memset(test, 0, times);
		Car *car = cars + index;
		randomValue = rand() % 10 + 1;
		go(car, randomValue);
		memset(test, '-', car->moveTime);
		printf("%d : %s : %d \n", car->number, test, car->moveTime);
		index++;
		if (index == carsNumber)
		{
			printf("------------------------------------ \n");
			index = 0;
			times--;
		}
	}
	free(cars);
	free(test);
}
