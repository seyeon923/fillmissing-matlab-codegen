#include <iostream>
#include <cmath>

#include "FillMissingNearestDouble.h"
#include "FillMissingNearestDouble_terminate.h"
#include "coder_array.h"

int main()
{
    double *ptr;

    double input[12] = {1, 2, 3, 4,
                        NAN, 6, 7, 8,
                        9, 10, 11, 12}; // 3x4 이미지라고 가정
    double output[12];

    int idx = 0;
    std::cout << "input: " << '\n';
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            std::cout << input[idx++] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    coder::SizeType size[2] = {3, 4};
    auto input_arr = coder::array<double, 2>();
    input_arr.set(input, 3, 4); // shallow copy

    std::cout << "input_arr: " << '\n';
    ptr = input_arr.data();
    assert(ptr == input); // Assert shallow copy
    idx = 0;
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            std::cout << ptr[idx++] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    auto output_arr = coder::array<double, 2>();
    output_arr.set(output, 3, 4);

    FillMissingNearestDouble(input_arr, output_arr);

    std::cout << "output: " << '\n';
    idx = 0;
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            std::cout << output[idx++] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    FillMissingNearestDouble_terminate(); // 프로그램 종료 시 한번만 호출하면 된다는 듯

    return 0;
}
// 실행 결과
// input:
// 1 2 3 4
// nan 6 7 8
// 9 10 11 12

// input_arr:
// 1 2 3 4
// nan 6 7 8
// 9 10 11 12

// output:
// 1 2 3 4
// 9 6 7 8
// 9 10 11 12
