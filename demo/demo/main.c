//
//  main.c
//  demo
//
//  Created by vision chen on 2021/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "itoa.h"

int c1;
float c2;
char c3;
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 99;
    char c = 'A';
    float d = 90.99;
    printf("Hello, World!\n");
    puts("hhhh");
    printf("value is %d\n",a);
    printf("a= %d,c= %c,d = %f\n",a,c,d);
    printf("a=%d,b=%c\n",100,'M');
    printf("a=%ds\n",99);
    puts("C语言中文网！"  "C语言和C++！"  "http://c.biancheng.net\n");
    long e = 2984;
    int f = sizeof(short);
    int g = sizeof(e);
    int h = sizeof e;
    printf("%d,%d,%d\n",f,g,h);
    short aa = 12;
    int b = 897;
    long cc = 7833;
    printf("%hd,%d,%ld\n",aa,b,cc);
    short ae = 0B01011;
    int ad = 0234;
    long af= 0xff1332;
    printf("%ho,%o,%lo\n",ae,ad,af); // 8进制形式输出
    printf("%hd,%d,%ld\n",ae,ad,af); // 10进制输出
    printf("%hx,%x,%lx\n",ae,ad,af); // 16进制输出
    printf("%hX,%X,%lX\n",ae,ad,af); // 16进制字母大写输出
    // 上述四个输出有一些缺陷，那就是无法分辨是8进制，还是10进制，还是16进制，可以通过加#前缀区分
    printf("%#ho,%#o,%#lo\n",ae,ad,af); // 8进制形式输出
    printf("%hd,%d,%ld\n",ae,ad,af); // 10进制输出
    printf("%#hx,%#x,%#lx\n",ae,ad,af); // 16进制输出
    printf("%#hX,%#X,%#lX\n",ae,ad,af); // 16进制字母大写输出
    // 如果只考虑正数，那么各种类型的表示的数值范围（取值范围）就比原来少了一半
    // 很多情况下，我们非常确定某个数字是正数，例如班级人数，这时符号位就是多余的，不如把符号位删掉，将所有位用来存储数值，这样能表示的数值就更大（大一倍）
    // 如果我们不希望设置符号位，可以在数据类型前面加上unsigned关键字
    unsigned short q = 12;
    unsigned int qw = 1003;
    unsigned qr = 1003; // 等价于 unsigned int qw，如果是unsigned int类型可以将int省略
    unsigned long qe = 209322;
    printf("%hd,%d,%d,%ld\n",q,qw,qr,qe);
    unsigned short we = 23;
    unsigned wr = 2312;
    unsigned long wt = 894363;
    printf("%ho,%o,%lo\n",we,wr,wt); // 输出无符号8进制数
    printf("%hu,%u,%lu\n",we,wr,wt); // 输出无符号10进制数
    printf("%hx,%x,%lx\n",we,wr,wt); // 输出无符号16进制数，小写
    printf("%hX,%X,%lX\n",we,wr,wt); // 输出无符号16进制数，大写
    int gg = 1.093e3;
    printf("%d\n",gg);
    float y1 = 1.0989909;
    double y2 = 1.09373643731;
    double y3 = 1.09379773e-2;
    printf("%f,%e,%E\n",y1,y1,y1);
    printf("%lf,%le,%lE\n",y2,y2,y2);
    printf("%lf\n",y3); // %f和%lf默认保存6位小数位，不足6位补0，超过按4舍5入截断
    float y4 = 78;
    double y5 = 90;
    printf("%f,%lf\n",y4,y5); // 将整数赋值给float或者double类型时，会变成小数
    float y6 = 10.7;
    double y7 = 923.2376234;
    printf("%e,%le\n",y6,y7); // 以指数形式输出小数时，输出结果为科学记数法，并且尾数保留6位小数，不足6位补0，超过按4舍5入截断
    float y8 = 0.0000001;
    float y9 = 90000000;
    float y10 = 1.34;
    float y11 = 1.32423232;
    // %g默认最多保留6位有效数字，包括小数部分和整数部分，%f和%e默认保留6位小数，只包括小数部分
    // %g不会强加0来凑够有效位数，而%f和%e会强加0来凑够小数部分的位数，所以一般%g会比较符合用户习惯
    // %g，%G以指数形式输出float类型，只是e大小写不一样，%lg，%lG以指数形式输出double类型，只是e大小写不一样
    printf("%g,%g,%g,%g\n",y8,y9,y10,y11); // %g会对比十进制和指数形式，以最短的方式输出小数，即占用最小的字符
    long y12 = 12; // 12和90这两个数字默认都是int类型的，而将12赋值给12，必须先从int类型转换成long
    int y13 = 90;  // 默认的不用转换
    float y14 = 23.32; // 23.32和92.303这两个数字默认是double类型的，而将92.303赋值给y15，必须先从double转换成float
    double y15 = 92.303; // 默认的不用转换
    printf("%ld,%d,%f,%lf\n",y12,y13,y14,y15);
    // 如果不想让数字使用默认类型，可以给数字加上后缀，手动指明类型
    // 加上后缀虽然数字的类型变了，但是并不意味着该数字只能赋值给制定的类型，他仍然能够赋值给其他类型，只要进行一下转换就可以了
    long y16 = 32l; // 在整数后面加上l或者L（不区分大小写）表明该数字是long类型
    long y17 = 930L;
    float y18 = 0.324f; // 在小数后面加上f或者F（不区分大小写）表明该数字是float类型
    float y19 = 2.32F;
    printf("%ld,%ld,%f,%f\n",y16,y17,y18,y19);
    // 在c语言中，小数和整数可以相互赋值
    int y20 = 12.327;
    int y21 = -31.3214;
    float y22 = 32;
    float y23 = -43;
    printf("%d,%d,%f,%f\n",y20,y21,y22,y23); // 将一个小数赋值给整数类型，会将小数部分丢掉，只能取整数部分，这会改变数字本来的值，注意是丢掉小数部分，而不是四舍五入  将一个整数赋值给小数类型，在小数点后面添加0就行，加几个无所谓 但是将小数赋值给整数类型时会“失真”，有些编译器会给出警告
    
    // 浮点数结构体
    typedef struct {
        unsigned int nMant: 23; // 尾数部分
        unsigned int nExp: 8; // 指数部分
        unsigned int nSign: 1; // 符号部分
    } FP_SIGNLE;
    char strBin[33] = {0};
    float ff = 19.625;
    FP_SIGNLE *p = (FP_SIGNLE*)&ff;
    itoa(p->nSign, strBin, 2);
    printf("sign: %s\n",strBin);
    itoa(p->nExp,strBin,2);
    printf("exp: %s\n",strBin);
    itoa(p->nMant,strBin,2);
    printf("nMain: %s\n",strBin);
    // 精度问题 对于十进制小数，小数部分转换成二进制使用“乘二取整法”，一个有限位数的小数不一定会转换成有限位数的二进制，只有位数是5的小数才有可能转换为有限位数的二进制，而float和double尾数部分都是有限的，即使能够转换成有限的二进制，也可能会超出尾数部分的长度，这样就必须“四舍五入”，所以就涉及到了精度的问题，因此，浮点数存储的不一定是正真实的小数，很可能是一个近似值
    // 对于char类型，计算机在存储的时候存储的是字符的ASCII码，而所有的字符编码都是一个整数，因此从该角度看， 字符类型和整数类型在本质上没有什么区别,所有的ASCII码实际上存储都是整数
    char q1 = '1';
    char q2 = '$';
    putchar(q1);putchar(q2);putchar('\n');
    printf("%c,%c\n",q1,q2);
    char q3 = 'E';
    char q4 = 76;
    printf("q3: %c,%d\n",q3,q3);
    printf("q4, %c,%d\n",q4,q4);
    
    // 在c语言中，没有专门的字符串类型，只能用数组或者指针来间接地存储字符串
    char str1[] = "这段是用数组的方式来存储字符串的";
    char *str2 = "这段是用指针的方式来存储字符串的";
    printf("%s\n%s\n",str1,str2);
    
    // c语言中，一个字符除了可以用它的实体（也就是真正的字符表示），还可以用编码值表示，这种用编码值来表示自字符的方式称为转义字符,可以使用八进制（\）和十六进制(\x)，也可以同时使用
    // 转义字符的初衷是用于ASCII码，所以取值有限，八进制的转移字符最多后面跟三位数，最大取值是\177,十六进制的最多跟两位，最大取值是\x7f
    // 单引号，双引号和反斜杠是特殊字符
    // 单引号是字符类型的开头和结尾，要使用\'表示，也即'\''
    // 双引号是字符串类型的开头和结尾，要使用\"表示，也即"abc\"12"
    // 反斜杠是转移字符的开头，要使用\\表示，也即'\\',或者"ab\\12"
    puts("C\tC++\tJava\n\"C\"\tfirst\tp\n");
    char a1 = '\62';
    char a2 = '\143';
    char a3 = '\x62';
    printf("%d,%d,%d\n",a1,a2,a3);
    puts("\63\32\41\62");
    puts("\x68\164\164\x70");
    // 标识符： 变量名、函数名、宏名、结构体名等都是标识符
    // c语言虽然不限制标识符的长度，但是它受不同编译器的限制，同时也受到操作系统的限制，例如某些编译器中规定标识符前128位有效，当两个标识符前128位相同时会被认为是同一标识符
    // 标识符中，大小写有区别
    // 关键字也称为保留字，例如int,float,double,unsigned等
    // 注释，单行注释//，多行注释/* */,多行注释不能嵌套使用
    // 表达式必须有一个执行结果，这个结果必须是一个值，例如2+1的结果是3，a=b=c=10的结果是10，printf("hello")的结果是5（printf的返回值是成功打印的字符的个数)
    // 以分号;结束的往往称为语句，而不是表达式，例如2+!; a=b=c;等
    
    // c语言中除法的算法有点奇怪，不同类型的除数和被除数会导致不同的运算结果
    // 当除数和被除数都是整数时，运算结果也是整数，如果不能整除，那么就直接丢掉小数部分，只保留整数部分，这跟小数赋值给整数是一个道理
    // 一旦除数和被除数中有一个是小数，那么运算结果也是小数，并且是double类型的小数
    int a7 = 18;
    int a8 =3;
    float a9 = 3.0;
    double a11 = a7 / a8;
    double a12 = a7 / a9;
    printf("%lf,%lf\n",a11,a12);
    //    int b1,b2;
    //    scanf("%d %d",&b1,&b2);
    //    printf("result:%d\n",b1/b2);
    
    // c语言中的取余运算符%，取余运算只能针对整数，也就是%两边都必须是整数，不能出现小数，否则编译器会报错
    // 余数可以是正数，也可以是负数，由%左边的整数决定，如果%左边是正数，那么余数也是正数，如果%左边是负数，那么余数也是负数
    printf("%d,%d,%d,%d\n",100%12,100%-12,-100%12,-100%-12);
    // 在printf中%是格式控制符的开头，是一种特殊字符，不能直接输出，如果想要输出%。必须在他前面再加一个%,这个时候%就是普通的字符，而不是用来表示格式控制符了
    // 自增++自减--
    // 自增自减的结果必须有变量来接收，所以自增自减只能针对变量，不能针对数字，例如10++就是错误的
    // 前自增自减和后自增自减的区别:前自增自减先自增自减后进行其他操作，后自增自减先进行其他操作后进行自增自减
    int b3 = 10,b4 = 20,b5 = 30,b6 = 40;
    int b33 = ++b3,b44 = b4++,b55 = --b5,b66 = b6--;
    printf("b3=%d,b33=%d\n",b3,b33);
    printf("b4=%d,b44=%d\n",b4,b44);
    printf("b5=%d,b55=%d\n",b5,b55);
    printf("b6=%d,b66=%d\n",b6,b66);
    int b7 = 12, b8 = 1;
    int b9 = b7 - (b8--); // 12 - 1 = 11 ，运算减法后b8就等于0了
    int b10 = (++b7) - (--b8); // 13 - (-1) = 14,先进行自增自减后才进行减法
    printf("b9=%d,b10=%d\n",b9,b10);
    // 在c语言中，变量可以定义在函数外面，也可以定义在函数里面,函数外定义的变量为全局变量，函数内定义的变量为局部变量
    // 在vc和vs编译器中，变量要在函数开头定义，例如在定义a，b之前有语句c=d+f; 这是错误的
    // 一个变量，如果不给它赋值，也会有一个默认的初始值，全局变量的默认初始值是0（它所占有的每一个字节都是0值），局部变量的默认初始值是随机的，是垃圾值，没有规律，因此在使用局部变量之前一定要初始化，否则它的值是没有意义的
    // 结合性：所谓结合性，就是当一个表达式中出现多个优先级相同的运算符时，先执行那个运算符，先执行左边的叫做左结合性，先执行右边的叫做右结合性
    // 自动类型转换，编译器自动进行转换
    // 1. 将一种数据类型赋值给另外一种类型的时候就会发生自动类型转换
    char s = 'A';
    printf("%c\n",s);
    // 在赋值运算中，赋值号两边的数据类型不同时，需要把右边表达式的类型转换为左边变量的类型，这可能会导致数据失真，或者精度降低；因此自动类型的转换并不一定是安全的，对于不安全的转换，浏览器一般会给出警告
    // 2. 在不同类型的混合运算中，编译器也会自动地进行数据类型转换，将参与运算的所有数据转换为同一种类型，然后再进行计算，转换规则如下：
    //  a. 按转换数据的长度增加的方向进行，以保证数值不失真，或者精度不降低，例如int和float参与运算时，先将int转换为float再进行运算
    //  b. 所有浮点数运算都是以双精度进行的，即使运算中只有float类型，也要先转为double类型，才能进行运算
    //  c. char与short运算参与运算时，必须先转换成int类型
    //  (short,char) -> int -> unsigned -> long -> double <- float
    float PI = 3.14159;
    int s1 , r = 5;
    double s2;
    s1 = r * r * PI;
    s2 = r * r * PI;
    printf("s1=%d,s2=%f\n",s1,s2); // 在计算r*r*PI时，r和PI都被转换成double类型，但由于s1是整型，所以赋值运算的结果仍为整型，舍去了小数部分，导致数据失真
    // 强制类型转换
    int s3 = 103;
    int s4 = 13;
    double avg;
    avg = (double) s3 / s4;
    printf("avg = %lf\n",avg); // 由于s3和s4都是int类型，如果不进行强制类型转换，那么s3/s4运算结果也是int，虽然avg是double可以接收小数，但是小数部分已经被提前“阉割”了，只能接收到整数部分，我们可以改变s3或者s4其中一个或者都改为double类型，那么运算结果也将变成double
    // 因此，对于除法运算，如果除数和被除数都是整型，那么运算结果也是整型，小数部分将会被直接丢弃
    // ()优先级高于/，对于表达式(double) s3 / s4，会先执行(double) s3，将s3转换为double类型，再进行除法运算，这样运算结果也是double类型，能够留住小数部分，注意如果写成(double)(s3 / s4),这样写的运算结果是7.000000，仍然不能保留小数部分
    // 无论是自动类型转换还是强制类型转换，都只是为了本次运算而进行的临时转换，转换的结果也会保存到临时的空间，不会改变数据本来的类型或值
    double total = 300.65;
    int count = 5;
    double unit;
    int int_total = (int) total;
    unit = int_total /count;
    printf("total=%lf,int_total=%d,unit=%lf\n",total,int_total,unit); // total变量被转换成了int类型才赋值给int_total,而这种转换并未影响到total变量本身的值和类型
    // 能自动转换的一定能强制转换，需要强制转换的不一定能自动转换
    int m1 = 10, m2 = 76, m3 = 979;
    int n1 = 89, n2 = 9087, n3 = 90865;
    printf("%9d %9d %9d\n",m1,m2,m3);
    printf("%-9d %-9d %-9d\n",n1,n2,n3); // %-9d中，d表示十进制输出，9表示最少占9个字符的宽度，宽度不足以空格补齐，-表示左对齐，不加-表示右对齐
    // printf格式控制符的完整形式为 %[flag][width][.precision]type ,其中[]表示此处的内容可有可无，可以省略
    // 1. type表示输出的类型，比如%d,%f,%c,%lf分别对应d,f,c,lf,type项必须有，这意味着输出时必须知道是什么类型
    // 2. width表示最小输出宽度，也就是至少占用几个字符的位置，例如上例中的9表示至少占用9个字符的宽度
    // 3. precision表示输出精度，也就是小数的位数，当小数部分位数大于precision时，会四舍五入的原则丢掉多余的数字，当小数部分小于precision时，会在后面补0
    // 4.
    //  当输出的宽度不足width时，以空格补齐，当输出结果的宽度超过width时，width不再起作用，按照数据本省的宽度输出
    // 5. flag时标识符。-表示左对齐，没有默认一般按右对齐，+用于整数或者小数，表示输出符号（正负号），若没有则只有在负数时才显示符号，空格 用于整数或者小数，输出为正时冠以空格，为负时冠以负号，#对于八进制（%o）和十六进制（%x / %X）整数，# 表示在输出时添加前缀；八进制的前缀是 0，十六进制的前缀是 0x / 0X。对于小数（%f / %e / %g），# 表示强迫输出小数点。如果没有小数部分，默认是不输出小数点的，加上 # 以后，即使没有小数部分也会带上小数点。
    //另外，.precision 也可以用于整数和字符串，但是功能却是相反的：
    //    用于整数时，.precision 表示最小输出宽度。与 width 不同的是，整数的宽度不足时会在左边补 0，而不是补空格。
    //    用于字符串时，.precision 表示最大输出宽度，或者说截取字符串。当字符串的长度大于 precision 时，会截掉多余的字符；当字符串的长度小于 precision 时，.precision 就不再起作用
    int m4 = 234;
    float m5 = 9.8;
    char m6 = '@';
    char *m7 = "https://www.baidu.com";
    printf("%10d%12f%4c%8s\n",m4,m5,m6,m7);
    
