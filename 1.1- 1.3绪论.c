#include <stdio.h>

// 定义复数结构体
typedef struct {
    float real;
    float imag;
} Complex;

// 1. 构造复数
void assign(Complex *z, float r, float i) {
    z->real = r;
    z->imag = i;
}

// 2. 复数相加：(a+bi) + (c+di) = (a+c) + (b+d)i
void add(Complex z1, Complex z2, Complex *z3) {
    z3->real = z1.real + z2.real;
    z3->imag = z1.imag + z2.imag;
}

// 3. 复数相乘：(a+bi)(c+di) = (ac-bd) + (ad+bc)i
void multiply(Complex z1, Complex z2, Complex *z4) {
    z4->real = z1.real * z2.real - z1.imag * z2.imag;
    z4->imag = z1.real * z2.imag + z1.imag * z2.real;
}

// 4. 复数相除 (简化版逻辑，主要体现图中 if 判断)
int divide(Complex z1, Complex z2, Complex *z) {
    float denominator = z2.real * z2.real + z2.imag * z2.imag;
    if (denominator == 0) return 0; // 除数不能为 0
    
    z->real = (z1.real * z2.real + z1.imag * z2.imag) / denominator;
    z->imag = (z1.imag * z2.real - z1.real * z2.imag) / denominator;
    return 1;
}

int main() {
    Complex z1, z2, z3, z4, z;
    float RealPart, ImagPart;

    // 第一步：构造基础数据
    assign(&z1, 8.0, 6.0); // z1 = 8+6i
    assign(&z2, 4.0, 3.0); // z2 = 4+3i

    // 第二步：按公式计算
    add(z1, z2, &z3);      // z3 = z1 + z2 (分母)
    multiply(z1, z2, &z4); // z4 = z1 * z2 (分子)

    // 第三步：相除并输出结果
    if (divide(z4, z3, &z)) {
        RealPart = z.real;
        ImagPart = z.imag;
        printf("计算结果为: %.2f + %.2fi\n", RealPart, ImagPart);
    } else {
        printf("错误：除数为零！\n");
    }

    return 0;
}
