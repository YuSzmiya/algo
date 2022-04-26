#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100	/*�f�[�^��*/
#define N 100	/*�J�Ԃ���*/

int makeData(int mat[]);
void shuffleData(int mat[]);
int linear_search(int mat[], int key);
int binary_search(int mat[], int key);

int main(void)
{
	int data[SIZE];
	int i;
	int max;
	int no, total;
	int key;

	srand(time(NULL));

	total = 0;
	for (i = 0; i < N; i++){
		max = makeData(data);	/*�f�[�^�z��̐���*/
		
		key = rand() % (int)(SIZE * 1.1);

//		no = linear_search(data, key);
		no = binary_search(data, key);
		
		total += no;
	}
	
	printf("���Ϗ����񐔂�[ %.3f ]�ł��B\n", (double)total / N);

	return (0);
}

/*****************************************************
* Linear search function
* @author	t.tamaki
* @param	mat[] : array for sorting
* @param	key : search key
* @return	number of search
******************************************************/
int linear_search(int mat[], int key)
{
	int i;
	
	for (i = 0; i < SIZE; i++){
		if (mat[i] == key){
			break;
		}
	}
	
	return (i + 1);
}

/*****************************************************
* Binary search function
* @author	t.tamaki
* @param	mat[] : array for sorting
* @param	key : search key
* @return	number of search
******************************************************/
int binary_search(int mat[], int key)
{
	// �����
	int no; // ���������
	int left;
	int right;
	int center;

	// ���
	no = 0;
	left = 0;
	right = SIZE -1;

	// ��
	while(left <= right){
		// ���������
		no++;
		
		// ������center����
		center = (int)((right - left) / 2);

		// ����
		if(mat[center] > key){	
			right = center-1;
		}else if(mat[center] < key){
			left = center+1;
		}else if(mat[center] == key){
			// return(center);
			break;
		}
	}
	return (no);
}
/*****************************************************
* Generate array of random number
* @author	t.tamaki
* @param	mat[] : array for sorting
* @return	maximum value in generated array
******************************************************/
int makeData(int mat[])
{
	int i, n;
	
	n = 1;
	i = 1;
	mat[0] = n;
	while (i < SIZE){
		n++;
		if (rand() / (RAND_MAX + 1.0) < 0.9){
			mat[i] = n;
			i++;
		}
		
	}
	
//	shuffleData(mat);
	
	return (n);
}

/*****************************************************
* Shuffle the number in array
* @author	t.tamaki
* @param	mat[] : array for sorting
* @return	void
******************************************************/
void shuffleData(int mat[])
{
	int n;
	int r;
	int tmp;
	
	n = SIZE-1;
	
	while (n--){
		r = rand() % SIZE;
		tmp = mat[n];
		mat[n] = mat[r];
		mat[r] = tmp;
	}
	
	return ;
}