//    printf("test\n");
//    sleep(5);
//    printf("等5秒\n");
    // 读取从键盘上输入的数据
    // scanf()：和 printf() 类似，scanf() 可以输入多种类型的数据  getchar()、getche()、getch()：这三个函数都用于输入单个字符  gets()：获取一行数据，并作为字符串处理
    
    // 对于scanf()输入数据的格式要和控制字符串的格式保持一致
    // scanf和printf非常相似，都有格式控制字符串，不同的是scanf的变量前要加一个&,&称为取地址符，也就是获取变量在内存中的地址
    // 对于整数、浮点数、字符，都要使用 & 获取它们的地址，scanf 会根据地址把读取到的数据写入内存
//    int m8 = 0, m9 = 0, m10 = 0 , m11 = 0;
//    scanf("%d",&m8);
//    scanf("%d",&m9);
//    printf("m8 + m9 = %d",m8+m9);
//    scanf("%d %d",&m10,&m11);
//    printf("m10 * m11 = %d\n",m10 * m11);
    
    int c1 = 12;
    char c2 = 'U';
    printf("&c1 = %p , &c2 = %p\n",&c1,&c2); // %p表示以十六进制的形式输出数据的地址，如果写成%P,那么十六进制的前缀会大写 注意这里的地址是虚拟地址，并不是真正的物理地址
    
