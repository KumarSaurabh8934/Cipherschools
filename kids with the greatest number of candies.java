class Solution {
public List kidsWithCandies(int[] candies, int extraCandies) {
int max=candies[0];
List l = new ArrayList();
for(int i=1;i<candies.length;i++)
if(candies[i]>max)
max=candies[i];
for(int i=0;i<candies.length;i++){
if(candies[i]+extraCandies>=max)
l.add(true);
else
l.add(false);
}
return l;
}
}
