#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int k) {
   return rand() % k;
}

void print(int num[], int size)
{
   for(int i = 0; i < size; ++i) {
       cout << num[i] << " ";
   }
   cout << endl;
}

int main() {
   srand(time(NULL));
   int num[] = {2, 7, 9, 1, 8};
   int size = sizeof(num) / sizeof(int);
   int rev;
   print(num, size);
   while(size > 0)
    {
       rev = random(size);
       for(int i = rev; i < size-1; ++i)
       {
           num[i] = num[i+1];
       }
       size--;
       print(num, size);
   }
   return 0;
}
