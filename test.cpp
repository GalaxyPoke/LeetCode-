#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include <string> // 包含stoi函数

using namespace std;


//class Solution {
//public:
//    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
//        int n = A.size();
//        move(n, A, B, C);
//    }
//
//    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
//        if (n == 1) {
//            C.push_back(A.back());
//            A.pop_back();
//            return;
//        }
//        move(n - 1, A, C, B);    // 将A上面n-1个通过C移到B
//        C.push_back(A.back()); // 将A最后一个移到C
//        A.pop_back();          // 这时，A空了
//        move(n - 1, B, A, C);    // 将B上面n-1个通过空的A移到C
//    }
//};
//
//int main() {
//    vector<int> A = { 3, 2, 1 }, B = {}, C = {};
//    Solution sol;
//    sol.hanota(A, B, C);
//
//    // 打印结果
//    cout << "C tower contains: ";
//    for (int num : C) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}



// 函数定义：移除有序向量中的重复元素，并返回新的向量长度
//int removeDuplicates(vector<int>& nums) {
//    int numsSize = nums.size(); // 获取向量的大小
//    if (numsSize == 0) { // 如果向量为空，则直接返回长度为0
//        return 0;
//    }
//
//    int dest = 0; // dest指针用于记录最后一个不重复元素的位置
//    // 遍历向量中除了第一个元素之外的所有元素
//    for (int cur = 1; cur < numsSize; ++cur) {
//        // 当前元素与dest位置的元素不相同，说明发现了新的不重复元素
//        if (nums[cur] != nums[dest]) {
//            // 将这个新的不重复元素移动到dest+1的位置
//            nums[++dest] = nums[cur];
//        }
//    }
//
//    // 返回新的向量长度，因为dest是从0开始的索引，所以要加1
//    return dest + 1;
//}
//
//int main() {
//    // 定义一个有序向量
//    std::vector<int> nums = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 5 };
//
//    // 输出原始向量
//    std::cout << "Original vector:\n";
//    for (int num : nums) {
//        std::cout << num << " ";
//    }
//    std::cout << "\n";
//
//    // 调用removeDuplicates函数
//    int newSize = removeDuplicates(nums);
//
//    // 输出处理后的向量和新的长度
//    std::cout << "Processed vector with no duplicates:\n";
//    for (int i = 0; i < newSize; ++i) {
//        std::cout << nums[i] << " ";
//    }
//    std::cout << "\nNew size: " << newSize << std::endl;
//
//    return 0;
//}


class Solution {
public:
    // 评估逆波兰表达式的主函数
    int evalRPN(vector<string>& tokens) {
        stack<int> st;  // 使用整数栈来存储中间计算结果

        // 遍历所有的token（即每一个数字或运算符）
        for (size_t i = 0; i < tokens.size(); i++) {
            int left, right;  // 用于存储两个操作数

            // 根据当前token的内容决定操作
            if (tokens[i] == "+") {  // 加法运算符
                GetNum(st, left, right);  // 从栈中取两个数
                st.push(left + right);  // 将两数之和压入栈中
            }
            else if (tokens[i] == "-") {  // 减法运算符
                GetNum(st, left, right);  // 从栈中取两个数
                st.push(left - right);  // 将两数之差压入栈中
            }
            else if (tokens[i] == "*") {  // 乘法运算符
                GetNum(st, left, right);  // 从栈中取两个数
                st.push(left * right);  // 将两数之积压入栈中
            }
            else if (tokens[i] == "/") {  // 除法运算符
                GetNum(st, left, right);  // 从栈中取两个数
                st.push(left / right);  // 将两数之商压入栈中
            }
            else {  // 数字
                st.push(stoi(tokens[i]));  // 将字符串转换为整数并压入栈中
            }
        }
        return st.top();  // 返回栈顶元素，即为表达式的最终结果
    }

    // 从栈中取出两个操作数的辅助函数
    void GetNum(stack<int>& st, int& left, int& right) {
        right = st.top();  // 栈顶是右操作数
        st.pop();  // 弹出栈顶元素
        left = st.top();  // 下一个栈顶是左操作数
        st.pop();  // 弹出栈顶元素
    }
};


// 函数定义：移除有序数组中的重复元素，并返回新的数组长度
int removeDuplicates(int* nums, int numsSize)
{
    // 如果数组为空，则直接返回长度为0
    if (numsSize == 0)
    {
        return 0;
    }

    // dest指针用于记录最后一个不重复元素的位置
    int dest = 0;
    // cur指针用于遍历数组中的每一个元素
    int cur = 1;
    // 初始化，将第一个元素视为不重复元素
    nums[dest] = nums[0];

    // 遍历数组中除了第一个元素之外的所有元素
    while (cur < numsSize)
    {
        // 当前元素与dest位置的元素不相同，说明发现了新的不重复元素
        if (nums[cur] != nums[dest])
        {
            // 将这个新的不重复元素移动到dest+1的位置
            nums[++dest] = nums[cur++];
        }
        else
        {
            // 如果当前元素与dest位置的元素相同，跳过这个重复元素
            cur++;
        }
    }

    // 返回新的数组长度，因为dest是从0开始的索引，所以要加1
    return dest + 1;
}


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int Numsize = nums.size();
        int cur = 1;
        int dest = 0;//默认第一个是独一无二的
        int flag = 1;//第二个元素至多可以重复一次，所以初始化flag为1，表示第一个元素已经出现过一次
        if (nums.size() <= 2) {
            return nums.size(); // 如果数组大小不超过2，则不需要任何操作
        }

        while (cur < Numsize)
        {

            if (nums[cur] == nums[dest] && flag < 2)
            {
                // 如果当前元素与前一个相同，但还没有重复超过一次，那么也添加到数组中
                nums[++dest] = nums[cur];
                cur++;
                flag++;
            }
            else if (nums[cur] == nums[dest] && flag >= 2)
            {
                //这种情况就不符合题目条件了
                cur++;

            }
            else
            {
                // 如果当前元素(cur)与前一个(dest)不同，那么它可以被添加到dest+1的位置中
                nums[++dest] = nums[cur];
                cur++;
                flag = 1;
            }
        }

        return dest + 1;// 数组的新长度是最后一个元素的索引 + 1
    }
};
