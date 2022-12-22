#include <iostream>
 using namespace std;
struct stack
{
     int front;
     int rear;
     int elements[50];
     int size;
};
void enqueue(stack &q, int value)
{
     if ((q.rear + 1) % q.size == q.front)
     {
          cout << "queue is full";
     }
     else
     {
          if (q.rear == -1)
          {
               q.front = 0;
               q.rear = 0;
          }
          else
          {
               q.rear = (q.rear + 1) % q.size;
          }
          q.elements[q.rear] = value;
     }
}
int dequeue(stack &q)
{
     int temp;
     if (q.front == -1)
     {
          cout << "queue is empty\n";
     }
     else
     {
          temp = q.elements[q.front];
          if (q.front == q.rear)
          {
               q.front = -1;
               q.rear = -1;
          }
          else
          {
               q.front = (q.front + 1) % q.size;
          }
     }
     return temp;
}
void island(int arr[][10], int i, int j, stack q)
{
     if (i < 0 || j < 0 || j > 9 || i > 9 || arr[i][j] != 1)
     {
          return;
     }
     arr[i][j] = 0;
     island(arr, i + 1, j, q);
     island(arr, i - 1, j, q);
     island(arr, i, j + 1, q);
     island(arr, i, j - 1, q);
     island(arr, i + 1, j + 1, q);
     island(arr, i - 1, j - 1, q);
     island(arr, i + 1, j - 1, q);
     island(arr, i - 1, j + 1, q);
     dequeue(q);
}
int main()
{
     stack q;
     q.front = -1;
     q.rear = -1;
     q.size = 50;
     int arr[10][10] = {1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1};
     int count = 0;
     for (int i = 0; i < 10; i++)
     {
          for (int j = 0; j < 10; j++)
          {
               if (arr[i][j] == 1)
               {
                    enqueue(q, arr[i][j]);
                    count++;
                    island(arr, i, j, q);
               }
          }
     }
     cout << count;
     return 0;
}
