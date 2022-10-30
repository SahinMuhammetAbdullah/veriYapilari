    int op,ch;
    do{
        printf("-------Welcome--------\n ");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n6.Sort\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
            case 6:sort();
            break;
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d",&op);
    }while(op!=0);