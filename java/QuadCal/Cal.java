package QuadCal;
import java.text.DecimalFormat;

public class Cal {
	private final double a;
	private final double b;
	private final double c;
	private double[] roots;
	private double discriminant;
	private String equation;
	private String range;
	private String MinOrMax;
	private String nature;
	private int code = -1;
	/*  code = -1 or 3 when there's an error
		code = 0 when there are no real roots
		code = 1 when there's a single coincident root
		code = 2 when there are two distinct real roots
	 */

	public Cal(double a, double b, double c) throws notQuadraticException {
		this.a = a;
		this.b = b;
		this.c = c;
		discriminant();
		eqn();
		roots();
		nature();
		range();
		MinOrMax();
	}

	private String df(double x) {
		DecimalFormat decimal = new DecimalFormat("#.##");
		return decimal.format(x);
	}

	private void discriminant() {
		discriminant = b * b - 4 * a * c;
	}

	private void eqn() throws notQuadraticException {
		String aStr;
		String bStr;
		String cStr;

		String BtoS = df(b);
		String CtoS = df(c);

		if (a == 1.0) {
			aStr = "";
		} else if (a == -1.0) {
			aStr = "-";
		} else if (a == 0.0) {
			throw new notQuadraticException();
		} else {
			aStr = df(a);
		}

		if (b == 1.0) {
			bStr = "+";
		} else if (b == -1.0) {
			bStr = "-";
		} else if (b == 0.0) {
			bStr = null;
		} else if (b > 0.0) {
			bStr = "+" + BtoS;
		} else {
			bStr = BtoS;
		}

		if (c == 0.0) {
			cStr = "";
		} else if (c > 0.0) {
			cStr = "+" + CtoS;
		} else {
			cStr = CtoS;
		}

		if (bStr == null) {
			equation = "y=" + aStr + cStr;
		} else {
			equation = "y=" + aStr + "x\u00b2" + bStr + "x" + cStr;
		}
	}

	private void range() {
		String lroot1 = df(roots[0]);
		String lroot2 = df(roots[1]);

		if (discriminant > 0 && a > 0) {
			range = "positive in the range of " + lroot1 + " > x > " + lroot2;
		} else if (discriminant > 0 && a < 0) {
			range = "positive in the range of " + lroot1 + " < x U x < " + lroot2;
		} else if (discriminant < 0 && a > 0) {
			range = "positive for all x real";
		} else if (discriminant < 0 && a < 0) {
			range = "negative for all x real";
		} else if (discriminant == 0 && a > 0) {
			range = "positive for all x real \n\tand equal to zero at " + lroot1;
		} else if (discriminant == 0 && a < 0) {
			range = "negative for all x real \n\tand equal to zero at " + lroot1;
		} else {
			range = null;
		}
	}

	private void MinOrMax() {
		if (a > 0) {
			MinOrMax = "minimum";
		} else if (a < 0) {
			MinOrMax = "maximum";
		} else {
			MinOrMax = null;
		}
	}

	private void roots() {
		roots = new double[2];
		double sqrt_disc = Math.sqrt(discriminant);
		double tmp;

		roots[0] = (-b - sqrt_disc) / (2 * a);
		roots[1] = (-b + sqrt_disc) / (2 * a);

		if (roots[0] < roots[1]) {
			tmp = roots[0];
			roots[0] = roots[1];
			roots[1] = tmp;
		}
	}

	private void nature() {
		if (discriminant < 0) {
			nature = "no real roots";
			code = 0;
		} else if (discriminant == 0) {
			nature = "one coincident root";
			code = 1;
		} else if (discriminant > 0) {
			nature = "two distinct real roots";
			code = 2;
		} else {
			code = 3;
		}
	}

	//getters
	public String getEquation(){
		return equation;
	}
	public double getRoot(int i){
		return roots[i];
	}
	public String getRange(){
		return range;
	}
	public double getDiscriminant(){
		return discriminant;
	}
	public String getMinOrMax(){
		return MinOrMax;
	}
	public String getNature(){
		return nature;
	}
	public int getCode(){
		return code;
	}
}
