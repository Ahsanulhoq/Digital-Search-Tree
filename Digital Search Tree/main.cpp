#include"digitalsearchtree.h"
int main()
{
    DigitalSearchTree d;
    int a;
    string s,o;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tWelcome To DIGITAL Search TREE"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"For this Demo you can only use 4bit Data,\nTherefore highest number of data you can store is 15"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    while(1)
    {
        cout<<"------------------------------------------------------------------------------------\n"<<endl;
        cout<<"Press 0 to Exit the program"<<endl;
        cout<<"Press 1 to Insert data"<<endl;
        cout<<"Press 2 to Delete a data"<<endl;
        cout<<"Press 3 to Search a data"<<endl;
        cout<<"Press 4 to Check if the Tree is Empty"<<endl;
        cout<<"Press 5 to Check Node numbers of the Tree"<<endl;
        cout<<"Press 6 to Print IN-ORDER"<<endl;
        cout<<"Press 7 to Print PRE-ORDER"<<endl;
        cout<<"Press 8 to Print POST-ORDER"<<endl;
        cout<<"Press 9 to Make Empty tree"<<endl;
        cout<<"Enter= ";
        cin>>o;
        cout<<"------------------------------------------------------------------------------------"<<endl;
        if(o=="0")
        {
            cout<<"------------------------"<<endl;
            cout<<"Good Bye!!!!"<<endl;
            return 0;
        }
        else if(o=="1")
        {
            if(d.CountNode()>=15)
            {
                cout<<"Can't add more data"<<endl;
                continue;
            }
            cout<<"Enter the amount of data you want to insert "<<endl;
            cin>>a;
            if(a>15)
            {
                cout<<"Can't store this much data"<<endl;
                continue;
            }
            getchar();
            for(int i=1;i<=a;i++)
            {
                cout<<"Enter number "<<i<<" data="<<endl;
                getline(cin,s);
                if(s.length()!=4)
                {
                    cout<<"Wrong Input"<<endl;
                    i--;
                    cout<<"------------------------"<<endl;
                    continue;
                }
                d.insertElement(s);
                cout<<i<<" Data Inserted"<<endl;
                cout<<"--------------------------------"<<endl;
            }
            cout<<"Insertion Done!"<<endl;
        }
        else if(o=="2")
        {
            cout<<"Enter the data you want to Delete "<<endl;
            cin>>s;
            getchar();
            if(s.length()!=4)
                {
                    cout<<"Wrong Input"<<endl;
                    cout<<"------------------------"<<endl;
                    continue;
                }
            if(d.searchElement(s))
                cout<<"Delete Done!"<<endl;
            else
                cout<<"\nTask Failed"<<endl;
            d.removeElement(s);

        }
        else if(o=="3")
        {
            cout<<"Enter the data you want to Search "<<endl;
            cin>>s;
            cout<<"-----------------------"<<endl;
            getchar();
            if(s.length()!=4)
                {
                    cout<<"Wrong Input"<<endl;
                    cout<<"------------------------"<<endl;
                    continue;
                }
            if(!d.isEmpty())
                {
                    if(d.searchElement(s))
                    {
                        cout<<s<<" is Found in the Tree"<<endl;
                    }
                    else
                    {
                        cout<<s<<" is not Found in the Tree"<<endl;
                    }
                }
            else
                cout<<"Tree is Empty"<<endl;
        }
        else if(o=="4")
        {
            if(d.isEmpty())
            {
                cout<<"Digital tree is Empty"<<endl;
            }
            else
            {
                cout<<"Digital tree is not empty"<<endl;
            }
        }
        else if(o=="5")
        {
            cout<<"Number of Nodes= "<<d.CountNode()<<endl;
        }
        else if (o=="6")
        {
            cout<<"In_order= ";
            d.print_tree_inorder();
            cout<<endl;
        }
        else if (o=="7")
        {
            cout<<"Pre_order= ";
            d.print_tree_preorder();
            cout<<endl;
        }
        else if (o=="8")
        {
            cout<<"Post_order= ";
            d.print_tree_postorder();
            cout<<endl;
        }
        else if(o=="9")
        {
            if(!d.isEmpty())
                {
                    d.makeTreeEmpty();
                    cout<<"Tree Erased"<<endl;
                }
            else
                {
                    cout<<"Tree is Already Empty"<<endl;
                }
        }


    }
}
