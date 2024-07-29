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
*  spectrum是自定义数据类型的名称
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

默认参数的声明和定义要注意，不能简单的复制函数头

```c++
#include <iostream>
using namespace std;
void test(int a,double b=100,char c='A');

int main()
{
    test(10);
    test(20,200,'B');
}

// void test(int a,double b=100,char c='A')//这样会报重定义错误
void test(int a,double b,char c)
{
    cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
}
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



##### 8.5.5  编译器选择使用哪个函数版本



对于函数重载、函数模板、模板重载，C++需要一个定义良好的策略，来决定函数调用使用哪一个函数定义，这个过程被称为**重载解析**。

简单的讲这个过程是这样进行的：

1. 创建候选函数列表。包含与被调用函数名称相同的函数和函数模板
2. 使用候选函数列表创建可行函数列表。这些是参数数目正确的函数
3. 确定是否有最佳的可行函数



##### 8.5.6  模板函数的发展

在C++发展的早期，大多数人没有想到模板函数和模板类会这么强大和有用，下面来介绍一些相关的问题以及解决方案。

1. 什么是类型

在C++98中，编写函数模板的时候，一个问题是并非总能指导在声明中要用什么类型，下面是一个不完整的示例：

```c++
template<class T1,class T2>
void ft(T1 x,T2 y)
{
     ...
     ?type? xpy=x+y;
     ...
}

```

问题是，xpy应该是什么类型，在C++98中这个问题是无法解决的

2. 关键词decltype（C++11）

C++11中新增的关键词decltype提供了解决方案，decltype关键词可以这样使用：

```c++
int x;
decltype(x) y;// 让y和x的类型是一致的
```

那么，关于上面的代码可以这样写：

```c++
decltype(x+y) xpy;
xpy=x+y;
```



#### 8.6  本章小结

C++扩展了C语言的函数功能。通过将inline关键词用于函数定义，可以提升函数的运行速度。

引用变量是一种伪装指针，它允许为变量创建别名。

C++原型让程序员可以定义参数的默认值，值得注意的是，如果为某个参数提供默认值，则必须为右边所有参数提供默认值

函数的特征标是其参数列表，程序员可以定义两个同名的函数，只要其特征标不同，这被称为函数多态或重载

函数模板自动完成重载函数的过程



### 第九章  内存模型和名称空间



#### 9.1  单独编译

和C一样，C++允许甚至鼓励程序员将组件函数放在独立的文件中



头文件常包含的内容：

* 函数原型
* 使用#define或const定义的符号常量
* 结构声明
* 类声明
* 模板声明
* 内联函数

看一下头文件引号和<>的区别，

```C++
include "" // 编译器首先从当前工作目录或者是源代码目录开始找
include<>  // 编译器将在存储标准头文件的主机系统文件系统查找
```



头文件管理：

在同一个文件中只能将同一个头文件包含一次。这个规则要记住很容易，但在使用的过程中很可能在不知情的情况下将头文件包含多次。有一种标准的C/C++技术可以避免代码多次包含同一个头文件。它基于预处理编译指令#ifndef（if not define）。下面的代码片段意味着仅当以前没有使用预处理编译指令#define定义名称COORDINH的时候才会处理#ifndef和#endif之间的语句：

```c++
#ifndef COORDINH
...
#endif
```



关于这部分内容看一下下面图吧：

![image-20240614140206577](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240614140206577.png)

头文件，其实顾名思义就是放”头“的地方，放的是”不被编译“的代码

在使用的时候，对于函数来言其实就和file2.cpp中的一样，函数的真正实现是在file.cpp中，在file1中引入头文件之后可以使用file2中实现好的函数



这部分偏工程应用，到实际工程中再看吧



#### 9.2  存储的持续性、作用域和链接性

C++使用三种不同的方案来存储数据，这些方案的区别就在于数据保留在内存中的时间

* 自动存储持续性：在函数定义中声明的变量（包括函数参数）的存储持续性是自动的，从程序开始执行所属的函数或代码块时被创建，在执行完函数或代码块的时候被释放
* 静态存储的持续性：在函数外定义的变量和使用关键字static定义的变量存储持续性都为静态，在程序整个运行期间都将存在
* 线性存储持续性：生命周期和所属线程一样长
* 动态存储持续性：用new运算符分配的内存将一直存在，直到使用delete运算符或程序结束为止，这样的内存存储持续性为动态，有时称为自由存储或者是堆



##### 9.2.1  作用域和链接 

作用域描述了名称在多大范围内是可见的。链接性描述了如何在不同的单元间共享。链接性为外部的名称可以早文件间共享，连接性为内部的名称只能由同一个文件中的函数共享，**自动变量没有链接性**。



##### 9.2.2  自动存储的持续性

在默认情况下，在函数中声明的函数参数和变量的存储持续性为自动，作用域为局部，没有链接性。也即是说对于它们来讲——只有在定义它们的函数中才能使用它们。



如果在代码块中定义了变量，则该变量的存在时间和作用域将被限制在该代码块内。看下面的例子

```c++
int main()
{
    int a=100;

    {
        cout<<"here"<<endl;
        int b=1000;
        cout<<a<<"         "<<b<<endl;
    }
    cout<<a;
}
```

对于变量a来言，a在内部和外部代码块中都是可见的，而b只在内部代码块中可见



那么问题来了，如果内部代码块中也定义了变量a呢？在代码块内部，旧的定义暂时不可见，新定义可见。

![image-20240618162056041](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240618162056041.png)



###### 自动变量

想一想，自动变量的数目其实是随着函数的开始和结束而增减，因此程序必须在运行时对自动变量进行管理。常用的办法是留出一段内存，将其视为栈来管理变量的增减。



###### 寄存器变量

关键词register最初是由C语言引入的，它建议编译器使用CPU寄存器来存储自动变量

```c++
register int a=100;
```

这样可以提升变量的访问速度



##### 9.2.3 静态持续变量

与C语言一样，C++为静态存储持续性变量提供了三种链接性：

* 外部链接性（可以在其他文件中访问）
* 内部链接性（只能在当前文件中访问）
* 无链接性（只能在当前函数或代码块中访问）



由于静态变量在整个程序运行期间的数目是不变的，所以程序不需要特殊的装置（如栈）来管理它们。如果没有显式的初始化静态变量，编译器将把它们设置为0

下面介绍如何创建这三种静态持续变量

```c++
// 创建链接性为外部的静态持续变量，必须在代码块外面声明
int global=100;

// 创建链接性为内部的静态持续变量，必须在代码块外面声明，并且使用static限定符
static int one_file=50;

// 创建没有链接性的静态变量，必须在代码块内声明，并且使用static限定符
void  funct1(int n)
{
    static int count=0;
    int llama=0;
}
```

所有的静态变量在整个程序执行期间都是存在的。看一下没有链接性的静态变量，即使在函数func1没有执行的时候，count也留存在内存中。

静态变量的初始化

在这部分记住，所有的静态变量都被零初始化，接下来会根据代码进行相应的赋值

```c++
const double pi=4.0*atan(1.0);
```

pi首先被初始化为0，然后在函数被连接且程序执行时根据atan(1.0)的值再进行赋值



##### 9.2.4  静态持续性、外部链接性

链接性为外部的变量通常简称为外部变量，它们的存储持续性为静态，作用域为整个文件。**由于外部变量是在函数外部定义的，因此对所有函数来讲都是外部的**。外部变量也称为全局变量。

###### 单定义规则

C++有单定义规则，这个规则指出，变量只能一次定义。为了满足这种需求，C++提供了两种变量声明，一种是定义声明，这种方式为变量分配存储空间。另一种是引用声明，它不给变量分配存储空间，引用已有的变量。

**引用声明使用关键字extern，且不进行初始化**。

如果要在多个文件中使用外部变量，只需在一个文件中包含该变量的定义（单定义规则），但在使用该变量的其他所有文件中，都必须使用关键字extern来声明它。

下面是一个使用示例

```c++
// file01.cpp
extern int cats=20; // 定义，这里即使用了extern关键字也是定义声明，不是引用声明，因为初始化了
int dogs=22;
int fleas;


