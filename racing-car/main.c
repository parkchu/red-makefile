#include <stdio.h>
#include <stdlib.h>

typedef struct _Car {
	int number;
} Car;

void makeCars(int carsNumber, Car *cars)
{
	int number;
	number = 1;
	while (number <= carsNumber)
	{
		Car car;
		car.number = number;
		cars[number - 1] = car;
		number++;
	}
}

void main()
{
	int carsNumber;
	int time;
	Car *cars;

	printf("몇개의 자동차로 경주를 할건가요? : ");
	scanf("%d", &carsNumber);
	cars = malloc(sizeof(Car) * carsNumber);
	makeCars(carsNumber, cars);
	time = 0;
	while (time < carsNumber)
	{
		printf("%d \n", cars[time].number);
		time++;
	}
	free(cars);
}
