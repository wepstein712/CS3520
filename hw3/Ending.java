// print ending of a string
class Ending {
    public static void main(String[] args)
    {
	String in = "Hello, world!";
	int length = 16;
	String out = "";
	
	for (int i = length / 2; i < length; i ++) {
	    out += in.charAt(i); // NOTE: use [] operator in C++
	}

	System.out.println(out + " " + out.length());
    }
}
