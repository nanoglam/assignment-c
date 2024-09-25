#include <stdio.h>

//盤面表示
int show(char x[10][10]) {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(i > 0 && j > 0) {
				printf("  %c ", x[i][j]);
			}else{
				printf("  %d ", x[i][j]);
			}
			if(j == 8) {
				printf("\n");
			}
		}
	}
}	

int main() {
	char Othello[10][10];
	
	//配列の中に盤面を埋め込む作業
	for(int i=0; i<9; i++) {
		Othello[0][i] = i;
	}
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(j == 0){
				Othello[i+1][j] = i + 1;
			}else {
				Othello[i+1][j] = '-';
			}
		}
	}
	
	//初期配置
	Othello[4][4] = 'o';
	Othello[5][5] = 'o';
	Othello[4][5] = '*';
	Othello[5][4] = '*';
	show(Othello);
	
	//入力
	int m,n =0;
	int count = 0;
	int blackcount = 0;
	int whitecount = 0;
	int colorchange = 0;
	int normal = 0;
	while(count < 64){
		//判定式のリセット
		count = 0;
		blackcount = 0;
		whitecount = 0;
		//黒の手番
		normal = 0;
		while(normal<1) {
			colorchange = 0;
			//スキップ用
			int skipA = 1;
			int skipB = 1;
			int skipC = 1;
			for(int i=1; i<=8; i++) {
				for(int j=1; j<=8; j++) {
					if(Othello[i][j] == '-') {
						for(int p=2; p<=7; p++) {
							//左
							if(Othello[i][j - p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							} 
							//右
							if(Othello[i][j + p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//下
							if(Othello[i + p][j] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//上
							if(Othello[i - p][j] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//左上
							if(Othello[i - p][j - p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//左下
							if(Othello[i + p][j - p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//右上
							if(Othello[i - p][j + p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//右下
							if(Othello[i + p][j + p] == '*') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
						}
					}
					if(!skipA) {
						break;
					}
				}
				if(!skipB) {
					break;
				}
			}
			if(skipC) {
				printf("駒を置ける場所がありません。黒の手番をスキップします。\n");
				break;
			}
			printf("黒の手番です。\n");
			printf("どこに駒を置くか、縦、横の順番で一つずつ入力してください。\n");
			scanf("%d%d", &m,&n);
			printf("あなたが入力した値は、(%d,%d)\n", m,n);
			if(m < 1 || m > 8 || n < 1 || n > 8) {
				printf("エラーです。もう一度入力してください。\n");
				continue;
			}
			if(Othello[m][n] == '*' || Othello[m][n] == 'o') {
				printf("すでに駒が置かれています。もう一度入力してください。\n");
				continue;
			}
			Othello[m][n] = '*';
			//駒の色を変化させるプログラム
			//左、右、下、上、左上、右上、左下、右下の順に記述
			//左
			if(Othello[m][n - 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m][n - i] == '*') {
						for(int j=1; n-i+j<n; j++) {
							Othello[m][n - i + j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右
			if(Othello[m][n + 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m][n + i] == '*' && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m][n + i - j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//下
			if(Othello[m + 1][n] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n] == '*' && m + i <= 8) {
						for(int j=1; m+i-j>m; j++) {
							Othello[m + i - j][n] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//上
			if(Othello[m - 1][n] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n] == '*' && m - i > 0) {
						for(int j=1; n-i+j<n; j++) {
							Othello[m - i + j][n] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//左上
			if(Othello[m - 1][n - 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n - i] == '*') {
						for(int j=1; n-i+j<n; j++) {
							Othello[m - i + j][n - i + j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右上
			if(Othello[m - 1][n + 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n + i] == '*' && m - i > 0 && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m - i + j][n + i - j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//左下
			if(Othello[m + 1][n - 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n - i] == '*' && m + i <= 8 && n - i > 0) {
						for(int j=1; m+i-j>m; j++) {
							Othello[m + i - j][n - i + j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右下
			if(Othello[m + 1][n + 1] == 'o') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n + i] == '*' && m + i <= 8 && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m + i - j][n + i - j] = '*';
						}
						colorchange = 1;
						break;
					}
				}
			}
			if(colorchange == 0) {
				printf("色が変わる駒がありません。置き直してください。\n");
				continue;
			}
			show(Othello);
			normal++;
		} 
			
		//白の手番
		normal = 0;
		while(normal<1) {
			colorchange = 0;
			//スキップ用
			int skipA = 1;
			int skipB = 1;
			int skipC = 1;
			for(int i=1; i<=8; i++) {
				for(int j=1; j<=8; j++) {
					if(Othello[i][j] == '-') {
						for(int p=2; p<=7; p++) {
							//左
							if(Othello[i][j - p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							} 
							//右
							if(Othello[i][j + p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//下
							if(Othello[i + p][j] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//上
							if(Othello[i - p][j] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//左上
							if(Othello[i - p][j - p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//左下
							if(Othello[i + p][j - p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//右上
							if(Othello[i - p][j + p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
							//右下
							if(Othello[i + p][j + p] == 'o') {
								skipA = 0;
								skipB = 0;
								skipC = 0;
								break;
							}
						}
					}
					if(!skipA) {
						break;
					}
				}
				if(!skipB) {
					break;
				}
			}
			if(skipC) {
				printf("駒を置ける場所がありません。白の手番をスキップします。\n");
				break;
			}
			printf("白の手番です。\n");
			printf("どこに駒を置くか、縦、横の順番で一つずつ入力してください。\n");
			scanf("%d%d", &m,&n);
			printf("あなたが入力した値は、(%d,%d)\n", m,n);
			if(m < 1 || m > 8 || n < 1 || n > 8) {
				printf("エラーです。もう一度入力してください。\n");
				continue;
			}
			if(Othello[m][n] == '*' || Othello[m][n] == 'o') {
				printf("すでに駒が置かれています。もう一度入力してください。\n");
				continue;
			}
			Othello[m][n] = 'o';
			
			//駒の色を変化させるプログラム
			//左、右、下、上、左上、右上、左下、右下の順に記述
			//左
			if(Othello[m][n - 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m][n - i] == 'o') {
						for(int j=1; n-i+j<n; j++) {
							Othello[m][n - i + j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右
			if(Othello[m][n + 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m][n + i] == 'o' && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m][n + i - j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//下
			if(Othello[m + 1][n] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n] == 'o' && m + i <= 8) {
						for(int j=1; m+i-j>m; j++) {
							Othello[m + i - j][n] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//上
			if(Othello[m - 1][n] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n] == 'o' && m - i > 0) {
						for(int j=1; n-i+j<n; j++) {
							Othello[m - i + j][n] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//左上
			if(Othello[m - 1][n - 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n - i] == 'o') {
						for(int j=1; n-i+j<n; j++) {
							Othello[m - i + j][n - i + j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右上
			if(Othello[m - 1][n + 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m - i][n + i] == 'o' && m - i > 0 && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m - i + j][n + i - j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//左下
			if(Othello[m + 1][n - 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n - i] == 'o' && m + i <= 8 && n - i > 0) {
						for(int j=1; m+i-j>m; j++) {
							Othello[m + i - j][n - i + j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			//右下
			if(Othello[m + 1][n + 1] == '*') {
				for(int i=2; i<=7; i++) {
					if(Othello[m + i][n + i] == 'o' && m + i <= 8 && n + i <= 8) {
						for(int j=1; n+i-j>n; j++) {
							Othello[m + i - j][n + i - j] = 'o';
						}
						colorchange = 1;
						break;
					}
				}
			}
			if(colorchange == 0) {
				printf("色が変わる駒がありません。置き直してください。\n");
				continue;
			}
			show(Othello);
			normal++;
		}
		
		
		//判定式
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				if(Othello[i][j] == '*') {
					blackcount++;
				}
			}
		}
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				if(Othello[i][j] == 'o') {
					whitecount++;
				}
			}
		}
		if(blackcount == 0) {
			printf("黒の駒がなくなったので、ゲームを終了します！\n");
			break;
		} else if(whitecount == 0) {
			printf("白の駒がなくなったので、ゲームを終了します！\n");
			break;
		}
		count = blackcount + whitecount;
	}
	//結果
	int black = 0;
	int white = 0;
	
	for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				if(Othello[i][j] == '*') {
					black++;
				}
			}
		}
	
	for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++) {
				if(Othello[i][j] == 'o') {
					white++;
				}
			}
		}
	
	if(black > white) {
		printf("結果は、黒が%d個。白が%d個なので、黒の勝ちです！\n", black, white);
	} else if(black < white) {
		printf("結果は、黒が%d個。白が%d個なので、白の勝ちです！\n", black, white);
	} else {
		printf("結果は、黒が%d個。白が%d個なので、引き分けです！\n", black, white);
	}
	return 0;
}

