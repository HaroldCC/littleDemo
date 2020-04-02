/*************************************************************************
> File Name       : testStack.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  10时41分36秒
************************************************************************/

package j06栈;

/**
 * testStack
 */
public class testStack {

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(11);
        stack.push(22);
        stack.push(33);
        stack.push(44);
        stack.push(55);

        while (!stack.isEmpty())
            System.out.println(stack.pop());
    }
}