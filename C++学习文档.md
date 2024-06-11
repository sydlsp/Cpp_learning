## C++学习文档



### chapter3



#### 3.1



##### 3.1.4 典型的整数溢出行为

典型的整数溢出行为可以用里程表来理解

![image-20240326090759665](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240326090759665.png)

##### 3.1.6 整型字面值

在c++的表示中，如果数字以0开头，那么表示这是一个八进制数字，如果数字以0x或者0X开头，那么表示这个数字是十六进制数字

通常情况下，cout输出是按照十进制输出的（不管这个数字是什么进制表示，都会转化为十进制的值）

修改cout输出进制的方式：程序3.4

```c++
// hexoct2.cpp -- display values in hex and octal
#include <iostream>
using namespace std;
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42; 
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!"  << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    //cout << hex不会输出任何东西，只是将cout的输出模式修改为十六进制而已
    cout << hex;      // manipulator for changing number base
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    //同理，将输出模式修改为八进制
    cout << oct;      // manipulator for changing number base
    cout << "inseam = " << inseam << " (octal for 42)" << endl;
    return 0; 
}
```



##### 3.1.8 转义字符

转义字符的简单示例：程序3.7，有趣的退格键

```c++
// bondini.cpp -- using escape sequences
#include <iostream>
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
    // cin.get();
    // cin.get();
    return 0; 
}
```



#### 3.2 Const限定符

关于Const限定符，其实重要的是理解一下Const和#define之间的关系，可以明确的是使用Const是要优于使用#define，原因主要有一下三点：

* Const可以明确的指定类型
* Const可以将定义限制在特定的作用域中
* Const可以用于更复杂的类型



#### 3.4 C++中的运算符

在c++中基本运算的运算符的理解是不难的，值得注意的是基本运算符的运算结果（**结果并不一定准确**），比方说在下面的例子中，执行完代码后会发现所要的结果与我们想要的不一致，这是因为**在c++中float类型只保证前6位或7位的精确度**，即当四舍五入到6位或者7位后结果是准确的，要更高的精确度需要使用double或者long double。

```c++
// arith.cpp -- some C++ arithmetic
#include <iostream>
int main()
{
    using namespace std;
    float hats, heads;
    hats=50.25;
    heads=11.17;
    //设置输出固定位数
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;
    // cin.get();
    // cin.get();
    return 0;
}
```

##### 3.4.5 C++中的auto声明

编译器可以通过变量的初始值推断变量的类型



### chapter4  复合类型



#### 4.1 数组

##### 4.1.3  C++11中数组初始化的方式

想要把数组中所有元素都初始化为0，可采用下列方式

```c++
int counts[10]={}
float balance[100]={}
```

同时，在数组初始化的时候不允许数组中数据的“类型转换”（不可以在float数组中初始化一个int型数）



#### 4.2 字符串

在C风格的字符串中，最显著的特征就是其是以**空字符**来结尾的，这个空字符一般是隐式的，但千万不要忘记它的存在！

参见m_4.2文件

```c++
char cat[3]="cat"//会报错，应该至少使用char[4]="cat"
```

##### 4.2.2 在数组中使用字符串

其实在这里关注一点就可以了，用strlen()统计的是字符串字符的个数（不包括空字符），而sizeof统计的是完整数组的长度

详情可见4.2_strings.cpp



##### 4.2.3 字符串的输入

cin使用空格、制表符以及换行符来确定字符串结尾的位置，这意味着用cin是没有办法输入”tom and jerry“这样的字符串的

参见4.3_instr1.cpp



##### 4.2.4 每次读取一行字符串输入

为了解决上述问题，需要用新的输入方式**cin.getline(数组名，最大读取字符数)**

cin.getline会自动将字符串中的回车键转化为空字符



##### 4.2.5 混合输入字符串和数字

在混合使用字符串和数字的时候可能会出现无法输入字符串的问题

产生问题的原因在于在输入完数字后会输入回车，程序如果不把这个回车吃掉这个回车就会被当成字符串，产生无法输入字符串的问题

参见4.6_numstr.cpp



#### 4.3 string类简介

类的程序设计可以让string自动处理字符串的大小，让字符串的相关操作更加灵活



#### 4.4 结构简介

结构其实就是定义新的数据结构，这样的数据结构和int，float等是一样的



关于结构的声明位置。结构的声明位置相对于函数来讲有两种选择：

* 在函数内，只能被声明所属的函数使用
* 在函数外，可以被其他函数使用

c++不提倡使用外部变量，但提倡使用外部结构声明



##### 4.4.4 结构的其他属性

C++使用户定义的类型与内置的类型尽可能的相似，因此结构之间是可以相互赋值的（**即便结构成员有数组也是可以赋值的**）

关于这点为什么可以参考：[数组不可直接赋值，为何结构体中的数组却可以？讲明白了！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/528459411)（这个还没仔细看过，可以作为参考）

同样的，与内置类型相似，结构也有对应的结构数组。



#### 4.5 共用体

共用体可以存储不同的数据类型，但同时只能存储其中的一种类型。

这句话有点拗口，可以这样理解：共用体类似于一个“化身”，每次只能化身为其内部定义的其中一种数据类型

共用体通常是为了节省内存，此外共用体常用于操作系统数据结构或硬件数据结构



#### 4.6 枚举

enum工具提供了另一种创建符号常量的方式

```c++
enum spectrum {red,orange,yellow,green,violet};
```

枚举的简单示例：

```c++
int main()
{

 enum spectrum {red,orange,yellow,green,violet};

 spectrum band;
 band=red;
 cout<<band;
 cout<<yellow;
}

输出结果为：0
输出结果为: 2
```



其中：

* enum 表示这是一个枚举，作用和struct是一样的
* spectrum是自定义数据类型的名称
* red,orange等作为符号常量，对应整数值0,1,2……这些常量被称之为枚举量

