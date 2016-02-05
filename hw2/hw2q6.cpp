
Node* merge(Node*& first, Node*& second)
{
    Node* ret = NULL;
    if (first == NULL)
    {
        return(second);
    }

    else if (second==NULL)
    {
       return(first);
    }

    if (first->data <= second->data)
    {
        ret = first;
        ret->next = merge(first->next, second);
    }

    else
    {
        ret = second;
        ret->next = merge(first, second->next);
    }

    first = second = NULL;
    return(ret);
}