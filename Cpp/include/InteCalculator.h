#ifndef _INTECALCULATOR_H_
#define _INTECALCULATOR_H_

#ifdef __cplusplus
/**
 * @brief 积分计算器
 * 
 * @tparam Inte_Filter_Type 滤波器类型
 */
template <class Inte_Filter_Type>
class InteCalculator
{
public:
    /* 用模板构造函数，解决不同filter的构造函数参数不同的问题, 如果构造函数的参数不符合filter类型的构造函数传参，则会编译失败 */
    template <typename... Args>
    InteCalculator(Args... args) : filter(args...) {}

    double get_inte() const { return inte; }

    double calc(double input, double _dt)
    {
        origin_inte = input * _dt; // 积分原始数据

        inte = get_filter_result(origin_inte);
        return inte;
    }

    void clear_inte()
    {
        this->origin_inte = 0;
        this->inte = 0;
    }

protected:
    Inte_Filter_Type filter;
    double get_filter_result(double data)
    {
        return filter.f(data);
    }
    double origin_inte = 0;
    double inte;
};
#endif  /* __cplusplus */

#endif  /* _DIFF_CALCULATOR_H_ */