枚举其实是符号常量对应到枚举量的过程

对于枚举，只定义了赋值运算符，没有定义枚举算数运算，也就是说虽然在上述代码中band输出是0，但不能执行band++等操作（因为band是spectrum类型，不是int等类型，枚举没有定义算数运算！）



##### 4.6.1 设置枚举的值

```c++
enum bits{one=1,two=2,four=4,eight=8};
```

在枚举中指定的值必须是整数，同时可以只显式地定义其中一些枚举量的值，也可以创建多个值相同的枚举量



#### 4.7 指针和自由存储空间

在计算机存储数据的时候要想明白三个问题：

* 信息存储在何处
* 存储的值是什么
* 存储信息的类型是什么

在C++中可以使用地址运算符（&）来获得一个变量的地址，在使用常规变量的时候值是指定的量，地址是派生量，而使用指针变量的时候，地址是指定的量，值是派生的量，将（*）运算符运用于指针变量可以获取该地址处的值

```c++
int main()
{
    int updates=6;
    int *p_updates; //声明指向int的指针

    p_updates=&updates; //将update的地址给p_updates

    cout<<p_updates<<endl; //输出地址
    cout<<*p_updates; //用*运算符来取地址中的值
}
```

值与地址是一个硬币的正反面

##### 指针与C++基本原理

在更深入的理解指针前，再看一下面向对象编程与过程性编程的区别，OOP强调的是在运行阶段进行决策（运行阶段确定数组的大小），过程性编程更强调在编译阶段进行决策（数组的大小是固定的）



##### 4.7.1 声明和初始化指针

对于每一个指针变量名都需要使用一个*，也就是说

```c++
int* p1,p2;
```

声明了一个指针p1以及一个int变量p2



##### 4.7.2 指针的危险

关于指针的使用，一定要在对指针应用（*）运算符前将指针初始化为一个确定的、适当的地址！



##### 4.7.4 使用new来分配内存

指针的真正用武之地在于：在运行阶段分配未命名的内存以存储值。在这种情况下，只能通过指针来访问内存。

简单示例：

```c++
int *pn=new int;
```

 

为一个数据对象（可以是结构，也可以是基本类型）获得并指定分配内存的通用格式如下：

```c++
typeName * pointer_name = new typeName
```



**地址本身只指出了对象存储地址的开始，并没有指出其类型（使用的字节数）。**

C++提供了检测并处理内存分配失败的工具。



##### 4.7.5 使用delete来释放内存

```c++
delete ps;
```

ps是指针，使用delete之后会释放ps所指向的内存，**但不会删除ps本身**，可以将ps重新指向新的内存块。关于**new和delete要配对使用**，否则会发生内存泄漏。

注意：不要尝试释放已经释放的内存块，C++标准指出，这样做的结果将是不确定的，这意味着什么情况都有可能发生 

注意：delete只能释放new分配的内存（进一步理解为什么new和delete要成对使用），对空指针使用delete是安全的

对于new和delete更精准的理解是：delete用于new分配的内存，不意味着要用于new的指针，下面是这句话的代码翻译：

```c++
int *ps=new int;
int *pq=ps;
delete pq;
```

但一般来言，不要创建两个指向同一个内存块的指针



##### 4.7.6 使用new来创建动态数组

new真正的用武之地在于大型数据（数组、字符串和结构等）



###### 使用new创建动态数组

在C++中创建动态数组只需要将数组的元素类型和元素数目告诉new即可，创建一个包含10个元素的int数组可以：

```c++
int *psome=new int [10];

//在这里10可以替换成变量
//int size=100;
//int *psome=new int [size];
```

new返回第一个元素的地址

当程序使用完new分配的内存块时，也应使用delete来释放内存：

```c++
delete [] psome;
```

在使用new和delete的时候有个小细节：

new有[]的时候，delete时就要有[]，没有的时候delete也不要有



为数组分配内存的通用格式如下：

```c++
type_name *point_name = new type_name [num_elements];
```



###### 使用动态数组

关于动态数组的使用，其实只要记住数组名是数组第一个元素的地址就很好理解了，也就是**把指针名当数组名**。



#### 4.8 指针、数组和指针算数

关于指针算数部分，要理解好指针的加法运算



##### 4.8.3.指针和字符串

```c++
char flower[10]="rose";
cout<<flower<<"s are red\n";
```

在这里，flower是字符串第一个元素的地址，cout接受这个地址后输出地址后的内存的内容，直到遇见空字符为止。有趣的是"s are red\n"是什么？

在C++中，用引号引起的字符串像数组名一样，也是第一个元素的地址，也就是说，上述代码不会将整个字符串发送给cout，只是发送该字符串的地址



一般来言，给cout提供一个指针，它将打印地址。但如果指针的类型是（char *）那么cout将输出其指向字符串的内容，如果要显示字符串的地址，那么就要将char *（字符串指针类型）强制转化为其他指针类型，如（int *）



##### 4.8.4 使用new创建动态结构

由于类和结构非常相似，本节介绍的内容也适用于类



先复习一下使用new的好处，使用new可以在运行时分配所需的空间而不是在编译的时候就分配好

将new用于结构由两部分组成：

* 创建结构
* 访问成员

创建结构的方式和创建内置数据类型的语法是相同的：

```c++
inflatable *ps =new inflatable;
```



下面需要关注的问题是如何访问结构成员：

在创建动态结构的时候，不能将成员运算符（.）用于结构名，原因是用上述创建动态结构的方式创建出的结构是没有名字的，只知道它的地址。C++为这种情况提供了**箭头成员运算符**（->）。就像成员运算符可用于结构名一样，箭头成员运算符可以用于指向结构的指针。

