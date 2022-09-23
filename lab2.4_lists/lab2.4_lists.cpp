//Вариант 10.
//Создайте односвязный список из 10000 целых чисел 
//и реализуйте в нем операцию удаления максимального элемента.
//Выполните M = 1000 таких запросов.
#include <iostream>
#include <chrono>
using namespace std;
#define M 1000;
#define N 10000;
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
struct T_List
{
    T_List* next;    
    int number;
};
void ADD(T_List* head, int number)
{
    T_List* p = new T_List;
    p->number = number;
    p->next = head->next;
    head->next = p;
}
void PRINT(T_List* head)
{
    T_List* p = head->next;
    while (p != nullptr)
    {
        std::cout << p->number << std::endl;
        p = p->next;
    }
}
void DELETEMAX(T_List* head)
{
    T_List* MAX;
    /*for ( int i=0; i<n-1; i++ )
        for (int j = 0; j < n+1; j++)*/
    T_List* p = head->next;
    while (p->next != nullptr)
    {        
        if (p->next->number > MAX->number)
        {
            MAX = p->next;
            p->next = p->next->next;
            //delete MAX;
        }            
         else  
             p = p->next;        
    }
    cout << MAX->number << endl;    
}
int main()
{
    T_List* head = new T_List;
    head->next = nullptr;
    Timer time1;
    for (int i = 0; i < N i++)
    {
        ADD(head, rand() % 10000);
    }
    PRINT(head);
    cout << endl;
    for (int i = 0; i < M i++)
        DELETEMAX(head);
    std::cout << "Time elapsed: " << time1.elapsed() << '\n';
    int arr[N];
    int max = 0;
    int maxnum = 0;
    for (int i = 0; i < N i++)
        arr[i] =  rand() % 10000;
    Timer time2;
    for (int j = 0; j < M j++)
    {
        for (int i = 0; i < N i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                maxnum = i;
            }
        }
        //delete arr[maxnum]; 
        arr[maxnum] = 0;
    }
    std::cout << "Time elapsed: " << time2.elapsed() << '\n';
}

