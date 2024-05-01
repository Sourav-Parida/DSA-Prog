struct node
{
    int coff, exp1, exp2;
    struct node *next;
};

void add(struct node *poly1, struct node *poly2)
{
    struct node *p1, *p2, *prev, *q;
    if (poly1 == NULL) // join two linked list
        poly1 = poly2;
    else
    {
        q = poly1;
        while (q→next != NULL)
            q = q→next;
        q→next = poly2;
    }
    for (p1 = poly1; p1 != NULL; p1 = p1→next)
    {
        // duplicate remove
        prev = p1;
        for (p2 = p1→ next; p2 != NULL;)
            if (p1→exp1 == p2→exp1 && p1→exp2 == p2→exp2){
                p1→coff = p1→coff + p2→coff
                prev→next = p2→next;
                free(p2);
                p2 = prev → next;
            }
            else
            {
                prev = p2;
                p2 = p2 → next;
            }
    }
}