```c++
struct things
{
    /* data */
    int good;
    float price;
};

int main()
{
    //创建有名字的结构
    things a={100,125.0};

    //用new创建动态结构
    things *b=new things;
    b->good=50;
    b->price=200.0;

    cout<<a.good;
    cout<<b->price;
}
```



##### 4.8.5 自动存储、静态存储和动态存储

根据分配内存的方法，C++有三种管理数据内存的方式：

* 自动存储：

在函数内部定义的常规变量（值是指定量，地址是派生量）使用自动存储空间。在其所属的函数被调用时自动产生，在函数结束时消亡。自动存储是局部变量，其作用域为包含它的代码块，**自动变量通常存储在栈中**。

* 静态存储：

静态存储是在整个程序执行期间都存在的存储方式，让变量成为静态的方式有两种：

1. 在函数外定义
2. 在声明变量的时候使用关键词static

* 动态存储：

new和delete运算符提供了比自动变量和静态变量更灵活的方式。它们管理了一个内存池，在C++中被称为自由存储空间或者是堆。new和delete的引入可以让使用者在一个函数内分配内存，在另一个函数中释放它。这样，数据的生命周期不完全受程序或函数的生存时间控制。程序员对如何使用内存有着更大的控制权，但内存管理也变得更复杂了。

###### 目前对delete的理解：

如存在两个指针ps，pn（ps和pn的类型相同）指向同一个内存地址，delete ps并不是解除ps和地址的绑定关系，而pn对地址的绑定关系还在（地址还是不自由的，还可以被指针操作）。delete ps应该是将ps指向的地址内存释放掉，也就是说这块地址现在完全自由了（其他指针也操作不了这块地址），不管有没有其他指针指向这块地址。



#### 4.9 类型组合

在本节中，指出了在使用类型组合的时候可能会出现声明错误（如二级指针等很容易出现声明错误），这个时候可以选择用**auto**来声明。在之前编译器利用它推断的类型来指明声明错误，现在auto借用了这种推断能力来自动推理类型。



#### 4.10 数组的替代品

模板类vector和array是数组的替代品



##### 4.10.1 模板类vector

模板类vector类似于string类，其也是一种动态数组，可以在运行阶段设置vector的长度。vector使用new和delete来管理内存，但这种工作是自动完成的。

在使用vector的时候必须要包含头文件vector。其次，vector包含在名称空间std中。第三，模板使用不同的语法来指出其存储的数据类型。第四，vector类使用不同的语法来指定元素数。

声明名称为vt的包含e_elem个类型为typeName的vector对象语法为

```c++
vector<typeName> vt(n_elem)
```

其中，n_elem可以是整型常量也可以是整型变量



##### 4.10.2 模板类array

vector类的功能比数组强大，但是其代价是付出的效率稍低。为了兼顾数组的效率和vector的安全性，C++11提供了新的模板类array，在使用array的时候需要包含头文件array，array在使用的时候与vector稍有不同：

```c++
array<int,5> ai;
```

声明名称为arr,包含n_elem个类型是typeName元素array的一般语法：

```c++
array<typeName,n_elem> arr;
```



##### 4.10.3 比较数组、vector对象和array对象 

由于vector是动态的，所以其存储的区域位于堆中，而数组和array是静态的，所以其存放区域在栈中。

array可以将一个对象复制给另外一个对象，但对于数组，必须逐元素复制数据。

使用array和vector可以降低超界错误的概率。注意:不是完全能够避免。



### 第五章 循环和关系表达式



本章大多数内容在C++中已经涉及到了，下面的笔记中补充一些之前未掌握的细节



#### 5.1  for循环



##### 5.1.1 for循环的组成部分



表达式的值，在C++中赋值表达式的值被定义为左侧成员的值

```c++
x=20; //该表达式的值是20

maids=(cook=4)+3; //该表达式的值是7

// 注意：在这里对表达式和语句没有完全区分，但一定要清楚每个表达式都有值，并不是每个语句都有值
```

在C++中表达式是值或值与运算符的组合，每个表达式都有值。



逗号运算符：

在所有运算符中，逗号运算符的优先级是最低的，且逗号运算符的值被定义为第二部分的值

```c++
cats=17,224; //首先将17赋值给cats，然后整体表达式的值被设置为224
```



字符变量的进一步理解：

char类型实际上是整型，因此可以直接对char类型使用递增运算符和递减运算符

```c++
char a='a';
cout<<++a;
```



#### 5.2 while循环



###### 类型别名

在C++中为类型建立别名的方式有两种：

* ```c++
  #define BYTE char; //将BYTE作为char的别名
  ```

* ```c++
  // 使用关键词typedef来创建别名
  typedef typeName aliasName; // 将aliasName作为typeName的别名
  ```

使用typedef可以处理更复杂的类型别名，使用typedef是一种更加的选择，有时也是唯一的选择。

```c++
typedef int* int_pont;
int main()
{
    int_pont a=new int,b=new int;
    int c=100;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

}
```

这样的话就创建了ab两个指向int的指针

注意：typedef不会创建新类型，只是为已有的类型建立一个新名称。



#### 5.3 do while循环

do while循环中循环体至少会执行一次



#### 5.4 基于范围的for循环（C++11）

在C++11中，新增了基于范围的for循环，这样简化了对数组（或容器类，如vector和array每个元素执行相同的操作）:

```c++
double prices[5]={1,2,3,4,5};
for (double x:prices)
{
     cout<<x<<endl;
}
```

如果要修改数组内的元素，需要使用不同的循环变量语法:

```c++
double prices[5]={1,2,3,4,5};
for (double &x:prices)
{
     x=x*0.8;
}
```



#### 5.5 循环和文本输入



##### 5.5.2 读取所有字符的方法

这里说的所有的字符包括空格等

```c++
char ch;
cin.get(ch);
```



常见的输入终止符是EOF，在windows系统中用control+Z来模拟EOF

下面是一直读取字符一直到遇到EOF为止的示例：

