// choose a string
class Choose {

    public static String choose(int n)
    {
	switch(n) {
	case 0: return "zero";
	case 1: return "one";
	case 2: return "two";
	}
    }
    
    public static void main()
    {
	System.out.println(choose(0));
	System.out.println(choose(2));
	System.out.println(choose(4));
    }
}