//file02.cpp
// 使用从file01.cpp定义的cats和dogs
extern int cats;

extern int dogs;

//由于file02.cpp文件中没有声明fleas，所以不能使用fleas变量

// file03.cpp
extern int cats;
extern int dogs;
extern int fleas;
```



###### C++的作用解析域

在下面的例子中涉及到同时编译两个C++文件，我们使用visual studio来进行同时编译。

```c++
// extern.cpp
// 和support.cpp一起编译

#include <iostream>

using namespace std;

double warming = 0.3; // 外部变量

// 函数原型
void update(double dt);
void local();

int main()
{
	cout << "Golbal warming is" << warming << " degrees." << endl;

	update(0.1);

	cout << "Golbal warming is" << warming << " degrees." << endl;

	local();

	cout << "Golbal warming is" << warming << " degrees" << endl;

}

```

```c++
// support.cpp
// 和extern.cpp一起编译
#include <iostream>

extern double warming; // 在另一个文件中使用warming
// double warming = 100; // 这样是不被允许的,重定义了
void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	//extern double warming; // 可选，写不写效果一样

	warming += dt;
	
	cout << "Updating global warming to" << warming;
	cout << " degrees." << std::endl;
}

void local()
{
	double warming = 0.8;
	cout << "local warming= " << warming << " degrees." << std::endl;

	cout << "But global warming= " << ::warming << " degrees" << std::endl;
}
```

下面对上述代码进行说明。

首先main函数和update函数都可以访问全局变量warming。

在support函数中用关键字extren重新声明外部变量warming，让文件内的函数可以使用它

看一下最值得注意的点：在local函数中定义了一个同名的局部变量warming，在没有特别强调的时候，局部变量会覆盖全局变量。在C++中，此时想使用全局变量要依赖作用域解析运算符(::)，放在变量前面的时候表示使用变量的全局版本。

##### 补充：在visual studio中同时编译多个C++文件的方式

```
g++ .\9.5_external.cpp .\9.6_support.cpp -o 9.5_9.6_output.exe
```

进入代码文件夹，执行上面的命令，其中-o前是C++文件名，-o后面是生成执行文件的名字

在生成执行文件之后，直接在命令行输入.\9.5_9.6_output.exe即可在命令行看到输入结果。



##### 9.2.5  静态持续性、内部链接性

将static限定符用于作用域为整个文件的变量时，该变量的链接性将为内部的。

看下面的例子

```c++
// file1.cpp
int errors=20;

// file2.cpp
int errors=100;
```

这样做将失败，原因是违反了单定义规则



```c++
// file1.cpp
int errors=20;

// file2.cpp
static int errors=100;
```

这样做是可以的，在file2中静态变量将隐藏外部常规变量



##### 9.2.7 说明符和限定符

下面是存储说明符：

* auto
* register
* static
* extern
* thread_local（变量的持续性和所属的线程相同）
* mutable



cv限定符

* const
* volatile

const表明内存被初始化后，程序便不能再对它进行修改

volatile表明，即使程序代码没有对内存单元进行修改，其值也可能发生变化。这听起来很奇怪，举个例子就好理解了。例如，可以将指针指向某一个硬件位置，其中包含了来自串行端口的时间或信息。在这种情况下，硬件（而不是程序）可能修改其中的内容。



###### 再谈const

在C++看来，全局const定义就像使用了static说明符一样（const全局变量的链接性是内部的）

假设将一组常量放在头文件中，并在同一个程序的多个文件中使用该头文件，那么所有的源文件都将包含如下定义：

```c++
const int fingers=10;
const char * warning="Wak!";
```

只有其链接性是内部的才不会违背单定义规则。



##### 9.2.8  函数和链接性

和C语言一样，C++不允许在一个函数中定义另外一个函数。

在默认情况下，函数的链接性是外部的，即可以在文件之间共享。如果想把函数的链接性设置为内部的，那么可以使用static将函数的链接性设置为内部的，使之只能在一个文件中使用。**必须同时在原型和函数定义中使用该关键字**。

```c++
static int private(double x);

static int private(double x)
{
    ...
}
```

在使用静态函数的文件中，静态函数将覆盖外部定义。单定义规则也适用于非内联函数，因此对于每个非内联函数，程序智能包含一个定义。



##### 9.2.10 存储方案和动态分配



###### 1.使用new运算符初始化

想要初始化动态分配的变量，在C++98中可以这样做

```c++
int *pi=new int (6); // 把6赋值给*pi
```

要初始化常规结构或数组，需要使用大括号的列表初始化，这要求编译器支持C++11

```c++
struct where {double x; double y; double z;};

where *one=new where {2.5,5.3,7.2};

int *arr=new int [4] {2,4,6,7};
```



###### 2.new失败时

new可能找不到请求的内存量，C++可能让new返回空指针，也可能引发异常std::bad_alloc



###### 3.定位new运算符

通常，new负责在堆中找到一个足以满足要求的内存块。但new运算符还有另一种变体，称为定位（placement）new运算符，可以指定要使用的位置。

要使用定位new特性，首先需要包含头文件new，其提供了这种版本new运算符的原型；然后将new运算符用于提供了所需地址的参数。除了需要指定参数之外，句法与常规new运算符相同。



关于包含了头文件new之后，常规new和定位new的区别其实是类似于重载的关系

```c++
#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;

char buffer[BUF];

int main()
{
    using namespace std;

    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:" << endl;
    pd1=new double[N]; // 使用堆
    pd2=new(buffer) double [N]; // 使用buffer数组的地址

    for (int i=0;i<N;i++)
        pd2[i]=pd1[i]=1000+20.0*i;
    
    cout<<"Memory addresses:"<<endl;
    // 这里复习一下当buffer是指向char的指针的时候，想输出其地址要加上(void *)强制转换
    cout<<"heap:"<<pd1<<"   static:"<<(void *)buffer<<endl;
    cout<<"new pd2:"<<pd2;

    for (i=0;i<N;i++)
    {
        cout<<pd1[i]<<" at "<<&pd1[i]<<"; ";
        cout<<pd2[i]<<" at "<<&pd2[i]<<endl;
    }

    cout<<"Calling new and placement new a second time:"<<endl;
    double *pd3, *pd4;
    pd3=new double[N]; // 还是使用堆,找到新的地址
    pd4=new(buffer) double[N]; // 使用buffer数组的地址，这里是覆写之前的内容了
    
    for (int i=0;i<N;i++)
        pd4[i]=pd3[i]=1000+40.0*i;
    
    cout<<"Memory contents"<<endl;
    for (i=0;i<N;i++)
    {
        cout<<pd3[i]<<" at "<<&pd3[i]<<"; ";
        cout<<pd4[i]<<" at "<<&pd4[i]<<endl;

    }


    // 释放内存
    delete [] pd1;
    delete [] pd3;
    return 0;

}
```



#### 9.3 名称空间

在C++中随着项目的增大，名称相互冲突的可能性也在增大。那么，在使用多个厂商的类库的时候，可能会导致名称冲突。



##### 9.3.1 传统的C++名称空间

先掌握一些术语

声明区域：可以在其中进行声明的区域。在函数外声明的全局变量，对这种变量，声明区域是其声明所在的文件。对于在函数中声明的变量，其声明区域为其声明所在的代码块。



潜在作用域：潜在作用域是从声明点开始，到其声明区域的结尾。

值得注意的是：变量并非在其潜在作用域内的任何位置都是可见的。例如，它可能被另一个嵌套在声明区域中声明的同名变量隐藏。变量对程序而言可见的区域被称之为**作用域**（scope）。



##### 9.3.2 新的名称空间特性

一个名称空间的名称不会与另外一个名称空间相同名称发生冲突。

下面的代码块使用了新的关键词namespace创建了两个名称空间Jack和Jill

```c++
namespace Jack
{
    double pail;
    void fetch();
    int pal;
    struct Well {...};
}

