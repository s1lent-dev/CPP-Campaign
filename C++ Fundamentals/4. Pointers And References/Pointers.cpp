#include<iostream>
#include<string>
using namespace std;

int add(int x,int y){
    return x+y;
}
int sub(int x,int y){
    return x-y;
}
int mul(int x,int y){
    return x*y;
}

int operate(int x,int y, int (*operation)(int,int)){
    return operation(x,y);
}

int main(){

    /*
    Major concepts regarding pointers and references -->

    1. Pointers
    2. References
    3. Types of pointers --> [Null pointers, Void pointers, Array pointers, Char pointers, Function pointers, Pointers to Pointers, Wild pointers]
    4. Dynamic memory allocation

    */

    // Pointers -->

    cout << "Printing the values after utilizing pointers" << endl;
    int a = 10;
    int *ptr = &a; // Pointers declaration / Referencing --> storing the address of a into ptr by using &(Address operator)
    int b = *ptr; // Dereferencing --> Dereferencing the address with *(Referencing/Dereferencing operator)

    cout << a << " " << ptr << " " << b << "\n" << endl;


    
    // References -->
    
    cout << "Printing the values after utilizing references" << endl;
    int c = 10;
    int &ref = c; // References declaration / Referencing --> storing the address of c into ref by using &(Address operator)
    int d = ref; // Dereferencing --> Dereferencing the address with *(Referencing/Dereferencing operator)

    cout << c << " " << &ref << " " << d << "\n" << endl;




    // Types of pointers -->

    cout << "Types of pointers" << endl;
    // 1] Null pointers --> 
    
    cout << "Printing the values after utilizing null pointers" << endl;
    int *e; // Contains garbage value
    int *f = NULL; // NULL is constant with vaue 0
    int *g = 0; // Same as above

    cout << e << " " << f << " " << g << "\n" << endl; // Prints garbage values == 0

    // 2] Void pointers -->
    
    cout << "Printing the values after utilizing void pointers" << endl;
    void *vptr;
    int h = 10;
    vptr = &h;  // Void pointers can store address of any object type
    //int i = *vptr // Error (Void pointers can't be dereferenced) 
    int i = *(int*)vptr; // you can de-reference the void pointer by typecasting it to int
    cout << vptr << " " << i << "\n" << endl;

    // 3] Array pointers -->
    
    cout << "Printing the values after utilizing array pointers" << endl;
    int arr[5] = {1,2,3,4,5};
    int *arr_ptr = arr; // Also can be declared as --> int *ptr1 = &arr[0]; // This is a pointer to the first element of the array
    int (*Ent_ptr)[5] = &arr;
    
    // Traversing array through pointers -->
    for(int i=0;i<5;i++){
        cout << *(arr_ptr+i) << " "; // Also can be declared as --> cout << *(arr+i) << " "; and cout << ptr[i] << " ";
        cout << arr_ptr[i] << " ";
        cout << *(arr+i) << " ";
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << arr << "-->" << *arr << " " << arr_ptr << "-->" << *arr_ptr << endl;

    for(int i = 0;i < 5;i++){
        cout << *(*Ent_ptr + i) << " ";
        cout << (*Ent_ptr)[i] << " ";
        cout << Ent_ptr[i] << " ";
    }
    cout << "\n " << endl;

    // 4] Char pointers -->
    
    cout << "Printing the values after utilizing char pointers" << endl;
    char ch_arr[] = "Hello";
    char *ch_ptr = ch_arr;

    cout << (void *)ch_ptr << " " << ch_ptr << "\n" << endl; // Char_ptr should have address of first character of ch_arr but it prints "Hello"
    // Because When you use cout << ch_ptr, it treats ch_ptr as a pointer to a null-terminated character array and prints the characters until it encounters the null terminator ('\0'), which marks the end of the string.
    // so by typecasting ch_ptr to void pointer then it will print the address of the first character of ch_arr
    
    // 5] Function pointers -->
    
    cout << "Printing the values after utilizing function pointers" << endl;
    int (*add_ptr) (int,int) = add;
    int (*sub_ptr) (int,int) = sub;
    int (*mul_ptr) (int,int) = mul;
    int (*operate_ptr) (int,int,int (*)(int,int)) = operate;

    cout << operate_ptr(10,20,add_ptr) << " " << operate_ptr(10,20,sub_ptr) << " " << operate_ptr(10,20,mul_ptr) << endl;
    // or
    cout << operate_ptr(10,20,add) << " " << operate_ptr(10,20,sub) << " " << operate_ptr(10,20,mul) << "\n" << endl;
    
    // 6] Pointers to pointers -->
    
    cout << "Printing the values after utilizing pointers to pointers" << endl;
    int p = 10;
    int *q = &p;
    int **r = &q;
    int ***s = &r;
    (*q)++;
    (**r)++;
    (***s) += 3;
    cout << s << " --> " << r << " --> " << q << " --> " << p << endl;
    // so here , p == *q == **r == ***s == 15
    // q == &p , *q == p // r == &q , *r == q , **r == p // s == &r , *s == r , **s == q , ***s == p
    cout << p << " " << *q << " " << **r << " " << ***s << "\n" << endl;

    // 7] Wild pointers -->
    
    cout << "Printing the values after utilizing wild pointers" << endl;
    int *wild_ptr; // The wild pointers points to the random address
    *wild_ptr = 20;

    cout << wild_ptr << " --> " << *wild_ptr << "\n" << endl;


    // Dynamic memory allocation -->
    
    cout << "Printing the values after utilizing dynamic memory allocation" << endl;
    int x = 25;
    int *DynamicPtr = new int;
    *DynamicPtr = 50;

    cout << DynamicPtr << " --> " << *DynamicPtr << endl;

    delete DynamicPtr; // Deallocating the memory and then DynamicPtr become "Dangling Pointer"

    cout << DynamicPtr << " --> " << *DynamicPtr << endl; // Dangling pointer which prints garbage value

}