'''
本题考察二维矩阵，列表中每个位置的元素值代表在网格对应x,y坐标位上的方块数量
俯视图为列表中元素值大于0的元素总数
主视图为列表中每一维的元素最大值之和
左视图为列表中不同维度对应位置的元素最大值之和:使用了zip(*)函数，相当于将一个矩阵转置
'''
class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        xy = 0
        for row in grid:
            for v in row:
                if v > 0:
                    xy = xy + 1
        yz = sum(map(max,grid))
        xz = sum(map(max,zip(*grid)))
        total = xy + yz + xz
        return total