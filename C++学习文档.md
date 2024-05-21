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

