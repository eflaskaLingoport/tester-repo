    node *n = new node;
    n->next = NULL;
    n->key = hashFunction(key);
    n->value = key;
    int p = n->key;
    if(table[n->key] == NULL)
    {
        table[n->key] = n;
        return;
    }
    else if(table[p]->key == key)
    {
        numOfcolision++;
        bool flag = false;
        int i = p;
        while(!flag)
        {
            if(table[i] == NULL)
            {
                table[i] = n;
                flag = true;
                return;
                break;
            }
            else if(i == tableSize)
            {
                p = 0;
                flag = true;
            }
            else
            {
                numOfcolision++;
                i++;
            }
            
        }
        if(p == 0)
        {
            int i = 0;
            bool flag2 = false;
            while(!flag2)
            {
                if(table[i] == NULL)
                {
                    table[i] = n;
                    flag = true;
                    break;
                }
                else if(table[i] != NULL)
                {
                    numOfcolision++;
                    i++;
                }
            }
        }
    }