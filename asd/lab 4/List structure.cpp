// ASD 4 (2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct books
{
    char book_title[20];
    int book_year;
    struct books* next;
} books;

books* head = NULL, * temp = NULL, * buffer=NULL, * q = NULL, * bublesort_swap = NULL, * first_obj = NULL ;

void printlist(struct books* head) {
    struct books* temp = head;
    if (temp == NULL) {
        printf("The list is empty\n");
        return ;
    }
    do {

        printf("%s, %d\n" , temp->book_title, temp->book_year);
        temp = temp->next;
    } while (temp != head);

}

struct books* createhead(struct books* head){
    head = (books*)malloc(sizeof(books));
    printf("Enter title:  ");
    scanf_s(" %s", head->book_title, 20);
    printf("Enter year:  ");
    scanf_s(" %d", &head->book_year);
    head->next = head;
    return head;
}

struct books* deletehead(struct books* head) {
   
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
   
    return head;
}



int main()
{
    int menu,  k, f = 0;
  
    for (;;) {
        printf("Enter number for: \n1 - add new element to list \n2 - delete element from head \n3 - Cycling move on k elements to left \n4 - print list\n5 - delete list\n0 - finish program\n");

        scanf_s(" %d", &menu);
        switch (menu) {
        case 1: {
            if (head == NULL)
            {
              
             head=   createhead(head);

            }
            else {

                temp = (books*)malloc(sizeof(books));
                printf("Enter title:  ");
                scanf_s(" %s", temp->book_title, 20);
                printf("Enter year:  ");
                scanf_s(" %d", &temp->book_year);

                if ((head->next == head) && (temp->book_year < head->book_year)) {
                    q = head;
                    head = temp;
                    temp = q;
                    head->next = temp;
                    temp->next = head;
                    break;
                }
                else if ((head->next == head) && (temp->book_year >= head->book_year)) {
                    head->next = temp;
                    temp->next = head;
                    break;
                }
                else {
                    first_obj = head;
                    while (first_obj->next != head) {
                        first_obj = first_obj->next;
                    }
                  
                    for (buffer = head; buffer->next != head; buffer = buffer->next, first_obj = first_obj->next) {
                        if ((temp->book_year < buffer->book_year) && (buffer == head)) {
                            q = head;
                            bublesort_swap = head->next;
                            head = temp;
                            head->next = q;
                            q->next = bublesort_swap;
                            f = 1;
                            break;
                        }
                        else if (temp->book_year < buffer->book_year) {
                            first_obj->next = temp;
                            temp->next = buffer;
                            f = 1;
                            break;
                        }
                    }
                    if (temp->book_year < buffer->book_year) {
                        first_obj->next = temp;
                        temp->next = buffer;
                        f = 1;
                        break;
                    }
                    if (f == 0) {
                        buffer->next = temp;
                        temp->next = head;
                        break;
                    }
                }
            }
            break;


        }
        case 2: {
            if (head != NULL) {
                if ((head->next) != head)
                {
                  head=  deletehead(head);

                }
                else head= NULL ;
                printlist(head);
            }
        }
              break;
        case 3: {
            printf("Enter k:  ");
            scanf_s("%d", &k);
            for (int i = k; i > 0; --i) {
                head = head->next;
            }
           
            printlist(head);

        }
              break;
        case 4: {
            printlist(head);
            break;

        }
        case 5: {
            struct books* h = head, * q = head;
            if (head != NULL)
            {

                while ((q->next) != h) {
                    head = head->next;
                    free(q);
                    q = head;
                }
                head = NULL;

            }

            printlist(head);

            break;
        }

        case 0: {
            printf("See you spase cowboy....");
            return 0;

        }
        default: {
            printf("Try, again");
        }
        }
    }
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
