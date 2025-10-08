#include <stdio.h>
#include <stdlib.h>

int contains(int *arr, int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
      return 1;
  }
  return 0;
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
  int *result = (int *)malloc(nums1Size * sizeof(int));
  int count = 0;

  for (int i = 0; i < nums1Size; i++)
  {
    if (contains(nums2, nums2Size, nums1[i]))
    {
      int alreadyExists = 0;
      for (int j = 0; j < count; j++)
      {
        if (result[j] == nums1[i])
        {
          alreadyExists = 1;
          break;
        }
      }
      if (!alreadyExists)
        result[count++] = nums1[i];
    }
  }

  *returnSize = count;
  return result;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int nums1[] = {1, 2, 2, 1};
  int nums2[] = {2, 2};
  int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
  int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
  int returnSize;
  int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

  printf("Intersection: ");
  for (int i = 0; i < returnSize; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);

  return 0;
}
