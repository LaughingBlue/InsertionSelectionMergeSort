// InsertionSelectionMergeSort.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "ISMsort.h"

#define ARR_NUM 3
#define ARR_LENGTH 50000

#define DEBUG 0

using namespace std;

const int THREADS = omp_get_num_procs();

int main()
{
	cout << "亂數數量: " << ARR_LENGTH << endl;
	srand(time(0));
	double tSTART_Insert, tEND_Insert, tSTART_Select, tEND_Select, tSTART_Merge, tEND_Merge;
	int testArr[ARR_NUM][ARR_LENGTH];

#pragma omp parallel for num_threads(THREADS)
	for (int i = 0; i<ARR_NUM; i++)
		for (int j = 0; j<ARR_LENGTH; j++)
			testArr[i][j] = 1 + rand() % ARR_LENGTH;

#pragma omp parallel for num_threads(THREADS)
	for (int i = 0; i < ARR_NUM; i++)
	{
		switch (i)
		{
			case 0:
				tSTART_Insert = clock();
				InsertSort(testArr[i], ARR_LENGTH);
				tEND_Insert = clock();				
				break;
			case 1:
				tSTART_Select = clock();
				SelectSort(testArr[i], ARR_LENGTH);
				tEND_Select = clock();				
				break;
			case 2:
				tSTART_Merge = clock();
				MergeSort(testArr[i], 0, ARR_LENGTH);
				tEND_Merge = clock();				
				break;
		}
	}

#if DEBUG == 1
	for (int i = 0; i<ARR_NUM; i++)
	{
		cout << "Array " << i << ": " << endl;
		for (int j = 0; j<ARR_LENGTH; j++)
			cout << testArr[i][j] << '\t';

		cout << endl << endl;
	}
#endif // DEBUG == 1	

	cout << endl << "InsertSort所花費的時間：" << (tEND_Insert - tSTART_Insert) / CLOCKS_PER_SEC << " S" << endl;//<< " MS" << endl;
	cout << endl << "SelectSort所花費的時間：" << (tEND_Select - tSTART_Select) / CLOCKS_PER_SEC << " S" << endl; //<< " MS" << endl; 
	cout << endl << "MergeSort所花費的時間：" << (tEND_Merge - tSTART_Merge) / CLOCKS_PER_SEC << " S" << endl; //<< " MS" << endl;
	system("pause");

	exit(0);
}

