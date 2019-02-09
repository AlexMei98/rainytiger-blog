#include <iostream>

int main()
{
    int nx = 2000;
    int ny = 1000;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";    // 表头

    // 从左到右, 从上到下按像素赋值.
    for(int j = ny - 1; j >= 0; j --)
    {
        for(int i = 0; i < nx; i ++)
        {
            // 原文是 float, 但是到第七章就会出现问题, 提前改为 double 减少之后修改的麻烦.
            // 这里也可以不用 double, 但是在 float 数值后要加 'f' 表示浮点数. 比如 '255.99f', '0.2f'.
            double r = double(i) / double(nx);
            double g = double(j) / double(ny);
            double b = 0.2;

            // 计算时 RGB 是从 0 到 1, 由于存储是整数存储, 映射到 0 到 255 范围.
            // 由于从浮点数到整数是向 0 取整, 直接乘 255 会导致实际运算时取不到 255, 故这里用的 255.99.
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
