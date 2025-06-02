#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class MyList
{
private:
    int myListSize = 0;
    int myListCapacity = 1;
    int currentPosition = 0;
    T *array;

public:
    MyList(int X)
    {
        myListCapacity = X;
        array = new T[myListCapacity];
    }
    MyList()
    {
        array = new T[myListCapacity];
    }
    int size()
    {
        return myListSize;
    }
    void push(T item)
    {
        if (myListSize + 1 > myListCapacity)
        {
            T *temp;
            temp = new T[myListCapacity * 2];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myListCapacity *= 2;
        }
        for (int i = myListSize; i > currentPosition; i--)
            array[i] = array[i - 1];
        array[currentPosition] = item;
        myListSize++;
    }
    void pushBack(T item)
    {
        if (myListSize + 1 > myListCapacity)
        {
            T *temp;
            temp = new T[myListCapacity * 2];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myListCapacity *= 2;
        }
        array[myListSize] = item;
        myListSize++;
    }
    T erase()
    {
        T ret = array[currentPosition];
        for (int i = currentPosition; i < myListSize; i++)
            array[i] = array[i + 1];
        myListSize--;
        if (myListCapacity / 2 == myListSize)
        {
            T *temp;
            myListCapacity /= 2;
            temp = new T[myListCapacity];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        return ret;
    }
    void setToBegin()
    {
        currentPosition = 0;
    }
    void setToEnd()
    {
        currentPosition = myListSize - 1;
    }
    void prev()
    {
        if (currentPosition != 0)
            currentPosition--;
    }
    void next()
    {
        if (currentPosition != myListSize - 1)
            currentPosition++;
    }
    int currPos()
    {
        return currentPosition;
    }
    void setToPos(int pos)
    {
        if (pos < myListSize && pos > -1)
            currentPosition = pos;
    }
    T getValue()
    {
        return array[currentPosition];
    }
    int find(T item)
    {
        for (int i = 0; i < myListSize; i++)
        {
            if (array[i] == item)
                return i;
        }
        return -1;
    }
    void display()
    {
        cout << "<";
        for (int i = 0; i < myListSize; i++)
        {
            if (i == currentPosition)
                cout << "| ";
            cout << array[i];
            if (i != myListSize - 1)
                cout << ' ';
        }
        cout << ">";
        cout << endl;
    }
    void clear()
    {
        delete[] array;
        myListSize = 0;
        myListCapacity = 1;
        currentPosition = 0;
        array = new T[myListCapacity];
    }
    ~MyList()
    {
        this->clear();
    }
};

int main()
{
    int n, k;
    // freopen("list_input.txt", "r", stdin);
    // freopen("list_output.txt", "w", stdout);
    cin >> k >> n;
    MyList<int> ml(n);
    int p;
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        ml.pushBack(p);
    }
    ml.setToPos(0);
    ml.display();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, ret = -1;
        cin >> a >> b;
        if (a == 1)
        {
            ml.display();
            ret = ml.size();
        }
        else if (a == 2)
        {
            ml.push(b);
            ml.display();
        }
        else if (a == 3)
        {
            ml.pushBack(b);
            ml.display();
        }
        else if (a == 4)
        {
            ret = ml.erase();
            ml.display();
        }
        else if (a == 5)
        {
            ml.setToBegin();
            ml.display();
        }
        else if (a == 6)
        {
            ml.setToEnd();
            ml.display();
        }
        else if (a == 7)
        {
            ml.prev();
            ml.display();
        }
        else if (a == 8)
        {
            ml.next();
            ml.display();
        }
        else if (a == 9)
        {
            ret = ml.currPos();
            ml.display();
        }
        else if (a == 10)
        {
            ml.setToPos(b);
            ml.display();
        }
        else if (a == 11)
        {
            ml.display();
            ret = ml.getValue();
        }
        else if (a == 12)
        {
            ml.display();
            ret = ml.find(b);
        }
        else if (a == 13)
        {
            ml.clear();
            ml.display();
        }
        cout << ret << endl;
    }
    return 0;
}