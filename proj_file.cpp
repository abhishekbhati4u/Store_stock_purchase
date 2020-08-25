/*This project has been prepared by Abhishek Bhati (Enrollment No. 9917103139 Batch:F5) and
Shivam Goel (Enrollment No. 9917103158 Batch:F5. It uses fractional knapsack problem algorithm and optimizes the purchase of the
items by taking the amount of values that were sold in the past and taking their average.*/

#include<bits/stdc++.h>
#include<algorithm>
#include<iomanip>

using namespace std;

struct item
{
    string name;
    int index;
    int id;
    int weight;
    int unit;
    float purchase_price;
    float selling_price;
    float profit;
    float loss;
    int amount_sold;
    int month;
    int year;
    float ValueRatio;
    int average;
    int counter;
    int tunits;
    int tweight;
};

int n;
int total_weights;
int total_units;
int units;
int weights;
vector<item> itm;

int checkinteger(int num)
{
    int d;
    if(num<0)
    {
        cout<<"\nWrong value entered. Enter again.";
        cin>>d;
        checkinteger(d);
    }
    else
    {
        return num;
    }
}

float checkfloat(float decimal)
{
    int d;
    if(decimal<0.0)
    {
        cout<<"\nWrong value entered. Enter again.";
        cin>>d;
        checkfloat(d);
    }
    else
    {
        return decimal;
    }
}

void add_records()
{
    cout<<"\nEnter the number of items that you want to enter:\n";
    cin>>n;
    int i;
    struct item obj;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter the month and the year of the sale:\n";
        cin>>obj.month>>obj.year;
        cout<<"\nEnter the name of the item:\n";
        cin>>obj.name;
        cout<<"\nEnter the id of the item:\n";
        cin>>obj.id;
        obj.id=checkinteger(obj.id);
        cout<<"\nEnter the weight (If the item is purchased in terms of the units then enter 0 for weight)\n";
        cin>>obj.weight;
        obj.weight=checkinteger(obj.weight);
        cout<<"\nEnter the units (If the item is purchased in terms of the weights then enter 0 for unit)\n";
        cin>>obj.unit;
        obj.unit=checkinteger(obj.unit);
        cout<<"\nEnter the purchasing price of the item per unit or unit weight:\n";
        cin>>obj.purchase_price;
        obj.purchase_price=checkfloat(obj.purchase_price);
        cout<<"\nEnter the selling price of the item per unit or unit weight:\n";
        cin>>obj.selling_price;
        obj.selling_price=checkfloat(obj.selling_price);
        cout<<"\nEnter the amount of the item sold during this month:\n";
        cin>>obj.amount_sold;
        if(obj.unit==0)
        {
            if(obj.amount_sold<obj.weight)
            {
                obj.loss=(obj.purchase_price*obj.weight)-(obj.selling_price*obj.amount_sold);
                obj.profit=0.0;
            }
            else
            {
                obj.profit=(obj.weight)*(obj.selling_price-obj.purchase_price);
                obj.loss=0.0;
            }
        }
        if(obj.weight==0)
        {
            if(obj.amount_sold<obj.unit)
            {
                obj.loss=(obj.purchase_price*obj.unit)-(obj.selling_price*obj.amount_sold);
                obj.profit=0.0;
            }
            else
            {
                obj.profit=(obj.unit)*(obj.selling_price-obj.purchase_price);
                obj.loss=0.0;
            }
        }
        obj.ValueRatio=obj.profit/(obj.amount_sold);
        obj.index=0;
        obj.counter=0;
        obj.average=0;
        obj.tunits=0;
        obj.weight=0;
        itm.push_back(obj);
    }

    cout<<"\nThese are the past records that are present in the records\n";
    struct item temp;
    for(i=0; i<n; i++)
    {
        temp=itm[i];
        cout<<"\nItem Name: "<<temp.name;
        cout<<"\nItem Id: "<<temp.id;
        cout<<"\nItem Weight: "<<temp.weight;
        cout<<"\nItem Unit: "<<temp.unit;
        cout<<"\nItem Purchase Month: "<<temp.month;
        cout<<"\nItem Purchase Year: "<<temp.year;
        cout<<"\nItem amount sold "<<temp.amount_sold;
        cout<<"\nItem Purchase Price: "<<temp.purchase_price;
        cout<<"\nItem Selling Price: "<<temp.selling_price;
        cout<<"\nItem Profit: "<<temp.profit;
        cout<<"\nItem Loss: "<<temp.loss;
    }
}

