#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Car {
	int number;
	int moveTime;
} Car;

typedef union _Element {
	int size;
	Car car;
} Element;

void getInputValue(int *carsNumber, int *times)
{
	printf("몇개의 자동차로 경주를 할건가요? : ");
        scanf("%d", carsNumber);
        printf("시도횟수는 몇회 인가요? : ");
        scanf("%d", times);
        printf("------------------------------------ \n");
}

void makeCars(Element *cars)
{
	int number;
	number = 1;
	while (number <= cars[0].size)
	{
		Car car;
		car.number = number;
		car.moveTime = 0;
		cars[number].car = car;
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

void race(Element *cars, int times)
{
	int number;
	int randomValue;
	Car *car;

	number = 1;
	while (number <= cars->size)
	{
		car = &cars[number].car;
		randomValue = rand() % 10 + 1;
		go(car, randomValue);
		showRacing(times, *car);
		number++;
	}
}

void startRacing(int times, Element *cars)
{
	int currentTime;

	currentTime = 0;
	while (currentTime < times)
	{
		race(cars, times);
		printf("------------------------------------ \n");
		currentTime++;
	}
}

void getWinner(Element *cars, Element *winner)
{
	int number;
	int topMoveTime;
	Car car;
	
	topMoveTime = -1;
	number = 1;
	while (number <= cars[0].size)
	{
		car = cars[number].car;
		if (topMoveTime < car.moveTime || number == 1)
		{
			topMoveTime = car.moveTime;
			winner[0].size = 1;
			winner[1].car = car;
		}
		else if (topMoveTime == car.moveTime)
		{
			winner[0].size++;
			winner[winner[0].size].car = car;
		}
		number++;
		
	}
}

void showWinner(Element *cars)
{
	Element *winner;
	int number;
	
	winner = malloc(sizeof(Element) * cars[0].size + 1);
	getWinner(cars, winner);
	printf("우승자는 ");
	number = 1;
	while (number <= winner[0].size) 
	{
		printf("%d번 ", winner[number].car.number);
		number++;
	}
        printf("자동차 입니다!!! \n");

	free(winner);
}

void main()
{
	int carsNumber;
	int times;
	Element *cars;

	srand(time(NULL));
	getInputValue(&carsNumber, &times);
	cars = malloc(sizeof(Element) * (carsNumber + 1));
	cars->size = carsNumber;
	makeCars(cars);
	startRacing(times, cars);
	showWinner(cars);

	free(cars);
}
