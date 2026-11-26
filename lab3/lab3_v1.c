#include <stdio.h>

int is_empty_queue();
int is_full_queue();
int size_queue();

int is_empty_stack();
int is_full_stack();
int size_stack();

#define SIZE 50
#define TESTING 0



// Реалізація функцій структур даних
// stack
char stack[SIZE];
signed char top = -1;

void push(char c)
{
    if (!is_full_stack())
    {
        top++;
        stack[top] = c;
        return;
    }

    printf("Стек повний!\n");
} // to insert an element into the stack
char pop()
{
    if (!is_empty_stack())
    {
        top--;
        return stack[top+1];
    }
    
    printf("Стек порожній!\n");
    return '\0';
} // to remove an element from the stack
char peek()
{
    if (!is_empty_stack())
    {
        return stack[top];
    }
    
    printf("Стек порожній!\n");
    return '\0';
} // returns the top element of the stack
int is_empty_stack()
{
    if (top == -1)
    {
        return 1;
    }

    return 0;
} // checks if the stack is empty
int is_full_stack()
{
    if (size_stack() == SIZE)
    {
        return 1;
    }

    return 0;
} // checks if the stack is full
int size_stack()
{
    return top + 1;
} // returns the size of the stack

// queue
char queue[SIZE];

signed char head = -1;
signed char tail = -1;

void enqueue(char c)
{
    if (is_empty_queue())
    {
        head = 0; tail = head;
        // head++;
        // tail = head;
        queue[head] = c;
    
        return;
    }
    else if (!is_full_queue())
    {
        if (tail != SIZE - 1)
        {
            tail++;
            queue[tail] = c;
        }
        else
        {
            head--;
            queue[head] = c;
        }
    
        return;
    }

    printf("Черга повна!\n");
} // insertion of elements to the queue
char dequeue()
{
    if (!is_empty_queue())
    {
        head++;
        return queue[head-1];
    }

    printf("Черга порожня!\n");
    return '\0';
} // removal of elements from the queue
char peek_front()
{
    if (!is_empty_queue())
    {
        return queue[head];
    }

    printf("Черга порожня!\n");
    return '\0';
} // returns the data element available at the front node of the queue without deleting it
int is_empty_queue()
{
    if (head == -1 || head > tail)
    {
        return 1;
    }
    
    return 0;
} // checks if the queue is empty
int is_full_queue()
{
    if (size_queue() == SIZE)
    {
        return 1;
    }

    return 0;
} // checks if the queue is full
int size_queue()
{
    if (!is_empty_queue())
    {
        return tail - head + 1;
    }

    return 0;
} // returns the size of the queue



// Прикладна частина програми
int compare(char a, char b)
{
    if (a == b)
    {
        return 1;
    }
    else if (b > a)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    a -= 32;

    if (a == b)
    {
        if (a >= 65 && a <= 90)
        {
            return 1;
        }
    }
    return 0;
}

int test();

int main()
{
    if (TESTING == 1)
    {
        test();
        return 0;
    }

    char sentence[SIZE];
    char result = -1;
    
    fgets(sentence,SIZE,stdin);

    // push & enque
    for (int i = 0; i < SIZE; i++){
        char c = sentence[i];
        if (c == '\0')
        {
            break;
        }

        if (c < 32 || c == 127)
        {
            break;
        }

        push(c);
        enqueue(c);
    }
    
    // compare symbols
    for (int i = 0; i < SIZE; i++){
        if (peek() == ' ')
        {
            pop();
            continue;
        }
        if (peek_front() == ' ')
        {
            dequeue();
            continue;
        }

        char a = pop();
        char b = dequeue();

        if (compare(a, b))
        {
            if (is_empty_queue() || is_empty_stack())
            {
                result = 1;
                break;
            }
        }
        else
        {
            result = 0;
            break;
        }
    }

    if (result == 1)
    {
        printf("Так\n");
    }
    else if (result == 0)
    {
        printf("Ні\n");
    }
    else
    {
        printf("Щось пішло не так\n");
    }

    return 0;
}

int test()
{
    printf("Тестування\n");
    printf("\nСпроба виконати операцію на порожній структурі\n");
    printf("pop() при порожньому стеці:\n");
    char temp = pop();
    printf("функція повернула: \"%c\" (%i)\n", temp, temp);

    printf("dequeue() при порожній черзі:\n");
    temp = dequeue();
    printf("функція повернула: \"%c\" (%i)\n", temp, temp);

    printf("\nДодавання елементу в заповнену структуру\n");
    for (int i = 0; i < SIZE; i++)
    {
        push('A');
        enqueue('A');
    }

    printf("push() при заповненому стеці:\n");
    push('A');

    printf("enqueue() при заповненій черзі:\n");
    enqueue('A');
}
