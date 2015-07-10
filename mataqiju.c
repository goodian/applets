/*
 * 马踏棋局，游戏规则：
 * 游戏开始，会设置一个初始位置，按照象棋规则，走遍所有棋盘位置，且最后回到初始
 * 位置。
 * 实现方案：深度遍历，指导找到符合条件的路径，然后打印输出。
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 6
#define COL 6

#define START_FLAG 99

#define MAX_STEP  (ROW * COL)
#define IN_RANGE(a, b) (a >= 0 && b >= 0 && a < ROW && b < COL)

int map[ROW][COL] = {0};

int find_way(int row, int col, int step)
{
	int tmp_r = 0;
	int tmp_c = 0;
	int ret = -1;

	if (step == MAX_STEP)
		return 0;

	if (step > MAX_STEP)
		return -1;
	/* Traverse max 8 possibilities */
	tmp_r = row + 1;
	tmp_c = col + 2;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row + 2;
	tmp_c = col + 1;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row + 2;
	tmp_c = col - 1;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row + 1;
	tmp_c = col - 2;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row - 1;
	tmp_c = col - 2;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row - 2;
	tmp_c = col - 1;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row - 2;
	tmp_c = col + 1;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	tmp_r = row - 1;
	tmp_c = col + 2;
	if (IN_RANGE(tmp_r, tmp_c) && (map[tmp_r][tmp_c] == 0 || (step == MAX_STEP - 1 && map[tmp_r][tmp_c] == START_FLAG))) {
		map[tmp_r][tmp_c] = ++step;
		ret = find_way(tmp_r, tmp_c, step);
		if (ret == 0) return ret;
		map[tmp_r][tmp_c] = 0;
		step--;
	}
	return -1;
}

void print_way()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf("%2d\t", map[i][j]);
		}
		printf("\n");
	}

	return;
}

void init_map(int row, int col)
{
	memset(map, 0, sizeof(map));
	map[row][col] = START_FLAG;
	return;
}

void trverse_all()
{
	int i = 0; 
	int j = 0;
	int ret = 0;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			init_map(i, j);
			ret = find_way(i, j, 0);
			printf("=====\n%d, %d, result: %d.\n", i, j, ret);
			if (ret == 0)
				print_way();
		}
	}

}

void usage()
{
	printf("Usage:\n"
		"  ./a.out <row> <col>\n"
		"  - <row> and <col> should in range 1-6\n"
		);
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int row, col;

#if 1
	if (argc != 3) {
		usage();
		goto out;
	}

	printf("row: %s, col: %s.\n", argv[1], argv[2]);

	row = atoi(argv[1]) - 1;
	col = atoi(argv[2]) - 1;

	if (!IN_RANGE(row, col)) {
		usage();
		goto out;
	}

	init_map(row, col);
	ret = find_way(row, col, 0);

	printf("result: %d.\n", ret);
	print_way();
#else
	trverse_all();
#endif

out:
	return 0;
}