```c++
char ch;

    while (cin.get(ch))
    {
        // cin.get(ch)的返回值是cin
        // 当读取失败的时候：包括但不限于读到EOF（还可能是磁盘故障等） cin的值为false
        cout<<ch<<endl;
    }
```



#### 5.6 嵌套循环和二维数组

在C++中没有提供二维数组类型，但可以采用类似于下面的方式创建二维数组

```c++
int maxtemps[4][5]; // 创建了一个4行5列的二维数组
```

关于二维数组，要想明白其本质是数组的数组。明白了这一点就可以理解maxtemps[0]其实是一个地址

```c++
#include <iostream>
#include <cxxabi.h>
using namespace std;
int main()
{
    int temp[4][5];
    
    cout<<temp[0]<<endl;
    cout<<abi::__cxa_demangle(typeid(temp[0]).name(),0,0,0 )<<endl;
}

结果为：
0x62fdd0
int [5]
```



### 第六章  分支语句和逻辑运算符



#### 6.2  逻辑表达式



##### 6.2.5 逻辑运算符细节

C++中逻辑OR和逻辑AND运算符的优先级都低于关系运算符，另一方面！运算符的优先级要高于所有的关系运算符和算数运算符。

在逻辑AND和逻辑OR运算符中，AND运算符的优先级要高于OR，也就是说

```c++
age>30 && age<45 || weight>300

被解释为：
(age>30 && age<45) || weight>300
```



在C++中，&& 运算符可以写作and，||运算符可以写作or，！运算符可以写作not，这是等价的



#### 6.3  字符库函数cctype

C++从C语言中继承了一个与字符相关的软件包，可以简化确定字符是否为大小写、数字、标点符号等工作，这些函数的原型在cctype中定义。有检测是否为字母字符的isalpha()，是否为数字字符的isdigts()，是否为标点符号的ispunct()等函数构成。更详细的说明请参考表6.4中内容。



#### 6.5  switch语句

在C++中switch语句就像是一个指路牌，告诉计算机接下来应执行哪一行代码。执行switch语句的时候，程序将跳到使用integer-expression值标记的那一行。故名思义integer-expression必须是一个结果为整数值的表达式，最常见的标签是int和char常量，在之前我们了解了枚举，integer-expression也可以是枚举量。



##### 6.5.1  将枚举量用作标签

通常cin无法识别枚举标签，当switch语句将int值和枚举标签进行比较时，会将枚举量提升为int。



#### 6.8  简单的文件输入/输出



##### 6.8.2  写入到文本文件中

文件输出和cout输出到控制台输出极为相似

* 必须包含头文件fstream
* 头文件fstream定义了一个用于处理输出的ofstream类
* 需要声明一个或多个ofstream变量
* 必须指明名称空间std
* 需要将ofstream对象和文件关联起来，其中一种关联的方法是使用open
* 在使用完文件后用close()方法将其关闭
* 可结合使用ofstream对象和运算符<<来输出各种类型的数据

下面是要求用户输入信息，将信息显示到屏幕上，再将信息写入到文件中的示例代码

```c++
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile; //实例化一个用于输出的类outFile
    outFile.open("carinfo.txt"); //将输出类和文件绑定起来

    cout<<"Enter the make and model of automobile:";
    cin.getline(automobile,50);

    cout<<"Enter the model year:";
    cin>>year;

    cout<<"Enter the original asking price:";
    cin>>a_price;

    d_price=0.913*a_price;

    // 输出到控制台上

    cout<<fixed;
    cout.precision(2); // 两者连用控制小数位数
    cout.setf(ios_base::showpoint);
    cout<<"Make and model:"<<automobile<<endl;
    cout<<"Year:"<<year<<endl;
    cout<<"Was asking $"<<a_price<<endl;
    cout<<"Now asking $"<<d_price<<endl;

    // 输出到文件中
    outFile<<fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile<<"Make and model:"<<automobile<<endl;
    outFile<<"Year:"<<year<<endl;
    outFile<<"Was asking $"<<a_price<<endl;
    outFile<<"Now asking $"<<d_price<<endl;

    outFile.close();
    return 0;

}
```



简单来说将文件输出的主要步骤如下：

1. 实例化ofstream对象
2. 将ofstream对象和一个文件关联起来（常见的方式是open）
3. 像使用cout对象那样使用ofstream对象



##### 6.8.3 读取文本文件

在上个小节中我们已经初步掌握了怎么写入到文本文件中，读取文本文件的操作和写文本文件的操作大致类似：

* 必须包含头文件ifstream
* 实例化ifstream类的对象
* 将ifstream对象和文件关联起来，常用的方式是使用open
* 像使用cin一样使用ifstream对象



### 第七章  函数——C++的编程模块



#### 7.1  复习函数的基本知识

要使用C++的函数，必须完成如下的工作：

* 提供函数定义
* 提供函数原型（可以理解为函数头）
* 调用函数



##### 7.1.1  定义函数

对于有返回值的函数必须使用返回语句，C++对于返回值有一定的限制：**不能是数组**，但可以是其他任何类型——整数、浮点数、指针甚至可以是结构和对象。但有趣的是，虽然C++函数不能直接返回数组，但是**可以将数组作为结构和对象的组成部分来返回**。



##### 7.1.2  函数原型和函数调用

函数调用常常隐藏在include文件中，所以可能对函数原型并不是特别的熟悉，关于函数原型，可以从以下几个方面来理解：



1. 为什么要使用函数原型：

原型描述了函数到编译器的接口，将返回类型以及参数的类型和数量告诉编译器



2. 函数原型的语法：

函数原型是一条语句，最简单的方式就是复制函数头并在结尾添加分号。

但是，函数类型不要求提供变量名，只需要有类型列表就足够了。同时函数原型中的变量名相当于占位符，**不必与函数定义中的变量名相同**。