int main()
{
    cout<<"\nEnter the total weights and the units that your store can hold:\n";
    cin>>total_weights;
    cin>>total_units;
    char ch;
    cout<<"\nEnter the previous records for the data file";
    add_records();
    int j;
    int k;
    units=0;
    weights=0;
    struct item tmp;
    for(j=0; j<itm.size(); j++)
    {
        for(k=0; k<itm.size()-j-1; k++)
        {
            if(itm[k].ValueRatio<itm[k+1].ValueRatio)
            {
                tmp=itm[k];
                itm[k]=itm[k+1];
                itm[k+1]=itm[k];
            }
        }
    }
    cout<<"\n The value ratio of the items are as follows:";
    for(j=0; j<itm.size(); j++)
    {
        itm[j].index=j;
        cout<<itm[j].ValueRatio<<"\t";
    }
    for(j=0; j<itm.size(); j++)
    {
        tmp=itm[j];
        for(k=j; k<itm.size(); k++)
        {
            if(itm[j].id==itm[k].id)
            {
                itm[j].counter=itm[j].counter+1;
                if(itm[j].weight==0)
                {
                    itm[j].tunits+=itm[k].unit;
                    itm[j].average=itm[j].tunits/itm[j].counter;
                }
                else if(itm[j].unit==0)
                {
                    itm[j].tweight+=itm[k].weight;
                    itm[j].average=itm[j].tweight/itm[j].counter;
                }
            }
        }
    }
    vector <item> objects;
    int flag1=0;
    int flag2=0;
    while(flag1==0 && flag2==0)
    {
        for(j=0; j<itm.size(); j++)
        {
            if(itm[j].weight==0)
            {
                if(itm[j].unit<=total_units-units)
                {
                    tmp=itm[j];
                    tmp.unit=itm[j].average;
                    units+=tmp.unit;
                    if(units==total_units)
                    {
                        flag1=1;
                    }
                    tmp.profit=(itm[j].selling_price-itm[j].purchase_price)*tmp.unit;
                    objects.push_back(tmp);
                }
                else
                {
                    tmp=itm[j];
                    tmp.unit=total_units-units;
                    units+=tmp.unit;
                    if(units==total_units)
                    {
                        flag1=1;
                    }
                    tmp.profit=(itm[j].selling_price-itm[j].purchase_price)*tmp.unit;
                    objects.push_back(tmp);
                }
                if(weights==total_weights)
                {
                    flag2=1;
                }
            }
            else if(itm[j].unit==0)
            {
                if(itm[j].weight<total_weights-weights)
                {
                    tmp=itm[j];
                    tmp.weight=itm[j].average;
                    weights+=tmp.weight;
                    if(weights==total_weights)
                    {
                        flag2=1;
                    }
                    tmp.profit=(itm[j].selling_price-itm[j].purchase_price)*tmp.weight;
                    objects.push_back(tmp);
                }
                else
                {
                    tmp=itm[j];
                    tmp.weight=total_weights-weights;
                    weights+=tmp.weight;
                    if(weights==total_weights)
                    {
                        flag2=1;
                    }
                    tmp.profit=(itm[j].selling_price-itm[j].purchase_price)*tmp.weight;
                    objects.push_back(tmp);
                }
                if(units==total_units)
                {
                    flag1=1;
                }
            }
        }
    }
    int ctr;
    cout<<"\n\nThe list of items to be purchased is as follows:\n";
    int total_profit=0.0;
    for(ctr=0; ctr<objects.size(); ctr++)
    {
        cout<<"\n";
        tmp=objects[ctr];
        total_profit+=tmp.profit;
        cout<<"\nItem Name: "<<tmp.name;
        cout<<"\nItem Id: "<<tmp.id;
        cout<<"\nItem Weight: "<<tmp.weight;
        cout<<"\nItem Unit: "<<tmp.unit;
        cout<<"\nItem Purchase Month: "<<tmp.month;
        cout<<"\nItem Purchase Year: "<<tmp.year;
        cout<<"\nItem Purchase Price: "<<tmp.purchase_price;
        cout<<"\nItem Selling Price: "<<tmp.selling_price;
        cout<<"\nItem Profit: "<<tmp.profit;
        cout<<"\nItem Loss: "<<tmp.loss;
    }
    cout<<"\nThe total profit expected from such a sale is "<<total_profit;
    float fraction;
    int len;
    int c;
    for(ctr=0; ctr<objects.size(); ctr++)
    {
        cout<<"\n";
        cout<<"Item ID: "<<objects[ctr].id;
        fraction=objects[ctr].profit/total_profit;
        len=(int)(fraction*100);
        for(c=0; c<len; c++)
        {
            cout<<".";
        }
    }
    return 0;
}