//    int c3,c4,c5;
//    scanf("%d %d",&c3,&c4);
//    printf("c3+c4=%d\n",c3+c4);
//    scanf("%d      %d",&c3,&c4);
//    printf("c3+c4=%d\n",c3+c4);
//    scanf("%d,%d,%d",&c3,&c4,&c5);
//    printf("c3+c4+c5=%d\n",c3+c4+c5);
//    scanf("%d is bigger than %d",&c3,&c4);
//    printf("c3 - c4 = %d\n",c3 - c4);
    // 从本质上讲，我们从键盘输入的数据并没有直接交给 scanf()，而是放入了缓冲区中，直到我们按下回车键，scanf() 才到缓冲区中读取数据
    // 对于char a[] = 'dafad'和char *a = 'adfad'这两种定义字符串的形式是有区别的，第一种形式的字符串即有读取权限也有写入权限，第二种只有读取权限，没有写入权限
    // printf()、puts() 等字符串输出函数只要求字符串有读取权限，而 scanf()、gets() 等字符串输入函数要求字符串有写入权限
    // 第一种形式的字符串既可以用于输出函数又可以用于输入函数，而第二种形式的字符串只能用于输出函数。
    // scanf() 遇到空格就认为字符串结束了，不再继续读取了。
    // 输入单个字符，我们可以使用scanf("%c").也可以使用getchar(),getche(),getch()这三个字符输入函数，他们具有scanf没有的特性，是scanf()不能替代的
    // 1. 最容易理解的字符输入函数是 getchar()，它就是scanf("%c", c)的替代品，除了更加简洁，没有其它优势了；或者说，getchar() 就是 scanf() 的一个简化版本。
