package QuadCal;

import java.text.DecimalFormat;

public class Cal{

	private double a;
	private double b;
	private double c;
	private double discriminant;
	
	public Cal(double a, double b, double c) throws notQuadraticException{
		setA(a);
		setB(b);
		setC(c);
		set_discriminant();
	}
	
	public String df(double x) {
		DecimalFormat decimal = new DecimalFormat("#.##");
		return decimal.format(x);
	}
	
	public double discriminant() {
		return b*b-4*a*c;
	}
	
	public void set_discriminant() {
		this.discriminant = discriminant();
	}

	public String eqn() {
		String a_tmp = df(a);
		String b_tmp = df(b);
		String c_tmp = df(c);
		
		switch (a_tmp) {
			case "-1": a_tmp = "-";
			break;
			case "1": a_tmp = "";
		}
		switch (b_tmp) {
			case "-1": b_tmp = "-";
			break;
			case "0": b_tmp = "NaN";
			break;
			case "1": b_tmp = "+";
		}
		if (b > 0 && b!=1) {
			b_tmp = "+"+b_tmp;
		}
		if (c==0) {
			c_tmp = "NaN";
		}
		else if(c>0) {
			c_tmp = "+"+c_tmp;
		}
		
		
		if(b_tmp.equals("NaN") && c_tmp.equals("NaN")) {
			return "y="+a_tmp+"x\u00b2";
		}
		else if (b_tmp.equals("NaN")) {
			return "y="+a_tmp+"x\u00b2"+c_tmp;
		}
		else if(c_tmp.equals("NaN")){
			return "y="+a_tmp+"x\u00b2"+b_tmp+"x";
		}
		else {
		return "y="+a_tmp+"x\u00b2"+b_tmp+"x"+c_tmp;
		}
	}
	
	public String sign() {
		String out;
		double[] roots = roots_inDoubles();
		String root1 = df(roots[0]);
		String root2 = df(roots[1]);
		
		if (discriminant > 0 && a > 0) {
			out = "positive in the range of "+root1+" < x < "+root2;
		}
		else if(discriminant > 0 && a<0) {
			out = "positive in the range of "+root1+" > x U x > "+root2;
		}
		else if(discriminant <0 && a>0) {
			out = "positive for all x real";
		}
		else if(discriminant<0 && a<0) {
			out = "negative for all x real";
		}
		else {
			out = null;
		}
		
		return out;
	}
	
	public String minORmax() {
		if (a>0) {
			return "minimum";
		}
		else if (a<0){
			return "maximum";
		}
		else {
			return null;
		}
	}
	
	public String[] roots() {
		double root1;
		double root2;
		
		double sqrt_disc = Math.sqrt(discriminant);
		
		root1 = (-b-sqrt_disc)/a;
		root2 = (-b+sqrt_disc)/a;
		
		String Sroot1 = Double.toString(root1);
		String Sroot2 = Double.toString(root2);
		
		if (Sroot1.equals(Sroot2)) {
			Sroot2="NaN";
		}
		
		return new String[] {Sroot1, Sroot2};
	}
	
	@SuppressWarnings("null")
	public double[] roots_inDoubles() {
		double root1;
		double root2;
		
		double sqrt_disc = Math.sqrt(discriminant);
		
		root1 = (-b-sqrt_disc)/a;
		root2 = (-b+sqrt_disc)/a;

		if (root1 < root2) {
			double tmp = root2;
			root2 = root1;
			root1 = tmp;
		}
		
		return new double[] {root1, root2};
	}
	
	public String[] nature() {
		String nat; 
		String code;
		
		if (discriminant < 0) {
			nat = "no real roots";
			code = "0";
		}
		else if (discriminant == 0) {
			nat = "one coincident root";
			code = "1";
		}
		else if (discriminant > 0) {
			nat = "two distinct real roots";
			code = "2";
		}
		else {
			nat = null;
			code = "3";
		}
		
		return new String[] {nat, code};
	}
	
	public String[] run() {
		String[] out = new String[8];
		out[0] = eqn();
		String[] nature = nature();
		String[] root = roots();
		out[1] = Double.toString(discriminant);
		out[2] = nature[0];
		out[3] = root[0];
		out[4] = root[1];
		out[5] = nature[1];
		out[6] = sign();
		out[7] = minORmax();
		return out;
	}
	
	public String toString() {
		String[] root = roots();
		String root1 = root[0];
		String root2 = root[1];
		return eqn()+"\n"+discriminant+"\n"+nature()[0]+"\n"+root1+"\n"+root2;
	}
	
	public void setA(double a) throws notQuadraticException{
		if (a == 0) {
			throw (new notQuadraticException());
		}
		this.a = a;
	}
	public void setB(double b) {
		this.b = b;
	}
	public void setC(double c) {
		this.c = c;
	}
}