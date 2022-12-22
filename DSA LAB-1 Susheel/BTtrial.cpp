Node* MergeTrees(Node* t1, Node* t2)
{
    if (! t1)
        return t2;
    if (! t2)
        return t1;
    stack<snode> s;
    snode temp;
    temp.l = t1;
    temp.r = t2;
    s.push(temp);
    snode n;
    while (! s.empty())
    {
        n = s.top();
        s.pop();
        if (n.l == NULL|| n.r == NULL)
            continue;
        n.l->data += n.r->data;
        if (n.l->left == NULL)
            n.l->left = n.r->left;
        else
        {
            snode t;
            t.l = n.l->left;
            t.r = n.r->left;
            s.push(t);
        }
        if (n.l->right == NULL)
            n.l->right = n.r->right;
        else
        {
            snode t;
            t.l = n.l->right;
            t.r = n.r->right;
            s.push(t);
        }
    }
    return t1;
}