#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int sudoku[9][9];

bool posibility(int row, int col, int value) {
	// 같은 행에 있는 열 원소 중에 겹치는 수가 있는지
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == value)
			return false;
	}

	// 같은 열에 있는 행 원소 중에 겹치는 수가 있는지
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == value)
			return false;
	}

	// 같은 3*3 칸 안에 있는 원소 중에 겹치는 수가 있는지
	int start_row = (row / 3) * 3; // value가 속한 3*3의 행의 첫 위치
	int start_col = (col / 3) * 3; // value가 속한 3*3의 열의 첫 위치

	for (int i = start_row; i < start_row + 3; i++) {
		for (int j = start_col; j < start_col + 3; j++) {
			if (sudoku[i][j] == value)
				return false;
		}
	}

	return true; // 중복되는 것이 없을 경우 true 반환
}

void resolve(int row, int col) {
	// 해당 행이 다 채워졌을 경우 다음 행의 첫 번째 열부터 시작
	if (col == 9) {
		resolve(row + 1, 0);
		return;
	}

	// 행과 열이 모두 채워졌을 경우 출력 후 종료
	if (row == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	// 만약 해당 위치의 값이 0이라면 1~9까지 중 가능한 수 탐색
	if (sudoku[row][col] == 0) {
		for (int value = 1; value <= 9; value++) {
			// value 값이 중복되지 않는지 검사
			if (posibility(row, col, value)) {
				sudoku[row][col] = value;
				resolve(row, col + 1); // 다음 칸 진행
			}
		}
		sudoku[row][col] = 0; // 채워지는 도중에 더이상 채울 수 없는 상태일 경우에, 다시 되돌아와서 그 자리를 0으로 초기화함
		return;
	}

	resolve(row, col + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &sudoku[i][j]);
		}
	}

	resolve(0, 0);

	return 0;
}