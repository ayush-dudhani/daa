import java.util.*;
public class ass5{
	//int count = 1;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[][] board = new int[n][n]; 
		for(int i=0; i<n; i++){
			Arrays.fill(board[i], -1);
		}
		knightTour(board, 0, 0, 1);
		
		
		
	}
	public static void knightTour(int[][] board, int i, int j, int count){
		if(i<0 || j<0 || i>=board.length || j>=board[0].length){
			return;
		}
		if(board[i][j] != -1)
			return;
		if(count == board.length * board[0].length){
			board[i][j] = count;
			printSol(board);
			return;
			
		}
		board[i][j] = count;
		knightTour(board, i+2, j-1, count+1);
		knightTour(board, i+2, j+1, count+1);
		knightTour(board, i-2, j+1, count+1);
		knightTour(board, i-2, j-1, count+1);
		knightTour(board, i+1, j+2, count+1);
		knightTour(board, i+1, j-2, count+1);
		knightTour(board, i-1, j+2, count+1);
		knightTour(board, i-1, j-2, count+1);
//System.out.println(board[i][j]);
		board[i][j] = -1;	

		
	}
	public static void printSol(int[][] matrix){
		for(int i=0; i<matrix.length; i++){
			for(int j =0; j<matrix[0].length; j++)
				System.out.print(matrix[i][j] + " ");
			System.out.println();
		}
	}
}