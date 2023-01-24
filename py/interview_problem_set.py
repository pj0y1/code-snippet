"""
所有题目完成后适当添加测试用例。
直接提交py文件。
"""
import time

"""
Q1
编写一个你认为的最优函数，接收两个整数 i, n,
输出：
i + ii + ... + i..i(n个i)
例：
输入 2, 3
计算 2 + 22 + 222
输出 246
"""
def calculate_sum(i, n):
    ans = 0
    v = i
    for _ in range(n):
        ans += v
        v = v*10+i
    return ans
    
"""
Q2.
不使用内置类range，实现与range基本功能相同的类
"""


class Range:
    """
    >>> list(range(1, 9)
    [1, 2, 3, 4, 5, 6, 7, 8]
    >>> list(range(9))
    [0, 1, 2, 3, 4, 5, 6, 7, 8]
    >>> list(range(9, 0, -1))
    [9, 8, 7, 6, 5, 4, 3, 2, 1]
    """
    def __init__(self, end, start=None, step=None):
        self._step = step if step else 1
        if start is None:
            self._start = 0
            self._end = end
        else:
            self._start = end
            self._end = start

    def __iter__(self):
        def cmp(a, b):
            if self._step > 0:
                return a > b
            else:
                return a < b

        while cmp(self._end, self._start):

            yield self._start
            self._start += self._step
        

"""
Q3. 
记录一个类的所有方法的调用信息。（包括__dict__等内置方法）
例：

class A(YOU_ARE_FREE_TO_INHERIT_FROM_ANY_CLASS):
    pass
        
a = A()

a.some_method()
将打印以下信息:
method: 'A.some_method' is called      # 打印方法名
method: 'A.some_method' finished in 0.001ms.  # 打印运行时间

a.any_attr = 7  # 调用属性将不打印任何信息

"""
class A:

    def __init__(self, *args, **kwargs):
        self.some_property = None

    def __getattribute__(self, name: str):

        def wrapper(*args, **kwargs):
            func = object.__getattribute__(self, name)
            print(f"'A.{func.__name__}' is called")
            t0 = time.time()
            func(*args, **kwargs)
            t1 = time.time()
            print(f"'A.{func.__name__}' finished in {(t1-t0)*1e3}ms.")

        if callable(object.__getattribute__(self, name)):
            return wrapper
        return object.__getattribute__(self, name)

    def some_method(self):
        pass

"""
Q4
class Matrix用于表示一个矩阵。
self.data 用于储存一个二维数组.
请实现该类的切片取数的功能，可仅考虑二维情况。
如果能用于任意多维情况更佳。
"""
class Matrix:
    """
    >>> matrix = Matrix([[1, 2, 3, 4],
                    [5, 6, 7, 8],
                    [0, 6, 2, 8],
                    [2, 3, 0, 2]])
    >>> matrix[1, 1]
    6
    >>> matrix[1, 1:3]
    [6, 7]
    >>> matrix[1:3, 2:4]
    [[7, 8],
    [2, 8]]
    """
    def __init__(self, data):
        self.data = data

    def __getitem__(self, idx):
        rs, cs = idx
        if isinstance(rs, int):
            return self.data[rs][cs]
        else:
            ans = []
            for r in self.data[rs]:
                ans.append(r[cs])
            return ans


"""
Q5.
有一套十分简易的字符串压缩规则如下（->左边为原字符串，右边为压缩后）

abababab -> [ab,4]
ababAAAcd -> [ab,2][A,3]cd
abbbaabbba -> [a[b,3]a,2]

即：
在方括号内，','左边为字符串，右边为重复次数，且方括号支持嵌套

注意：
1.原字符串不包含'[],'。

请实现对应的解压算法。（即输入->右边的字符串，输出左边的字符串。）
"""

def compressString(s):
    pass


if __name__ == '__main__':
    ans = calculate_sum(5, 3)
    print(ans)
    print(list(Range(9)))
    print(list(Range(5,9)))
    print(list(Range(9,6,-1)))
    a = A()
    a.some_method()
    a.some_property = 7

    matrix = Matrix([[1, 2, 3, 4],
                    [5, 6, 7, 8],
                    [0, 6, 2, 8],
                    [2, 3, 0, 2]])
    print(matrix[1,1])
    print(matrix[1, 1:3])
    print(matrix[1:3, 2:3])
