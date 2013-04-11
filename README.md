
## CSimpleLib

一些简单的数据结构的实现，最开始的初衷 是因为之前使用C++的map 和 set的时候    
发现内存占用太大，而我大部分只是想用一个 int -- int 的映射，int数字的范围 大概在千万以下     

然后参考了 redis 中list 的实现，和一些开源代码的写法

##内容
* CSlist 单链表
* CArray 数组
* CIntMap int-int 映射的一个map 实现，底层用的数组
* Csort 快速排序的实现
