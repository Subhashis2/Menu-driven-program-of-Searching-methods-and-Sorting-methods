//....Subhashis PAUl

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int Search(int);
int Sort(int);
int Frequency_of_elements();
struct array
{
	int num;   int key;   int *arr;
	int *freq;
};

int do_recursive_binary_search(struct array *elements,int,int);
int do_iteration_binary_search(struct array *elements);
int do_linear_search(struct array *elements);
int do_bubble_sort(struct array *elements);
int do_selection_sort(struct array *elements);
int do_insertion_sort(struct array *elements);
int do_merge_sort(struct array *elements,int,int);
int do_merge(struct array *elements,int,int,int);
int check_frequency(struct array *elements);
int swap(struct array *elements,int,int);

int main()
{
int choice;
while(1)
{
	system("CLS");
printf("\n *********************************************************************************");
printf("\n *                                                                               *");
printf("\n *                                   /---> Using Recursive Method (Type 1)       *");
printf("\n *                 /--> Binary Search                                            *");
printf("\n *                /                  \\---> Using Iteration Method (Type 2)       *");
printf("\n *               /                                                               *");
printf("\n *  Search Method                                                                *");
printf("\n *               \\                                                               *");
printf("\n *                \\---> Linear Search (Type 3)                                   *");
printf("\n *                                                                               *");
printf("\n *                      /---> Bubble Sort (Type 4)                               *");
printf("\n *                     /                                                         *");
printf("\n *                    | ----> Selection Sort (Type 5)                            *");
printf("\n *  Sorting Method ---|                                                          *");
printf("\n *                    |----> Insertion Sort (Type 6)                             *");
printf("\n *                     \\                                                         *");
printf("\n *                      \\---> Merge Sort (Type 7)                                *");
printf("\n *                                                                               *");
printf("\n *  Frequency of all elements of array (Type 8)                                  *");
printf("\n *                                                                               *");
printf("\n *            Type (0) to exit.....                                              *");
printf("\n *                                                                               *");
printf("\n *********************************************************************************");
printf("\n\n Please enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
	case 0:
		exit(0);
		break;
	case 1:
		Search(choice);
		break;
	case 2:
		Search(choice);
		break;
	case 3:
		Search(choice);
		break;
	case 4:
		Sort(choice);
		break;
	case 5:
		Sort(choice);
		break;
	case 6:
		Sort(choice);
		break;
	case 7:
		Sort(choice);
		break;
	case 8:
		Frequency_of_elements();
		break;
	default:
		printf("\n Enter correct choice !!!!");
		sleep(2);
		break;
}
}
return 0;
}

int Search(int pass_val)
{
	struct array elements;
	int i,flag;

	system("CLS");
	if(pass_val == 1)
	printf("\n\t\t\t\t -:  RECURSIVE BINARY SEARCH  :-\n\n\n");
	else if(pass_val == 2)
	printf("\n\t\t\t\t -:  ITERATION BINARY SEARCH  :-\n\n\n");
	else
	printf("\n\t\t\t\t -:  LINEAR BINARY SEARCH  :-\n\n\n");
	printf("Enter number of elements in the array :  ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements : ");
	for(i=0;i<elements.num;i++)
	scanf("%d",elements.arr+i);
	printf("\nEnter the key to search in the array :  ");
	scanf("%d",&elements.key);
	do_insertion_sort(&elements);
	if(pass_val == 1)
	flag = do_recursive_binary_search(&elements, 0 , (elements.num - 1));
	else if(pass_val == 1)
	flag = do_iteration_binary_search(&elements);
	else
	flag = do_linear_search(&elements);
	if(flag)
	printf("\n %d is Found in the array !!",elements.key);
	else
	printf("\n %d is not Found in the array !!",elements.key);
	free(elements.arr);
	printf("\n\n\n Type 'y' to try again or type 'n' to go to main menu : ");
	if(getch() == 'y')
	Search(pass_val);
	else
	main();
return 0;
}

int do_recursive_binary_search(struct array *elements, int lb, int ub)
{
	int mid;
	if(lb == ub)
		if(elements->arr[lb] == elements->key)
			return 1;
		else
			return 0;
	else
	{
		mid = (lb +ub)/2;
		if(elements->arr[mid] == elements->key)
			return 1;
		if(elements->key < elements->arr[mid])
			do_recursive_binary_search(elements, lb, mid-1);
		else
			do_recursive_binary_search(elements, mid+1, ub);
	}
}

int do_iteration_binary_search(struct array *elements)
{
	int lb,ub,mid;
	lb = 0;
	ub = elements->num - 1;
	mid = (lb + ub)/2;
	while(lb<=ub)
	{
		if(elements->key == elements->arr[mid])
		{
			return 1;
			break;
		}
		if(elements->key < elements->arr[mid])
		ub = mid - 1;
		else
		lb = mid + 1;
		mid = (lb + ub)/2;
	}
	if(lb > ub)
	return 0;
	else
	return 1;
}

int do_linear_search(struct array *elements)
{
	int i,found=0;
	for(i=0;i<elements->num;i++)
	{
		if(elements->arr[i] == elements->key)
		{
			return 1;
			found = 1;
			break;
		}
	}
	if(!found)
	return 0;
}