namespace Jill
{
    double bucker(double n){...};
    double fetch;
    int pal;
    struct Hill {...};
}
```

名称空间可以是全局的，也可以位于另一个名称空间之中，**但不能位于代码块中**。因此，在默认情况下，在名称空间中声明的链接性是外部的。



名称空间是开放的（open），即可以把名称加入到已有的名称空间中，下面是将goose添加到Jill空间已有的名称列表中

```c++
namespace Jill
{
  char * goose(const char *)
}
```



在Jack名称中为fetch()函数提供了原型。可以在该文件后面（或另外一个文件中）再次使用Jack名称空间来提供该函数的代码。

```c++
namespace Jack
{
   void fetch()
   {
      ...
   }
}
```

有个名称空间，就需要有一种方法访问给定名称空间中的名称。最简单的方法是用作用域解析运算符(::)，使用名称空间来限定该名称。

```c++
Jack::pail=12.34; //使用一个变量
Jill::Hill mole;  // 创建一个Hill类型的结构
Jack::fetch();   // 使用一个函数
```

###### 1.using声明和using编译指令

在实际使用过程中，人们并不希望每次使用名称的时候都对其进行限定，因此C++提供了两种机制（using声明和using编译指令）来简化对名称空间中名称的使用。

using声明使特定的标识符可用，using编译指令使整个名称空间可用。

```c++
using Jill::fetch;
```

在进行上述声明后，可以使用fetch来代替Jill::fetch()



using编译指令使所有的名称都可以用



###### 2.比较using编译指令和using声明

一般来说使用using声明要比使用using编译更安全



##### 9.3.3 名称空间示例

9.11 是头文件，包含头文件中常包含的内容：常量、结构定义和函数原型

9.12 是源代码文件，提供了头文件中函数原型对应的定义

9.13是源代码文件，使用了名称空间中声明和定义的结构和函数



#### 9.4 总结

C++鼓励程序员在开发时使用多个文件。一种有效的组织策略是：用头文件来定义用户类型，将函数定义放在一个独立的源代码文件中，将main()和其他使用这些函数的函数放在第三个文件中。



### 第十章 对象和类



面向对象编程（OOP）是一种特殊的、设计程序的概念性方法，C++通过一些特性改进了C语言，使得应用这些方法更容易，下面是最重要的OOP特性：

* 抽象
* 封装和数据隐藏
* 多态
* 继承
* 代码的可重用性



#### 10.2 抽象和类



##### 10.2.1 类型是什么

指定一个类型基本要完成三项工作：

* 决定数据对象需要的内存数量
* 决定如何解释内存中的位（long和float在内存中占用的位数相同，但将他们转化为数值的方式是不同的）
* 决定可使用数据对象执行的操作或方法



##### 10.2.2 C++中的类

类是一种将抽象转换为用户定义类型的C++工具，它将数据表示和操纵数据的方法组合成一个整洁的包。

一般来说，类规范由两个部分组成。

类声明：以数据成员的方式描述数据部分，以成员函数（被称为方法）的方式描述公有接口

类方法定义：描述如何实现类成员函数

简单理解的话：类声明提供了类的蓝图，而方法定义则提供了细节。



为开发一个类并编写一个使用它的程序，需要完成多个步骤。通常，C++的程序员将接口（类定义）放在头文件中，并将实现（类方法的代码）放在源代码文件中

```c++
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>
class Stock
{
    private:
        std::string company; // 公司名称
        long shares; // 持有的股票数量
        double share_val; // 每股的价格
        double total_val; // 总价值
        void set_tot() {total_val=shares*share_val;} // 成员函数可以就地定义，这自动成为内联函数
    
    public:
       void acquire(const std::string &co,long n,double pr);
       void buy(long num,double price); // 也可以用原型表示
       void sell(long num,double price);
       void update(double price);
       void show();
};

#endif
```



###### 1.访问控制

关键词private和public描述了对类成员的访问控制。使用类对象的程序都可以直接访问公有部分，但只能通过**公有成员函数**或友元函数来访问对象的私有成员。**公有成员函数是程序和对象私有成员的桥梁**，提供了对象和程序之间的接口。



###### 2.控制对成员的访问：公有还是私有

无论类成员是数据成员还是成员函数，都可以在类的公有部分或私有部分中声明它。但由于隐藏数据是OOP的主要目标之一，因此**数据项通常放在私有部分，组成类接口的成员函数放在公有部分**。把成员函数放在私有部分中，不能直接从程序中调用这种函数，但**公有方法可以使用它们**。通常，程序员使用私有成员函数来处理不属于公有接口的实现细节。

不必在类声明中使用关键字private，因为这是类对象的默认访问控制。

**注意：结构的默认访问控制是public**



##### 10.2.3 实现类成员函数

为类声明中的原型表示的成员函数提供代码。成员函数定义和常规函数的定义非常类似，但有两个特殊的特征：

* 定义成员函数时，使用作用域解析运算符（::）来标识函数所属的类
* 类方法可以访问类的private组件

作用域解析运算符确定了方法定义对应的类的身份。



在定义位于类声明中的函数都自动成为内联函数，如果愿意，也可以在类声明之外定义成员函数，并使其成为内联函数，只需要在实现函数定义的时候使用inline限定符即可。

```c++
inline void Stock::set_tot()
{
   ...
}
```



###### 方法使用哪一个对象

这是一个好问题，在C++中，所创建的每个新对象都有自己的存储空间，用于存储其内部变量和类成员。但同一个类的所有对象共享同一组类方法，也就是说每种方法只有一个副本。

在调用方法的时候，不同的实例其实是向代码发送不同的数据，如下图所示。

![image-20240703103901190](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240703103901190.png)

##### 10.2.4 使用类

下面是使用类的简单示例

```c++
#include <iostream>
#include "10.1_stock00.h"

