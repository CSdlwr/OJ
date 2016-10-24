import java.util.ArrayList;
import java.util.List;

public class PacificAtlanticWaterFlow {

    public static void main(String[] args) {
	int[][] matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	PacificAtlanticWaterFlow flow = new PacificAtlanticWaterFlow();
	flow.pacificAtlantic(matrix);
    }

    private void printArray(int[][] arr) {
	for (int i = 0; i < arr.length; ++i) {
	    System.out.print("[");
	    for (int j = 0; j < arr[i].length; ++j) {
		System.out.print(arr[i][j] + ",");
	    }
	    System.out.println("]");
	}
    }

    public List<int[]> pacificAtlantic(int[][] matrix) {
	List<int[]> ans = new ArrayList<int[]>();
	if (matrix == null || matrix.length == 0) {
	    return ans;
	}

	int[][] state1 = new int[matrix.length][matrix[0].length];
	int[][] state2 = new int[matrix.length][matrix[0].length];
	for (int i = 0; i < matrix.length; ++i) {
	    state1[i][0] = 1;
	    state2[i][state2[0].length - 1] = 1;
	}

	for (int j = 0; j < matrix[0].length; ++j) {
	    state1[0][j] = 1;
	    state2[state2.length - 1][j] = 1;
	}

	//printArray(state1);
	//System.out.println("\n");
	//printArray(state2);
	//System.out.println("\n");

	for (int i = 0; i < matrix.length; ++i) {
	    traverse(matrix, i, 0, state1);
	    traverse(matrix, i, state2[0].length - 1, state2);
	}
	
	for (int j = 0; j < matrix[0].length; ++j) {
	    traverse(matrix, 0, j, state1);
	    traverse(matrix, state2.length - 1, j, state2);
	}

	printArray(state1);
	System.out.println("\n");
	printArray(state2);

	for (int i = 0; i < matrix.length; ++i) {
	    for (int j = 0; j < matrix[i].length; ++j) {
		if (state1[i][j] == 1 && state2[i][j] == 1) {
		    ans.add(new int[] {i, j});
		    System.out.printf("[%d, %d], ", i, j);
		}
	    }
	}
	return ans;
    }

    public void traverse(int[][] matrix, int i, int j, int[][] state) {

	if (i >= 1 && matrix[i - 1][j] >= matrix[i][j] && state[i - 1][j] != 1) {
	    state[i - 1][j] = 1;
	    traverse(matrix, i - 1, j, state);
	}
	if (i < matrix.length - 1 && matrix[i + 1][j] >= matrix[i][j] && state[i + 1][j] != 1) {
	    state[i + 1][j] = 1;
	    traverse(matrix, i + 1, j, state);
	}
	if (j >= 1 && matrix[i][j - 1] >= matrix[i][j] && state[i][j - 1] != 1) {
	    state[i][j - 1] = 1;
	    traverse(matrix, i, j - 1, state);
	}
	if (j < matrix[0].length - 1 && matrix[i][j + 1] >= matrix[i][j] && state[i][j + 1] != 1) {
	    state[i][j + 1] = 1;
	    traverse(matrix, i, j + 1, state);
	}
    }

}