int Sort(int pass_val)
{
	struct array elements; 
	int i,flag;
	system("CLS");
	if(pass_val == 4)
	printf("\n\t\t\t\t -:  BUBBLE SORT METHOD  :-\n\n\n");
	else if(pass_val == 5)
	printf("\n\t\t\t\t -:  SELECTION SORT METHOD  :-\n\n\n");
	else if(pass_val == 6)
	printf("\n\t\t\t\t -:  INSERTION SORT METHOD  :-\n\n\n");
	else
	printf("\n\t\t\t\t -:  MERGE SORT METHOD  :-\n\n\n");
	
	printf("Enter number of elements in the array :  ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements : ");
	for(i=0;i<elements.num;i++)
	scanf("%d",elements.arr+i);
	if(pass_val == 4)
	do_bubble_sort(&elements);
	else if(pass_val == 5)
	do_selection_sort(&elements);
	else if(pass_val == 6)
	do_insertion_sort(&elements);
	else
	do_merge_sort(&elements, 0 , (elements.num - 1));
	printf("\n\n After sorting, the array is :     ");
	HANDLE color= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,14);
	for(i=0;i<elements.num;i++)
	printf("%d\t",*(elements.arr+i));
	SetConsoleTextAttribute(color,10);
	free(elements.arr);
	printf("\n\n\n Type 'y' to try again or type 'n' to go to main menu : ");
	if(getch() == 'y')
	Sort(pass_val);
	else
	main();
return 0;
}

int do_bubble_sort(struct array *elements)
{
	int i,j;
	for(i=0; i<elements->num-1; i++)
		for(j=0; j<elements->num-1-i; j++)
		{
			if(elements->arr[j] > elements->arr[j+1])
			{
				swap(elements,j,j+1);
			}
		}
return 0;
}

int do_selection_sort(struct array *elements)
{
	int i,j,min;
	for(i=0;i<elements->num-1;i++)
	{
	min = i;

for(j=i+1; j<elements->num; j++)
	if(elements->arr[j] < elements->arr[min])
	min = j;
if(min != i)
swap(elements,i,min);
	}
return 0;
}

int do_insertion_sort(struct array *elements)
{
	int i,j,temp;
	for(i=1; i<elements->num; i++)
	{
		temp = elements->arr[i];
		j = i-1;
		while(j>=0 && elements->arr[j] > temp)
		{
			elements->arr[j+1] = elements->arr[j];
			j = j - 1;
		}
	elements->arr[j+1] = temp;
	}
return 0;
}

int do_merge_sort(struct array *elements, int lb, int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb + ub)/2;
		do_merge_sort(elements, lb, mid);
		do_merge_sort(elements, mid+1, ub);
		do_merge(elements, lb, mid, ub);
	}	
}

int do_merge(struct array *elements,int lb,int mid,int ub)
{
	int i = lb;
	int j = mid + 1;
	int k = lb;
	int temp[20];
	while(i <= mid && j <= ub)
	{
		if(elements->arr[i] <= elements->arr[j])
		{
			temp[k] = elements->arr[i];
			i++;
		}
		else
		{
			temp[k] = elements->arr[j];
			j++;
		}
		k++;
	}
	if(i > mid)
		while(j <= ub)
		{
			temp[k] = elements->arr[j];
			j++;
			k++;
		}
	else
		while(i <= mid)
		{
			temp[k] = elements->arr[i];
			i++;
			k++;
		}
	for (i = lb; i <= ub; i++)
    {
        elements->arr[i] = temp[i];
    }
}

int Frequency_of_elements()
{
struct array elements;
	int i,flag;

	system("CLS");
	printf("\n\t\t\t\t -: FREQUENCY OF ELEMENTS IN ARRAY :-\n\n\n");
	printf("Enter number of elements in the array :  ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements : ");
	for(i=0;i<elements.num;i++)
	{
	scanf("%d",elements.arr+i);
	elements.freq[i] = -1;
	}
	check_frequency(&elements);
	system("CLS");
	printf("\n Frequency of all elements in the array is : ");
	printf("\n\n\t\t\t Element ----  Frequency");
	printf("\n\t\t\t________________________");
	for(i=0; i<elements.num; i++)
		if(elements.freq[i] != 0)
			printf("\n\t\t\t     %d   --->    %d",*(elements.arr+i),*(elements.freq+i));
	free(elements.arr);
	free(elements.freq);
	printf("\n\n\n Type 'y' to try again or type 'n' to go to main menu : ");
	if(getch() == 'y')
	Frequency_of_elements();
	else
	main();
return 0;
}

int check_frequency(struct array *elements)
{
	int i,j,freq;
	for(i=0; i<elements->num; i++)
	{
		freq = 1;
		for(j=i+1; j<elements->num; j++)
		{
			if(elements->arr[i] == elements->arr[j])
			{
				freq++;
				elements->freq[j] = 0;
			}
		}
		if(elements->freq[i] != 0)
			elements->freq[i] = freq;
	}
return 0;
}

int swap(struct array *elements,int x,int y)
{
	elements->arr[x] = elements->arr[x] + elements->arr[y];
	elements->arr[y] = elements->arr[x] - elements->arr[y];
	elements->arr[x] = elements->arr[x] - elements->arr[y];
return 0;
}