3. 函数原型的功能

函数原型可以帮助编译器完成许多工作，其可以确保：

* 编译器正确处理返回值
* 编译器检查参数的数目和类型是否正确



#### 7.2  函数参数和按值传递

C++通常按值传递参数，这意味着将数值参数传递给函数，函数将其值赋值给一个新的变量。

```c++
double volume=cube(side);

double cube(double x)
```

这意味着被调用时，函数将创建一个名为x的double变量，然后将side的值赋给x，这样cube中执行的操作便不会影响到main()中的数据。像这样，用于接收传递值的变量被称为**形参**，传递给函数的值被称为**实参**。C++标准用参数（argument表示实参）用（parameter）表示形参。



在函数中声明的变量（包括参数）是该函数私有的，函数被调用时被分配内存，在函数结束时将被释放，这样的变量也被称为自动变量。



其实这样理解的话：**形参的作用其实是变量声明，将一部分需要接收外部数据的变量声明在函数头中**



##### 7.2.1  多个参数

函数可以有多个参数，在定义和调用参数的时候只需要将这些参数分开即可。



#### 7.3  函数和数组

到现在为止函数的示例都很简单，参数和返回值的类型都是基本类型，但是函数是处理更复杂类型（数组和结构）的关键。

```C++
int sum_arr(int arr[],int n) // arr=array name,n=size
```

方括号指出arr是一个数组，但实际情况是**arr**不是一个数组，而**是一个指针**。但在编写函数的其他部分的时候可以将arr当作数组来使用。



##### 7.3.1  函数如何使用指针来处理数组

由于arr是一个指针，因此，更准确的写法是

```c++
int sum_arr(int *arr,int n)
```

借此机会再复习以下两个恒等式

```c++
arr[i]==*(arr+i);
&arr[i]==arr+i
```



##### 7.3.2  将数组作为参数意味这着什么

在之前我们已经认识到了函数的形参其实是声明变量，那么数组名作为函数的实参其实是将地址赋值给了声明出来的变量。那也就是说形参指向的和实参是同一个地址，这便是形参可以操作数组的原理。



在C++中，将数组名和指针对应，可以节省复制整个数组所需的时间和内存。但使用原始数据增加了破坏数据的风险，但是在C++中const限定符提供了解决这种问题的方法



##### 7.3.3  更多数组函数的示例

当我们选择使用数组来表示数据的时候，实际上是在进行一次设计方面的抉择，不仅仅是确定数据的存储方式，也涉及到数据要如何使用

###### 使用const保护数组

为了防止函数无意中修改数组,可在声明形参的时候使用关键字**const**

```c++
void show_array(const doulbe arr[],int n)
```

这样的声明表明arr指向的是一个常量数据,不可以使用arr来修改该数据.

注意:这样并**不意味着原始数组必须是常量**,只是意味着不能在show_array中使用arr来修改数组的内容



目前先把const理解为修饰符,而不是类型符号,也就是当不想让某个数据被修改的时候,使用**const**来进行修饰就好了.



##### 7.3.5  指针和const

将const用于指针有两种不同的方式:

1. 让指针指向一个常量对象,这样可以防止指针修改指向变量的值
2. 将指针本身声明为一个常量,这样可以防止修改指针指向的位置



声明一个指向常量的指针pt:

```c++
int age=39;
const int *pt=&age;
```

这个声明指出pt指向一个const int,因此不能使用pt来修改这个值.**pt的声明不意味着它指向的值是常量,只是意味着对于pt来言,这个值是常量**.



在C++中,禁止将const地址赋值给非const指针,这也很好理解,避免非const指针可以修改const变量的值



声明一个指向固定地址的指针:

```c++
int * const finger=&sloth; // finger只能指向sloth,但可以修改sloth的值
```



小结:

const和指针的关系很微妙,现在先这样理解一下:

const int * pt:const的是int,也就是值不可改变

int * const pt:const的是pt,也就是pt指向的地址不可改变.



#### 7.4  指针和二维数组

在进入这个部分的时候要明确两个概念：指针数组和数组指针，区分这两个概念的方法也很简单，知道*运算符的优先级要低于[]就很好理解了



指针数组

```c++
int *ar2[4];
```

由于*的优先级要低于[],所以ar2是一个数组，数组里放的是指针



数组指针

```c++
int (*ar2)[4]
```

由于用()改变了运算符的顺序，所以ar2是一个指针，这个指针指向了一个由4个int组成的数组



#### 7.5  函数和C风格字符串



##### 7.5.2  返回C风格字符串的函数

假设，需要编写一个返回字符串的函数。函数本身无法返回一个字符串，但是可以返回字符串的地址

```c++
#include <iostream>
using namespace std;
char * buildstr(char c,int n);

int main()
{
    int times;
    char ch;

    cout<<"Enter a character:";
    cin>>ch;
    cout<<"Enter an integer";
    cin>>times;

    char *ps=buildstr(ch,times);
    cout<<ps<<endl;
    delete []ps;
}

char * buildstr(char c,int n)
{
    char *pstr=new char[n+1];
    pstr[n]='\0';
    while(n-->0)
    {
        pstr[n]=c;
    }

    return pstr;
}
```

注意看上面的代码，变量pstr的作用域在buildstr中，因此在函数结束的时候pstr（的内存，**注意：不是字符串的内存**）被释放，由于函数返回的是pstr的值，因此程序可以用ps来访问new出来的内存。当字符串不被需要的时候，要使用delete释放其所占的内存。  



#### 7.6  函数和结构

在C++中函数可以返回结构。与数组名就是数组第一个地址**不同**的是，结构名只是结构的名称，要获取结构的地址必须使用取地址运算符&。**函数可以返回结构**。也就是说C++在处理结构的时候其实是把结构当成一个单值变量来做的。



