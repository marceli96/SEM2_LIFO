#include <iostream>

using namespace std;


class Element
{
public:
    int value;
    Element *next;
    Element *prev;

    Element(int x)
    {
        value = x;
        next = NULL;
        prev = NULL;
    }
};

class LIFO
{
private:
    Element *head;
    int maxSize = 10;
    int currentSize;

public:
    LIFO()
    {
        head = NULL;
        currentSize = 0;
    }

    bool canIpush()
    {
        if (currentSize < maxSize)
            return true;
        else
        {
           cout << "Nie mozna dodac kolejnego elementu, poniewaz stos jest pelny!" << endl;
            return false;
        }

    }

    int push(int x)
    {
        if (canIpush())
        {
            Element *newElement = new Element(x);
            if (head == NULL)
            {
                head = newElement;
                currentSize++;
            }
            else
            {
                head->prev = newElement;
                newElement->next = head;
                head = newElement;

                currentSize++;
            }

        }
        else
        {
            return -1;
        }
    }

    bool canIpop()
    {
        if(head==NULL)
        {
            cout << "Nie mozna zdjac elementu, poniewaz stos jest pusty!" << endl;;
            return false;
        }
        else
            return true;
    }

    void pop()
    {
        Element *temp = head;

        if(canIpop())
        {
            Element *toDelete;
            toDelete = head;
            head = head->next;
            delete(toDelete);

            currentSize--;
        }
    }

    int showTop()
    {
        return head->value;
    }

    void show()
    {
        Element *temp = head;
        cout << "Stos:" << endl;
        while (temp != NULL)
        {
            cout << temp->value << endl;
            temp=temp->next;
        }

    }

    void check()
    {
        if(currentSize==0)
            cout << "Stos jest pusty!" << endl;
        else if ((currentSize > 0) & (currentSize < maxSize))
            cout << "Na stose jest " << currentSize <<" elementow." << endl;
        else if (currentSize = maxSize)
            cout << "Stos jest pe³ny!" << endl;
    }


};


int main()
{
    LIFO stos;
    stos.check();
    stos.push(5);
    stos.push(6);
    stos.push(1);
    stos.push(52);
    stos.push(35);

    stos.show();
    cout << "Wartosc wierzcholka wynosi: " << stos.showTop() << endl;
    stos.check();
    stos.pop();
    stos.show();
    cout << "Wartosc wierzcholka wynosi: " << stos.showTop() << endl;
    stos.check();

    stos.pop();
    stos.pop();
    stos.pop();
    stos.pop();
    stos.pop();
    stos.show();
    stos.check();


    return 0;
}
