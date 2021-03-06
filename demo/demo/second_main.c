//
//  second_main.c
//  demo
//
//  Created by vision chen on 2021/4/11.
//

#include "second_main.h"
#define N 100
#define O N+1 // 宏定义允许嵌套，在宏定义的字符串中可以使用已经定义的宏名，在宏展开时由预处理程序层层代换
#define M (n*n + 3*n) // 两边的括号不能少，否则在宏展开以后可能会产生歧义
#define NINT unsigned int // 可用宏定义表示数据类型，使书写方便
#define PIN1 int *
#define P(y) y*y + 3*y // 带参数的宏定义
#define max(x,y) x>y? x:y // 输出较大的值
#define SQ(y) (y)*(y)
#define SQ2(y) y*y // 注意跟SQ的区别
#define SQ3(y) ((y)*(y)) // 对于带参宏定义不仅要在参数两侧加括号，还应该在整个字符串外加括号
#define STR(s) #s // #用来将宏参数转换为字符串，也就是在宏参数的开头和末尾添加引号
#define CON1(a,b) a##e##b // ##称为连接符，用来将宏参数或其他的串连接起来
#define CON2(a,b) a##b##000

//用函数计算平方值
int SQ4(int y) {
    return ((y) * (y));
}
void second_main() {
    int sum = 20 + N;
    printf("%d\n",sum);
    // 宏定义一般形式为 #define  宏名  字符串
    // 宏名是标识符的一种，命名规则和变量相同。字符串可以是数字、表达式、if 语句、函数等
    int n = 10;
    sum = 3*M + 4*M + 5*M;
    printf("sum=%d\n",sum);
    // 宏定义必须写在函数之外，其作用域为宏定义命令起到源程序结束。如要终止其作用域可使用#undef命令
    // 代码中的宏名如果被引号包围，那么预处理程序不对其作宏代替
    printf("M\n");
    // 注意用宏定义表示数据类型和用 typedef 定义数据说明符的区别。宏定义只是简单的字符串替换，由预处理器来处理；而 typedef 是在编译阶段由编译器处理的，它并不是简单的字符串替换，而给原有的数据类型起一个新的名字，将它作为一种新的数据类型
    // 宏定义虽然也可表示数据类型， 但毕竟只是简单的字符串替换
    typedef int *PIN2;
    PIN1 a,b; // 在宏代换后变成int * a, b; 表示 a 是指向整型的指针变量，而 b 是整型变量
    PIN2 c,d; // 表示 c、d 都是指向整型的指针变量 因为 PIN2 是一个新的、完整的数据类型
    // C语言允许宏带有参数。在宏定义中的参数称为“形式参数”，在宏调用中的参数称为“实际参数”，这点和函数有些类似。
    // 对带参数的宏，在展开过程中不仅要进行字符串替换，还要用实参去替换形参
    // 带参数的宏的定义形式为： #define 宏名(形参列表) 字符串
    printf("带参数的宏P(5) = %d\n",P(5));
    printf("带参数的宏max(766,9777) = %d\n",max(766,9777));
    // 带参宏定义中，形参之间可以出现空格，但是宏名和形参列表之间不能有空格出现
    // #define MAX  (a,b)  (a>b)?a:b 将被认为是无参宏定义，宏名 MAX 代表字符串(a,b) (a>b)?a:b
    // 在带参宏定义中，不会为形式参数分配内存，因此不必指明数据类型。而在宏调用中，实参包含了具体的数据，要用它们去替换形参，因此实参必须要指明数据类型。
    printf("SQ(9+1)=%d\n",SQ(9+1)); // 宏展开时，用 a+1 代换 y，再用 (y)*(y) 代换 SQ
    // 这与函数的调用是不同的，函数调用时要把实参表达式的值求出来再传递给形参，而宏展开中对实参表达式不作计算，直接按照原样替换
    // 在宏定义中，字符串内的形参通常要用括号括起来以避免出错。例如上面的宏定义中 (y)*(y) 表达式的 y 都用括号括起来
    printf("SQ2(9+1) = %d\n",SQ2(9+1)); // 宏替换后将得到以下语句sq=a+1*a+1
    // 参数两边的括号是不能少的。即使在参数两边加括号还是不够的
    int sq = 200 / SQ(9+1);
    printf("200 / SQ(9+1) = %d\n",sq); // 200,而我们希望的结果是2 在宏展开之后变为：sq=200/(9+1)*(9+1);
    // 为了得到正确答案，应该在宏定义中的整个字符串外加括号
    sq = 200/SQ3(9+1);
    printf("200 / SQ3(9+1) = %d\n",sq); // 2
    // 带参数的宏和函数很相似，但有本质上的区别：宏展开仅仅是字符串的替换，不会对表达式进行计算；宏在编译之前就被处理掉了，它没有机会参与编译，也不会占用内存。而函数是一段可以重复使用的代码，会被编译，会给它分配内存，每次调用函数，就是执行这块内存中的代码
    int i = 1;
    while (i<=5) {
        printf("宏定义SQ3(5) = %d ,函数定义SQ4(5)= %d\n",SQ3(i),SQ4(i));
        i++;
    }
    // 带参数的宏也可以用来定义多个语句，在宏调用时，把这些语句又替换到源程序中
    // 宏参数的字符串化和宏参数的连接
    // #用来将参数转化为字符串，也就是在宏参数的开头和结尾添加引号
    printf("宏参数#的字符串化%s\n",STR(c.biancheng.net));
    printf("宏参数#的字符串化%s\n",STR("c.biancheng.net"));
    // ##的用法: 称为连接符，用来将宏参数或其他的串连接起来
    printf("宏参数##连接符%f\n",CON1(8.5, 2));
    printf("宏参数##连接符%d\n",CON2(12,34));
    // C语言中几个预定义宏,就是已经预先定义好的宏，我们可以直接使用，无需再重新定义
    // 1. __LINE__：表示当前源代码的行号；
    // 2. __FILE__：表示当前源文件的名称；
    // 3. __DATE__：表示当前的编译日期；
    // 4. __TIME__：表示当前的编译时间
    // 5. __STDC__：当要求程序严格遵循ANSI C标准时该标识被赋值为1；
    // 6. __cplusplus：当编写C++程序时该标识符被定义。
    printf("line: %d\n",__LINE__);
    printf("file: %s\n",__FILE__);
    printf("date: %s\n",__DATE__);
    printf("time: %s\n",__TIME__);
    printf("stdc: %d\n",__STDC__);
    
    //C语言#if、##ifdef、#ifndef的用法详解，C语言条件编译详解
    // 假如现在要开发一个C语言程序，让它输出红色的文字，并且要求跨平台，在 Windows 和 Linux 下都能运行 我们必须要能够识别出不同的平台
    // 这些操作都是在预处理阶段完成的，多余的代码以及所有的宏都不会参与编译，不仅保证了代码的正确性，还减小了编译后文件的体积
    // 这种能够根据不同情况编译不同代码、产生不同目标文件的机制，称为条件编译。条件编译是预处理程序的功能，不是编译器的功能
    // #if 命令要求判断条件为“整型常量表达式”，也就是说，表达式中不能包含变量，而且结果必须是整数；而 if 后面的表达式没有限制，只要符合语法就行。这是 #if 和 if 的一个重要区别
    #if _WIN32
        system("color 0c");
        printf("http://c.biancheng.net\n");
    #elif __linux__
        printf("\033[22;31mhttp://c.biancheng.net\n\033[22;30m");
    #else
        printf("http://c.biancheng.net\n");
    #endif
    // #ifdef 用法的一般格式为：
    //#ifdef  宏名
    //  程序段1
    //#else
    //    程序段2
    //#endif
    // 它的意思是，如果当前的宏已被定义过，则对“程序段1”进行编译，否则对“程序段2”进行编译
    // VS/VC 有两种编译模式，Debug 和 Release。在学习过程中，我们通常使用 Debug 模式，这样便于程序的调试；而最终发布的程序，要使用 Release 模式，这样编译器会进行很多优化，提高程序运行效率，删除冗余信息
    // #ifndef 的用法,与#ifdef正好相反
    // #if 后面跟的是“整型常量表达式”，而 #ifdef 和 #ifndef 后面跟的只能是一个宏名，不能是其他的
    // #error 指令用于在编译期间产生错误信息，并阻止程序的编译，其形式如下： #error error_message
    // 例如，我们的程序针对Linux编写，不保证兼容Windows
    #ifdef WIN32
    #error This programme cannot compile at Windows Platform
    #endif
}
    

#undef M //表示M只在second_main函数中有效，在其他函数中无效
