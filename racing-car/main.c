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

void showRacing(int times, Car car)
{
        char *distance = malloc(sizeof(char) * times);

        memset(distance, 0, times);
        memset(distance, '-', car.moveTime);
        printf("%d : %s : %d \n", car.number, distance, car.moveTime);

        free(distance);
}

void race(int carsNumber, Car *cars, int times)
{
	int index;
	int randomValue;
	Car *car;

	index = 0;
	while (index < carsNumber)
	{
		car = cars + index;
		randomValue = rand() % 10 + 1;
		go(car, randomValue);
		showRacing(times, *car);
		index++;
	}
}

void startRacing(int times, int carsNumber, Car *cars)
{
	int currentTime;
	Car *car;

	currentTime = 0;
	while (currentTime < times)
	{
		race(carsNumber, cars, times);
		printf("------------------------------------ \n");
		currentTime++;
	}
}

void main()
{
	int carsNumber;
	int times;
	Car *cars;

	srand(time(NULL));
	getInputValue(&carsNumber, &times);
	cars = malloc(sizeof(Car) * carsNumber);
	makeCars(carsNumber, cars);
	startRacing(times, carsNumber, cars);

	free(cars);
}
