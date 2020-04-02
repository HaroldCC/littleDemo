package j01动态数组;

/*************************************************************************
> File Name       : 斐波那契数列.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月14日  13时54分15秒
************************************************************************/
//package Java版;

/**
 * 斐波那契数列 E:0 1 1 2 3 5 8 13 ...... Q:求第n个数的斐波那契数是多少？
 */
public class j01斐波那契数列 {

    // 方法一: 时间复杂度：O(2^n)
    // 缺点：当计算的是较大时，无法成功计算 时间复杂度高
    public static int fib1(int n) {
        if (n <= 1)
            return n;

        return fib1(n - 1) + fib1(n - 2);
    }

    // 方法二：
    public static int fib2(int n) {
        if (n <= 1)
            return n;

        int first = 0;
        int second = 1;
        for (int i = 0; i < n - 1; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }

    public static void main(String[] args) {
        System.out.print("fib2:");
        System.out.println(fib2(30));
        System.out.print("fib1:");
        System.out.println(fib1(30));
    }

}