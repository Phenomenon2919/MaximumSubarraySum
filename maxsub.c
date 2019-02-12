#include <stdio.h> 
#include <limits.h> 
//Function Declaration
int max1(int a, int b);
int max2(int a, int b, int c);
int maxCrossingSum(int arr[], int l, int m, int h); 
int maxSubArraySum(int arr[], int l, int h);

//Main function
int main() 
{ 
   int i,n;

   /**
      Taking input from the user
   */
   printf("\nEnter Size of the Array: ");
   scanf("%d",&n);
   int arr[n];
   printf("\nEnter array: ");
   for(i=0;i<n;i++)
   {
      printf("\nEnter element no. %d: ",i+1);
      scanf("%d",&arr[i]);
   } 

   /**
      Calling the Maximum Subarray Sum function
   */
   int max_sum = maxSubArraySum(arr, 0, n-1); 

   //Print Result
   printf("Maximum contiguous sum = %d\n", max_sum);
   return 0; 
} 
/**
  Return maximum of 2 elements
*/
int max1(int a, int b)
{
  return (a > b)? a : b; 
}
/**
  Return maximum of 3 elements
*/
int max2(int a, int b, int c)
{ 
  return max1(max1(a, b), c); 
}

/**
  Function to add the elements from left and the right together
*/
int maxCrossingSum(int arr[], int l, int m, int h) 
{ 
    // Add elements on left of centre
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    // Add elements on right of centre
    sum = 0;
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    // Return sum of elements on left and right of centre 
    return left_sum + right_sum; 
} 

/**
  Function to calculate the maximum Subarray
  This function repeatedly calls itself for the left and right part of the array individually
  and finally calls for the cross addition of of both the parts
  Then the program returns the maximum of the three values.
*/
int maxSubArraySum(int arr[], int l, int h) 
{ 
  
   if (l == h) 
     return arr[l]; 
  
   int m = (l + h)/2; 
  
   return max2(maxSubArraySum(arr, l, m), 
              maxSubArraySum(arr, m+1, h), 
              maxCrossingSum(arr, l, m, h)); 
} 