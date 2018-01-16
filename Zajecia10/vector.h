typedef struct _Vector
{
    int *array;
    int capacity;
    int amountOfElements;
} Vector;

void initialise(Vector *vector);
void reserve(Vector *vector, int size);
int size(Vector *vector);
int capacity(Vector *vector);
void empty(Vector *vector);
void pushBack(Vector *vector, int element);
void insert(Vector *vector, int position, int element);
void removeFromEnd(Vector *vector);
void reverse(Vector *vector);
int at(Vector *vector, int position);