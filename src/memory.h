typedef struct Partition Partition;
struct Partition {
	int	size,
		free;
 	struct Partition *next;
};

typedef struct Memory Memory;
struct Memory {
    struct Partition *head;
};

void insert_partition(Memory * list, Partition * partition)
{

    if (list == NULL || partition == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->head == NULL)
    {
    	list->head = partition;
    }
    else
    {
		Partition * temp = list->head;
		while(temp->next != NULL)  
			temp = temp->next;
		partition->next = NULL;
		temp->next = partition;
    }
}

void delete_partition(Memory * list, Partition * partition)
{
	if(list->head == partition)
	{
		if(list->head->next == NULL)
        {
            list->head = NULL;
            free(partition);
            return;
        }
        list->head = list->head->next;
 
        free(partition);
 
        return;
	}
	else
	{
	    Partition *prev = list->head;
	    while(prev->next != NULL && prev->next != partition)
	        prev = prev->next;
	 
	    if(prev->next == NULL)
	    {
	        return;
	    }
	 
	    prev->next = prev->next->next;
	 
	    free(partition);
	 
	    return; 
	}
}

// http://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
void move_partition(Memory * source, Memory * destination, Partition * partition)
{
	Partition * p_move 	= malloc(sizeof(Partition));
	p_move->size		= partition->size;
	p_move->free 		= partition->free
	p_move->next 		= NULL;	

	if (destination->head == NULL)
    {
    	destination->head = p_move;
    }
    else
    {
		Partition * temp = destination->head;
		while(temp->next != NULL)  
			temp = temp->next;
		temp->next = p_move;
    }

    delete_partition(source, partition);
}

void print_partition(Partition * partition)
{
	printf("Size: %d octets \n", 
		partition->size
	);
}

void print_list(List * list) {
    
	if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Partition * current = list->head;

    while (current != NULL) 
    {
    	print_partition(current);
        current = current->next;
    }
}

int list_size(Memory * list)
{
	if(list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Partition * current = list->head;
	int count = 0;

	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

Memory * init_list(int * n)
{
	Memory * l = malloc(sizeof(Memory));

	if (l == NULL || p ==  NULL)
	{
		exit(EXIT_FAILURE);
	}

 	l->head = NULL;

 	return l;
}