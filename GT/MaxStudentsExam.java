import java.util.HashMap;
import java.util.Map;

public class MaxStudentsExam {

    public int maxStudents(char[][] seats) {
        int m = seats.length, n = seats[0].length;
        int[] valid = new int[m];
        
        for (int i = 0; i < m; ++i) {
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    mask |= (1 << j);
                }
            }
            valid[i] = mask;
        }

        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(0, 0);

        for (int i = 0; i < m; ++i) {
            Map<Integer, Integer> next = new HashMap<>();
            for (int mask = 0; mask < (1 << n); ++mask) {
                if ((mask & ~valid[i]) != 0 || (mask & (mask >> 1)) != 0) continue;
                int count = Integer.bitCount(mask);

                for (int prevMask : dp.keySet()) {
                    if ((mask & (prevMask >> 1)) != 0 || (mask & (prevMask << 1)) != 0) continue;
                    next.put(mask, Math.max(next.getOrDefault(mask, 0), dp.get(prevMask) + count));
                }
            }
            dp = next;
        }

        int ans = 0;
        for (int val : dp.values()) {
            ans = Math.max(ans, val);
        }
        return ans;
    }

    public static void main(String[] args) {
        char[][] seats = {
            {'#', '.', '#', '#', '.', '#'},
            {'.', '#', '#', '#', '#', '.'},
            {'#', '.', '#', '#', '.', '#'}
        };
        System.out.println(new MaxStudentsExam().maxStudents(seats));
    }
}
