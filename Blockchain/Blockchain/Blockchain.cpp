// Blockchain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data[5];
	float Address;
};
typedef struct Node* node;

struct BlocksIp {
	node end;
	node head;
	node temnod;
	int i;
}blc;

void addelement(int Data) {
	float sum = 0;
	float addr = 0;
	if (blc.temnod != NULL) {
		if (blc.i < 5) {
			blc.temnod->data[blc.i] = Data;
			blc.i = blc.i + 1;
		}
		else {
			blc.i = 1;
			if (blc.head == NULL) {
				blc.head = blc.temnod;
				blc.end = blc.temnod;
				blc.temnod = (node)malloc(sizeof(struct Node));
				blc.temnod->data[0] = Data;
				blc.temnod->Address = 0;
			}
			else {
				for (int i = 0; i < 5; i++) {
					sum = sum + blc.end->data[i];
				}
				addr = (float)(int)blc.temnod;
				blc.end->Address = (addr + sum) / 8573;//This is the encryption where address of the node is dependent on the data in the node
				blc.end = blc.temnod;
				blc.temnod = (node)malloc(sizeof(struct Node));
				blc.temnod->data[0] = Data;
				blc.temnod->Address = 0;
			}
		}
	}
	else {
		blc.temnod = (node)malloc(sizeof(struct Node));
		blc.temnod->data[0] = Data;
		blc.temnod->Address = 0;
	}
}

void printBloc(node head) {
	node temp = head;
	float addr = 0;
	float sum = 0;
	while (temp->Address != 0) {
		for (int i = 0; i < 5; i++) {
			printf("%d ", temp->data[i]);
			sum = sum + temp->data[i];
		}
		printf("\n");
		addr = (temp->Address * 8573) - sum;//This is Decryption
		temp = (node)(int)addr;
		sum = 0;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", temp->data[i]);
	}
}

int main(void) {
	char c;
	int i = 30;
	int j = 0;
	blc.i = 1;
	while (i > 0) {
		scanf_s("%d", &j);
		addelement(j);
		i = i - 1;
	}
	printBloc(blc.head);
	scanf_s(" %c", &c);
	while (c != 'S') {
		scanf_s(" %c", &c);
	}
	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
