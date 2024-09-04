#include<iostream>
#include<cstring>
using namespace std;

struct items
{
    int item;
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void BillHeader(char name[50],char date[30])
{
    cout<<"\n\n";
    cout<<"\t Restaurant";
    cout<<"\n\t -------------";
    cout<<"\nInvoice to:"<<date<<endl;
    cout<<"-----------------------------------------------\n";
    cout<<"Items  \t\t";
    cout<<"\tQuantity\t";
    cout<<"Total\t\t\n";
    cout<<"-----------------------------------------------\n";
    cout<<endl;

}

void BillBody(int item,int qty, float price)
{
    switch(item)
    {
    case 11:
        cout<<"FRENCH FRIES      "<<"\t";
        break;
    case 12:
        cout<<"SWEET POTATO FRIES"<<"\t";
        break;
    case 14:
        cout<<"SPICY CHICKEN     "<<"\t";
        break;
    case 13:
        cout<<"CHEESE BURGER     "<<"\t";
        break;
    case 15:
        cout<<"CHICKEN BURGER    "<<"\t";
        break;
    case 16:
        cout<<"CHEESE CAKE       "<<"\t";
        break;
    case 17:
        cout<<"CLASSIC PIZZA     "<<"\t";
        break;
    case 18:
        cout<<"CHEESE PIZZA      "<<"\t";
        break;
    case 19:
        cout<<"PIZZA MASHROOMS   "<<"\t";
        break;
    case 21:
        cout<<"MILK SHAKE        "<<"\t";
        break;
    case  22:
        cout<<"ICE TEA           "<<"\t";
        break;
    case 23:
        cout<<"ORANGE JIUCE      "<<"\t";
        break;
    case 24:
        cout<<"LEMON TEA         "<<"\t";
        break;
    case 25:
        cout<<"COFFEE            "<<"\t";
        break;
    case 31:
        cout<<"APPLE PIE         "<<"\t";
        break;
    case 32:
        cout<<"ICE CREAM         "<<"\t";
        break;
    case 33:
        cout<<"COLD COFFEE       "<<"\t";
        break;


    }
    cout<<qty<<"\t\t";
    cout<<qty*price;
    cout<<endl;
}

void BillFooter(float total,float net,char parcel )
{
    cout<<"\n";
    float discount;

    if(total>=500)
    {
        discount = 0.1*total;
    }
    else
    {
        discount = 0.0;
    }
    float netTotal=total+net-discount;
    if(parcel=='Y')
    {
        cout<<"\nParcel charge\t\t\t\t 150 BDT";
    }

    cout<<"\n-----------------------------------------------\n";
    cout<<"Sub Total\t\t\t\t"<<total<<" BDT";

    if(discount !=0)
    {
        cout<<"\nDiscount @10% \t\t\t\t"<<discount<<" BDT";
    }
    else
    {
        cout<<"\nDiscount @0% \t\t\t\t"<<discount<<" BDT";
    }

    cout<<"\n\t\t\t\t\t-------";
    cout<<"\nNet Total\t\t\t\t"<<netTotal<<" BDT";
    cout<<"\n-----------------------------------------------";

}

void menu()
{
    cout<<"\n\n";
    cout<<"\t=============RESTAURANT Menu============";
    cout<<"\n\n----Main Course----\n";
    cout<<"11.FRENCH FRIES            BDT.150\n";
    cout<<"12.SWEET POTATO FRIES      BDT.220\n";
    cout<<"13.CHEESE BURGER           BDT.200\n";
    cout<<"14.SPICY CHICKEN           BDT.130\n";
    cout<<"15.CHICKEN BURGER          BDT.240\n";
    cout<<"16.CHEESE CAKE             BDT.450\n";
    cout<<"17.CLASSIC PIZZA           BDT.350\n";
    cout<<"18.CHEESE PIZZA            BDT.400\n";
    cout<<"19.PIZZA MASHROOMS         BDT.450\n";
    cout<<"\n----DRINKS----\n";
    cout<<"21.MILK SHAKE              BDT.100\n";
    cout<<"22.ICE TEA                 BDT.80\n";
    cout<<"23.ORANGE JIUCE            BDT.70\n";
    cout<<"24.LEMON TEA               BDT.80\n";
    cout<<"25.COFFEE                  BDT.60\n\n";
    cout<<"----DESSERT---\n";
    cout<<"31.APPLE PIE               BDT.200\n";
    cout<<"32.ICE CREAM               BDT.150\n";
    cout<<"33.COLD COFFEE             BDT.140\n";
}

int main()
{

    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'Y',count  = 'Y',parcel= 'Y';
    char name[50];
    FILE *file;

    while(count=='Y')
    {
        system("clear");
        float total = 0;
        float net=0;
        int invoiceFound = 0;
        cout<<"\t=============RESTAURANT============";
        cout<<"\n\nPlease select your prefered operation";
        cout<<"\n\n1.Generate Invoice";
        cout<<"\n2.Show all Invoices";
        cout<<"\n3.Search Invoice";
        cout<<"\n4.Exit";
        cout<<"\n\nYour choice:\t";
        cin>>opt;
        fgetc(stdin);

        switch(opt)
        {
        case 1:
            system("clear");
            menu();
            cout<<"\nPlease enter the name of the customer:\t";
            fgets(ord.customer,50,stdin);
            ord.customer[strlen(ord.customer)-1] = 0;
            strcpy(ord.date,__DATE__);
            cout<<"\nPlease enter the number of items:\t";
            cin>>n;
            ord.numOfItems = n;
            for(int i=0; i<n; i++)
            {
                fgetc(stdin);
                cout<<"\n\n";
                cout<<"Please enter the item: \t"<<i+1<<"\t";
                cin>> ord.itm[i].item;
                cout<<"Please enter the quantity:\t";
                cin>>ord.itm[i].qty;
                switch(ord.itm[i].item)
                {
                case 11:
                    ord.itm[i].price=150;
                    break;
                case 12:
                    ord.itm[i].price=220;
                    break;
                case 13:
                    ord.itm[i].price=200;
                    break;
                case 14:
                    ord.itm[i].price=130;
                    break;
                case 15:
                    ord.itm[i].price=240;
                    break;
                case 16:
                    ord.itm[i].price=450;
                    break;
                case 17:
                    ord.itm[i].price=350;
                    break;
                case 18:
                    ord.itm[i].price=400;
                    break;
                case 19:
                    ord.itm[i].price=450;
                    break;
                case 21:
                    ord.itm[i].price=100;
                    break;
                case 22:
                    ord.itm[i].price=80;
                    break;
                case 23:
                    ord.itm[i].price=70;
                    break;
                case 24:
                    ord.itm[i].price=80;
                    break;
                case 25:
                    ord.itm[i].price=60;
                    break;
                case 31:
                    ord.itm[i].price=200;
                    break;
                case 32:
                    ord.itm[i].price=150;
                    break;
                case 33:
                    ord.itm[i].price=140;
                    break;

                }

                total += ord.itm[i].qty * ord.itm[i].price;

            }

            cout<<"\nDo you want to Parcel your order [Y/n]:\t";
            cin>>parcel;
            system("clear");

            BillHeader(ord.customer,ord.date);
            for(int i=0; i<ord.numOfItems; i++)
            {
                BillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
            }
            if(parcel=='Y')
            {
                net=150;

            }

            BillFooter(total,net,parcel);

            cout<<"\nDo you want to save the invoice [Y/n]:\t";
            cin>>saveBill;

            if(saveBill == 'Y')
            {
                file=fopen("RestaurantBill.dat","a+");
                fwrite(&ord,sizeof(struct orders),1,file);
                if(fwrite != 0)
                    cout<<"\nSuccessfully saved";
                else
                    cout<<"\nError saving";
                fclose(file);
            }
            break;

        case 2:
            system("clear");
            file = fopen("RestaurantBill.dat","r");
            cout<<"\n  *****Your Previous Invoices*****\n";
            while(fread(&order,sizeof(struct orders),1,file))
            {
                float tot = 0;
                float Net =0;
                char par=parcel;
                BillHeader(order.customer,order.date);
                for(int i=0; i<order.numOfItems; i++)
                {
                    BillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                    tot+=order.itm[i].qty * order.itm[i].price;
                }
                if(par=='Y')
                {
                    Net = 150;

                }
                BillFooter(tot,Net,par);
            }
            fclose(file);
            break;

        case 3:
            cout<<"Enter the name of the customer:\t";
            fgets(name,50,stdin);
            name[strlen(name)-1] = 0;
            //system("clear");
            file = fopen("RestaurantBill.dat","r");
            cout<<"\t*****Invoice of "<<name<<"*****";
            while(fread(&order,sizeof(struct orders),1,file))
            {
                float tot = 0;
                  float Net = 0;
                char par=parcel;
                if(!strcmp(order.customer,name))
                {
                    BillHeader(order.customer,order.date);
                    for(int i=0; i<order.numOfItems; i++)
                    {
                        BillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                        tot+=order.itm[i].qty * order.itm[i].price;
                    }
                    if(par=='Y')
                    {
                        Net = 150;
                    }
                    BillFooter(tot,Net,par);
                    invoiceFound = 1;
                }

            }
            if(!invoiceFound)
            {
                cout<<"Sorry the invoice for "<<name<<" doesnot exists";
            }
            fclose(file);
            break;

        case 4:
            cout<<"\n\t\t Bye Bye :)\n\n";
            exit(0);
            break;

        default:
            cout<<"Sorry invalid option";
            break;
        }
        cout<<"\nDo you want to perform another operation?[Y/n]:\t";
        cin>>count;

    }
    cout<<"\n\t\t Bye Bye :)\n\n";
    cout<<"\n\n";

    return 0;

}

