import java.io.*;
import java.util.*;
import java.math.*;

public class p1001 {
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()) {
			String base = scanner.next();
			int level = scanner.nextInt();
			System.out.println(expo(base, level));
		}
		scanner.close();
	}

	public static String expo(String base, int level) {
		if(level == 0) {
			return "1";
		} else{
			BigDecimal baseD = new BigDecimal(base);
			BigDecimal result = baseD;
			for(int i=1; i < level; ++i) {
				result = result.multiply(baseD);
			}
			String resultStr = result.toPlainString();
			return simplify(resultStr);
		}
	}

	public static String simplify(String str) {
		int dotIndex = str.indexOf('.');
		// erase leading 0
		int leadingZero = 0;
		for(; leadingZero < str.length() && str.charAt(leadingZero) == '0'; ++leadingZero);
		str = str.substring(leadingZero);
		// erase tailing 0
		if(dotIndex != 0) {
			int tailingZero = str.length() - 1;
			for(; tailingZero > dotIndex && str.charAt(tailingZero) == '0'; --tailingZero);
			str = str.substring(0, tailingZero + 1);
			if(str.charAt(str.length() - 1) == '.') {
				str = str.substring(0, str.length() - 1);
			}
		}
		if(str.length() == 0) {
			str = "0";
		}
		return str;
	}
}
