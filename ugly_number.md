# info 
在leetcode上面答的第一道题目
# 题目
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

# 解析
分解质因数问题,

先看一些概念:

质数:*除了1和它本身以外不再有其他的除数整除*

质因数:*能整除给定正整数的质数*

分解质因数:*每个合数都可以写成几个质数相乘的形式。其中每个质数都是这个合数的因数，叫做这个合数的分解质因数*

本题的意思是说如果质因子只有*2*,*3*,*5*的话就是*丑数*.*1*天生就是丑数.

思路是,从*2*,*3*,*5*开始除,如果都除不通肯定不是丑数,如果,如果不论怎么除都余数都不是*0*,那么它就是不是一个*uglynumber*.

例如:82,

1. 82 / 2 = 41; 余数是0,那么从*41*开始
2. 41 / 2,41 / 3,41 / 5 余数都不是*0*,那么这就不是一个丑数了.



# C++代码

    class Solution {
    public:
        bool isUgly(int num) {
            if(num==1){
                return true;
            }else if(num <= 0){
                return false;
            }else if(num%2 !=0 && num%3 != 0 && num%5 !=0){
                return false;
            }else{
                int factors[] = {2,3,5};
                int index = 0;
                while(1){
                    for(index = 0;index < 3;index++){
                        if(num%factors[index]==0){
                            num = num / factors[index];
                            break;
                        }
                    }
                    if(index == 3){
                        return false;
                    }
                    if(num == 1){
                        return true;
                    }
                }
            }
        }
    };

 