#include "DiffCalculator.h"
#include "filter.h"
#include "SecondButterworthLPF.h"

int main()
{
    LPF_SecondOrder_Classdef lpf(10,500);
    DiffCalculator<LPF_SecondOrder_Classdef> diff(lpf);
    return 0;
}