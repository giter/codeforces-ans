import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

		static String conv(int s) {

				StringBuffer sb = new StringBuffer();

				while (s > 0) {
						sb.append((char) ('A' + (s + 25) % 26));
						if (s % 26 == 0) {
								s -= 26;
						}
						s = s / 26;
				}

				return sb.reverse().toString();
		}

		static int conv(String s) {

				int v = 0;

				int m = 1;

				for (int i = s.length() - 1; i >= 0; i--) {
						v += m * (s.charAt(i) - 'A' + 1);
						m *= 26;
				}

				return v;
		}

		public static void main(String[] args) {

				Scanner scanner = new Scanner(System.in);

				int n = scanner.nextInt();

				Pattern _rc = Pattern.compile("R(\\d+)C(\\d+)");
				Pattern rc = Pattern.compile("([A-Z]+)(\\d+)");

				for (int i = 0; i < n; i++) {
						String s = scanner.next();

						Matcher m = _rc.matcher(s);

						if (m.find()) {
								System.out.print(conv(Integer.parseInt(m.group(2))));
								System.out.println(Integer.parseInt(m.group(1)));
						} else {
								m = rc.matcher(s);
								if (m.find()) {
										System.out.print('R');
										System.out.print(Integer.parseInt(m.group(2)));
										System.out.print('C');
										System.out.println(conv(m.group(1)));
								}
						}

				}
		}
}

