#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

void push(Node** head,int num);

void headPrevPtr(Node* head);

void printRight(Node* head, int k);

Node* Pos(Node* head,int pos);

void printleft(Node* head,int k);

void killFirstElem(Node** head);

void killLastElem(Node* head);

int main(int argc,char* argv[])
{
	Node* head = NULL;
	int SIZE;
	printf("Write a size of array:\t");
	scanf("%d",&SIZE);
	if(SIZE <= 0)
	{
		printf("Size should be bigger than 0");
		return -1;
	}
	int arr[SIZE];
	for(int i = 0; i < SIZE;i++)
	{
		printf("Write a %d num of array:\t",i+1);
		scanf("%d",&arr[i]);
		push(&head,arr[i]);
	}
	int k;
	do
	{
		printf("Write k,k > 0, k < %d:\t",SIZE);
		scanf("%d",&k);
	}
	while(k<=0|| k > SIZE);
			
	int temp = SIZE-k+1;
	printf("Array:\n\n");
	print(head);
	printf("Array from k to k - 1 leftside:\n\n");
	printleft(head,temp);
	killFirstElem(&head);
	killLastElem(head);
	printf("Array after killing first and last elements:\n\n");
	print(head);
	printf("Array after killing first and last elements from k to k + 1 rightside:\n\n");
	printRight(head,k);
	return 0;
}

void push(Node** head,int num)
{
	if(*head == NULL)
	{
		Node *tmp = (Node*) malloc(sizeof(Node));
		tmp->data = num;
		tmp->next = NULL;
		tmp->prev = NULL;
		(*head) = tmp;
	}
	else
	{
		Node* tmp = (Node*) malloc(sizeof(Node));
		tmp->data = num;
		tmp->prev = NULL;
		tmp->next = *(head);
		(*head) = tmp;
		tmp->next->prev = *(head);
	}
}

void headPrevPtr(Node* head)
{
	Node* tmp = head;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	head->prev = tmp;
}

void printRight(Node* head, int k)
{
	Node *tmp =head;
	headPrevPtr(head);
	int count = 0;
	int count1 = 0;
	int temp;
	while(tmp)
	{
		tmp = tmp->next;
		count1++;
	}
	temp = count1;
	while(count < k && head->next)
	{
		head = head->next;
		count++;
	}
	count1++;
	while(count1 !=0)
	{
		printf("%d\t",head->data);
		head = head->prev;
		count1 --;
	}
    if(temp!= 1)
	{
		printf("%d\t",head->data);		
	}
}

Node* Pos(Node* head,int pos)
{
	int count = 0;
	while(count < pos && head->next)
	{
		 head = head->next;
		count++;
	}
	return head;
}

void printleft(Node* head,int k)
{
	Node* temp = head;
	int count = 0;
	while(count < k-1 && head->next)
	{
		head = head->next;
		count++;
	}
	while(head)
	{
		printf("%d\t",head->data);
		head = head->next;
		if(head == NULL)
		{
			head = Pos(temp,0);
			for(int i = 0; i < count;i++)
			{
				printf("%d\t", head->data);
				head = head->next;
			}
			break;
		}
	}
	printf("\n");
}
void print(Node* head)
{
	while(head->next)
	{
		head = head->next;
	}
	while(head)
	{
		printf("%d\t",head->data);
		head = head->prev;
	}
	printf("\n");
}
void killFirstElem(Node** head)
{
	if((*head) == NULL)
	{
		printf("List is empty");
		return -1;
	}
	if((*head)->next == NULL)
	{
		free((*head));
		(*head) = NULL;
		printf("List consists of 1 element and is empty after killing");
		exit(0);
	}
	Node* tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
void killLastElem(Node* head)
{
	if(head == NULL)
	{
		exit(-2);
	}
	if(head->next == NULL)
	{
		printf("List consists of 2 elements and is empty after killing");
		exit(2);
	}
	while(head->next->next)
	{
		head = head->next;
	}
	Node* tmp = head;
	tmp->next = NULL;
	free(head->next);
}
