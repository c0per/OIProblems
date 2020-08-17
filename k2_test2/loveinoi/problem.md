# Love In OI

## 题目背景

小C要给他的女朋友写情书，可是他对自己写下的文字有着严格而傲娇的要求。

现在他准备给你看看他写好的情书，希望你帮助他将其转换成正确的格式。

情书由英文（小写和大写字母）写成，以及空格、换行（`\n`）、英文符号（,.?'":;）。

而格式要求也很简单：

对于原文，删去所有的标点符号和空白字符，再讲5个字母组成一组（最后一组可以少于5个字母），每组字母间插入一个空格，在一行上输出即可。

## 输入格式

若干行，每行是一个由英文字母（小写和大写）、空格、英文符号（详间题目背景）组成的字符串。

## 输出格式

共一行，为调整过格式的字符串。

## 样例输入1

```
You distract me.
I've been distracted since the moment I met you.
Because all I can think about is how much I want to kiss you.
```

## 样例输出1

```
Youdi strac tmeIv ebeen distr acted since themo mentI metyo uBeca useal lIcan think about ishow muchI wantt okiss you
```

## 样例输入2

```
Do you have a map? Because I just keep losing in your eyes.
```

## 样例输出2

```
Doyou havea mapBe cause Ijust keepl osing inyou reyes
```

## 数据范围与约定

每行的字符总数不超过`1000`

全文的字符总数不超过`100000`

行数不超过`2000`
