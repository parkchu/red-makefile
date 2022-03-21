#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct _Car {
	char name[15];
	int number;
	int moveTime;
} Car;

typedef union _Element {
	int size;
	Car car;
} Element;

void getInputValue(char *names, int *times)
{
	printf("자동차들의 이름을 입력해주세요 (','로 구분됩니다.) : ");
        scanf("%s", names);
        printf("시도횟수는 몇회 인가요? : ");
        scanf("%d", times);
        printf("------------------------------------ \n");
}

void makeCars(Element *cars, char *names)
{
	char *name;
	int size;
	
	name = strtok(names, ",");
	while (name != NULL)
	{
		Car car;
		
		size = ++cars[0].size;
		realloc(cars, sizeof(Element) * (size + 1));
		strcpy(car.name, name);
		car.number = size;
		car.moveTime = 0;
		cars[size].car = car;
		name = strtok(NULL, ",");
	}
}

void showStartingSignal()
{
        printf("잠시후 레이싱이 시작됩니다. \n");
        sleep(1);
        printf("3.....\n");
        sleep(1);
        printf("2...\n");
        sleep(1);
        printf("1..\n");
        sleep(1);
        printf("출발!!!!\n\n");
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
        printf("%d번차 : %s : %s : %d \n", car.number, distance, car.name, car.moveTime);

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

	showStartingSignal();
	currentTime = 0;
	while (currentTime < times)
	{
		race(cars, times);
		printf("------------------------------------ \n");
		currentTime++;
		sleep(1);
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
		printf("%s님 ", winner[number].car.name);
		number++;
	}
        printf("자동차 입니다!!! \n");

	free(winner);
}

void main()
{
	char names[200];
	int times;
	Element *cars;

	srand(time(NULL));
	getInputValue(names, &times);
	cars = malloc(sizeof(Element));
	cars->size = 0;
	makeCars(cars, names);
	startRacing(times, cars);
	showWinner(cars);

	free(cars);
}
