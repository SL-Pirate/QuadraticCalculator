package QuadCal;

public class notQuadraticException extends Exception{
	private static final long serialVersionUID = 1L;
	
	@Override
	public String getMessage() {
		return "This is not a quadratic equation";
	}
}