//    char c6 = getchar();
//    printf("%c\n",c6);
    // getche() 就比较有意思了，它没有缓冲区，输入一个字符后会立即读取，不用等待用户按下回车键，这是它和 scanf()、getchar() 的最大区别,getche位于 conio.h 头文件中，而这个头文件是 Windows 特有的
//    char c7 = getche();
//    printf("%c\n",c7);
    // getch() 也没有缓冲区，输入一个字符后会立即读取，不用按下回车键，这一点和 getche() 相同。getch() 的特别之处是它没有回显，看不到输入的字符。所谓回显，就是在控制台上显示出用户输入的字符；没有回显，就不会显示用户输入的字符，就好像根本没有输入一样。
    // 通常用在输入密码时，我们不希望回显
    // getch() 也位于 conio.h 头文件中，也不是标准函数，默认只能在 Windows 下使用
    
    //gets() 这个专用的字符串输入函数，它拥有一个 scanf() 不具备的特性
//    char c8[30];
//    gets(c8);
//    printf("c8: %s\n",c8); // gets() 是有缓冲区的，每次按下回车键，就代表当前输入结束了，gets() 开始从缓冲区中读取内容，这一点和 scanf() 是一样的
    //gets() 和 scanf() 的主要区别:
    // scanf() 读取字符串时以空格为分隔，遇到空格就认为当前字符串结束了，所以无法读取含有空格的字符串
    // gets() 认为空格也是字符串的一部分，只有遇到回车键时才认为字符串输入结束，所以，不管输入了多少个空格，只要不按下回车键，对 gets() 来说就是一个完整的字符串
    // gets() 能读取含有空格的字符串，而 scanf() 不能
    // 缓冲区是为了让低速的输入输出设备和高速的用户程序能够协调工作，并降低输入输出设备的读写次数
    // 根据缓冲区对应的是输入设备还是输出设备，可以分为输入缓冲区和输出缓冲区
    // 根据数据刷新（也可以称为清空缓冲区，就是将缓冲区的数据“倒出”）的时机，可以划分为全缓冲，行缓冲，不带缓冲
    // 1. 全缓冲：当缓冲区被填满以后再进行真正的输入输出操作，缓冲区的大小都是有限制的，比如1kb,1mb等，数据量达到最大值时就清空缓冲区 在实际开发中，将数据写入文件后，打开文件并不能立即看到内容，只有清空缓冲区，或者关闭文件，或者关闭程序后，才能在文件中看到内容，这就是缓冲区在作怪
    // 2. 行缓冲： 当在输入或输出的过程中遇到换行符时，才执行真正的输入输出操作，行缓冲的经典代表就是标准输入设备（键盘）和标准输出设备（显示器）
    // 3. 不带缓冲： 数据没有地方缓存，必须立即进行输入输出getche和getch就不带缓冲，输入一个字符后就立即执行了，不用按回车键
    // c语言标准规定，输入输出缓冲区要具有以下特征： 1.当且仅当输入输出不涉及交互设备时，他们才是全缓冲的 2. 错误显示设备不能带有缓冲区
    
    // 1) 输入设备
     /* scanf()、getchar()、gets() 就是从输入设备（键盘）上读取内容。对于输入设备，没有缓冲区将导致非常奇怪的行为，比如，我们本来想输入一个整数 947，没有缓冲区的话，输入 9 就立即读取了，根本没有机会输入 47，所以，没有输入缓冲区是不能接受的。Windows、Linux、Mac OS 在实现时都给输入设备带上了行缓冲，所以 scanf()、getchar()、gets() 在每个平台下的表现都一致。
      但是在某些特殊情况下，我们又希望程序能够立即响应用户按键，例如在游戏中，用户按下方向键人物要立即转向，而且越快越好，这肯定就不能带有缓冲区了。Windows 下特有的 getche() 和 getch() 就是为这种特殊需求而设计的，它们都不带缓冲区。
      */
    // Windows 平台下，输出设备是不带缓冲区的；Linux 和 Mac OS 平台下，输出设备带有行缓冲区
    // 刷新缓冲区，就是将缓冲区中的内容送达到目的地，缓冲区的刷新遵循以下的规则：
    /* 1. 不管是行缓冲还是全缓冲，缓冲区满时会自动刷新；
    2. 行缓冲遇到换行符\n时会刷新；
    3. 关闭文件时会刷新缓冲区；
    4. 程序关闭时一般也会刷新缓冲区，这个是由标准库来保障的；
    5. 使用特定的函数也可以手动刷新缓冲区
     */
    
    /*scanf() 是带有缓冲区的。遇到 scanf() 函数，程序会先检查输入缓冲区中是否有数据
    1如果没有，就等待用户输入。用户从键盘输入的每个字符都会暂时保存到缓冲区，直到按下回车键，输入结束，scanf() 再从缓冲区中读取数据，赋值给变量。
    2如果有数据，哪怕是一个字符，scanf() 也会直接读取，不会等待用户输入*/
    
