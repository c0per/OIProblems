# 能成

## 题目背景

你已经对图论有所了解了。

现在我们在一张`n`个点`m`条边的有向图上有`q`个询问，请你回答。

对于每一个询问，有两个点`u`和`v`。

请回答能否从点`u`走到点`v`。

## 输入格式（`check.in`）

第一行两个整数`n`，`m`，具体含义见题目。

接下来`m`行，每行两个整数`u`，`v`，代表存在一条`u`到`v`的有向边。

接下来的 1 行 1 个整数`q`，具体含义见题目。

接下来`q`行，每行两个整数`u`，`v`，代表一个`u`，`v`的询问。

## 输出格式（`check.out`）

`q`行，每行包含一个`Yes`或`No`字符串，代表可以或不可以从`u`走到`v`。

## 输入样例

```
7 5
5 2
4 6
2 3
3 1
3 5
5
6 7
5 3
1 5
3 6
3 2
```

## 输出样例

```
No
Yes
No
No
Yes
```

##数据范围与约定

对于 60% 的数据：

$500 \le q \le 1000$

对于 100% 的数据：

$500 \le n \le 1000$

$5 * 10 ^ 5 \le q 10 ^ 6$

$\frac{n}{2} \le m \le 2n$

图中不存在重边（起点和终点均相同的边），自环（起点与终点相同的边）。

另外，每个点都可以走到这个点本身。
