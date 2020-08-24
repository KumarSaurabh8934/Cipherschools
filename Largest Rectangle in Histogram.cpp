class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        if(arr.empty())
			{return 0;}
        
        int l[arr.size()], r[arr.size()];
        stack <int > s;
        
		// finding the position of the smaller bar nearest to current bar from left
		// ie equivalent to finding the next smaller element to the left
        for(int x=0;x<arr.size();x++)
        {
            if(s.empty())
            {l[x]= -1;}
            
            else if(arr[s.top()] >= arr[x])
            {
                while(!s.empty() && arr[s.top()]>=arr[x])
                    {s.pop();}
                
                if(s.empty())
                    {   l[x]= -1;}
                
                else
                    {   l[x]= s.top();}
                    
            }
            
            else if(arr[s.top()] < arr[x])
            {
                l[x]=s.top();
            }
            
            s.push(x);
        }
        
        while(!s.empty())
        {s.pop();}
        
		
		// finding the position of the smaller bar nearest to current bar from right
		// ie equivalent to finding the next smaller element to the right
                 
        for(int x= arr.size()-1; x>=0;x--)
        {
            if(s.empty())
            {
                r[x]= arr.size();
            }
            
            else if(arr[x] <= arr[s.top()])
            {
                while(!s.empty() && arr[s.top()]>=arr[x])
                    {s.pop();}
                
                if(s.empty())
                    {r[x]= arr.size();}
                
                else
                    {r[x]= s.top();}
                    
            }
            
            else if(arr[s.top()] < arr[x])
            {
                r[x]=s.top();
            }
            
            s.push(x);
        }
        
        int max=0;        
		
        for(int x=0; x<arr.size();x++)
        {
	
				if( max< arr[x]*(r[x]-l[x]-1))
					{
							max = arr[x]*(r[x]-l[x]-1); 
					}
			
		}
                 
        return max;
    }
};
