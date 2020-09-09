#include <bits/stdc++.h>
using ll = long long int;
using ld = long double;
using namespace std;

template <class T>
class Deque{
    
    private:
    ll front, rear;
    ll size, count;
    T *deq;

    public:
     Deque()
     {
         
         size = 10000000;
         front = -1;
         rear = -1;
         count = 0;
         deq = new T[size]; 
     }

      Deque(ll N, T x);
      void push_front(T x);
      void push_back(T x);
      void pop_front();
      void pop_back();
      void clearDeque();
      void dequeResize(ll x, T d);
      void printDeque();
      ll dequeSize()
      {
         return count;
      }
      T dequeFront();
      T dequeBack();   
      T operator[](ll pos);
      bool isEmpty()
       {
         if(count == 0 || (front == -1 and rear == -1)) return true;
         return false;
       }
       bool isFull()
       {
         if((count == size) || (((rear+1) % size) == front)) return true;
         return false;
       }
};

template <class T>
Deque<T>:: Deque(ll N, T x)
     {
         size = 10000000;
         deq = new T[size];
         front = 0;
         rear = N-1; 
         count = 0;
         for(ll i=front; i<=rear; i++)
         {
             deq[i] = x;
             count++;
         }
     }

 template <class T>   
     void Deque<T>:: push_front(T x)
        {
            
            if(isEmpty())
            {
               front = 0;
               rear = 0;
               deq[front] = x;
                count++;
            }
            else if(isFull())
            {
                T *newd;
                size += 256;
                newd = new T[size];
                newd[0] = x;
                count = 1;
                ll pos = 1, i;
                for( i=front; i<=rear; i++)
                {
                    newd[pos++] = deq[i];
                    count++;
                }
                deq = newd;
                front = 0;
                rear = count-1;
                 delete[] newd;
            }

            else if(front == 0 and rear != size-1)
            {
               front = size -1;
               deq[front] = x;
                count++;
            }
            
            else
            {
                front--;
                deq[front] = x;
                 count++;
            }
           
        }

     template <class T>
     void Deque<T>::push_back(T x)
        {
            
            if(isEmpty())
            {
               front = 0;
               rear = 0;
               deq[front] = x;
                count++;
            }
            else if(isFull())
            {
                
                count = 0; 
                T *newd;
                newd = new T[size+10];
                ll pos = 0, i;
                for(i=front; i!=rear;)
                {
                    newd[pos++] = deq[i];
                    i = (i+1)%size;
                    count++;
                }
                newd[pos++] = deq[i];
                newd[pos] = x;
                count += 2;
                deq = newd;
                front = 0;
                rear = pos;
                 size +=10 ;
                delete[] newd;
            }
            else if(rear == size-1 and front != 0)
            {
                rear = 0;
                deq[rear] = x;
                count++;
            }
            else
            {
                rear++;
                count++;
                deq[rear] = x;
            }
            
        }

     template <class T>
     void Deque<T>::pop_front()
     {
         if(isEmpty())
         {
             cout << "Deque is Empty pf\n";
             return ;
         }
         else if(count == 1)
         {
             front = -1;
             rear = -1;
             count--;
         }
         else
         {
            count--;
            front = (front+1)%size;
         } 
     }   

     template <class T>
     void Deque<T>::pop_back()
     {
         if(isEmpty())
         {
             cout << "Deque is Empty pb\n";
             return;
         }
        
         else if(count == 1)
         {
             front = -1;
             rear = -1;
             count--;
         }
         else if(rear == 0)
         {
             rear = size - 1;
             count--;
         }
         else
         {
            rear--;
            count--;
         }
     }     
   
     template <class T>
     T Deque<T>::dequeFront()
     {
         if(isEmpty()) 
            {
                cout << "Deque is Empty df\n";
                exit(1);
            }
            else
            {
                return deq[front];
            }
     }

     template <class T>
     T Deque<T>::dequeBack()
     {
         if(isEmpty()) 
            {
                cout << "Deque is Empty db\n";
                exit(1);
            }
            else
            {
                return deq[rear];
            }
     }

    
    template <class T>
     void Deque<T>::dequeResize(ll x, T d)
     {
        if(x == count) return;

        else if(count == 0)
        {
            size = 10000000;
            deq = new T[size];
            front = 0;
            rear = x-1; 
            for(ll i=front; i<=rear; i++)
            {
                deq[i] = d;
                count++;
            }
         }

         else if(x < count)
         {
             ll diff = x;
              count = x;
             T *newd = new T[10000000];
              ll i, pos=0;
             for(i=front; diff>0 ;)
             {
                 newd[pos++] = deq[i];
                 i = (i+1) % size;
                 diff--;
             }
             front = 0;
             rear = pos-1;
             size = 10000000;
             delete[] deq;

             deq = newd;
         }

         else
         {
             ll diff = x - count;
             T *newd;
             newd = new T[10000000];
             ll pos = 0, i;
        
             for(i=front; i!=rear; )
             {
                 newd[pos++] = deq[i];
                 i = (i+1) % size;
             }

             newd[pos++] = deq[i];
             
             while(diff--)
                newd[pos++] = d;
             
             front = 0;
             rear = pos-1;
              count = x;
             size = 10000000;
             delete[] deq;
             deq = newd;
             }
              
         }
   
    
 template <class T>
 void Deque<T>::clearDeque()
  {
         if(isEmpty())
            return ;

         size = 10000000;
         front = -1;
         rear = -1;
         count = 0;   
  }

template <class T>    
void Deque<T>::printDeque()
    {
       if(isEmpty())
       { 
        cout << "\nDeque is Empty pd\n";
        return;
       }

      ll i;
      for( i=front; i!=rear; )
      {
          cout << deq[i] << " ";
          i = (i + 1) % size;
      }
       cout << deq[rear] ;
       cout << endl;
    }     

template <class T>    
T Deque<T>::operator[](ll pos)
{
   if((!isEmpty()) and (pos >=0) and ((front + pos)% size <= rear))
     {
        return deq[(front + pos) % size];
     }

     cout << "Invalid position\n";  
     exit(1);
}

int main()
{
    // Sample TestCase
    
    Deque<string> dq(100000, "8");
    cout << "deque size intially" << dq.dequeSize() << endl;
    ll t=100000;
    while (t--)
    {
        string t = dq[50000];
        
    }
    dq.clearDeque();
    cout << "after clear size is : " << dq.dequeSize() << endl;
    
    t = 50000;
    while(t--)
    {
        dq.push_back("2");
        dq.push_front("1");
    }
    cout << "1 lakh elements pushed\n";
     cout << "after push size is : " << dq.dequeSize()<< endl;
    
     dq.dequeResize(100001, "101010");
      cout << "\nafter calling resize, size is : " << dq.dequeSize()<< endl;
      cout << "\ndeq[99999] is : ";
      cout << dq[99999] << endl;
      cout << "\nfront : " << dq.dequeFront()<< endl;
      cout << "\nback : " << dq.dequeBack()<< endl;
    return 0;
}
