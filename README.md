# Store_stock_purchase

The project entitled “Store Stock Purchase Optimizing Program” helps the owner of a small-scale local store to make efficient purchase decisions for the store stock.

This is a program based on C++ that I wrote in my 4th Semester of B.Tech. along as a project submission for Algorithms Lab.

A description of all the variables and the working of the program is as follows:

Due to the limited capacity of a store, the owner can keep only a finite number of objects for sale. He has to maximize the profit of the store by selling only these number of objects. With the help of the program, the owner can give inputs according to the requirements of the store and can get a combination of products that will give maximum profits. The main data structure used is a structure defined as item that contains all the details of an item that is sold or purchased with the name item. The structure item contains and stores the following fields:

1. String name: The name of the item
2. Int Index: used when sorting the items by the value ratio
3. Int Id: used for the identification of the item
4. Weight: If the item is purchased in terms of weights rather than units, then this will be used. Else, it will be put to zero.
5. Unit: If the item is purchased in terms of units rather than weights. Then this will be used. Else, it will be put to zero.
6. Float purchase_price: The price at which the item is purchased.
7. Float selling_price: The price at which the item is sold.
8. Int month: The month in which the past sales record was made.
9. Int year: The year in which the past sales record was made.
10. Float ValueRatio: The ratio of the profit earned to the amount of the item sold.
11. Average: The average number of items sold during a month. Calculated using all the past records entered.
12. Int counter: To keep a record of the number of records entered for the particular item during all the past entries.
13. Int tunits: The total number of units of the item sold during all the past records, used to calculate the average number of the units for that particular item having a unique ID.
14. Int tweight: The total weight of the items sold during all the past records, used to calculate the average weight sold for that particular item having a unique ID.

Along with this, some other global variables also have been declared as follows:
1. Int n: This takes the number of the items for whose the previous records are to be entered in the program.
2. Total_weights: This takes in the total amount that can be stored at maximum in the store in the form of weights.
3. Total_units: This takes in the total amount that can be stored at maximum in the store in the form of units.
4. Units: This variable is initialized to zero and is increment according to the conditions until it becomes equal to total_units.
5. Weights: This variable is also initialized to zero and is incremented according to the conditions until it becomes equal to total_weights.
6. vector<item> itm: This is a variable of structures of the type item that is used to store all the past items and the sales records.
 
Apart from these, three functions have also been declared globally;
1. int checkinteger(int num): It checks whether the number entered by the user is less than zero or not. If it is less than zero, then the number entered is required to be entered again and again using recursion until the user enters the correct number. It is used to check fields like the item id, the number of units, amount sold, etc.
2. float checkfloat(float decimal): It checks whether the decimal value entered by the user is less than zero or not. If it is less than zero, then the value is required to be entered again and again using recursion until the user enters the correct value. It is used to check fields like the selling price, the purchasing price, etc.
3. void add_records: In this function the user is required to enter the past records and then these records are stored in the vector named itm. The past records are used to calculate the average amount of items of a particular type sold in a month. The idea behind this is that a store will sell only a certain quantity of a item in a month in the area that it operates.

The rest of the operations that are used in the program are defined as follows in the main function :
At first, the function to all the past records is called and these are stored in the vector itm.
Then, using bubble sort, the vector is sorted on the basis of the ValueRatio in decreasing order.
After this, the Knapsack algorithm is applied to calculate the order and the number of items to be purchased on the basis of the maximum profit.
Two flag variables flag1 and flag2 are used to keep a count of the items and check when the purchased amount has reached the capacity. The items are first decremented on the basis of the average amount sold and if the capacity of the store falls short, then only the leftover amount is added to the list of the items to be purchased. All these details are further stored in the vector objects which is composed of structure variables of the type item.

At last, the dotted lines represent the amount contributed in the total profit by a particular item in the constructed list, provided that all the items are sold. It is calculated on the basis of the percentage and then the dots are represented on the basis of the length of the fraction calculated multiplied by 100.

The worst-case time complexity of the overall program will be O(n2) and the best-case time complexity of the overall program will be O(n).
