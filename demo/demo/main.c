//
//  main.c
//  demo
//
//  Created by vision chen on 2021/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "itoa.h"

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
    return 0;
}
