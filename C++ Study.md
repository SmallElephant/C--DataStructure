# C++ Study

## 输出

```
cout c out 输出 endl end line 换行符
```

## 字符串 string

1.导入字符串库

```
#include <string.h>
```

2.字符串长度

```
len = str.length();
```

## scanf 输入

与printf相对应，标准输入模式，注意传递的输入内容的地址：

```
    scanf("%s",num);
```

连续的两次scanf之间读取需要输入getchar方法。

 ```
  scanf("%s",num);
  getchar();
  scanf("%c",&t);
 ```
 
## malloc 内存分配

C语言中需要导入头文件:

```
#include <stdlib.h>
```

```
    char *res = (char *)malloc(sizeof(char) * len);
    char res[maxsize];
``` 

## 指针与地址

```
*list 是一个变量，类型是TBNode，可以进行读写操作，list是地址，可以直接进行加减运算
```

```
TBNode *list;
```

## 字符串拼接

```
string s;
s.push_back(char);
```

## 二维数组定义

```
int *res[100];
```