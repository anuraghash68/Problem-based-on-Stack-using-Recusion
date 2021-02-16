#include<bits/stdc++.h>
using namespace std;
   

void insertBottomOfStack(stack<int>&s, int val)
{
  if(s.size() == 0)
  {
    s.push(val);
    return;
  }
  else{
    int curr = s.top();
    s.pop();
    insertBottomOfStack(s, val);
    s.push(curr);
  }

}
void insertIntoMiddleOfStack(stack<int>&s, int val, int n)
{
 
  if(n/2 == s.size() && n%2 == 0)
  {
    s.push(val);
    return;
  }
  else if((n/2)+1 == s.size() && n%2 != 0)
  {
   s.push(val);
   return;
  }
  else{
    int curr = s.top();
    s.pop();
    insertIntoMiddleOfStack(s, val, n);
    s.push(curr);
  }
}
void deleteIntoMiddleOfStack(stack<int>&s, int n)
{
 
  if(n/2 == s.size() && n%2 == 0)
  {
    s.pop();
    return;
  }
  else if((n/2)+1 == s.size() && n%2 != 0)
  {
   s.pop();
   return;
  }
  else{
    int curr = s.top();
    s.pop();
    deleteIntoMiddleOfStack(s, n);
    s.push(curr);
  }
}

void reverseStack(stack<int>&s)
{
  // 5 -> 4 -> 3 ->2 ->1
//1,2,3,4,5, -->>>  5 -> 1 -> 2  -> 3 ->4  - >>> 5 -> 4 -> 1 -> 2 -> 3  ->>> 
                                                 //5 -> 4 -> 3 -> 1 -> 2 
                                                 // 5 -> 4  -> 3 -> 2 -> 1  
  if(s.size() == 1)
  {
    return;
  }
  else{
  int curr = s.top();
  s.pop();
  reverseStack(s);//o(n)
  insertBottomOfStack(s, curr);//o(n) --->>> total T.C = o(n) + o(n) ~ o(n);
  }

}


void insertInStackAtCorrectPos(stack<int>&s, int val)
{
  if(s.size() == 0 || s.top() == val)
  {
    s.push(val);
    return;
  }
  else{
    int ele = s.top();
    s.pop();
    insertInStackAtCorrectPos(s, val);
    s.push(ele);
  }
}

void sortStack(stack<int>&s)
{
  if(s.size() == 1)
  {
    return;
  }
  else{
    int curr = s.top();
    s.pop();
    sortStack(s);
    insertInStackAtCorrectPos(s, curr);
  }
}

int main()
{

   stack<int>s;
   s.push(7);
   s.push(6);
   s.push(5);
   s.push(4);
   s.push(3);
   s.push(2);
   s.push(1);

   //insert(s, 6);

   //insertIntoMiddleOfStack(s, 7, s.size());
   //deleteIntoMiddleOfStack(s, s.size());
   sortStack(s);
   while(!s.empty())
   {
    cout << s.top() << ' ';
    s.pop();
   }
  
   return 0;
}