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

```
char *res = (char *)malloc(sizeof(char) * total);
``` 