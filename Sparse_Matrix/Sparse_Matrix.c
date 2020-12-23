#include <stdio.h>

int main()
{
	int Matrix[5][5] =
	{
		{0,1,3,0,0},
		{1,9,0,0,8},
		{0,0,0,0,0},
		{3,7,0,5,0},
		{0,0,0,1,0}
	};

	size_t size_row = sizeof(Matrix) / sizeof(Matrix[0]);
	size_t size_col = sizeof(Matrix[0]) / sizeof(Matrix[0][0]);

	size_t size_values = 0;
	for(size_t i=0; i<size_row;i++)
	{
		for(size_t j=0; j<size_col;j++)
		{
			if(Matrix[i][j] != 0)
				size_values++;
		}
	}

	int k = 0;
	int CompressedMatrix[3][size_values];
	for(size_t i=0; i < size_row; i++)
	{
		for(size_t j=0; j < size_col; j++)
		{
			if(Matrix[i][j] != 0)
			{
				CompressedMatrix[0][k] = i;
				CompressedMatrix[1][k] = j;
				CompressedMatrix[2][k] = Matrix[i][j];
				k++;
			}
		}
	}

	for(size_t i=0; i<3;i++)
	{
		for(size_t j=0; j< size_values; j++)
		{
			if (i == 0 && j == 0)
				printf("i\t");
			else if (i == 1 && j == 0)
				printf("j\t");
			else if (i == 2 && j == 0)
				printf("Values\t");
			printf("|%d| ",CompressedMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