##### 7.6.3  传递结构的地址

当结构很大的时候，传递结构的地址而不是整个结构可以节省时间和空间，在使用的时候其实和使用普通变量是一致的：

* 调用函数时传递结构地址而不是结构本身
* 将形参声明为指向结构的指针
* 由于形参是指针而不是结构，因此，应用间接成员运算符(->)而不是成员运算符



#### 7.9  递归

C++允许函数自己调用自己，这被称为递归。C++与C语言不同的是C++不允许mian函数自己调用自己。



##### 7.9.1  包含一个递归调用的递归

在写递归的时候，函数中如果没有终止递归调用的代码，那么函数将无限循环下去，所以，写递归的时候就要想好递归终止的条件是什么，下面是一个简单的递归示例：

```c++
#include <iostream>
void countdown(int n);
int main()
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
      using namespace std;
      cout<<"Counting down ..."<<n<<endl;
      if (n>0)
        countdown(n-1);
      // 终止条件
      else
         cout<<n<<":Kaboom!\n";
}
```



##### 7.9.2 包含多个递归调用的递归

二叉树的先根、中根、后跟遍历的代码其实就是典型的包含多个递归的递归



#### 7.10  函数指针

如果不提函数指针，那么对C或者C++函数的理解是不够完整的。与数据是类似的，函数也有地址。这个地址就是机器语言代码内存的开始地址。可以编写将一个函数地址作为参数的函数。**这样做可以让该函数在不同的时间使用不同的函数**。



##### 7.10.1  函数指针的基础知识

现在，先通过一个例子来理解这个过程，假设需要设计一个名为estimate()的函数来估算编写指定行数算法所需要的时间，并且希望不同的程序员都来使用这个函数，该函数允许每个程序员提供自己的算法来估算时间。这样，要完成下面的工作：

* 获取函数的地址
* 声明函数的指针
* 使用函数指针来调用函数



1. 获取函数的地址

​	获取函数的地址这件事本身非常简单，只需要使用函数名（后面不跟参数）即可，从这点上来看函数名和数组名还是有点像的

区分一下下面两行代码

```c++
process(think);
thought(think());
```

process函数可以在其内部调用think函数，但是thought函数是接受think函数的返回值



2.   声明函数指针

​	与声明指向某种数据类型的指针是类似的，在声明指向函数的指针的时候，也必须指定指针指向的函数类型，这意味着**声明应指定函数的返回类型和参数列表**。

```C++
// 有函数原型如下
double pam(int);

// 那么要声明一个指向其的指针
double (*pf)(int);// pf是一个指向拥有一个参数类型为int，返回值为double的指针
```



同样的，在理解一下*运算符的优先级：

```c++
*pf(int);// 由于*运算符的优先级低，pf首先是一个函数，只是其返回值是指针，最简单的理解就是int* sum(int *a,int *b)

(*pf)(int);// 由于*运算符被括号包裹起来了，所以pf首先是一个指针，这个指针指向的是一个拥有int型参数的函数
```



在正确声明函数以及函数指针之后，就可以将函数地址赋给函数指针了

```c++
pf=pam;
```



注意：

pam的特征标（参数列表）和返回值必须与pf相同，如果不相同，编译器将拒绝这种赋值。



3.   使用指针来调用函数

​	之前我们在理解的时候，说函数名和指针名是有点像的，那么在使用的时候，可以直接使用指针名来使用函数，如下所示：

```c++
double pam(int);

double (*pf)(int);
pf=pam;

double x=pam(4);

double y=(*pf)(5);// 这中方式给出了强有力的提示，我正在使用函数指针！

double z=pf(6);
```

上面的代码都是正确的，但关于为什么(*pf)和pf是等价的，不同的人有不同的理解，其实有历史与逻辑的问题，这里知道它们是等价的就好了。



##### 7.10.2  函数指针示例

```c++
#include <iostream>

double betsy(int);
double pam(int);

// 定义一个接受函数指针的函数
void estimate(int lines,double (*pf)(int));

int main()
{
    using namespace std;

    int code;

    cout<<"How many lines of code do you need?"<<endl;

    cin>>code;

    cout<<"Here is Betsy's estimate:"<<endl;
    // 函数名就是函数的地址
    estimate(code,betsy);

    cout<<"Here is Pam's estimate:"<<endl;
    estimate(code,pam);
}

double betsy(int lns)
{
    return 0.05*lns;
}

double pam(int lns)
{
     return 0.03*lns+0.004*lns*lns;
}

void estimate(int lines,double (*pf)(int))
{
    using namespace std;
    cout<<lines<<"lines will take"<<endl;
    cout<<pf(lines)<<"hour(s) will take"<<endl;
    
    // cout<<(*pf)(lines)<<"Hour(s) will take"<<endl; 同样可以
}
```



关于函数指针的用法其实还有不少，但作为了解先了解这么多，等以后用到的时候再查找和学习。



##### 7.10.4  使用typedef进行简化

除了auto之外，C++还提供了其他简化声明的工具，关键词**typedef**让程序员可以创建类型的别名。

使用typedef可以减少输入量，让程序员在写代码的时候少犯错。



### 第八章  函数探幽



#### 8.1  内联函数

内联函数是C++为了提高程序运行速度而做的一项改进，常规函数和内联函数的主要区别并不在于编写方式，而在于C++编译器如何将他们组合到程序中。

所谓内联函数是说，内联函数的编译代码与其他程序代码“内联”起来了，也就是说对于内联函数，程序无需跳到另一个位置执行代码再调回来。也正是因此，**内联函数的运行速度比常规函数要快。但代价是占用更多的内存**，如果程序在10个地方调用同一个内联函数，那么程序将包含该函数代码的10个副本。

要使用这种特性，必须采取下述措施之一：

* 在函数声明前加上关键词**inline**
* 在函数定义前加上关键词**inline**