//    int p1,p2,p3;
//    scanf("%d",&p1);
//    scanf("%d",&p2);
//    scanf("%d",&p3);
//    printf("p1 = %d, p2 = %d , p3 = %d\n",p1,p2,p3);
    // 注意：scanf() 匹配到想要的数据后，会将匹配到的数据从缓冲区中删除，而没有匹配到的数据仍然会留在缓冲区中。
    
    // 阻塞式键盘监听，阻塞式键盘监听用于用户输入时一般没有任何问题，用户输入完数据再执行后面的代码往往也符合逻辑。然而在很多小游戏中，阻塞式键盘监听会带来很大的麻烦，用户要不停按键游戏才能进行，这简直就是灾难，所以在小游戏中一般采用非阻塞式键盘监听：用户输入数据后程序可以捕获，用户不输入数据程序也可以继续执行。Windows 系统中，conio.h头文件中的kbhit()函数就可以用来实现非阻塞式键盘监听
    // c语言中三大结构：顺序结构，选择结构，循环结构
//    int age1;
//    printf("please enter your age\n");
//    scanf("%d\n",&age1);
//    if (age1 > 18) {
//        printf("adult\n");
//    } else {
//        printf("teenager\n");
//    }
//    system("pause");
    
//    int a0,b0,max;
//    printf("two num:");
//    scanf("%d %d",&a0,&b0);
//    if (a0>b0) max = a0;
//    else max = b0;
//    printf("较大的值是：%d\n",max);
    
    // 像1+2这样的有两个操作数，+是操作符，我们称这样的运算符为双目运算符（+-*/），有一个操作的称为单目远算符（++，--），三目运算符（只有？）
    // 关系运算符的结果只有0或1，当条件成立时结果为1，不成立结果为0
    char c20 = 'k';
    int i1 = 1, j1 = 2, k1= 3;
    float x10 = 3e5,ya2=0.85;
    int result_1 = 'a' + 5 < c20 ,result_2 = x10 - 5.25 <= x10 + ya2;
    printf("%d %d\n",result_1,-i1-2*j1 >= k1+1);
    printf("%d %d\n",1<j1,result_2);
    printf("%d %d\n",i1 + j1 + k1 == -2 * j1,k1 == j1 == i1 +5);
    // 对于含多个关系运算符的表达式，如 k==j==i+5，根据运算符的左结合性，先计算k==j，该式不成立，其值为0，再计算0==i+5，也不成立，故表达式值为0
    // 逻辑运算符
    // 逻辑运算符中&&和｜|为左结合性，！为右结合性
    // 一般称非零值为真，零值为假
    // 逻辑运算符与其他运算符的优先级 赋值运算符（=）< &&和｜｜ < 关系运算符 < 算数运算符 < 非(!)
