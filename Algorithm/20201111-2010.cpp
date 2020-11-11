#include <iostream>

int main()
{
	int NUM_OF_MULTITAB;
	int MAX_COMPUTER_CONNECTALBE = 1;
	int HOLES_OF_MULTITAB;
	scanf("%d", &NUM_OF_MULTITAB);
	for(int i=0; i<NUM_OF_MULTITAB; i++)
	{
		scanf("%d", &HOLES_OF_MULTITAB);
		MAX_COMPUTER_CONNECTALBE += (HOLES_OF_MULTITAB - 1);
	}
	printf("%d", MAX_COMPUTER_CONNECTALBE);
	return 0;
}