其实占用内存增加也很好理解，没有了跳转的过程自然在编译的时候需要复制副本将两个函数的代码放到一起。



#### 8.2  引用变量

C++新增了一种复合类型——引用变量。引用是已定义变量的别名。

引用变量的主要用途是做函数的形参。通过将引用变量用作参数，函数将使用原始数据而不是其副本。这样，除了指针之外，引用也为函数处理大型结构提供了一种非常方便的途径。



##### 8.2.1 创建引用变量

在之前讲过，C和C++中用&运算符来指示变量的地址，C++给&符号赋予了另一个含义，将其用来声明引用。例如，将rodents作为rats变量的别名，可以这样做：

```c++
int rats;
int & rodents=rats;
```

其中，&不是地址运算符，而是类型标识符的一部分。就像声明中char*表示变量是一个指向char的指针一样，int & 表示变量是一个指向int的引用。

由于两者是别名的关系，所以两者的地址和值完全相同。

引用和指针实际上还是有差别的，其中一个差别是：

**引用必须在声明的时候对其初始化，而不能像指针那样先声明，再赋值**

引用更接近const指针，必须在创建时对其初始化，一旦与某个变量关联起来，就将一直效忠于它。

也就是说：

```C++
int & const=rats;
// 实际上时下面代码的伪装表示
int * const pr=&rats;
```



##### 8.2.2  将引用作为函数的参数

将引用作为函数的参数的方式被称为按引用传递。按引用传递允许被调用的函数能访问调用函数的变量，C++新增的这项特性是对C语言的超越。



##### 8.2.3  引用的属性和特别之处

其实关于引用变量，记住其是一个变量的别名就好了。

在C++11中新增了一个新的引用——右值引用，这种引用可以指向右值，使用&&来声明



##### 8.2.4  将引用用于结构

引用非常适合用于结构和类（C++用户定义的类型），引入引用的主要目的也是为了用于这些类型的，而不是基本的内置类型。

使用结构引用参数的方式和使用基本变量的引用相同，只需要在声明结构参数的时候使用引用运算符即可：

```C++
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void set_pc(free_throws & ft);
```

和指针一样，如果不希望值被修改，用const来限定一下就好

```C++
void set_pc(const free_throws & ft);
```



###### 为什么要返回引用

下面深入的讨论返回引用与传统返回机制的不同之处，看下面的代码：

```C++
double m=sqrt(16.0);
cout<<sqrt(25.0);
```

第一条语句中，值4.0被复制到一个临时的位置，然后复制给m；在第二条语句中，值5.0被复制到一个临时位置，然后传递给cout（这是理论上的描述，实际上编译器可能会省略一些步骤）

```c++
#include <iostream>
using namespace std;

struct A_struct
{
    int a;
    double b;
    char c;
};
A_struct & change_struct(A_struct & temp);


int main()
{
    A_struct stru_1,stru_2;
    stru_1={100,200.0,'a'};
    stru_2={500,1000.0,'b'};
    cout<<stru_1.a<<"   "<<stru_2.a<<endl;
    A_struct stru_3;
    stru_3=change_struct(stru_1);
    cout<<stru_1.a<<"   "<<stru_3.a;
}


A_struct & change_struct(A_struct & temp)
{
    temp.a=temp.a*5;
    return temp;
}


```

返回结构引用的简单示例，当函数返回结构的时候，**不是将结构复制到一个临时变量中再将其赋值给其他变量，而是直接将引用名绑定，这样的好处是提升了效率**。

 

###### 返回引用时要注意的问题

返回引用最重要的一点是，应避免返回函数终止时不存在的内存单元的引用，需要避免编写下面的代码：

```C++
const free_throws & clone2(free_throws & ft)
{
      free_throws newguy;
      newguy=ft;
      return newguy;
}
```

函数返回的是临时变量newguy的引用，函数运行完成后临时变量uewguy将不再存在，**要避免返回这种指向临时变量的引用，同时也要避免返回指向临时变量的指针**。



##### 8.2.5 将引用用于类对象

将类对象传递给函数的时候，C++常用的做法是使用引用。例如可以使用引用，将string类等类对象作为参数。



在这里，**还是要强调不要返回函数内声明的临时变量的引用或指针**！



##### 8.2.7 何时使用引用参数

使用引用参数的原因主要有：

* 程序员能够修改函数中的数据对象
* 传递引用而不是整个数据对象可以提高程序的运动速度



#### 8.3  默认参数

C++中引入了一个新内容——默认参数。默认参数是指当函数调用中省略实参自动使用的一个值，使用默认参数将极大提高函数的灵活性。

设置默认值必须通过函数原型，对于带参数的列表，必须从右向左添加默认值，也就是说，要对某个参数设置默认值，则必须为它右边所有的参数设置默认值：

```c++
int harpo(int n,int m=100, int j=5);
```



#### 8.4  函数重载

函数多态是C++在C语言基础上新增的功能。默认参数可以使用不同数目的参数调用同一个函数，函数多态（函数重载）可以使用多个重名的函数。C++使用上下文来确定要使用的函数重载的版本。



**函数重载的关键是函数的参数列表**——也称为函数特征标。如果两个函数的参数数目和类型相同，同时参数的排列顺序也相同，则它们的特征标相同，变量名是无关紧要的。C++允许定义名称相同的函数，条件是它们的特征标不同。



一些看起来不同的特征标是不能共存的：

```C++
double cube(double x);
double cube(double & x)
```

这会导致有：

```c++
cout<<cube(x);
```

编译器不知道使用哪一个函数。因此为了避免这种混乱，C++认为**类型引用和类型是同一种特征标**。



##### 注意：是特征标而不是函数类型使得函数可以重载

下面两个声明是互斥的

```C++
long gronk(int n,float m);
double gronk(int n,float m);
```

