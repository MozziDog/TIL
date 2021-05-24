#include <iostream>
#include <cstring>

class Closet// 옷장
{
public:
	class Partition
	{
	public:
		char category[20];
		int amount =0;
	};
	
	Partition* partition;
	int NUM_OF_PARTITION;
	
	void init()
	{
		delete partition;
		partition = 0;
		NUM_OF_PARTITION = 0;
	}
	
	//반환 값은 삽입한 파티션 번호
	int insertPartition(const char* str_category)
	{
		Partition* tmp = partition;
		partition = new Partition[++NUM_OF_PARTITION];
		for(int i=0; i<NUM_OF_PARTITION-1; i++)
		{
			strcpy(partition[i].category, tmp[i].category);
			partition[i].amount = tmp[i].amount;
		}
		strcpy(partition[NUM_OF_PARTITION-1].category, str_category);
		partition[NUM_OF_PARTITION-1].amount = 0;
		return NUM_OF_PARTITION-1;
	}
	
	void insertCloth(char* str_category)
	{
		int partitionNumber;
		for(int i=0; i<NUM_OF_PARTITION; i++)
		{
			if(NUM_OF_PARTITION ==0)
			{
				partitionNumber = insertPartition(str_category);
				break;
			}
			if(strcmp(partition[i].category, str_category) == 0)
			{
				partitionNumber = i;
				break;
			}
			if(i==NUM_OF_PARTITION-1)
			{
				partitionNumber = insertPartition(str_category);
				break;
			}
		}
		partition[partitionNumber].amount += 1;
	}
};

int main()
{
	int numOfTestcase, amountOfClothing;
	char category[20];
	Closet closet;
	scanf("%d", &numOfTestcase);
	for(int testcase=0; testcase<numOfTestcase; testcase++)
	{
		closet.init();
		scanf("%d", &amountOfClothing);
		for(int i=0; i<amountOfClothing; i++)
		{
			scanf("%s %s", &category);
			closet.insertCloth(category);
		}
		int answer = 1;
		for(int i=0; i<closet.NUM_OF_PARTITION; i++)
		{
			answer *= (closet.partition[i].amount -1);
		}
		printf("%d", answer-1);
		
	}
	return 0;
}