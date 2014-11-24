#include "base.h"

//1.1 Implement an algorithm to determine if a string has all unique characters. What if you
//can not use additional data structures?
//时间复杂度为o(n), 空间复杂度256
//可选方式:
//  1. 如果字符串中只有a-z26个字符那么可以纯粹的使用一个int的bit位来表示
//  2. 暴力法, 对每一个字符检测整个字符串 O(n^2)
//  3. 排序法, 对字符串排序,检测相邻字符串是否相同(O(nlgn + n))
bool checkStringUnique(const string &s)
{
    //此处将unsigned char改为bool
    unsigned char keeps[256] = {0};
    for (int i = 0; i < s.length(); ++i)
    {
        if (keeps[s[i]] != 0)
        {
            return false;
        }

        keeps[s[i]] = 1;
    }

    return true;
}
//1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
//five characters, including the null character.)
void reverseString(char *s)
{
    if (NULL == s)
    {
        return ;
    }

    int len = strlen(s);
    char *e = s + len - 1;
    //上述两行代码使用了标准库可以使用下面代码代替
    //char *e = s;
    //while (*e)
    //{
    //  ++e;
    //}
    //--e;
    while (s < e)
    {
        *s ^= *e;
        *e ^= *s;
        *s++ ^= *e--;
    }
}
//1.3 Design an algorithm and write code to remove the duplicate characters in a string
//without using any additional buffer. NOTE: One or two additional variables are fine.
//An extra copy of the array is not.
//FOLLOW UP
//Write the test cases for this method.
//测试用例:
//  1.空串
//  2.连续重复
//  3.间隔重复
//  4.无重复
//  5.全部相同字符
//method1: 该方法复杂度为O(nlgn), 使用了排序算法改变了字符串的顺序(不推荐)
void removeDuplicate(string &s)
{
    if (s.length() == 0)
    {
        return ;
    }
    sort(s.begin(), s.end());

    int last = 0;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != s[i-1])
        {
            s[++last] = s[i];
        }
    }

    s.resize(last+1);
}
//method2: 使用暴力检测法
void removeDuplicate1(char *s)
{
    if (s == NULL)
    {
        return ;
    }

    int tail = 1;
    int len = strlen(s);
    int j;
    for (int i = 1; i < len; ++i)
    {
        for (j = 0; j < tail; ++j)
        {
            if (s[j] == s[i])
            {
                break;
            }
        }

        if (j != tail)
        {
            s[tail] = s[i];
            ++tail;
        }
    }
    s[tail] = '\0';
}
//method3: hash
void removeDuplicate2(char *s)
{
    if (s == NULL)
    {
        return ;
    }

    bool test[256] = {false};
    char *tail = s;
    ++s;
    while (*s)
    {
        if (test[*s] != true)
        {
            *(++tail) = *s;
            test[*s] = true;
        }

        ++s;
    }
    ++tail;
    *tail = '\0';
}
int main()
{
    cout << checkStringUnique(string("abcdefg")) << endl;
    cout << checkStringUnique(string("abdea")) << endl;

    char s[] = "shaofeng";
    reverseString(s);
    cout << s << endl;

    string ss = "shaofengshao";
    removeDuplicate(ss);
    cout << ss << endl;

    cout << sizeof(bool) << endl;
}