C++不允许以这种方式进行重载，返回类型可以不同，但特征标一定不能相同



##### 8.4.2  何时使用函数模板

虽然函数重载看起来很吸引人，但是也不要滥用。仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应采用函数重载



#### 8.5  函数模板

现在的C++编译器实现了C++新增的一项特性——函数模板。函数模板是通用的函数描述，也就是说它们**使用泛型来定义函数**，其中泛型可以用具体的类型（如int或者double等）替换。**通过将类型作为参数传递给模板**，编译器生成该类型的函数。由于模板允许以泛型（而不是具体类型）的方式编写程序，因此有时也被称为通用编程。



函数模板允许以任意类型方式来定义函数，例如可任意这样建立一个交换模板：

```C++
template <typename AnyType>

void Swap( AnyType &a , AnyType &b)
{
     AnyType temp;
     temp=a;
     a=b;
     b=temp;
}
```

第一行指出，要建立一个模板，并将类型命名为AnyType。关键字template和typename是必须的，除非可以使用关键词class来代替typename。另外，必须使用尖括号。类型名可以任意选择，这里是AnyType。为了方便，许多程序员使用简单的名称，例如T来代替。

其实：

```C++
template <typename AnyType>
template <class AnyType>
```

表示的含义是一样的，之所以有这两种形式是因为C++98之前没有关键词typename所以用的是class



要让编译器知道程序需要一个特定形式的交换参数，只需要在程序中使用函数即可。编译器将检查所使用的函数类型，下面是一个使用示例：

```C++
#include <iostream>

// 函数模板原型
template <typename T> // or class T
void Swap(T & a, T & b);

int main()
{
    using namespace std;

    int i=10,j=20;
    cout<<"i:"<<i<<"j:"<<j;

    Swap(i,j);// 生成void Swap(int &,int &)
    cout<<"i:"<<i<<"j:"<<j;

    double x=24.5,y=81.7;
    cout<<"x:"<<x<<"y:"<<y;
    Swap(x,y);
    cout<<"x:"<<x<<"y:"<<y;

}

template <typename T>
void Swap(T & a, T & b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}
```



##### 8.5.1  重载的模板

与函数重载类似，模板也是可以重载的。模板重载的要求和函数重载的要求是一样的。函数的特征标必须不同，在下面的示例中我们还将看到在模板定义中可以包含具体类型（**并不是所有的模板参数都必须是模板参数类型**）。



```c++
#include <iostream>

template <typename T> void Swap(T &a, T &b);
template <typename T> void Swap(T *a,T *b,int n);
```



##### 8.5.2  模板的局限性

模板很好用，但模板在使用的时候是有局限的

```c++
template <typename T> void f(T a,T b);
```

如果T为数组，那么a=b;这样的方式就是有问题的。



##### 8.5.3  显式具体化

假设定义了如下结构：

```C++
struct job
{
   char name[40];
   double salary;
   int floor;
}
```

假设，我希望对于job类型，该类型在执行交换的时候只交换salary和floor，而其他类型执行的是完全交换，为了让Swap模板函数在遇到job类型的时候有不同的执行过程要怎么做呢？



在C++中可以提供一个具体化的函数定义——称之为显式具体化，其中包含所需的代码。当编译器找到与函数调用匹配的具体化定义时，将使用该定义而不再寻找模板。



第三代具体化方法（ISO/ANSI C++标准）：

* 对于给定的函数名，可以有非模板函数、模板函数以及显式具体化模板函数以及它们的重载版本
* 显式具体化的原型和定义应以Template<>打头，并通过名称来指出类型
* 具体化优先于常规模板，而非模板函数优先于具体化和常规模板

下面是用于交换job结构的非模板函数、模板函数和具体化原型：

```C++
// 非模板函数定义
void Swap(job &, job &);

// 模板函数定义
template <typename T> void Swap(T &,T &);

//具体化原型
template<> void Swap<job>(job &,job &);
```

三者的顺序是非模板版本优先于显式具体化和模板版本，显式具体化优先于使用模板生成的版本

在下面的代码中，第一次调用Swap使用的是通用版本，第二次调用是哟个的是基于job类型的显式具体化版本

```C++
template<class T> void Swap(T &,T &);

// 由于Swap<job>中的job是可选的，因此下面两种函数声明是等价的
template<> void Swap<job>(job &,job &);
template<> void Swap(job &,job &);

int main()
{
    double u,v;
    
    Swap(u,v); // 使用模板函数
    
    job a,b;
    
    Swap(a,b); // 使用显式具体化函数
}
```

###### 显式具体化的使用代码

```C++
#include <iostream>

// 模板函数声明
template<class T> void Swap(T &,T &);

struct job
{
    char name[40];
    double salary;
    int floor;
};

// 显式具体化函数声明
template<> void Swap<job> (job &,job &);

void Show(job & j);

int main()
{

    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);

    int i=10,j=20;
    cout<<"i,j="<<i<<","<<j<<endl;

    // 使用通用模板
    Swap(i,j);
    cout<<"Now i,j="<<i<<","<<j<<endl;

    job sue={"Susan Yaffee",73000.60,7};
    job sidney={"Sidney Taffee",78060.72,9};

    cout<<"Before swapping"<<endl;
    Show(sue);
    Show(sidney);

    // 用显式具体化函数
    Swap(sue,sidney);
    cout<<"After swapping"<<endl;
    Show(sue);
    Show(sidney);
    return 0;
}

template<class T> void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<> void Swap<job> (job &a,job &b)
{
    double t1;
    int t2;

    t1=a.salary;
    a.salary=b.salary;
    b.salary=t1;

    t2=a.floor;
    a.floor=b.floor;
    b.floor=t2;
}

void Show(job &a)
{
    using namespace std;
    cout<<a.name<<"$"<<a.salary<<"On floor"<<a.floor<<endl;
}
```

