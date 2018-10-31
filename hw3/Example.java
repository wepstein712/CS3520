// example java program
class Example {
    public static int sqr(int x) {
	return x * x;
    }
    
    public static void main(String[] args) {
	int vals[] = { 1, 2, 3, 4 };

	String text = " squared is ";
	for(int i = 0; i <= 4; i++) {
	    System.out.println(vals[i] + text + sqr(vals[i]));
	}
    }
}
