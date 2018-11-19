#include <iostream>
#include <array>
#include <vector>

/*
Question: Given a sequence of positive integers A and an integer T, 
return whether there is a continuous sequence of A that sums up to exactly T
Example
[23, 5, 4, 7, 2, 11], 20. Return True because 7 + 2 + 11 = 20
[1, 3, 5, 23, 2], 8. Return True because 3 + 5 = 8
[1, 3, 5, 23, 2], 7 Return False because no sequence in this array adds up to 7
*/
using namespace std;
int testarr[] = {23, 5, 4, 7, 2, 11};
array<int,6> myarray {23, 5, 4, 7, 2, 11};

class myTest{
public:
    myTest(int i):testValue(i),test2(300){}
    void setValue(int i);
    int getValue(const myTest&)const;
private:
    int testValue;
    int test2;

};

int myTest::getValue(const myTest & a)const
{
    return a.test2;

}
void myTest::setValue(int i)
{
    this->test2 = i;
}

int testfun(const myTest & a)
{
    //return a.testValue;
}


class MyQueue {
    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position
        int p_start;            
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};




class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        data.assign(k,0);
        head=tail=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
    if(isFull()){
        return false;
        }
    else{
        data.push_back(value);
        tail = (tail+1)%size;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
    if(isEmpty())
        {
    return false;
    }
    else
        {
        head = (head+1)%size;
        return true;
    }
        
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
        {
    return false;
    }
        else{
            return data[head-1];
            }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
        {
    return false;
    }
        else{
            return data[tail-1];
            }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
    if(head==tail)
        {
        return true;
    }
    else
        {
        return false;
    }
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
    if(((head==0)&&(tail==size-1))||((head - tail)==1))
        {
        return true;
    }
    else
        {
return false;
    }
        
    }
private:
     // store elements
    vector<int> data;       
    // a pointer to indicate the start position
    int head;
    int tail;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */


int main(int argc, char * * argv)
{
    int bigthan = 0;
    int inputNum = 0;
    const char* p = "const data";
    const char* p2 = "donst data test";
    p = p2;
    char* const p1 = "const pointer";
    //*p1 = 'a';
    cout<<"p = "<<p<<endl;
    cout<<"*p = "<<*p<<endl;
    cout<<"p1 = "<<p1<<endl;
    cout<<"*p1 = "<<*p1<<endl;


    for (int i = 0; i < myarray.size(); ++i)
        {
            if(myarray[i]>=inputNum)
                {
                    bigthan = myarray[i];
                    cout<<bigthan<<endl;
                    break;
                }
        }
    cout<<bigthan<<endl;
    myTest mytes(2);
    myTest myt2(4);
    cout<<"myt2 test2 value is "<<myt2.getValue(myt2)<<endl;
    myt2.setValue(6);
    cout<<"myt2 test2 value is "<<myt2.getValue(myt2)<<endl;
    
    cout<<"test is "<<mytes.getValue(mytes)<<endl;
    //cout<<"test private is "<<mytes.testValue<<endl;

    MyCircularQueue obj(5);
    //MyCircularQueue *mcq = new MyCircularQueue(4);
    for(int i = 0;i<3;i++){
    obj.enQueue(i);
       }
    cout<<"obj is full "<<obj.isFull()<<endl;
    
    cout<<"obj is rear "<<obj.Rear()<<endl;
    cout<<"obj is font "<<obj.Front()<<endl;
}
