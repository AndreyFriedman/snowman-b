#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <ctime>
using namespace std;
using namespace ariel;

int randomSnowman = 0;
int main() {
	cout << ariel::snowman(11111111) << endl;
	cout << ariel::snowman(22222222) << endl;
	cout << ariel::snowman(33333333) << endl;
	cout << ariel::snowman(44444444) << endl;
	srand(time(NULL));
	for (size_t i = 0; i < 8; i++)
	{
		randomSnowman = randomSnowman*10 + rand()%4 + 1;
		cout<<randomSnowman<<endl;	
	}
	
	
	cout << randomSnowman << endl;
	cout << ariel::snowman(randomSnowman) << endl;

}