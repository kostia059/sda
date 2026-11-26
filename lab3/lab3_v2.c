#include <stdio.h>
#include <stdlib.h>

int is_empty_queue();
int is_full_queue();
int size_queue();

int is_empty_stack();
int is_full_stack();
int size_stack();

#define SIZE 50
#define TESTING 0



// Реалізація функцій структур даних
// node
typedef struct Node
{
    char symbol;
    struct Node* next;
} Node;

// stack
Node* bottom = NULL;
Node* top = NULL;

void push(char c)
{
    if (!is_empty_stack())
    {
        Node* new_node = malloc(sizeof(Node));

        top->next = new_node;
        new_node->symbol = c;
        
        top = new_node;
    }
    else
    {
        bottom = malloc(sizeof(Node));
        
        bottom->symbol = c;
        bottom->next = NULL;
        
        top = bottom;
    }
} // to insert an element into the stack
char pop()
{
    if (!is_empty_stack())
    {
        if (top == bottom)
        {
            char result = bottom->symbol;

            free(bottom);
            bottom = NULL;

            return result;
        }
        else
        {
            char result = top->symbol;
    
            Node* curr = bottom;
    
            while (curr->next != top)
            {
                curr = curr->next;
            }
            free(top);
            top = curr;
    
            return result;
        }
    }

    printf("Стек порожній!\n");
    return '\0';
} // to remove an element from the stack
char peek()
{
    if (!is_empty_stack())
    {
        char result = top->symbol;
        return result;
    }
    return '\0';
} // returns the top element of the stack
int is_empty_stack()
{
    if (bottom == NULL)
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
    if (is_empty_stack())
    {
        return 0;
    }

    int size = 1;
    Node* curr = bottom;
    while (curr->next != NULL)
    {
        curr = curr->next;
        size++;
    }
    
    return size;
} // returns the size of the stack

// queue
Node* head = NULL;
Node* tail = NULL;

void enqueue(char c)
{
    if (!is_empty_queue())
    {
        Node* new_node = malloc(sizeof(Node));
        
        tail->next = new_node;
        new_node->symbol = c;
        
        tail = new_node;
    }
    else
    {
        head = malloc(sizeof(Node));
        
        head->symbol = c;
        head->next = NULL;

        tail = head;
    }
} // insertion of elements to the queue
char dequeue()
{
    if (!is_empty_queue())
    {
        Node* temp = head;

        char result = head->symbol;
        head = head->next;
        
        free(temp);

        return result;
    }

    printf("Черга порожня!\n");
    return '\0';
} // removal of elements from the queue
char peek_front()
{
    if (!is_empty_queue())
    {
        char result = head->symbol;
        return result;
    }

    return '\0';
} // returns the data element available at the front node of the queue without deleting it
int is_empty_queue()
{
    if (head == NULL)
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
    if (is_empty_queue())
    {
        return 0;
    }

    int size = 1;
    Node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        size++;
    }
    
    return size;
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