//    int age1;
//    float score1;
//    printf("please enter your age and socre:");
//    scanf("%d %f",&age1,&score1);
//    if (age1 >= 18 && score1 >= 60) {
//        printf("welcome!\n");
//    } else {
//        printf("sorry!");
//    }
    
    // break 是C语言中的一个关键字，专门用于跳出 switch 语句。所谓“跳出”，是指一旦遇到 break，就不再执行 switch 中的任何语句，包括当前分支中的语句和其他分支中的语句；也就是说，整个 switch 执行结束了，接着会执行整个 switch 后面的代码
//    int number1;
//    printf("please enter a number");
//    scanf("%d",&number1);
//    switch (number1) {
//        case 1:
//            printf("monday");
//            break;
//        case 2:
//            printf("tuesday");
//            break;
//        case 3:
//            printf("wednesday");
//            break;
//        case 4:
//            printf("thursday");
//            break;
//        case 5:
//            printf("friday");
//            break;
//        case 6:
//            printf("saturday");
//            break;
//        case 7:
//            printf("sunday");
//            break;
//        default:
//            printf("error");
//            break;
//    }
    
    //case 后面必须是一个整数，或者是结果为整数的表达式，但不能包含任何变量,其中字符和整数可以相互转换（例如'A'可以转换）
    //default 不是必须的。当没有 default 时，如果所有 case 都匹配失败，那么就什么都不执行
    // 条件运算符(?)是c语言中唯一的三目远算符
    // 条件表达式应注意1.条件运算符的优先级低于关系运算符和算术运算符，但高于赋值符 2.条件运算符?和：是一对运算符，不能分开单独使用 3.条件运算符的结合方向是自右至左例： a>b ? a : c>d ? c : d; 应该理解为 a>b ? a : ( c>d ? c : d );
//    int nu1 ,nu2;
//    printf("please enter two integer number:");
//    scanf("%d %d",&nu1,&nu2);
//    printf("max = %d\n",nu1>nu2?nu1:nu2);
    int base = 1 , sums = 0;
    while (base <= 100) {
        sums += base;
        base++;
    }
    printf("sums = %d\n",sums);
    // while 循环的整体思路是这样的：设置一个带有变量的循环条件，也即一个带有变量的表达式；在循环体中额外添加一条语句，让它能够改变循环条件中变量的值。这样，随着循环的不断执行，循环条件中变量的值也会不断变化，终有一个时刻，循环条件不再成立，整个循环就结束了
    return 0;
}
