#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1,2,3,4,5,6};

            for(int i=0;i<2;i++)
            {
                int temp=nums[nums.size()-1];
                for(int j=nums.size()-2;j>=0;j--)
                {
                    nums[j+1]=nums[j];
                }
                nums[0]=temp;

            }

             for(int value:nums)
            {
                cout<<value<<" ";
            }

    return 0;
}