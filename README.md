# Average-Temperature-calculator
Fenwick tree (Binary index tree) data structure to perform average range queries over given stream of temperature values from a text file using file handling in C++. 

# About the project
Average Temperature calculator is console based application to perform efficient logarithmic range queries and value updates on a stream of data provided.

# Binary indexed trees aka Fenwick trees
A Fenwick tree or binary indexed tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers. When compared with a flat array of numbers, the Fenwick tree achieves a much better balance between two operations: element update and prefix sum calculation. In a flat array of n numbers, you can either store the elements, or the prefix sums. In the first case, computing prefix sums requires linear time; in the second case, updating the array elements requires linear time (in both cases, the other operation can be performed in constant time). Fenwick trees allow both operations to be performed in O(log(N)) time. This is achieved by representing the numbers as a tree, where the value of each node is the sum of the numbers in that subtree. The tree structure allows operations to be performed using only O(log(N)) node accesses.

Sum calculation till index - 
```c++
int fenwick::halfRange(int index){
// returns sum from start index to a
    int  s= 0;
    while(index>=1){
        s+= tree[index];
        index -= -index&index;
    }
    return s;
}
```

Range sum - 
```c++
int fenwick::sRange(int a, int b){
    //returns sum between a and b position in tree (inclusive)
return halfRange(b)-halfRange(a-1);
}
```


Value at index updated by d-

```c++
void fenwick::update(int pos, int value){

    int d = value-org[pos];
    org[pos] = value;
    while(pos<sot){
        tree[pos] += d;
        pos+= -pos&pos;
    }
}
```

# Usage
Run the executable in the bin folder or compile and run main.cpp. Add the stream of temperature values in file temp.txt or any other text file. Give the name of respective text file as input.

# Applications
Study of deviation of weather on certain periods of time, helpful in weather forecasting.