int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart",20,12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15,18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400,20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000,40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000,0.125);
    fluffy_the_cat.show();
    return 0;
}
```



##### 10.2.5 修改实现

想要修改实现，其实就是保持头文件和客户文件不变，在函数的实现文件中将实现的具体细节修改后重新编译即可。



#### 10.3 类的构造和析构函数

C++的目标是让使用类对象和使用标准类型一样，到现在为止，本章提供的代码还不能像初始化int或者结构那样来初始化实例对象。

```c++
int year=1000;
struct thing
{
   char * pn;
   int m;
};
thing amabob={"weight",-23};  // 可以
Stock hot={"Apple.Inc",200,50.25}; // 这是不可以的
```

之所以不能像初始化结构那样来初始化实例其实是因为数据的访问状态是私有的，这意味着程序只能通过成员函数来访问数据成员，因此需要设计合适的成员函数才能成功的将对象初始化。

为此，C++提供了一种特殊的成员函数——类构造函数，专门用于构造新对象、将值赋给它们的数据成员。**构造函数没有返回值，没有声明类型**。



##### 10.3.1 声明和定义构造函数

现在创建Stock的构造函数，假设当前程序员只想设置company成员，而将其他值设为0，这可以使用默认参数来完成

```C++
Stock(const string &co,long n=0,double pr=0.0)
```

下面是构造函数的一种可能定义

```c++
Stock::Stock(const string &co,long n,double pr)
{
    company=co;
    if (n<0)
    {
        cout<<"Number of shares can't be negative; "
            <<company<<" shares set to 0.\n";
        shares=0;
    }

    else
        shares=n;
    
    share_val=pr;
    set_tot();
}
```

**程序在声明对象时，自动调用构造函数**。

###### 参数名和成员名

 不要将类成员名称用作构造参数的参数名，这样会导致混乱，为了避免这种混乱，可以在参数名中加上后缀



##### 10.3.2 使用构造函数

C++提供了两种使用构造函数来初始化对象的方式。

显式调用：

```c++
Stock food=Stock("World Cabbage",250,1.25);
```

隐式调用：

```c++
Stock garment("Furry Mason",50,2.5);
```

每次创建类对象（甚至使用new分配动态内存）时，C++都使用类构造函数，下面是将构造函数和new一起使用的方法：

```c++
Stock *pstock=new Stock("Electroshock Games",18,19.0);
```

**构造函数被用来创建对象，而不能通过对象来调用**。



##### 10.3.3 默认构造函数

默认构造函数是在未提供显式的初始值时，用来创建对象的构造函数。如果没有提供给任何构造函数，C++将自动提供默认构造函数，默认构造函数不做任何工作。

只有当程序员没有定义任何构造函数的时候，编译器才会提供默认构造函数。换句话来说当程序员提供了非默认构造函数

```c++
Stock(const string &co,long n,double pr)
```

但没有提供默认构造函数，下面的声明将出错：

```c++
Stock stock1;
```

**那么，我想创建一个对象，而不显式地初始化，则必须定义一个不接受任何参数的默认构造函数**。

定义默认构造函数的方式有两种：

* 一种是给已有的构造函数的所有参数提供默认值

```c++
Stock(const string &co="Error",int n=0,double pr=0.0);
```

* 另一种是通过重载来定义另外一个构造函数——一个没有参数的构造函数

```c++
Stock();
```

由于只能有一个默认的构造函数，因此不能同时采用这两种方式。实际上，通常应该初始化所有的对象，这样可以保证所有成员一开始就有已知的合理值。

下面是为Stock类定义的一个默认构造函数

```c++
Stock::Stock()
{
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
```

使用上面两种方式中任意一种方式创建默认构造函数后，便可以声明对象变量，而不对它们进行显式初始化。

```c++
Stock first; // 隐式调用
Stock first=Stock(); // 显式调用
Stock *prelief=new Stock; // 隐式调用
```

值得注意的是，**隐式的调用默认构造函数不需要使用圆括号**。

这是因为

```c++
Stock second();
```

这样的形式其实在声明一个返回Stock的函数。



##### 10.3.4 析构函数

在用构造函数创建对象后，程序负责跟踪该对象，直到其过期为止。在对象过期时，程序将自动调用一个特殊的成员函数——析构函数。析构函数完成清理工作。析构函数很有用，例如，如果构造函数使用new来分配内存，则析构函数使用deleta来释放内存。Stock的构造函数没有使用new，因此析构函数没有什么要完成的任务。



和构造函数一样，析构函数的名称也很特殊：在类名前面加上~。同样的，析构函数没有返回值和声明类型。特殊的是，析构函数没有参数，因此，析构函数的原型必须是这样的

```
~Stock();
```

由于在类对象过期时析构函数将自动被调用，因此，必须有一个析构函数。如果程序员没有提供析构函数，编译器将隐式地声明一个默认析构函数。



##### 10.3.5 改进Stock类

###### 1.头文件

````c++
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>
using namespace std;
class Stock
{  
    private:
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {total_val=share_val*shares;}
    
    public:
       Stock(); // 默认构造函数
       Stock(const string & co,long n=0,double pr=0.0); //在函数声明的时候指定默认参数
       ~Stock();
       void buy(long num,double price);
       void sell(long num,double price);
       void update(double price);
       void show();
};
#endif
````

###### 2.实现文件

```c++
#include <iostream>
#include "10.4_stock10.h"
using namespace std;
Stock::Stock() // 默认构造函数
{
    cout<<"Default constructor called\n";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

Stock::Stock(const string & co,long n,double pr) 
// 由于在类声明的时候已经说过默认参数的值了，这里就不能再指定了，否则会报重定义错误
{
    cout<<"Constructor using "<<co<<" called\n";
    company=co;
    if (n<0)
    {
        cout<<"Number of shares can't be negative; "
            <<company<<" shares set to 0.\n";
        shares=0;
    }

    else
        shares=n;
    
    share_val=pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout<<"Bye, "<<company<<"!\n";
}

// 实现类中的其他方法
void Stock::buy(long num,double price)
{
    if (num<0)
    {
        std::cout<<"Number of shares purchased can't be negative. "
                 <<"Transaction is aborted.\n";
    }

    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}

void Stock::sell(long num,double price)
{
    using std::cout;
    if (num<0)
    {
        cout<<"Number of shares sold can't be negative. "
            <<"Transaction is aborted.\n";
    }

    else if (num>shares)
    {
        cout<<"You can't sell more than you have! "
            <<"Transaction is aborted.\n";
    }

    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val=price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;
    // 设置格式为#.###
    ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec=cout.precision(3);

    cout<<"Company: "<<company
        <<" Shares: "<<shares<<'\n'
        <<" Share Price: $"<<share_val;
    // 设置格式为#.##
    cout.precision(2);
    cout<<" Total Worth: $"<<total_val<<'\n';

    // 恢复原始格式
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}
```

###### 3.客户文件

```c++
#include <iostream>
#include "10.4_stock10.h"

int main()
{
    using std::cout;
    cout<<"使用构造函数创建新的实例"<<endl;
    Stock stock1("NanoSmart",12,20.0); // 隐式调用构造函数
    stock1.show();

    Stock stock2=Stock("Boffo Objects",2,2.0); // 显式调用构造函数
    stock2.show();

    //把stock1赋值给stock2
    stock2=stock1;
    cout<<"展示stock1和stock2"<<endl;
    stock1.show();
    stock2.show();

    // 使用构造函数来重新给stock1实例化
    stock1=Stock("Nifty Foods",10,50.0);
    cout<<"新的stock1"<<endl;
    stock1.show();
    return 0;
}
```



在上面的示例中，可以看出给类对象赋值将把一个对象成员复制给另一个，原来的内容将会被覆盖。

从客户文件中，我们可以看出构造函数不仅可用于初始化新的对象，而且可以将新值赋给stock1

下面更仔细的剖析一下

```c++
stock1=Stock("Nifty Foods",10,50.0);
```

这其实是让程序创建一个新的、临时的对象，然后将内容复制到stock1来实现的，随后调用析构函数，删除临时对象，来看一下客户文件的输出

```c++
Constructor using NanoSmart called
Company: NanoSmart Shares: 12
 Share Price: $20.000 Total Worth: $240.00
Constructor using Boffo Objects called
Company: Boffo Objects Shares: 2
 Share Price: $2.000 Total Worth: $4.00
Company: NanoSmart Shares: 12
 Share Price: $20.000 Total Worth: $240.00
Company: NanoSmart Shares: 12
 Share Price: $20.000 Total Worth: $240.00
Constructor using Nifty Foods called
Bye, Nifty Foods!  // 临时对象Stock("Nifty Foods",10,50.0)析构函数的输出
Company: Nifty Foods Shares: 10
Share Price: $50.000 Total Worth: $500.00
Bye, NanoSmart! // 这里想明白了其实是stock2析构函数的输出，stock2成员的值被stock1覆盖了
Bye, Nifty Foods! // 这里是stock1析构函数的输出，stock1成员的值被临时变量覆盖了
```



###### C++的列表初始化

在C++中，也可以将列表初始化的语法用于类，只要提供与某个构造函数的参数列表相匹配的内容，并用大括号括起来就好。

```c++
Stock hot_tip={"Apple,Inc",100,45.0};
```



###### const成员函数

看下面的代码片段

```c++
const Stock land=Stock("Apple,Inc");
land.show();
```

对于当前的C++来说，编译器将拒绝第二行。这是由于show()函数无法确保调用对象不被修改。在之前，我们是通过将参数声明为const引用或者指向const的指针来解决这个问题，但这里有个语法问题：**show()方法没有任何参数**。show函数使用的对象是由方法调用隐式提供的。那么此时，需要一种新的语法来保证函数不会修改调用对象。C++的解决方法是将const关键字放在函数括号的后面。

也就是说函数的声明应该像这样

```c++
void show() const;
```

同样，函数定义的开头应该像这样

```c++
void Stock::show() const;
```

以这种方式声明和定义类的函数被称为const成员函数。只要类方法不修改调用对象，就应将其声明为const，下面我们将遵守这一规则。

也就是说const实例只能调用const成员函数



#### 10.4  this指针

对于Stock类，还有很多工作要做。到目前为止，每个成员函数都只涉及到一个对象，即调用它的对象。但有的时候方法可能涉及到两个对象，在这种情况下要使用C++的this指针。

现在我们的Stock类已经可以显示数据的，但是它缺乏分析能力。Stock类无法判别我们哪一支股票的价格更高。

那么，如何将两个要比较的对象提供给成员函数呢，例如将方法命名为topval，则stock1.topval()将访问stock1对象的数据，而stock2.topval()将访问stock2对象的数据，如果希望该方法对两个对象进行比较，则必须将第二个对象作为参数传递给它。

下面是如何将方法的答案来传回给调用程序呢？最简单的方法是让方法返回一个引用

```c++
const Stock & topval(const Stock & s) const;
```

该函数隐式的访问一个对象，而显式的访问另一个对象，并返回其中一个对象的引用，括号中的const表明函数不会修改隐式访问的对象，而括号外的const表明，该函数不会修改被隐式访问的对象

来看下面的部分实现：

```c++
const Stock & topval(const Stock & s) const
{
    if (s.val>total_val)
          return s;
    else
        return ???;
}
```

C++来解决???部分问题的方法是引入this指针，this指针用来指向用来调用成员函数的对象（其实是this作为隐藏参数传递给方法）。

###### 注意：

每个成员函数，包括构造和析构函数都有一个this指针。this指针指向调用对象，如果方法需要引用整个调用对象，则可以使用表达式*this。从理解上看this和python类中的self的作用是类似的，但要记住**this是指针**。

那上面的部分实现可以修改为：

```c++
const Stock & topval(const Stock & s) const
{
    if (s.val>total_val)
          return s;
    else
        return *this;
}
```



#### 10.5 对象数组

声明对象数组的方法和声明标准类型的数组是相同的



#### 10.6 类作用域

在之前我们介绍了全局作用域和局部作用域，在C++中引入了新的作用域：类作用域。

在类中定义的名称（如类数据成员和类成员函数名）的作用域都为整个类，作用域为整个类的名称在该类中是已知的，在类外不可知的。因此，在不同的类中使用相同的类成员名不会引起冲突。



##### 10.6.1 作用域为类的常量

有时候，使符号常量的作用域为类很有用。

但值得注意的是：**声明类只是描述了对象的形式，并没有创建对象**。因此，在创建对象前，将没有用于存储值的空间。

有两种方式可以实现这样的目标，并且效果相同

第一种是在类中声明一个枚举。在类声明中声明枚举的作用域为整个类，因此可以用枚举为整型常量提供作用域为整个类的符号名称。

```c++
class Bakery
{
   private:
         enum {Months=12};
         double costs[Months];
}
```

注意：用这种声明方式并不会创建类数据成员，也就是说，所有的对象中都**不包含枚举**。

第二种是使用关键字static

```c++
class Bakery
{
     private:
         static const int Months=12;
         double costs[Months];
}
```

这将创建一个名为Months的常量，该常量将与其他静态变量存储在一起，而不是存储在对象中。因此**只有一个Months常量**，这个常量将被所有Bakery常量共享。



##### 10.6.2 作用域内枚举

传统的枚举存在一些问题，其中之一是两个枚举定义中的枚举量可能发生冲突。假设有一个处理鸡蛋和T恤的项目，其中包含类似下面的代码：

```c++
enum egg {Small,Medium,Large,Jumbo};
enum t_shirt {Small,Medium,Large,Xlarge};
```

这将无法通过编译，因为egg和t_shirt位于相同的作用域内，它们将发生冲突，为了避免这种问题，C++11提供了一种新的枚举，其枚举的作用域为类

```c++
enum class egg {Small,Medium,Large,Jumbo};
enum class t_shirt {Small,Medium,Large,Xlarge};
```

也可以使用关键词struct来代替class，无论用哪种方式，都需要使用枚举名来线性枚举量

```c++
egg choice=egg::Large;
t_shirt Floyd=t_shirt::Large;
```



#### 10.8 总结

使用OOP方法解决编程问题的第一步是根据它与程序之间的接口来描述数据，从而指定如何使用数据。



### 第十一章 使用类

在上一章中，我们已经学习和定义使用简单的类，踏上了面向对象的编程之旅。本章将进一步探讨类的特征，重点是类的设计技术。

“轻松地使用这种语言，不要觉得必须使用所有的特性，不要在第一次学习时就试图使用所有的特性。”



#### 11.1 运算符重载

运算符重载是一种形式的C++多态，运算符重载将重载的概念拓展到运算符上，允许赋予C++运算符多种含义。实际上在C++（C）中我们已经见识到了运算符的重载，例如*运算符用于地址得到的是地址里面的值，用于两个数字的时候，得到的是它们之间的乘积。**C++根据操作数和类型来决定使用哪一种操作**。

C++允许将运算符重载扩展到用户定义的类型，例如允许使用+来将两个对象相加。利用C++的运算符重载可以隐藏内部机理，强调实质，这也是OOP的另一个目标。

要重载运算符，需要使用被称为运算符函数的特殊函数形式，运算符函数的格式如下：

```c++
operatorop (argument-list)
```

例如，operator+()是重载+运算符，operator*()是重载 * 运算符。op必须是有效的C++运算符，不能重新虚构一个新的符号。例如，不能有operator@这样的运算符，原因是C++中没有@运算符。

C++对运算符的重载做了一些限制，但了解重载的工作方式之后，这些限制就很容易理解了。下面首先通过一些示例对运算符重载进行阐述，然后再讨论这些限制。



#### 11.2  计算时间：一个运算符重载示例

```c++
class Time
{
    private:
       int hours;
       int minutes;
    

    public:
      Time();
      Time(int h,int m=0);
      void AddMin(int m);
      void AddHr(int h);
      void Reset(int h=0,int m=0);
      // 成员函数可以访问类的所有对象的私有成员，这是C++语言设计的一部分
      // 这样的设计旨在允许类的成员函数可以完全控制和操作类的内部成员状态
      Time Sum(const Time &t) const;
      void Show() const;
};
```

想将Time类转换为重载的加法运算符很容易，只需要把Sum的名称转换为operator+即可

使用

```c++
int main()
{
    using namespace std;
    Time  planning;
    Time  coding(2,40);
    Time  fixing(5,55);
    Time  total;

    cout<<"planning time=";
    planning.Show();

    cout<<"coding time=";
    coding.Show();

    cout<<"fixing time=";
    fixing.Show();
    
    // 方式一
    total=coding+fixing;
    cout<<"coding+fixing=";
    total.Show();

    Time morefixing(3,28);
    cout<<"more fixing time=";
    morefixing.Show();
    // 方式二
    total=morefixing.operator+(total);
    cout<<"morefixing.operator+(total)=";
    total.Show();

}
```

关于运算符的重载，其实就是一个有特殊名称的函数，函数名就是operator后面接着重载的运算符，剩下的按照函数理解就好。

**值得注意的是**：虽然上面的运算符重载函数看起来只有两个参数，但是t1+t2+t3+t4这样的形式仍然可以运行出正确的结果，是没有问题的。



##### 11.2.2 重载限制

多数C++的运算符都可以用这样的方式来重载。重载的运算符至少有一个类型是用户定义的类型，下面详细的介绍C++对用户定义运算符重载的限制：

1. 重载后的运算符必须有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。因此并不能将减法运算符重载为计算两个double的和。
2. 使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符重载程使用一个操作数。
3. 不能改变运算符的优先级
4. 不能创建新的运算符



##### 11.2.3 其他重载运算符

这部分可以作为练习来复习运算符重载



#### 11.3 友元

C++控制对类对象私有部分的访问。一般来讲，公有类方法提供了唯一的访问途径，但这样的方法有时太过严格，在一些情况下不适合特定的编程问题。C++提供了另一种形式的访问权限：友元。

友元有三种：

* 友元函数
* 友元类
* 友元成员函数

**通过让函数成为类的友元，可以赋予该函数与类的成员相同的访问权限**。

在介绍友元之前，介绍一下为何需要友元。在为类重载二元运算符常常需要友元，将Time对象乘以一个实数就属于这样的情况。

在前面的Time类示例中，重载乘法运算符和其他两种运算符的差别在于重载的乘法运算符使用了两种不同的类型，也就是说，加法和减法两个运算符都结合了两个Time值，而乘法运算符将一个Time和一个double值结合在一起。这限制了该运算符的使用方式。要记住的是**左侧的操作数是调用对象**，也就是说：

```c++
A=B*2.75
```

被转换为下面的函数调用

```c++
A=B.operator*(2.75)
```

解决这个问题，可以告知每个人只能用B*2.75这种格式来编写，不能写成2.75 *B，这种解决方案是服务器友好的，但用户警惕的，有没有更好的解决方式呢，答案是有的：**用非成员函数**。

大多数运算符都可以用成员或者非成员函数来重载。非成员函数不是由对象来调用的，它使用的所有值（包括对象）都是显式参数。

使用非成员函数可以按所需的顺序来获得操作数，但这样引发了一个问题：常规的非成员函数不能直接访问类的私有成员。

为了解决这个问题，引入了一个特别的非成员函数——友元函数。



##### 11.3.1 创建友元

创建友元的第一步是将其原型放到类的声明中：

```c++
friend Time operator*(double m,const Time &t);
```

这样的原型意味着如下两点：

* 虽然operator*()函数是在类中声明的，但是它不是类的成员函数，因此不能用成员运算符来调用
* 虽然operator*()不是类的成员函数，但是它与成员函数的访问权限相同

第二步是编写函数定义，由于operator*()不是类的成员函数，因此，不要使用Time::限定符，也不要在定义中使用关键词friend，定义应该如下:

```c++
Time operator*(double m,const Time &t)
{
    ...
}
```

###### 关注：友元是否有悖于OOP

友元机制的存在允许非成员函数访问私有数据，这样看起来确实在一定程度上违反了OOP数据隐藏的原则。这样的观点其实是片面的，将友元函数看成类的扩展接口的组成部分更为合理。在友元的相关操作中，**只有类声明可以决定哪一个函数是友元**，从这里理解类的声明仍然控制了哪些函数可以访问私有数据。因此，**类方法和友元函数只是表达类接口的两种不同机制**。



##### 11.3.2 常用的友元

一个很有用的特性是可以对<<运算符进行重载，使之可以与cout一起来显示对象的内容，与前面的示例相比，这种重载要更复杂一些，下面用两步来完成。假设trip是一个Time对象，为了显示Time的值，前面使用的是Show()，但是，如果能实现下面的操作会更好

```c++
cout<<trip;
```

在ostream类中已经对<<运算符做了重载，要能让cout来识别Time对象有两种办法：

1. 将新的运算符定义添加到ostream类声明中，但这样是危险且浪费时间的
2. 通过Time类声明来让Time类知道如何使用cout

###### <<的第一种重载版本

要使Time类知道使用cout，**必须使用友元函数**，其原因是，下面的语句要使用两个对象，第一个对象是（cout）

```c++
cout<<trip;
```

如果使用一个Time成员来重载<<，那么Time对象将是第一个操作数，这不符合cout的使用习惯，所以，在这里要使用友元函数。可以像下面这样重载运算符

```c++
void operator<<(ostream &os,const Time &t)
{
     os<<t.hours<<"hours"<<t.minutes<<minutes;
}
```

这样，就可以使用下面的语句了：

```c++
cout<<trip;
```

在调用的时候应该使用cout对象本身，而不是它的拷贝，因此，函数是按引用而不是按值来传递该对象。



###### <<的第二种版本

在上面介绍的实现存在这样一个问题：不允许将重新定义的<<运算符和cout一起使用，也就是说：

```c++
cout<<"Trip time:"<<trip<<endl;
```

这样的写法是不允许的，其原因是<<运算符要求左边是一个cout对象，怎么解决这个问题呢？其实很简单，让函数返回cout对象就好了

```c++
ostream & operator<<(ostream &os,const Time &t)
{
    os<<t.hours<<"hours,"<<t.minutes<<"minutes"<<endl;
    return os;
}
```

注意，按照我们之前的理解还是要返回引用，所以返回的类型为ostream &

一般来言，要重载<<运算符来显示c_name对象，可以使用友元函数

```c++
ostream & operator(ostream &os,const c_name & obj)
{
    ...
    return os;
}
```

**注意**：只有类声明中的原型才需要使用friend关键字



#### 11.5 再谈重载：一个矢量类

下面用一个例子介绍使用运算符重载和友元的类的设计——一个表示矢量的类。在这部分中将实现一个二维矢量，矢量有两种表示的方法，一种是用长度和角度（极坐标的形式），另一种是用x和y表示矢量。

同时，为了复习名称空间，将矢量类的声明放在VECTOR名称空间中。



##### 11.5.1 使用状态成员

在我们定义的Vector类中，同时存储了矢量的直角坐标和极坐标的两种表示方法，使用名为mode的成员变量来控制使用构造函数，reset方法和重载的operator<<函数使用哪种形式。在这一节的代码部分需要学到的是怎么利用好类的构造函数。



#### 11.6 类的自动转换和强制类型转换

下面来讨论另一个主题——类型转换。首先来回顾一下C++是如何来处理内置类型的转换的，如果两种类型兼容，c++自动将值转换为接收变量的值。

```c++
long count=8; // 8会被转换为long类型
```

C++语言不自动转换不兼容的类型，下面的语句是非法的

```c++
int *p =10;
```

在不考虑实际意义的情况下，可以使用强制类型转换来使上述语句合法

```c++
int *p =(int*) 10;
```

在C++中可以将类定义成与基本类型或与另一个类相关，使得从一种类型转换到另一种类型是有意义的，下面的例子将磅转化为英石的程序改写为类的形式，来说明这件事情。

看一下Stonewt类的其中一个构造函数

```c++
Stonewt::Stonewt(double lbs)
{
    stone=int(lbs)/Lbs_per_stn;
    pds_left=int(lbs)%Lbs_per_stn+lbs-int(lbs);
    pounds=lbs;
}
```

该构造函数接收一个参数，这意味着可以编写下面的代码

```c++
Stonewt myCat;
myCat=19.6;
```

程序将使用Stonewt(double)来创建一个临时的Stonewt对象，并将19.6作为初始化值。随后，采用**逐成员赋值**方式将该临时对象的内容复制到myCat中，这个过程被称为**隐式转换**。

**注意：只有接受一个参数的构造函数才能作为转换函数**

```c++
Stonewe(int stn,double lbs);//不可以
Stonewe(int stn,double lbs=10);//可以
```

将构造函数用作自动类型转换的函数看起来是一项不错的特性，但是有经验的C++程序员会发现这种特性并非总是合乎需要的，这可能会导致意外的类型转换，因此C++新增了关键字explicit，用于关闭这种特性，也就是说可以这样声明构造函数：

```c++
explicit Stonewt(double lbs);//关闭上述隐式转换
```

在添加了explicit之后，仍然会允许显示转换

```c++
myCat=(Stonewt) 19.6; //可以
```



##### 11.6.1  转换函数

在上面的例子中我们已经认识到了可以将内置类型隐式或显式的转化为自定义的类，那么可以做相反的转换吗？也就是说将Stonewt对象转化为double值？答案是可以的，但不是使用构造函数来做，而是使用**C++特殊的运算符函数——转换函数**来做。

转换函数是用户定义的强制类型转换，可以像使用强制类型转换那样来使用它们。

如何创建转换函数呢？要转换为typename类型，需要使用这种形式的转换函数 

```
operator typeName();
```

需要注意如下几点：

* 转换函数必须是**类方法**
* 转换函数不能有返回类型
* 转换函数不能有参数

例如转换为double类型的函数原型如下：

```c++
operator double();
```

double 指出了要转换成的类型，因此，不需要指定返回类型。转换函数必须是类方法意味着需要通过类对象来调用，从而告知转换函数要转换的值，因此函数不需要参数。

要将stone_wt对象转换为int类型和double类型，需要将下面的原型添加到类声明中。

```c++
//在public:中添加
operator double () const;
operator int() const;
```

函数的具体实现为：

```c++
Stonewt::operator double () const
{
       return pounds;
}

Stonewt::operator int () const
{
       return int (pounds+0.5);
}
```

注意：在C++98中关键字explicit不能限制转换函数只能用于显式转换，但c++11消除了这种限制。



##### 类的自动类型转换和强制类型转换小结：

总之，C++为类提供了下面的类型转换：

* 只有一个参数的类构造函数用于将类型与该参数相同的值转换为类类型
* 利用转换函数（一种特殊的成员运算符函数）将类对象转换为其他类型

关于类的自动类型转换和强制类型转换，现阶段先做了解，知道有这种语法现象就好。



#### 11.7 小结

本章介绍了定义和使用类的许多重要方面，其中一些内容需要随着事件经验的增加逐渐掌握它们。

一般来说，访问私有类成员的唯一方法是使用类方法。C++使用友元函数避开了这种限制。要让函数成为友元，需要在类中声明该函数，并在声明前加上关键词friend

C++扩展了对运算符的重载，允许自定义特殊的运算符函数。运算符函数既可以是类成员函数，也可以是友元函数。当运算符函数是成员函数时，第一个操作数将是调用该函数的对象。最常见的运算符重载任务之一是定义<<运算符

C++也允许指定在类和基本类型之间进行转换的方式，在11.6节对这种转换的方式做了较为详细的阐释。

本章的习题11.7复数类可以很好的复习本节的知识。



### 第十二章  类和动态内存分配

本章将介绍如何对类使用new和delete以及如何处理由于使用动态内存而引起的一些微妙问题。



#### 12.1 动态内存和类

C++可以让程序再运行时决定内存分配，而不是在编译时决定，这样可以根据程序的需要来使用内存。C++使用new和delete来动态控制内存。但在类中使用这样的运算符将导致许多新的编程问题，在这种情况下，析构函数是必不可少的。



##### 12.1.1 复习示例和静态类成员

学习到这里，已经有一阶段没有使用new和delete了，所以在这里使用一个小程序来复习它们。首先设计一个StringBad类，然后设计一个功能稍强的String类

要明确的是StringBad类是一个有缺陷的类，但是在这一过程中仍有很多细节值得我们来学习：

详细的代码可以参考12.1-12.3代码，在这里我们挑一些重点的来说：

* 首先是静态成员初始化的问题，在类的声明中是不能初始化静态成员变量的。这是由于声明只描述如何分配内存，但是并不分配内存。只有两种特殊情况除外：

​	静态数据成员是整型或者枚举型const

* 当类的成员按值传递的时候，就像我们之前理解的一样

  ```c++
  void callme (const StringBad st)
  ```

  其实是将原来的类的示例赋值给st，也就意味着会调用st的构造函数和析构函数

* 按值传递给函数其实和下面的语句是类似的

  ```c++
  StringBad sailor=sports;
  ```

  这样的语句其实等价于

  ```c++
  StringBad sailor=StringBad(sports);
  ```

  编译器自动生成了一个拷贝构造函数

  ```c++
  StringBad (const StringBad &);
  ```



##### 12.1.2 特殊成员函数

StringBad的一系列问题是由特殊成员函数引起的，这些成员函数是自动定义的，就StringBad类来言，这些函数的行为与类设计不符，具体来言C++自动提供了下面这些成员函数：

* 默认构造函数（如果没有定义构造函数）
* 默认析构函数（如果没有定义）
* 复制构造函数（如果没有定义）
* 赋值运算符（如果没有定义）
* 地址运算符（如果没有定义）

更准确的说，编译器将生成最后三个函数的定义——如果程序使用对象的方式要求这样做。StringBad中的问题是由隐式复制构造函数和隐式赋值运算符引起的。

**隐式地址运算符**返回的是调用对象的地址——即this指针的值，这与我们的初衷是一致的，这里便不详细探讨了。



###### 复制构造函数

记住：**它的名字叫复制构造函数，本质是构造函数**

复制构造函数用于将一个对象复制到新创建的对象中。也就是说，它用于初始化的过程中（包含按值传递参数），而不是常规的赋值过程中。类的复制构造函数的原型通常如下：

```c++
class_name(const Class_name &)
```

它接受一个指向对象的常量引用作为参数。对于复制构造函数，需要知道两点：何时调用有何功能。

* 何时调用复制构造函数

新建一个对象并将其初始化为同类现有对象的时候，复制构造函数都将被调用。假motto是一个StringBad对象，下面的4种声明都将调用复制构造函数：

```c++
StringBad ditto(motto);
StringBad metto=motto;
StringBad also=StringBad(motto);
StringBad *pStringBad=new StringBad(motto);
```

**每当程序生成了对象副本时，编译器都将使用复制构造函数**。具体来说：

当函数按值传递对象或函数返回对象时，都将使用复制构造函数



###### 默认的复制构造函数的功能

默认的复制构造函数将逐个复制非静态成员（成员复制也称为浅复制），复制的是成员的值。复制构造函数执行的操作可由下面的图来说明：

![image-20240722162010950](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240722162010950.png)

##### 12.1.3 回到StringBad：复制构造函数到底哪里出了问题

在书本给出的运行示例中，构造函数计数比析构函数计数少了两次，这个问题很好解决：用显式的复制构造函数来做就好

```c++
StringBad::StringBad (const StringBad &s)
{
     num_strings++;
     ...
}
```

这个问题并不是大问题，问题的关键是在代码示例中字符串出现乱码，这个问题需要仔细剖析：

其根本原因是因为隐式复制构造函数时按值进行复制的，对于我们实现的代码来讲，隐式复制构造函数的功能相当于

```c++
sailor.str=sport.str;
```

这里str成员的类型时char*，也就是说**复制的并不是字符串，而是指向一个字符串的指针**。当析构函数被调用的时候，StringBad释放str指向的内存，假设时sailor先被释放，那么再使用soprts的str成员时，由于内存已经被释放，所以会出现乱码等情况。



在明确了问题出现的原因之后，怎么解决就变得清晰了。其实就是定义一个显式的复制构造函数。在复制的时候将字符串的副本赋值给str成员，而不是仅仅复制字符串的地址。这样，每个对象都会有自己的字符串，而不是引用另一个对象的字符串，这样的操作被称为**深复制**。

必须定义复制构造函数的原因在于：一些类成员是使用new初始化的、必须指向数据的指针而不是数据本身。

**也就是说，如果类中包含了使用new初始化的指针成员，就需要定义复制构造函数以复制指向的数据而不是指针。**



##### 12.1.4 StringBad的其他问题：赋值运算符

在说赋值运算符之前，要明确一下，在初始化对象的时候不一定使用赋值运算符：

```c++
StringBad metoo=knot;
```

这个语句可能调用赋值运算符也可能不调用赋值运算符。简而言之，按照上面的形式创建新对象的时候总是会调用复制构造函数，但不一定调用赋值运算符，具体怎么做要看编译器是怎么实现的。

与复制构造函数类似，赋值运算符也是对成员进行逐个复制，明白了复制构造函数出现问题的原因也就明白了赋值运算符可能出现问题的原因。



赋值运算符处理过程中有一些特殊的细节需要注意：

* 由于目标对象可能引用了以前分配的数据，所以函数应当使用delete[]来释放这些数据
* 函数应当避免将对象赋值给自身
* 函数返回一个指向调用对象的引用



#### 12.2 改进后的新String类

在明确了了之前类实现时，存在的问题，现在，我们可以设计新的String类。

在这一部分，涉及到了静态成员函数，关于静态成员函数我们需要知道：

函数的声明必须包含关键字static，但是如果之后函数的定义是独立的，那么便不能包含关键字static

不能通过对象调用静态成员函数，如果静态成员函数是在公有声明部分，可以用类名和作用域解析运算符来调用

同时，由于静态成员函数不与特定的对象相关联，因此只能使用静态数据成员



#### 12.3 在构造函数中使用new时应注意的事项

至此，我们已经明白了在使用new初始化对象的指针成员时必须特别小心。

现在再看一下

```c++
private:
   char *str;
   int len;
```

其实在创建实例的时候都会为他们分配空间，那为什么要用new呢，其实就是为了防止野指针可能出现的一系列问题，所以要用new来分配内存。

* 如果在构造函数中使用new来初始化指针成员，则应该在析构函数中使用delete
* new和delete必须相互兼容。new对应于delete，new[]对应于delete[]
* 如果有多个构造函数，则必须使用相同的方式使用new，要么都带中括号，要么都不带。因为只有一个析构函数，所有的构造函数都必须与它兼容
* 应定义一个复制构造函数，通过深度复制将一个对象初始化为另一个对象
* 应定义一个赋值运算符，通过深度复制将一个对象复制给另一个对象（包括：检查自我赋值的情况，释放成员指针以前指向的内存，复制数据而不仅仅是数据的地址，返回一个指向调用对象的引用 四个步骤）



#### 12.4  有关返回对象的说明

当成员函数或者独立函数返回对象时，有几种返回方式可以选择：

* 指向对象的引用
* 指向对象的const引用
* const对象



##### 12.4.1  返回指向const对象的引用

使用const引用的常见原因是旨在提高效率

返回对象将调用复制构造函数，而返回引用不会



##### 12.4.3  返回对象

如果返回的对象是被调用函数中的局部变量，则不应该按引用的方式返回它。在这种情况下，应返回对象而不是引用。



#### 12.5 使用指向对象的指针

C++程序经常使用指向对象的指针，在这里我们也来看一下指向对象的指针。

* 首先，使用常规表示法来声明指向对象的指针

  ```c++
  String * glamour;
  ```

* 可以将指针初始化为指向已有的对象：

  ```c++
  String *first = & saysings[0];
  ```

* 可以使用new来初始化指针，这将创建一个新的对象

  ``` c++
  String *favourite =new String(value);
  ```

* 对类使用new将调用相应的类构造函数来初始化新创建的对象

关于指针和对象可以用下面这张图来说明

![image-20240729171305560](C:\Users\Shipu\AppData\Roaming\Typora\typora-user-images\image-20240729171305560.png)



##### 12.5.3  再谈定位new运算符

之前我们已经了解过定位new运算符了，简单的复习一下：

定位new运算符允许在指定的内存位置上构造对象，这在需要精确控制对象的存储位置时非常有用，例如在嵌入式编程或者需要手动管理内存池的高性能应用中。



12.8是使用定位new运算符的一个例子，从这个例子的运行结果我们可以看出两点：

1. 在创建第二个对象时，定位new运算符使用一个新对象覆盖了第一个对象
2. 与一般new出来的对象在delete的时候会自动调用析构函数不同，定位new运算符在delete的时候不会自动调用析构函数

注意：根据12.8的实际代码，我们会提出一个问题，直接delete pc1 delete pc3不就可以了吗？

这样是不可行的，主要原因在于delete不能与定位new运算符同时使用



解决办法：

**显式的调用析构函数**



12.9是使用定位new运算符的更好实现



#### 12.6  复习各种技术

在讲述书本内容之前，关于引用我们在来理解一下：

```c++
int main()
{
  int a;
  int &b=a;
  int c;
  
  a=100;
  c=b;
  cout<<a<<"  "<<b<<"  "<<c<<endl;

  a=1000;
  cout<<a<<"  "<<b<<"  "<<c<<endl;

}
```

在上面的代码中，ac是常规变量，b是引用变量，理解的关键在于c=b意味着什么？

1. 意味着仅仅将b的值赋值给c
2. 将c变成b的别名

答案是c=b的含义是1而不是2选项。理解这个问题的关键在于看清变量的类型，c是int而不是int &



##### 三种较为难以掌握的编程技术：

重载<<运算符，转换函数，构造函数使用new的类

