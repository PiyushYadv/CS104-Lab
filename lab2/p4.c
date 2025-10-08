#include <stdio.h>
#include <stdlib.h>

int isPresent(int *arr, int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
      return 1;
  }
  return 0;
}

int *unionArray(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
  int *result = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
  int count = 0;

  for (int i = 0; i < nums1Size; i++)
  {
    result[count++] = nums1[i];
  }

  for (int i = 0; i < nums2Size; i++)
  {
    if (!isPresent(result, count, nums2[i]))
    {
      result[count++] = nums2[i];
    }
  }

  *returnSize = count;
  return result;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int nums1[] = {1, 2, 2, 1};
  int nums2[] = {2, 2, 3};
  int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
  int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
  int returnSize;
  int *result = unionArray(nums1, nums1Size, nums2, nums2Size, &returnSize);

  printf("Union: ");
  for (int i = 0; i < returnSize; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);

  return 0;
}
