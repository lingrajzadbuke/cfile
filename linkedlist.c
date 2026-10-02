#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_node(int data)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void create()
{
  int n, i, data;
  struct node *temp, *newnode;

  printf("Enter number of nodes: ");
  scanf("%d", &n);

  head = NULL;
  for (i = 0; i < n; i++)
  {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);
    newnode = create_node(data);

    if (head == NULL)
    {
      head = newnode;
    }
    else
    {
      temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newnode;
    }
  }
}

void display()
{
  struct node *temp;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("Linked list: ");
  temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insert_first()
{
  int data;
  struct node *newnode;

  printf("Enter data to insert at first: ");
  scanf("%d", &data);

  newnode = create_node(data);
  newnode->next = head;
  head = newnode;
}

void insert_last()
{
  int data;
  struct node *newnode, *temp;

  printf("Enter data to insert at last: ");
  scanf("%d", &data);

  newnode = create_node(data);

  if (head == NULL)
  {
    head = newnode;
    return;
  }

  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}

void insert_at_pos()
{
  int data, pos, i;
  struct node *newnode, *temp;

  printf("Enter position to insert: ");
  scanf("%d", &pos);
  printf("Enter data: ");
  scanf("%d", &data);

  if (pos < 1)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    newnode = create_node(data);
    newnode->next = head;
    head = newnode;
    return;
  }

  temp = head;
  for (i = 1; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of range\n");
    return;
  }

  newnode = create_node(data);
  newnode->next = temp->next;
  temp->next = newnode;
}

void delete_first()
{
  struct node *temp;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  temp = head;
  head = head->next;
  printf("Deleted: %d\n", temp->data);
  free(temp);
}

void delete_last()
{
  struct node *temp, *prev;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  if (head->next == NULL)
  {
    printf("Deleted: %d\n", head->data);
    free(head);
    head = NULL;
    return;
  }

  temp = head;
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  printf("Deleted: %d\n", temp->data);
  free(temp);
}

void delete_at_pos()
{
  int pos, i;
  struct node *temp, *prev;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("Enter position to delete: ");
  scanf("%d", &pos);

  if (pos < 1)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return;
  }

  temp = head;
  for (i = 1; i < pos && temp != NULL; i++)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of range\n");
    return;
  }

  prev->next = temp->next;
  printf("Deleted: %d\n", temp->data);
  free(temp);
}

int main()
{
  int ch;

  while (1)
  {
    printf("\n--- Linked List Menu ---\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Insert first\n");
    printf("4. Insert last\n");
    printf("5. Insert at position\n");
    printf("6. Delete first\n");
    printf("7. Delete last\n");
    printf("8. Delete at position\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      display();
      break;
    case 3:
      insert_first();
      break;
    case 4:
      insert_last();
      break;
    case 5:
      insert_at_pos();
      break;
    case 6:
      delete_first();
      break;
    case 7:
      delete_last();
      break;
    case 8:
      delete_at_pos();
      break;
    case 9:
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
}