#include<bits/stdc++.h>
using namespace std;
int solve(std::vector<int> const & numbers)
{
    int min_so_far  = numbers[0], min_ending_here = numbers[0];
    size_t begin = 0;
    size_t begin_temp = 0;
    size_t end = 0;
    for(size_t i = 1; i < numbers.size(); i++)
    {
            if(min_ending_here > 0)
            {
                    min_ending_here = numbers[i];
                    begin_temp = i;
            }
            else
            {
                    min_ending_here += numbers[i];
            }

            if(min_ending_here <= min_so_far )
            {
                    min_so_far  = min_ending_here;
                    begin = begin_temp;
                    end = i;
            }
    }
    int sum=0;
    for(int i=0;i<begin;i++){
        sum+=numbers[i];
    }
    for(int i=begin;i<=end;i++){
        sum-=numbers[i];
    }
    for(int i=end+1;i<numbers.size();i++){
        sum+=numbers[i];
    }
    return sum;

}
int main(){
int n;
cin>>n;
vector<int> arr;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
}

  cout<<solve(arr)<<"\n";
}
