import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Map<String, Integer> scores = new HashMap<>(1024);
		Map<String, Integer> mscores = new HashMap<>(1024);

		List<String> names = new ArrayList<>(1024);
		List<Integer> cscores = new ArrayList<>(1024);

		Scanner cin = new Scanner(System.in);

		int n = cin.nextInt();
		int max = Integer.MIN_VALUE;

		for (int i = 0; i < n; i++) {

			String name = cin.next();
			int s = cin.nextInt();

			names.add(name);
			cscores.add(s);

			if (scores.containsKey(name)) {
				s = s + scores.get(name);
			}

			scores.put(name, s);

		}

		for (Integer s : scores.values()) {
			if (s > max) {
				max = s;
			}
		}

		for (int i = 0; i < n; i++) {

			String name = names.get(i);
			int s = cscores.get(i);

			if (mscores.containsKey(name)) {
				s = s + mscores.get(name);
			}

			mscores.put(name, s);

			if (scores.get(name) == max && s >= max) {
				System.out.println(name);
				return;
			}
		}

	}
}

