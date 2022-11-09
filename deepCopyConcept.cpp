#include<iostream>
using namespace std;

class Arr
{
    private:
        int size;
        float *a = new float[size];
    public:
        Arr()
        {
            size = 0;
        }
        void setArray(float ar[], int size)
        {
            this->size = size;

            float *newArr = new float[this->size];
            delete a;
            a = newArr;
            int i;
            for(i = 0; i < this->size; i++)
            {
                a[i] = ar[i];
            }
        }
        Arr(float ar[], int size)
        {
            this->size = size;

            int i;
            for(i = 0; i < this->size; i++)
            {
                a[i] = ar[i];
            }
        }
        ~Arr()
        {
            delete a;
        }
        void displayArray()
        {
            int i;
            for(i = 0; i < size; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        float getElement(int index)
        {
            return a[index];
        }
        float operator[](int index)
        {
            if(index >= 0 && index < this->size)
                return a[index];
            else
                cout<<"This index does not exist in the array!!!";
                return -1;
        }
        void operator=(Arr &ar)
        {
            cout<<"Operator = called"<<endl;
            size = ar.size;
            float * newArr = new float[size];

            int i;
            for(i = 0; i < size; i++)
            {
                newArr[i] = ar.a[i];
            }
            a = newArr;
        }
        Arr(Arr &ar)
        {
            cout<<"Copy Constructor called"<<endl;
            size = ar.size;
            float * newArr = new float[size];

            int i;
            for(i = 0; i < size; i++)
            {
                newArr[i] = ar.a[i];
            }
            a = newArr;
        }
};

int main()
{
    float a[] = {11, 22, 33, 44, 55, 66};
    Arr n(a, 6);
    Arr n2;
    n2 = n;

    Arr n3 = n;

    n.displayArray();
    n2.displayArray();
    n3.displayArray();

    float a2[] = {1, 2, 3};
    n.setArray(a2, 3);

    n.displayArray();
    n2.displayArray();
    n3.displayArray();
    return 0;
}
