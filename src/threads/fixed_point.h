//
// Created by 전승훈 on 2022/03/16.
//

#ifndef PINTOS_SRC_THREADS_FIXED_POINT_H_
#define PINTOS_SRC_THREADS_FIXED_POINT_H_

#endif //PINTOS_SRC_THREADS_FIXED_POINT_H_

#define F (1 << 14)
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))

int int_to_fp(const int n);

int fp_to_int_round(const int fp);

int fp_to_int(const int fp); /* FP를 int로 전환(버림) */

int add_fp(const int fp1, const int fp2); /* FP의 덧셈 */

int add_mixed(const int fp, const int n); /* FP와 int의 덧셈 */

int sub_fp(const int fp1, const int fp2); /* FP의 뺄셈(x-y) */

int sub_mixed(const int fp, const int n); /* FP와 int의 뺄셈(x-n) */

int mult_fp(const int fp1, const int fp2); /* FP의 곱셈 */

int mult_mixed(const int fp, const int n); /* FP와 int의 곱셈 */

int div_fp(const int fp1, const int fp2); /* FP의 나눗셈(x/y) */

int div_mixed(const int fp, const int n);

/* 구현 */

int int_to_fp(const int n)
{
  return n*F;
}

int fp_to_int_round(const int fp)
{
  return (fp>=0) ? (fp + F/2)/F : (fp - F/2)/F;
}

int fp_to_int(const int fp)
{
  return fp/F;
}

int add_fp(const int fp1, const int fp2)
{
  return fp1 + fp2;
}

int add_mixed(const int fp, const int n)
{
  return fp + n*F;
}

int sub_fp(const int fp1, const int fp2) /* FP의 뺄셈(x-y) */
{
  return fp1 - fp2;
}

int sub_mixed(const int fp, const int n) /* FP와 int의 뺄셈(x-n) */
{
  return fp - n*F;
}

int mult_fp(const int fp1, const int fp2) /* FP의 곱셈 */
{
  return ((int64_t) fp1) * fp2 / F;
}

int mult_mixed(const int fp, const int n) /* FP와 int의 곱셈 */
{
  return fp * n;
}

int div_fp(const int fp1, const int fp2) /* FP의 나눗셈(x/y) */
{
  return ((int64_t) fp1) * F / fp2;
}

int div_mixed(const int fp, const int n)
{
  return fp / n;
}