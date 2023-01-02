
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void bubblesort(int arr[25], int n)
{
  int i, j, temp;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertionsort(int arr[25], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (j > 0 && temp <= arr[j])
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}

void fork1()
{
  int arr[25], n, i;
  printf("\n Enter the no. of values in array:");
  scanf("%d", &n);
  printf("\n Enter the array elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int pid = fork();
  if (pid == 0)
  {
    sleep(10);
    printf("\n Child process \n");
    printf("Child processid=%d\n", getpid());
    insertionsort(arr, n);
    printf("\n Elements sorted using insertion:");
    printf("\n");
    for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
    printf("\b");
    printf("\n Parent processid=%d\n", getpid());
  }
  else
  {
    printf("\n Parent process\n");
    printf("\n parent process process=%d\n", getpid());
    bubblesort(arr, n);
    printf("Elements sorted using bubblesort:");
    printf("\n");
    for (i = 0; i < n; i++)
      printf("%d,", arr[i]);
    printf("\n\n\n");
  }
}

int main()
{
  fork1();
  return 0;
}
